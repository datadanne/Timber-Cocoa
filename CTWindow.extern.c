#include "CTWindow.extern.h"
#import "CTWindow.extern.m"

#include <assert.h>

extern pthread_mutex_t rts;
extern pthread_mutex_t envmut;
extern int envRootsDirty;
CocoaEvent_CTCommon receivedEvent;

pthread_mutex_t eventMutex;

@interface NSEvent (DeviceDelta)
  - (float)deviceDeltaX;
  - (float)deviceDeltaY;
@end

extern ADDR base;

int p = 0;
bool dispatchEventToTimber(NSEvent* event) { 
	DEBUG("C: Event received in dispatchEventToTimber\n"); 
    int b1;
    DISABLE(rts);
    b1 = *base;
    ENABLE(rts);
	/* figure out event
		flag 0,1,2 0 = windowEvent, etc. */
	if ([event type] == NSLeftMouseDown || [event type] == NSLeftMouseDragged) {
        Position_CTCommon x_5110 = NULL;
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

	} else if ([event type] == NSScrollWheel) {
  	    NSLog(@"Scroll Event: %@", event);

        printf("Scrolling event! \n");            
        //    printf("deltaX: %f \n", [event deltaX]);
        //    printf("deltaY: %f \n", [event deltaX]);
        // 
        //    printf("hasPreciseScrollingDeltas: %d \n", [event hasPreciseScrollingDeltas]);
        //    printf("scrollingDeltaX: %f \n", [event scrollingDeltaX]);
        //    printf("scrollingDeltaY: %f \n", [event scrollingDeltaY]);                                   
        //    printf("isDirectionIntevertedFromDevice: %d", [event isDirectionInvertedFromDevice]);  

   		NSPoint p = [event locationInWindow];

        Position_CTCommon x_1073;
        NEW(Position_CTCommon, x_1073, WORDS(sizeof(struct Position_CTCommon)));
        x_1073->GCINFO = __GC__Position_CTCommon;
        x_1073->x_CTCommon = p.x;
        x_1073->y_CTCommon = p.y;
        _MouseWheelScroll_CTCommon x_1074;
        NEW (_MouseWheelScroll_CTCommon, x_1074, WORDS(sizeof(struct _MouseWheelScroll_CTCommon)));
        x_1074->GCINFO = __GC___MouseWheelScroll_CTCommon;
        x_1074->Tag = 4;
        x_1074->a = x_1073;

        float deltaX = -1 * [event deviceDeltaX];
        float deltaY = -1 * [event deviceDeltaY];

#if _ENVIRONMENT_MAC_OS_X_VERSION_MIN_REQUIRED_ >= 1070
            if ([event hasPreciseScrollingDeltas]) {
                deltaX = [event scrollingDeltaX];
                deltaY = [event scrollingDeltaY];
            }

            if ([event isDirectionInvertedFromDevice]) {
                deltaX *= -1;
                deltaY *= -1;
            }
#endif
        x_1074->b = deltaX;
        x_1074->c = deltaY;

        //CocoaEvent_CTCommon test_12;
        NEW (CocoaEvent_CTCommon, receivedEvent, WORDS(sizeof(struct _MouseEvent_CTCommon)));
        ((_MouseEvent_CTCommon)receivedEvent)->GCINFO = __GC___MouseEvent_CTCommon;
        ((_MouseEvent_CTCommon)receivedEvent)->Tag = 1;
        ((_MouseEvent_CTCommon)receivedEvent)->a = (MouseEventType_CTCommon)x_1074;     

    	App_CTCommon app = getApp();
        app->sendInputEvent_CTCommon(app, (CocoaEvent_CTCommon)receivedEvent, [event windowNumber], 0);      
        return true;
	} else {
        printf("Event of type %d was discarded\n", [event type]);
        return false;
    }
 	
 	/*DISABLE(envmut);
    printf("envRD1\n");
	envRootsDirty = 1;
	ENABLE(envmut);*/

	App_CTCommon app = getApp();
	
    int b2;
    DISABLE(rts);
    b2 = *base;
    ENABLE(rts);
	
    assert(b1 == b2);
    return app->sendInputEvent_CTCommon(app, (CocoaEvent_CTCommon)receivedEvent, [event windowNumber], 0);
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

	// Install event scanner to keep track of delegate address.
	pthread_mutex_init(&eventMutex, &glob_mutexattr);
	DISABLE(envmut);
	addRootScanner(&eventScanner);
	envRootsDirty = 1;
	ENABLE(envmut);
    
    __block CocoaWindow *window;
    dispatch_sync(dispatch_get_main_queue(), ^{
    	NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];	

        NSRect frameRect = NSMakeRect(0, 0, 0, 0);
        NSUInteger styleMask = (NSTitledWindowMask | NSClosableWindowMask | NSResizableWindowMask);
        window = [[CocoaWindow alloc] initWithContentRect:frameRect styleMask:styleMask  backing:NSBackingStoreBuffered defer:NO]; 

        // Move window to the top left corner
        [window cascadeTopLeftFromPoint:NSMakePoint(10,10)];

        [window setTitle:@"new WINDOW!"];

        [window setEventDispatcher:dispatchEventToTimber];

        if (!delegate)
        	delegate = [[WindowDelegate alloc] init];

        [window setDelegate:delegate];
        [window makeKeyAndOrderFront:window];

        // NOTE: Can't use COCOA_ID macro here due to windowId, not Id
        internal_CocoaID_CTCommon thisWindow = (internal_CocoaID_CTCommon)(wnd->windowId_CTCommon);
        thisWindow->this = (NSObject*) window;
        DEBUG("Window OK!");
        [pool drain];
    });
    
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
	
	[thisWindow setContentSize: NSMakeSize(pos->width_CTCommon, pos->height_CTCommon)]; //-20 to compensate for border.
	
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