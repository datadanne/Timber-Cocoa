#ifndef CTLIB_EXTERN_H
#define CTLIB_EXTERN_H

#include "Cocoa.h"
#import <Cocoa/Cocoa.h>
#include "CocoaHelpers.h"

#define COCOA_REF(id) (((internal_CocoaID_CTCommon) id)->this)
#define DEBUGGING 0
#define DEBUG(...) if(DEBUGGING){printf("%s:%d ",__FILE__, __LINE__);printf(__VA_ARGS__);printf("\n");}

struct Callback;
typedef struct Callback * Callback;

int length (LIST list);
char *listToChars(LIST str);

#endif
