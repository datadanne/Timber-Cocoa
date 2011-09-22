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
  /*  _WindowResize_CTCommon x_1815;
    NEW (_WindowResize_CTCommon, x_1815, WORDS(sizeof(struct _WindowResize_CTCommon)));
    x_1815->GCINFO = __GC___WindowResize_CTCommon;
    x_1815->a = toSize_22;
    CocoaEvent_CTCommon injector_23;
    NEW (CocoaEvent_CTCommon, injector_23, WORDS(sizeof(struct _WindowEvent_CTCommon)));
    ((_WindowEvent_CTCommon)injector_23)->GCINFO = __GC___WindowEvent_CTCommon;
    ((_WindowEvent_CTCommon)injector_23)->Tag = 2;
    ((_WindowEvent_CTCommon)injector_23)->a = (WindowEventType_CTCommon)x_1815;*/

	App_CTCommon app = getApp();

    Size_CTCommon newSize = app->sendWindowResize_CTCommon(app, toSize_22, [sender windowNumber], 0);
	/*
    NSSize currentSize = [sender frame].size;
    
    if (tres->Tag == 1) {
        printf("Timber decides size\n");
        _ResultSize_CTCommon r = (_ResultSize_CTCommon) tres;
        currentSize = NSMakeSize(r->a->width_CTCommon, r->a->height_CTCommon);
    }*/
    
    toSize = NSMakeSize(newSize->width_CTCommon, newSize->height_CTCommon);
    
    return toSize; //currentSize;
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
@end
