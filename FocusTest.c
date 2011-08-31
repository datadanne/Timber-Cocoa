#include "FocusTest.h"
 
struct S_574;
typedef struct S_574 *S_574;
struct T_2101;
typedef struct T_2101 *T_2101;
struct T_2100;
typedef struct T_2100 *T_2100;
struct T_2099;
typedef struct T_2099 *T_2099;
struct T_2098;
typedef struct T_2098 *T_2098;
struct T_2097;
typedef struct T_2097 *T_2097;
struct T_2096;
typedef struct T_2096 *T_2096;
struct T_2095;
typedef struct T_2095 *T_2095;
struct T_2094;
typedef struct T_2094 *T_2094;
struct T_2093;
typedef struct T_2093 *T_2093;
struct T_2092;
typedef struct T_2092 *T_2092;
struct T_2091;
typedef struct T_2091 *T_2091;
struct T_2090;
typedef struct T_2090 *T_2090;
 
struct S_574 {
    POLY GCINFO;
    Bool block_4;
};
struct T_2101 {
    POLY GCINFO;
    Bool (*Code) (T_2101, KeyEventType_CTCommon, Int);
    CLOS tabStop_18;
};
struct T_2100 {
    POLY GCINFO;
    TUP0 (*Code) (T_2100);
    AbsTime baseline;
    AbsTime deadline;
    Msg next;
    CLOS applicationDidFinishLaunching_25;
    CLOS tabStop_18;
    Button_CTButton button2_10;
    Button_CTButton button_9;
    Container_CTContainer c2_8;
    CocoaWindow_CTCommon w1_7;
    Env_COCOA osx_6;
    Ref self_3;
};
struct T_2099 {
    POLY GCINFO;
    Msg (*Code) (T_2099, Time, Time);
    CLOS applicationDidFinishLaunching_25;
    CLOS tabStop_18;
    Button_CTButton button2_10;
    Button_CTButton button_9;
    Container_CTContainer c2_8;
    CocoaWindow_CTCommon w1_7;
    Env_COCOA osx_6;
    Ref self_3;
};
struct T_2098 {
    POLY GCINFO;
    TUP0 (*Code) (T_2098);
    AbsTime baseline;
    AbsTime deadline;
    Msg next;
    Ref self_27;
    CLOS doNothing_22;
    CocoaWindow_CTCommon w1_7;
    Env_POSIX env_5;
};
struct T_2097 {
    POLY GCINFO;
    Bool (*Code) (T_2097, MouseEventType_CTCommon, Int);
    CLOS doNothing_22;
};
struct T_2096 {
    POLY GCINFO;
    TUP0 (*Code) (T_2096);
    AbsTime baseline;
    AbsTime deadline;
    Msg next;
    App_CTCommon a_2071;
    CLOS doNothing_22;
    Button_CTButton button2_10;
    Button_CTButton button_9;
    CocoaWindow_CTCommon w1_7;
    Env_POSIX env_5;
    Ref self_3;
};
struct T_2095 {
    POLY GCINFO;
    Msg (*Code) (T_2095, App_CTCommon, Time, Time);
    CLOS doNothing_22;
    Button_CTButton button2_10;
    Button_CTButton button_9;
    CocoaWindow_CTCommon w1_7;
    Env_POSIX env_5;
    Ref self_3;
};
struct T_2094 {
    POLY GCINFO;
    Bool (*Code) (T_2094, BITS32, POLY, Int);
    Env_POSIX env_5;
    Ref self_3;
};
struct T_2093 {
    POLY GCINFO;
    LIST (*Code) (T_2093);
    Ref self_20;
};
struct T_2092 {
    POLY GCINFO;
    TUP0 (*Code) (T_2092);
    AbsTime baseline;
    AbsTime deadline;
    Msg next;
    Ref self_20;
    Button_CTButton button_9;
};
struct T_2091 {
    POLY GCINFO;
    Bool (*Code) (T_2091, BITS32, POLY, Int);
    Button_CTButton button_9;
    Env_POSIX env_5;
    Ref self_3;
};
struct T_2090 {
    POLY GCINFO;
    Bool (*Code) (T_2090, BITS32, App_CTCommon, Int, POLY, Int);
    Env_POSIX env_5;
    Ref self_3;
};
 
static WORD __GC__S_574[];
static WORD __GC__T_2101[];
static WORD __GC__T_2100[];
static WORD __GC__T_2099[];
static WORD __GC__T_2098[];
static WORD __GC__T_2097[];
static WORD __GC__T_2096[];
static WORD __GC__T_2095[];
static WORD __GC__T_2094[];
static WORD __GC__T_2093[];
static WORD __GC__T_2092[];
static WORD __GC__T_2091[];
static WORD __GC__T_2090[];
static Msg f_2089 (Ref self_27,
                   CLOS doNothing_22,
                   CocoaWindow_CTCommon w1_7,
                   Env_POSIX env_5,
                   Time a_2063,
                   Time a_2064);
static Msg f_2088 (Ref self_20,
                   Button_CTButton button_9,
                   Time a_2033,
                   Time a_2034);
static Bool f_2112 (T_2090 this_2103,
                    BITS32 a_2108,
                    App_CTCommon a_2027,
                    Int a_2028,
                    POLY a_2029,
                    Int a_2030);
static LIST f_2118 (T_2093 this_2117);
static Bool f_2121 (T_2091 this_2113,
                    BITS32 a_2116,
                    POLY a_2039,
                    Int a_2040);
static Bool f_2127 (T_2094 this_2122,
                    BITS32 a_2125,
                    POLY a_2043,
                    Int a_2044);
static Bool f_2141 (T_2097 this_2137,
                    MouseEventType_CTCommon a_2047,
                    Int a_2048);
static Bool f_2149 (T_2097 this_2145,
                    MouseEventType_CTCommon a_2051,
                    Int a_2052);
static Bool f_2156 (T_2097 this_2152,
                    MouseEventType_CTCommon a_2055,
                    Int a_2056);
static TUP0 f_2166 (T_2096 this_2132);
static Msg f_2167 (T_2095 this_2128,
                   App_CTCommon a_2071,
                   Time a_2072,
                   Time a_2073);
static Bool f_2180 (T_2101 this_2176,
                    KeyEventType_CTCommon a_2076,
                    Int a_2077);
static TUP0 f_2194 (T_2100 this_2171);
static Msg f_2195 (T_2099 this_2168, Time a_2083, Time a_2084);
static Bool f_2201 (T_2097 this_2197,
                    MouseEventType_CTCommon a_2059,
                    Int a_2060);
static TUP0 f_2213 (T_2098 this_2196);
static TUP0 f_2216 (T_2092 this_2214);
 
static WORD __GC__S_574[] = {WORDS(sizeof(struct S_574)), 0, 0};
static WORD __GC__T_2101[] = {WORDS(sizeof(struct T_2101)),
                              0,
                              WORDS(offsetof(struct T_2101, tabStop_18)),
                              0};
static WORD __GC__T_2100[] = {WORDS(sizeof(struct T_2100)),
                              0,
                              WORDS(offsetof(struct T_2100, applicationDidFinishLaunching_25)),
                              WORDS(offsetof(struct T_2100, tabStop_18)),
                              WORDS(offsetof(struct T_2100, button2_10)),
                              WORDS(offsetof(struct T_2100, button_9)),
                              WORDS(offsetof(struct T_2100, c2_8)),
                              WORDS(offsetof(struct T_2100, w1_7)),
                              WORDS(offsetof(struct T_2100, osx_6)),
                              WORDS(offsetof(struct T_2100, self_3)),
                              0};
static WORD __GC__T_2099[] = {WORDS(sizeof(struct T_2099)),
                              0,
                              WORDS(offsetof(struct T_2099, applicationDidFinishLaunching_25)),
                              WORDS(offsetof(struct T_2099, tabStop_18)),
                              WORDS(offsetof(struct T_2099, button2_10)),
                              WORDS(offsetof(struct T_2099, button_9)),
                              WORDS(offsetof(struct T_2099, c2_8)),
                              WORDS(offsetof(struct T_2099, w1_7)),
                              WORDS(offsetof(struct T_2099, osx_6)),
                              WORDS(offsetof(struct T_2099, self_3)),
                              0};
static WORD __GC__T_2098[] = {WORDS(sizeof(struct T_2098)),
                              0,
                              WORDS(offsetof(struct T_2098, self_27)),
                              WORDS(offsetof(struct T_2098, doNothing_22)),
                              WORDS(offsetof(struct T_2098, w1_7)),
                              WORDS(offsetof(struct T_2098, env_5)),
                              0};
static WORD __GC__T_2097[] = {WORDS(sizeof(struct T_2097)),
                              0,
                              WORDS(offsetof(struct T_2097, doNothing_22)),
                              0};
static WORD __GC__T_2096[] = {WORDS(sizeof(struct T_2096)),
                              0,
                              WORDS(offsetof(struct T_2096, a_2071)),
                              WORDS(offsetof(struct T_2096, doNothing_22)),
                              WORDS(offsetof(struct T_2096, button2_10)),
                              WORDS(offsetof(struct T_2096, button_9)),
                              WORDS(offsetof(struct T_2096, w1_7)),
                              WORDS(offsetof(struct T_2096, env_5)),
                              WORDS(offsetof(struct T_2096, self_3)),
                              0};
static WORD __GC__T_2095[] = {WORDS(sizeof(struct T_2095)),
                              0,
                              WORDS(offsetof(struct T_2095, doNothing_22)),
                              WORDS(offsetof(struct T_2095, button2_10)),
                              WORDS(offsetof(struct T_2095, button_9)),
                              WORDS(offsetof(struct T_2095, w1_7)),
                              WORDS(offsetof(struct T_2095, env_5)),
                              WORDS(offsetof(struct T_2095, self_3)),
                              0};
static WORD __GC__T_2094[] = {WORDS(sizeof(struct T_2094)),
                              0,
                              WORDS(offsetof(struct T_2094, env_5)),
                              WORDS(offsetof(struct T_2094, self_3)),
                              0};
static WORD __GC__T_2093[] = {WORDS(sizeof(struct T_2093)),
                              0,
                              WORDS(offsetof(struct T_2093, self_20)),
                              0};
static WORD __GC__T_2092[] = {WORDS(sizeof(struct T_2092)),
                              0,
                              WORDS(offsetof(struct T_2092, self_20)),
                              WORDS(offsetof(struct T_2092, button_9)),
                              0};
static WORD __GC__T_2091[] = {WORDS(sizeof(struct T_2091)),
                              0,
                              WORDS(offsetof(struct T_2091, button_9)),
                              WORDS(offsetof(struct T_2091, env_5)),
                              WORDS(offsetof(struct T_2091, self_3)),
                              0};
static WORD __GC__T_2090[] = {WORDS(sizeof(struct T_2090)),
                              0,
                              WORDS(offsetof(struct T_2090, env_5)),
                              WORDS(offsetof(struct T_2090, self_3)),
                              0};
CLOS root_FocusTest (World w_2, Int d_2087) {
    Ref self_3;
    NEW (Ref, self_3, WORDS(sizeof(struct Ref))+
                      WORDS(sizeof(struct S_574)));
    INITREF(self_3);
    ((S_574)STATEOF(self_3))->GCINFO = __GC__S_574;
    Env_POSIX env_5;
    env_5 = posix_POSIX(w_2, 0);
    Env_COCOA osx_6;
    osx_6 = cocoa_COCOA(w_2, 0);
    CocoaWindow_CTCommon w1_7;
    w1_7 = mkWindow_CTWindow(env_5, 0);
    Container_CTContainer c2_8;
    c2_8 = mkContainer_CTContainer(env_5, 0);
    Button_CTButton button_9;
    button_9 = mkCocoaButton_CTButton((BITS32)0, (POLY)env_5, 0);
    Button_CTButton button2_10;
    button2_10 = mkCocoaButton_CTButton((BITS32)0, (POLY)env_5, 0);
    CLOS tabClick_11;
    NEW (CLOS, tabClick_11, WORDS(sizeof(struct T_2090)));
    ((T_2090)tabClick_11)->GCINFO = __GC__T_2090;
    ((T_2090)tabClick_11)->Code = f_2112;
    ((T_2090)tabClick_11)->env_5 = env_5;
    ((T_2090)tabClick_11)->self_3 = self_3;
    CLOS tabStop_18;
    NEW (CLOS, tabStop_18, WORDS(sizeof(struct T_2091)));
    ((T_2091)tabStop_18)->GCINFO = __GC__T_2091;
    ((T_2091)tabStop_18)->Code = f_2121;
    ((T_2091)tabStop_18)->button_9 = button_9;
    ((T_2091)tabStop_18)->env_5 = env_5;
    ((T_2091)tabStop_18)->self_3 = self_3;
    CLOS doNothing_22;
    NEW (CLOS, doNothing_22, WORDS(sizeof(struct T_2094)));
    ((T_2094)doNothing_22)->GCINFO = __GC__T_2094;
    ((T_2094)doNothing_22)->Code = f_2127;
    ((T_2094)doNothing_22)->env_5 = env_5;
    ((T_2094)doNothing_22)->self_3 = self_3;
    CLOS applicationDidFinishLaunching_25;
    NEW (CLOS, applicationDidFinishLaunching_25, WORDS(sizeof(struct T_2095)));
    ((T_2095)applicationDidFinishLaunching_25)->GCINFO = __GC__T_2095;
    ((T_2095)applicationDidFinishLaunching_25)->Code = f_2167;
    ((T_2095)applicationDidFinishLaunching_25)->doNothing_22 = doNothing_22;
    ((T_2095)applicationDidFinishLaunching_25)->button2_10 = button2_10;
    ((T_2095)applicationDidFinishLaunching_25)->button_9 = button_9;
    ((T_2095)applicationDidFinishLaunching_25)->w1_7 = w1_7;
    ((T_2095)applicationDidFinishLaunching_25)->env_5 = env_5;
    ((T_2095)applicationDidFinishLaunching_25)->self_3 = self_3;
    ((S_574)STATEOF(self_3))->block_4 = (Bool)0;
    CLOS x_2086;
    NEW (CLOS, x_2086, WORDS(sizeof(struct T_2099)));
    ((T_2099)x_2086)->GCINFO = __GC__T_2099;
    ((T_2099)x_2086)->Code = f_2195;
    ((T_2099)x_2086)->applicationDidFinishLaunching_25 = applicationDidFinishLaunching_25;
    ((T_2099)x_2086)->tabStop_18 = tabStop_18;
    ((T_2099)x_2086)->button2_10 = button2_10;
    ((T_2099)x_2086)->button_9 = button_9;
    ((T_2099)x_2086)->c2_8 = c2_8;
    ((T_2099)x_2086)->w1_7 = w1_7;
    ((T_2099)x_2086)->osx_6 = osx_6;
    ((T_2099)x_2086)->self_3 = self_3;
    return x_2086;
}
static Msg f_2089 (Ref self_27,
                   CLOS doNothing_22,
                   CocoaWindow_CTCommon w1_7,
                   Env_POSIX env_5,
                   Time a_2063,
                   Time a_2064) {
    Msg x_2065;
    NEW (Msg, x_2065, WORDS(sizeof(struct T_2098)));
    ((T_2098)x_2065)->GCINFO = __GC__T_2098;
    ((T_2098)x_2065)->Code = f_2213;
    ((T_2098)x_2065)->self_27 = self_27;
    ((T_2098)x_2065)->doNothing_22 = doNothing_22;
    ((T_2098)x_2065)->w1_7 = w1_7;
    ((T_2098)x_2065)->env_5 = env_5;
    return (Msg)ASYNC(x_2065, a_2063, a_2064);
}
static Msg f_2088 (Ref self_20,
                   Button_CTButton button_9,
                   Time a_2033,
                   Time a_2034) {
    Msg x_2035;
    NEW (Msg, x_2035, WORDS(sizeof(struct T_2092)));
    ((T_2092)x_2035)->GCINFO = __GC__T_2092;
    ((T_2092)x_2035)->Code = f_2216;
    ((T_2092)x_2035)->self_20 = self_20;
    ((T_2092)x_2035)->button_9 = button_9;
    return (Msg)ASYNC(x_2035, a_2033, a_2034);
}
static Bool f_2112 (T_2090 this_2103,
                    BITS32 a_2108,
                    App_CTCommon a_2027,
                    Int a_2028,
                    POLY a_2029,
                    Int a_2030) {
    Ref self_15;
    self_15 = (Ref)LOCK((OID)this_2103->self_3);
    WFile_POSIX x_2109;
    x_2109 = this_2103->env_5->stdout_POSIX;
    Int d_33;
    d_33 = x_2109->write_POSIX(x_2109,
                               _sym_20_Prelude/* ++ */((BITS32)1,
                                                       getStr("Sending KeyPressed \"Tab\" to window with ID: "),
                                                       _sym_20_Prelude/* ++ */((BITS32)1,
                                                                               show_723_Prelude(a_2028),
                                                                               getStr("\n"))),
                               0);
    _KeyPressed_CTCommon x_2110;
    NEW (_KeyPressed_CTCommon, x_2110, WORDS(sizeof(struct _KeyPressed_CTCommon)));
    x_2110->GCINFO = __GC___KeyPressed_CTCommon;
    x_2110->Tag = 1;
    x_2110->a = (CocoaKey_CTCommon)0;
    CocoaEvent_CTCommon foo_16;
    NEW (CocoaEvent_CTCommon, foo_16, WORDS(sizeof(struct _KeyEvent_CTCommon)));
    ((_KeyEvent_CTCommon)foo_16)->GCINFO = __GC___KeyEvent_CTCommon;
    ((_KeyEvent_CTCommon)foo_16)->Tag = 0;
    ((_KeyEvent_CTCommon)foo_16)->a = (KeyEventType_CTCommon)x_2110;
    _KeyPressed_CTCommon x_2111;
    NEW (_KeyPressed_CTCommon, x_2111, WORDS(sizeof(struct _KeyPressed_CTCommon)));
    x_2111->GCINFO = __GC___KeyPressed_CTCommon;
    x_2111->Tag = 1;
    x_2111->a = (CocoaKey_CTCommon)78;
    CocoaEvent_CTCommon superTest_17;
    NEW (CocoaEvent_CTCommon, superTest_17, WORDS(sizeof(struct _KeyEvent_CTCommon)));
    ((_KeyEvent_CTCommon)superTest_17)->GCINFO = __GC___KeyEvent_CTCommon;
    ((_KeyEvent_CTCommon)superTest_17)->Tag = 0;
    ((_KeyEvent_CTCommon)superTest_17)->a = (KeyEventType_CTCommon)x_2111;
    Msg d_34;
    d_34 = a_2027->eventDispatcher_CTCommon(a_2027,
                                            superTest_17,
                                            a_2028,
                                            Inherit,
                                            Inherit);
    UNLOCK((OID)self_15);
    return (Bool)1;
}
static LIST f_2118 (T_2093 this_2117) {
    switch ((WORD)((S_574)STATEOF(this_2117->self_20))->block_4) {
        case 1: return getStr("Tab shall not pass!\n");
        case 0: return getStr("It\'s ok. Tab may continue.\n");
    }
}
static Bool f_2121 (T_2091 this_2113,
                    BITS32 a_2116,
                    POLY a_2039,
                    Int a_2040) {
    Ref self_20;
    self_20 = (Ref)LOCK((OID)this_2113->self_3);
    Msg d_35;
    d_35 = f_2088(self_20,
                  this_2113->button_9,
                  primTimePlus(Inherit, millisec(100)),
                  Inherit);
    ((S_574)STATEOF(self_20))->block_4 = not_Prelude(((S_574)STATEOF(self_20))->block_4);
    CLOS x_2119;
    NEW (CLOS, x_2119, WORDS(sizeof(struct T_2093)));
    ((T_2093)x_2119)->GCINFO = __GC__T_2093;
    ((T_2093)x_2119)->Code = f_2118;
    ((T_2093)x_2119)->self_20 = self_20;
    WFile_POSIX x_2120;
    x_2120 = this_2113->env_5->stdout_POSIX;
    Int d_37;
    d_37 = x_2120->write_POSIX(x_2120,
                               ((LIST(*)(CLOS))(x_2119->Code))(x_2119),
                               0);
    Bool x_2036;
    x_2036 = ((S_574)STATEOF(self_20))->block_4;
    UNLOCK((OID)self_20);
    return x_2036;
}
static Bool f_2127 (T_2094 this_2122,
                    BITS32 a_2125,
                    POLY a_2043,
                    Int a_2044) {
    Ref self_24;
    self_24 = (Ref)LOCK((OID)this_2122->self_3);
    WFile_POSIX x_2126;
    x_2126 = this_2122->env_5->stdout_POSIX;
    Int d_38;
    d_38 = x_2126->write_POSIX(x_2126, getStr("MOUSE CLICK"), 0);
    UNLOCK((OID)self_24);
    return (Bool)1;
}
static Bool f_2141 (T_2097 this_2137,
                    MouseEventType_CTCommon a_2047,
                    Int a_2048) {
    CLOS x_2140;
    x_2140 = this_2137->doNothing_22;
    return ((Bool(*)(CLOS, BITS32, POLY, Int))(x_2140->Code))(x_2140,
                                                              (BITS32)0,
                                                              (POLY)a_2047,
                                                              a_2048);
}
static Bool f_2149 (T_2097 this_2145,
                    MouseEventType_CTCommon a_2051,
                    Int a_2052) {
    CLOS x_2148;
    x_2148 = this_2145->doNothing_22;
    return ((Bool(*)(CLOS, BITS32, POLY, Int))(x_2148->Code))(x_2148,
                                                              (BITS32)0,
                                                              (POLY)a_2051,
                                                              a_2052);
}
static Bool f_2156 (T_2097 this_2152,
                    MouseEventType_CTCommon a_2055,
                    Int a_2056) {
    CLOS x_2155;
    x_2155 = this_2152->doNothing_22;
    return ((Bool(*)(CLOS, BITS32, POLY, Int))(x_2155->Code))(x_2155,
                                                              (BITS32)0,
                                                              (POLY)a_2055,
                                                              a_2056);
}
static TUP0 f_2166 (T_2096 this_2132) {
    Ref self_27;
    self_27 = (Ref)LOCK((OID)this_2132->self_3);
    App_CTCommon x_2133;
    x_2133 = this_2132->a_2071;
    TUP0 d_39;
    d_39 = x_2133->showWindow_CTCommon(x_2133, this_2132->w1_7, 0);
    App_CTCommon x_2134;
    x_2134 = this_2132->a_2071;
    TUP0 d_40;
    d_40 = x_2134->setEnv_CTCommon(x_2134, this_2132->env_5, 0);
    Button_CTButton tabButton_28;
    tabButton_28 = mkCocoaButton_CTButton((BITS32)0,
                                          (POLY)this_2132->env_5,
                                          0);
    Msg d_41;
    d_41 = tabButton_28->setTitle_CTButton(tabButton_28,
                                           getStr("Tab (nofocus)"),
                                           Inherit,
                                           Inherit);
    Position_CTCommon x_2135;
    NEW (Position_CTCommon, x_2135, WORDS(sizeof(struct Position_CTCommon)));
    x_2135->GCINFO = __GC__Position_CTCommon;
    x_2135->x_CTCommon = 20;
    x_2135->y_CTCommon = 200;
    HasPosition_CTCommon x_2136;
    x_2136 = c_392_CTButton(tabButton_28);
    TUP0 d_42;
    d_42 = x_2136->setPosition_CTCommon(x_2136, x_2135, 0);
    T_2097 x_2142;
    NEW (T_2097, x_2142, WORDS(sizeof(struct T_2097)));
    x_2142->GCINFO = __GC__T_2097;
    x_2142->Code = f_2141;
    x_2142->doNothing_22 = this_2132->doNothing_22;
    HandlesMouseEvents_CTCommon x_2143;
    x_2143 = tabButton_28->l_Button_CTButton_HandlesMouseEvents_CTCommon_CTButton;
    TUP0 d_45;
    d_45 = x_2143->installMouseListener_CTCommon(x_2143,
                                                 (CLOS)x_2142,
                                                 0);
    IsFocusable_CTCommon x_2144;
    x_2144 = tabButton_28->l_Button_CTButton_Component_CTCommon_CTButton->l_Component_CTCommon_AbstractComponent_CTCommon_CTCommon->l_AbstractComponent_CTCommon_IsFocusable_CTCommon_CTCommon;
    TUP0 d_46;
    d_46 = x_2144->setIsFocusable_CTCommon(x_2144, (Bool)0, 0);
    T_2097 x_2150;
    NEW (T_2097, x_2150, WORDS(sizeof(struct T_2097)));
    x_2150->GCINFO = __GC__T_2097;
    x_2150->Code = f_2149;
    x_2150->doNothing_22 = this_2132->doNothing_22;
    HandlesMouseEvents_CTCommon x_2151;
    x_2151 = this_2132->button_9->l_Button_CTButton_HandlesMouseEvents_CTCommon_CTButton;
    TUP0 d_47;
    d_47 = x_2151->installMouseListener_CTCommon(x_2151,
                                                 (CLOS)x_2150,
                                                 0);
    T_2097 x_2157;
    NEW (T_2097, x_2157, WORDS(sizeof(struct T_2097)));
    x_2157->GCINFO = __GC__T_2097;
    x_2157->Code = f_2156;
    x_2157->doNothing_22 = this_2132->doNothing_22;
    HandlesMouseEvents_CTCommon x_2158;
    x_2158 = this_2132->button2_10->l_Button_CTButton_HandlesMouseEvents_CTCommon_CTButton;
    TUP0 d_48;
    d_48 = x_2158->installMouseListener_CTCommon(x_2158,
                                                 (CLOS)x_2157,
                                                 0);
    ContainsComponents_CTCommon x_2159;
    x_2159 = this_2132->w1_7->l_CocoaWindow_CTCommon_ContainsComponents_CTCommon_CTCommon;
    TUP0 d_49;
    d_49 = x_2159->addComponent_CTCommon(x_2159,
                                         tabButton_28->l_Button_CTButton_Component_CTCommon_CTButton,
                                         0);
    Button_CTButton x_2160;
    x_2160 = this_2132->button_9;
    Msg d_50;
    d_50 = x_2160->setTitle_CTButton(x_2160,
                                     getStr("First"),
                                     Inherit,
                                     Inherit);
    Position_CTCommon x_2161;
    NEW (Position_CTCommon, x_2161, WORDS(sizeof(struct Position_CTCommon)));
    x_2161->GCINFO = __GC__Position_CTCommon;
    x_2161->x_CTCommon = 20;
    x_2161->y_CTCommon = 20;
    HasPosition_CTCommon x_2162;
    x_2162 = c_392_CTButton(this_2132->button_9);
    TUP0 d_51;
    d_51 = x_2162->setPosition_CTCommon(x_2162, x_2161, 0);
    Position_CTCommon x_2163;
    NEW (Position_CTCommon, x_2163, WORDS(sizeof(struct Position_CTCommon)));
    x_2163->GCINFO = __GC__Position_CTCommon;
    x_2163->x_CTCommon = 0;
    x_2163->y_CTCommon = 55;
    HasPosition_CTCommon x_2164;
    x_2164 = c_392_CTButton(this_2132->button2_10);
    TUP0 d_54;
    d_54 = x_2164->setPosition_CTCommon(x_2164, x_2163, 0);
    Button_CTButton x_2165;
    x_2165 = this_2132->button2_10;
    Msg d_57;
    d_57 = x_2165->setTitle_CTButton(x_2165,
                                     getStr("Second"),
                                     Inherit,
                                     Inherit);
    Msg d_58;
    d_58 = f_2089(self_27,
                  this_2132->doNothing_22,
                  this_2132->w1_7,
                  this_2132->env_5,
                  primTimePlus(Inherit, sec(7)),
                  Inherit);
    UNLOCK((OID)self_27);
    return (TUP0)0;
}
static Msg f_2167 (T_2095 this_2128,
                   App_CTCommon a_2071,
                   Time a_2072,
                   Time a_2073) {
    Msg x_2070;
    NEW (Msg, x_2070, WORDS(sizeof(struct T_2096)));
    ((T_2096)x_2070)->GCINFO = __GC__T_2096;
    ((T_2096)x_2070)->Code = f_2166;
    ((T_2096)x_2070)->a_2071 = a_2071;
    ((T_2096)x_2070)->doNothing_22 = this_2128->doNothing_22;
    ((T_2096)x_2070)->button2_10 = this_2128->button2_10;
    ((T_2096)x_2070)->button_9 = this_2128->button_9;
    ((T_2096)x_2070)->w1_7 = this_2128->w1_7;
    ((T_2096)x_2070)->env_5 = this_2128->env_5;
    ((T_2096)x_2070)->self_3 = this_2128->self_3;
    return (Msg)ASYNC(x_2070, a_2072, a_2073);
}
static Bool f_2180 (T_2101 this_2176,
                    KeyEventType_CTCommon a_2076,
                    Int a_2077) {
    CLOS x_2179;
    x_2179 = this_2176->tabStop_18;
    return ((Bool(*)(CLOS, BITS32, POLY, Int))(x_2179->Code))(x_2179,
                                                              (BITS32)0,
                                                              (POLY)a_2076,
                                                              a_2077);
}
static TUP0 f_2194 (T_2100 this_2171) {
    Ref self_32;
    self_32 = (Ref)LOCK((OID)this_2171->self_3);
    Size_CTCommon x_2172;
    NEW (Size_CTCommon, x_2172, WORDS(sizeof(struct Size_CTCommon)));
    x_2172->GCINFO = __GC__Size_CTCommon;
    x_2172->width_CTCommon = 108;
    x_2172->height_CTCommon = 17;
    HasSize_CTCommon x_2173;
    x_2173 = this_2171->button_9->l_Button_CTButton_Component_CTCommon_CTButton->l_Component_CTCommon_AbstractComponent_CTCommon_CTCommon->l_AbstractComponent_CTCommon_HasSize_CTCommon_CTCommon;
    TUP0 d_74;
    d_74 = x_2173->setSize_CTCommon(x_2173, x_2172, 0);
    AbstractComponent_CTCommon x_2174;
    x_2174 = this_2171->button2_10->l_Button_CTButton_Component_CTCommon_CTButton->l_Component_CTCommon_AbstractComponent_CTCommon_CTCommon;
    TUP0 d_77;
    d_77 = x_2174->setName_CTCommon(x_2174, getStr("Second"), 0);
    AbstractComponent_CTCommon x_2175;
    x_2175 = this_2171->button_9->l_Button_CTButton_Component_CTCommon_CTButton->l_Component_CTCommon_AbstractComponent_CTCommon_CTCommon;
    TUP0 d_78;
    d_78 = x_2175->setName_CTCommon(x_2175, getStr("First"), 0);
    T_2101 x_2181;
    NEW (T_2101, x_2181, WORDS(sizeof(struct T_2101)));
    x_2181->GCINFO = __GC__T_2101;
    x_2181->Code = f_2180;
    x_2181->tabStop_18 = this_2171->tabStop_18;
    HandlesKeyEvents_CTCommon x_2182;
    x_2182 = this_2171->button_9->l_Button_CTButton_HandlesKeyEvents_CTCommon_CTButton;
    TUP0 d_79;
    d_79 = x_2182->installKeyListener_CTCommon(x_2182,
                                               (CLOS)x_2181,
                                               0);
    AbstractComponent_CTCommon x_2183;
    x_2183 = this_2171->c2_8->l_Container_CTContainer_Component_CTCommon_CTContainer->l_Component_CTCommon_AbstractComponent_CTCommon_CTCommon;
    TUP0 d_80;
    d_80 = x_2183->setName_CTCommon(x_2183,
                                    getStr("greenContainer"),
                                    0);
    Size_CTCommon x_2184;
    NEW (Size_CTCommon, x_2184, WORDS(sizeof(struct Size_CTCommon)));
    x_2184->GCINFO = __GC__Size_CTCommon;
    x_2184->width_CTCommon = 180;
    x_2184->height_CTCommon = 140;
    HasSize_CTCommon x_2185;
    x_2185 = this_2171->c2_8->l_Container_CTContainer_Component_CTCommon_CTContainer->l_Component_CTCommon_AbstractComponent_CTCommon_CTCommon->l_AbstractComponent_CTCommon_HasSize_CTCommon_CTCommon;
    TUP0 d_81;
    d_81 = x_2185->setSize_CTCommon(x_2185, x_2184, 0);
    Position_CTCommon x_2186;
    NEW (Position_CTCommon, x_2186, WORDS(sizeof(struct Position_CTCommon)));
    x_2186->GCINFO = __GC__Position_CTCommon;
    x_2186->x_CTCommon = 0;
    x_2186->y_CTCommon = 0;
    HasPosition_CTCommon x_2187;
    x_2187 = c_560_CTContainer(this_2171->c2_8);
    TUP0 d_84;
    d_84 = x_2187->setPosition_CTCommon(x_2187, x_2186, 0);
    Color_CTCommon x_2188;
    NEW (Color_CTCommon, x_2188, WORDS(sizeof(struct Color_CTCommon)));
    x_2188->GCINFO = __GC__Color_CTCommon;
    x_2188->r_CTCommon = 0;
    x_2188->g_CTCommon = 255;
    x_2188->b_CTCommon = 0;
    HasBackgroundColor_CTCommon x_2189;
    x_2189 = this_2171->c2_8->l_Container_CTContainer_HasBackgroundColor_CTCommon_CTContainer;
    TUP0 d_87;
    d_87 = x_2189->setBackgroundColor_CTCommon(x_2189, x_2188, 0);
    ContainsComponents_CTCommon x_2190;
    x_2190 = this_2171->c2_8->l_Container_CTContainer_ContainsComponents_CTCommon_CTContainer;
    TUP0 d_91;
    d_91 = x_2190->addComponent_CTCommon(x_2190,
                                         this_2171->button_9->l_Button_CTButton_Component_CTCommon_CTButton,
                                         0);
    ContainsComponents_CTCommon x_2191;
    x_2191 = this_2171->c2_8->l_Container_CTContainer_ContainsComponents_CTCommon_CTContainer;
    TUP0 d_92;
    d_92 = x_2191->addComponent_CTCommon(x_2191,
                                         this_2171->button2_10->l_Button_CTButton_Component_CTCommon_CTButton,
                                         0);
    ContainsComponents_CTCommon x_2192;
    x_2192 = this_2171->w1_7->l_CocoaWindow_CTCommon_ContainsComponents_CTCommon_CTCommon;
    TUP0 d_93;
    d_93 = x_2192->addComponent_CTCommon(x_2192,
                                         this_2171->c2_8->l_Container_CTContainer_Component_CTCommon_CTContainer,
                                         0);
    Env_COCOA x_2193;
    x_2193 = this_2171->osx_6;
    TUP0 d_94;
    d_94 = x_2193->startApplication_COCOA(x_2193,
                                          this_2171->applicationDidFinishLaunching_25,
                                          0);
    UNLOCK((OID)self_32);
    return (TUP0)0;
}
static Msg f_2195 (T_2099 this_2168, Time a_2083, Time a_2084) {
    Msg x_2085;
    NEW (Msg, x_2085, WORDS(sizeof(struct T_2100)));
    ((T_2100)x_2085)->GCINFO = __GC__T_2100;
    ((T_2100)x_2085)->Code = f_2194;
    ((T_2100)x_2085)->applicationDidFinishLaunching_25 = this_2168->applicationDidFinishLaunching_25;
    ((T_2100)x_2085)->tabStop_18 = this_2168->tabStop_18;
    ((T_2100)x_2085)->button2_10 = this_2168->button2_10;
    ((T_2100)x_2085)->button_9 = this_2168->button_9;
    ((T_2100)x_2085)->c2_8 = this_2168->c2_8;
    ((T_2100)x_2085)->w1_7 = this_2168->w1_7;
    ((T_2100)x_2085)->osx_6 = this_2168->osx_6;
    ((T_2100)x_2085)->self_3 = this_2168->self_3;
    return (Msg)ASYNC(x_2085, a_2083, a_2084);
}
static Bool f_2201 (T_2097 this_2197,
                    MouseEventType_CTCommon a_2059,
                    Int a_2060) {
    CLOS x_2200;
    x_2200 = this_2197->doNothing_22;
    return ((Bool(*)(CLOS, BITS32, POLY, Int))(x_2200->Code))(x_2200,
                                                              (BITS32)0,
                                                              (POLY)a_2059,
                                                              a_2060);
}
static TUP0 f_2213 (T_2098 this_2196) {
    Ref self_29;
    self_29 = (Ref)LOCK((OID)this_2196->self_27);
    Button_CTButton button3_30;
    button3_30 = mkCocoaButton_CTButton((BITS32)0,
                                        (POLY)this_2196->env_5,
                                        0);
    Msg d_59;
    d_59 = button3_30->setTitle_CTButton(button3_30,
                                         getStr("Three?"),
                                         Inherit,
                                         Inherit);
    T_2097 x_2202;
    NEW (T_2097, x_2202, WORDS(sizeof(struct T_2097)));
    x_2202->GCINFO = __GC__T_2097;
    x_2202->Code = f_2201;
    x_2202->doNothing_22 = this_2196->doNothing_22;
    HandlesMouseEvents_CTCommon x_2203;
    x_2203 = button3_30->l_Button_CTButton_HandlesMouseEvents_CTCommon_CTButton;
    TUP0 d_60;
    d_60 = x_2203->installMouseListener_CTCommon(x_2203,
                                                 (CLOS)x_2202,
                                                 0);
    Container_CTContainer c3_31;
    c3_31 = mkContainer_CTContainer(this_2196->env_5, 0);
    ContainsComponents_CTCommon x_2204;
    x_2204 = c3_31->l_Container_CTContainer_ContainsComponents_CTCommon_CTContainer;
    TUP0 d_61;
    d_61 = x_2204->addComponent_CTCommon(x_2204,
                                         button3_30->l_Button_CTButton_Component_CTCommon_CTButton,
                                         0);
    Size_CTCommon x_2205;
    NEW (Size_CTCommon, x_2205, WORDS(sizeof(struct Size_CTCommon)));
    x_2205->GCINFO = __GC__Size_CTCommon;
    x_2205->width_CTCommon = 180;
    x_2205->height_CTCommon = 50;
    HasSize_CTCommon x_2206;
    x_2206 = c3_31->l_Container_CTContainer_Component_CTCommon_CTContainer->l_Component_CTCommon_AbstractComponent_CTCommon_CTCommon->l_AbstractComponent_CTCommon_HasSize_CTCommon_CTCommon;
    TUP0 d_62;
    d_62 = x_2206->setSize_CTCommon(x_2206, x_2205, 0);
    AbstractComponent_CTCommon x_2207;
    x_2207 = c3_31->l_Container_CTContainer_Component_CTCommon_CTContainer->l_Component_CTCommon_AbstractComponent_CTCommon_CTCommon;
    TUP0 d_65;
    d_65 = x_2207->setName_CTCommon(x_2207, getStr("Container:C3"), 0);
    Position_CTCommon x_2208;
    NEW (Position_CTCommon, x_2208, WORDS(sizeof(struct Position_CTCommon)));
    x_2208->GCINFO = __GC__Position_CTCommon;
    x_2208->x_CTCommon = 0;
    x_2208->y_CTCommon = 100;
    HasPosition_CTCommon x_2209;
    x_2209 = c_560_CTContainer(c3_31);
    TUP0 d_66;
    d_66 = x_2209->setPosition_CTCommon(x_2209, x_2208, 0);
    Color_CTCommon x_2210;
    NEW (Color_CTCommon, x_2210, WORDS(sizeof(struct Color_CTCommon)));
    x_2210->GCINFO = __GC__Color_CTCommon;
    x_2210->r_CTCommon = 240;
    x_2210->g_CTCommon = 66;
    x_2210->b_CTCommon = 33;
    HasBackgroundColor_CTCommon x_2211;
    x_2211 = c3_31->l_Container_CTContainer_HasBackgroundColor_CTCommon_CTContainer;
    TUP0 d_69;
    d_69 = x_2211->setBackgroundColor_CTCommon(x_2211, x_2210, 0);
    ContainsComponents_CTCommon x_2212;
    x_2212 = this_2196->w1_7->l_CocoaWindow_CTCommon_ContainsComponents_CTCommon_CTCommon;
    TUP0 d_73;
    d_73 = x_2212->addComponent_CTCommon(x_2212,
                                         c3_31->l_Container_CTContainer_Component_CTCommon_CTContainer,
                                         0);
    UNLOCK((OID)self_29);
    return (TUP0)0;
}
static TUP0 f_2216 (T_2092 this_2214) {
    Ref self_21;
    self_21 = (Ref)LOCK((OID)this_2214->self_20);
    Button_CTButton x_2215;
    x_2215 = this_2214->button_9;
    Msg d_36;
    d_36 = x_2215->setTitle_CTButton(x_2215,
                                     _sym_20_Prelude/* ++ */((BITS32)1,
                                                             getStr("Consume: "),
                                                             show_729_Prelude(not_Prelude(((S_574)STATEOF(self_21))->block_4))),
                                     Inherit,
                                     Inherit);
    UNLOCK((OID)self_21);
    return (TUP0)0;
}
 
void _init_FocusTest () {
    static int INITIALIZED = 0;
    if (!INITIALIZED) {
        _init_Prelude();
        _init_POSIX();
        _init_COCOA();
        INITIALIZED = 1;
    }
}
 

