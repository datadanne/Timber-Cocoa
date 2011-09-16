#ifndef _COCOA_CTWINDOW_TIMBER_
#define _COCOA_CTWINDOW_TIMBER_

#import <Cocoa/Cocoa.h>

/* 
    Window delegate allows interception of window close events.
*/
@interface WindowDelegate : NSObject <NSWindowDelegate>
@end

@interface CocoaWindow : NSWindow {
@private
	bool (*dispatch)(NSEvent* event);
}
- (void) setEventDispatcher:(bool(*)(NSEvent*))dispatcher;
@end
        
#endif