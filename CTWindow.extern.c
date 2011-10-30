#include "CTWindow.extern.h"
#import "CTWindow.extern.m"

Bool compareKeys_CTWindow(CocoaKey_CocoaDef aKey, CocoaKey_CocoaDef anotherKey) {
    return ((int)aKey == (int)anotherKey);
}

@interface NSEvent (DeviceDelta)
  - (float)deviceDeltaX;
  - (float)deviceDeltaY;
@end

bool dispatchEventToTimber(NSEvent* event) { 
    InputEvent_CocoaDef receivedEvent; //should be global if has to be a root for GC
    
	if ([event type] == NSLeftMouseDown) {
        Position_CocoaDef pos;
	    NEW (Position_CocoaDef, pos, WORDS(sizeof(struct Position_CocoaDef)));
	    pos->GCINFO = __GC__Position_CocoaDef;
		NSPoint p = [event locationInWindow];
	    pos->x_CocoaDef = p.x;
		pos->y_CocoaDef = p.y;
		
		DEBUG("C detects mouse at %f , %f", p.x, p.y);
		
	    _MouseClicked_CocoaDef clicked;
	    NEW (_MouseClicked_CocoaDef, clicked, WORDS(sizeof(struct _MouseClicked_CocoaDef)));
	    clicked->GCINFO = __GC___MouseClicked_CocoaDef;
	    clicked->Tag = 3;
	    clicked->a = pos;
	   
	    NEW (InputEvent_CocoaDef, receivedEvent, WORDS(sizeof(struct _MouseEvent_CocoaDef)));
	    ((_MouseEvent_CocoaDef)receivedEvent)->GCINFO = __GC___MouseEvent_CocoaDef;
	    ((_MouseEvent_CocoaDef)receivedEvent)->Tag = 1;
	    ((_MouseEvent_CocoaDef)receivedEvent)->a = (MouseEventType_CocoaDef)clicked;
		
		DEBUG("Event is to be sent for window nr %d", [event windowNumber]);
		
	} else if ([event type] == NSKeyUp || [event type] == NSFlagsChanged) {
	    _KeyReleased_CocoaDef released;
        NEW (_KeyReleased_CocoaDef, released, WORDS(sizeof(struct _KeyReleased_CocoaDef)));
        released->GCINFO = __GC___KeyReleased_CocoaDef;
        released->Tag = 0;
        released->a = (CocoaKey_CocoaDef)(POLY)(126 - [event keyCode]);

        DEBUG("KEY CODE %d\n", [event keyCode]);

        NEW (InputEvent_CocoaDef, receivedEvent, WORDS(sizeof(struct _KeyEvent_CocoaDef)));
        ((_KeyEvent_CocoaDef)receivedEvent)->GCINFO = __GC___KeyEvent_CocoaDef;
        ((_KeyEvent_CocoaDef)receivedEvent)->Tag = 0;
        ((_KeyEvent_CocoaDef)receivedEvent)->a = (KeyEventType_CocoaDef)released;

	} else if ([event type] == NSKeyDown || [event type] == NSFlagsChanged) {
		_KeyPressed_CocoaDef pressed;
	    NEW (_KeyPressed_CocoaDef, pressed, WORDS(sizeof(struct _KeyPressed_CocoaDef)));
	    pressed->GCINFO = __GC___KeyPressed_CocoaDef;
	    pressed->Tag = 1;
        pressed->a = (CocoaKey_CocoaDef)(POLY)(126 - [event keyCode]);
        
	    DEBUG("KEY CODE %d\n", [event keyCode]);

	    NEW (InputEvent_CocoaDef, receivedEvent, WORDS(sizeof(struct _KeyEvent_CocoaDef)));
	    ((_KeyEvent_CocoaDef)receivedEvent)->GCINFO = __GC___KeyEvent_CocoaDef;
	    ((_KeyEvent_CocoaDef)receivedEvent)->Tag = 0;
        ((_KeyEvent_CocoaDef)receivedEvent)->a = (KeyEventType_CocoaDef)pressed;

	} else if ([event type] == NSScrollWheel) {

        DEBUG("Scrolling event! \n");            

   		NSPoint p = [event locationInWindow];

        Position_CocoaDef position;
        NEW(Position_CocoaDef, position, WORDS(sizeof(struct Position_CocoaDef)));
        position->GCINFO = __GC__Position_CocoaDef;
        position->x_CocoaDef = p.x;
        position->y_CocoaDef = p.y;
        
        _MouseWheelScroll_CocoaDef scroll;
        NEW (_MouseWheelScroll_CocoaDef, scroll, WORDS(sizeof(struct _MouseWheelScroll_CocoaDef)));
        scroll->GCINFO = __GC___MouseWheelScroll_CocoaDef;
        scroll->Tag = 4;
        scroll->a = position;

        float deltaX;
        float deltaY;
#if __ENVIRONMENT_MAC_OS_X_VERSION_MIN_REQUIRED__ >= 1070
        if ([event hasPreciseScrollingDeltas]) {
            deltaX = [event scrollingDeltaX];
            deltaY = [event scrollingDeltaY];
        }
        if ([event isDirectionInvertedFromDevice]) {
            deltaX *= -1;
            deltaY *= -1;
        }
#else
        deltaX = -1 * [event deviceDeltaX];
        deltaY = -1 * [event deviceDeltaY];
        
#endif

        scroll->b = deltaX;
        scroll->c = deltaY;

        NEW (InputEvent_CocoaDef, receivedEvent, WORDS(sizeof(struct _MouseEvent_CocoaDef)));
        ((_MouseEvent_CocoaDef)receivedEvent)->GCINFO = __GC___MouseEvent_CocoaDef;
        ((_MouseEvent_CocoaDef)receivedEvent)->Tag = 1;
        ((_MouseEvent_CocoaDef)receivedEvent)->a = (MouseEventType_CocoaDef)scroll;     
        
	} else {
	    
        // printf("Event of type %d was discarded\n", [event type]);
        return false;
        
    }

	App_CocoaDef app = getApp();    
    return app->l_App_CocoaDef_AppImpl_CocoaDef_CocoaDef->sendInputEvent_CocoaDef(
        app->l_App_CocoaDef_AppImpl_CocoaDef_CocoaDef, (InputEvent_CocoaDef)receivedEvent, 
        [event windowNumber], 0);
}

// --------- Window ----------------------------------------------
/*
void scanEventReceived() {
	DISABLE(rts);
	if(receivedEvent)
		receivedEvent = (InputEvent_CocoaDef)copy((ADDR)receivedEvent);
	ENABLE(rts);
}

struct Scanner eventScanner = {scanEventReceived, NULL};
*/

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
        window = [[CocoaWindow alloc] initWithContentRect:frameRect styleMask:styleMask  
            backing:NSBackingStoreBuffered defer:NO]; 
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
    initResult->b = (POLY)([window windowNumber]);
    return initResult;
}

TUP0 destroyCocoaWindow_CTWindow(Int cocoaRef) {
    dispatch_async(dispatch_get_main_queue(), ^{
	    NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
        CocoaWindow *thisWindow = (CocoaWindow*) cocoaRef;
	    [thisWindow close];
	    [pool drain];
    });
}

TUP0 windowSetContentView_CTWindow(Int windowRef, Int cmpRef) {
    dispatch_async(dispatch_get_main_queue(), ^{   
	    NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];  
        CocoaWindow *wnd = (CocoaWindow*) windowRef;
        NSView *view = (NSView*) cmpRef;                                             
	    [wnd setContentView: view];
	    [pool release];
    });
}

TUP0 windowSetVisible_CTWindow(Int cocoaRef) {  
    dispatch_async(dispatch_get_main_queue(), ^{ 
	    NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
        CocoaWindow *thisWindow = (CocoaWindow*) cocoaRef;
	    [thisWindow orderFront: NULL];
	    [pool drain];
    });
}

TUP0 windowSetHidden_CTWindow(Int cocoaRef) {
    dispatch_async(dispatch_get_main_queue(), ^{ 
	    NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
        CocoaWindow *thisWindow = (CocoaWindow*) cocoaRef;
	    [thisWindow orderOut: NULL];
	    [pool drain];
    });
}

TUP0 windowSetFocus_CTWindow(Int cocoaRef, Int cmpRef) {
    dispatch_async(dispatch_get_main_queue(), ^{ 
	    NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
        CocoaWindow *thisWindow = (CocoaWindow*) cocoaRef;
        NSView *responder = (NSView*) cmpRef;
	    [thisWindow makeFirstResponder: responder];
	    [pool drain];
    });
}

TUP0 windowSetSize_CTWindow (Int cocoaRef, Size_CocoaDef size) {
    int width = size->width_CocoaDef;
    int height = size->height_CocoaDef;
	dispatch_async(dispatch_get_main_queue(), ^{
	    NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
	    CocoaWindow *thisWindow = (CocoaWindow*) cocoaRef;
	    [thisWindow setContentSize: NSMakeSize(width, height)];
		[pool drain];
    });
}

TUP0 windowSetPosition_CTWindow (Int cocoaRef, Position_CocoaDef pos) {
    int y = pos->y_CocoaDef;
    int x = pos->x_CocoaDef;
	dispatch_async(dispatch_get_main_queue(), ^{
		NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
        CocoaWindow *thisWindow = (CocoaWindow*) cocoaRef;
		int screenHeight = [[[NSScreen screens] objectAtIndex: 0] frame].size.height;
		int windowHeight = [thisWindow frame].size.height;
		int newY = screenHeight - y - windowHeight;
	    NSPoint p = NSMakePoint(x,newY);
	    [thisWindow setFrameOrigin:p];
	   	[pool drain]; 
	});
} 

TUP0 windowSetResizable_CTWindow (Int cocoaRef, Bool resizable) {
    NSUInteger styleMask;
    if (resizable) {
        styleMask = (NSTitledWindowMask | NSClosableWindowMask | NSResizableWindowMask);
    } else {
        styleMask = (NSTitledWindowMask | NSClosableWindowMask);
    }                                                            
    dispatch_async(dispatch_get_main_queue(), ^{
		NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
        CocoaWindow *thisWindow = (CocoaWindow*) cocoaRef;
	    [thisWindow setStyleMask: styleMask];
	   	[pool drain];         
    });
}

TUP0 windowSetTitle_CTWindow (Int cocoaRef, LIST title) {
    char *buf = listToChars(title); 
    dispatch_async(dispatch_get_main_queue(), ^{
		NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
        CocoaWindow *thisWindow = (CocoaWindow*) cocoaRef;
	    [thisWindow setTitle: [NSString stringWithFormat:@"%s", buf]];
	   	[pool drain];         
        free(buf);
    });
}  
void _init_external_CTWindow(void) {
/*
    DISABLE(rts);
	addRootScanner(&eventScanner);
	rootsDirty = 1;
	ENABLE(rts);
*/
}