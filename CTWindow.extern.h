#ifndef CTWINDOW_EXTERN_H_
#define CTWINDOW_EXTERN_H_

#import <Cocoa/Cocoa.h>

#include "rts.h"
extern pthread_mutex_t rts;
extern int rootsDirty;

// Window delegate allows interception of window close events.
@interface WindowDelegate : NSObject <NSWindowDelegate>
@end

@interface CocoaWindow : NSWindow {
@private
	bool (*dispatch)(NSEvent* event);
}
- (void) setEventDispatcher:(bool(*)(NSEvent*))dispatcher;
@end
Bool compareKeys_CTWindow(CocoaKey_CocoaDef, CocoaKey_CocoaDef);
TUP2 initCocoaWindow_CTWindow(TUP0);
TUP0 destroyCocoaWindow_CTWindow(Int);
TUP0 windowSetContentView_CTWindow(Int,Int);
TUP0 windowSetHidden_CTWindow(Int);
TUP0 windowSetVisible_CTWindow(Int);
TUP0 windowSetSize_CTWindow(Int, Size_CocoaDef);
TUP0 windowSetPosition_CTWindow(Int, Position_CocoaDef);
TUP0 windowSetFocus_CTWindow(Int,Int);

#endif