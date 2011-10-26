#ifndef COCOA_EXTERN_H
#define COCOA_EXTERN_H

#import <Cocoa/Cocoa.h>

#include "CocoaDef.h"

extern pthread_mutex_t rts;
extern int rootsDirty;
extern ADDR copy(ADDR obj);

#define DEBUGGING 0
#define DEBUG(...) if(DEBUGGING){printf("%s:%d ",__FILE__, __LINE__);printf(__VA_ARGS__);printf("\n");}

CocoaEnv_CocoaDef cocoa_COCOA(World, Int);
TUP0 startApplication_COCOA (CocoaEnv_CocoaDef, CLOS, Int);

App_CocoaDef getApp(void);

struct AppCallback;
typedef struct AppCallback * AppCallback;

struct AppCallback {
    POLY GCINFO;
    Msg (*Code) (AppCallback, App_CocoaDef, Time, Time);
};

AppCallback toRunWhenAppFinished;

int length (LIST list);
char *listToChars(LIST str);

#endif
