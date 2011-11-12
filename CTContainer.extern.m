// ------------- CocoaView ----------------------------               
@interface CocoaView : NSView {
@private
    int r;
    int g;
    int b;
    float alpha;
}
-(void) setBackgroundColor:(int) ra:(int) ga:(int) ba:(float) newAlpha;
@end

@implementation CocoaView
- (BOOL)isFlipped {
    return YES;
}
- (id)init {
    if ((self = [super init])) {
        r = 100; 
        g = 100;
        b = 100;
        alpha = 1.0;
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
    CGContextSetRGBFillColor(context, r/255.0, g/255.0, b/255.0, alpha);
    CGContextFillRect(context, NSRectToCGRect(dirtyRect));
}
-(void) setBackgroundColor:(int) ra:(int) ga:(int) ba :(float) newAlpha{
    r = ra;
    g = ga;
    b = ba;
    alpha = newAlpha;
    [self setNeedsDisplay:YES];
}
@end

