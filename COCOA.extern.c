#include "COCOA.extern.h"
#import "COCOA.extern.m"

int length (LIST list) {
    switch ((int)list) {
        case 0: return 0;
        default: return (1 + length(((CONS)list)->tl));
    }
}

char *listToChars(LIST str) {
	int len;
    char* buf; 
	int size = length(str);

    NEW(char*, buf, WORDS(sizeof(char) * size+1));   
    len = 0;
    while (str && len < size) {
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
	if (!app) {
		app = cocoaApplication_COCOA(0);
		toRunWhenAppFinished = (AppCallback)clos;

	    DISABLE(rts);
    	addRootScanner(&appScanner);
    	rootsDirty = 1;
    	ENABLE(rts);
    	
        runAsMainContinuation(createCocoaApplication);
	}
    return 0;
}

void _init_external_COCOA(void) {
}