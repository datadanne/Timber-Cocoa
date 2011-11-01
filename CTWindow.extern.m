#include "COCOA.extern.h"

// ------------- WindowDelegate ---------------------------- 
@implementation WindowDelegate
-(BOOL) windowShouldClose:(id)sender {
    Thread current_thread = CURRENT();
	TIMERGET(current_thread->msg->baseline);

	/* Ask Timber whether or not the window should close */
	App_CocoaDef app = getApp();
	return ! (app->l_App_CocoaDef_AppImpl_CocoaDef_CocoaDef->sendWindowCloseRequest_CocoaDef(app->l_App_CocoaDef_AppImpl_CocoaDef_CocoaDef, [sender windowNumber], 0));
}
- (NSSize)windowWillResize:(NSWindow *)sender toSize:(NSSize)toSize { 
    Thread current_thread = CURRENT();
	TIMERGET(current_thread->msg->baseline);

    Size_CocoaDef toSize_22;
    NEW (Size_CocoaDef, toSize_22, WORDS(sizeof(struct Size_CocoaDef)));
    toSize_22->GCINFO = __GC__Size_CocoaDef;
    toSize_22->width_CocoaDef = toSize.width;
    toSize_22->height_CocoaDef = toSize.height;

    /* Inform Timber a resize is taking place */
	App_CocoaDef app = getApp();
    app->l_App_CocoaDef_AppImpl_CocoaDef_CocoaDef->sendWindowResize_CocoaDef(app->l_App_CocoaDef_AppImpl_CocoaDef_CocoaDef, toSize_22, [sender windowNumber], 0);

    return toSize;
}
@end

// ------------- CocoaWindow ----------------------------
@implementation CocoaWindow
- (void) setEventDispatcher:(bool(*)(NSEvent*))dispatcher {
	dispatch = dispatcher;
}

- (void) sendEvent:(NSEvent*) event {
    Thread current_thread = CURRENT();
	TIMERGET(current_thread->msg->baseline);
	if (!dispatch || !dispatch(event)) {
	    [super sendEvent:event];
	}
}

@end
