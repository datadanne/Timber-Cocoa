#include "CTWindow.extern.h"
#import "CTWindow.extern.m"

#include <assert.h>

extern pthread_mutex_t rts;
extern pthread_mutex_t envmut;
extern int rootsDirty;
InputEvent_COCOA receivedEvent;

pthread_mutex_t eventMutex;

@interface NSEvent (DeviceDelta)
  - (float)deviceDeltaX;
  - (float)deviceDeltaY;
@end

extern ADDR base;

int p = 0;
bool dispatchEventToTimber(NSEvent* event) { 
	DEBUG("C: Event received in dispatchEventToTimber\n"); 

	/* figure out event
		flag 0,1,2 0 = windowEvent, etc. */
	if ([event type] == NSLeftMouseDown || [event type] == NSLeftMouseDragged) {
        Position_COCOA x_5110 = NULL;
	    NEW (Position_COCOA, x_5110, WORDS(sizeof(struct Position_COCOA)));

	    x_5110->GCINFO = __GC__Position_COCOA;
		NSPoint p = [event locationInWindow];
	    x_5110->x_COCOA = p.x;
		x_5110->y_COCOA = p.y;
		
		DEBUG("C detects mouse at %f , %f", p.x, p.y);
		
	    _MouseClicked_COCOA x_5111;
	    NEW (_MouseClicked_COCOA, x_5111, WORDS(sizeof(struct _MouseClicked_COCOA)));
	    x_5111->GCINFO = __GC___MouseClicked_COCOA;
	    x_5111->Tag = 3;
	    x_5111->a = x_5110;
	   
	    NEW (InputEvent_COCOA, receivedEvent, WORDS(sizeof(struct _MouseEvent_COCOA)));
	    ((_MouseEvent_COCOA)receivedEvent)->GCINFO = __GC___MouseEvent_COCOA;
	    ((_MouseEvent_COCOA)receivedEvent)->Tag = 1;
	    ((_MouseEvent_COCOA)receivedEvent)->a = (MouseEventType_COCOA)x_5111;
		
		DEBUG("Event is to be sent for window nr %d", [event windowNumber]);
	} else if ([event type] == NSKeyUp || [event type] == NSFlagsChanged) {
	    _KeyReleased_COCOA x_1652;
        NEW (_KeyReleased_COCOA, x_1652, WORDS(sizeof(struct _KeyReleased_COCOA)));
        x_1652->GCINFO = __GC___KeyReleased_COCOA;
        x_1652->Tag = 0;

        DEBUG("KEY CODE %d\n", [event keyCode]);

        x_1652->a = (CocoaKey_COCOA)(POLY)(126 - [event keyCode]);
                
        NEW (InputEvent_COCOA, receivedEvent, WORDS(sizeof(struct _KeyEvent_COCOA)));
        ((_KeyEvent_COCOA)receivedEvent)->GCINFO = __GC___KeyEvent_COCOA;
        ((_KeyEvent_COCOA)receivedEvent)->Tag = 0;
        ((_KeyEvent_COCOA)receivedEvent)->a = (KeyEventType_COCOA)x_1652;

	} else if ([event type] == NSKeyDown || [event type] == NSFlagsChanged) {
		    _KeyPressed_COCOA x_1652;
	        NEW (_KeyPressed_COCOA, x_1652, WORDS(sizeof(struct _KeyPressed_COCOA)));
	        x_1652->GCINFO = __GC___KeyPressed_COCOA;
	        x_1652->Tag = 1;

	        DEBUG("KEY CODE %d\n", [event keyCode]);

	        x_1652->a = (CocoaKey_COCOA)(POLY)(126 - [event keyCode]);

	        NEW (InputEvent_COCOA, receivedEvent, WORDS(sizeof(struct _KeyEvent_COCOA)));
	        ((_KeyEvent_COCOA)receivedEvent)->GCINFO = __GC___KeyEvent_COCOA;
	        ((_KeyEvent_COCOA)receivedEvent)->Tag = 0;
	        ((_KeyEvent_COCOA)receivedEvent)->a = (KeyEventType_COCOA)x_1652;

	} else if ([event type] == NSScrollWheel) {
  	    NSLog(@"Scroll Event: %@", event);

        DEBUG("Scrolling event! \n");            
        //    printf("deltaX: %f \n", [event deltaX]);
        //    printf("deltaY: %f \n", [event deltaX]);
        // 
        //    printf("hasPreciseScrollingDeltas: %d \n", [event hasPreciseScrollingDeltas]);
        //    printf("scrollingDeltaX: %f \n", [event scrollingDeltaX]);
        //    printf("scrollingDeltaY: %f \n", [event scrollingDeltaY]);                                   
        //    printf("isDirectionIntevertedFromDevice: %d", [event isDirectionInvertedFromDevice]);  

   		NSPoint p = [event locationInWindow];

        Position_COCOA x_1073;
        NEW(Position_COCOA, x_1073, WORDS(sizeof(struct Position_COCOA)));
        x_1073->GCINFO = __GC__Position_COCOA;
        x_1073->x_COCOA = p.x;
        x_1073->y_COCOA = p.y;
        
        _MouseWheelScroll_COCOA x_1074;
        NEW (_MouseWheelScroll_COCOA, x_1074, WORDS(sizeof(struct _MouseWheelScroll_COCOA)));
        x_1074->GCINFO = __GC___MouseWheelScroll_COCOA;
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

        //InputEvent_COCOA test_12;
        NEW (InputEvent_COCOA, receivedEvent, WORDS(sizeof(struct _MouseEvent_COCOA)));
        ((_MouseEvent_COCOA)receivedEvent)->GCINFO = __GC___MouseEvent_COCOA;
        ((_MouseEvent_COCOA)receivedEvent)->Tag = 1;
        ((_MouseEvent_COCOA)receivedEvent)->a = (MouseEventType_COCOA)x_1074;     

    	App_COCOA app = getApp();
        app->l_App_COCOA_AppImpl_COCOA_COCOA->sendInputEvent_COCOA(app->l_App_COCOA_AppImpl_COCOA_COCOA, 
			(InputEvent_COCOA)receivedEvent, [event windowNumber], 0);      
        return true;
	} else {
        printf("Event of type %d was discarded\n", [event type]);
        return false;
    }
 	
 	/*DISABLE(envmut);
    printf("envRD1\n");
	rootsDirty = 1;
	ENABLE(envmut);*/

	App_COCOA app = getApp();
	
    bool timberResult = app->l_App_COCOA_AppImpl_COCOA_COCOA->sendInputEvent_COCOA(app->l_App_COCOA_AppImpl_COCOA_COCOA, (InputEvent_COCOA)receivedEvent, [event windowNumber], 0);
    return timberResult;
}

// --------- Window ----------------------------------------------
TUP0 windowSetContentView_CTWindow(CocoaWindow_COCOA window, CocoaID_COCOA id, Int dummy) {
	NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
	internal_CocoaID_COCOA thisWindow = 		  
		(internal_CocoaID_COCOA)(window->windowId_COCOA);
	CocoaWindow *wind = (CocoaWindow*) thisWindow->this;
	CocoaView *view = (CocoaView*) COCOA_REF(id);	
	                                                                     
	[wind setContentView: view];
	[pool release];
	return 0;
}

void scanEventReceived() {
	DISABLE(envmut);
	if(receivedEvent)
		receivedEvent = (InputEvent_COCOA)copy((ADDR)receivedEvent);
	ENABLE(envmut);
    DEBUG("GC in scanEventReceived: done with copy?\n");
}

struct Scanner eventScanner = {scanEventReceived, NULL};
static WindowDelegate *delegate;


Int initCocoaWindow_CTWindow(CocoaWindow_COCOA wnd, App_COCOA app, Int dummy) {   
	DEBUG("Initializing window...");
    
    __block CocoaWindow *window;
    // Keep this as sync to ensure window is completely created before use.
    // Also, with async there would be a risk of GC moving wnd before it is accessed.
    dispatch_sync(dispatch_get_main_queue(), ^{
    	NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];	
        NSRect frameRect = NSMakeRect(0, [[[NSScreen screens] objectAtIndex: 0] frame].size.height, 1, 1);
        NSUInteger styleMask = (NSTitledWindowMask | NSClosableWindowMask | NSResizableWindowMask);
        window = [[CocoaWindow alloc] initWithContentRect:frameRect styleMask:styleMask  backing:NSBackingStoreBuffered defer:NO]; 
        [window setTitle:@"new WINDOW!"];
        [window setEventDispatcher:dispatchEventToTimber];

        if (!delegate)
        	delegate = [[WindowDelegate alloc] init];

        [window setDelegate:delegate];
       // [window makeKeyAndOrderFront:window];

        // NOTE: Can't use COCOA_ID macro here due to windowId, not Id
        internal_CocoaID_COCOA thisWindow = (internal_CocoaID_COCOA)(wnd->windowId_COCOA);
        thisWindow->this = (NSObject*) window;
        DEBUG("Window OK!");
        [pool drain];
    });
    
	return [window windowNumber];
}

TUP0 destroyCocoaWindow_CTWindow(CocoaID_COCOA wnd, Int dummy) {
    CocoaWindow *thisWindow = (CocoaWindow*) COCOA_REF(wnd);
    dispatch_async(dispatch_get_main_queue(), ^{
    
	    NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
	    [thisWindow close];
	    [pool drain];
        });
}
   
TUP0 windowSetVisible_CTWindow(CocoaID_COCOA wnd, Int dummy) {  
	NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
	CocoaWindow *thisWindow = (CocoaWindow*) COCOA_REF(wnd);
	[thisWindow orderFront: NULL];
	[pool drain];
}

TUP0 windowSetHidden_CTWindow(CocoaID_COCOA wnd, Int dummy) {
	NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
	CocoaWindow *thisWindow = (CocoaWindow*) COCOA_REF(wnd);
	[thisWindow orderOut: NULL];
	[pool drain];
}

TUP0 windowSetFocus_CTWindow(CocoaID_COCOA wnd, CocoaID_COCOA cmp, Int dummy) {
	NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
	CocoaWindow *thisWindow = (CocoaWindow*) COCOA_REF(wnd);
	NSView *responder = (NSView*) COCOA_REF(cmp);
	[thisWindow makeFirstResponder: responder];
	[pool drain];
}

TUP0 windowSetSize_CTWindow (CocoaID_COCOA wnd, Size_COCOA pos, Int dummy) {
	DEBUG("setting containerSize ext!");
	CocoaWindow *thisWindow = (CocoaWindow*) COCOA_REF(wnd);
    int width = pos->width_COCOA;
    int height = pos->height_COCOA;

	dispatch_async(dispatch_get_main_queue(), ^{
	    NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
	    [thisWindow setContentSize: NSMakeSize(width, height)];
		[pool drain];
    });
}

TUP0 windowSetPosition_CTWindow (CocoaID_COCOA wnd, Position_COCOA pos, Int dummy) {

    CocoaWindow *thisWindow = (CocoaWindow*) COCOA_REF(wnd);
    int y = pos->y_COCOA;
    int x = pos->x_COCOA;
    
	dispatch_async(dispatch_get_main_queue(), ^{
		NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
		int screenHeight = [[[NSScreen screens] objectAtIndex: 0] frame].size.height;
		int windowHeight = [thisWindow frame].size.height;
		int newY = screenHeight - y - windowHeight;
	    NSPoint p = NSMakePoint(x,newY);
	    [thisWindow setFrameOrigin:p];
	   	[pool drain]; 
	});
}

void _init_external_CTWindow(void) {
	// Install event scanner to keep track of delegate address.
	pthread_mutex_init(&eventMutex, &glob_mutexattr);

    DISABLE(rts);
	addRootScanner(&eventScanner);
	rootsDirty = 1;
	ENABLE(rts);
}