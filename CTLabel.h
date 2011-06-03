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
Component_CTCommon c_391_CTLabel (Label_CTLabel v_393);
HandlesMouseEvents_CTCommon c_394_CTLabel (Label_CTLabel v_396);
IsFocusable_CTCommon c_398_CTLabel (Label_CTLabel a_397);
HasSize_CTCommon c_400_CTLabel (Label_CTLabel a_399);
HandlesEvents_CTCommon c_402_CTLabel (Label_CTLabel a_401);
HasPosition_CTCommon c_404_CTLabel (Label_CTLabel a_403);
Label_CTLabel mkCocoaLabel_CTLabel (Int d_1831);
 
void _init_CTLabel ();
 
#include "CTLabel.extern.h"
#endif
