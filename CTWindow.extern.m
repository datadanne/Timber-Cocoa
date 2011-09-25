/* 
    ------------- WindowDelegate ---------------------------- 
*/
@implementation WindowDelegate
-(BOOL) windowShouldClose:(id)sender {
	
	App_CTCommon app = getApp();

	CocoaEvent_CTCommon superTest_107;
    NEW (CocoaEvent_CTCommon, superTest_107, WORDS(sizeof(struct _WindowEvent_CTCommon)));
    ((_WindowEvent_CTCommon)superTest_107)->GCINFO = __GC___WindowEvent_CTCommon;
    ((_WindowEvent_CTCommon)superTest_107)->Tag = 2;
    ((_WindowEvent_CTCommon)superTest_107)->a = (WindowEventType_CTCommon)1;

	printf("CLOSIN TIME for window nr %d \n", [sender windowNumber]);
	app->sendInputEvent_CTCommon(app, (CocoaEvent_CTCommon)superTest_107, [sender windowNumber], 0);
	return 0;
}
- (NSSize)windowWillResize:(NSWindow *)sender toSize:(NSSize)toSize {    
    Size_CTCommon toSize_22;
    NEW (Size_CTCommon, toSize_22, WORDS(sizeof(struct Size_CTCommon)));
    toSize_22->GCINFO = __GC__Size_CTCommon;
    toSize_22->width_CTCommon = toSize.width;
    toSize_22->height_CTCommon = toSize.height;

	App_CTCommon app = getApp();

    /* Inform Timber a resize is taking place */
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
