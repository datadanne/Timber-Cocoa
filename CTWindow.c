#include "CTWindow.h"
#include "CTWindow.extern.c"
 
struct S_582;
typedef struct S_582 *S_582;
struct T_3718;
typedef struct T_3718 *T_3718;
struct T_3717;
typedef struct T_3717 *T_3717;
struct T_3716;
typedef struct T_3716 *T_3716;
struct T_3715;
typedef struct T_3715 *T_3715;
struct T_3714;
typedef struct T_3714 *T_3714;
struct T_3713;
typedef struct T_3713 *T_3713;
struct T_3712;
typedef struct T_3712 *T_3712;
struct T_3711;
typedef struct T_3711 *T_3711;
struct T_3710;
typedef struct T_3710 *T_3710;
struct T_3709;
typedef struct T_3709 *T_3709;
struct T_3708;
typedef struct T_3708 *T_3708;
struct T_3707;
typedef struct T_3707 *T_3707;
struct T_3706;
typedef struct T_3706 *T_3706;
struct T_3705;
typedef struct T_3705 *T_3705;
struct T_3704;
typedef struct T_3704 *T_3704;
struct T_3703;
typedef struct T_3703 *T_3703;
struct T_3702;
typedef struct T_3702 *T_3702;
struct T_3701;
typedef struct T_3701 *T_3701;
struct T_3700;
typedef struct T_3700 *T_3700;
struct T_3699;
typedef struct T_3699 *T_3699;
struct T_3698;
typedef struct T_3698 *T_3698;
struct T_3697;
typedef struct T_3697 *T_3697;
struct T_3696;
typedef struct T_3696 *T_3696;
struct T_3695;
typedef struct T_3695 *T_3695;
 
struct S_582 {
    POLY GCINFO;
    Maybe_Prelude keyListener_10;
    Maybe_Prelude windowListener_11;
    Int nr_12;
    CocoaState_CTCommon state_13;
    Bool isVisible_14;
    Maybe_Prelude currentFocus_15;
    Maybe_Prelude nextFocus_16;
    Maybe_Prelude previousFocus_17;
    Bool consumed_18;
    CocoaWindow_CTCommon this_19;
};
struct T_3718 {
    POLY GCINFO;
    TUP0 (*installMouseListener_CTCommon) (T_3718, CLOS, Int);
    CLOS x_3675;
};
struct T_3717 {
    POLY GCINFO;
    Maybe_Prelude (*handleEvent_CTCommon) (T_3717,
                                           CocoaEvent_CTCommon,
                                           LIST,
                                           Int);
    CLOS x_3668;
};
struct T_3716 {
    POLY GCINFO;
    HandlesEvents_CTCommon l_HandlesWindowEvents_CTCommon_HandlesEvents_CTCommon_CTCommon;
    TUP0 (*installWindowListener_CTCommon) (T_3716, CLOS, Int);
    CLOS x_3672;
};
struct T_3715 {
    POLY GCINFO;
    TUP0 (*installKeyListener_CTCommon) (T_3715, CLOS, Int);
    CLOS x_3665;
};
struct T_3714 {
    POLY GCINFO;
    TUP0 (*addComponent_CTCommon) (T_3714, Component_CTCommon, Int);
    LIST (*getComponents_CTCommon) (T_3714, Int);
    CLOS x_3663;
    CLOS x_3660;
};
struct T_3713 {
    POLY GCINFO;
    ContainsComponents_CTCommon l_CocoaWindow_CTCommon_ContainsComponents_CTCommon_CTCommon;
    HandlesKeyEvents_CTCommon l_CocoaWindow_CTCommon_HandlesKeyEvents_CTCommon_CTCommon;
    HandlesWindowEvents_CTCommon l_CocoaWindow_CTCommon_HandlesWindowEvents_CTCommon_CTCommon;
    HandlesMouseEvents_CTCommon l_CocoaWindow_CTCommon_HandlesMouseEvents_CTCommon_CTCommon;
    CocoaID_CTCommon windowId_CTCommon;
    Int (*getId_CTCommon) (T_3713, Int);
    TUP0 (*initWindow_CTCommon) (T_3713, App_CTCommon, Int);
    TUP0 (*destroyWindow_CTCommon) (T_3713, Int);
    Bool (*hide_CTCommon) (T_3713, Int);
    Bool (*setVisible_CTCommon) (T_3713, Int);
    Msg (*setFocus_CTCommon) (T_3713, Component_CTCommon, Time, Time);
    CLOS x_3690;
    CLOS x_3684;
    CLOS x_3682;
    CLOS x_3680;
    CLOS x_3678;
    CocoaID_CTCommon windowId_20;
    Ref self_9;
};
struct T_3712 {
    POLY GCINFO;
    Bool (*Code) (T_3712, Int);
    CocoaID_CTCommon windowId_20;
    Ref self_9;
};
struct T_3711 {
    POLY GCINFO;
    TUP0 (*Code) (T_3711, CLOS, Int);
    Container_CTContainer rootContainer_21;
};
struct T_3710 {
    POLY GCINFO;
    TUP0 (*Code) (T_3710, CLOS, Int);
    Ref self_9;
};
struct T_3709 {
    POLY GCINFO;
    TUP0 (*Code) (T_3709, CLOS, Int);
    Ref self_9;
};
struct T_3708 {
    POLY GCINFO;
    TUP0 (*Code) (T_3708, Ref);
    Maybe_Prelude cmp_83;
    CocoaID_CTCommon windowId_20;
    Ref self_9;
};
struct T_3707 {
    POLY GCINFO;
    CLOS (*Code) (T_3707);
    Maybe_Prelude cmp_83;
    CocoaID_CTCommon windowId_20;
    Ref self_9;
};
struct T_3706 {
    POLY GCINFO;
    CLOS (*Code) (T_3706);
    Ref self_58;
    Container_CTContainer rootContainer_21;
};
struct T_3705 {
    POLY GCINFO;
    TUP0 (*Code) (T_3705, Ref);
    Container_CTContainer rootContainer_21;
};
struct T_3704 {
    POLY GCINFO;
    CLOS (*Code) (T_3704);
    Ref self_46;
    Container_CTContainer rootContainer_21;
};
struct T_3703 {
    POLY GCINFO;
    TUP0 (*Code) (T_3703, Ref);
    Container_CTContainer rootContainer_21;
    CocoaID_CTCommon windowId_20;
    Ref self_9;
};
struct T_3702 {
    POLY GCINFO;
    CLOS (*Code) (T_3702);
    CocoaKey_CTCommon x_137;
    Container_CTContainer rootContainer_21;
    CocoaID_CTCommon windowId_20;
    Ref self_9;
};
struct T_3701 {
    POLY GCINFO;
    Maybe_Prelude (*Code) (T_3701, CocoaEvent_CTCommon, LIST, Int);
    Container_CTContainer rootContainer_21;
    CocoaID_CTCommon windowId_20;
    Ref self_9;
};
struct T_3700 {
    POLY GCINFO;
    TUP0 (*Code) (T_3700);
    AbsTime baseline;
    AbsTime deadline;
    Msg next;
    Component_CTCommon cmp_34;
    CocoaID_CTCommon windowId_20;
    Ref self_9;
};
struct T_3699 {
    POLY GCINFO;
    TUP0 (*Code) (T_3699, Int);
    Container_CTContainer rootContainer_21;
    CocoaID_CTCommon windowId_20;
    Ref self_9;
};
struct T_3698 {
    POLY GCINFO;
    TUP0 (*Code) (T_3698, App_CTCommon, Int);
    Container_CTContainer rootContainer_21;
    Ref self_9;
};
struct T_3697 {
    POLY GCINFO;
    Int (*Code) (T_3697, Int);
    Ref self_9;
};
struct T_3696 {
    POLY GCINFO;
    LIST (*Code) (T_3696, Int);
    Container_CTContainer rootContainer_21;
};
struct T_3695 {
    POLY GCINFO;
    TUP0 (*Code) (T_3695, Component_CTCommon, Int);
    Container_CTContainer rootContainer_21;
};
 
static WORD __GC__S_582[];
static WORD __GC__T_3718[];
static WORD __GC__T_3717[];
static WORD __GC__T_3716[];
static WORD __GC__T_3715[];
static WORD __GC__T_3714[];
static WORD __GC__T_3713[];
static WORD __GC__T_3712[];
static WORD __GC__T_3711[];
static WORD __GC__T_3710[];
static WORD __GC__T_3709[];
static WORD __GC__T_3708[];
static WORD __GC__T_3707[];
static WORD __GC__T_3706[];
static WORD __GC__T_3705[];
static WORD __GC__T_3704[];
static WORD __GC__T_3703[];
static WORD __GC__T_3702[];
static WORD __GC__T_3701[];
static WORD __GC__T_3700[];
static WORD __GC__T_3699[];
static WORD __GC__T_3698[];
static WORD __GC__T_3697[];
static WORD __GC__T_3696[];
static WORD __GC__T_3695[];
static TUP0 f_3694 (Ref self_76);
static Msg setFocus_33 (CocoaID_CTCommon windowId_20,
                        Ref self_9,
                        Component_CTCommon cmp_34,
                        Time a_3618,
                        Time a_3619);
static TUP0 f_3725 (T_3695 this_3721,
                    Component_CTCommon a_3601,
                    Int a_3602);
static LIST f_3729 (T_3696 this_3726, Int a_3604);
static Int f_3732 (T_3697 this_3730, Int a_3608);
static TUP0 f_3737 (T_3698 this_3733,
                    App_CTCommon a_3611,
                    Int a_3612);
static TUP0 f_3741 (T_3699 this_3738, Int a_3615);
static TUP0 f_3758 (T_3705 this_3754, Ref self_51);
static TUP0 f_3762 (CLOS this_3760, Ref self_54);
static CLOS f_3764 (T_3704 this_3753);
static TUP0 f_3768 (T_3703 this_3749, Ref self_46);
static TUP0 f_3779 (T_3705 this_3775, Ref self_63);
static TUP0 f_3783 (CLOS this_3781, Ref self_66);
static CLOS f_3785 (T_3706 this_3774);
static TUP0 f_3789 (T_3703 this_3770, Ref self_58);
static TUP0 f_3793 (CLOS this_3791, Ref self_70);
static CLOS f_3795 (T_3702 this_3748);
static TUP0 f_3804 (T_3708 this_3801, Ref self_84);
static TUP0 f_3808 (CLOS this_3806, Ref self_87);
static CLOS f_3810 (T_3707 this_3800);
static Maybe_Prelude f_3813 (T_3701 this_3742,
                             CocoaEvent_CTCommon a_3629,
                             LIST a_3630,
                             Int a_3631);
static TUP0 f_3818 (T_3709 this_3814, CLOS a_3636, Int a_3637);
static TUP0 f_3823 (T_3710 this_3819, CLOS a_3644, Int a_3645);
static TUP0 f_3828 (T_3711 this_3824, CLOS a_3650, Int a_3651);
static Bool f_3831 (T_3712 this_3829, Int a_3656);
static Bool f_3834 (T_3712 this_3832, Int a_3659);
static TUP0 f_3839 (T_3714 this_3835,
                    Component_CTCommon a_3661,
                    Int a_3662);
static LIST f_3843 (T_3714 this_3840, Int a_3664);
static TUP0 f_3849 (T_3715 this_3845, CLOS a_3666, Int a_3667);
static Maybe_Prelude f_3856 (T_3717 this_3851,
                             CocoaEvent_CTCommon a_3669,
                             LIST a_3670,
                             Int a_3671);
static TUP0 f_3862 (T_3716 this_3858, CLOS a_3673, Int a_3674);
static TUP0 f_3868 (T_3718 this_3864, CLOS a_3676, Int a_3677);
static TUP0 f_3873 (T_3713 this_3870, Int a_3679);
static Int f_3877 (T_3713 this_3874, Int a_3681);
static Bool f_3881 (T_3713 this_3878, Int a_3683);
static TUP0 f_3886 (T_3713 this_3882,
                    App_CTCommon a_3685,
                    Int a_3686);
static Msg f_3891 (T_3713 this_3887,
                   Component_CTCommon a_3687,
                   Time a_3688,
                   Time a_3689);
static Bool f_3895 (T_3713 this_3892, Int a_3691);
static TUP0 f_3899 (T_3700 this_3897);
 
static WORD __GC__S_582[] = {WORDS(sizeof(struct S_582)),
                             0,
                             WORDS(offsetof(struct S_582, keyListener_10)),
                             WORDS(offsetof(struct S_582, windowListener_11)),
                             WORDS(offsetof(struct S_582, state_13)),
                             WORDS(offsetof(struct S_582, currentFocus_15)),
                             WORDS(offsetof(struct S_582, nextFocus_16)),
                             WORDS(offsetof(struct S_582, previousFocus_17)),
                             WORDS(offsetof(struct S_582, this_19)),
                             0};
static WORD __GC__T_3718[] = {WORDS(sizeof(struct T_3718)),
                              0,
                              WORDS(offsetof(struct T_3718, x_3675)),
                              0};
static WORD __GC__T_3717[] = {WORDS(sizeof(struct T_3717)),
                              0,
                              WORDS(offsetof(struct T_3717, x_3668)),
                              0};
static WORD __GC__T_3716[] = {WORDS(sizeof(struct T_3716)),
                              0,
                              WORDS(offsetof(struct T_3716, l_HandlesWindowEvents_CTCommon_HandlesEvents_CTCommon_CTCommon)),
                              WORDS(offsetof(struct T_3716, x_3672)),
                              0};
static WORD __GC__T_3715[] = {WORDS(sizeof(struct T_3715)),
                              0,
                              WORDS(offsetof(struct T_3715, x_3665)),
                              0};
static WORD __GC__T_3714[] = {WORDS(sizeof(struct T_3714)),
                              0,
                              WORDS(offsetof(struct T_3714, x_3663)),
                              WORDS(offsetof(struct T_3714, x_3660)),
                              0};
static WORD __GC__T_3713[] = {WORDS(sizeof(struct T_3713)),
                              0,
                              WORDS(offsetof(struct T_3713, l_CocoaWindow_CTCommon_ContainsComponents_CTCommon_CTCommon)),
                              WORDS(offsetof(struct T_3713, l_CocoaWindow_CTCommon_HandlesKeyEvents_CTCommon_CTCommon)),
                              WORDS(offsetof(struct T_3713, l_CocoaWindow_CTCommon_HandlesWindowEvents_CTCommon_CTCommon)),
                              WORDS(offsetof(struct T_3713, l_CocoaWindow_CTCommon_HandlesMouseEvents_CTCommon_CTCommon)),
                              WORDS(offsetof(struct T_3713, windowId_CTCommon)),
                              WORDS(offsetof(struct T_3713, x_3690)),
                              WORDS(offsetof(struct T_3713, x_3684)),
                              WORDS(offsetof(struct T_3713, x_3682)),
                              WORDS(offsetof(struct T_3713, x_3680)),
                              WORDS(offsetof(struct T_3713, x_3678)),
                              WORDS(offsetof(struct T_3713, windowId_20)),
                              WORDS(offsetof(struct T_3713, self_9)),
                              0};
static WORD __GC__T_3712[] = {WORDS(sizeof(struct T_3712)),
                              0,
                              WORDS(offsetof(struct T_3712, windowId_20)),
                              WORDS(offsetof(struct T_3712, self_9)),
                              0};
static WORD __GC__T_3711[] = {WORDS(sizeof(struct T_3711)),
                              0,
                              WORDS(offsetof(struct T_3711, rootContainer_21)),
                              0};
static WORD __GC__T_3710[] = {WORDS(sizeof(struct T_3710)),
                              0,
                              WORDS(offsetof(struct T_3710, self_9)),
                              0};
static WORD __GC__T_3709[] = {WORDS(sizeof(struct T_3709)),
                              0,
                              WORDS(offsetof(struct T_3709, self_9)),
                              0};
static WORD __GC__T_3708[] = {WORDS(sizeof(struct T_3708)),
                              0,
                              WORDS(offsetof(struct T_3708, cmp_83)),
                              WORDS(offsetof(struct T_3708, windowId_20)),
                              WORDS(offsetof(struct T_3708, self_9)),
                              0};
static WORD __GC__T_3707[] = {WORDS(sizeof(struct T_3707)),
                              0,
                              WORDS(offsetof(struct T_3707, cmp_83)),
                              WORDS(offsetof(struct T_3707, windowId_20)),
                              WORDS(offsetof(struct T_3707, self_9)),
                              0};
static WORD __GC__T_3706[] = {WORDS(sizeof(struct T_3706)),
                              0,
                              WORDS(offsetof(struct T_3706, self_58)),
                              WORDS(offsetof(struct T_3706, rootContainer_21)),
                              0};
static WORD __GC__T_3705[] = {WORDS(sizeof(struct T_3705)),
                              0,
                              WORDS(offsetof(struct T_3705, rootContainer_21)),
                              0};
static WORD __GC__T_3704[] = {WORDS(sizeof(struct T_3704)),
                              0,
                              WORDS(offsetof(struct T_3704, self_46)),
                              WORDS(offsetof(struct T_3704, rootContainer_21)),
                              0};
static WORD __GC__T_3703[] = {WORDS(sizeof(struct T_3703)),
                              0,
                              WORDS(offsetof(struct T_3703, rootContainer_21)),
                              WORDS(offsetof(struct T_3703, windowId_20)),
                              WORDS(offsetof(struct T_3703, self_9)),
                              0};
static WORD __GC__T_3702[] = {WORDS(sizeof(struct T_3702)),
                              0,
                              WORDS(offsetof(struct T_3702, x_137)),
                              WORDS(offsetof(struct T_3702, rootContainer_21)),
                              WORDS(offsetof(struct T_3702, windowId_20)),
                              WORDS(offsetof(struct T_3702, self_9)),
                              0};
static WORD __GC__T_3701[] = {WORDS(sizeof(struct T_3701)),
                              0,
                              WORDS(offsetof(struct T_3701, rootContainer_21)),
                              WORDS(offsetof(struct T_3701, windowId_20)),
                              WORDS(offsetof(struct T_3701, self_9)),
                              0};
static WORD __GC__T_3700[] = {WORDS(sizeof(struct T_3700)),
                              0,
                              WORDS(offsetof(struct T_3700, cmp_34)),
                              WORDS(offsetof(struct T_3700, windowId_20)),
                              WORDS(offsetof(struct T_3700, self_9)),
                              0};
static WORD __GC__T_3699[] = {WORDS(sizeof(struct T_3699)),
                              0,
                              WORDS(offsetof(struct T_3699, rootContainer_21)),
                              WORDS(offsetof(struct T_3699, windowId_20)),
                              WORDS(offsetof(struct T_3699, self_9)),
                              0};
static WORD __GC__T_3698[] = {WORDS(sizeof(struct T_3698)),
                              0,
                              WORDS(offsetof(struct T_3698, rootContainer_21)),
                              WORDS(offsetof(struct T_3698, self_9)),
                              0};
static WORD __GC__T_3697[] = {WORDS(sizeof(struct T_3697)),
                              0,
                              WORDS(offsetof(struct T_3697, self_9)),
                              0};
static WORD __GC__T_3696[] = {WORDS(sizeof(struct T_3696)),
                              0,
                              WORDS(offsetof(struct T_3696, rootContainer_21)),
                              0};
static WORD __GC__T_3695[] = {WORDS(sizeof(struct T_3695)),
                              0,
                              WORDS(offsetof(struct T_3695, rootContainer_21)),
                              0};
CocoaWindow_CTCommon mkWindow_CTWindow (BITS32 a_3719,
                                        POLY env_8,
                                        Int d_3693) {
    Ref self_9;
    NEW (Ref, self_9, WORDS(sizeof(struct Ref))+
                      WORDS(sizeof(struct S_582)));
    INITREF(self_9);
    ((S_582)STATEOF(self_9))->GCINFO = __GC__S_582;
    CocoaID_CTCommon windowId_20;
    windowId_20 = mkCocoaID_CTCommon(0);
    Container_CTContainer rootContainer_21;
    rootContainer_21 = mkContainer_CTContainer(a_3719, env_8, 0);
    CLOS addComponent_22;
    NEW (CLOS, addComponent_22, WORDS(sizeof(struct T_3695)));
    ((T_3695)addComponent_22)->GCINFO = __GC__T_3695;
    ((T_3695)addComponent_22)->Code = f_3725;
    ((T_3695)addComponent_22)->rootContainer_21 = rootContainer_21;
    CLOS getComponents_23;
    NEW (CLOS, getComponents_23, WORDS(sizeof(struct T_3696)));
    ((T_3696)getComponents_23)->GCINFO = __GC__T_3696;
    ((T_3696)getComponents_23)->Code = f_3729;
    ((T_3696)getComponents_23)->rootContainer_21 = rootContainer_21;
    CLOS getId_24;
    NEW (CLOS, getId_24, WORDS(sizeof(struct T_3697)));
    ((T_3697)getId_24)->GCINFO = __GC__T_3697;
    ((T_3697)getId_24)->Code = f_3732;
    ((T_3697)getId_24)->self_9 = self_9;
    CLOS initWindow_26;
    NEW (CLOS, initWindow_26, WORDS(sizeof(struct T_3698)));
    ((T_3698)initWindow_26)->GCINFO = __GC__T_3698;
    ((T_3698)initWindow_26)->Code = f_3737;
    ((T_3698)initWindow_26)->rootContainer_21 = rootContainer_21;
    ((T_3698)initWindow_26)->self_9 = self_9;
    CLOS destroyWindow_29;
    NEW (CLOS, destroyWindow_29, WORDS(sizeof(struct T_3699)));
    ((T_3699)destroyWindow_29)->GCINFO = __GC__T_3699;
    ((T_3699)destroyWindow_29)->Code = f_3741;
    ((T_3699)destroyWindow_29)->rootContainer_21 = rootContainer_21;
    ((T_3699)destroyWindow_29)->windowId_20 = windowId_20;
    ((T_3699)destroyWindow_29)->self_9 = self_9;
    CLOS handleEvent_38;
    NEW (CLOS, handleEvent_38, WORDS(sizeof(struct T_3701)));
    ((T_3701)handleEvent_38)->GCINFO = __GC__T_3701;
    ((T_3701)handleEvent_38)->Code = f_3813;
    ((T_3701)handleEvent_38)->rootContainer_21 = rootContainer_21;
    ((T_3701)handleEvent_38)->windowId_20 = windowId_20;
    ((T_3701)handleEvent_38)->self_9 = self_9;
    CLOS installWindowListener_88;
    NEW (CLOS, installWindowListener_88, WORDS(sizeof(struct T_3709)));
    ((T_3709)installWindowListener_88)->GCINFO = __GC__T_3709;
    ((T_3709)installWindowListener_88)->Code = f_3818;
    ((T_3709)installWindowListener_88)->self_9 = self_9;
    CLOS installKeyListener_91;
    NEW (CLOS, installKeyListener_91, WORDS(sizeof(struct T_3710)));
    ((T_3710)installKeyListener_91)->GCINFO = __GC__T_3710;
    ((T_3710)installKeyListener_91)->Code = f_3823;
    ((T_3710)installKeyListener_91)->self_9 = self_9;
    CLOS installMouseListener_94;
    NEW (CLOS, installMouseListener_94, WORDS(sizeof(struct T_3711)));
    ((T_3711)installMouseListener_94)->GCINFO = __GC__T_3711;
    ((T_3711)installMouseListener_94)->Code = f_3828;
    ((T_3711)installMouseListener_94)->rootContainer_21 = rootContainer_21;
    CLOS hide_95;
    NEW (CLOS, hide_95, WORDS(sizeof(struct T_3712)));
    ((T_3712)hide_95)->GCINFO = __GC__T_3712;
    ((T_3712)hide_95)->Code = f_3831;
    ((T_3712)hide_95)->windowId_20 = windowId_20;
    ((T_3712)hide_95)->self_9 = self_9;
    CLOS setVisible_99;
    NEW (CLOS, setVisible_99, WORDS(sizeof(struct T_3712)));
    ((T_3712)setVisible_99)->GCINFO = __GC__T_3712;
    ((T_3712)setVisible_99)->Code = f_3834;
    ((T_3712)setVisible_99)->windowId_20 = windowId_20;
    ((T_3712)setVisible_99)->self_9 = self_9;
    ((S_582)STATEOF(self_9))->keyListener_10 = (Maybe_Prelude)1;
    ((S_582)STATEOF(self_9))->windowListener_11 = (Maybe_Prelude)1;
    ((S_582)STATEOF(self_9))->nr_12 = 0;
    ((S_582)STATEOF(self_9))->state_13 = (CocoaState_CTCommon)1;
    ((S_582)STATEOF(self_9))->isVisible_14 = (Bool)0;
    ((S_582)STATEOF(self_9))->currentFocus_15 = (Maybe_Prelude)1;
    ((S_582)STATEOF(self_9))->nextFocus_16 = (Maybe_Prelude)1;
    ((S_582)STATEOF(self_9))->previousFocus_17 = (Maybe_Prelude)1;
    ((S_582)STATEOF(self_9))->consumed_18 = (Bool)0;
    CLOS x_3660;
    x_3660 = addComponent_22;
    CLOS x_3663;
    x_3663 = getComponents_23;
    CLOS x_3665;
    x_3665 = installKeyListener_91;
    CLOS x_3668;
    x_3668 = handleEvent_38;
    CLOS x_3672;
    x_3672 = installWindowListener_88;
    CLOS x_3675;
    x_3675 = installMouseListener_94;
    CLOS x_3678;
    x_3678 = destroyWindow_29;
    CLOS x_3680;
    x_3680 = getId_24;
    CLOS x_3682;
    x_3682 = hide_95;
    CLOS x_3684;
    x_3684 = initWindow_26;
    CLOS x_3690;
    x_3690 = setVisible_99;
    T_3714 x_3844;
    NEW (T_3714, x_3844, WORDS(sizeof(struct T_3714)));
    x_3844->GCINFO = __GC__T_3714;
    x_3844->addComponent_CTCommon = f_3839;
    x_3844->getComponents_CTCommon = f_3843;
    x_3844->x_3663 = x_3663;
    x_3844->x_3660 = x_3660;
    T_3715 x_3850;
    NEW (T_3715, x_3850, WORDS(sizeof(struct T_3715)));
    x_3850->GCINFO = __GC__T_3715;
    x_3850->installKeyListener_CTCommon = f_3849;
    x_3850->x_3665 = x_3665;
    T_3717 x_3857;
    NEW (T_3717, x_3857, WORDS(sizeof(struct T_3717)));
    x_3857->GCINFO = __GC__T_3717;
    x_3857->handleEvent_CTCommon = f_3856;
    x_3857->x_3668 = x_3668;
    T_3716 x_3863;
    NEW (T_3716, x_3863, WORDS(sizeof(struct T_3716)));
    x_3863->GCINFO = __GC__T_3716;
    x_3863->l_HandlesWindowEvents_CTCommon_HandlesEvents_CTCommon_CTCommon = (HandlesEvents_CTCommon)x_3857;
    x_3863->installWindowListener_CTCommon = f_3862;
    x_3863->x_3672 = x_3672;
    T_3718 x_3869;
    NEW (T_3718, x_3869, WORDS(sizeof(struct T_3718)));
    x_3869->GCINFO = __GC__T_3718;
    x_3869->installMouseListener_CTCommon = f_3868;
    x_3869->x_3675 = x_3675;
    T_3713 x_3896;
    NEW (T_3713, x_3896, WORDS(sizeof(struct T_3713)));
    x_3896->GCINFO = __GC__T_3713;
    x_3896->l_CocoaWindow_CTCommon_ContainsComponents_CTCommon_CTCommon = (ContainsComponents_CTCommon)x_3844;
    x_3896->l_CocoaWindow_CTCommon_HandlesKeyEvents_CTCommon_CTCommon = (HandlesKeyEvents_CTCommon)x_3850;
    x_3896->l_CocoaWindow_CTCommon_HandlesWindowEvents_CTCommon_CTCommon = (HandlesWindowEvents_CTCommon)x_3863;
    x_3896->l_CocoaWindow_CTCommon_HandlesMouseEvents_CTCommon_CTCommon = (HandlesMouseEvents_CTCommon)x_3869;
    x_3896->windowId_CTCommon = windowId_20;
    x_3896->destroyWindow_CTCommon = f_3873;
    x_3896->getId_CTCommon = f_3877;
    x_3896->hide_CTCommon = f_3881;
    x_3896->initWindow_CTCommon = f_3886;
    x_3896->setFocus_CTCommon = f_3891;
    x_3896->setVisible_CTCommon = f_3895;
    x_3896->x_3690 = x_3690;
    x_3896->x_3684 = x_3684;
    x_3896->x_3682 = x_3682;
    x_3896->x_3680 = x_3680;
    x_3896->x_3678 = x_3678;
    x_3896->windowId_20 = windowId_20;
    x_3896->self_9 = self_9;
    ((S_582)STATEOF(self_9))->this_19 = (CocoaWindow_CTCommon)x_3896;
    CocoaWindow_CTCommon x_3692;
    x_3692 = ((S_582)STATEOF(self_9))->this_19;
    return x_3692;
}
static TUP0 f_3694 (Ref self_76) {
    switch ((WORD)compareState_CTCommon(((S_582)STATEOF(self_76))->state_13,
                                        (CocoaState_CTCommon)2)) {
        case 1: { ((S_582)STATEOF(self_76))->state_13 = (CocoaState_CTCommon)1;
                  break;
                }
                break;
        case 0: break;
    }
    return (TUP0)0;
}
static Msg setFocus_33 (CocoaID_CTCommon windowId_20,
                        Ref self_9,
                        Component_CTCommon cmp_34,
                        Time a_3618,
                        Time a_3619) {
    Msg x_3620;
    NEW (Msg, x_3620, WORDS(sizeof(struct T_3700)));
    ((T_3700)x_3620)->GCINFO = __GC__T_3700;
    ((T_3700)x_3620)->Code = f_3899;
    ((T_3700)x_3620)->cmp_34 = cmp_34;
    ((T_3700)x_3620)->windowId_20 = windowId_20;
    ((T_3700)x_3620)->self_9 = self_9;
    return (Msg)ASYNC(x_3620, a_3618, a_3619);
}
static TUP0 f_3725 (T_3695 this_3721,
                    Component_CTCommon a_3601,
                    Int a_3602) {
    ContainsComponents_CTCommon x_3724;
    x_3724 = this_3721->rootContainer_21->l_Container_CTContainer_ContainsComponents_CTCommon_CTContainer;
    return x_3724->addComponent_CTCommon(x_3724, a_3601, a_3602);
}
static LIST f_3729 (T_3696 this_3726, Int a_3604) {
    ContainsComponents_CTCommon x_3728;
    x_3728 = this_3726->rootContainer_21->l_Container_CTContainer_ContainsComponents_CTCommon_CTContainer;
    return x_3728->getComponents_CTCommon(x_3728, a_3604);
}
static Int f_3732 (T_3697 this_3730, Int a_3608) {
    Ref self_25;
    self_25 = (Ref)LOCK((OID)this_3730->self_9);
    Int x_3605;
    x_3605 = ((S_582)STATEOF(self_25))->nr_12;
    UNLOCK((OID)self_25);
    return x_3605;
}
static TUP0 f_3737 (T_3698 this_3733,
                    App_CTCommon a_3611,
                    Int a_3612) {
    Ref self_28;
    self_28 = (Ref)LOCK((OID)this_3733->self_9);
    Int x_103;
    x_103 = initCocoaWindow_CTWindow(((S_582)STATEOF(self_28))->this_19,
                                     a_3611,
                                     0);
    ((S_582)STATEOF(self_28))->nr_12 = x_103;
    Component_CTCommon x_3736;
    x_3736 = this_3733->rootContainer_21->l_Container_CTContainer_Component_CTCommon_CTContainer;
    TUP0 d_104;
    d_104 = x_3736->init_CTCommon(x_3736, a_3611, 0);
    ((S_582)STATEOF(self_28))->state_13 = (CocoaState_CTCommon)2;
    ((S_582)STATEOF(self_28))->isVisible_14 = (Bool)1;
    TUP0 d_105;
    d_105 = setContentViewForWindow_CTWindow(((S_582)STATEOF(self_28))->this_19,
                                             this_3733->rootContainer_21->l_Container_CTContainer_Component_CTCommon_CTContainer->id_CTCommon,
                                             0);
    UNLOCK((OID)self_28);
    return (TUP0)0;
}
static TUP0 f_3741 (T_3699 this_3738, Int a_3615) {
    Ref self_30;
    self_30 = (Ref)LOCK((OID)this_3738->self_9);
    switch ((WORD)compareState_CTCommon(((S_582)STATEOF(self_30))->state_13,
                                        (CocoaState_CTCommon)2)) {
        case 1: { Ref self_31;
                  self_31 = self_30;
                  ((S_582)STATEOF(self_31))->state_13 = (CocoaState_CTCommon)0;
                  Component_CTCommon x_3740;
                  x_3740 = this_3738->rootContainer_21->l_Container_CTContainer_Component_CTCommon_CTContainer;
                  TUP0 d_106;
                  d_106 = x_3740->destroy_CTCommon(x_3740, 0);
                  TUP0 d_107;
                  d_107 = destroyCocoaWindow_CTWindow(this_3738->windowId_20, 0);
                  UNLOCK((OID)self_30);
                  return (TUP0)0;
                }
                break;
        case 0: { Ref self_32;
                  self_32 = self_30;
                  UNLOCK((OID)self_30);
                  return (TUP0)0;
                }
                break;
    }
}
static TUP0 f_3758 (T_3705 this_3754, Ref self_51) {
    IsFocusable_CTCommon x_3756;
    x_3756 = this_3754->rootContainer_21->l_Container_CTContainer_Component_CTCommon_CTContainer->l_Component_CTCommon_IsFocusable_CTCommon_CTCommon;
    Maybe_Prelude x_121;
    x_121 = x_3756->getNextFocusTarget_CTCommon(x_3756, 0);
    ((S_582)STATEOF(self_51))->currentFocus_15 = x_121;
    switch ((WORD)isJust_Prelude((BITS32)0,
                                 ((S_582)STATEOF(self_51))->currentFocus_15)) {
        case 1: { IsFocusable_CTCommon x_3757;
                  x_3757 = ((Component_CTCommon)fromJust_Prelude((BITS32)0,
                                                                 ((S_582)STATEOF(self_51))->currentFocus_15))->l_Component_CTCommon_IsFocusable_CTCommon_CTCommon;
                  Maybe_Prelude x_123;
                  x_123 = x_3757->getNextFocusTarget_CTCommon(x_3757, 0);
                  ((S_582)STATEOF(self_51))->nextFocus_16 = x_123;
                  break;
                }
                break;
        case 0: break;
    }
    return (TUP0)0;
}
static TUP0 f_3762 (CLOS this_3760, Ref self_54) {
    return (TUP0)0;
}
static CLOS f_3764 (T_3704 this_3753) {
    switch ((WORD)isNothing_Prelude((BITS32)0,
                                    ((S_582)STATEOF(this_3753->self_46))->nextFocus_16)) {
        case 1: { T_3705 x_3759;
                  NEW (T_3705, x_3759, WORDS(sizeof(struct T_3705)));
                  x_3759->GCINFO = __GC__T_3705;
                  x_3759->Code = f_3758;
                  x_3759->rootContainer_21 = this_3753->rootContainer_21;
                  return (CLOS)x_3759;
                }
                break;
        case 0: { CLOS x_3763;
                  NEW (CLOS, x_3763, WORDS(sizeof(struct CLOS)));
                  x_3763->GCINFO = __GC__CLOS;
                  x_3763->Code = ((void(*)(void))f_3762);
                  return x_3763;
                }
                break;
    }
}
static TUP0 f_3768 (T_3703 this_3749, Ref self_46) {
    switch ((WORD)isNothing_Prelude((BITS32)0,
                                    ((S_582)STATEOF(self_46))->currentFocus_15)) {
        case 1: { IsFocusable_CTCommon x_3751;
                  x_3751 = this_3749->rootContainer_21->l_Container_CTContainer_Component_CTCommon_CTContainer->l_Component_CTCommon_IsFocusable_CTCommon_CTCommon;
                  Maybe_Prelude x_117;
                  x_117 = x_3751->getNextFocusTarget_CTCommon(x_3751, 0);
                  ((S_582)STATEOF(self_46))->currentFocus_15 = x_117;
                  break;
                }
                break;
        case 0: break;
    }
    switch ((WORD)isJust_Prelude((BITS32)0,
                                 ((S_582)STATEOF(self_46))->currentFocus_15)) {
        case 1: { IsFocusable_CTCommon x_3752;
                  x_3752 = ((Component_CTCommon)fromJust_Prelude((BITS32)0,
                                                                 ((S_582)STATEOF(self_46))->currentFocus_15))->l_Component_CTCommon_IsFocusable_CTCommon_CTCommon;
                  Maybe_Prelude x_119;
                  x_119 = x_3752->getNextFocusTarget_CTCommon(x_3752, 0);
                  ((S_582)STATEOF(self_46))->nextFocus_16 = x_119;
                  break;
                }
                break;
        case 0: break;
    }
    CLOS x_3765;
    NEW (CLOS, x_3765, WORDS(sizeof(struct T_3704)));
    ((T_3704)x_3765)->GCINFO = __GC__T_3704;
    ((T_3704)x_3765)->Code = f_3764;
    ((T_3704)x_3765)->self_46 = self_46;
    ((T_3704)x_3765)->rootContainer_21 = this_3749->rootContainer_21;
    CLOS x_3766;
    x_3766 = ((CLOS(*)(CLOS))(x_3765->Code))(x_3765);
    TUP0 d_120;
    d_120 = ((TUP0(*)(CLOS, Ref))(x_3766->Code))(x_3766, self_46);
    switch ((WORD)isJust_Prelude((BITS32)0,
                                 ((S_582)STATEOF(self_46))->nextFocus_16)) {
        case 1: { IsFocusable_CTCommon x_3767;
                  x_3767 = ((Component_CTCommon)fromJust_Prelude((BITS32)0,
                                                                 ((S_582)STATEOF(self_46))->nextFocus_16))->l_Component_CTCommon_IsFocusable_CTCommon_CTCommon;
                  Maybe_Prelude next_56;
                  next_56 = x_3767->getNextFocusTarget_CTCommon(x_3767, 0);
                  ((S_582)STATEOF(self_46))->currentFocus_15 = ((S_582)STATEOF(self_46))->nextFocus_16;
                  Msg d_125;
                  d_125 = setFocus_33(this_3749->windowId_20,
                                      this_3749->self_9,
                                      (Component_CTCommon)fromJust_Prelude((BITS32)0,
                                                                           ((S_582)STATEOF(self_46))->nextFocus_16),
                                      Inherit,
                                      Inherit);
                  break;
                }
                break;
        case 0: break;
    }
    return (TUP0)0;
}
static TUP0 f_3779 (T_3705 this_3775, Ref self_63) {
    IsFocusable_CTCommon x_3777;
    x_3777 = this_3775->rootContainer_21->l_Container_CTContainer_Component_CTCommon_CTContainer->l_Component_CTCommon_IsFocusable_CTCommon_CTCommon;
    Maybe_Prelude x_131;
    x_131 = x_3777->getPreviousFocusTarget_CTCommon(x_3777, 0);
    ((S_582)STATEOF(self_63))->currentFocus_15 = x_131;
    switch ((WORD)isJust_Prelude((BITS32)0,
                                 ((S_582)STATEOF(self_63))->currentFocus_15)) {
        case 1: { IsFocusable_CTCommon x_3778;
                  x_3778 = ((Component_CTCommon)fromJust_Prelude((BITS32)0,
                                                                 ((S_582)STATEOF(self_63))->currentFocus_15))->l_Component_CTCommon_IsFocusable_CTCommon_CTCommon;
                  Maybe_Prelude x_133;
                  x_133 = x_3778->getPreviousFocusTarget_CTCommon(x_3778, 0);
                  ((S_582)STATEOF(self_63))->previousFocus_17 = x_133;
                  break;
                }
                break;
        case 0: break;
    }
    return (TUP0)0;
}
static TUP0 f_3783 (CLOS this_3781, Ref self_66) {
    return (TUP0)0;
}
static CLOS f_3785 (T_3706 this_3774) {
    switch ((WORD)isNothing_Prelude((BITS32)0,
                                    ((S_582)STATEOF(this_3774->self_58))->previousFocus_17)) {
        case 1: { T_3705 x_3780;
                  NEW (T_3705, x_3780, WORDS(sizeof(struct T_3705)));
                  x_3780->GCINFO = __GC__T_3705;
                  x_3780->Code = f_3779;
                  x_3780->rootContainer_21 = this_3774->rootContainer_21;
                  return (CLOS)x_3780;
                }
                break;
        case 0: { CLOS x_3784;
                  NEW (CLOS, x_3784, WORDS(sizeof(struct CLOS)));
                  x_3784->GCINFO = __GC__CLOS;
                  x_3784->Code = ((void(*)(void))f_3783);
                  return x_3784;
                }
                break;
    }
}
static TUP0 f_3789 (T_3703 this_3770, Ref self_58) {
    switch ((WORD)isNothing_Prelude((BITS32)0,
                                    ((S_582)STATEOF(self_58))->currentFocus_15)) {
        case 1: { IsFocusable_CTCommon x_3772;
                  x_3772 = this_3770->rootContainer_21->l_Container_CTContainer_Component_CTCommon_CTContainer->l_Component_CTCommon_IsFocusable_CTCommon_CTCommon;
                  Maybe_Prelude x_127;
                  x_127 = x_3772->getPreviousFocusTarget_CTCommon(x_3772, 0);
                  ((S_582)STATEOF(self_58))->currentFocus_15 = x_127;
                  break;
                }
                break;
        case 0: break;
    }
    switch ((WORD)isJust_Prelude((BITS32)0,
                                 ((S_582)STATEOF(self_58))->currentFocus_15)) {
        case 1: { IsFocusable_CTCommon x_3773;
                  x_3773 = ((Component_CTCommon)fromJust_Prelude((BITS32)0,
                                                                 ((S_582)STATEOF(self_58))->currentFocus_15))->l_Component_CTCommon_IsFocusable_CTCommon_CTCommon;
                  Maybe_Prelude x_129;
                  x_129 = x_3773->getPreviousFocusTarget_CTCommon(x_3773, 0);
                  ((S_582)STATEOF(self_58))->previousFocus_17 = x_129;
                  break;
                }
                break;
        case 0: break;
    }
    CLOS x_3786;
    NEW (CLOS, x_3786, WORDS(sizeof(struct T_3706)));
    ((T_3706)x_3786)->GCINFO = __GC__T_3706;
    ((T_3706)x_3786)->Code = f_3785;
    ((T_3706)x_3786)->self_58 = self_58;
    ((T_3706)x_3786)->rootContainer_21 = this_3770->rootContainer_21;
    CLOS x_3787;
    x_3787 = ((CLOS(*)(CLOS))(x_3786->Code))(x_3786);
    TUP0 d_130;
    d_130 = ((TUP0(*)(CLOS, Ref))(x_3787->Code))(x_3787, self_58);
    switch ((WORD)isJust_Prelude((BITS32)0,
                                 ((S_582)STATEOF(self_58))->previousFocus_17)) {
        case 1: { IsFocusable_CTCommon x_3788;
                  x_3788 = ((Component_CTCommon)fromJust_Prelude((BITS32)0,
                                                                 ((S_582)STATEOF(self_58))->previousFocus_17))->l_Component_CTCommon_IsFocusable_CTCommon_CTCommon;
                  Maybe_Prelude next_68;
                  next_68 = x_3788->getPreviousFocusTarget_CTCommon(x_3788, 0);
                  ((S_582)STATEOF(self_58))->currentFocus_15 = ((S_582)STATEOF(self_58))->previousFocus_17;
                  Msg d_135;
                  d_135 = setFocus_33(this_3770->windowId_20,
                                      this_3770->self_9,
                                      (Component_CTCommon)fromJust_Prelude((BITS32)0,
                                                                           ((S_582)STATEOF(self_58))->previousFocus_17),
                                      Inherit,
                                      Inherit);
                  break;
                }
                break;
        case 0: break;
    }
    return (TUP0)0;
}
static TUP0 f_3793 (CLOS this_3791, Ref self_70) {
    return (TUP0)0;
}
static CLOS f_3795 (T_3702 this_3748) {
    switch ((WORD)compareKeys_CTCommon(this_3748->x_137,
                                       (CocoaKey_CTCommon)78)) {
        case 1: { T_3703 x_3769;
                  NEW (T_3703, x_3769, WORDS(sizeof(struct T_3703)));
                  x_3769->GCINFO = __GC__T_3703;
                  x_3769->Code = f_3768;
                  x_3769->rootContainer_21 = this_3748->rootContainer_21;
                  x_3769->windowId_20 = this_3748->windowId_20;
                  x_3769->self_9 = this_3748->self_9;
                  return (CLOS)x_3769;
                }
                break;
        case 0: { switch ((WORD)compareKeys_CTCommon(this_3748->x_137,
                                                     (CocoaKey_CTCommon)69)) {
                      case 1: { T_3703 x_3790;
                                NEW (T_3703, x_3790, WORDS(sizeof(struct T_3703)));
                                x_3790->GCINFO = __GC__T_3703;
                                x_3790->Code = f_3789;
                                x_3790->rootContainer_21 = this_3748->rootContainer_21;
                                x_3790->windowId_20 = this_3748->windowId_20;
                                x_3790->self_9 = this_3748->self_9;
                                return (CLOS)x_3790;
                              }
                              break;
                      case 0: { CLOS x_3794;
                                NEW (CLOS, x_3794, WORDS(sizeof(struct CLOS)));
                                x_3794->GCINFO = __GC__CLOS;
                                x_3794->Code = ((void(*)(void))f_3793);
                                return x_3794;
                              }
                              break;
                  }
                }
                break;
    }
}
static TUP0 f_3804 (T_3708 this_3801, Ref self_84) {
    IsFocusable_CTCommon x_3803;
    x_3803 = ((Component_CTCommon)fromJust_Prelude((BITS32)0,
                                                   this_3801->cmp_83))->l_Component_CTCommon_IsFocusable_CTCommon_CTCommon;
    Bool x_145;
    x_145 = x_3803->getIsFocusable_CTCommon(x_3803, 0);
    switch ((WORD)x_145) {
        case 1: { Msg d_146;
                  d_146 = setFocus_33(this_3801->windowId_20,
                                      this_3801->self_9,
                                      (Component_CTCommon)fromJust_Prelude((BITS32)0,
                                                                           this_3801->cmp_83),
                                      Inherit,
                                      Inherit);
                  break;
                }
                break;
        case 0: break;
    }
    return (TUP0)0;
}
static TUP0 f_3808 (CLOS this_3806, Ref self_87) {
    return (TUP0)0;
}
static CLOS f_3810 (T_3707 this_3800) {
    switch ((WORD)isJust_Prelude((BITS32)0, this_3800->cmp_83)) {
        case 1: { T_3708 x_3805;
                  NEW (T_3708, x_3805, WORDS(sizeof(struct T_3708)));
                  x_3805->GCINFO = __GC__T_3708;
                  x_3805->Code = f_3804;
                  x_3805->cmp_83 = this_3800->cmp_83;
                  x_3805->windowId_20 = this_3800->windowId_20;
                  x_3805->self_9 = this_3800->self_9;
                  return (CLOS)x_3805;
                }
                break;
        case 0: { CLOS x_3809;
                  NEW (CLOS, x_3809, WORDS(sizeof(struct CLOS)));
                  x_3809->GCINFO = __GC__CLOS;
                  x_3809->Code = ((void(*)(void))f_3808);
                  return x_3809;
                }
                break;
    }
}
static Maybe_Prelude f_3813 (T_3701 this_3742,
                             CocoaEvent_CTCommon a_3629,
                             LIST a_3630,
                             Int a_3631) {
    switch (a_3629->Tag) {
        case 0: { KeyEventType_CTCommon x_147;
                  x_147 = ((_KeyEvent_CTCommon)a_3629)->a;
                  Ref self_41;
                  self_41 = (Ref)LOCK((OID)this_3742->self_9);
                  switch (x_147->Tag) {
                      case 1: { CocoaKey_CTCommon x_137;
                                x_137 = ((_KeyPressed_CTCommon)x_147)->a;
                                Ref x_111;
                                x_111 = self_41;
                                ((S_582)STATEOF(x_111))->consumed_18 = (Bool)0;
                                switch ((WORD)isJust_Prelude((BITS32)0,
                                                             ((S_582)STATEOF(x_111))->currentFocus_15)) {
                                    case 1: { _KeyEvent_CTCommon x_3746;
                                              NEW (_KeyEvent_CTCommon, x_3746, WORDS(sizeof(struct _KeyEvent_CTCommon)));
                                              x_3746->GCINFO = __GC___KeyEvent_CTCommon;
                                              x_3746->Tag = 0;
                                              x_3746->a = x_147;
                                              HandlesEvents_CTCommon x_3747;
                                              x_3747 = ((Component_CTCommon)fromJust_Prelude((BITS32)0,
                                                                                             ((S_582)STATEOF(x_111))->currentFocus_15))->l_Component_CTCommon_HandlesEvents_CTCommon_CTCommon;
                                              Maybe_Prelude x_113;
                                              x_113 = x_3747->handleEvent_CTCommon(x_3747,
                                                                                   (CocoaEvent_CTCommon)x_3746,
                                                                                   a_3630,
                                                                                   0);
                                              ((S_582)STATEOF(x_111))->consumed_18 = isJust_Prelude((BITS32)0,
                                                                                                    x_113);
                                              break;
                                            }
                                            break;
                                    case 0: break;
                                }
                                switch ((WORD)_sym_679_Prelude/* == */(((S_582)STATEOF(x_111))->consumed_18,
                                                                       (Bool)0)) {
                                    case 1: { CLOS x_3796;
                                              NEW (CLOS, x_3796, WORDS(sizeof(struct T_3702)));
                                              ((T_3702)x_3796)->GCINFO = __GC__T_3702;
                                              ((T_3702)x_3796)->Code = f_3795;
                                              ((T_3702)x_3796)->x_137 = x_137;
                                              ((T_3702)x_3796)->rootContainer_21 = this_3742->rootContainer_21;
                                              ((T_3702)x_3796)->windowId_20 = this_3742->windowId_20;
                                              ((T_3702)x_3796)->self_9 = this_3742->self_9;
                                              CLOS x_3797;
                                              x_3797 = ((CLOS(*)(CLOS))(x_3796->Code))(x_3796);
                                              TUP0 d_115;
                                              d_115 = ((TUP0(*)(CLOS, Ref))(x_3797->Code))(x_3797,
                                                                                           x_111);
                                              break;
                                            }
                                            break;
                                    case 0: break;
                                }
                                Bool x_136;
                                x_136 = dynamicHandleEvent_CTCommon((BITS32)0,
                                                                    (POLY)x_147,
                                                                    ((S_582)STATEOF(x_111))->keyListener_10,
                                                                    x_111);
                                Maybe_Prelude x_3621;
                                x_3621 = boolToMaybe_CTCommon((BITS32)0, (Maybe_Prelude)1, x_136);
                                UNLOCK((OID)self_41);
                                return x_3621;
                              }
                              break;
                      default: RAISE(1);
                  }
                }
                break;
        case 2: { WindowEventType_CTCommon x_148;
                  x_148 = ((_WindowEvent_CTCommon)a_3629)->a;
                  Ref self_74;
                  self_74 = (Ref)LOCK((OID)this_3742->self_9);
                  switch ((WORD)x_148) {
                      case 1: { TUP0 d_139;
                                d_139 = f_3694(self_74);
                                break;
                              }
                              break;
                      case 0: break;
                  }
                  Bool x_142;
                  x_142 = dynamicHandleEvent_CTCommon((BITS32)0,
                                                      (POLY)x_148,
                                                      ((S_582)STATEOF(self_74))->windowListener_11,
                                                      self_74);
                  Maybe_Prelude x_3624;
                  x_3624 = boolToMaybe_CTCommon((BITS32)0, (Maybe_Prelude)1, x_142);
                  UNLOCK((OID)self_74);
                  return x_3624;
                }
                break;
        case 1: { MouseEventType_CTCommon x_149;
                  x_149 = ((_MouseEvent_CTCommon)a_3629)->a;
                  Ref self_82;
                  self_82 = (Ref)LOCK((OID)this_3742->self_9);
                  _MouseEvent_CTCommon x_3798;
                  NEW (_MouseEvent_CTCommon, x_3798, WORDS(sizeof(struct _MouseEvent_CTCommon)));
                  x_3798->GCINFO = __GC___MouseEvent_CTCommon;
                  x_3798->Tag = 1;
                  x_3798->a = x_149;
                  HandlesEvents_CTCommon x_3799;
                  x_3799 = this_3742->rootContainer_21->l_Container_CTContainer_Component_CTCommon_CTContainer->l_Component_CTCommon_HandlesEvents_CTCommon_CTCommon;
                  Maybe_Prelude cmp_83;
                  cmp_83 = x_3799->handleEvent_CTCommon(x_3799,
                                                        (CocoaEvent_CTCommon)x_3798,
                                                        a_3630,
                                                        0);
                  CLOS x_3811;
                  NEW (CLOS, x_3811, WORDS(sizeof(struct T_3707)));
                  ((T_3707)x_3811)->GCINFO = __GC__T_3707;
                  ((T_3707)x_3811)->Code = f_3810;
                  ((T_3707)x_3811)->cmp_83 = cmp_83;
                  ((T_3707)x_3811)->windowId_20 = this_3742->windowId_20;
                  ((T_3707)x_3811)->self_9 = this_3742->self_9;
                  CLOS x_3812;
                  x_3812 = ((CLOS(*)(CLOS))(x_3811->Code))(x_3811);
                  TUP0 d_143;
                  d_143 = ((TUP0(*)(CLOS, Ref))(x_3812->Code))(x_3812, self_82);
                  UNLOCK((OID)self_82);
                  return cmp_83;
                }
                break;
    }
}
static TUP0 f_3818 (T_3709 this_3814, CLOS a_3636, Int a_3637) {
    Ref self_90;
    self_90 = (Ref)LOCK((OID)this_3814->self_9);
    _Just_Prelude x_3817;
    NEW (_Just_Prelude, x_3817, WORDS(sizeof(struct _Just_Prelude)));
    x_3817->GCINFO = __GC___Just_Prelude+((4 * (BITS32)0));
    x_3817->a = (POLY)a_3636;
    ((S_582)STATEOF(self_90))->windowListener_11 = (Maybe_Prelude)x_3817;
    UNLOCK((OID)self_90);
    return (TUP0)0;
}
static TUP0 f_3823 (T_3710 this_3819, CLOS a_3644, Int a_3645) {
    Ref self_93;
    self_93 = (Ref)LOCK((OID)this_3819->self_9);
    _Just_Prelude x_3822;
    NEW (_Just_Prelude, x_3822, WORDS(sizeof(struct _Just_Prelude)));
    x_3822->GCINFO = __GC___Just_Prelude+((4 * (BITS32)0));
    x_3822->a = (POLY)a_3644;
    ((S_582)STATEOF(self_93))->keyListener_10 = (Maybe_Prelude)x_3822;
    UNLOCK((OID)self_93);
    return (TUP0)0;
}
static TUP0 f_3828 (T_3711 this_3824, CLOS a_3650, Int a_3651) {
    HandlesMouseEvents_CTCommon x_3827;
    x_3827 = this_3824->rootContainer_21->l_Container_CTContainer_HandlesMouseEvents_CTCommon_CTContainer;
    return x_3827->installMouseListener_CTCommon(x_3827,
                                                 a_3650,
                                                 a_3651);
}
static Bool f_3831 (T_3712 this_3829, Int a_3656) {
    Ref self_96;
    self_96 = (Ref)LOCK((OID)this_3829->self_9);
    switch ((WORD)((compareState_CTCommon(((S_582)STATEOF(self_96))->state_13,
                                          (CocoaState_CTCommon)2) && _sym_679_Prelude/* == */(((S_582)STATEOF(self_96))->isVisible_14,
                                                                                              (Bool)1)))) {
        case 1: { Ref self_97;
                  self_97 = self_96;
                  Msg d_150;
                  d_150 = windowSetHidden_CTWindow(this_3829->windowId_20,
                                                   Inherit,
                                                   Inherit);
                  ((S_582)STATEOF(self_97))->isVisible_14 = (Bool)0;
                  UNLOCK((OID)self_96);
                  return (Bool)1;
                }
                break;
        case 0: { Ref self_98;
                  self_98 = self_96;
                  UNLOCK((OID)self_96);
                  return (Bool)0;
                }
                break;
    }
}
static Bool f_3834 (T_3712 this_3832, Int a_3659) {
    Ref self_100;
    self_100 = (Ref)LOCK((OID)this_3832->self_9);
    switch ((WORD)((compareState_CTCommon(((S_582)STATEOF(self_100))->state_13,
                                          (CocoaState_CTCommon)2) && _sym_679_Prelude/* == */(((S_582)STATEOF(self_100))->isVisible_14,
                                                                                              (Bool)0)))) {
        case 1: { Ref self_101;
                  self_101 = self_100;
                  Msg d_151;
                  d_151 = windowSetVisible_CTWindow(this_3832->windowId_20,
                                                    Inherit,
                                                    Inherit);
                  ((S_582)STATEOF(self_101))->isVisible_14 = (Bool)1;
                  UNLOCK((OID)self_100);
                  return (Bool)1;
                }
                break;
        case 0: { Ref self_102;
                  self_102 = self_100;
                  UNLOCK((OID)self_100);
                  return (Bool)0;
                }
                break;
    }
}
static TUP0 f_3839 (T_3714 this_3835,
                    Component_CTCommon a_3661,
                    Int a_3662) {
    CLOS x_3838;
    x_3838 = this_3835->x_3660;
    return ((TUP0(*)(CLOS, Component_CTCommon, Int))(x_3838->Code))(x_3838,
                                                                    a_3661,
                                                                    a_3662);
}
static LIST f_3843 (T_3714 this_3840, Int a_3664) {
    CLOS x_3842;
    x_3842 = this_3840->x_3663;
    return ((LIST(*)(CLOS, Int))(x_3842->Code))(x_3842, a_3664);
}
static TUP0 f_3849 (T_3715 this_3845, CLOS a_3666, Int a_3667) {
    CLOS x_3848;
    x_3848 = this_3845->x_3665;
    return ((TUP0(*)(CLOS, CLOS, Int))(x_3848->Code))(x_3848,
                                                      a_3666,
                                                      a_3667);
}
static Maybe_Prelude f_3856 (T_3717 this_3851,
                             CocoaEvent_CTCommon a_3669,
                             LIST a_3670,
                             Int a_3671) {
    CLOS x_3855;
    x_3855 = this_3851->x_3668;
    return ((Maybe_Prelude(*)(CLOS, CocoaEvent_CTCommon, LIST, Int))(x_3855->Code))(x_3855,
                                                                                    a_3669,
                                                                                    a_3670,
                                                                                    a_3671);
}
static TUP0 f_3862 (T_3716 this_3858, CLOS a_3673, Int a_3674) {
    CLOS x_3861;
    x_3861 = this_3858->x_3672;
    return ((TUP0(*)(CLOS, CLOS, Int))(x_3861->Code))(x_3861,
                                                      a_3673,
                                                      a_3674);
}
static TUP0 f_3868 (T_3718 this_3864, CLOS a_3676, Int a_3677) {
    CLOS x_3867;
    x_3867 = this_3864->x_3675;
    return ((TUP0(*)(CLOS, CLOS, Int))(x_3867->Code))(x_3867,
                                                      a_3676,
                                                      a_3677);
}
static TUP0 f_3873 (T_3713 this_3870, Int a_3679) {
    CLOS x_3872;
    x_3872 = this_3870->x_3678;
    return ((TUP0(*)(CLOS, Int))(x_3872->Code))(x_3872, a_3679);
}
static Int f_3877 (T_3713 this_3874, Int a_3681) {
    CLOS x_3876;
    x_3876 = this_3874->x_3680;
    return ((Int(*)(CLOS, Int))(x_3876->Code))(x_3876, a_3681);
}
static Bool f_3881 (T_3713 this_3878, Int a_3683) {
    CLOS x_3880;
    x_3880 = this_3878->x_3682;
    return ((Bool(*)(CLOS, Int))(x_3880->Code))(x_3880, a_3683);
}
static TUP0 f_3886 (T_3713 this_3882,
                    App_CTCommon a_3685,
                    Int a_3686) {
    CLOS x_3885;
    x_3885 = this_3882->x_3684;
    return ((TUP0(*)(CLOS, App_CTCommon, Int))(x_3885->Code))(x_3885,
                                                              a_3685,
                                                              a_3686);
}
static Msg f_3891 (T_3713 this_3887,
                   Component_CTCommon a_3687,
                   Time a_3688,
                   Time a_3689) {
    return setFocus_33(this_3887->windowId_20,
                       this_3887->self_9,
                       a_3687,
                       a_3688,
                       a_3689);
}
static Bool f_3895 (T_3713 this_3892, Int a_3691) {
    CLOS x_3894;
    x_3894 = this_3892->x_3690;
    return ((Bool(*)(CLOS, Int))(x_3894->Code))(x_3894, a_3691);
}
static TUP0 f_3899 (T_3700 this_3897) {
    Ref self_35;
    self_35 = (Ref)LOCK((OID)this_3897->self_9);
    _Just_Prelude x_3898;
    NEW (_Just_Prelude, x_3898, WORDS(sizeof(struct _Just_Prelude)));
    x_3898->GCINFO = __GC___Just_Prelude+((4 * (BITS32)0));
    x_3898->a = (POLY)this_3897->cmp_34;
    ((S_582)STATEOF(self_35))->currentFocus_15 = (Maybe_Prelude)x_3898;
    switch ((WORD)compareState_CTCommon(((S_582)STATEOF(self_35))->state_13,
                                        (CocoaState_CTCommon)2)) {
        case 1: { Ref self_36;
                  self_36 = self_35;
                  TUP0 d_108;
                  d_108 = windowSetFocus_CTWindow(this_3897->windowId_20,
                                                  this_3897->cmp_34->id_CTCommon,
                                                  0);
                  UNLOCK((OID)self_35);
                  return (TUP0)0;
                }
                break;
        case 0: { Ref self_37;
                  self_37 = self_35;
                  UNLOCK((OID)self_35);
                  return (TUP0)0;
                }
                break;
    }
}
 
void _init_CTWindow () {
    static int INITIALIZED = 0;
    if (!INITIALIZED) {
        _init_Prelude();
        _init_POSIX();
        _init_CTCommon();
        _init_CTContainer();
        INITIALIZED = 1;
    }
}
 

