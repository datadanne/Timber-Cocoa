#ifndef CTLABEL_H_
#define CTLABEL_H_
#include "Prelude.h"
#include "CTCommon.h"
 
struct Label_CTLabel;
typedef struct Label_CTLabel *Label_CTLabel;
 
struct Label_CTLabel {
    POLY GCINFO;
    Component_CTCommon l_Label_CTLabel_Component_CTCommon_CTLabel;
    HandlesMouseEvents_CTCommon l_Label_CTLabel_HandlesMouseEvents_CTCommon_CTLabel;
    Msg (*setText_CTLabel) (Label_CTLabel, LIST, Time, Time);
    LIST (*getText_CTLabel) (Label_CTLabel, Int);
    Msg (*setTextColor_CTLabel) (Label_CTLabel,
                                 Color_CTCommon,
                                 Time,
                                 Time);
    Color_CTCommon (*getTextColor_CTLabel) (Label_CTLabel, Int);
};
 
extern WORD __GC__Label_CTLabel[];
Component_CTCommon c_397_CTLabel (Label_CTLabel v_399);
HandlesMouseEvents_CTCommon c_400_CTLabel (Label_CTLabel v_402);
AbstractComponent_CTCommon c_404_CTLabel (Label_CTLabel a_403);
HandlesEvents_CTCommon c_406_CTLabel (Label_CTLabel a_405);
IsFocusable_CTCommon c_408_CTLabel (Label_CTLabel a_407);
HasSize_CTCommon c_410_CTLabel (Label_CTLabel a_409);
HasPosition_CTCommon c_412_CTLabel (Label_CTLabel a_411);
Label_CTLabel mkCocoaLabel_CTLabel (Int d_1901);
 
void _init_CTLabel ();
 
#include "CTLabel.extern.h"
#endif
