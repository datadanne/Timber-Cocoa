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
	app->eventDispatcher_CTCommon(app, (CocoaEvent_CTCommon)superTest_107, [sender windowNumber], 0);
	return 1;
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
