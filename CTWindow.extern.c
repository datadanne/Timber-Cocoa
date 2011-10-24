#include "CTWindow.extern.h"
#import "CTWindow.extern.m"

extern pthread_mutex_t rts;
extern int rootsDirty;

InputEvent_COCOA receivedEvent;
pthread_mutex_t eventMutex;

@interface NSEvent (DeviceDelta)
  - (float)deviceDeltaX;
  - (float)deviceDeltaY;
@end

bool dispatchEventToTimber(NSEvent* event) { 
	printf("C: Event received in dispatchEventToTimber\n"); 

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

	App_COCOA app = getApp();    
    return app->l_App_COCOA_AppImpl_COCOA_COCOA->sendInputEvent_COCOA(app->l_App_COCOA_AppImpl_COCOA_COCOA, (InputEvent_COCOA)receivedEvent, [event windowNumber], 0);
}

// --------- Window ----------------------------------------------
void scanEventReceived() {
	DISABLE(rts);
	if(receivedEvent)
		receivedEvent = (InputEvent_COCOA)copy((ADDR)receivedEvent);
	ENABLE(rts);
}

struct Scanner eventScanner = {scanEventReceived, NULL};
static WindowDelegate *delegate;

TUP2 initCocoaWindow_CTWindow(TUP0 dummy) {   
	DEBUG("Initializing window...");
    __block CocoaWindow *window;
    // Keep this as sync to ensure window is completely created before use.
    // Also, with async there would be a risk of GC moving wnd before it is accessed.
    dispatch_sync(dispatch_get_main_queue(), ^{
    	NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];	
        NSRect frameRect = NSMakeRect(0, [[[NSScreen screens] objectAtIndex: 0] frame].size.height, 1, 1);
        NSUInteger styleMask = (NSTitledWindowMask | NSClosableWindowMask | NSResizableWindowMask);
        window = [[CocoaWindow alloc] initWithContentRect:frameRect styleMask:styleMask  backing:NSBackingStoreBuffered defer:NO]; 
        [window setTitle:@"CocoaWindow"];
        [window setEventDispatcher:dispatchEventToTimber];

        if (!delegate)
        	delegate = [[WindowDelegate alloc] init];

        [window setDelegate:delegate];
        [window makeKeyAndOrderFront:window];
        [pool drain];
    });

    TUP2 initResult;
    NEW (TUP2, initResult, WORDS(sizeof(struct TUP2)));
    initResult->GCINFO = __GC__TUP2+((5 * (((BITS32)1 | (BITS32)2))));
    initResult->a = (POLY)window;
    initResult->b = (POLY)([window windowNumber]-1); // -1 needed from conversion? No?
    return initResult;
}

TUP0 destroyCocoaWindow_CTWindow(Int cocoaRef) {
    CocoaWindow *thisWindow = (CocoaWindow*) cocoaRef;
    dispatch_async(dispatch_get_main_queue(), ^{
    
	    NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
	    [thisWindow close];
	    [pool drain];
        });
}

TUP0 windowSetContentView_CTWindow(Int windowRef, Int cmpRef) {
	NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
    CocoaWindow *wnd = (CocoaWindow*) windowRef;
    CocoaView *view = (CocoaView*) cmpRef;                                                  
	[wnd setContentView: view];
	[pool release];
}

TUP0 windowSetVisible_CTWindow(Int cocoaRef) {  
	NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
    CocoaWindow *thisWindow = (CocoaWindow*) cocoaRef;
	[thisWindow orderFront: NULL];
	[pool drain];
}

TUP0 windowSetHidden_CTWindow(Int cocoaRef) {
	NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
    CocoaWindow *thisWindow = (CocoaWindow*) cocoaRef;
	[thisWindow orderOut: NULL];
	[pool drain];
}

TUP0 windowSetFocus_CTWindow(Int cocoaRef, Int cmpRef) {
	NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
    CocoaWindow *thisWindow = (CocoaWindow*) cocoaRef;
    NSView *responder = (NSView*) cmpRef;
	[thisWindow makeFirstResponder: responder];
	[pool drain];
}

TUP0 windowSetSize_CTWindow (Int cocoaRef, Size_COCOA size) {
    CocoaWindow *thisWindow = (CocoaWindow*) cocoaRef;    int width = size->width_COCOA;
    int height = size->height_COCOA;

	dispatch_async(dispatch_get_main_queue(), ^{
	    NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
	    [thisWindow setContentSize: NSMakeSize(width, height)];
		[pool drain];
    });
}

TUP0 windowSetPosition_CTWindow (Int cocoaRef, Position_COCOA pos) {
    CocoaWindow *thisWindow = (CocoaWindow*) cocoaRef;
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
	pthread_mutex_init(&eventMutex, &glob_mutexattr);
    DISABLE(rts);
	addRootScanner(&eventScanner);
	rootsDirty = 1;
	ENABLE(rts);
}