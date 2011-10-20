#ifndef COCOA_EXTERN_H
#define COCOA_EXTERN_H
#include "rts.h"

CocoaEnv_COCOA cocoa_COCOA(World w, Int dummy);
TUP0 startApplication_COCOA (CocoaEnv_COCOA env, CLOS clos, Int poly);
App_CTCommon getApp(void);
#endif
//#include "includes.h"
