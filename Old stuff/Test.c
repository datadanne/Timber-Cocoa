#include "Test.h"
 
struct S_248;
typedef struct S_248 *S_248;
struct T_916;
typedef struct T_916 *T_916;
struct T_915;
typedef struct T_915 *T_915;
struct T_914;
typedef struct T_914 *T_914;
struct T_913;
typedef struct T_913 *T_913;
struct T_912;
typedef struct T_912 *T_912;
struct T_911;
typedef struct T_911 *T_911;
struct T_910;
typedef struct T_910 *T_910;
struct T_909;
typedef struct T_909 *T_909;
struct T_908;
typedef struct T_908 *T_908;
 
struct S_248 {
    POLY GCINFO;
};
struct T_916 {
    POLY GCINFO;
    TUP0 (*Code) (T_916);
    AbsTime baseline;
    AbsTime deadline;
    Msg next;
    Button_NSTest button_27;
    Ref self_23;
    NSWindow_NSTest window_22;
    CLOS printWindowList_17;
    Env_POSIX env_4;
    Ref self_3;
};
struct T_915 {
    POLY GCINFO;
    TUP0 (*Code) (T_915);
    AbsTime baseline;
    AbsTime deadline;
    Msg next;
    NSWindow_NSTest window_22;
    Ref self_21;
    CLOS printWindowList_17;
    CLOS printApplicationState_6;
    Env_POSIX env_4;
    Ref self_3;
};
struct T_914 {
    POLY GCINFO;
    TUP0 (*Code) (T_914);
    AbsTime baseline;
    AbsTime deadline;
    Msg next;
    CLOS printWindowList_17;
    CLOS printApplicationState_6;
    Env_COCOA osx_5;
    Env_POSIX env_4;
    Ref self_3;
};
struct T_913 {
    POLY GCINFO;
    Msg (*Code) (T_913, Time, Time);
    CLOS printWindowList_17;
    CLOS printApplicationState_6;
    Env_COCOA osx_5;
    Env_POSIX env_4;
    Ref self_3;
};
struct T_912 {
    POLY GCINFO;
    TUP0 (*Code) (T_912, NSWindow_NSTest, Ref);
    Env_POSIX env_4;
};
struct T_911 {
    POLY GCINFO;
    TUP0 (*Code) (T_911, Component_NSTest, Ref);
    Env_POSIX env_4;
};
struct T_910 {
    POLY GCINFO;
    TUP0 (*Code) (T_910);
    AbsTime baseline;
    AbsTime deadline;
    Msg next;
    NSWindow_NSTest window_13;
    Env_POSIX env_4;
    Ref self_3;
};
struct T_909 {
    POLY GCINFO;
    TUP0 (*Code) (T_909);
    AbsTime baseline;
    AbsTime deadline;
    Msg next;
    Env_COCOA osx_5;
    Env_POSIX env_4;
    Ref self_3;
};
struct T_908 {
    POLY GCINFO;
    Msg (*Code) (T_908, Time, Time);
    Env_COCOA osx_5;
    Env_POSIX env_4;
    Ref self_3;
};
 
static WORD __GC__S_248[];
static WORD __GC__T_916[];
static WORD __GC__T_915[];
static WORD __GC__T_914[];
static WORD __GC__T_913[];
static WORD __GC__T_912[];
static WORD __GC__T_911[];
static WORD __GC__T_910[];
static WORD __GC__T_909[];
static WORD __GC__T_908[];
static Msg f_907 (NSWindow_NSTest window_22,
                  Ref self_21,
                  CLOS printWindowList_17,
                  CLOS printApplicationState_6,
                  Env_POSIX env_4,
                  Ref self_3,
                  Time a_896,
                  Time a_897);
static Msg f_906 (Button_NSTest button_27,
                  Ref self_23,
                  NSWindow_NSTest window_22,
                  CLOS printWindowList_17,
                  Env_POSIX env_4,
                  Ref self_3,
                  Time a_891,
                  Time a_892);
static Msg printComponentList_12 (Env_POSIX env_4,
                                  Ref self_3,
                                  NSWindow_NSTest window_13,
                                  Time a_877,
                                  Time a_878);
static TUP0 f_925 (T_909 this_921);
static Msg f_926 (T_908 this_918, Time a_871, Time a_872);
static TUP0 f_935 (T_912 this_931,
                   NSWindow_NSTest a_880,
                   Ref a_881);
static TUP0 f_938 (T_909 this_930);
static Msg f_939 (T_908 this_927, Time a_887, Time a_888);
static TUP0 f_946 (T_914 this_943);
static Msg f_947 (T_913 this_940, Time a_901, Time a_902);
static TUP0 f_951 (T_915 this_948);
static TUP0 f_955 (T_916 this_952);
static TUP0 f_962 (T_911 this_958,
                   Component_NSTest a_873,
                   Ref a_874);
static TUP0 f_965 (T_910 this_956);
 
static WORD __GC__S_248[] = {WORDS(sizeof(struct S_248)), 0, 0};
static WORD __GC__T_916[] = {WORDS(sizeof(struct T_916)),
                             0,
                             WORDS(offsetof(struct T_916, button_27)),
                             WORDS(offsetof(struct T_916, self_23)),
                             WORDS(offsetof(struct T_916, window_22)),
                             WORDS(offsetof(struct T_916, printWindowList_17)),
                             WORDS(offsetof(struct T_916, env_4)),
                             WORDS(offsetof(struct T_916, self_3)),
                             0};
static WORD __GC__T_915[] = {WORDS(sizeof(struct T_915)),
                             0,
                             WORDS(offsetof(struct T_915, window_22)),
                             WORDS(offsetof(struct T_915, self_21)),
                             WORDS(offsetof(struct T_915, printWindowList_17)),
                             WORDS(offsetof(struct T_915, printApplicationState_6)),
                             WORDS(offsetof(struct T_915, env_4)),
                             WORDS(offsetof(struct T_915, self_3)),
                             0};
static WORD __GC__T_914[] = {WORDS(sizeof(struct T_914)),
                             0,
                             WORDS(offsetof(struct T_914, printWindowList_17)),
                             WORDS(offsetof(struct T_914, printApplicationState_6)),
                             WORDS(offsetof(struct T_914, osx_5)),
                             WORDS(offsetof(struct T_914, env_4)),
                             WORDS(offsetof(struct T_914, self_3)),
                             0};
static WORD __GC__T_913[] = {WORDS(sizeof(struct T_913)),
                             0,
                             WORDS(offsetof(struct T_913, printWindowList_17)),
                             WORDS(offsetof(struct T_913, printApplicationState_6)),
                             WORDS(offsetof(struct T_913, osx_5)),
                             WORDS(offsetof(struct T_913, env_4)),
                             WORDS(offsetof(struct T_913, self_3)),
                             0};
static WORD __GC__T_912[] = {WORDS(sizeof(struct T_912)),
                             0,
                             WORDS(offsetof(struct T_912, env_4)),
                             0};
static WORD __GC__T_911[] = {WORDS(sizeof(struct T_911)),
                             0,
                             WORDS(offsetof(struct T_911, env_4)),
                             0};
static WORD __GC__T_910[] = {WORDS(sizeof(struct T_910)),
                             0,
                             WORDS(offsetof(struct T_910, window_13)),
                             WORDS(offsetof(struct T_910, env_4)),
                             WORDS(offsetof(struct T_910, self_3)),
                             0};
static WORD __GC__T_909[] = {WORDS(sizeof(struct T_909)),
                             0,
                             WORDS(offsetof(struct T_909, osx_5)),
                             WORDS(offsetof(struct T_909, env_4)),
                             WORDS(offsetof(struct T_909, self_3)),
                             0};
static WORD __GC__T_908[] = {WORDS(sizeof(struct T_908)),
                             0,
                             WORDS(offsetof(struct T_908, osx_5)),
                             WORDS(offsetof(struct T_908, env_4)),
                             WORDS(offsetof(struct T_908, self_3)),
                             0};
CLOS root_Test (World w_2, Int d_905) {
    Ref self_3;
    NEW (Ref, self_3, WORDS(sizeof(struct Ref))+
                      WORDS(sizeof(struct S_248)));
    INITREF(self_3);
    ((S_248)STATEOF(self_3))->GCINFO = __GC__S_248;
    Env_POSIX env_4;
    env_4 = posix_POSIX(w_2, 0);
    Env_COCOA osx_5;
    osx_5 = cocoa_COCOA(w_2, 0);
    CLOS printApplicationState_6;
    NEW (CLOS, printApplicationState_6, WORDS(sizeof(struct T_908)));
    ((T_908)printApplicationState_6)->GCINFO = __GC__T_908;
    ((T_908)printApplicationState_6)->Code = f_926;
    ((T_908)printApplicationState_6)->osx_5 = osx_5;
    ((T_908)printApplicationState_6)->env_4 = env_4;
    ((T_908)printApplicationState_6)->self_3 = self_3;
    CLOS printWindowList_17;
    NEW (CLOS, printWindowList_17, WORDS(sizeof(struct T_908)));
    ((T_908)printWindowList_17)->GCINFO = __GC__T_908;
    ((T_908)printWindowList_17)->Code = f_939;
    ((T_908)printWindowList_17)->osx_5 = osx_5;
    ((T_908)printWindowList_17)->env_4 = env_4;
    ((T_908)printWindowList_17)->self_3 = self_3;
    CLOS x_904;
    NEW (CLOS, x_904, WORDS(sizeof(struct T_913)));
    ((T_913)x_904)->GCINFO = __GC__T_913;
    ((T_913)x_904)->Code = f_947;
    ((T_913)x_904)->printWindowList_17 = printWindowList_17;
    ((T_913)x_904)->printApplicationState_6 = printApplicationState_6;
    ((T_913)x_904)->osx_5 = osx_5;
    ((T_913)x_904)->env_4 = env_4;
    ((T_913)x_904)->self_3 = self_3;
    return x_904;
}
static Msg f_907 (NSWindow_NSTest window_22,
                  Ref self_21,
                  CLOS printWindowList_17,
                  CLOS printApplicationState_6,
                  Env_POSIX env_4,
                  Ref self_3,
                  Time a_896,
                  Time a_897) {
    Msg x_898;
    NEW (Msg, x_898, WORDS(sizeof(struct T_915)));
    ((T_915)x_898)->GCINFO = __GC__T_915;
    ((T_915)x_898)->Code = f_951;
    ((T_915)x_898)->window_22 = window_22;
    ((T_915)x_898)->self_21 = self_21;
    ((T_915)x_898)->printWindowList_17 = printWindowList_17;
    ((T_915)x_898)->printApplicationState_6 = printApplicationState_6;
    ((T_915)x_898)->env_4 = env_4;
    ((T_915)x_898)->self_3 = self_3;
    return (Msg)ASYNC(x_898, a_896, a_897);
}
static Msg f_906 (Button_NSTest button_27,
                  Ref self_23,
                  NSWindow_NSTest window_22,
                  CLOS printWindowList_17,
                  Env_POSIX env_4,
                  Ref self_3,
                  Time a_891,
                  Time a_892) {
    Msg x_893;
    NEW (Msg, x_893, WORDS(sizeof(struct T_916)));
    ((T_916)x_893)->GCINFO = __GC__T_916;
    ((T_916)x_893)->Code = f_955;
    ((T_916)x_893)->button_27 = button_27;
    ((T_916)x_893)->self_23 = self_23;
    ((T_916)x_893)->window_22 = window_22;
    ((T_916)x_893)->printWindowList_17 = printWindowList_17;
    ((T_916)x_893)->env_4 = env_4;
    ((T_916)x_893)->self_3 = self_3;
    return (Msg)ASYNC(x_893, a_891, a_892);
}
static Msg printComponentList_12 (Env_POSIX env_4,
                                  Ref self_3,
                                  NSWindow_NSTest window_13,
                                  Time a_877,
                                  Time a_878) {
    Msg x_879;
    NEW (Msg, x_879, WORDS(sizeof(struct T_910)));
    ((T_910)x_879)->GCINFO = __GC__T_910;
    ((T_910)x_879)->Code = f_965;
    ((T_910)x_879)->window_13 = window_13;
    ((T_910)x_879)->env_4 = env_4;
    ((T_910)x_879)->self_3 = self_3;
    return (Msg)ASYNC(x_879, a_877, a_878);
}
static TUP0 f_925 (T_909 this_921) {
    Ref self_7;
    self_7 = (Ref)LOCK((OID)this_921->self_3);
    Env_COCOA x_922;
    x_922 = this_921->osx_5;
    ApplicationState_COCOA p_8;
    p_8 = x_922->getApplicationState_COCOA(x_922, 0);
    switch ((WORD)p_8) {
        case 1: { Ref self_9;
                  self_9 = self_7;
                  WFile_POSIX x_923;
                  x_923 = this_921->env_4->stdout_POSIX;
                  Int d_29;
                  d_29 = x_923->write_POSIX(x_923,
                                            getStr("ApplicationState: Running\n"),
                                            0);
                  UNLOCK((OID)self_7);
                  return (TUP0)0;
                }
                break;
        case 0: { Ref self_10;
                  self_10 = self_7;
                  WFile_POSIX x_924;
                  x_924 = this_921->env_4->stdout_POSIX;
                  Int d_30;
                  d_30 = x_924->write_POSIX(x_924,
                                            getStr("ApplicationState: Stopped\n"),
                                            0);
                  UNLOCK((OID)self_7);
                  return (TUP0)0;
                }
                break;
    }
}
static Msg f_926 (T_908 this_918, Time a_871, Time a_872) {
    Msg x_870;
    NEW (Msg, x_870, WORDS(sizeof(struct T_909)));
    ((T_909)x_870)->GCINFO = __GC__T_909;
    ((T_909)x_870)->Code = f_925;
    ((T_909)x_870)->osx_5 = this_918->osx_5;
    ((T_909)x_870)->env_4 = this_918->env_4;
    ((T_909)x_870)->self_3 = this_918->self_3;
    return (Msg)ASYNC(x_870, a_871, a_872);
}
static TUP0 f_935 (T_912 this_931,
                   NSWindow_NSTest a_880,
                   Ref a_881) {
    WFile_POSIX x_934;
    x_934 = this_931->env_4->stdout_POSIX;
    Int d_37;
    d_37 = x_934->write_POSIX(x_934,
                              getStr("window detected in list!\n"),
                              0);
    return (TUP0)0;
}
static TUP0 f_938 (T_909 this_930) {
    Ref self_18;
    self_18 = (Ref)LOCK((OID)this_930->self_3);
    T_912 x_936;
    NEW (T_912, x_936, WORDS(sizeof(struct T_912)));
    x_936->GCINFO = __GC__T_912;
    x_936->Code = f_935;
    x_936->env_4 = this_930->env_4;
    TUP0 d_36;
    d_36 = forallListUnit_Prelude((BITS32)4,
                                  (CLOS)x_936,
                                  this_930->osx_5->windows_COCOA,
                                  self_18);
    WFile_POSIX x_937;
    x_937 = this_930->env_4->stdout_POSIX;
    Int d_38;
    d_38 = x_937->write_POSIX(x_937, getStr("no more windows..\n"), 0);
    UNLOCK((OID)self_18);
    return (TUP0)0;
}
static Msg f_939 (T_908 this_927, Time a_887, Time a_888) {
    Msg x_886;
    NEW (Msg, x_886, WORDS(sizeof(struct T_909)));
    ((T_909)x_886)->GCINFO = __GC__T_909;
    ((T_909)x_886)->Code = f_938;
    ((T_909)x_886)->osx_5 = this_927->osx_5;
    ((T_909)x_886)->env_4 = this_927->env_4;
    ((T_909)x_886)->self_3 = this_927->self_3;
    return (Msg)ASYNC(x_886, a_887, a_888);
}
static TUP0 f_946 (T_914 this_943) {
    Ref self_21;
    self_21 = (Ref)LOCK((OID)this_943->self_3);
    Env_COCOA x_944;
    x_944 = this_943->osx_5;
    Msg d_39;
    d_39 = x_944->startApplication_COCOA(x_944, Inherit, Inherit);
    NSWindow_NSTest window_22;
    window_22 = mkNSWindow_NSTest(0);
    CLOS x_945;
    x_945 = this_943->printWindowList_17;
    Msg d_40;
    d_40 = ((Msg(*)(CLOS, Time, Time))(x_945->Code))(x_945,
                                                     Inherit,
                                                     Inherit);
    Msg d_41;
    d_41 = f_907(window_22,
                 self_21,
                 this_943->printWindowList_17,
                 this_943->printApplicationState_6,
                 this_943->env_4,
                 this_943->self_3,
                 primTimePlus(Inherit, sec(2)),
                 Inherit);
    UNLOCK((OID)self_21);
    return (TUP0)0;
}
static Msg f_947 (T_913 this_940, Time a_901, Time a_902) {
    Msg x_903;
    NEW (Msg, x_903, WORDS(sizeof(struct T_914)));
    ((T_914)x_903)->GCINFO = __GC__T_914;
    ((T_914)x_903)->Code = f_946;
    ((T_914)x_903)->printWindowList_17 = this_940->printWindowList_17;
    ((T_914)x_903)->printApplicationState_6 = this_940->printApplicationState_6;
    ((T_914)x_903)->osx_5 = this_940->osx_5;
    ((T_914)x_903)->env_4 = this_940->env_4;
    ((T_914)x_903)->self_3 = this_940->self_3;
    return (Msg)ASYNC(x_903, a_901, a_902);
}
static TUP0 f_951 (T_915 this_948) {
    Ref self_23;
    self_23 = (Ref)LOCK((OID)this_948->self_21);
    NSWindow_NSTest window2_24;
    window2_24 = mkNSWindow_NSTest(0);
    NSWindow_NSTest window3_25;
    window3_25 = mkNSWindow_NSTest(0);
    Button_NSTest button2_26;
    button2_26 = mkButton_NSTest(0);
    NSWindow_NSTest x_949;
    x_949 = this_948->window_22;
    Msg d_42;
    d_42 = x_949->addButton_NSTest(x_949,
                                   button2_26,
                                   Inherit,
                                   Inherit);
    Button_NSTest button_27;
    button_27 = mkButton_NSTest(0);
    Msg d_43;
    d_43 = window2_24->addButton_NSTest(window2_24,
                                        button_27,
                                        Inherit,
                                        Inherit);
    CLOS x_950;
    x_950 = this_948->printApplicationState_6;
    Msg d_44;
    d_44 = ((Msg(*)(CLOS, Time, Time))(x_950->Code))(x_950,
                                                     Inherit,
                                                     Inherit);
    Msg d_45;
    d_45 = printComponentList_12(this_948->env_4,
                                 this_948->self_3,
                                 this_948->window_22,
                                 Inherit,
                                 Inherit);
    Msg d_46;
    d_46 = f_906(button_27,
                 self_23,
                 this_948->window_22,
                 this_948->printWindowList_17,
                 this_948->env_4,
                 this_948->self_3,
                 primTimePlus(Inherit, sec(2)),
                 Inherit);
    UNLOCK((OID)self_23);
    return (TUP0)0;
}
static TUP0 f_955 (T_916 this_952) {
    Ref self_28;
    self_28 = (Ref)LOCK((OID)this_952->self_23);
    CLOS x_953;
    x_953 = this_952->printWindowList_17;
    Msg d_47;
    d_47 = ((Msg(*)(CLOS, Time, Time))(x_953->Code))(x_953,
                                                     Inherit,
                                                     Inherit);
    Button_NSTest x_954;
    x_954 = this_952->button_27;
    Msg d_48;
    d_48 = x_954->setTitle_NSTest(x_954,
                                  getStr("Hello"),
                                  Inherit,
                                  Inherit);
    Msg d_49;
    d_49 = printComponentList_12(this_952->env_4,
                                 this_952->self_3,
                                 this_952->window_22,
                                 Inherit,
                                 Inherit);
    UNLOCK((OID)self_28);
    return (TUP0)0;
}
static TUP0 f_962 (T_911 this_958,
                   Component_NSTest a_873,
                   Ref a_874) {
    WFile_POSIX x_961;
    x_961 = this_958->env_4->stdout_POSIX;
    Int d_34;
    d_34 = x_961->write_POSIX(x_961,
                              getStr("found a component in list!\n"),
                              0);
    return (TUP0)0;
}
static TUP0 f_965 (T_910 this_956) {
    Ref self_14;
    self_14 = (Ref)LOCK((OID)this_956->self_3);
    WFile_POSIX x_957;
    x_957 = this_956->env_4->stdout_POSIX;
    Int d_32;
    d_32 = x_957->write_POSIX(x_957, getStr("---\n"), 0);
    T_911 x_963;
    NEW (T_911, x_963, WORDS(sizeof(struct T_911)));
    x_963->GCINFO = __GC__T_911;
    x_963->Code = f_962;
    x_963->env_4 = this_956->env_4;
    TUP0 d_33;
    d_33 = forallListUnit_Prelude((BITS32)4,
                                  (CLOS)x_963,
                                  this_956->window_13->myComponents_NSTest,
                                  self_14);
    WFile_POSIX x_964;
    x_964 = this_956->env_4->stdout_POSIX;
    Int d_35;
    d_35 = x_964->write_POSIX(x_964, getStr("---\n"), 0);
    UNLOCK((OID)self_14);
    return (TUP0)0;
}
 
void _init_Test () {
    static int INITIALIZED = 0;
    if (!INITIALIZED) {
        _init_Prelude();
        _init_POSIX();
        _init_COCOA();
        INITIALIZED = 1;
    }
}
 

