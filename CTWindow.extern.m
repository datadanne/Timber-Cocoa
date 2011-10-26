/* 
    ------------- WindowDelegate ---------------------------- 
*/
@implementation WindowDelegate
-(BOOL) windowShouldClose:(id)sender {
	//printf("CLOSIN TIME for window nr %d \n", [sender windowNumber]);
	
	/* Ask Timber whether or not the window should close */
	App_CocoaDef app = getApp();
	return app->l_App_CocoaDef_AppImpl_CocoaDef_CocoaDef->sendWindowCloseRequest_CocoaDef(app->l_App_CocoaDef_AppImpl_CocoaDef_CocoaDef, [sender windowNumber], 0);
}
- (NSSize)windowWillResize:(NSWindow *)sender toSize:(NSSize)toSize {    
    Size_CocoaDef toSize_22;
    NEW (Size_CocoaDef, toSize_22, WORDS(sizeof(struct Size_CocoaDef)));
    toSize_22->GCINFO = __GC__Size_CocoaDef;
    toSize_22->width_CocoaDef = toSize.width;
    toSize_22->height_CocoaDef = toSize.height;

    /* Inform Timber a resize is taking place */
	App_CocoaDef app = getApp();
    app->l_App_CocoaDef_AppImpl_COCOA_COCOA->sendWindowResize_CocoaDef(app->l_App_CocoaDef_AppImpl_CocoaDef_CocoaDef, toSize_22, [sender windowNumber], 0);

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
