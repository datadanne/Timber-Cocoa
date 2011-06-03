#include <stdio.h>

#include <objc/objc.h>
#include <objc/runtime.h>
#include <objc/message.h>
#import <Cocoa/Cocoa.h>


@interface MyWindow : NSObject
-(void)aMethod:(id)param;
@end

@implementation MyWindow
-(void)aMethod:(id)param{
	printf("Creating window... \n");
    NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
	
	[NSApplication sharedApplication];
	
	
	NSRect frame = NSMakeRect(20,20,250,250);
	printf("Making rect\n");
	NSWindow *window = [[NSWindow alloc] initWithContentRect:frame
												   styleMask:(NSResizableWindowMask | NSClosableWindowMask | NSTitledWindowMask)
													 backing:NSBackingStoreBuffered
													   defer:NO];
	[window setBackgroundColor:[NSColor grayColor]];
	printf("BGColor was set to gray\n");
	[window performSelectorOnMainThread:@selector(makeKeyAndOrderFront:) withObject:NSApp waitUntilDone:NO];

	printf("Runloop ended for some reason?\n");
	[pool drain];
}
@end


static MyWindow *myWindow;

Msg showWindow (Env_Cocoa env, Time base, Time deadline) {
	NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
	[NSThread detachNewThreadSelector:@selector(aMethod:) toTarget:myWindow withObject:nil];
	 
	[pool drain];
}

struct Env_Cocoa env_cocoa = {0, &showWindow};

Env_Cocoa cocoa_Cocoa(World w, Int dummy) {
	printf("timber initiated\n");
    NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
	[NSApplication sharedApplication];

	myWindow = [[MyWindow alloc] init];
	//[myWindow aMethod:nil];


	[pool drain];
	return &env_cocoa;
}
