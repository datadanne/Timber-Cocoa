#ifndef COCOA_EXTERN_H
#define COCOA_EXTERN_H
#include "rts.h"

#import <Cocoa/Cocoa.h>

#define COCOA_REF(id) (((internal_CocoaID_COCOA) id)->this)
#define DEBUGGING 0
#define DEBUG(...) if(DEBUGGING){printf("%s:%d ",__FILE__, __LINE__);printf(__VA_ARGS__);printf("\n");}

CocoaEnv_COCOA cocoa_COCOA(World w, Int dummy);
TUP0 startApplication_COCOA (CocoaEnv_COCOA env, CLOS clos, Int poly);
App_COCOA getApp(void);


struct internal_CocoaID_COCOA {
    POLY GCINFO;
    Int dummy_COCOA;
	NSObject *this;
};

typedef struct internal_CocoaID_COCOA *internal_CocoaID_COCOA;     

struct Callback;
typedef struct Callback * Callback;

struct AppCallback;
typedef struct AppCallback * AppCallback;

int length (LIST list);
char *listToChars(LIST str);


CocoaID_COCOA mkCocoaID_COCOA(Int dummy);

#endif
//#include "includes.h"
