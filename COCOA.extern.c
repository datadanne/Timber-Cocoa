#include "COCOA.extern.h"
#import <Cocoa/Cocoa.h>

struct AppCallback;
typedef struct AppCallback * AppCallback;

extern ADDR copy(ADDR obj);

struct AppCallback {
	POLY GCINFO;
	TUP0 (*Code)(AppCallback, App_CTCommon, Time, Time); 
};

// place COCOA struct outisde the garbage collected heap by setting gcinfo to 0
struct Env_COCOA cenv_struct = { 0, &startApplication_COCOA }; 
Env_COCOA cenv				 = &cenv_struct;
                                                        
Env_COCOA cocoa_COCOA(World w, Int dummy) {
    // Keep w but don't use it.
	return cenv;
}

/*
 * Private methods
 */

// GC Root Scanner

extern pthread_mutex_t envmut;
extern int envRootsDirty;

static AppCallback toRunWhenAppFinished;
App_CTCommon app;

App_CTCommon getApp(void) {
	return app;
}

void scanAppInit(void) {
	DISABLE(envmut);
	
	if(toRunWhenAppFinished)
		toRunWhenAppFinished = (AppCallback)copy((ADDR)toRunWhenAppFinished);
	
	if (app)
		app = (App_CTCommon)copy((ADDR)app);

	ENABLE(envmut);
}

struct Scanner appScanner = {scanAppInit, NULL};

@interface CocoaDelegate : NSObject <NSApplicationDelegate>
-(void) applicationDidFinishLaunching:(NSNotification*)aNotification;
@end

@implementation CocoaDelegate
-(void) applicationDidFinishLaunching:(NSNotification*)aNotification {
	printf("Application OK!\n");
	toRunWhenAppFinished->Code(toRunWhenAppFinished, app, 0,0);
	toRunWhenAppFinished = NULL;
}
@end

void *createCocoaApplication(void *arg) {
	NSAutoreleasePool * pool = [[NSAutoreleasePool alloc] init];

	/* https://gnunet.org/svn/GNUnet/src/setup/cocoa/config_cocoa.m */
	NSApp = [NSApplication sharedApplication];
	
	ProcessSerialNumber psn;
	if (GetCurrentProcess(&psn) == noErr) {
		TransformProcessType(
			&psn,kProcessTransformToForegroundApplication);
		SetFrontProcess(&psn);
	}
    /* ... */

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

	CocoaDelegate *delegate = [[CocoaDelegate alloc] init];
	[[NSApplication sharedApplication] setDelegate:delegate];
	
	NSRect rect = NSMakeRect(0, 0, 0, 0);
    NSUInteger styleMask = NSBorderlessWindowMask;
   	[[[CocoaWindow createAndStuff] initWithContentRect:rect styleMask:styleMask  backing:NSBackingStoreBuffered defer:NO] autorelease];
	[pool drain];
	[NSApp run];
		
    return NULL;
}

TUP0 startApplication_COCOA (Env_COCOA env, CLOS clos, Int poly) {
	printf("Initializing cocoa application: ");
	toRunWhenAppFinished = (AppCallback)clos;

	if (!app) {
		app = cocoaApplication_CTApplication(0);
		
		DISABLE(envmut);
		addRootScanner(&appScanner);
		envRootsDirty = 1;
		ENABLE(envmut);   
		                                  			 	
		struct Handler handler = { NULL, &createCocoaApplication };
		addHandler(&handler, 1);
	}
		
	return 0;
}

