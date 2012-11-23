#include "COCOA.extern.h"

// ------------- CocoaDelegate ---------------------------- 
@interface CocoaDelegate : NSObject <NSApplicationDelegate>
-(void) applicationDidFinishLaunching:(NSNotification*)aNotification;
@end

@implementation CocoaDelegate
-(void) applicationDidFinishLaunching:(NSNotification*)aNotification {
	    toRunWhenAppFinished->Code(toRunWhenAppFinished, getApp(), 0,0);
}
@end