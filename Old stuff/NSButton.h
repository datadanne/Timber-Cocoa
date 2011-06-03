#ifndef NSBUTTON_H_
#define NSBUTTON_H_
#include "Prelude.h"
#include "NSTest.h"
 
struct Button_NSButton;
typedef struct Button_NSButton *Button_NSButton;
 
struct Button_NSButton {
    POLY GCINFO;
    Component_NSTest l_Button_NSButton_Component_NSTest_NSButton;
    HandlesMouseEvents_NSTest l_Button_NSButton_HandlesMouseEvents_NSTest_NSButton;
    Msg (*setTitle_NSButton) (Button_NSButton, LIST, Time, Time);
    LIST (*getTitle_NSButton) (Button_NSButton, Int);
};
 
extern WORD __GC__Button_NSButton[];
Component_NSTest c_322_NSButton (Button_NSButton v_324);
HandlesMouseEvents_NSTest c_325_NSButton (Button_NSButton v_327);
HasSize_NSTest c_329_NSButton (Button_NSButton a_328);
HandlesEvents_NSTest c_331_NSButton (Button_NSButton a_330);
HasPosition_NSTest c_333_NSButton (Button_NSButton a_332);
Button_NSButton mkButton_NSButton (BITS32 a_1438,
                                   POLY env_8,
                                   Int d_1418);
 
void _init_NSButton ();
 
#include "NSButton.extern.h"
#endif
