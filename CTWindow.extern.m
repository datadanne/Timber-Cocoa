/* 
    ------------- WindowDelegate ---------------------------- 
*/
@implementation WindowDelegate
-(BOOL) windowShouldClose:(id)sender {
	//printf("CLOSIN TIME for window nr %d \n", [sender windowNumber]);
	
	/* Ask Timber whether or not the window should close */
	App_COCOA app = getApp();
	return app->l_App_COCOA_AppImpl_COCOA_COCOA->sendWindowCloseRequest_COCOA(app->l_App_COCOA_AppImpl_COCOA_COCOA, [sender windowNumber], 0);
}
- (NSSize)windowWillResize:(NSWindow *)sender toSize:(NSSize)toSize {    
    Size_COCOA toSize_22;
    NEW (Size_COCOA, toSize_22, WORDS(sizeof(struct Size_COCOA)));
    toSize_22->GCINFO = __GC__Size_COCOA;
    toSize_22->width_COCOA = toSize.width;
    toSize_22->height_COCOA = toSize.height;

    /* Inform Timber a resize is taking place */
	App_COCOA app = getApp();
    app->l_App_COCOA_AppImpl_COCOA_COCOA->sendWindowResize_COCOA(app->l_App_COCOA_AppImpl_COCOA_COCOA, toSize_22, [sender windowNumber], 0);

    return toSize;
}
@end


// ------------- CocoaWindow ----------------------------
@implementation CocoaWindow
- (void) setEventDispatcher:(bool(*)(NSEvent*))dispatcher {
	dispatch = dispatcher;
}
- (void) sendEvent:(NSEvent*) event {	
	if (!dispatch || !dispatch(event)) {
	    [super sendEvent:event];
	}
}
+ (id) createAndStuff {
    return [super alloc];
}
@end
