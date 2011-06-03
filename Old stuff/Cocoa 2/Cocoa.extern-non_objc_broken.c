#include <stdio.h>

#include <objc/objc.h>
#include <objc/runtime.h>
#include <objc/message.h>
#import <Cocoa/Cocoa.h>

Msg showWindow (Env_Cocoa env, Time base, Time deadline) {
	
	NSRect windowRect = NSMakeRect(300,300,300,500);

	// Prevent memory leaking
	id NSAutoreleasePool = objc_getClass("NSAutoreleasePool");
	id pool = objc_msgSend((id)NSAutoreleasePool, sel_registerName("alloc"));
	pool = objc_msgSend(pool, sel_registerName("init"));	
	
	id NSSpeechSynthesizer = objc_getClass("NSSpeechSynthesizer");
	id availableVoices = objc_msgSend((id)NSSpeechSynthesizer, sel_registerName("availableVoices"));
	
	int countVoices = (int) objc_msgSend(availableVoices, sel_registerName("count"));
	printf("Found %d names:\n", countVoices);
	
	char* names;
	int i;
	for(i = 0; i < countVoices; i++) {
		names = (char*)objc_msgSend(objc_msgSend((id)availableVoices, sel_registerName("objectAtIndex:"), i), sel_registerName("UTF8String"));
		printf("%s\n", names);
	}
	
/*	int *cocoa_library = dlopen("/Library/Frameworks/Cocoa.framework/Cocoa", RTLD_LAZY);
	if (cocoa_library == NULL) {
		printf("ERROR\n");
		return 0;
	}*/
	
//	id frame = objc_msgSend(NULL, sel_registerName("NSRect"),10,20,30,40);
	id NSWindow = objc_getClass("NSWindow");
	id NSApp = objc_getClass("NSApp");
	id window = (objc_msgSend(NSWindow, sel_registerName("alloc")), 
				 sel_registerName("initWithContentRect:styleMask:backing:defer"), windowRect, 0xF, 0, NO);
	window = objc_msgSend(window, sel_registerName("display"));
	window = objc_msgSend(window, sel_registerName("makeKeyAndOrderFront:"), NSApp);
	
	id NSApplication = objc_getClass("NSApplication");
	
	objc_msgSend(NSApplication, sel_registerName("sharedApplication"));
	
	//id NSApp = objc_getClass("NSApp");
	//result = objc_msgSend(result, sel_registerName("run"));
	
	id NSRunLoop = objc_getClass("NSRunLoop");
	objc_msgSend(objc_msgSend(NSRunLoop, sel_registerName("currentRunLoop")), sel_registerName("run"));
	
	printf("message\n");
	
}

struct Env_Cocoa env_cocoa = {0, &showWindow};


Env_Cocoa cocoa_Cocoa(World w, Int dummy) {

	/* Init Objc runtime? Threads etc.
	*/

	

	return &env_cocoa;
}
