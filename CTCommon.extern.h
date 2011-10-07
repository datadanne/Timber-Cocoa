#ifndef _COCOA_CTCOMMON_TIMBER_
#define _COCOA_CTCOMMON_TIMBER_

#include "Cocoa.h"
#import <Cocoa/Cocoa.h>

#define COCOA_REF(id) (((internal_CocoaID_CTCommon) id)->this)
#define DEBUGGING 0
#define DEBUG(...) if(DEBUGGING){printf("%s:%d ",__FILE__, __LINE__);printf(__VA_ARGS__);printf("\n");}

struct Callback;
typedef struct Callback * Callback;

int length (LIST list);
char *listToChars(LIST str);


CocoaID_CTCommon mkCocoaID_CTCommon(Int dummy);

struct internal_CocoaID_CTCommon {
    POLY GCINFO;
    Int dummy_CTCommon;
	NSObject *this;
};

typedef struct internal_CocoaID_CTCommon *internal_CocoaID_CTCommon;     

#endif