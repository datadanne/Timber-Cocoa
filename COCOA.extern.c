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
struct CocoaEnv_COCOA cenv_struct = { 0, &startApplication_COCOA }; 
CocoaEnv_COCOA cenv				 = &cenv_struct;
                                                        
CocoaEnv_COCOA cocoa_COCOA(World w, Int dummy) {
    // Keep w but don't use it.
	return cenv;
}

/*
 * Private methods
 */

// GC Root Scanner

extern pthread_mutex_t envmut;
extern int rootsDirty;

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
	
    DEBUG("GC in scanAppInit: Scanning app something something, done?\n");
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

void createCocoaApplication(void) {
    printf("hello says createCocoaApplication\n");
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
	
	[pool drain];
	[NSApp run];

}

extern pthread_cond_t sleepVar;

TUP0 startApplication_COCOA (CocoaEnv_COCOA env, CLOS clos, Int poly) {
	printf("Initializing cocoa application: ");
	toRunWhenAppFinished = (AppCallback)clos;

	if (!app) {
		app = cocoaApplication_CTApplication(0);

        runAsMainContinuation(createCocoaApplication);
        pthread_cond_signal(&sleepVar);
	}
	
    return 0;
}

void _init_external_COCOA(void) {
    DISABLE(rts);
	addRootScanner(&appScanner);
	rootsDirty = 1;
	ENABLE(rts);
}