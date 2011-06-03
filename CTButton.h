#ifndef CTBUTTON_H_
#define CTBUTTON_H_
#include "Prelude.h"
#include "CTCommon.h"
#include "POSIX.h"
 
struct Button_CTButton;
typedef struct Button_CTButton *Button_CTButton;
 
struct Button_CTButton {
    POLY GCINFO;
    Component_CTCommon l_Button_CTButton_Component_CTCommon_CTButton;
    HandlesMouseEvents_CTCommon l_Button_CTButton_HandlesMouseEvents_CTCommon_CTButton;
    HandlesKeyEvents_CTCommon l_Button_CTButton_HandlesKeyEvents_CTCommon_CTButton;
    Msg (*setTitle_CTButton) (Button_CTButton, LIST, Time, Time);
    LIST (*getTitle_CTButton) (Button_CTButton, Int);
};
 
extern WORD __GC__Button_CTButton[];
Component_CTCommon c_418_CTButton (Button_CTButton v_420);
HandlesMouseEvents_CTCommon c_421_CTButton (Button_CTButton v_423);
HandlesKeyEvents_CTCommon c_424_CTButton (Button_CTButton v_426);
IsFocusable_CTCommon c_428_CTButton (Button_CTButton a_427);
HasSize_CTCommon c_430_CTButton (Button_CTButton a_429);
HandlesEvents_CTCommon c_432_CTButton (Button_CTButton a_431);
HasPosition_CTCommon c_434_CTButton (Button_CTButton a_433);
Button_CTButton mkCocoaButton_CTButton (Env_POSIX env_8,
                                        Int d_2214);
 
void _init_CTButton ();
 
#include "CTButton.extern.h"
#endif
