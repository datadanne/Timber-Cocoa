#include "Paint.h"
 
struct S_346;
typedef struct S_346 *S_346;
struct T_1243;
typedef struct T_1243 *T_1243;
struct T_1242;
typedef struct T_1242 *T_1242;
struct T_1241;
typedef struct T_1241 *T_1241;
struct T_1240;
typedef struct T_1240 *T_1240;
struct T_1239;
typedef struct T_1239 *T_1239;
struct T_1238;
typedef struct T_1238 *T_1238;
struct T_1237;
typedef struct T_1237 *T_1237;
 
struct S_346 {
    POLY GCINFO;
    Int pixelCount_4;
};
struct T_1243 {
    POLY GCINFO;
    Bool (*Code) (T_1243, MouseEventType_CTCommon, Int);
    CLOS drawPixel_16;
    Container_CTContainer c2_8;
};
struct T_1242 {
    POLY GCINFO;
    TUP0 (*Code) (T_1242);
    AbsTime baseline;
    AbsTime deadline;
    Msg next;
    CLOS applicationDidFinishLaunching_23;
    CLOS drawPixel_16;
    Label_CTLabel label_11;
    Container_CTContainer c2_8;
    CocoaWindow_CTCommon w1_7;
    Env_COCOA osx_6;
    Ref self_3;
};
struct T_1241 {
    POLY GCINFO;
    Msg (*Code) (T_1241, Time, Time);
    CLOS applicationDidFinishLaunching_23;
    CLOS drawPixel_16;
    Label_CTLabel label_11;
    Container_CTContainer c2_8;
    CocoaWindow_CTCommon w1_7;
    Env_COCOA osx_6;
    Ref self_3;
};
struct T_1240 {
    POLY GCINFO;
    TUP0 (*Code) (T_1240);
    AbsTime baseline;
    AbsTime deadline;
    Msg next;
    App_CTCommon a_1220;
    CocoaWindow_CTCommon w1_7;
    Env_POSIX env_5;
    Ref self_3;
};
struct T_1239 {
    POLY GCINFO;
    Msg (*Code) (T_1239, App_CTCommon, Time, Time);
    CocoaWindow_CTCommon w1_7;
    Env_POSIX env_5;
    Ref self_3;
};
struct T_1238 {
    POLY GCINFO;
    TUP0 (*Code) (T_1238);
    AbsTime baseline;
    AbsTime deadline;
    Msg next;
    Container_CTContainer blackBox_20;
    Ref self_19;
    CocoaWindow_CTCommon w1_7;
};
struct T_1237 {
    POLY GCINFO;
    Bool (*Code) (T_1237, BITS32, POLY, MouseEventType_CTCommon, Int);
    Label_CTLabel label_11;
    CocoaWindow_CTCommon w1_7;
    Env_POSIX env_5;
    Ref self_3;
};
 
static WORD __GC__S_346[];
static WORD __GC__T_1243[];
static WORD __GC__T_1242[];
static WORD __GC__T_1241[];
static WORD __GC__T_1240[];
static WORD __GC__T_1239[];
static WORD __GC__T_1238[];
static WORD __GC__T_1237[];
static Msg f_1236 (Container_CTContainer blackBox_20,
                   Ref self_19,
                   CocoaWindow_CTCommon w1_7,
                   Time a_1207,
                   Time a_1208);
static Position_CTCommon posget_12 (MouseEventType_CTCommon a_27);
static Bool f_1256 (T_1237 this_1245,
                    BITS32 a_1249,
                    POLY a_1212,
                    MouseEventType_CTCommon a_1213,
                    Int a_1214);
static TUP0 f_1264 (T_1240 this_1261);
static Msg f_1265 (T_1239 this_1257,
                   App_CTCommon a_1220,
                   Time a_1221,
                   Time a_1222);
static Bool f_1280 (T_1243 this_1276,
                    MouseEventType_CTCommon a_1224,
                    Int a_1225);
static TUP0 f_1284 (T_1242 this_1269);
static Msg f_1285 (T_1241 this_1266, Time a_1231, Time a_1232);
static TUP0 f_1288 (T_1238 this_1286);
 
static WORD __GC__S_346[] = {WORDS(sizeof(struct S_346)), 0, 0};
static WORD __GC__T_1243[] = {WORDS(sizeof(struct T_1243)),
                              0,
                              WORDS(offsetof(struct T_1243, drawPixel_16)),
                              WORDS(offsetof(struct T_1243, c2_8)),
                              0};
static WORD __GC__T_1242[] = {WORDS(sizeof(struct T_1242)),
                              0,
                              WORDS(offsetof(struct T_1242, applicationDidFinishLaunching_23)),
                              WORDS(offsetof(struct T_1242, drawPixel_16)),
                              WORDS(offsetof(struct T_1242, label_11)),
                              WORDS(offsetof(struct T_1242, c2_8)),
                              WORDS(offsetof(struct T_1242, w1_7)),
                              WORDS(offsetof(struct T_1242, osx_6)),
                              WORDS(offsetof(struct T_1242, self_3)),
                              0};
static WORD __GC__T_1241[] = {WORDS(sizeof(struct T_1241)),
                              0,
                              WORDS(offsetof(struct T_1241, applicationDidFinishLaunching_23)),
                              WORDS(offsetof(struct T_1241, drawPixel_16)),
                              WORDS(offsetof(struct T_1241, label_11)),
                              WORDS(offsetof(struct T_1241, c2_8)),
                              WORDS(offsetof(struct T_1241, w1_7)),
                              WORDS(offsetof(struct T_1241, osx_6)),
                              WORDS(offsetof(struct T_1241, self_3)),
                              0};
static WORD __GC__T_1240[] = {WORDS(sizeof(struct T_1240)),
                              0,
                              WORDS(offsetof(struct T_1240, a_1220)),
                              WORDS(offsetof(struct T_1240, w1_7)),
                              WORDS(offsetof(struct T_1240, env_5)),
                              WORDS(offsetof(struct T_1240, self_3)),
                              0};
static WORD __GC__T_1239[] = {WORDS(sizeof(struct T_1239)),
                              0,
                              WORDS(offsetof(struct T_1239, w1_7)),
                              WORDS(offsetof(struct T_1239, env_5)),
                              WORDS(offsetof(struct T_1239, self_3)),
                              0};
static WORD __GC__T_1238[] = {WORDS(sizeof(struct T_1238)),
                              0,
                              WORDS(offsetof(struct T_1238, blackBox_20)),
                              WORDS(offsetof(struct T_1238, self_19)),
                              WORDS(offsetof(struct T_1238, w1_7)),
                              0};
static WORD __GC__T_1237[] = {WORDS(sizeof(struct T_1237)),
                              0,
                              WORDS(offsetof(struct T_1237, label_11)),
                              WORDS(offsetof(struct T_1237, w1_7)),
                              WORDS(offsetof(struct T_1237, env_5)),
                              WORDS(offsetof(struct T_1237, self_3)),
                              0};
CLOS root_Paint (World w_2, Int d_1235) {
    Ref self_3;
    NEW (Ref, self_3, WORDS(sizeof(struct Ref))+
                      WORDS(sizeof(struct S_346)));
    INITREF(self_3);
    ((S_346)STATEOF(self_3))->GCINFO = __GC__S_346;
    Env_POSIX env_5;
    env_5 = posix_POSIX(w_2, 0);
    Env_COCOA osx_6;
    osx_6 = cocoa_COCOA(w_2, 0);
    CocoaWindow_CTCommon w1_7;
    w1_7 = mkWindow_CTWindow((BITS32)0, (POLY)env_5, 0);
    Container_CTContainer c2_8;
    c2_8 = mkContainer_CTContainer((BITS32)0, (POLY)env_5, 0);
    Button_CTButton button_9;
    button_9 = mkCocoaButton_CTButton(env_5, 0);
    Button_CTButton button2_10;
    button2_10 = mkCocoaButton_CTButton(env_5, 0);
    Label_CTLabel label_11;
    label_11 = mkCocoaLabel_CTLabel(0);
    CLOS drawPixel_16;
    NEW (CLOS, drawPixel_16, WORDS(sizeof(struct T_1237)));
    ((T_1237)drawPixel_16)->GCINFO = __GC__T_1237;
    ((T_1237)drawPixel_16)->Code = f_1256;
    ((T_1237)drawPixel_16)->label_11 = label_11;
    ((T_1237)drawPixel_16)->w1_7 = w1_7;
    ((T_1237)drawPixel_16)->env_5 = env_5;
    ((T_1237)drawPixel_16)->self_3 = self_3;
    CLOS applicationDidFinishLaunching_23;
    NEW (CLOS, applicationDidFinishLaunching_23, WORDS(sizeof(struct T_1239)));
    ((T_1239)applicationDidFinishLaunching_23)->GCINFO = __GC__T_1239;
    ((T_1239)applicationDidFinishLaunching_23)->Code = f_1265;
    ((T_1239)applicationDidFinishLaunching_23)->w1_7 = w1_7;
    ((T_1239)applicationDidFinishLaunching_23)->env_5 = env_5;
    ((T_1239)applicationDidFinishLaunching_23)->self_3 = self_3;
    ((S_346)STATEOF(self_3))->pixelCount_4 = 0;
    CLOS x_1234;
    NEW (CLOS, x_1234, WORDS(sizeof(struct T_1241)));
    ((T_1241)x_1234)->GCINFO = __GC__T_1241;
    ((T_1241)x_1234)->Code = f_1285;
    ((T_1241)x_1234)->applicationDidFinishLaunching_23 = applicationDidFinishLaunching_23;
    ((T_1241)x_1234)->drawPixel_16 = drawPixel_16;
    ((T_1241)x_1234)->label_11 = label_11;
    ((T_1241)x_1234)->c2_8 = c2_8;
    ((T_1241)x_1234)->w1_7 = w1_7;
    ((T_1241)x_1234)->osx_6 = osx_6;
    ((T_1241)x_1234)->self_3 = self_3;
    return x_1234;
}
static Msg f_1236 (Container_CTContainer blackBox_20,
                   Ref self_19,
                   CocoaWindow_CTCommon w1_7,
                   Time a_1207,
                   Time a_1208) {
    Msg x_1209;
    NEW (Msg, x_1209, WORDS(sizeof(struct T_1238)));
    ((T_1238)x_1209)->GCINFO = __GC__T_1238;
    ((T_1238)x_1209)->Code = f_1288;
    ((T_1238)x_1209)->blackBox_20 = blackBox_20;
    ((T_1238)x_1209)->self_19 = self_19;
    ((T_1238)x_1209)->w1_7 = w1_7;
    return (Msg)ASYNC(x_1209, a_1207, a_1208);
}
static Position_CTCommon posget_12 (MouseEventType_CTCommon a_27) {
    switch (a_27->Tag) {
        case 2: { Position_CTCommon x_28;
                  x_28 = ((_MousePressed_CTCommon)a_27)->a;
                  return x_28;
                }
                break;
        case 1: { Position_CTCommon x_29;
                  x_29 = ((_MouseReleased_CTCommon)a_27)->a;
                  return x_29;
                }
                break;
        case 3: { Position_CTCommon x_30;
                  x_30 = ((_MouseClicked_CTCommon)a_27)->a;
                  return x_30;
                }
                break;
        default: RAISE(1);
    }
}
static Bool f_1256 (T_1237 this_1245,
                    BITS32 a_1249,
                    POLY a_1212,
                    MouseEventType_CTCommon a_1213,
                    Int a_1214) {
    Ref self_19;
    self_19 = (Ref)LOCK((OID)this_1245->self_3);
    Container_CTContainer blackBox_20;
    blackBox_20 = mkContainer_CTContainer((BITS32)0,
                                          (POLY)this_1245->env_5,
                                          0);
    Size_CTCommon x_1250;
    NEW (Size_CTCommon, x_1250, WORDS(sizeof(struct Size_CTCommon)));
    x_1250->GCINFO = __GC__Size_CTCommon;
    x_1250->width_CTCommon = 5;
    x_1250->height_CTCommon = 5;
    HasSize_CTCommon x_1251;
    x_1251 = blackBox_20->l_Container_CTContainer_Component_CTCommon_CTContainer->l_Component_CTCommon_HasSize_CTCommon_CTCommon;
    Msg d_31;
    d_31 = x_1251->setSize_CTCommon(x_1251, x_1250, Inherit, Inherit);
    Label_CTLabel x_1252;
    x_1252 = this_1245->label_11;
    Msg d_34;
    d_34 = x_1252->setText_CTLabel(x_1252,
                                   _sym_20_Prelude/* ++ */((BITS32)1,
                                                           getStr("Pixel Count: "),
                                                           show_723_Prelude(((S_346)STATEOF(self_19))->pixelCount_4)),
                                   Inherit,
                                   Inherit);
    Position_CTCommon pos_21;
    pos_21 = posget_12(a_1213);
    Color_CTCommon x_1253;
    NEW (Color_CTCommon, x_1253, WORDS(sizeof(struct Color_CTCommon)));
    x_1253->GCINFO = __GC__Color_CTCommon;
    x_1253->r_CTCommon = (pos_21->x_CTCommon % 255);
    x_1253->g_CTCommon = (pos_21->y_CTCommon % 255);
    x_1253->b_CTCommon = ((2 * ((pos_21->y_CTCommon - pos_21->x_CTCommon))) % 255);
    HasBackgroundColor_CTCommon x_1254;
    x_1254 = blackBox_20->l_Container_CTContainer_HasBackgroundColor_CTCommon_CTContainer;
    Msg d_35;
    d_35 = x_1254->setBackgroundColor_CTCommon(x_1254,
                                               x_1253,
                                               Inherit,
                                               Inherit);
    HasPosition_CTCommon x_1255;
    x_1255 = blackBox_20->l_Container_CTContainer_Component_CTCommon_CTContainer->l_Component_CTCommon_HasSize_CTCommon_CTCommon->l_HasSize_CTCommon_HasPosition_CTCommon_CTCommon;
    Msg d_39;
    d_39 = x_1255->setPosition_CTCommon(x_1255,
                                        pos_21,
                                        Inherit,
                                        Inherit);
    ((S_346)STATEOF(self_19))->pixelCount_4 = _sym_620_Prelude/* + */(1,
                                                                      ((S_346)STATEOF(self_19))->pixelCount_4);
    Msg d_40;
    d_40 = f_1236(blackBox_20,
                  self_19,
                  this_1245->w1_7,
                  primTimePlus(Inherit, millisec(100)),
                  Inherit);
    UNLOCK((OID)self_19);
    return (Bool)1;
}
static TUP0 f_1264 (T_1240 this_1261) {
    Ref self_25;
    self_25 = (Ref)LOCK((OID)this_1261->self_3);
    App_CTCommon x_1262;
    x_1262 = this_1261->a_1220;
    TUP0 d_42;
    d_42 = x_1262->setEnv_CTCommon(x_1262, this_1261->env_5, 0);
    App_CTCommon x_1263;
    x_1263 = this_1261->a_1220;
    TUP0 d_43;
    d_43 = x_1263->showWindow_CTCommon(x_1263, this_1261->w1_7, 0);
    UNLOCK((OID)self_25);
    return (TUP0)0;
}
static Msg f_1265 (T_1239 this_1257,
                   App_CTCommon a_1220,
                   Time a_1221,
                   Time a_1222) {
    Msg x_1219;
    NEW (Msg, x_1219, WORDS(sizeof(struct T_1240)));
    ((T_1240)x_1219)->GCINFO = __GC__T_1240;
    ((T_1240)x_1219)->Code = f_1264;
    ((T_1240)x_1219)->a_1220 = a_1220;
    ((T_1240)x_1219)->w1_7 = this_1257->w1_7;
    ((T_1240)x_1219)->env_5 = this_1257->env_5;
    ((T_1240)x_1219)->self_3 = this_1257->self_3;
    return (Msg)ASYNC(x_1219, a_1221, a_1222);
}
static Bool f_1280 (T_1243 this_1276,
                    MouseEventType_CTCommon a_1224,
                    Int a_1225) {
    CLOS x_1279;
    x_1279 = this_1276->drawPixel_16;
    return ((Bool(*)(CLOS, BITS32, POLY, MouseEventType_CTCommon, Int))(x_1279->Code))(x_1279,
                                                                                       (BITS32)0,
                                                                                       (POLY)this_1276->c2_8,
                                                                                       a_1224,
                                                                                       a_1225);
}
static TUP0 f_1284 (T_1242 this_1269) {
    Ref self_26;
    self_26 = (Ref)LOCK((OID)this_1269->self_3);
    Size_CTCommon x_1270;
    NEW (Size_CTCommon, x_1270, WORDS(sizeof(struct Size_CTCommon)));
    x_1270->GCINFO = __GC__Size_CTCommon;
    x_1270->width_CTCommon = 300;
    x_1270->height_CTCommon = 50;
    HasSize_CTCommon x_1271;
    x_1271 = this_1269->label_11->l_Label_CTLabel_Component_CTCommon_CTLabel->l_Component_CTCommon_HasSize_CTCommon_CTCommon;
    Msg d_44;
    d_44 = x_1271->setSize_CTCommon(x_1271, x_1270, Inherit, Inherit);
    Position_CTCommon x_1272;
    NEW (Position_CTCommon, x_1272, WORDS(sizeof(struct Position_CTCommon)));
    x_1272->GCINFO = __GC__Position_CTCommon;
    x_1272->x_CTCommon = 50;
    x_1272->y_CTCommon = 200;
    HasPosition_CTCommon x_1273;
    x_1273 = this_1269->label_11->l_Label_CTLabel_Component_CTCommon_CTLabel->l_Component_CTCommon_HasSize_CTCommon_CTCommon->l_HasSize_CTCommon_HasPosition_CTCommon_CTCommon;
    Msg d_47;
    d_47 = x_1273->setPosition_CTCommon(x_1273,
                                        x_1272,
                                        Inherit,
                                        Inherit);
    Label_CTLabel x_1274;
    x_1274 = this_1269->label_11;
    Msg d_50;
    d_50 = x_1274->setText_CTLabel(x_1274,
                                   getStr("PainTimber. Paint slowly or I will segfault. :("),
                                   Inherit,
                                   Inherit);
    ContainsComponents_CTCommon x_1275;
    x_1275 = this_1269->w1_7->l_CocoaWindow_CTCommon_ContainsComponents_CTCommon_CTCommon;
    TUP0 d_51;
    d_51 = x_1275->addComponent_CTCommon(x_1275,
                                         this_1269->label_11->l_Label_CTLabel_Component_CTCommon_CTLabel,
                                         0);
    T_1243 x_1281;
    NEW (T_1243, x_1281, WORDS(sizeof(struct T_1243)));
    x_1281->GCINFO = __GC__T_1243;
    x_1281->Code = f_1280;
    x_1281->drawPixel_16 = this_1269->drawPixel_16;
    x_1281->c2_8 = this_1269->c2_8;
    HandlesMouseEvents_CTCommon x_1282;
    x_1282 = this_1269->w1_7->l_CocoaWindow_CTCommon_HandlesMouseEvents_CTCommon_CTCommon;
    TUP0 d_52;
    d_52 = x_1282->installMouseListener_CTCommon(x_1282,
                                                 (CLOS)x_1281,
                                                 0);
    Env_COCOA x_1283;
    x_1283 = this_1269->osx_6;
    TUP0 d_53;
    d_53 = x_1283->startApplication_COCOA(x_1283,
                                          this_1269->applicationDidFinishLaunching_23,
                                          0);
    UNLOCK((OID)self_26);
    return (TUP0)0;
}
static Msg f_1285 (T_1241 this_1266, Time a_1231, Time a_1232) {
    Msg x_1233;
    NEW (Msg, x_1233, WORDS(sizeof(struct T_1242)));
    ((T_1242)x_1233)->GCINFO = __GC__T_1242;
    ((T_1242)x_1233)->Code = f_1284;
    ((T_1242)x_1233)->applicationDidFinishLaunching_23 = this_1266->applicationDidFinishLaunching_23;
    ((T_1242)x_1233)->drawPixel_16 = this_1266->drawPixel_16;
    ((T_1242)x_1233)->label_11 = this_1266->label_11;
    ((T_1242)x_1233)->c2_8 = this_1266->c2_8;
    ((T_1242)x_1233)->w1_7 = this_1266->w1_7;
    ((T_1242)x_1233)->osx_6 = this_1266->osx_6;
    ((T_1242)x_1233)->self_3 = this_1266->self_3;
    return (Msg)ASYNC(x_1233, a_1231, a_1232);
}
static TUP0 f_1288 (T_1238 this_1286) {
    Ref self_22;
    self_22 = (Ref)LOCK((OID)this_1286->self_19);
    ContainsComponents_CTCommon x_1287;
    x_1287 = this_1286->w1_7->l_CocoaWindow_CTCommon_ContainsComponents_CTCommon_CTCommon;
    TUP0 d_41;
    d_41 = x_1287->addComponent_CTCommon(x_1287,
                                         this_1286->blackBox_20->l_Container_CTContainer_Component_CTCommon_CTContainer,
                                         0);
    UNLOCK((OID)self_22);
    return (TUP0)0;
}
 
void _init_Paint () {
    static int INITIALIZED = 0;
    if (!INITIALIZED) {
        _init_Prelude();
        _init_POSIX();
        _init_COCOA();
        _init_CTLabel();
        INITIALIZED = 1;
    }
}
 

