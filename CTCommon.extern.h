#ifndef _COCOA_CTCOMMON_TIMBER_
#define _COCOA_CTCOMMON_TIMBER_
#include "ctlib.h"

CocoaID_CTCommon mkCocoaID_CTCommon(Int dummy);

struct internal_CocoaID_CTCommon {
    POLY GCINFO;
    Int dummy_CTCommon;
	NSObject *this;
};

typedef struct internal_CocoaID_CTCommon *internal_CocoaID_CTCommon;     

#endif