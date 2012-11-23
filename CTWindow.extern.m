#include "Cocoa.extern.h"
#include "rts.h"

// ------------- WindowDelegate ---------------------------- 
// Window delegate allows interception of window close events
@interface WindowDelegate : NSObject <NSWindowDelegate>
@end

@implementation WindowDelegate
-(BOOL) windowShouldClose:(id)sender {
    Thread current_thread = CURRENT();
	TIMERGET(current_thread->msg->baseline);
    enterLocalPtrScope();
    
	/* Ask Timber whether or not the window should close */
	App_CocoaDef app = getApp();
    BOOL result = ! (app->l_App_CocoaDef_AppImpl_CocoaDef_CocoaDef->sendWindowCloseRequest_CocoaDef(app->l_App_CocoaDef_AppImpl_CocoaDef_CocoaDef, [sender windowNumber], 0));
    
    leaveLocalPtrScope();
    return result;
}
- (NSSize)windowWillResize:(NSWindow *)sender toSize:(NSSize)toSize {
    Thread current_thread = CURRENT();
	TIMERGET(current_thread->msg->baseline);
    enterLocalPtrScope();
    
    Size_CocoaDef toSize_22;
    NEW (Size_CocoaDef, toSize_22, WORDS(sizeof(struct Size_CocoaDef)));
    toSize_22->GCINFO = __GC__Size_CocoaDef;
    toSize_22->width_CocoaDef = toSize.width;
    toSize_22->height_CocoaDef = toSize.height;

    /* Inform Timber a resize is taking place */
	App_CocoaDef app = getApp();
    app->l_App_CocoaDef_AppImpl_CocoaDef_CocoaDef->sendWindowResize_CocoaDef(app->l_App_CocoaDef_AppImpl_CocoaDef_CocoaDef, toSize_22, [sender windowNumber], 0);
    
    leaveLocalPtrScope();
    return toSize;
}
@end

// ------------- CocoaWindow ----------------------------
@interface CocoaWindow : NSWindow {
@private
	bool (*dispatch)(NSEvent* event);
}
- (void) setEventDispatcher:(bool(*)(NSEvent*))dispatcher;
@end

@implementation CocoaWindow
- (void) setEventDispatcher:(bool(*)(NSEvent*))dispatcher {
	dispatch = dispatcher;
}

- (void) sendEvent:(NSEvent*) event {
    Thread current_thread = CURRENT();
	TIMERGET(current_thread->msg->baseline);
    enterLocalPtrScope();
    
	if (!dispatch || !dispatch(event)) {
	    [super sendEvent:event];
	}
    
    leaveLocalPtrScope();
}
- (void)noResponderFor:(SEL)eventSelector {
    // This is to shadow the default implementation, which beeps on unhandled keyDown events.
    // Cocoa should not beep, as the key might be listened on in Timber.
}
@end
