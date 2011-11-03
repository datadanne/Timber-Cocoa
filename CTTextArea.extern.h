#ifndef CTTEXTAREA_EXTERN_H_
#define CTTEXTAREA_EXTERN_H_

#include "CocoaDef.h"

Int initTextArea_CTTextArea(World,Int);
TUP0 textAreaSetText_CTTextArea(Int,LIST,Int);
TUP0 textAreaSetPosition_CTTextArea(Int,Position_CocoaDef,Int);
TUP0 textAreaSetSize_CTTextArea(Int,Size_CocoaDef,Int);
TUP0 textAreaSetHorizontalScroll_CTTextArea(Int,Bool,Int);
TUP0 textAreaSetVerticalScroll_CTTextArea(Int,Bool,Int);
TUP0 textAreaScrollTo_CTTextArea(Int,Float,Float,Int);

#endif