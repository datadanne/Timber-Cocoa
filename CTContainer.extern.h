#ifndef _COCOA_NSCONTAINER_TIMBER_
#define _COCOA_NSCONTAINER_TIMBER_

#import <Cocoa/Cocoa.h>

/* 
    Extended version of NSView, adds method for changing background color.
*/
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