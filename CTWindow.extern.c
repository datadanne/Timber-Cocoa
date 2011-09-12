#include "CTWindow.extern.h"

extern pthread_mutex_t envmut;
extern int envRootsDirty;
CocoaEvent_CTCommon receivedEvent;

pthread_mutex_t eventMutex;

bool dispatchEventToTimber(NSEvent* event) { 
	App_CTCommon app = getApp();
	DEBUG("C: Event received in dispatchEventToTimber\n");
	/* figure out event
		flag 0,1,2 0 = windowEvent, etc. */
	if ([event type] == NSLeftMouseDown || [event type] == NSLeftMouseDragged) {
        
 		Position_CTCommon x_5110;
	    NEW (Position_CTCommon, x_5110, WORDS(sizeof(struct Position_CTCommon)));
	    x_5110->GCINFO = __GC__Position_CTCommon;
		NSPoint p = [event locationInWindow];
	    x_5110->x_CTCommon = p.x;
		x_5110->y_CTCommon = p.y;
		DEBUG("C detects mouse at %f , %f", p.x, p.y);
	    _MouseClicked_CTCommon x_5111;
	    NEW (_MouseClicked_CTCommon, x_5111, WORDS(sizeof(struct _MouseClicked_CTCommon)));
	    x_5111->GCINFO = __GC___MouseClicked_CTCommon;
	    x_5111->Tag = 3;
	    x_5111->a = x_5110;
	   
	    NEW (CocoaEvent_CTCommon, receivedEvent, WORDS(sizeof(struct _MouseEvent_CTCommon)));
	    ((_MouseEvent_CTCommon)receivedEvent)->GCINFO = __GC___MouseEvent_CTCommon;
	    ((_MouseEvent_CTCommon)receivedEvent)->Tag = 1;
	    ((_MouseEvent_CTCommon)receivedEvent)->a = (MouseEventType_CTCommon)x_5111;
		
		DEBUG("Event is to be sent for window nr %d", [event windowNumber]);
	} else if ([event type] == NSFlagsChanged || [event type] == NSKeyUp) {
	    _KeyPressed_CTCommon x_1652;
        NEW (_KeyPressed_CTCommon, x_1652, WORDS(sizeof(struct _KeyPressed_CTCommon)));
        x_1652->GCINFO = __GC___KeyPressed_CTCommon;
        x_1652->Tag = 1;

        printf("KEY CODE %d\n", [event keyCode]);

        x_1652->a = (CocoaKey_CTCommon)(POLY)(126 - [event keyCode]);
                
        NEW (CocoaEvent_CTCommon, receivedEvent, WORDS(sizeof(struct _KeyEvent_CTCommon)));
        ((_KeyEvent_CTCommon)receivedEvent)->GCINFO = __GC___KeyEvent_CTCommon;
        ((_KeyEvent_CTCommon)receivedEvent)->Tag = 0;
        ((_KeyEvent_CTCommon)receivedEvent)->a = (KeyEventType_CTCommon)x_1652;

	} else {
	    printf("Event of type %d was discarded\n", [event type]);
        return false;
    }

    return app->eventDispatcher_CTCommon(app, (CocoaEvent_CTCommon)receivedEvent, [event windowNumber], 0);
}

void scanEventReceived(void) {
	DISABLE(envmut);
	if(receivedEvent)
		receivedEvent = (CocoaEvent_CTCommon)copy((ADDR)receivedEvent);
	ENABLE(envmut);
}

struct Scanner eventScanner = {scanEventReceived, NULL};

// --------- Window ----------------------------------------------
TUP0 windowSetContentView_CTWindow(CocoaWindow_CTCommon window, CocoaID_CTCommon id, Int dummy) {
	NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
	internal_CocoaID_CTCommon thisWindow = 		  
		(internal_CocoaID_CTCommon)(window->windowId_CTCommon);
	CocoaWindow *wind = (CocoaWindow*) thisWindow->this;
	CocoaView *view = (CocoaView*) COCOA_REF(id);	
	                                                                     
	[wind setContentView: view];
	[pool release];
	return 0;
}


static WindowDelegate *delegate;

Int initCocoaWindow_CTWindow(CocoaWindow_CTCommon wnd, App_CTCommon app, Int dummy) {   
	DEBUG("Initializing window...");
	NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];	
	CocoaWindow *window;
	
	window = [[[CocoaWindow alloc] initWithContentRect:NSMakeRect(0, 0, 0, 0) styleMask:(NSTitledWindowMask | NSClosableWindowMask | NSResizableWindowMask)  backing:NSBackingStoreBuffered defer:NO] autorelease]; 
	
	pthread_mutex_init(&eventMutex, &glob_mutexattr);

	DISABLE(envmut);
	addRootScanner(&eventScanner);
	envRootsDirty = 1;
	ENABLE(envmut);

    [window cascadeTopLeftFromPoint:NSMakePoint(10,10)];
    [window setTitle:@"new WINDOW!"];
	[window setEventDispatcher:dispatchEventToTimber];
	
	if (!delegate)
		delegate = [[WindowDelegate alloc] init];
	
	[window setDelegate:delegate];
	[window makeKeyAndOrderFront:NSApp];
	
	internal_CocoaID_CTCommon thisWindow = (internal_CocoaID_CTCommon)(wnd->windowId_CTCommon);
	thisWindow->this = (NSObject*) window;
	DEBUG("Window OK!");
	
	return [window windowNumber];
}

TUP0 destroyCocoaWindow_CTWindow(CocoaID_CTCommon wnd, Int dummy) {
	NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
	CocoaWindow *thisWindow = (CocoaWindow*) COCOA_REF(wnd);
	[thisWindow close];
	[pool drain];
}
   
Msg windowSetVisible_CTWindow(CocoaID_CTCommon wnd, Time start, Time stop) {  
	NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
	CocoaWindow *thisWindow = (CocoaWindow*) COCOA_REF(wnd);
	[thisWindow orderFront: NULL];
	[pool drain];
}

Msg windowSetHidden_CTWindow(CocoaID_CTCommon wnd, Time start, Time stop) {
	NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
	CocoaWindow *thisWindow = (CocoaWindow*) COCOA_REF(wnd);
	[thisWindow orderOut: NULL];
	[pool drain];
}

TUP0 windowSetFocus_CTWindow(CocoaID_CTCommon wnd, CocoaID_CTCommon cmp, Int dummy) {
	NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
	CocoaWindow *thisWindow = (CocoaWindow*) COCOA_REF(wnd);
	NSView *responder = (NSView*) COCOA_REF(cmp);
	[thisWindow makeFirstResponder: responder];
	[pool drain];
}

Msg windowSetSize_CTWindow (CocoaID_CTCommon wnd, Size_CTCommon pos, Time start, Time stop) {
	NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
	DEBUG("setting containerSize ext!");
	CocoaWindow *thisWindow = (CocoaWindow*) COCOA_REF(wnd);
	
	//dispatch_async(dispatch_get_main_queue(), ^{
	    [thisWindow setContentSize: NSMakeSize(pos->width_CTCommon, pos->height_CTCommon)];
//	});
	[pool drain];
}

Msg windowSetPosition_CTWindow (CocoaID_CTCommon wnd, Position_CTCommon pos, Time start, Time stop) {
	NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
	CocoaWindow *thisWindow = (CocoaWindow*) COCOA_REF(wnd);
    NSPoint p = NSMakePoint(pos->x_CTCommon,pos->y_CTCommon);
   	//dispatch_async(dispatch_get_main_queue(), ^{
        [thisWindow setFrameOrigin:p];
   // });
   	[pool drain]; 
}