#ifndef COCOAHELPERS_H
#define COCOAHELPERS_H

@interface WindowDelegate : NSObject <NSWindowDelegate>
@end

@interface CocoaView : NSView {
@private
    int r;
    int g;
    int b;
}
-(void) setBackgroundColor:(int) ra:(int) ga:(int) ba;
@end

@interface CocoaWindow : NSWindow {
@private
	bool (*dispatch)(NSEvent* event);
}
- (void) setEventDispatcher:(bool(*)(NSEvent*))dispatcher;
@end

#endif
