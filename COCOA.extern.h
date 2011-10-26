#ifndef COCOA_EXTERN_H
#define COCOA_EXTERN_H

#include "rts.h"

#import <Cocoa/Cocoa.h>

#define DEBUGGING 0
#define DEBUG(...) if(DEBUGGING){printf("%s:%d ",__FILE__, __LINE__);printf(__VA_ARGS__);printf("\n");}

CocoaEnv_CocoaDef cocoa_COCOA(World, Int);
TUP0 startApplication_COCOA (CocoaEnv_CocoaDef, CLOS, Int);
Bool compareKeys_COCOA(CocoaKey_CocoaDef, CocoaKey_CocoaDef);
Bool compareState_COCOA(ComponentState_CocoaDef, ComponentState_CocoaDef);

App_CocoaDef getApp(void);

struct AppCallback;
typedef struct AppCallback * AppCallback;

int length (LIST list);
char *listToChars(LIST str);

#endif
