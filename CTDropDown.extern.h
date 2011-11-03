#ifndef CTDROPDOWN_EXTERN_H_
#define CTDROPDOWN_EXTERN_H_

#include "CocoaDef.h"

#define DROPDOWN_HEIGHT 22

Int  initDropDown_CTDropDown(World,Int);
TUP0 dropDownAddOption_CTDropDown(Int,LIST,Int);
TUP0 dropDownSetPosition_CTDropDown(Int,Position_CocoaDef,Int);
Size_CocoaDef dropDownSetSize_CTDropDown(Int,Size_CocoaDef,Int);
LIST dropDownGetSelectedOption_CTDropDown(Int,Int);

#endif
