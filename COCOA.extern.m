#include "COCOA.extern.h"

// ------------- CocoaDelegate ---------------------------- 
@interface CocoaDelegate : NSObject <NSApplicationDelegate>
-(void) applicationDidFinishLaunching:(NSNotification*)aNotification;
@end

@implementation CocoaDelegate
-(void) applicationDidFinishLaunching:(NSNotification*)aNotification {
//    DISABLE(rts);
//    if (toRunWhenAppFinished->Code == NULL) {
//        printf("COCOA.extern.c: CRITICAL ERROR in applicationDidFinishLaunching: nothing to run!\n");
//    } else {
//        ENABLE(rts);
	    toRunWhenAppFinished->Code(toRunWhenAppFinished, getApp(), 0,0);
//	    toRunWhenAppFinished = NULL;
//        DISABLE(rts);
//	}
//    ENABLE(rts);
}
@end