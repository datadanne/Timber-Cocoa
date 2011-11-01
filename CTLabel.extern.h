#ifndef CTLABEL_EXTERN_H_
#define CTLABEL_EXTERN_H_

#import <Cocoa/Cocoa.h>

#include "CocoaDef.h"

Int initLabel_CTLabel(World,Int);
TUP0 labelSetText_CTLabel(Int,LIST,Int);
TUP0 labelSetPosition_CTLabel(Int,Position_CocoaDef,Int);
TUP0 labelSetSize_CTLabel(Int,Size_CocoaDef,Int);
TUP0 labelSetTextColor_CTLabel(Int,Color_CocoaDef,Int);

#endif