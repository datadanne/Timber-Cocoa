/* 
    ------------- WindowDelegate ---------------------------- 
*/
@implementation WindowDelegate
-(BOOL) windowShouldClose:(id)sender {
	printf("CLOSIN TIME for window nr %d \n", [sender windowNumber]);
	
	/* Ask Timber whether or not the window should close */
	App_CTCommon app = getApp();
	return app->sendWindowCloseRequest_CTCommon(app, [sender windowNumber], 0);
}
- (NSSize)windowWillResize:(NSWindow *)sender toSize:(NSSize)toSize {    
    Size_CTCommon toSize_22;
    NEW (Size_CTCommon, toSize_22, WORDS(sizeof(struct Size_CTCommon)));
    toSize_22->GCINFO = __GC__Size_CTCommon;
    toSize_22->width_CTCommon = toSize.width;
    toSize_22->height_CTCommon = toSize.height;

    /* Inform Timber a resize is taking place */
	App_CTCommon app = getApp();
    app->sendWindowResize_CTCommon(app, toSize_22, [sender windowNumber], 0);

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
