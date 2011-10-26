#ifndef CTTEXTAREA_EXTERN_H_
#define CTTEXTAREA_EXTERN_H_

Int initTextArea_CTTextArea(TUP0);
TUP0 textAreaSetText_CTTextArea(Int, LIST);
TUP0 textAreaSetPosition_CTTextArea(Int, Position_CocoaDef);
TUP0 textAreaSetSize_CTTextArea(Int, Size_CocoaDef);
TUP0 textAreaSetHorizontalScroll_CTTextArea(Int, Bool);
TUP0 textAreaSetVerticalScroll_CTTextArea(Int, Bool);
TUP0 textAreaScrollTo_CTTextArea(Int, Float, Float);

#endif