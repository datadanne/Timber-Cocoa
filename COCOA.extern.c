#include "COCOA.extern.h"
#import <Cocoa/Cocoa.h>

/*
    Helper functions for converting LIST from char*
*/
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

struct AppCallback {
    POLY GCINFO;
    Msg (*Code) (AppCallback, App_CocoaDef, Time, Time);
};

// GCINFO = 0 makes it static (not GC'ed)
struct CocoaEnv_CocoaDef cenv_struct = { 0, &startApplication_COCOA }; 

CocoaEnv_CocoaDef cenv				 = &cenv_struct;                                                        

CocoaEnv_CocoaDef cocoa_COCOA(World w, Int dummy) {
    // Keep w but don't use it.
	return cenv;
}

/*
    Root scanner for GC
 */
App_CocoaDef app;
void scanAppInit(void);
struct Scanner appScanner = {scanAppInit, NULL};
static AppCallback toRunWhenAppFinished;
extern ADDR copy(ADDR obj);

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

@interface CocoaDelegate : NSObject <NSApplicationDelegate>
-(void) applicationDidFinishLaunching:(NSNotification*)aNotification;
@end

@implementation CocoaDelegate
-(void) applicationDidFinishLaunching:(NSNotification*)aNotification {

    DISABLE(rts);
    if (toRunWhenAppFinished->Code == NULL) {
        printf("COCOA.extern.c: CRITICAL ERROR in applicationDidFinishLaunching: nothing to run!\n");
    } else {
        ENABLE(rts);
	    toRunWhenAppFinished->Code(toRunWhenAppFinished, app, 0,0);
	    toRunWhenAppFinished = NULL;
        DISABLE(rts);
	}
    ENABLE(rts);
}
@end

void createCocoaApplication(Thread current_thread) {
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

    // Add Quit option to app menu
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

extern int rootsDirty;
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

Bool compareKeys_COCOA(CocoaKey_CocoaDef aKey, CocoaKey_CocoaDef anotherKey) {
    return ((int)aKey == (int)anotherKey);
}

Bool compareState_COCOA(ComponentState_CocoaDef aState, ComponentState_CocoaDef anotherState) {
    return ((int)aState == (int)anotherState));
}

void _init_external_COCOA(void) {
}