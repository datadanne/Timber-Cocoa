#include "COCOA.extern.h"
#import <Cocoa/Cocoa.h>

extern ADDR copy(ADDR obj);

// these functions are used to convert from LIST to char*
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

struct Callback {
	WORD * GCINFO;
	TUP0 (*Code) (Callback, Time, Time);
};

struct AppCallback {
    POLY GCINFO;
    Msg (*Code) (AppCallback, App_COCOA, Time, Time);
    CocoaWindow_COCOA w1_8;
    Ref self_4;
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
App_COCOA app;

App_COCOA getApp(void) {
	return app;
}

void scanAppInit(void) {
    DISABLE(rts);
	if (app) {
		app = (App_COCOA)copy((ADDR)app);
	}

	if (toRunWhenAppFinished) {
		toRunWhenAppFinished = (AppCallback)copy((ADDR)toRunWhenAppFinished);
	}
	ENABLE(rts);
}

struct Scanner appScanner = {scanAppInit, NULL};

@interface CocoaDelegate : NSObject <NSApplicationDelegate>
-(void) applicationDidFinishLaunching:(NSNotification*)aNotification;
@end

@implementation CocoaDelegate
-(void) applicationDidFinishLaunching:(NSNotification*)aNotification {

    DISABLE(rts);
    if (toRunWhenAppFinished->Code == NULL) {
        printf("CRITICAL ERROR in applicationDidFinishLaunching: Nothing to run!\n");
    } else {
        ENABLE(rts);
	    toRunWhenAppFinished->Code(toRunWhenAppFinished, app, 0,0);
	    toRunWhenAppFinished = NULL;
        DISABLE(rts);
	}
    ENABLE(rts);
}
@end

void createCocoaApplication(void) {
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

TUP0 startApplication_COCOA (CocoaEnv_COCOA env, CLOS clos, Int poly) {
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

Bool compareKeys_COCOA(Bool targetValue, CocoaKey_COCOA aKey, CocoaKey_COCOA anotherKey) {
    return (targetValue == (((int)aKey == (int)anotherKey)));
}

Bool compareState_COCOA(Bool targetValue, ComponentState_COCOA aState, ComponentState_COCOA anotherState) {
    return (targetValue == (((int)aState == (int)anotherState)));
}

// --------- GC Handling ------------------------------------------------
WORD __internal__GC__CocoaID_COCOA[] = {WORDS(sizeof(struct internal_CocoaID_COCOA)), 0, 0};

CocoaID_COCOA mkCocoaID_COCOA(Int dummy) {
	internal_CocoaID_COCOA cocoaObject;
	NEW(internal_CocoaID_COCOA, cocoaObject, WORDS(sizeof(struct internal_CocoaID_COCOA)));
	cocoaObject->GCINFO = __internal__GC__CocoaID_COCOA;  
	cocoaObject->this 	= NULL;

	return (CocoaID_COCOA) cocoaObject;
}

void _init_external_COCOA(void) {
}