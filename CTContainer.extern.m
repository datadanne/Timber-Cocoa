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


/* 
    ------------- CocoaView ----------------------------       
*/        
@implementation CocoaView
- (id)init {
    if ((self = [super init])) {
        r = 100; 
        g = 100;
        b = 100;
    }
    return self;
}
- (id)initWithFrame:(NSRect)frame {
    if ((self = [super initWithFrame:frame])) {
        r = 100;
        g = 100;
        b = 100;
    }
    return self;
}      
- (void)dealloc {
    [super dealloc];
}
- (void)drawRect:(NSRect)dirtyRect {
    // Fill in background Color
    CGContextRef context = (CGContextRef) [[NSGraphicsContext currentContext] graphicsPort];
    CGContextSetRGBFillColor(context, r/255.0, g/255.0, b/255.0, 1.0);
    CGContextFillRect(context, NSRectToCGRect(dirtyRect));
}
-(void) setBackgroundColor:(int) ra:(int) ga:(int) ba {
    r = ra;
    g = ga;
    b = ba;
    [self setNeedsDisplay:YES];
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
