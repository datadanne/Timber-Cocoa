#import <Cocoa/Cocoa.h>


int main(int argc, char **argv)	{

	/*ProcessSerialNumber psn;
	if (GetCurrentProcess(&psn) == noErr) {
		TransformProcessType(
							 &psn,kProcessTransformToForegroundApplication);
		SetFrontProcess(&psn);
	}
	
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
	
	NSApplicationDelegate *delegate = [[NSApplicationDelegate alloc] init];
	[[NSApplication sharedApplication] setDelegate:delegate];
	*/
	
	// main.m
    /*#import <Cocoa/Cocoa.h>

    {
     NSAutoreleasePool * pool = [[NSAutoreleasePool alloc] init];
     NSLog(@"NSApp=%@", NSApp);
     [NSApplication sharedApplication];
     NSLog(@"NSApp=%@", NSApp);
     // [NSBundle loadNibNamed:@"MainMenu" owner:NSApp];
     NSRect frame = NSMakeRect(100, 100, 200, 200);
     NSUInteger styleMask = NSBorderlessWindowMask;
     NSRect rect = [NSWindow contentRectForFrameRect:frame styleMask:styleMask];
     NSWindow * window = [[NSWindow alloc] initWithContentRect:rect styleMask:styleMask
     backing: NSBackingStoreBuffered defer:false];
     [window setBackgroundColor:[NSColor blueColor]];
     [window makeKeyAndOrderFront: window];
     [pool drain];
     [NSApp run];
    }*/
    
    NSAutoreleasePool * pool = [[NSAutoreleasePool alloc] init];

    /* https://gnunet.org/svn/GNUnet/src/setup/cocoa/config_cocoa.m */
    [NSApplication sharedApplication];
    	
	NSRect rect = NSMakeRect(100, 100, 200, 200);
    NSUInteger styleMask = (NSTitledWindowMask | NSClosableWindowMask | NSResizableWindowMask);
	NSWindow *window = [[NSWindow alloc] initWithContentRect:rect styleMask:styleMask  backing:NSBackingStoreBuffered defer:NO]; 

    //[window cascadeTopLeftFromPoint:NSMakePoint(10,10)];
    [window setTitle:@"new WINDOW!"];
    [window setBackgroundColor:[NSColor blueColor]];
    [window makeKeyAndOrderFront: window];
	[pool drain];
	[NSApp run];
	
	return 0;
}