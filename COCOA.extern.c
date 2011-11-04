#include "COCOA.extern.h"
#import <Cocoa/Cocoa.h>
#import "COCOA.extern.m"

int length (LIST list) {
    int l;
    for(l=0; ((int)list)!=0; l++)
        list = ((CONS)list)->tl;
    return l;
}

char *listToChars(LIST str) {
	int len = 0;
    int size = length(str);
    char* buf = malloc(sizeof(char)*size+1);
    while (len < size) {
      buf[len++] = (Char)(Int)((CONS)str)->hd;
      str = ((CONS)str)->tl;
    }
	buf[len] = 0;
    return buf;
}

// GCINFO = 0 makes it static (not GC'ed)
struct CocoaEnv_CocoaDef cenv_struct = { 0, &startApplication_COCOA }; 
CocoaEnv_CocoaDef cenv = &cenv_struct;                                                        

CocoaEnv_CocoaDef cocoa_COCOA(World w, Int dummy) {
	return cenv;
}

// Root scanner for GC
App_CocoaDef app;
void scanAppInit(void);
struct Scanner appScanner = {scanAppInit, NULL};

void scanAppInit(void) {
    DISABLE(rts);
	if (app) {
		app = (App_CocoaDef)copy((ADDR)app);
	}
	if (toRunWhenAppFinished) {
		toRunWhenAppFinished = (AppCallback)copy((ADDR)toRunWhenAppFinished);
	}
	ENABLE(rts);
}

App_CocoaDef getApp(void) {
	return app;
}

void createCocoaApplication(Thread current_thread) {
	NSAutoreleasePool * pool = [[NSAutoreleasePool alloc] init];
	NSApp = [NSApplication sharedApplication];
	 
	// code from https://gnunet.org/svn/GNUnet/src/setup/cocoa/config_cocoa.m 
	ProcessSerialNumber psn;
	if (GetCurrentProcess(&psn) == noErr) {
		TransformProcessType(
			&psn,kProcessTransformToForegroundApplication);
		SetFrontProcess(&psn);
	}

    // Add Quit option to app menu
	id menubar = [[NSMenu new] autorelease];
    id appMenuItem = [[NSMenuItem new] autorelease];
    [menubar addItem:appMenuItem];
    [NSApp setMainMenu:menubar];
    id appMenu = [[NSMenu new] autorelease];
    id appName = [[NSProcessInfo processInfo] processName];
    id quitTitle = [@"Quit " stringByAppendingString:appName];
    id quitMenuItem = [[[NSMenuItem alloc] initWithTitle:quitTitle
									       action:@selector(terminate:) 
									       keyEquivalent:@"q"] autorelease];
    [appMenu addItem:quitMenuItem];
    [appMenuItem setSubmenu:appMenu];

	CocoaDelegate *delegate = [[CocoaDelegate alloc] init];
	[[NSApplication sharedApplication] setDelegate:delegate];
	
	[pool drain];
	[NSApp run];
}

TUP0 startApplication_COCOA (CocoaEnv_CocoaDef env, CLOS clos, Int poly) {
    DISABLE(rts);
	if (!app) {
		app = cocoaApplication_COCOA(0);
		toRunWhenAppFinished = (AppCallback)clos;
    	addRootScanner(&appScanner);
    	rootsDirty = 1;
    	ENABLE(rts);
        runAsMainContinuation(createCocoaApplication);
	} else {
        ENABLE(rts);
    }
    return 0;
}

void _init_external_COCOA(void) {
    // Do nothing
}