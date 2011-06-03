#import <Cocoa/Cocoa.h>
#include <stdio.h>

#include <objc/objc.h>
#include <objc/runtime.h>
#include <objc/message.h>


@interface MyWindow : NSObject
+(void)aMethod:(id)param;
@end

@implementation MyWindow
+(void)aMethod:(id)param{
	[NSAutoreleasePool new];


	//[NSApplication sharedApplication];

    [NSApp setActivationPolicy:NSApplicationActivationPolicyRegular];
    id menubar = [[NSMenu new] autorelease];
    id appMenuItem = [[NSMenuItem new] autorelease];
    [menubar addItem:appMenuItem];
    [NSApp setMainMenu:menubar];
    id appMenu = [[NSMenu new] autorelease];
    id appName = [[NSProcessInfo processInfo] processName];
    id quitTitle = [@"Quit " stringByAppendingString:appName];
    id quitMenuItem = [[[NSMenuItem alloc] initWithTitle:quitTitle
        action:@selector(terminate:) keyEquivalent:@"q"] autorelease];
    [appMenu addItem:quitMenuItem];
    [appMenuItem setSubmenu:appMenu];
    id window = [[[NSWindow alloc] initWithContentRect:NSMakeRect(0, 0, 200, 200)
        styleMask:NSTitledWindowMask backing:NSBackingStoreBuffered defer:NO]
            autorelease];
    [window cascadeTopLeftFromPoint:NSMakePoint(20,20)];
    [window setTitle:appName];
    [window makeKeyAndOrderFront:nil];
    [NSApp activateIgnoringOtherApps:YES];

    [NSApp run];
}
@end

static MyWindow *myWindow;

int main()
{	
	NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
	
	NSThread *a = [[NSThread alloc] init];
	
	[NSApplication sharedApplication];
	
	
    [NSThread detachNewThreadSelector:@selector(aMethod:) toTarget:[MyWindow class] withObject:nil];
	[pool drain];
	while(1);
	
}