#ifndef CTDROPDOWN_EXTERN_H_
#define CTDROPDOWN_EXTERN_H_

#import <Cocoa/Cocoa.h>

#include "CocoaDef.h"
#include "rts.h"

#define DROPDOWN_HEIGHT 22

@interface DropDownClickHandler : NSObject {
    float x;
    float y;
    float width;
    float height;   
    
    float lastEventX;
    float lastEventY;
} 
- (void) setCoordsX: (float) xarg andY: (float) yarg;
- (void) setWidth: (float) w andHeight: (float) h;

@end   

Int  initDropDown_CTDropDown(World,Int);
TUP0 dropDownAddOption_CTDropDown(Int,LIST,Int);
TUP0 dropDownSetPosition_CTDropDown(Int,Position_CocoaDef,Int);
Size_CocoaDef dropDownSetSize_CTDropDown(Int,Size_CocoaDef,Int);
LIST dropDownGetSelectedOption_CTDropDown(Int,Int);

#endif
