#ifndef CTCOMMON_H_
#define CTCOMMON_H_
#include "Prelude.h"
#include "POSIX.h"
 
struct ApplicationState_CTCommon;
typedef struct ApplicationState_CTCommon *ApplicationState_CTCommon;
struct _Stopped_CTCommon;
typedef struct _Stopped_CTCommon *_Stopped_CTCommon;
struct _Running_CTCommon;
typedef struct _Running_CTCommon *_Running_CTCommon;
struct CocoaState_CTCommon;
typedef struct CocoaState_CTCommon *CocoaState_CTCommon;
struct _Destroyed_CTCommon;
typedef struct _Destroyed_CTCommon *_Destroyed_CTCommon;
struct _Inactive_CTCommon;
typedef struct _Inactive_CTCommon *_Inactive_CTCommon;
struct _Active_CTCommon;
typedef struct _Active_CTCommon *_Active_CTCommon;
struct WindowEventType_CTCommon;
typedef struct WindowEventType_CTCommon *WindowEventType_CTCommon;
struct _WindowNotClosed_CTCommon;
typedef struct _WindowNotClosed_CTCommon *_WindowNotClosed_CTCommon;
struct _WindowClosed_CTCommon;
typedef struct _WindowClosed_CTCommon *_WindowClosed_CTCommon;
struct Position_CTCommon;
typedef struct Position_CTCommon *Position_CTCommon;
struct MouseEventType_CTCommon;
typedef struct MouseEventType_CTCommon *MouseEventType_CTCommon;
struct _MouseMoved_CTCommon;
typedef struct _MouseMoved_CTCommon *_MouseMoved_CTCommon;
struct _MouseReleased_CTCommon;
typedef struct _MouseReleased_CTCommon *_MouseReleased_CTCommon;
struct _MousePressed_CTCommon;
typedef struct _MousePressed_CTCommon *_MousePressed_CTCommon;
struct _MouseClicked_CTCommon;
typedef struct _MouseClicked_CTCommon *_MouseClicked_CTCommon;
struct CocoaKey_CTCommon;
typedef struct CocoaKey_CTCommon *CocoaKey_CTCommon;
struct _UpArrow_CTCommon;
typedef struct _UpArrow_CTCommon *_UpArrow_CTCommon;
struct _DownArrow_CTCommon;
typedef struct _DownArrow_CTCommon *_DownArrow_CTCommon;
struct _RightArrow_CTCommon;
typedef struct _RightArrow_CTCommon *_RightArrow_CTCommon;
struct _LeftArrow_CTCommon;
typedef struct _LeftArrow_CTCommon *_LeftArrow_CTCommon;
struct _F1_CTCommon;
typedef struct _F1_CTCommon *_F1_CTCommon;
struct _PageDown_CTCommon;
typedef struct _PageDown_CTCommon *_PageDown_CTCommon;
struct _F2_CTCommon;
typedef struct _F2_CTCommon *_F2_CTCommon;
struct _End_CTCommon;
typedef struct _End_CTCommon *_End_CTCommon;
struct _F4_CTCommon;
typedef struct _F4_CTCommon *_F4_CTCommon;
struct _ForwardDelete_CTCommon;
typedef struct _ForwardDelete_CTCommon *_ForwardDelete_CTCommon;
struct _PageUp_CTCommon;
typedef struct _PageUp_CTCommon *_PageUp_CTCommon;
struct _Home_CTCommon;
typedef struct _Home_CTCommon *_Home_CTCommon;
struct _Help_CTCommon;
typedef struct _Help_CTCommon *_Help_CTCommon;
struct _F15_CTCommon;
typedef struct _F15_CTCommon *_F15_CTCommon;
struct _Dummy15_CTCommon;
typedef struct _Dummy15_CTCommon *_Dummy15_CTCommon;
struct _F12_CTCommon;
typedef struct _F12_CTCommon *_F12_CTCommon;
struct _Dummy14_CTCommon;
typedef struct _Dummy14_CTCommon *_Dummy14_CTCommon;
struct _F10_CTCommon;
typedef struct _F10_CTCommon *_F10_CTCommon;
struct _Dummy13_CTCommon;
typedef struct _Dummy13_CTCommon *_Dummy13_CTCommon;
struct _F14_CTCommon;
typedef struct _F14_CTCommon *_F14_CTCommon;
struct _F16_CTCommon;
typedef struct _F16_CTCommon *_F16_CTCommon;
struct _F13_CTCommon;
typedef struct _F13_CTCommon *_F13_CTCommon;
struct _Dummy12_CTCommon;
typedef struct _Dummy12_CTCommon *_Dummy12_CTCommon;
struct _F11_CTCommon;
typedef struct _F11_CTCommon *_F11_CTCommon;
struct _Dummy11_CTCommon;
typedef struct _Dummy11_CTCommon *_Dummy11_CTCommon;
struct _F9_CTCommon;
typedef struct _F9_CTCommon *_F9_CTCommon;
struct _F8_CTCommon;
typedef struct _F8_CTCommon *_F8_CTCommon;
struct _F3_CTCommon;
typedef struct _F3_CTCommon *_F3_CTCommon;
struct _F7_CTCommon;
typedef struct _F7_CTCommon *_F7_CTCommon;
struct _F6_CTCommon;
typedef struct _F6_CTCommon *_F6_CTCommon;
struct _F5_CTCommon;
typedef struct _F5_CTCommon *_F5_CTCommon;
struct _Dummy10_CTCommon;
typedef struct _Dummy10_CTCommon *_Dummy10_CTCommon;
struct _Dummy9_CTCommon;
typedef struct _Dummy9_CTCommon *_Dummy9_CTCommon;
struct _Dummy8_CTCommon;
typedef struct _Dummy8_CTCommon *_Dummy8_CTCommon;
struct _Keypad9_CTCommon;
typedef struct _Keypad9_CTCommon *_Keypad9_CTCommon;
struct _Keypad8_CTCommon;
typedef struct _Keypad8_CTCommon *_Keypad8_CTCommon;
struct _F20_CTCommon;
typedef struct _F20_CTCommon *_F20_CTCommon;
struct _Keypad7_CTCommon;
typedef struct _Keypad7_CTCommon *_Keypad7_CTCommon;
struct _Keypad6_CTCommon;
typedef struct _Keypad6_CTCommon *_Keypad6_CTCommon;
struct _Keypad5_CTCommon;
typedef struct _Keypad5_CTCommon *_Keypad5_CTCommon;
struct _Keypad4_CTCommon;
typedef struct _Keypad4_CTCommon *_Keypad4_CTCommon;
struct _Keypad3_CTCommon;
typedef struct _Keypad3_CTCommon *_Keypad3_CTCommon;
struct _Keypad2_CTCommon;
typedef struct _Keypad2_CTCommon *_Keypad2_CTCommon;
struct _Keypad1_CTCommon;
typedef struct _Keypad1_CTCommon *_Keypad1_CTCommon;
struct _Keypad0_CTCommon;
typedef struct _Keypad0_CTCommon *_Keypad0_CTCommon;
struct _KeypadEquals_CTCommon;
typedef struct _KeypadEquals_CTCommon *_KeypadEquals_CTCommon;
struct _F19_CTCommon;
typedef struct _F19_CTCommon *_F19_CTCommon;
struct _F18_CTCommon;
typedef struct _F18_CTCommon *_F18_CTCommon;
struct _KeypadMinus_CTCommon;
typedef struct _KeypadMinus_CTCommon *_KeypadMinus_CTCommon;
struct _Dummy7_CTCommon;
typedef struct _Dummy7_CTCommon *_Dummy7_CTCommon;
struct _KeypadEnter_CTCommon;
typedef struct _KeypadEnter_CTCommon *_KeypadEnter_CTCommon;
struct _KeypadDivide_CTCommon;
typedef struct _KeypadDivide_CTCommon *_KeypadDivide_CTCommon;
struct _Mute_CTCommon;
typedef struct _Mute_CTCommon *_Mute_CTCommon;
struct _VolumeDown_CTCommon;
typedef struct _VolumeDown_CTCommon *_VolumeDown_CTCommon;
struct _VolumeUp_CTCommon;
typedef struct _VolumeUp_CTCommon *_VolumeUp_CTCommon;
struct _KeypadClear_CTCommon;
typedef struct _KeypadClear_CTCommon *_KeypadClear_CTCommon;
struct _Dummy6_CTCommon;
typedef struct _Dummy6_CTCommon *_Dummy6_CTCommon;
struct _KeypadPlus_CTCommon;
typedef struct _KeypadPlus_CTCommon *_KeypadPlus_CTCommon;
struct _Dummy5_CTCommon;
typedef struct _Dummy5_CTCommon *_Dummy5_CTCommon;
struct _KeypadMultiply_CTCommon;
typedef struct _KeypadMultiply_CTCommon *_KeypadMultiply_CTCommon;
struct _Dummy4_CTCommon;
typedef struct _Dummy4_CTCommon *_Dummy4_CTCommon;
struct _KeypadDecimal_CTCommon;
typedef struct _KeypadDecimal_CTCommon *_KeypadDecimal_CTCommon;
struct _F17_CTCommon;
typedef struct _F17_CTCommon *_F17_CTCommon;
struct _Function_CTCommon;
typedef struct _Function_CTCommon *_Function_CTCommon;
struct _RightControl_CTCommon;
typedef struct _RightControl_CTCommon *_RightControl_CTCommon;
struct _RightOption_CTCommon;
typedef struct _RightOption_CTCommon *_RightOption_CTCommon;
struct _RightShift_CTCommon;
typedef struct _RightShift_CTCommon *_RightShift_CTCommon;
struct _Control_CTCommon;
typedef struct _Control_CTCommon *_Control_CTCommon;
struct _Option_CTCommon;
typedef struct _Option_CTCommon *_Option_CTCommon;
struct _CapsLock_CTCommon;
typedef struct _CapsLock_CTCommon *_CapsLock_CTCommon;
struct _Shift_CTCommon;
typedef struct _Shift_CTCommon *_Shift_CTCommon;
struct _Command_CTCommon;
typedef struct _Command_CTCommon *_Command_CTCommon;
struct _Dummy3_CTCommon;
typedef struct _Dummy3_CTCommon *_Dummy3_CTCommon;
struct _Escape_CTCommon;
typedef struct _Escape_CTCommon *_Escape_CTCommon;
struct _Dummy2_CTCommon;
typedef struct _Dummy2_CTCommon *_Dummy2_CTCommon;
struct _Delete_CTCommon;
typedef struct _Delete_CTCommon *_Delete_CTCommon;
struct _Grave_CTCommon;
typedef struct _Grave_CTCommon *_Grave_CTCommon;
struct _Space_CTCommon;
typedef struct _Space_CTCommon *_Space_CTCommon;
struct _Tab_CTCommon;
typedef struct _Tab_CTCommon *_Tab_CTCommon;
struct _Period_CTCommon;
typedef struct _Period_CTCommon *_Period_CTCommon;
struct _M_CTCommon;
typedef struct _M_CTCommon *_M_CTCommon;
struct _N_CTCommon;
typedef struct _N_CTCommon *_N_CTCommon;
struct _Slash_CTCommon;
typedef struct _Slash_CTCommon *_Slash_CTCommon;
struct _Comma_CTCommon;
typedef struct _Comma_CTCommon *_Comma_CTCommon;
struct _Backslash_CTCommon;
typedef struct _Backslash_CTCommon *_Backslash_CTCommon;
struct _Semicolon_CTCommon;
typedef struct _Semicolon_CTCommon *_Semicolon_CTCommon;
struct _K_CTCommon;
typedef struct _K_CTCommon *_K_CTCommon;
struct _Quote_CTCommon;
typedef struct _Quote_CTCommon *_Quote_CTCommon;
struct _J_CTCommon;
typedef struct _J_CTCommon *_J_CTCommon;
struct _L_CTCommon;
typedef struct _L_CTCommon *_L_CTCommon;
struct _Return_CTCommon;
typedef struct _Return_CTCommon *_Return_CTCommon;
struct _P_CTCommon;
typedef struct _P_CTCommon *_P_CTCommon;
struct _I_CTCommon;
typedef struct _I_CTCommon *_I_CTCommon;
struct _LeftBracket_CTCommon;
typedef struct _LeftBracket_CTCommon *_LeftBracket_CTCommon;
struct _U_CTCommon;
typedef struct _U_CTCommon *_U_CTCommon;
struct _O_CTCommon;
typedef struct _O_CTCommon *_O_CTCommon;
struct _RightBracket_CTCommon;
typedef struct _RightBracket_CTCommon *_RightBracket_CTCommon;
struct _Num0_CTCommon;
typedef struct _Num0_CTCommon *_Num0_CTCommon;
struct _Num8_CTCommon;
typedef struct _Num8_CTCommon *_Num8_CTCommon;
struct _Minus_CTCommon;
typedef struct _Minus_CTCommon *_Minus_CTCommon;
struct _Num7_CTCommon;
typedef struct _Num7_CTCommon *_Num7_CTCommon;
struct _Num9_CTCommon;
typedef struct _Num9_CTCommon *_Num9_CTCommon;
struct _Equal_CTCommon;
typedef struct _Equal_CTCommon *_Equal_CTCommon;
struct _Num5_CTCommon;
typedef struct _Num5_CTCommon *_Num5_CTCommon;
struct _Num6_CTCommon;
typedef struct _Num6_CTCommon *_Num6_CTCommon;
struct _Num4_CTCommon;
typedef struct _Num4_CTCommon *_Num4_CTCommon;
struct _Num3_CTCommon;
typedef struct _Num3_CTCommon *_Num3_CTCommon;
struct _Num2_CTCommon;
typedef struct _Num2_CTCommon *_Num2_CTCommon;
struct _Num1_CTCommon;
typedef struct _Num1_CTCommon *_Num1_CTCommon;
struct _T_CTCommon;
typedef struct _T_CTCommon *_T_CTCommon;
struct _Y_CTCommon;
typedef struct _Y_CTCommon *_Y_CTCommon;
struct _R_CTCommon;
typedef struct _R_CTCommon *_R_CTCommon;
struct _E_CTCommon;
typedef struct _E_CTCommon *_E_CTCommon;
struct _W_CTCommon;
typedef struct _W_CTCommon *_W_CTCommon;
struct _Q_CTCommon;
typedef struct _Q_CTCommon *_Q_CTCommon;
struct _B_CTCommon;
typedef struct _B_CTCommon *_B_CTCommon;
struct _Dummy1_CTCommon;
typedef struct _Dummy1_CTCommon *_Dummy1_CTCommon;
struct _V_CTCommon;
typedef struct _V_CTCommon *_V_CTCommon;
struct _C_CTCommon;
typedef struct _C_CTCommon *_C_CTCommon;
struct _X_CTCommon;
typedef struct _X_CTCommon *_X_CTCommon;
struct _Z_CTCommon;
typedef struct _Z_CTCommon *_Z_CTCommon;
struct _G_CTCommon;
typedef struct _G_CTCommon *_G_CTCommon;
struct _H_CTCommon;
typedef struct _H_CTCommon *_H_CTCommon;
struct _F_CTCommon;
typedef struct _F_CTCommon *_F_CTCommon;
struct _D_CTCommon;
typedef struct _D_CTCommon *_D_CTCommon;
struct _S_CTCommon;
typedef struct _S_CTCommon *_S_CTCommon;
struct _A_CTCommon;
typedef struct _A_CTCommon *_A_CTCommon;
struct KeyEventType_CTCommon;
typedef struct KeyEventType_CTCommon *KeyEventType_CTCommon;
struct _KeyReleased_CTCommon;
typedef struct _KeyReleased_CTCommon *_KeyReleased_CTCommon;
struct _KeyPressed_CTCommon;
typedef struct _KeyPressed_CTCommon *_KeyPressed_CTCommon;
struct CocoaEvent_CTCommon;
typedef struct CocoaEvent_CTCommon *CocoaEvent_CTCommon;
struct _KeyEvent_CTCommon;
typedef struct _KeyEvent_CTCommon *_KeyEvent_CTCommon;
struct _MouseEvent_CTCommon;
typedef struct _MouseEvent_CTCommon *_MouseEvent_CTCommon;
struct _WindowEvent_CTCommon;
typedef struct _WindowEvent_CTCommon *_WindowEvent_CTCommon;
struct Size_CTCommon;
typedef struct Size_CTCommon *Size_CTCommon;
struct Color_CTCommon;
typedef struct Color_CTCommon *Color_CTCommon;
struct HasPosition_CTCommon;
typedef struct HasPosition_CTCommon *HasPosition_CTCommon;
struct HasSize_CTCommon;
typedef struct HasSize_CTCommon *HasSize_CTCommon;
struct HasBackgroundColor_CTCommon;
typedef struct HasBackgroundColor_CTCommon *HasBackgroundColor_CTCommon;
struct CocoaID_CTCommon;
typedef struct CocoaID_CTCommon *CocoaID_CTCommon;
struct HandlesKeyEvents_CTCommon;
typedef struct HandlesKeyEvents_CTCommon *HandlesKeyEvents_CTCommon;
struct HandlesMouseEvents_CTCommon;
typedef struct HandlesMouseEvents_CTCommon *HandlesMouseEvents_CTCommon;
struct HandlesEvents_CTCommon;
typedef struct HandlesEvents_CTCommon *HandlesEvents_CTCommon;
struct HandlesWindowEvents_CTCommon;
typedef struct HandlesWindowEvents_CTCommon *HandlesWindowEvents_CTCommon;
struct IsFocusable_CTCommon;
typedef struct IsFocusable_CTCommon *IsFocusable_CTCommon;
struct Component_CTCommon;
typedef struct Component_CTCommon *Component_CTCommon;
struct ContainsComponents_CTCommon;
typedef struct ContainsComponents_CTCommon *ContainsComponents_CTCommon;
struct CocoaWindow_CTCommon;
typedef struct CocoaWindow_CTCommon *CocoaWindow_CTCommon;
struct App_CTCommon;
typedef struct App_CTCommon *App_CTCommon;
 
struct ApplicationState_CTCommon {
    POLY GCINFO;
};
struct _Stopped_CTCommon {
    POLY GCINFO;
};
struct _Running_CTCommon {
    POLY GCINFO;
};
struct CocoaState_CTCommon {
    POLY GCINFO;
};
struct _Destroyed_CTCommon {
    POLY GCINFO;
};
struct _Inactive_CTCommon {
    POLY GCINFO;
};
struct _Active_CTCommon {
    POLY GCINFO;
};
struct WindowEventType_CTCommon {
    POLY GCINFO;
};
struct _WindowNotClosed_CTCommon {
    POLY GCINFO;
};
struct _WindowClosed_CTCommon {
    POLY GCINFO;
};
struct Position_CTCommon {
    POLY GCINFO;
    Int x_CTCommon;
    Int y_CTCommon;
};
struct MouseEventType_CTCommon {
    POLY GCINFO;
    Int Tag;
};
struct _MouseMoved_CTCommon {
    POLY GCINFO;
    Int Tag;
    Position_CTCommon a;
};
struct _MouseReleased_CTCommon {
    POLY GCINFO;
    Int Tag;
    Position_CTCommon a;
};
struct _MousePressed_CTCommon {
    POLY GCINFO;
    Int Tag;
    Position_CTCommon a;
};
struct _MouseClicked_CTCommon {
    POLY GCINFO;
    Int Tag;
    Position_CTCommon a;
};
struct CocoaKey_CTCommon {
    POLY GCINFO;
};
struct _UpArrow_CTCommon {
    POLY GCINFO;
};
struct _DownArrow_CTCommon {
    POLY GCINFO;
};
struct _RightArrow_CTCommon {
    POLY GCINFO;
};
struct _LeftArrow_CTCommon {
    POLY GCINFO;
};
struct _F1_CTCommon {
    POLY GCINFO;
};
struct _PageDown_CTCommon {
    POLY GCINFO;
};
struct _F2_CTCommon {
    POLY GCINFO;
};
struct _End_CTCommon {
    POLY GCINFO;
};
struct _F4_CTCommon {
    POLY GCINFO;
};
struct _ForwardDelete_CTCommon {
    POLY GCINFO;
};
struct _PageUp_CTCommon {
    POLY GCINFO;
};
struct _Home_CTCommon {
    POLY GCINFO;
};
struct _Help_CTCommon {
    POLY GCINFO;
};
struct _F15_CTCommon {
    POLY GCINFO;
};
struct _Dummy15_CTCommon {
    POLY GCINFO;
};
struct _F12_CTCommon {
    POLY GCINFO;
};
struct _Dummy14_CTCommon {
    POLY GCINFO;
};
struct _F10_CTCommon {
    POLY GCINFO;
};
struct _Dummy13_CTCommon {
    POLY GCINFO;
};
struct _F14_CTCommon {
    POLY GCINFO;
};
struct _F16_CTCommon {
    POLY GCINFO;
};
struct _F13_CTCommon {
    POLY GCINFO;
};
struct _Dummy12_CTCommon {
    POLY GCINFO;
};
struct _F11_CTCommon {
    POLY GCINFO;
};
struct _Dummy11_CTCommon {
    POLY GCINFO;
};
struct _F9_CTCommon {
    POLY GCINFO;
};
struct _F8_CTCommon {
    POLY GCINFO;
};
struct _F3_CTCommon {
    POLY GCINFO;
};
struct _F7_CTCommon {
    POLY GCINFO;
};
struct _F6_CTCommon {
    POLY GCINFO;
};
struct _F5_CTCommon {
    POLY GCINFO;
};
struct _Dummy10_CTCommon {
    POLY GCINFO;
};
struct _Dummy9_CTCommon {
    POLY GCINFO;
};
struct _Dummy8_CTCommon {
    POLY GCINFO;
};
struct _Keypad9_CTCommon {
    POLY GCINFO;
};
struct _Keypad8_CTCommon {
    POLY GCINFO;
};
struct _F20_CTCommon {
    POLY GCINFO;
};
struct _Keypad7_CTCommon {
    POLY GCINFO;
};
struct _Keypad6_CTCommon {
    POLY GCINFO;
};
struct _Keypad5_CTCommon {
    POLY GCINFO;
};
struct _Keypad4_CTCommon {
    POLY GCINFO;
};
struct _Keypad3_CTCommon {
    POLY GCINFO;
};
struct _Keypad2_CTCommon {
    POLY GCINFO;
};
struct _Keypad1_CTCommon {
    POLY GCINFO;
};
struct _Keypad0_CTCommon {
    POLY GCINFO;
};
struct _KeypadEquals_CTCommon {
    POLY GCINFO;
};
struct _F19_CTCommon {
    POLY GCINFO;
};
struct _F18_CTCommon {
    POLY GCINFO;
};
struct _KeypadMinus_CTCommon {
    POLY GCINFO;
};
struct _Dummy7_CTCommon {
    POLY GCINFO;
};
struct _KeypadEnter_CTCommon {
    POLY GCINFO;
};
struct _KeypadDivide_CTCommon {
    POLY GCINFO;
};
struct _Mute_CTCommon {
    POLY GCINFO;
};
struct _VolumeDown_CTCommon {
    POLY GCINFO;
};
struct _VolumeUp_CTCommon {
    POLY GCINFO;
};
struct _KeypadClear_CTCommon {
    POLY GCINFO;
};
struct _Dummy6_CTCommon {
    POLY GCINFO;
};
struct _KeypadPlus_CTCommon {
    POLY GCINFO;
};
struct _Dummy5_CTCommon {
    POLY GCINFO;
};
struct _KeypadMultiply_CTCommon {
    POLY GCINFO;
};
struct _Dummy4_CTCommon {
    POLY GCINFO;
};
struct _KeypadDecimal_CTCommon {
    POLY GCINFO;
};
struct _F17_CTCommon {
    POLY GCINFO;
};
struct _Function_CTCommon {
    POLY GCINFO;
};
struct _RightControl_CTCommon {
    POLY GCINFO;
};
struct _RightOption_CTCommon {
    POLY GCINFO;
};
struct _RightShift_CTCommon {
    POLY GCINFO;
};
struct _Control_CTCommon {
    POLY GCINFO;
};
struct _Option_CTCommon {
    POLY GCINFO;
};
struct _CapsLock_CTCommon {
    POLY GCINFO;
};
struct _Shift_CTCommon {
    POLY GCINFO;
};
struct _Command_CTCommon {
    POLY GCINFO;
};
struct _Dummy3_CTCommon {
    POLY GCINFO;
};
struct _Escape_CTCommon {
    POLY GCINFO;
};
struct _Dummy2_CTCommon {
    POLY GCINFO;
};
struct _Delete_CTCommon {
    POLY GCINFO;
};
struct _Grave_CTCommon {
    POLY GCINFO;
};
struct _Space_CTCommon {
    POLY GCINFO;
};
struct _Tab_CTCommon {
    POLY GCINFO;
};
struct _Period_CTCommon {
    POLY GCINFO;
};
struct _M_CTCommon {
    POLY GCINFO;
};
struct _N_CTCommon {
    POLY GCINFO;
};
struct _Slash_CTCommon {
    POLY GCINFO;
};
struct _Comma_CTCommon {
    POLY GCINFO;
};
struct _Backslash_CTCommon {
    POLY GCINFO;
};
struct _Semicolon_CTCommon {
    POLY GCINFO;
};
struct _K_CTCommon {
    POLY GCINFO;
};
struct _Quote_CTCommon {
    POLY GCINFO;
};
struct _J_CTCommon {
    POLY GCINFO;
};
struct _L_CTCommon {
    POLY GCINFO;
};
struct _Return_CTCommon {
    POLY GCINFO;
};
struct _P_CTCommon {
    POLY GCINFO;
};
struct _I_CTCommon {
    POLY GCINFO;
};
struct _LeftBracket_CTCommon {
    POLY GCINFO;
};
struct _U_CTCommon {
    POLY GCINFO;
};
struct _O_CTCommon {
    POLY GCINFO;
};
struct _RightBracket_CTCommon {
    POLY GCINFO;
};
struct _Num0_CTCommon {
    POLY GCINFO;
};
struct _Num8_CTCommon {
    POLY GCINFO;
};
struct _Minus_CTCommon {
    POLY GCINFO;
};
struct _Num7_CTCommon {
    POLY GCINFO;
};
struct _Num9_CTCommon {
    POLY GCINFO;
};
struct _Equal_CTCommon {
    POLY GCINFO;
};
struct _Num5_CTCommon {
    POLY GCINFO;
};
struct _Num6_CTCommon {
    POLY GCINFO;
};
struct _Num4_CTCommon {
    POLY GCINFO;
};
struct _Num3_CTCommon {
    POLY GCINFO;
};
struct _Num2_CTCommon {
    POLY GCINFO;
};
struct _Num1_CTCommon {
    POLY GCINFO;
};
struct _T_CTCommon {
    POLY GCINFO;
};
struct _Y_CTCommon {
    POLY GCINFO;
};
struct _R_CTCommon {
    POLY GCINFO;
};
struct _E_CTCommon {
    POLY GCINFO;
};
struct _W_CTCommon {
    POLY GCINFO;
};
struct _Q_CTCommon {
    POLY GCINFO;
};
struct _B_CTCommon {
    POLY GCINFO;
};
struct _Dummy1_CTCommon {
    POLY GCINFO;
};
struct _V_CTCommon {
    POLY GCINFO;
};
struct _C_CTCommon {
    POLY GCINFO;
};
struct _X_CTCommon {
    POLY GCINFO;
};
struct _Z_CTCommon {
    POLY GCINFO;
};
struct _G_CTCommon {
    POLY GCINFO;
};
struct _H_CTCommon {
    POLY GCINFO;
};
struct _F_CTCommon {
    POLY GCINFO;
};
struct _D_CTCommon {
    POLY GCINFO;
};
struct _S_CTCommon {
    POLY GCINFO;
};
struct _A_CTCommon {
    POLY GCINFO;
};
struct KeyEventType_CTCommon {
    POLY GCINFO;
    Int Tag;
};
struct _KeyReleased_CTCommon {
    POLY GCINFO;
    Int Tag;
    CocoaKey_CTCommon a;
};
struct _KeyPressed_CTCommon {
    POLY GCINFO;
    Int Tag;
    CocoaKey_CTCommon a;
};
struct CocoaEvent_CTCommon {
    POLY GCINFO;
    Int Tag;
};
struct _KeyEvent_CTCommon {
    POLY GCINFO;
    Int Tag;
    KeyEventType_CTCommon a;
};
struct _MouseEvent_CTCommon {
    POLY GCINFO;
    Int Tag;
    MouseEventType_CTCommon a;
};
struct _WindowEvent_CTCommon {
    POLY GCINFO;
    Int Tag;
    WindowEventType_CTCommon a;
};
struct Size_CTCommon {
    POLY GCINFO;
    Int width_CTCommon;
    Int height_CTCommon;
};
struct Color_CTCommon {
    POLY GCINFO;
    Int r_CTCommon;
    Int g_CTCommon;
    Int b_CTCommon;
};
struct HasPosition_CTCommon {
    POLY GCINFO;
    Msg (*setPosition_CTCommon) (HasPosition_CTCommon,
                                 Position_CTCommon,
                                 Time,
                                 Time);
    Position_CTCommon (*getPosition_CTCommon) (HasPosition_CTCommon,
                                               Int);
};
struct HasSize_CTCommon {
    POLY GCINFO;
    HasPosition_CTCommon l_HasSize_CTCommon_HasPosition_CTCommon_CTCommon;
    Msg (*setSize_CTCommon) (HasSize_CTCommon,
                             Size_CTCommon,
                             Time,
                             Time);
    Size_CTCommon (*getSize_CTCommon) (HasSize_CTCommon, Int);
};
struct HasBackgroundColor_CTCommon {
    POLY GCINFO;
    Msg (*setBackgroundColor_CTCommon) (HasBackgroundColor_CTCommon,
                                        Color_CTCommon,
                                        Time,
                                        Time);
    Color_CTCommon (*getBackgroundColor_CTCommon) (HasBackgroundColor_CTCommon,
                                                   Int);
};
struct CocoaID_CTCommon {
    POLY GCINFO;
    Int dummy_CTCommon;
};
struct HandlesKeyEvents_CTCommon {
    POLY GCINFO;
    TUP0 (*installKeyListener_CTCommon) (HandlesKeyEvents_CTCommon,
                                         CLOS,
                                         Int);
};
struct HandlesMouseEvents_CTCommon {
    POLY GCINFO;
    TUP0 (*installMouseListener_CTCommon) (HandlesMouseEvents_CTCommon,
                                           CLOS,
                                           Int);
};
struct HandlesEvents_CTCommon {
    POLY GCINFO;
    Maybe_Prelude (*handleEvent_CTCommon) (HandlesEvents_CTCommon,
                                           CocoaEvent_CTCommon,
                                           LIST,
                                           Int);
};
struct HandlesWindowEvents_CTCommon {
    POLY GCINFO;
    HandlesEvents_CTCommon l_HandlesWindowEvents_CTCommon_HandlesEvents_CTCommon_CTCommon;
    TUP0 (*installWindowListener_CTCommon) (HandlesWindowEvents_CTCommon,
                                            CLOS,
                                            Int);
};
struct IsFocusable_CTCommon {
    POLY GCINFO;
    TUP0 (*setNextFocusTarget_CTCommon) (IsFocusable_CTCommon,
                                         Maybe_Prelude,
                                         Int);
    Maybe_Prelude (*getNextFocusTarget_CTCommon) (IsFocusable_CTCommon,
                                                  Int);
    TUP0 (*setPreviousFocusTarget_CTCommon) (IsFocusable_CTCommon,
                                             Maybe_Prelude,
                                             Int);
    Maybe_Prelude (*getPreviousFocusTarget_CTCommon) (IsFocusable_CTCommon,
                                                      Int);
    TUP0 (*setIsFocusable_CTCommon) (IsFocusable_CTCommon, Bool, Int);
    Bool (*getIsFocusable_CTCommon) (IsFocusable_CTCommon, Int);
};
struct Component_CTCommon {
    POLY GCINFO;
    IsFocusable_CTCommon l_Component_CTCommon_IsFocusable_CTCommon_CTCommon;
    HasSize_CTCommon l_Component_CTCommon_HasSize_CTCommon_CTCommon;
    HandlesEvents_CTCommon l_Component_CTCommon_HandlesEvents_CTCommon_CTCommon;
    CocoaID_CTCommon id_CTCommon;
    TUP0 (*init_CTCommon) (Component_CTCommon, App_CTCommon, Int);
    TUP0 (*destroy_CTCommon) (Component_CTCommon, Int);
    TUP0 (*setName_CTCommon) (Component_CTCommon, LIST, Int);
    LIST (*getName_CTCommon) (Component_CTCommon, Int);
};
struct ContainsComponents_CTCommon {
    POLY GCINFO;
    TUP0 (*addComponent_CTCommon) (ContainsComponents_CTCommon,
                                   Component_CTCommon,
                                   Int);
    LIST (*getComponents_CTCommon) (ContainsComponents_CTCommon, Int);
};
struct CocoaWindow_CTCommon {
    POLY GCINFO;
    ContainsComponents_CTCommon l_CocoaWindow_CTCommon_ContainsComponents_CTCommon_CTCommon;
    HandlesKeyEvents_CTCommon l_CocoaWindow_CTCommon_HandlesKeyEvents_CTCommon_CTCommon;
    HandlesWindowEvents_CTCommon l_CocoaWindow_CTCommon_HandlesWindowEvents_CTCommon_CTCommon;
    HandlesMouseEvents_CTCommon l_CocoaWindow_CTCommon_HandlesMouseEvents_CTCommon_CTCommon;
    CocoaID_CTCommon windowId_CTCommon;
    Int (*getId_CTCommon) (CocoaWindow_CTCommon, Int);
    TUP0 (*initWindow_CTCommon) (CocoaWindow_CTCommon,
                                 App_CTCommon,
                                 Int);
    TUP0 (*destroyWindow_CTCommon) (CocoaWindow_CTCommon, Int);
    Bool (*hide_CTCommon) (CocoaWindow_CTCommon, Int);
    Bool (*setVisible_CTCommon) (CocoaWindow_CTCommon, Int);
    Msg (*setFocus_CTCommon) (CocoaWindow_CTCommon,
                              Component_CTCommon,
                              Time,
                              Time);
};
struct App_CTCommon {
    POLY GCINFO;
    TUP0 (*showWindow_CTCommon) (App_CTCommon,
                                 CocoaWindow_CTCommon,
                                 Int);
    ApplicationState_CTCommon (*getApplicationState_CTCommon) (App_CTCommon,
                                                               Int);
    Msg (*eventDispatcher_CTCommon) (App_CTCommon,
                                     CocoaEvent_CTCommon,
                                     Int,
                                     Time,
                                     Time);
    TUP0 (*setEnv_CTCommon) (App_CTCommon, Env_POSIX, Int);
};
 
extern WORD __GC__ApplicationState_CTCommon[];
extern WORD __GC__CocoaState_CTCommon[];
extern WORD __GC__WindowEventType_CTCommon[];
extern WORD __GC__Position_CTCommon[];
extern WORD __GC__MouseEventType_CTCommon[];
extern WORD __GC___MouseMoved_CTCommon[];
extern WORD __GC___MouseReleased_CTCommon[];
extern WORD __GC___MousePressed_CTCommon[];
extern WORD __GC___MouseClicked_CTCommon[];
extern WORD __GC__CocoaKey_CTCommon[];
extern WORD __GC__KeyEventType_CTCommon[];
extern WORD __GC___KeyReleased_CTCommon[];
extern WORD __GC___KeyPressed_CTCommon[];
extern WORD __GC__CocoaEvent_CTCommon[];
extern WORD __GC___KeyEvent_CTCommon[];
extern WORD __GC___MouseEvent_CTCommon[];
extern WORD __GC___WindowEvent_CTCommon[];
extern WORD __GC__Size_CTCommon[];
extern WORD __GC__Color_CTCommon[];
extern WORD __GC__HasPosition_CTCommon[];
extern WORD __GC__HasSize_CTCommon[];
extern WORD __GC__HasBackgroundColor_CTCommon[];
extern WORD __GC__CocoaID_CTCommon[];
extern WORD __GC__HandlesKeyEvents_CTCommon[];
extern WORD __GC__HandlesMouseEvents_CTCommon[];
extern WORD __GC__HandlesEvents_CTCommon[];
extern WORD __GC__HandlesWindowEvents_CTCommon[];
extern WORD __GC__IsFocusable_CTCommon[];
extern WORD __GC__Component_CTCommon[];
extern WORD __GC__ContainsComponents_CTCommon[];
extern WORD __GC__CocoaWindow_CTCommon[];
extern WORD __GC__App_CTCommon[];
HasPosition_CTCommon c_560_CTCommon (HasSize_CTCommon v_562);
HandlesEvents_CTCommon c_563_CTCommon (HandlesWindowEvents_CTCommon v_565);
IsFocusable_CTCommon c_566_CTCommon (Component_CTCommon v_568);
HasSize_CTCommon c_569_CTCommon (Component_CTCommon v_571);
HandlesEvents_CTCommon c_572_CTCommon (Component_CTCommon v_574);
ContainsComponents_CTCommon c_575_CTCommon (CocoaWindow_CTCommon v_577);
HandlesKeyEvents_CTCommon c_578_CTCommon (CocoaWindow_CTCommon v_580);
HandlesWindowEvents_CTCommon c_581_CTCommon (CocoaWindow_CTCommon v_583);
HandlesMouseEvents_CTCommon c_584_CTCommon (CocoaWindow_CTCommon v_586);
HasPosition_CTCommon c_588_CTCommon (Component_CTCommon a_587);
HandlesEvents_CTCommon c_590_CTCommon (CocoaWindow_CTCommon a_589);
IsFocusable_CTCommon focusWrapper_CTCommon (Component_CTCommon this_219,
                                            Bool focusable_220,
                                            Int d_1654);
Bool dynamicHandleEvent_CTCommon (BITS32 a_1729,
                                  POLY a_264,
                                  Maybe_Prelude a_265,
                                  Ref a_1655);
Maybe_Prelude boolToMaybe_CTCommon (BITS32 a_1730,
                                    Maybe_Prelude a_269,
                                    Bool a_270);
LIST showName_CTCommon (BITS32 a_1732,
                        Maybe_Prelude a_275,
                        Ref a_1656);
Bool _sym_257_CTCommon/* == */ (CocoaState_CTCommon a_1657,
                                CocoaState_CTCommon a_1658);
Bool _sym_258_CTCommon/* /= */ (CocoaState_CTCommon a_1659,
                                CocoaState_CTCommon a_1660);
extern Eq_Prelude eqCocoaState_CTCommon;
Bool _sym_255_CTCommon/* == */ (CocoaKey_CTCommon a_1665,
                                CocoaKey_CTCommon a_1666);
Bool _sym_256_CTCommon/* /= */ (CocoaKey_CTCommon a_1667,
                                CocoaKey_CTCommon a_1668);
extern Eq_Prelude eqCocoaKey_CTCommon;
 
void _init_CTCommon ();
 
#include "CTCommon.extern.h"
#endif
