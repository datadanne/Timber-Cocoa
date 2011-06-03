#include "CTContainer.h"
#include "CTContainer.extern.c"
 
struct S_816;
typedef struct S_816 *S_816;
struct T_4261;
typedef struct T_4261 *T_4261;
struct T_4260;
typedef struct T_4260 *T_4260;
struct T_4259;
typedef struct T_4259 *T_4259;
struct T_4258;
typedef struct T_4258 *T_4258;
struct T_4257;
typedef struct T_4257 *T_4257;
struct T_4256;
typedef struct T_4256 *T_4256;
struct T_4255;
typedef struct T_4255 *T_4255;
struct T_4254;
typedef struct T_4254 *T_4254;
struct T_4253;
typedef struct T_4253 *T_4253;
struct T_4252;
typedef struct T_4252 *T_4252;
struct T_4251;
typedef struct T_4251 *T_4251;
struct T_4250;
typedef struct T_4250 *T_4250;
struct T_4249;
typedef struct T_4249 *T_4249;
struct T_4248;
typedef struct T_4248 *T_4248;
struct T_4247;
typedef struct T_4247 *T_4247;
struct T_4246;
typedef struct T_4246 *T_4246;
struct T_4245;
typedef struct T_4245 *T_4245;
struct T_4244;
typedef struct T_4244 *T_4244;
struct T_4243;
typedef struct T_4243 *T_4243;
struct T_4242;
typedef struct T_4242 *T_4242;
struct T_4241;
typedef struct T_4241 *T_4241;
struct T_4240;
typedef struct T_4240 *T_4240;
struct T_4239;
typedef struct T_4239 *T_4239;
struct T_4238;
typedef struct T_4238 *T_4238;
struct T_4237;
typedef struct T_4237 *T_4237;
struct T_4236;
typedef struct T_4236 *T_4236;
struct T_4235;
typedef struct T_4235 *T_4235;
struct T_4234;
typedef struct T_4234 *T_4234;
struct T_4233;
typedef struct T_4233 *T_4233;
struct T_4232;
typedef struct T_4232 *T_4232;
struct T_4231;
typedef struct T_4231 *T_4231;
struct T_4230;
typedef struct T_4230 *T_4230;
struct T_4229;
typedef struct T_4229 *T_4229;
struct T_4228;
typedef struct T_4228 *T_4228;
struct T_4227;
typedef struct T_4227 *T_4227;
struct T_4226;
typedef struct T_4226 *T_4226;
struct T_4225;
typedef struct T_4225 *T_4225;
struct T_4224;
typedef struct T_4224 *T_4224;
struct T_4223;
typedef struct T_4223 *T_4223;
struct T_4222;
typedef struct T_4222 *T_4222;
 
struct S_816 {
    POLY GCINFO;
    CocoaState_CTCommon myState_11;
    LIST myComponents_12;
    Position_CTCommon position_13;
    Size_CTCommon size_14;
    Color_CTCommon color_15;
    Maybe_Prelude keyEventHandler_16;
    Maybe_Prelude appRef_17;
    Maybe_Prelude mouseEventHandler_18;
    Maybe_Prelude currentEventHasBeenConsumedBy_19;
    Maybe_Prelude nextFocusTarget_20;
    LIST name_21;
};
struct T_4261 {
    POLY GCINFO;
    Maybe_Prelude (*Code) (T_4261, BITS32, POLY, POLY, Int);
    Ref self_10;
};
struct T_4260 {
    POLY GCINFO;
    Msg (*setBackgroundColor_CTCommon) (T_4260,
                                        Color_CTCommon,
                                        Time,
                                        Time);
    Color_CTCommon (*getBackgroundColor_CTCommon) (T_4260, Int);
    CLOS x_4210;
    CLOS x_4212;
};
struct T_4259 {
    POLY GCINFO;
    TUP0 (*installKeyListener_CTCommon) (T_4259, CLOS, Int);
    CLOS x_4207;
};
struct T_4258 {
    POLY GCINFO;
    TUP0 (*installMouseListener_CTCommon) (T_4258, CLOS, Int);
    CLOS x_4204;
};
struct T_4257 {
    POLY GCINFO;
    TUP0 (*addComponent_CTCommon) (T_4257, Component_CTCommon, Int);
    LIST (*getComponents_CTCommon) (T_4257, Int);
    CLOS x_4199;
    CLOS x_4202;
};
struct T_4256 {
    POLY GCINFO;
    Maybe_Prelude (*handleEvent_CTCommon) (T_4256,
                                           CocoaEvent_CTCommon,
                                           LIST,
                                           Int);
    CLOS x_4185;
};
struct T_4255 {
    POLY GCINFO;
    Msg (*setPosition_CTCommon) (T_4255,
                                 Position_CTCommon,
                                 Time,
                                 Time);
    Position_CTCommon (*getPosition_CTCommon) (T_4255, Int);
    CLOS x_4173;
    CLOS x_4175;
};
struct T_4254 {
    POLY GCINFO;
    HasPosition_CTCommon l_HasSize_CTCommon_HasPosition_CTCommon_CTCommon;
    Msg (*setSize_CTCommon) (T_4254, Size_CTCommon, Time, Time);
    Size_CTCommon (*getSize_CTCommon) (T_4254, Int);
    CLOS x_4179;
    CLOS x_4181;
};
struct T_4253 {
    POLY GCINFO;
    TUP0 (*setNextFocusTarget_CTCommon) (T_4253, Maybe_Prelude, Int);
    Maybe_Prelude (*getNextFocusTarget_CTCommon) (T_4253, Int);
    TUP0 (*setPreviousFocusTarget_CTCommon) (T_4253,
                                             Maybe_Prelude,
                                             Int);
    Maybe_Prelude (*getPreviousFocusTarget_CTCommon) (T_4253, Int);
    TUP0 (*setIsFocusable_CTCommon) (T_4253, Bool, Int);
    Bool (*getIsFocusable_CTCommon) (T_4253, Int);
    CLOS x_4158;
    CLOS x_4160;
    CLOS x_4162;
    CLOS x_4164;
    CLOS x_4167;
    CLOS x_4170;
};
struct T_4252 {
    POLY GCINFO;
    IsFocusable_CTCommon l_Component_CTCommon_IsFocusable_CTCommon_CTCommon;
    HasSize_CTCommon l_Component_CTCommon_HasSize_CTCommon_CTCommon;
    HandlesEvents_CTCommon l_Component_CTCommon_HandlesEvents_CTCommon_CTCommon;
    CocoaID_CTCommon id_CTCommon;
    TUP0 (*init_CTCommon) (T_4252, App_CTCommon, Int);
    TUP0 (*destroy_CTCommon) (T_4252, Int);
    TUP0 (*setName_CTCommon) (T_4252, LIST, Int);
    LIST (*getName_CTCommon) (T_4252, Int);
    CLOS x_4189;
    CLOS x_4191;
    CLOS x_4193;
    CLOS x_4196;
};
struct T_4251 {
    POLY GCINFO;
    TUP0 (*Code) (T_4251, Component_CTCommon, Ref);
    App_CTCommon a_4156;
    CocoaID_CTCommon id_22;
};
struct T_4250 {
    POLY GCINFO;
    TUP0 (*Code) (T_4250, App_CTCommon, Int);
    Container_CTContainer this_86;
    CocoaID_CTCommon id_22;
    Ref self_10;
};
struct T_4249 {
    POLY GCINFO;
    TUP0 (*Code) (T_4249, Component_CTCommon, Ref);
    MouseEventType_CTCommon eventInNewCoordsystem_105;
    Position_CTCommon pos2_104;
    LIST a_4150;
};
struct T_4248 {
    POLY GCINFO;
    Maybe_Prelude (*Code) (T_4248, MouseEventType_CTCommon, LIST, Ref);
    Container_CTContainer this_86;
};
struct T_4247 {
    POLY GCINFO;
    Maybe_Prelude (*Code) (T_4247, CocoaEvent_CTCommon, LIST, Int);
    CLOS mouseEventDispatcher_84;
    Ref self_10;
};
struct T_4246 {
    POLY GCINFO;
    TUP0 (*Code) (T_4246, Ref);
    Component_CTCommon a_4138;
    IsFocusable_CTCommon focus_77;
};
struct T_4245 {
    POLY GCINFO;
    TUP0 (*Code) (T_4245, Ref);
    Component_CTCommon a_4138;
};
struct T_4244 {
    POLY GCINFO;
    CLOS (*Code) (T_4244);
    Ref self_88;
    Component_CTCommon a_4138;
    IsFocusable_CTCommon focus_77;
};
struct T_4243 {
    POLY GCINFO;
    TUP0 (*Code) (T_4243, Component_CTCommon, Int);
    IsFocusable_CTCommon focus_77;
    CocoaID_CTCommon id_22;
    Ref self_10;
};
struct T_4242 {
    POLY GCINFO;
    Bool (*Code) (T_4242, Int);
    IsFocusable_CTCommon focus_77;
};
struct T_4241 {
    POLY GCINFO;
    TUP0 (*Code) (T_4241, Bool, Int);
    IsFocusable_CTCommon focus_77;
};
struct T_4240 {
    POLY GCINFO;
    Maybe_Prelude (*Code) (T_4240, Int);
    IsFocusable_CTCommon focus_77;
};
struct T_4239 {
    POLY GCINFO;
    TUP0 (*Code) (T_4239, Maybe_Prelude, Int);
    IsFocusable_CTCommon focus_77;
};
struct T_4238 {
    POLY GCINFO;
    TUP0 (*Code) (T_4238, Maybe_Prelude, Int);
    Ref self_10;
};
struct T_4237 {
    POLY GCINFO;
    TUP0 (*Code) (T_4237, LIST, Int);
    Ref self_10;
};
struct T_4236 {
    POLY GCINFO;
    TUP0 (*Code) (T_4236, CLOS, Int);
    Ref self_10;
};
struct T_4235 {
    POLY GCINFO;
    TUP0 (*Code) (T_4235, CLOS, Int);
    Ref self_10;
};
struct T_4234 {
    POLY GCINFO;
    Maybe_Prelude (*Code) (T_4234, Int);
    Ref self_10;
};
struct T_4233 {
    POLY GCINFO;
    LIST (*Code) (T_4233, Int);
    Ref self_10;
};
struct T_4232 {
    POLY GCINFO;
    LIST (*Code) (T_4232, Int);
    Ref self_10;
};
struct T_4231 {
    POLY GCINFO;
    TUP0 (*Code) (T_4231, Int);
    Ref self_10;
};
struct T_4230 {
    POLY GCINFO;
    Color_CTCommon (*Code) (T_4230, Int);
    Ref self_10;
};
struct T_4229 {
    POLY GCINFO;
    TUP0 (*Code) (T_4229);
    AbsTime baseline;
    AbsTime deadline;
    Msg next;
    Color_CTCommon a_4077;
    CocoaID_CTCommon id_22;
    Ref self_10;
};
struct T_4228 {
    POLY GCINFO;
    Msg (*Code) (T_4228, Color_CTCommon, Time, Time);
    CocoaID_CTCommon id_22;
    Ref self_10;
};
struct T_4227 {
    POLY GCINFO;
    Size_CTCommon (*Code) (T_4227, Int);
    Ref self_10;
};
struct T_4226 {
    POLY GCINFO;
    TUP0 (*Code) (T_4226);
    AbsTime baseline;
    AbsTime deadline;
    Msg next;
    Size_CTCommon a_4065;
    CocoaID_CTCommon id_22;
    Ref self_10;
};
struct T_4225 {
    POLY GCINFO;
    Msg (*Code) (T_4225, Size_CTCommon, Time, Time);
    CocoaID_CTCommon id_22;
    Ref self_10;
};
struct T_4224 {
    POLY GCINFO;
    Position_CTCommon (*Code) (T_4224, Int);
    Ref self_10;
};
struct T_4223 {
    POLY GCINFO;
    TUP0 (*Code) (T_4223);
    AbsTime baseline;
    AbsTime deadline;
    Msg next;
    Position_CTCommon a_4053;
    CocoaID_CTCommon id_22;
    Ref self_10;
};
struct T_4222 {
    POLY GCINFO;
    Msg (*Code) (T_4222, Position_CTCommon, Time, Time);
    CocoaID_CTCommon id_22;
    Ref self_10;
};
 
static WORD __GC__S_816[];
static WORD __GC__T_4261[];
static WORD __GC__T_4260[];
static WORD __GC__T_4259[];
static WORD __GC__T_4258[];
static WORD __GC__T_4257[];
static WORD __GC__T_4256[];
static WORD __GC__T_4255[];
static WORD __GC__T_4254[];
static WORD __GC__T_4253[];
static WORD __GC__T_4252[];
static WORD __GC__T_4251[];
static WORD __GC__T_4250[];
static WORD __GC__T_4249[];
static WORD __GC__T_4248[];
static WORD __GC__T_4247[];
static WORD __GC__T_4246[];
static WORD __GC__T_4245[];
static WORD __GC__T_4244[];
static WORD __GC__T_4243[];
static WORD __GC__T_4242[];
static WORD __GC__T_4241[];
static WORD __GC__T_4240[];
static WORD __GC__T_4239[];
static WORD __GC__T_4238[];
static WORD __GC__T_4237[];
static WORD __GC__T_4236[];
static WORD __GC__T_4235[];
static WORD __GC__T_4234[];
static WORD __GC__T_4233[];
static WORD __GC__T_4232[];
static WORD __GC__T_4231[];
static WORD __GC__T_4230[];
static WORD __GC__T_4229[];
static WORD __GC__T_4228[];
static WORD __GC__T_4227[];
static WORD __GC__T_4226[];
static WORD __GC__T_4225[];
static WORD __GC__T_4224[];
static WORD __GC__T_4223[];
static WORD __GC__T_4222[];
static TUP0 inithelper_59 (CocoaID_CTCommon id_22, Ref self_60);
static CLOS getType_58 (MouseEventType_CTCommon a_139);
static Position_CTCommon posget_54 (MouseEventType_CTCommon a_135);
static TUP0 f_4271 (T_4223 this_4269);
static Msg f_4272 (T_4222 this_4265,
                   Position_CTCommon a_4053,
                   Time a_4054,
                   Time a_4055);
static Position_CTCommon f_4275 (T_4224 this_4273, Int a_4059);
static TUP0 f_4282 (T_4226 this_4280);
static Msg f_4283 (T_4225 this_4276,
                   Size_CTCommon a_4065,
                   Time a_4066,
                   Time a_4067);
static Size_CTCommon f_4286 (T_4227 this_4284, Int a_4071);
static TUP0 f_4293 (T_4229 this_4291);
static Msg f_4294 (T_4228 this_4287,
                   Color_CTCommon a_4077,
                   Time a_4078,
                   Time a_4079);
static Color_CTCommon f_4297 (T_4230 this_4295, Int a_4083);
static TUP0 f_4300 (T_4231 this_4298, Int a_4086);
static LIST f_4303 (T_4232 this_4301, Int a_4090);
static LIST f_4306 (T_4233 this_4304, Int a_4094);
static Maybe_Prelude f_4309 (T_4234 this_4307, Int a_4099);
static TUP0 f_4314 (T_4235 this_4310, CLOS a_4104, Int a_4105);
static TUP0 f_4319 (T_4236 this_4315, CLOS a_4112, Int a_4113);
static TUP0 f_4323 (T_4237 this_4320, LIST a_4118, Int a_4119);
static TUP0 f_4330 (T_4238 this_4324,
                    Maybe_Prelude a_4122,
                    Int a_4123);
static TUP0 f_4335 (T_4239 this_4331,
                    Maybe_Prelude a_4126,
                    Int a_4127);
static Maybe_Prelude f_4339 (T_4240 this_4336, Int a_4129);
static TUP0 f_4344 (T_4241 this_4340, Bool a_4132, Int a_4133);
static Bool f_4348 (T_4242 this_4345, Int a_4135);
static TUP0 f_4361 (T_4245 this_4353, Ref self_89);
static TUP0 f_4371 (T_4246 this_4363, Ref self_91);
static CLOS f_4373 (T_4244 this_4352);
static TUP0 f_4377 (T_4243 this_4349,
                    Component_CTCommon a_4138,
                    Int a_4139);
static Maybe_Prelude f_4383 (T_4247 this_4378,
                             CocoaEvent_CTCommon a_4142,
                             LIST a_4143,
                             Int a_4144);
static TUP0 f_4396 (T_4249 this_4389,
                    Component_CTCommon a_4146,
                    Ref a_4147);
static Maybe_Prelude f_4399 (T_4248 this_4384,
                             MouseEventType_CTCommon a_4149,
                             LIST a_4150,
                             Ref a_4151);
static TUP0 f_4407 (T_4251 this_4404,
                    Component_CTCommon a_4152,
                    Ref a_4153);
static TUP0 f_4409 (T_4250 this_4400,
                    App_CTCommon a_4156,
                    Int a_4157);
static Bool f_4413 (T_4253 this_4410, Int a_4159);
static Maybe_Prelude f_4417 (T_4253 this_4414, Int a_4161);
static Maybe_Prelude f_4421 (T_4253 this_4418, Int a_4163);
static TUP0 f_4426 (T_4253 this_4422, Bool a_4165, Int a_4166);
static TUP0 f_4431 (T_4253 this_4427,
                    Maybe_Prelude a_4168,
                    Int a_4169);
static TUP0 f_4436 (T_4253 this_4432,
                    Maybe_Prelude a_4171,
                    Int a_4172);
static Position_CTCommon f_4441 (T_4255 this_4438, Int a_4174);
static Msg f_4447 (T_4255 this_4442,
                   Position_CTCommon a_4176,
                   Time a_4177,
                   Time a_4178);
static Size_CTCommon f_4452 (T_4254 this_4449, Int a_4180);
static Msg f_4458 (T_4254 this_4453,
                   Size_CTCommon a_4182,
                   Time a_4183,
                   Time a_4184);
static Maybe_Prelude f_4465 (T_4256 this_4460,
                             CocoaEvent_CTCommon a_4186,
                             LIST a_4187,
                             Int a_4188);
static TUP0 f_4470 (T_4252 this_4467, Int a_4190);
static LIST f_4474 (T_4252 this_4471, Int a_4192);
static TUP0 f_4479 (T_4252 this_4475,
                    App_CTCommon a_4194,
                    Int a_4195);
static TUP0 f_4484 (T_4252 this_4480, LIST a_4197, Int a_4198);
static TUP0 f_4490 (T_4257 this_4486,
                    Component_CTCommon a_4200,
                    Int a_4201);
static LIST f_4494 (T_4257 this_4491, Int a_4203);
static TUP0 f_4500 (T_4258 this_4496, CLOS a_4205, Int a_4206);
static TUP0 f_4506 (T_4259 this_4502, CLOS a_4208, Int a_4209);
static Color_CTCommon f_4511 (T_4260 this_4508, Int a_4211);
static Msg f_4517 (T_4260 this_4512,
                   Color_CTCommon a_4213,
                   Time a_4214,
                   Time a_4215);
static Maybe_Prelude f_4524 (T_4261 this_4519,
                             BITS32 a_4523,
                             POLY a_4218,
                             POLY a_4219,
                             Int a_4220);
static MouseEventType_CTCommon f_4531 (CLOS this_4528,
                                       Position_CTCommon eta_1424);
static MouseEventType_CTCommon f_4536 (CLOS this_4533,
                                       Position_CTCommon eta_1428);
static MouseEventType_CTCommon f_4541 (CLOS this_4538,
                                       Position_CTCommon eta_1432);
 
WORD __GC__Container_CTContainer[] = {WORDS(sizeof(struct Container_CTContainer)),
                                      0,
                                      WORDS(offsetof(struct Container_CTContainer, l_Container_CTContainer_Component_CTCommon_CTContainer)),
                                      WORDS(offsetof(struct Container_CTContainer, l_Container_CTContainer_ContainsComponents_CTCommon_CTContainer)),
                                      WORDS(offsetof(struct Container_CTContainer, l_Container_CTContainer_HandlesMouseEvents_CTCommon_CTContainer)),
                                      WORDS(offsetof(struct Container_CTContainer, l_Container_CTContainer_HandlesKeyEvents_CTCommon_CTContainer)),
                                      WORDS(offsetof(struct Container_CTContainer, l_Container_CTContainer_HasBackgroundColor_CTCommon_CTContainer)),
                                      0};
static WORD __GC__S_816[] = {WORDS(sizeof(struct S_816)),
                             0,
                             WORDS(offsetof(struct S_816, myState_11)),
                             WORDS(offsetof(struct S_816, myComponents_12)),
                             WORDS(offsetof(struct S_816, position_13)),
                             WORDS(offsetof(struct S_816, size_14)),
                             WORDS(offsetof(struct S_816, color_15)),
                             WORDS(offsetof(struct S_816, keyEventHandler_16)),
                             WORDS(offsetof(struct S_816, appRef_17)),
                             WORDS(offsetof(struct S_816, mouseEventHandler_18)),
                             WORDS(offsetof(struct S_816, currentEventHasBeenConsumedBy_19)),
                             WORDS(offsetof(struct S_816, nextFocusTarget_20)),
                             WORDS(offsetof(struct S_816, name_21)),
                             0};
static WORD __GC__T_4261[] = {WORDS(sizeof(struct T_4261)),
                              0,
                              WORDS(offsetof(struct T_4261, self_10)),
                              0};
static WORD __GC__T_4260[] = {WORDS(sizeof(struct T_4260)),
                              0,
                              WORDS(offsetof(struct T_4260, x_4210)),
                              WORDS(offsetof(struct T_4260, x_4212)),
                              0};
static WORD __GC__T_4259[] = {WORDS(sizeof(struct T_4259)),
                              0,
                              WORDS(offsetof(struct T_4259, x_4207)),
                              0};
static WORD __GC__T_4258[] = {WORDS(sizeof(struct T_4258)),
                              0,
                              WORDS(offsetof(struct T_4258, x_4204)),
                              0};
static WORD __GC__T_4257[] = {WORDS(sizeof(struct T_4257)),
                              0,
                              WORDS(offsetof(struct T_4257, x_4199)),
                              WORDS(offsetof(struct T_4257, x_4202)),
                              0};
static WORD __GC__T_4256[] = {WORDS(sizeof(struct T_4256)),
                              0,
                              WORDS(offsetof(struct T_4256, x_4185)),
                              0};
static WORD __GC__T_4255[] = {WORDS(sizeof(struct T_4255)),
                              0,
                              WORDS(offsetof(struct T_4255, x_4173)),
                              WORDS(offsetof(struct T_4255, x_4175)),
                              0};
static WORD __GC__T_4254[] = {WORDS(sizeof(struct T_4254)),
                              0,
                              WORDS(offsetof(struct T_4254, l_HasSize_CTCommon_HasPosition_CTCommon_CTCommon)),
                              WORDS(offsetof(struct T_4254, x_4179)),
                              WORDS(offsetof(struct T_4254, x_4181)),
                              0};
static WORD __GC__T_4253[] = {WORDS(sizeof(struct T_4253)),
                              0,
                              WORDS(offsetof(struct T_4253, x_4158)),
                              WORDS(offsetof(struct T_4253, x_4160)),
                              WORDS(offsetof(struct T_4253, x_4162)),
                              WORDS(offsetof(struct T_4253, x_4164)),
                              WORDS(offsetof(struct T_4253, x_4167)),
                              WORDS(offsetof(struct T_4253, x_4170)),
                              0};
static WORD __GC__T_4252[] = {WORDS(sizeof(struct T_4252)),
                              0,
                              WORDS(offsetof(struct T_4252, l_Component_CTCommon_IsFocusable_CTCommon_CTCommon)),
                              WORDS(offsetof(struct T_4252, l_Component_CTCommon_HasSize_CTCommon_CTCommon)),
                              WORDS(offsetof(struct T_4252, l_Component_CTCommon_HandlesEvents_CTCommon_CTCommon)),
                              WORDS(offsetof(struct T_4252, id_CTCommon)),
                              WORDS(offsetof(struct T_4252, x_4189)),
                              WORDS(offsetof(struct T_4252, x_4191)),
                              WORDS(offsetof(struct T_4252, x_4193)),
                              WORDS(offsetof(struct T_4252, x_4196)),
                              0};
static WORD __GC__T_4251[] = {WORDS(sizeof(struct T_4251)),
                              0,
                              WORDS(offsetof(struct T_4251, a_4156)),
                              WORDS(offsetof(struct T_4251, id_22)),
                              0};
static WORD __GC__T_4250[] = {WORDS(sizeof(struct T_4250)),
                              0,
                              WORDS(offsetof(struct T_4250, this_86)),
                              WORDS(offsetof(struct T_4250, id_22)),
                              WORDS(offsetof(struct T_4250, self_10)),
                              0};
static WORD __GC__T_4249[] = {WORDS(sizeof(struct T_4249)),
                              0,
                              WORDS(offsetof(struct T_4249, eventInNewCoordsystem_105)),
                              WORDS(offsetof(struct T_4249, pos2_104)),
                              WORDS(offsetof(struct T_4249, a_4150)),
                              0};
static WORD __GC__T_4248[] = {WORDS(sizeof(struct T_4248)),
                              0,
                              WORDS(offsetof(struct T_4248, this_86)),
                              0};
static WORD __GC__T_4247[] = {WORDS(sizeof(struct T_4247)),
                              0,
                              WORDS(offsetof(struct T_4247, mouseEventDispatcher_84)),
                              WORDS(offsetof(struct T_4247, self_10)),
                              0};
static WORD __GC__T_4246[] = {WORDS(sizeof(struct T_4246)),
                              0,
                              WORDS(offsetof(struct T_4246, a_4138)),
                              WORDS(offsetof(struct T_4246, focus_77)),
                              0};
static WORD __GC__T_4245[] = {WORDS(sizeof(struct T_4245)),
                              0,
                              WORDS(offsetof(struct T_4245, a_4138)),
                              0};
static WORD __GC__T_4244[] = {WORDS(sizeof(struct T_4244)),
                              0,
                              WORDS(offsetof(struct T_4244, self_88)),
                              WORDS(offsetof(struct T_4244, a_4138)),
                              WORDS(offsetof(struct T_4244, focus_77)),
                              0};
static WORD __GC__T_4243[] = {WORDS(sizeof(struct T_4243)),
                              0,
                              WORDS(offsetof(struct T_4243, focus_77)),
                              WORDS(offsetof(struct T_4243, id_22)),
                              WORDS(offsetof(struct T_4243, self_10)),
                              0};
static WORD __GC__T_4242[] = {WORDS(sizeof(struct T_4242)),
                              0,
                              WORDS(offsetof(struct T_4242, focus_77)),
                              0};
static WORD __GC__T_4241[] = {WORDS(sizeof(struct T_4241)),
                              0,
                              WORDS(offsetof(struct T_4241, focus_77)),
                              0};
static WORD __GC__T_4240[] = {WORDS(sizeof(struct T_4240)),
                              0,
                              WORDS(offsetof(struct T_4240, focus_77)),
                              0};
static WORD __GC__T_4239[] = {WORDS(sizeof(struct T_4239)),
                              0,
                              WORDS(offsetof(struct T_4239, focus_77)),
                              0};
static WORD __GC__T_4238[] = {WORDS(sizeof(struct T_4238)),
                              0,
                              WORDS(offsetof(struct T_4238, self_10)),
                              0};
static WORD __GC__T_4237[] = {WORDS(sizeof(struct T_4237)),
                              0,
                              WORDS(offsetof(struct T_4237, self_10)),
                              0};
static WORD __GC__T_4236[] = {WORDS(sizeof(struct T_4236)),
                              0,
                              WORDS(offsetof(struct T_4236, self_10)),
                              0};
static WORD __GC__T_4235[] = {WORDS(sizeof(struct T_4235)),
                              0,
                              WORDS(offsetof(struct T_4235, self_10)),
                              0};
static WORD __GC__T_4234[] = {WORDS(sizeof(struct T_4234)),
                              0,
                              WORDS(offsetof(struct T_4234, self_10)),
                              0};
static WORD __GC__T_4233[] = {WORDS(sizeof(struct T_4233)),
                              0,
                              WORDS(offsetof(struct T_4233, self_10)),
                              0};
static WORD __GC__T_4232[] = {WORDS(sizeof(struct T_4232)),
                              0,
                              WORDS(offsetof(struct T_4232, self_10)),
                              0};
static WORD __GC__T_4231[] = {WORDS(sizeof(struct T_4231)),
                              0,
                              WORDS(offsetof(struct T_4231, self_10)),
                              0};
static WORD __GC__T_4230[] = {WORDS(sizeof(struct T_4230)),
                              0,
                              WORDS(offsetof(struct T_4230, self_10)),
                              0};
static WORD __GC__T_4229[] = {WORDS(sizeof(struct T_4229)),
                              0,
                              WORDS(offsetof(struct T_4229, a_4077)),
                              WORDS(offsetof(struct T_4229, id_22)),
                              WORDS(offsetof(struct T_4229, self_10)),
                              0};
static WORD __GC__T_4228[] = {WORDS(sizeof(struct T_4228)),
                              0,
                              WORDS(offsetof(struct T_4228, id_22)),
                              WORDS(offsetof(struct T_4228, self_10)),
                              0};
static WORD __GC__T_4227[] = {WORDS(sizeof(struct T_4227)),
                              0,
                              WORDS(offsetof(struct T_4227, self_10)),
                              0};
static WORD __GC__T_4226[] = {WORDS(sizeof(struct T_4226)),
                              0,
                              WORDS(offsetof(struct T_4226, a_4065)),
                              WORDS(offsetof(struct T_4226, id_22)),
                              WORDS(offsetof(struct T_4226, self_10)),
                              0};
static WORD __GC__T_4225[] = {WORDS(sizeof(struct T_4225)),
                              0,
                              WORDS(offsetof(struct T_4225, id_22)),
                              WORDS(offsetof(struct T_4225, self_10)),
                              0};
static WORD __GC__T_4224[] = {WORDS(sizeof(struct T_4224)),
                              0,
                              WORDS(offsetof(struct T_4224, self_10)),
                              0};
static WORD __GC__T_4223[] = {WORDS(sizeof(struct T_4223)),
                              0,
                              WORDS(offsetof(struct T_4223, a_4053)),
                              WORDS(offsetof(struct T_4223, id_22)),
                              WORDS(offsetof(struct T_4223, self_10)),
                              0};
static WORD __GC__T_4222[] = {WORDS(sizeof(struct T_4222)),
                              0,
                              WORDS(offsetof(struct T_4222, id_22)),
                              WORDS(offsetof(struct T_4222, self_10)),
                              0};
Component_CTCommon c_668_CTContainer (Container_CTContainer v_670) {
    return v_670->l_Container_CTContainer_Component_CTCommon_CTContainer;
}
ContainsComponents_CTCommon c_671_CTContainer (Container_CTContainer v_673) {
    return v_673->l_Container_CTContainer_ContainsComponents_CTCommon_CTContainer;
}
HandlesMouseEvents_CTCommon c_674_CTContainer (Container_CTContainer v_676) {
    return v_676->l_Container_CTContainer_HandlesMouseEvents_CTCommon_CTContainer;
}
HandlesKeyEvents_CTCommon c_677_CTContainer (Container_CTContainer v_679) {
    return v_679->l_Container_CTContainer_HandlesKeyEvents_CTCommon_CTContainer;
}
HasBackgroundColor_CTCommon c_680_CTContainer (Container_CTContainer v_682) {
    return v_682->l_Container_CTContainer_HasBackgroundColor_CTCommon_CTContainer;
}
IsFocusable_CTCommon c_684_CTContainer (Container_CTContainer a_683) {
    return a_683->l_Container_CTContainer_Component_CTCommon_CTContainer->l_Component_CTCommon_IsFocusable_CTCommon_CTCommon;
}
HasSize_CTCommon c_686_CTContainer (Container_CTContainer a_685) {
    return a_685->l_Container_CTContainer_Component_CTCommon_CTContainer->l_Component_CTCommon_HasSize_CTCommon_CTCommon;
}
HandlesEvents_CTCommon c_688_CTContainer (Container_CTContainer a_687) {
    return a_687->l_Container_CTContainer_Component_CTCommon_CTContainer->l_Component_CTCommon_HandlesEvents_CTCommon_CTCommon;
}
HasPosition_CTCommon c_690_CTContainer (Container_CTContainer a_689) {
    return a_689->l_Container_CTContainer_Component_CTCommon_CTContainer->l_Component_CTCommon_HasSize_CTCommon_CTCommon->l_HasSize_CTCommon_HasPosition_CTCommon_CTCommon;
}
Bool inInterval_CTContainer (BITS32 a_4262,
                             Ord_Prelude v_795,
                             Num_Prelude v_797,
                             POLY x_123,
                             POLY startPos_124,
                             POLY width_125) {
    return (v_795->_sym_158_Prelude/* >= */(v_795,
                                            x_123,
                                            startPos_124) && v_795->_sym_156_Prelude/* <= */(v_795,
                                                                                             x_123,
                                                                                             v_797->_sym_161_Prelude/* + */(v_797,
                                                                                                                            startPos_124,
                                                                                                                            width_125)));
}
Container_CTContainer mkContainer_CTContainer (BITS32 a_4263,
                                               POLY e_9,
                                               Int d_4221) {
    Ref self_10;
    NEW (Ref, self_10, WORDS(sizeof(struct Ref))+
                       WORDS(sizeof(struct S_816)));
    INITREF(self_10);
    ((S_816)STATEOF(self_10))->GCINFO = __GC__S_816;
    CocoaID_CTCommon id_22;
    id_22 = mkCocoaID_CTCommon(0);
    CLOS setPosition_23;
    NEW (CLOS, setPosition_23, WORDS(sizeof(struct T_4222)));
    ((T_4222)setPosition_23)->GCINFO = __GC__T_4222;
    ((T_4222)setPosition_23)->Code = f_4272;
    ((T_4222)setPosition_23)->id_22 = id_22;
    ((T_4222)setPosition_23)->self_10 = self_10;
    CLOS getPosition_28;
    NEW (CLOS, getPosition_28, WORDS(sizeof(struct T_4224)));
    ((T_4224)getPosition_28)->GCINFO = __GC__T_4224;
    ((T_4224)getPosition_28)->Code = f_4275;
    ((T_4224)getPosition_28)->self_10 = self_10;
    CLOS setSize_30;
    NEW (CLOS, setSize_30, WORDS(sizeof(struct T_4225)));
    ((T_4225)setSize_30)->GCINFO = __GC__T_4225;
    ((T_4225)setSize_30)->Code = f_4283;
    ((T_4225)setSize_30)->id_22 = id_22;
    ((T_4225)setSize_30)->self_10 = self_10;
    CLOS getSize_35;
    NEW (CLOS, getSize_35, WORDS(sizeof(struct T_4227)));
    ((T_4227)getSize_35)->GCINFO = __GC__T_4227;
    ((T_4227)getSize_35)->Code = f_4286;
    ((T_4227)getSize_35)->self_10 = self_10;
    CLOS setBackgroundColor_37;
    NEW (CLOS, setBackgroundColor_37, WORDS(sizeof(struct T_4228)));
    ((T_4228)setBackgroundColor_37)->GCINFO = __GC__T_4228;
    ((T_4228)setBackgroundColor_37)->Code = f_4294;
    ((T_4228)setBackgroundColor_37)->id_22 = id_22;
    ((T_4228)setBackgroundColor_37)->self_10 = self_10;
    CLOS getBackgroundColor_42;
    NEW (CLOS, getBackgroundColor_42, WORDS(sizeof(struct T_4230)));
    ((T_4230)getBackgroundColor_42)->GCINFO = __GC__T_4230;
    ((T_4230)getBackgroundColor_42)->Code = f_4297;
    ((T_4230)getBackgroundColor_42)->self_10 = self_10;
    CLOS destroy_44;
    NEW (CLOS, destroy_44, WORDS(sizeof(struct T_4231)));
    ((T_4231)destroy_44)->GCINFO = __GC__T_4231;
    ((T_4231)destroy_44)->Code = f_4300;
    ((T_4231)destroy_44)->self_10 = self_10;
    CLOS getComponents_46;
    NEW (CLOS, getComponents_46, WORDS(sizeof(struct T_4232)));
    ((T_4232)getComponents_46)->GCINFO = __GC__T_4232;
    ((T_4232)getComponents_46)->Code = f_4303;
    ((T_4232)getComponents_46)->self_10 = self_10;
    CLOS getName_48;
    NEW (CLOS, getName_48, WORDS(sizeof(struct T_4233)));
    ((T_4233)getName_48)->GCINFO = __GC__T_4233;
    ((T_4233)getName_48)->Code = f_4306;
    ((T_4233)getName_48)->self_10 = self_10;
    CLOS getNextFocusTarget_50;
    NEW (CLOS, getNextFocusTarget_50, WORDS(sizeof(struct T_4234)));
    ((T_4234)getNextFocusTarget_50)->GCINFO = __GC__T_4234;
    ((T_4234)getNextFocusTarget_50)->Code = f_4309;
    ((T_4234)getNextFocusTarget_50)->self_10 = self_10;
    CLOS installKeyListener_61;
    NEW (CLOS, installKeyListener_61, WORDS(sizeof(struct T_4235)));
    ((T_4235)installKeyListener_61)->GCINFO = __GC__T_4235;
    ((T_4235)installKeyListener_61)->Code = f_4314;
    ((T_4235)installKeyListener_61)->self_10 = self_10;
    CLOS installMouseListener_64;
    NEW (CLOS, installMouseListener_64, WORDS(sizeof(struct T_4236)));
    ((T_4236)installMouseListener_64)->GCINFO = __GC__T_4236;
    ((T_4236)installMouseListener_64)->Code = f_4319;
    ((T_4236)installMouseListener_64)->self_10 = self_10;
    CLOS setName_67;
    NEW (CLOS, setName_67, WORDS(sizeof(struct T_4237)));
    ((T_4237)setName_67)->GCINFO = __GC__T_4237;
    ((T_4237)setName_67)->Code = f_4323;
    ((T_4237)setName_67)->self_10 = self_10;
    CLOS setNextFocusTarget_70;
    NEW (CLOS, setNextFocusTarget_70, WORDS(sizeof(struct T_4238)));
    ((T_4238)setNextFocusTarget_70)->GCINFO = __GC__T_4238;
    ((T_4238)setNextFocusTarget_70)->Code = f_4330;
    ((T_4238)setNextFocusTarget_70)->self_10 = self_10;
    IsFocusable_CTCommon focus_77;
    CLOS setPreviousFocusTarget_78;
    CLOS getPreviousFocusTarget_79;
    CLOS setIsFocusable_80;
    CLOS getIsFocusable_81;
    CLOS addComponent_82;
    CLOS handleEvent_83;
    CLOS mouseEventDispatcher_84;
    CLOS init_85;
    CLOS x_4158;
    CLOS x_4160;
    CLOS x_4162;
    CLOS x_4164;
    CLOS x_4167;
    CLOS x_4170;
    CLOS x_4173;
    CLOS x_4175;
    CLOS x_4179;
    CLOS x_4181;
    CLOS x_4185;
    CLOS x_4189;
    CLOS x_4191;
    CLOS x_4193;
    CLOS x_4196;
    CLOS x_4199;
    CLOS x_4202;
    CLOS x_4204;
    CLOS x_4207;
    CLOS x_4210;
    CLOS x_4212;
    T_4253 x_4437;
    T_4255 x_4448;
    T_4254 x_4459;
    T_4256 x_4466;
    T_4252 x_4485;
    T_4257 x_4495;
    T_4258 x_4501;
    T_4259 x_4507;
    T_4260 x_4518;
    Container_CTContainer this_86;
    Component_CTCommon x_3398;
    x_4160 = getNextFocusTarget_50;
    x_4167 = setNextFocusTarget_70;
    x_4173 = getPosition_28;
    x_4175 = setPosition_23;
    NEW (T_4255, x_4448, WORDS(sizeof(struct T_4255)));
    x_4448->GCINFO = __GC__T_4255;
    x_4448->getPosition_CTCommon = f_4441;
    x_4448->setPosition_CTCommon = f_4447;
    x_4448->x_4173 = x_4173;
    x_4448->x_4175 = x_4175;
    x_4179 = getSize_35;
    x_4181 = setSize_30;
    NEW (T_4254, x_4459, WORDS(sizeof(struct T_4254)));
    x_4459->GCINFO = __GC__T_4254;
    x_4459->l_HasSize_CTCommon_HasPosition_CTCommon_CTCommon = (HasPosition_CTCommon)x_4448;
    x_4459->getSize_CTCommon = f_4452;
    x_4459->setSize_CTCommon = f_4458;
    x_4459->x_4179 = x_4179;
    x_4459->x_4181 = x_4181;
    x_4189 = destroy_44;
    x_4191 = getName_48;
    x_4196 = setName_67;
    x_4202 = getComponents_46;
    x_4204 = installMouseListener_64;
    NEW (T_4258, x_4501, WORDS(sizeof(struct T_4258)));
    x_4501->GCINFO = __GC__T_4258;
    x_4501->installMouseListener_CTCommon = f_4500;
    x_4501->x_4204 = x_4204;
    x_4207 = installKeyListener_61;
    NEW (T_4259, x_4507, WORDS(sizeof(struct T_4259)));
    x_4507->GCINFO = __GC__T_4259;
    x_4507->installKeyListener_CTCommon = f_4506;
    x_4507->x_4207 = x_4207;
    x_4210 = getBackgroundColor_42;
    x_4212 = setBackgroundColor_37;
    NEW (T_4260, x_4518, WORDS(sizeof(struct T_4260)));
    x_4518->GCINFO = __GC__T_4260;
    x_4518->getBackgroundColor_CTCommon = f_4511;
    x_4518->setBackgroundColor_CTCommon = f_4517;
    x_4518->x_4210 = x_4210;
    x_4518->x_4212 = x_4212;
    {   Array roots = CYCLIC_BEGIN(22,1);
        focus_77 = (IsFocusable_CTCommon)roots->elems[0];
        setPreviousFocusTarget_78 = (CLOS)roots->elems[1];
        getPreviousFocusTarget_79 = (CLOS)roots->elems[2];
        setIsFocusable_80 = (CLOS)roots->elems[3];
        getIsFocusable_81 = (CLOS)roots->elems[4];
        addComponent_82 = (CLOS)roots->elems[5];
        handleEvent_83 = (CLOS)roots->elems[6];
        mouseEventDispatcher_84 = (CLOS)roots->elems[7];
        init_85 = (CLOS)roots->elems[8];
        x_4158 = (CLOS)roots->elems[9];
        x_4162 = (CLOS)roots->elems[10];
        x_4164 = (CLOS)roots->elems[11];
        x_4170 = (CLOS)roots->elems[12];
        x_4185 = (CLOS)roots->elems[13];
        x_4193 = (CLOS)roots->elems[14];
        x_4199 = (CLOS)roots->elems[15];
        x_4437 = (T_4253)roots->elems[16];
        x_4466 = (T_4256)roots->elems[17];
        x_4485 = (T_4252)roots->elems[18];
        x_4495 = (T_4257)roots->elems[19];
        this_86 = (Container_CTContainer)roots->elems[20];
        x_3398 = (Component_CTCommon)roots->elems[21];
        focus_77 = focusWrapper_CTCommon(x_3398, (Bool)0, 0);
        roots->elems[0] = (POLY)focus_77;
        NEW (CLOS, setPreviousFocusTarget_78, WORDS(sizeof(struct T_4239)));
        roots->elems[1] = (POLY)setPreviousFocusTarget_78;
        ((T_4239)(CLOS)roots->elems[1])->GCINFO = __GC__T_4239;
        ((T_4239)(CLOS)roots->elems[1])->Code = f_4335;
        ((T_4239)(CLOS)roots->elems[1])->focus_77 = focus_77;
        NEW (CLOS, getPreviousFocusTarget_79, WORDS(sizeof(struct T_4240)));
        roots->elems[2] = (POLY)getPreviousFocusTarget_79;
        ((T_4240)(CLOS)roots->elems[2])->GCINFO = __GC__T_4240;
        ((T_4240)(CLOS)roots->elems[2])->Code = f_4339;
        ((T_4240)(CLOS)roots->elems[2])->focus_77 = focus_77;
        NEW (CLOS, setIsFocusable_80, WORDS(sizeof(struct T_4241)));
        roots->elems[3] = (POLY)setIsFocusable_80;
        ((T_4241)(CLOS)roots->elems[3])->GCINFO = __GC__T_4241;
        ((T_4241)(CLOS)roots->elems[3])->Code = f_4344;
        ((T_4241)(CLOS)roots->elems[3])->focus_77 = focus_77;
        NEW (CLOS, getIsFocusable_81, WORDS(sizeof(struct T_4242)));
        roots->elems[4] = (POLY)getIsFocusable_81;
        ((T_4242)(CLOS)roots->elems[4])->GCINFO = __GC__T_4242;
        ((T_4242)(CLOS)roots->elems[4])->Code = f_4348;
        ((T_4242)(CLOS)roots->elems[4])->focus_77 = focus_77;
        NEW (CLOS, addComponent_82, WORDS(sizeof(struct T_4243)));
        roots->elems[5] = (POLY)addComponent_82;
        ((T_4243)(CLOS)roots->elems[5])->GCINFO = __GC__T_4243;
        ((T_4243)(CLOS)roots->elems[5])->Code = f_4377;
        ((T_4243)(CLOS)roots->elems[5])->focus_77 = focus_77;
        ((T_4243)(CLOS)roots->elems[5])->id_22 = id_22;
        ((T_4243)(CLOS)roots->elems[5])->self_10 = self_10;
        NEW (CLOS, handleEvent_83, WORDS(sizeof(struct T_4247)));
        roots->elems[6] = (POLY)handleEvent_83;
        ((T_4247)(CLOS)roots->elems[6])->GCINFO = __GC__T_4247;
        ((T_4247)(CLOS)roots->elems[6])->Code = f_4383;
        ((T_4247)(CLOS)roots->elems[6])->mouseEventDispatcher_84 = mouseEventDispatcher_84;
        ((T_4247)(CLOS)roots->elems[6])->self_10 = self_10;
        NEW (CLOS, mouseEventDispatcher_84, WORDS(sizeof(struct T_4248)));
        roots->elems[7] = (POLY)mouseEventDispatcher_84;
        ((T_4248)(CLOS)roots->elems[7])->GCINFO = __GC__T_4248;
        ((T_4248)(CLOS)roots->elems[7])->Code = f_4399;
        ((T_4248)(CLOS)roots->elems[7])->this_86 = this_86;
        NEW (CLOS, init_85, WORDS(sizeof(struct T_4250)));
        roots->elems[8] = (POLY)init_85;
        ((T_4250)(CLOS)roots->elems[8])->GCINFO = __GC__T_4250;
        ((T_4250)(CLOS)roots->elems[8])->Code = f_4409;
        ((T_4250)(CLOS)roots->elems[8])->this_86 = this_86;
        ((T_4250)(CLOS)roots->elems[8])->id_22 = id_22;
        ((T_4250)(CLOS)roots->elems[8])->self_10 = self_10;
        x_4158 = getIsFocusable_81;
        roots->elems[9] = (POLY)x_4158;
        x_4162 = getPreviousFocusTarget_79;
        roots->elems[10] = (POLY)x_4162;
        x_4164 = setIsFocusable_80;
        roots->elems[11] = (POLY)x_4164;
        x_4170 = setPreviousFocusTarget_78;
        roots->elems[12] = (POLY)x_4170;
        CYCLIC_UPDATE(roots, 13, hp);
        x_4185 = handleEvent_83;
        roots->elems[13] = (POLY)x_4185;
        x_4193 = init_85;
        roots->elems[14] = (POLY)x_4193;
        x_4199 = addComponent_82;
        roots->elems[15] = (POLY)x_4199;
        NEW (T_4253, x_4437, WORDS(sizeof(struct T_4253)));
        roots->elems[16] = (POLY)x_4437;
        ((T_4253)roots->elems[16])->GCINFO = __GC__T_4253;
        ((T_4253)roots->elems[16])->getIsFocusable_CTCommon = f_4413;
        ((T_4253)roots->elems[16])->getNextFocusTarget_CTCommon = f_4417;
        ((T_4253)roots->elems[16])->getPreviousFocusTarget_CTCommon = f_4421;
        ((T_4253)roots->elems[16])->setIsFocusable_CTCommon = f_4426;
        ((T_4253)roots->elems[16])->setNextFocusTarget_CTCommon = f_4431;
        ((T_4253)roots->elems[16])->setPreviousFocusTarget_CTCommon = f_4436;
        ((T_4253)roots->elems[16])->x_4158 = x_4158;
        ((T_4253)roots->elems[16])->x_4160 = x_4160;
        ((T_4253)roots->elems[16])->x_4162 = x_4162;
        ((T_4253)roots->elems[16])->x_4164 = x_4164;
        ((T_4253)roots->elems[16])->x_4167 = x_4167;
        ((T_4253)roots->elems[16])->x_4170 = x_4170;
        NEW (T_4256, x_4466, WORDS(sizeof(struct T_4256)));
        roots->elems[17] = (POLY)x_4466;
        ((T_4256)roots->elems[17])->GCINFO = __GC__T_4256;
        ((T_4256)roots->elems[17])->handleEvent_CTCommon = f_4465;
        ((T_4256)roots->elems[17])->x_4185 = x_4185;
        NEW (T_4252, x_4485, WORDS(sizeof(struct T_4252)));
        roots->elems[18] = (POLY)x_4485;
        ((T_4252)roots->elems[18])->GCINFO = __GC__T_4252;
        ((T_4252)roots->elems[18])->l_Component_CTCommon_IsFocusable_CTCommon_CTCommon = (IsFocusable_CTCommon)x_4437;
        ((T_4252)roots->elems[18])->l_Component_CTCommon_HasSize_CTCommon_CTCommon = (HasSize_CTCommon)x_4459;
        ((T_4252)roots->elems[18])->l_Component_CTCommon_HandlesEvents_CTCommon_CTCommon = (HandlesEvents_CTCommon)x_4466;
        ((T_4252)roots->elems[18])->id_CTCommon = id_22;
        ((T_4252)roots->elems[18])->destroy_CTCommon = f_4470;
        ((T_4252)roots->elems[18])->getName_CTCommon = f_4474;
        ((T_4252)roots->elems[18])->init_CTCommon = f_4479;
        ((T_4252)roots->elems[18])->setName_CTCommon = f_4484;
        ((T_4252)roots->elems[18])->x_4189 = x_4189;
        ((T_4252)roots->elems[18])->x_4191 = x_4191;
        ((T_4252)roots->elems[18])->x_4193 = x_4193;
        ((T_4252)roots->elems[18])->x_4196 = x_4196;
        NEW (T_4257, x_4495, WORDS(sizeof(struct T_4257)));
        roots->elems[19] = (POLY)x_4495;
        ((T_4257)roots->elems[19])->GCINFO = __GC__T_4257;
        ((T_4257)roots->elems[19])->addComponent_CTCommon = f_4490;
        ((T_4257)roots->elems[19])->getComponents_CTCommon = f_4494;
        ((T_4257)roots->elems[19])->x_4199 = x_4199;
        ((T_4257)roots->elems[19])->x_4202 = x_4202;
        NEW (Container_CTContainer, this_86, WORDS(sizeof(struct Container_CTContainer)));
        roots->elems[20] = (POLY)this_86;
        ((Container_CTContainer)roots->elems[20])->GCINFO = __GC__Container_CTContainer;
        ((Container_CTContainer)roots->elems[20])->l_Container_CTContainer_Component_CTCommon_CTContainer = (Component_CTCommon)x_4485;
        ((Container_CTContainer)roots->elems[20])->l_Container_CTContainer_ContainsComponents_CTCommon_CTContainer = (ContainsComponents_CTCommon)x_4495;
        ((Container_CTContainer)roots->elems[20])->l_Container_CTContainer_HandlesMouseEvents_CTCommon_CTContainer = (HandlesMouseEvents_CTCommon)x_4501;
        ((Container_CTContainer)roots->elems[20])->l_Container_CTContainer_HandlesKeyEvents_CTCommon_CTContainer = (HandlesKeyEvents_CTCommon)x_4507;
        ((Container_CTContainer)roots->elems[20])->l_Container_CTContainer_HasBackgroundColor_CTCommon_CTContainer = (HasBackgroundColor_CTCommon)x_4518;
        x_3398 = this_86->l_Container_CTContainer_Component_CTCommon_CTContainer;
        roots->elems[21] = (POLY)x_3398;
        CYCLIC_END(roots, hp);
    }
    CLOS handleEvent_120;
    NEW (CLOS, handleEvent_120, WORDS(sizeof(struct T_4261)));
    ((T_4261)handleEvent_120)->GCINFO = __GC__T_4261;
    ((T_4261)handleEvent_120)->Code = f_4524;
    ((T_4261)handleEvent_120)->self_10 = self_10;
    ((S_816)STATEOF(self_10))->myState_11 = (CocoaState_CTCommon)1;
    ((S_816)STATEOF(self_10))->myComponents_12 = (LIST)0;
    Position_CTCommon x_4525;
    NEW (Position_CTCommon, x_4525, WORDS(sizeof(struct Position_CTCommon)));
    x_4525->GCINFO = __GC__Position_CTCommon;
    x_4525->x_CTCommon = 0;
    x_4525->y_CTCommon = 0;
    ((S_816)STATEOF(self_10))->position_13 = x_4525;
    Size_CTCommon x_4526;
    NEW (Size_CTCommon, x_4526, WORDS(sizeof(struct Size_CTCommon)));
    x_4526->GCINFO = __GC__Size_CTCommon;
    x_4526->width_CTCommon = 0;
    x_4526->height_CTCommon = 0;
    ((S_816)STATEOF(self_10))->size_14 = x_4526;
    Color_CTCommon x_4527;
    NEW (Color_CTCommon, x_4527, WORDS(sizeof(struct Color_CTCommon)));
    x_4527->GCINFO = __GC__Color_CTCommon;
    x_4527->r_CTCommon = 255;
    x_4527->g_CTCommon = 255;
    x_4527->b_CTCommon = 255;
    ((S_816)STATEOF(self_10))->color_15 = x_4527;
    ((S_816)STATEOF(self_10))->keyEventHandler_16 = (Maybe_Prelude)1;
    ((S_816)STATEOF(self_10))->appRef_17 = (Maybe_Prelude)1;
    ((S_816)STATEOF(self_10))->mouseEventHandler_18 = (Maybe_Prelude)1;
    ((S_816)STATEOF(self_10))->currentEventHasBeenConsumedBy_19 = (Maybe_Prelude)1;
    ((S_816)STATEOF(self_10))->nextFocusTarget_20 = (Maybe_Prelude)1;
    ((S_816)STATEOF(self_10))->name_21 = getStr("Container");
    return this_86;
}
static TUP0 inithelper_59 (CocoaID_CTCommon id_22, Ref self_60) {
    Msg d_146;
    d_146 = containerSetSize_CTContainer(id_22,
                                         ((S_816)STATEOF(self_60))->size_14,
                                         Inherit,
                                         Inherit);
    Msg d_147;
    d_147 = containerSetBackgroundColor_CTContainer(id_22,
                                                    ((S_816)STATEOF(self_60))->color_15,
                                                    Inherit,
                                                    Inherit);
    Msg d_148;
    d_148 = containerSetPosition_CTContainer(id_22,
                                             ((S_816)STATEOF(self_60))->position_13,
                                             Inherit,
                                             Inherit);
    return (TUP0)0;
}
static CLOS getType_58 (MouseEventType_CTCommon a_139) {
    switch (a_139->Tag) {
        case 2: { Position_CTCommon x_143;
                  x_143 = ((_MousePressed_CTCommon)a_139)->a;
                  CLOS x_4532;
                  NEW (CLOS, x_4532, WORDS(sizeof(struct CLOS)));
                  x_4532->GCINFO = __GC__CLOS;
                  x_4532->Code = ((void(*)(void))f_4531);
                  return x_4532;
                }
                break;
        case 1: { Position_CTCommon x_144;
                  x_144 = ((_MouseReleased_CTCommon)a_139)->a;
                  CLOS x_4537;
                  NEW (CLOS, x_4537, WORDS(sizeof(struct CLOS)));
                  x_4537->GCINFO = __GC__CLOS;
                  x_4537->Code = ((void(*)(void))f_4536);
                  return x_4537;
                }
                break;
        case 3: { Position_CTCommon x_145;
                  x_145 = ((_MouseClicked_CTCommon)a_139)->a;
                  CLOS x_4542;
                  NEW (CLOS, x_4542, WORDS(sizeof(struct CLOS)));
                  x_4542->GCINFO = __GC__CLOS;
                  x_4542->Code = ((void(*)(void))f_4541);
                  return x_4542;
                }
                break;
        default: RAISE(1);
    }
}
static Position_CTCommon posget_54 (MouseEventType_CTCommon a_135) {
    switch (a_135->Tag) {
        case 2: { Position_CTCommon x_136;
                  x_136 = ((_MousePressed_CTCommon)a_135)->a;
                  return x_136;
                }
                break;
        case 1: { Position_CTCommon x_137;
                  x_137 = ((_MouseReleased_CTCommon)a_135)->a;
                  return x_137;
                }
                break;
        case 3: { Position_CTCommon x_138;
                  x_138 = ((_MouseClicked_CTCommon)a_135)->a;
                  return x_138;
                }
                break;
        default: RAISE(1);
    }
}
static TUP0 f_4271 (T_4223 this_4269) {
    Ref self_25;
    self_25 = (Ref)LOCK((OID)this_4269->self_10);
    CocoaState_CTCommon x_4270;
    x_4270 = ((S_816)STATEOF(self_25))->myState_11;
    switch ((WORD)x_4270) {
        case 2: { Msg d_127;
                  d_127 = containerSetPosition_CTContainer(this_4269->id_22,
                                                           this_4269->a_4053,
                                                           Inherit,
                                                           Inherit);
                  break;
                }
                break;
        case 0: break;
        case 1: break;
    }
    ((S_816)STATEOF(self_25))->position_13 = this_4269->a_4053;
    UNLOCK((OID)self_25);
    return (TUP0)0;
}
static Msg f_4272 (T_4222 this_4265,
                   Position_CTCommon a_4053,
                   Time a_4054,
                   Time a_4055) {
    Msg x_4052;
    NEW (Msg, x_4052, WORDS(sizeof(struct T_4223)));
    ((T_4223)x_4052)->GCINFO = __GC__T_4223;
    ((T_4223)x_4052)->Code = f_4271;
    ((T_4223)x_4052)->a_4053 = a_4053;
    ((T_4223)x_4052)->id_22 = this_4265->id_22;
    ((T_4223)x_4052)->self_10 = this_4265->self_10;
    return (Msg)ASYNC(x_4052, a_4054, a_4055);
}
static Position_CTCommon f_4275 (T_4224 this_4273, Int a_4059) {
    Ref self_29;
    self_29 = (Ref)LOCK((OID)this_4273->self_10);
    Position_CTCommon x_4056;
    x_4056 = ((S_816)STATEOF(self_29))->position_13;
    UNLOCK((OID)self_29);
    return x_4056;
}
static TUP0 f_4282 (T_4226 this_4280) {
    Ref self_32;
    self_32 = (Ref)LOCK((OID)this_4280->self_10);
    CocoaState_CTCommon x_4281;
    x_4281 = ((S_816)STATEOF(self_32))->myState_11;
    switch ((WORD)x_4281) {
        case 2: { Msg d_130;
                  d_130 = containerSetSize_CTContainer(this_4280->id_22,
                                                       this_4280->a_4065,
                                                       Inherit,
                                                       Inherit);
                  break;
                }
                break;
        case 0: break;
        case 1: break;
    }
    ((S_816)STATEOF(self_32))->size_14 = this_4280->a_4065;
    UNLOCK((OID)self_32);
    return (TUP0)0;
}
static Msg f_4283 (T_4225 this_4276,
                   Size_CTCommon a_4065,
                   Time a_4066,
                   Time a_4067) {
    Msg x_4064;
    NEW (Msg, x_4064, WORDS(sizeof(struct T_4226)));
    ((T_4226)x_4064)->GCINFO = __GC__T_4226;
    ((T_4226)x_4064)->Code = f_4282;
    ((T_4226)x_4064)->a_4065 = a_4065;
    ((T_4226)x_4064)->id_22 = this_4276->id_22;
    ((T_4226)x_4064)->self_10 = this_4276->self_10;
    return (Msg)ASYNC(x_4064, a_4066, a_4067);
}
static Size_CTCommon f_4286 (T_4227 this_4284, Int a_4071) {
    Ref self_36;
    self_36 = (Ref)LOCK((OID)this_4284->self_10);
    Size_CTCommon x_4068;
    x_4068 = ((S_816)STATEOF(self_36))->size_14;
    UNLOCK((OID)self_36);
    return x_4068;
}
static TUP0 f_4293 (T_4229 this_4291) {
    Ref self_39;
    self_39 = (Ref)LOCK((OID)this_4291->self_10);
    CocoaState_CTCommon x_4292;
    x_4292 = ((S_816)STATEOF(self_39))->myState_11;
    switch ((WORD)x_4292) {
        case 2: { Msg d_133;
                  d_133 = containerSetBackgroundColor_CTContainer(this_4291->id_22,
                                                                  this_4291->a_4077,
                                                                  Inherit,
                                                                  Inherit);
                  break;
                }
                break;
        case 0: break;
        case 1: break;
    }
    ((S_816)STATEOF(self_39))->color_15 = this_4291->a_4077;
    UNLOCK((OID)self_39);
    return (TUP0)0;
}
static Msg f_4294 (T_4228 this_4287,
                   Color_CTCommon a_4077,
                   Time a_4078,
                   Time a_4079) {
    Msg x_4076;
    NEW (Msg, x_4076, WORDS(sizeof(struct T_4229)));
    ((T_4229)x_4076)->GCINFO = __GC__T_4229;
    ((T_4229)x_4076)->Code = f_4293;
    ((T_4229)x_4076)->a_4077 = a_4077;
    ((T_4229)x_4076)->id_22 = this_4287->id_22;
    ((T_4229)x_4076)->self_10 = this_4287->self_10;
    return (Msg)ASYNC(x_4076, a_4078, a_4079);
}
static Color_CTCommon f_4297 (T_4230 this_4295, Int a_4083) {
    Ref self_43;
    self_43 = (Ref)LOCK((OID)this_4295->self_10);
    Color_CTCommon x_4080;
    x_4080 = ((S_816)STATEOF(self_43))->color_15;
    UNLOCK((OID)self_43);
    return x_4080;
}
static TUP0 f_4300 (T_4231 this_4298, Int a_4086) {
    Ref self_45;
    self_45 = (Ref)LOCK((OID)this_4298->self_10);
    ((S_816)STATEOF(self_45))->myState_11 = (CocoaState_CTCommon)0;
    UNLOCK((OID)self_45);
    return (TUP0)0;
}
static LIST f_4303 (T_4232 this_4301, Int a_4090) {
    Ref self_47;
    self_47 = (Ref)LOCK((OID)this_4301->self_10);
    LIST x_4087;
    x_4087 = ((S_816)STATEOF(self_47))->myComponents_12;
    UNLOCK((OID)self_47);
    return x_4087;
}
static LIST f_4306 (T_4233 this_4304, Int a_4094) {
    Ref self_49;
    self_49 = (Ref)LOCK((OID)this_4304->self_10);
    LIST x_4091;
    x_4091 = ((S_816)STATEOF(self_49))->name_21;
    UNLOCK((OID)self_49);
    return x_4091;
}
static Maybe_Prelude f_4309 (T_4234 this_4307, Int a_4099) {
    Ref self_51;
    self_51 = (Ref)LOCK((OID)this_4307->self_10);
    switch ((WORD)_sym_689_Prelude/* > */(length_Prelude((BITS32)0,
                                                         ((S_816)STATEOF(self_51))->myComponents_12),
                                          0)) {
        case 1: { Ref self_52;
                  self_52 = self_51;
                  Maybe_Prelude x_4095;
                  NEW (Maybe_Prelude, x_4095, WORDS(sizeof(struct _Just_Prelude)));
                  ((_Just_Prelude)x_4095)->GCINFO = __GC___Just_Prelude+((4 * (BITS32)0));
                  ((_Just_Prelude)x_4095)->a = (POLY)(Component_CTCommon)last_Prelude((BITS32)0,
                                                                                      ((S_816)STATEOF(self_52))->myComponents_12);
                  UNLOCK((OID)self_51);
                  return x_4095;
                }
                break;
        case 0: { Ref self_53;
                  self_53 = self_51;
                  Maybe_Prelude x_4096;
                  x_4096 = ((S_816)STATEOF(self_53))->nextFocusTarget_20;
                  UNLOCK((OID)self_51);
                  return x_4096;
                }
                break;
    }
}
static TUP0 f_4314 (T_4235 this_4310, CLOS a_4104, Int a_4105) {
    Ref self_63;
    self_63 = (Ref)LOCK((OID)this_4310->self_10);
    _Just_Prelude x_4313;
    NEW (_Just_Prelude, x_4313, WORDS(sizeof(struct _Just_Prelude)));
    x_4313->GCINFO = __GC___Just_Prelude+((4 * (BITS32)0));
    x_4313->a = (POLY)a_4104;
    ((S_816)STATEOF(self_63))->keyEventHandler_16 = (Maybe_Prelude)x_4313;
    UNLOCK((OID)self_63);
    return (TUP0)0;
}
static TUP0 f_4319 (T_4236 this_4315, CLOS a_4112, Int a_4113) {
    Ref self_66;
    self_66 = (Ref)LOCK((OID)this_4315->self_10);
    _Just_Prelude x_4318;
    NEW (_Just_Prelude, x_4318, WORDS(sizeof(struct _Just_Prelude)));
    x_4318->GCINFO = __GC___Just_Prelude+((4 * (BITS32)0));
    x_4318->a = (POLY)a_4112;
    ((S_816)STATEOF(self_66))->mouseEventHandler_18 = (Maybe_Prelude)x_4318;
    UNLOCK((OID)self_66);
    return (TUP0)0;
}
static TUP0 f_4323 (T_4237 this_4320, LIST a_4118, Int a_4119) {
    Ref self_69;
    self_69 = (Ref)LOCK((OID)this_4320->self_10);
    ((S_816)STATEOF(self_69))->name_21 = a_4118;
    UNLOCK((OID)self_69);
    return (TUP0)0;
}
static TUP0 f_4330 (T_4238 this_4324,
                    Maybe_Prelude a_4122,
                    Int a_4123) {
    Ref self_72;
    self_72 = (Ref)LOCK((OID)this_4324->self_10);
    ((S_816)STATEOF(self_72))->nextFocusTarget_20 = a_4122;
    switch ((WORD)_sym_689_Prelude/* > */(length_Prelude((BITS32)0,
                                                         ((S_816)STATEOF(self_72))->myComponents_12),
                                          0)) {
        case 1: { Ref self_73;
                  self_73 = self_72;
                  IsFocusable_CTCommon x_4327;
                  x_4327 = ((Component_CTCommon)head_Prelude((BITS32)0,
                                                             ((S_816)STATEOF(self_73))->myComponents_12))->l_Component_CTCommon_IsFocusable_CTCommon_CTCommon;
                  TUP0 d_149;
                  d_149 = x_4327->setNextFocusTarget_CTCommon(x_4327,
                                                              ((S_816)STATEOF(self_73))->nextFocusTarget_20,
                                                              0);
                  switch ((WORD)isJust_Prelude((BITS32)0,
                                               ((S_816)STATEOF(self_73))->nextFocusTarget_20)) {
                      case 1: { _Just_Prelude x_4328;
                                NEW (_Just_Prelude, x_4328, WORDS(sizeof(struct _Just_Prelude)));
                                x_4328->GCINFO = __GC___Just_Prelude+((4 * (BITS32)0));
                                x_4328->a = (POLY)(Component_CTCommon)head_Prelude((BITS32)0,
                                                                                   ((S_816)STATEOF(self_73))->myComponents_12);
                                IsFocusable_CTCommon x_4329;
                                x_4329 = ((Component_CTCommon)fromJust_Prelude((BITS32)0,
                                                                               ((S_816)STATEOF(self_73))->nextFocusTarget_20))->l_Component_CTCommon_IsFocusable_CTCommon_CTCommon;
                                TUP0 d_151;
                                d_151 = x_4329->setPreviousFocusTarget_CTCommon(x_4329,
                                                                                (Maybe_Prelude)x_4328,
                                                                                0);
                                break;
                              }
                              break;
                      case 0: break;
                  }
                  UNLOCK((OID)self_72);
                  return (TUP0)0;
                }
                break;
        case 0: { Ref self_76;
                  self_76 = self_72;
                  UNLOCK((OID)self_72);
                  return (TUP0)0;
                }
                break;
    }
}
static TUP0 f_4335 (T_4239 this_4331,
                    Maybe_Prelude a_4126,
                    Int a_4127) {
    IsFocusable_CTCommon x_4334;
    x_4334 = this_4331->focus_77;
    return x_4334->setPreviousFocusTarget_CTCommon(x_4334,
                                                   a_4126,
                                                   a_4127);
}
static Maybe_Prelude f_4339 (T_4240 this_4336, Int a_4129) {
    IsFocusable_CTCommon x_4338;
    x_4338 = this_4336->focus_77;
    return x_4338->getPreviousFocusTarget_CTCommon(x_4338, a_4129);
}
static TUP0 f_4344 (T_4241 this_4340, Bool a_4132, Int a_4133) {
    IsFocusable_CTCommon x_4343;
    x_4343 = this_4340->focus_77;
    return x_4343->setIsFocusable_CTCommon(x_4343, a_4132, a_4133);
}
static Bool f_4348 (T_4242 this_4345, Int a_4135) {
    IsFocusable_CTCommon x_4347;
    x_4347 = this_4345->focus_77;
    return x_4347->getIsFocusable_CTCommon(x_4347, a_4135);
}
static TUP0 f_4361 (T_4245 this_4353, Ref self_89) {
    Component_CTCommon newestCmp_90;
    newestCmp_90 = (Component_CTCommon)head_Prelude((BITS32)0,
                                                    ((S_816)STATEOF(self_89))->myComponents_12);
    IsFocusable_CTCommon x_4355;
    x_4355 = newestCmp_90->l_Component_CTCommon_IsFocusable_CTCommon_CTCommon;
    Maybe_Prelude x_154;
    x_154 = x_4355->getNextFocusTarget_CTCommon(x_4355, 0);
    IsFocusable_CTCommon x_4356;
    x_4356 = this_4353->a_4138->l_Component_CTCommon_IsFocusable_CTCommon_CTCommon;
    TUP0 d_153;
    d_153 = x_4356->setNextFocusTarget_CTCommon(x_4356, x_154, 0);
    _Just_Prelude x_4357;
    NEW (_Just_Prelude, x_4357, WORDS(sizeof(struct _Just_Prelude)));
    x_4357->GCINFO = __GC___Just_Prelude+((4 * (BITS32)0));
    x_4357->a = (POLY)this_4353->a_4138;
    IsFocusable_CTCommon x_4358;
    x_4358 = newestCmp_90->l_Component_CTCommon_IsFocusable_CTCommon_CTCommon;
    TUP0 d_155;
    d_155 = x_4358->setNextFocusTarget_CTCommon(x_4358,
                                                (Maybe_Prelude)x_4357,
                                                0);
    _Just_Prelude x_4359;
    NEW (_Just_Prelude, x_4359, WORDS(sizeof(struct _Just_Prelude)));
    x_4359->GCINFO = __GC___Just_Prelude+((4 * (BITS32)0));
    x_4359->a = (POLY)newestCmp_90;
    IsFocusable_CTCommon x_4360;
    x_4360 = this_4353->a_4138->l_Component_CTCommon_IsFocusable_CTCommon_CTCommon;
    TUP0 d_156;
    d_156 = x_4360->setPreviousFocusTarget_CTCommon(x_4360,
                                                    (Maybe_Prelude)x_4359,
                                                    0);
    return (TUP0)0;
}
static TUP0 f_4371 (T_4246 this_4363, Ref self_91) {
    IsFocusable_CTCommon x_4365;
    x_4365 = this_4363->a_4138->l_Component_CTCommon_IsFocusable_CTCommon_CTCommon;
    TUP0 d_157;
    d_157 = x_4365->setNextFocusTarget_CTCommon(x_4365,
                                                ((S_816)STATEOF(self_91))->nextFocusTarget_20,
                                                0);
    IsFocusable_CTCommon x_4366;
    x_4366 = this_4363->focus_77;
    Maybe_Prelude x_159;
    x_159 = x_4366->getPreviousFocusTarget_CTCommon(x_4366, 0);
    IsFocusable_CTCommon x_4367;
    x_4367 = this_4363->a_4138->l_Component_CTCommon_IsFocusable_CTCommon_CTCommon;
    TUP0 d_158;
    d_158 = x_4367->setPreviousFocusTarget_CTCommon(x_4367, x_159, 0);
    switch ((WORD)isJust_Prelude((BITS32)0,
                                 ((S_816)STATEOF(self_91))->nextFocusTarget_20)) {
        case 1: { _Just_Prelude x_4368;
                  NEW (_Just_Prelude, x_4368, WORDS(sizeof(struct _Just_Prelude)));
                  x_4368->GCINFO = __GC___Just_Prelude+((4 * (BITS32)0));
                  x_4368->a = (POLY)this_4363->a_4138;
                  IsFocusable_CTCommon x_4369;
                  x_4369 = ((Component_CTCommon)fromJust_Prelude((BITS32)0,
                                                                 ((S_816)STATEOF(self_91))->nextFocusTarget_20))->l_Component_CTCommon_IsFocusable_CTCommon_CTCommon;
                  TUP0 d_161;
                  d_161 = x_4369->setPreviousFocusTarget_CTCommon(x_4369,
                                                                  (Maybe_Prelude)x_4368,
                                                                  0);
                  break;
                }
                break;
        case 0: break;
    }
    _Just_Prelude x_4370;
    NEW (_Just_Prelude, x_4370, WORDS(sizeof(struct _Just_Prelude)));
    x_4370->GCINFO = __GC___Just_Prelude+((4 * (BITS32)0));
    x_4370->a = (POLY)this_4363->a_4138;
    ((S_816)STATEOF(self_91))->nextFocusTarget_20 = (Maybe_Prelude)x_4370;
    return (TUP0)0;
}
static CLOS f_4373 (T_4244 this_4352) {
    switch ((WORD)_sym_689_Prelude/* > */(length_Prelude((BITS32)0,
                                                         ((S_816)STATEOF(this_4352->self_88))->myComponents_12),
                                          0)) {
        case 1: { T_4245 x_4362;
                  NEW (T_4245, x_4362, WORDS(sizeof(struct T_4245)));
                  x_4362->GCINFO = __GC__T_4245;
                  x_4362->Code = f_4361;
                  x_4362->a_4138 = this_4352->a_4138;
                  return (CLOS)x_4362;
                }
                break;
        case 0: { T_4246 x_4372;
                  NEW (T_4246, x_4372, WORDS(sizeof(struct T_4246)));
                  x_4372->GCINFO = __GC__T_4246;
                  x_4372->Code = f_4371;
                  x_4372->a_4138 = this_4352->a_4138;
                  x_4372->focus_77 = this_4352->focus_77;
                  return (CLOS)x_4372;
                }
                break;
    }
}
static TUP0 f_4377 (T_4243 this_4349,
                    Component_CTCommon a_4138,
                    Int a_4139) {
    Ref self_88;
    self_88 = (Ref)LOCK((OID)this_4349->self_10);
    CLOS x_4374;
    NEW (CLOS, x_4374, WORDS(sizeof(struct T_4244)));
    ((T_4244)x_4374)->GCINFO = __GC__T_4244;
    ((T_4244)x_4374)->Code = f_4373;
    ((T_4244)x_4374)->self_88 = self_88;
    ((T_4244)x_4374)->a_4138 = a_4138;
    ((T_4244)x_4374)->focus_77 = this_4349->focus_77;
    CLOS x_4375;
    x_4375 = ((CLOS(*)(CLOS))(x_4374->Code))(x_4374);
    TUP0 d_152;
    d_152 = ((TUP0(*)(CLOS, Ref))(x_4375->Code))(x_4375, self_88);
    CONS x_4376;
    NEW (CONS, x_4376, WORDS(sizeof(struct CONS)));
    x_4376->GCINFO = __GC__CONS+((5 * (BITS32)0));
    x_4376->hd = (POLY)a_4138;
    x_4376->tl = ((S_816)STATEOF(self_88))->myComponents_12;
    ((S_816)STATEOF(self_88))->myComponents_12 = (LIST)x_4376;
    switch ((WORD)((compareState_CTCommon(((S_816)STATEOF(self_88))->myState_11,
                                          (CocoaState_CTCommon)2) && isJust_Prelude((BITS32)0,
                                                                                    ((S_816)STATEOF(self_88))->appRef_17)))) {
        case 1: { Ref self_94;
                  self_94 = self_88;
                  TUP0 d_162;
                  d_162 = a_4138->init_CTCommon(a_4138,
                                                (App_CTCommon)fromJust_Prelude((BITS32)0,
                                                                               ((S_816)STATEOF(self_94))->appRef_17),
                                                0);
                  Msg d_163;
                  d_163 = containerAddComponent_CTContainer(this_4349->id_22,
                                                            a_4138->id_CTCommon,
                                                            Inherit,
                                                            Inherit);
                  UNLOCK((OID)self_88);
                  return (TUP0)0;
                }
                break;
        case 0: { Ref self_95;
                  self_95 = self_88;
                  UNLOCK((OID)self_88);
                  return (TUP0)0;
                }
                break;
    }
}
static Maybe_Prelude f_4383 (T_4247 this_4378,
                             CocoaEvent_CTCommon a_4142,
                             LIST a_4143,
                             Int a_4144) {
    switch (a_4142->Tag) {
        case 1: { MouseEventType_CTCommon x_167;
                  x_167 = ((_MouseEvent_CTCommon)a_4142)->a;
                  Ref self_98;
                  self_98 = (Ref)LOCK((OID)this_4378->self_10);
                  CLOS x_4382;
                  x_4382 = this_4378->mouseEventDispatcher_84;
                  Maybe_Prelude x_164;
                  x_164 = ((Maybe_Prelude(*)(CLOS, MouseEventType_CTCommon, LIST, Ref))(x_4382->Code))(x_4382,
                                                                                                       x_167,
                                                                                                       a_4143,
                                                                                                       self_98);
                  UNLOCK((OID)self_98);
                  return x_164;
                }
                break;
        default: RAISE(1);
    }
}
static TUP0 f_4396 (T_4249 this_4389,
                    Component_CTCommon a_4146,
                    Ref a_4147) {
    switch ((WORD)isNothing_Prelude((BITS32)0,
                                    ((S_816)STATEOF(a_4147))->currentEventHasBeenConsumedBy_19)) {
        case 1: { Ref self_108;
                  self_108 = a_4147;
                  HasPosition_CTCommon x_4392;
                  x_4392 = a_4146->l_Component_CTCommon_HasSize_CTCommon_CTCommon->l_HasSize_CTCommon_HasPosition_CTCommon_CTCommon;
                  Position_CTCommon cmpPos_109;
                  cmpPos_109 = x_4392->getPosition_CTCommon(x_4392, 0);
                  HasSize_CTCommon x_4393;
                  x_4393 = a_4146->l_Component_CTCommon_HasSize_CTCommon_CTCommon;
                  Size_CTCommon cmpSize_110;
                  cmpSize_110 = x_4393->getSize_CTCommon(x_4393, 0);
                  switch ((WORD)((inInterval_CTContainer((BITS32)1,
                                                         ordInt_Prelude,
                                                         numInt_Prelude,
                                                         (POLY)this_4389->pos2_104->x_CTCommon,
                                                         (POLY)cmpPos_109->x_CTCommon,
                                                         (POLY)cmpSize_110->width_CTCommon) && inInterval_CTContainer((BITS32)1,
                                                                                                                      ordInt_Prelude,
                                                                                                                      numInt_Prelude,
                                                                                                                      (POLY)this_4389->pos2_104->y_CTCommon,
                                                                                                                      (POLY)cmpPos_109->y_CTCommon,
                                                                                                                      (POLY)cmpSize_110->height_CTCommon)))) {
                      case 1: { _MouseEvent_CTCommon x_4394;
                                NEW (_MouseEvent_CTCommon, x_4394, WORDS(sizeof(struct _MouseEvent_CTCommon)));
                                x_4394->GCINFO = __GC___MouseEvent_CTCommon;
                                x_4394->Tag = 1;
                                x_4394->a = this_4389->eventInNewCoordsystem_105;
                                HandlesEvents_CTCommon x_4395;
                                x_4395 = a_4146->l_Component_CTCommon_HandlesEvents_CTCommon_CTCommon;
                                Maybe_Prelude x_172;
                                x_172 = x_4395->handleEvent_CTCommon(x_4395,
                                                                     (CocoaEvent_CTCommon)x_4394,
                                                                     this_4389->a_4150,
                                                                     0);
                                ((S_816)STATEOF(self_108))->currentEventHasBeenConsumedBy_19 = x_172;
                                break;
                              }
                              break;
                      case 0: break;
                  }
                  return (TUP0)0;
                }
                break;
        case 0: { Ref self_113;
                  self_113 = a_4147;
                  return (TUP0)0;
                }
                break;
    }
}
static Maybe_Prelude f_4399 (T_4248 this_4384,
                             MouseEventType_CTCommon a_4149,
                             LIST a_4150,
                             Ref a_4151) {
    ((S_816)STATEOF(a_4151))->currentEventHasBeenConsumedBy_19 = (Maybe_Prelude)1;
    Position_CTCommon pos_102;
    pos_102 = posget_54(a_4149);
    CLOS et_103;
    et_103 = getType_58(a_4149);
    Position_CTCommon pos2_104;
    NEW (Position_CTCommon, pos2_104, WORDS(sizeof(struct Position_CTCommon)));
    pos2_104->GCINFO = __GC__Position_CTCommon;
    pos2_104->x_CTCommon = _sym_621_Prelude/* - */(pos_102->x_CTCommon,
                                                   ((S_816)STATEOF(a_4151))->position_13->x_CTCommon);
    pos2_104->y_CTCommon = _sym_621_Prelude/* - */(pos_102->y_CTCommon,
                                                   ((S_816)STATEOF(a_4151))->position_13->y_CTCommon);
    CLOS x_4388;
    x_4388 = getType_58(a_4149);
    MouseEventType_CTCommon eventInNewCoordsystem_105;
    eventInNewCoordsystem_105 = ((MouseEventType_CTCommon(*)(CLOS, Position_CTCommon))(x_4388->Code))(x_4388,
                                                                                                      pos_102);
    T_4249 x_4397;
    NEW (T_4249, x_4397, WORDS(sizeof(struct T_4249)));
    x_4397->GCINFO = __GC__T_4249;
    x_4397->Code = f_4396;
    x_4397->eventInNewCoordsystem_105 = eventInNewCoordsystem_105;
    x_4397->pos2_104 = pos2_104;
    x_4397->a_4150 = a_4150;
    TUP0 d_170;
    d_170 = forallListUnit_Prelude((BITS32)4,
                                   (CLOS)x_4397,
                                   ((S_816)STATEOF(a_4151))->myComponents_12,
                                   a_4151);
    switch ((WORD)isNothing_Prelude((BITS32)0,
                                    ((S_816)STATEOF(a_4151))->currentEventHasBeenConsumedBy_19)) {
        case 1: { Bool x_174;
                  x_174 = dynamicHandleEvent_CTCommon((BITS32)0,
                                                      (POLY)a_4149,
                                                      ((S_816)STATEOF(a_4151))->mouseEventHandler_18,
                                                      a_4151);
                  _Just_Prelude x_4398;
                  NEW (_Just_Prelude, x_4398, WORDS(sizeof(struct _Just_Prelude)));
                  x_4398->GCINFO = __GC___Just_Prelude+((4 * (BITS32)0));
                  x_4398->a = (POLY)this_4384->this_86->l_Container_CTContainer_Component_CTCommon_CTContainer;
                  ((S_816)STATEOF(a_4151))->currentEventHasBeenConsumedBy_19 = boolToMaybe_CTCommon((BITS32)0,
                                                                                                    (Maybe_Prelude)x_4398,
                                                                                                    x_174);
                  break;
                }
                break;
        case 0: break;
    }
    Maybe_Prelude x_4148;
    x_4148 = ((S_816)STATEOF(a_4151))->currentEventHasBeenConsumedBy_19;
    return x_4148;
}
static TUP0 f_4407 (T_4251 this_4404,
                    Component_CTCommon a_4152,
                    Ref a_4153) {
    TUP0 d_178;
    d_178 = a_4152->init_CTCommon(a_4152, this_4404->a_4156, 0);
    Msg d_179;
    d_179 = containerAddComponent_CTContainer(this_4404->id_22,
                                              a_4152->id_CTCommon,
                                              Inherit,
                                              Inherit);
    return (TUP0)0;
}
static TUP0 f_4409 (T_4250 this_4400,
                    App_CTCommon a_4156,
                    Int a_4157) {
    Ref self_117;
    self_117 = (Ref)LOCK((OID)this_4400->self_10);
    ((S_816)STATEOF(self_117))->myState_11 = (CocoaState_CTCommon)2;
    _Just_Prelude x_4403;
    NEW (_Just_Prelude, x_4403, WORDS(sizeof(struct _Just_Prelude)));
    x_4403->GCINFO = __GC___Just_Prelude+((4 * (BITS32)0));
    x_4403->a = (POLY)a_4156;
    ((S_816)STATEOF(self_117))->appRef_17 = (Maybe_Prelude)x_4403;
    TUP0 d_175;
    d_175 = initContainer_CTContainer(this_4400->this_86, a_4156, 0);
    TUP0 d_176;
    d_176 = inithelper_59(this_4400->id_22, self_117);
    T_4251 x_4408;
    NEW (T_4251, x_4408, WORDS(sizeof(struct T_4251)));
    x_4408->GCINFO = __GC__T_4251;
    x_4408->Code = f_4407;
    x_4408->a_4156 = a_4156;
    x_4408->id_22 = this_4400->id_22;
    TUP0 d_177;
    d_177 = forallListUnit_Prelude((BITS32)4,
                                   (CLOS)x_4408,
                                   ((S_816)STATEOF(self_117))->myComponents_12,
                                   self_117);
    UNLOCK((OID)self_117);
    return (TUP0)0;
}
static Bool f_4413 (T_4253 this_4410, Int a_4159) {
    CLOS x_4412;
    x_4412 = this_4410->x_4158;
    return ((Bool(*)(CLOS, Int))(x_4412->Code))(x_4412, a_4159);
}
static Maybe_Prelude f_4417 (T_4253 this_4414, Int a_4161) {
    CLOS x_4416;
    x_4416 = this_4414->x_4160;
    return ((Maybe_Prelude(*)(CLOS, Int))(x_4416->Code))(x_4416,
                                                         a_4161);
}
static Maybe_Prelude f_4421 (T_4253 this_4418, Int a_4163) {
    CLOS x_4420;
    x_4420 = this_4418->x_4162;
    return ((Maybe_Prelude(*)(CLOS, Int))(x_4420->Code))(x_4420,
                                                         a_4163);
}
static TUP0 f_4426 (T_4253 this_4422, Bool a_4165, Int a_4166) {
    CLOS x_4425;
    x_4425 = this_4422->x_4164;
    return ((TUP0(*)(CLOS, Bool, Int))(x_4425->Code))(x_4425,
                                                      a_4165,
                                                      a_4166);
}
static TUP0 f_4431 (T_4253 this_4427,
                    Maybe_Prelude a_4168,
                    Int a_4169) {
    CLOS x_4430;
    x_4430 = this_4427->x_4167;
    return ((TUP0(*)(CLOS, Maybe_Prelude, Int))(x_4430->Code))(x_4430,
                                                               a_4168,
                                                               a_4169);
}
static TUP0 f_4436 (T_4253 this_4432,
                    Maybe_Prelude a_4171,
                    Int a_4172) {
    CLOS x_4435;
    x_4435 = this_4432->x_4170;
    return ((TUP0(*)(CLOS, Maybe_Prelude, Int))(x_4435->Code))(x_4435,
                                                               a_4171,
                                                               a_4172);
}
static Position_CTCommon f_4441 (T_4255 this_4438, Int a_4174) {
    CLOS x_4440;
    x_4440 = this_4438->x_4173;
    return ((Position_CTCommon(*)(CLOS, Int))(x_4440->Code))(x_4440,
                                                             a_4174);
}
static Msg f_4447 (T_4255 this_4442,
                   Position_CTCommon a_4176,
                   Time a_4177,
                   Time a_4178) {
    CLOS x_4446;
    x_4446 = this_4442->x_4175;
    return ((Msg(*)(CLOS, Position_CTCommon, Time, Time))(x_4446->Code))(x_4446,
                                                                         a_4176,
                                                                         a_4177,
                                                                         a_4178);
}
static Size_CTCommon f_4452 (T_4254 this_4449, Int a_4180) {
    CLOS x_4451;
    x_4451 = this_4449->x_4179;
    return ((Size_CTCommon(*)(CLOS, Int))(x_4451->Code))(x_4451,
                                                         a_4180);
}
static Msg f_4458 (T_4254 this_4453,
                   Size_CTCommon a_4182,
                   Time a_4183,
                   Time a_4184) {
    CLOS x_4457;
    x_4457 = this_4453->x_4181;
    return ((Msg(*)(CLOS, Size_CTCommon, Time, Time))(x_4457->Code))(x_4457,
                                                                     a_4182,
                                                                     a_4183,
                                                                     a_4184);
}
static Maybe_Prelude f_4465 (T_4256 this_4460,
                             CocoaEvent_CTCommon a_4186,
                             LIST a_4187,
                             Int a_4188) {
    CLOS x_4464;
    x_4464 = this_4460->x_4185;
    return ((Maybe_Prelude(*)(CLOS, CocoaEvent_CTCommon, LIST, Int))(x_4464->Code))(x_4464,
                                                                                    a_4186,
                                                                                    a_4187,
                                                                                    a_4188);
}
static TUP0 f_4470 (T_4252 this_4467, Int a_4190) {
    CLOS x_4469;
    x_4469 = this_4467->x_4189;
    return ((TUP0(*)(CLOS, Int))(x_4469->Code))(x_4469, a_4190);
}
static LIST f_4474 (T_4252 this_4471, Int a_4192) {
    CLOS x_4473;
    x_4473 = this_4471->x_4191;
    return ((LIST(*)(CLOS, Int))(x_4473->Code))(x_4473, a_4192);
}
static TUP0 f_4479 (T_4252 this_4475,
                    App_CTCommon a_4194,
                    Int a_4195) {
    CLOS x_4478;
    x_4478 = this_4475->x_4193;
    return ((TUP0(*)(CLOS, App_CTCommon, Int))(x_4478->Code))(x_4478,
                                                              a_4194,
                                                              a_4195);
}
static TUP0 f_4484 (T_4252 this_4480, LIST a_4197, Int a_4198) {
    CLOS x_4483;
    x_4483 = this_4480->x_4196;
    return ((TUP0(*)(CLOS, LIST, Int))(x_4483->Code))(x_4483,
                                                      a_4197,
                                                      a_4198);
}
static TUP0 f_4490 (T_4257 this_4486,
                    Component_CTCommon a_4200,
                    Int a_4201) {
    CLOS x_4489;
    x_4489 = this_4486->x_4199;
    return ((TUP0(*)(CLOS, Component_CTCommon, Int))(x_4489->Code))(x_4489,
                                                                    a_4200,
                                                                    a_4201);
}
static LIST f_4494 (T_4257 this_4491, Int a_4203) {
    CLOS x_4493;
    x_4493 = this_4491->x_4202;
    return ((LIST(*)(CLOS, Int))(x_4493->Code))(x_4493, a_4203);
}
static TUP0 f_4500 (T_4258 this_4496, CLOS a_4205, Int a_4206) {
    CLOS x_4499;
    x_4499 = this_4496->x_4204;
    return ((TUP0(*)(CLOS, CLOS, Int))(x_4499->Code))(x_4499,
                                                      a_4205,
                                                      a_4206);
}
static TUP0 f_4506 (T_4259 this_4502, CLOS a_4208, Int a_4209) {
    CLOS x_4505;
    x_4505 = this_4502->x_4207;
    return ((TUP0(*)(CLOS, CLOS, Int))(x_4505->Code))(x_4505,
                                                      a_4208,
                                                      a_4209);
}
static Color_CTCommon f_4511 (T_4260 this_4508, Int a_4211) {
    CLOS x_4510;
    x_4510 = this_4508->x_4210;
    return ((Color_CTCommon(*)(CLOS, Int))(x_4510->Code))(x_4510,
                                                          a_4211);
}
static Msg f_4517 (T_4260 this_4512,
                   Color_CTCommon a_4213,
                   Time a_4214,
                   Time a_4215) {
    CLOS x_4516;
    x_4516 = this_4512->x_4212;
    return ((Msg(*)(CLOS, Color_CTCommon, Time, Time))(x_4516->Code))(x_4516,
                                                                      a_4213,
                                                                      a_4214,
                                                                      a_4215);
}
static Maybe_Prelude f_4524 (T_4261 this_4519,
                             BITS32 a_4523,
                             POLY a_4218,
                             POLY a_4219,
                             Int a_4220) {
    Ref self_122;
    self_122 = (Ref)LOCK((OID)this_4519->self_10);
    UNLOCK((OID)self_122);
    return (Maybe_Prelude)1;
}
static MouseEventType_CTCommon f_4531 (CLOS this_4528,
                                       Position_CTCommon eta_1424) {
    _MousePressed_CTCommon x_4530;
    NEW (_MousePressed_CTCommon, x_4530, WORDS(sizeof(struct _MousePressed_CTCommon)));
    x_4530->GCINFO = __GC___MousePressed_CTCommon;
    x_4530->Tag = 2;
    x_4530->a = eta_1424;
    return (MouseEventType_CTCommon)x_4530;
}
static MouseEventType_CTCommon f_4536 (CLOS this_4533,
                                       Position_CTCommon eta_1428) {
    _MouseReleased_CTCommon x_4535;
    NEW (_MouseReleased_CTCommon, x_4535, WORDS(sizeof(struct _MouseReleased_CTCommon)));
    x_4535->GCINFO = __GC___MouseReleased_CTCommon;
    x_4535->Tag = 1;
    x_4535->a = eta_1428;
    return (MouseEventType_CTCommon)x_4535;
}
static MouseEventType_CTCommon f_4541 (CLOS this_4538,
                                       Position_CTCommon eta_1432) {
    _MouseClicked_CTCommon x_4540;
    NEW (_MouseClicked_CTCommon, x_4540, WORDS(sizeof(struct _MouseClicked_CTCommon)));
    x_4540->GCINFO = __GC___MouseClicked_CTCommon;
    x_4540->Tag = 3;
    x_4540->a = eta_1432;
    return (MouseEventType_CTCommon)x_4540;
}
 
void _init_CTContainer () {
    static int INITIALIZED = 0;
    if (!INITIALIZED) {
        _init_Prelude();
        _init_POSIX();
        _init_CTCommon();
        INITIALIZED = 1;
    }
}
 

