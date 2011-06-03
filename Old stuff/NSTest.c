#include "NSTest.h"
 
struct S_203;
typedef struct S_203 *S_203;
struct T_534;
typedef struct T_534 *T_534;
struct T_533;
typedef struct T_533 *T_533;
struct T_532;
typedef struct T_532 *T_532;
struct T_531;
typedef struct T_531 *T_531;
struct T_530;
typedef struct T_530 *T_530;
 
struct S_203 {
    POLY GCINFO;
    LIST activeWindows_3;
};
struct T_534 {
    POLY GCINFO;
    TUP0 (*showWindow_CTCommon) (T_534, CocoaWindow_CTCommon, Int);
    ApplicationState_CTCommon (*getApplicationState_CTCommon) (T_534,
                                                               Int);
    Msg (*eventDispatcher_CTCommon) (T_534,
                                     CocoaEvent_CTCommon,
                                     Int,
                                     Time,
                                     Time);
    CLOS x_524;
    CLOS x_526;
    Ref self_2;
};
struct T_533 {
    POLY GCINFO;
    TUP0 (*Code) (T_533, CocoaWindow_CTCommon, Int);
    App_CTCommon this_15;
    Ref self_2;
};
struct T_532 {
    POLY GCINFO;
    ApplicationState_CTCommon (*Code) (T_532, Int);
    Ref self_2;
};
struct T_531 {
    POLY GCINFO;
    TUP0 (*Code) (T_531, CocoaWindow_CTCommon, Ref);
    CocoaEvent_CTCommon c_5;
    Int id_6;
};
struct T_530 {
    POLY GCINFO;
    TUP0 (*Code) (T_530);
    AbsTime baseline;
    AbsTime deadline;
    Msg next;
    CocoaEvent_CTCommon c_5;
    Int id_6;
    Ref self_2;
};
 
static WORD __GC__S_203[];
static WORD __GC__T_534[];
static WORD __GC__T_533[];
static WORD __GC__T_532[];
static WORD __GC__T_531[];
static WORD __GC__T_530[];
static Msg eventDispatcher_4 (Ref self_2,
                              CocoaEvent_CTCommon c_5,
                              Int id_6,
                              Time a_510,
                              Time a_511);
static ApplicationState_CTCommon f_538 (T_532 this_536, Int a_515);
static TUP0 f_543 (T_533 this_539,
                   CocoaWindow_CTCommon a_518,
                   Int a_519);
static Msg f_549 (T_534 this_544,
                  CocoaEvent_CTCommon a_520,
                  Int a_521,
                  Time a_522,
                  Time a_523);
static ApplicationState_CTCommon f_553 (T_534 this_550, Int a_525);
static TUP0 f_558 (T_534 this_554,
                   CocoaWindow_CTCommon a_527,
                   Int a_528);
static TUP0 f_564 (T_531 this_560,
                   CocoaWindow_CTCommon a_506,
                   Ref a_507);
static TUP0 f_566 (T_530 this_559);
 
static WORD __GC__S_203[] = {WORDS(sizeof(struct S_203)),
                             0,
                             WORDS(offsetof(struct S_203, activeWindows_3)),
                             0};
static WORD __GC__T_534[] = {WORDS(sizeof(struct T_534)),
                             0,
                             WORDS(offsetof(struct T_534, x_524)),
                             WORDS(offsetof(struct T_534, x_526)),
                             WORDS(offsetof(struct T_534, self_2)),
                             0};
static WORD __GC__T_533[] = {WORDS(sizeof(struct T_533)),
                             0,
                             WORDS(offsetof(struct T_533, this_15)),
                             WORDS(offsetof(struct T_533, self_2)),
                             0};
static WORD __GC__T_532[] = {WORDS(sizeof(struct T_532)),
                             0,
                             WORDS(offsetof(struct T_532, self_2)),
                             0};
static WORD __GC__T_531[] = {WORDS(sizeof(struct T_531)),
                             0,
                             WORDS(offsetof(struct T_531, c_5)),
                             0};
static WORD __GC__T_530[] = {WORDS(sizeof(struct T_530)),
                             0,
                             WORDS(offsetof(struct T_530, c_5)),
                             WORDS(offsetof(struct T_530, self_2)),
                             0};
App_CTCommon cocoaApplication_NSTest (Int d_529) {
    Ref self_2;
    NEW (Ref, self_2, WORDS(sizeof(struct Ref))+
                      WORDS(sizeof(struct S_203)));
    INITREF(self_2);
    ((S_203)STATEOF(self_2))->GCINFO = __GC__S_203;
    CLOS getApplicationState_12;
    NEW (CLOS, getApplicationState_12, WORDS(sizeof(struct T_532)));
    ((T_532)getApplicationState_12)->GCINFO = __GC__T_532;
    ((T_532)getApplicationState_12)->Code = f_538;
    ((T_532)getApplicationState_12)->self_2 = self_2;
    CLOS showWindow_14;
    CLOS x_524;
    CLOS x_526;
    App_CTCommon this_15;
    x_524 = getApplicationState_12;
    {   Array roots = CYCLIC_BEGIN(3,0);
        showWindow_14 = (CLOS)roots->elems[0];
        x_526 = (CLOS)roots->elems[1];
        this_15 = (App_CTCommon)roots->elems[2];
        NEW (CLOS, showWindow_14, WORDS(sizeof(struct T_533)));
        roots->elems[0] = (POLY)showWindow_14;
        ((T_533)(CLOS)roots->elems[0])->GCINFO = __GC__T_533;
        ((T_533)(CLOS)roots->elems[0])->Code = f_543;
        ((T_533)(CLOS)roots->elems[0])->this_15 = this_15;
        ((T_533)(CLOS)roots->elems[0])->self_2 = self_2;
        x_526 = showWindow_14;
        roots->elems[1] = (POLY)x_526;
        NEW (App_CTCommon, this_15, WORDS(sizeof(struct T_534)));
        roots->elems[2] = (POLY)this_15;
        ((T_534)(App_CTCommon)roots->elems[2])->GCINFO = __GC__T_534;
        ((T_534)(App_CTCommon)roots->elems[2])->eventDispatcher_CTCommon = f_549;
        ((T_534)(App_CTCommon)roots->elems[2])->getApplicationState_CTCommon = f_553;
        ((T_534)(App_CTCommon)roots->elems[2])->showWindow_CTCommon = f_558;
        ((T_534)(App_CTCommon)roots->elems[2])->x_524 = x_524;
        ((T_534)(App_CTCommon)roots->elems[2])->x_526 = x_526;
        ((T_534)(App_CTCommon)roots->elems[2])->self_2 = self_2;
        CYCLIC_END(roots, hp);
    }
    ((S_203)STATEOF(self_2))->activeWindows_3 = (LIST)0;
    return this_15;
}
static Msg eventDispatcher_4 (Ref self_2,
                              CocoaEvent_CTCommon c_5,
                              Int id_6,
                              Time a_510,
                              Time a_511) {
    Msg x_512;
    NEW (Msg, x_512, WORDS(sizeof(struct T_530)));
    ((T_530)x_512)->GCINFO = __GC__T_530;
    ((T_530)x_512)->Code = f_566;
    ((T_530)x_512)->c_5 = c_5;
    ((T_530)x_512)->id_6 = id_6;
    ((T_530)x_512)->self_2 = self_2;
    return (Msg)ASYNC(x_512, a_510, a_511);
}
static ApplicationState_CTCommon f_538 (T_532 this_536,
                                        Int a_515) {
    Ref self_13;
    self_13 = (Ref)LOCK((OID)this_536->self_2);
    UNLOCK((OID)self_13);
    return (ApplicationState_CTCommon)1;
}
static TUP0 f_543 (T_533 this_539,
                   CocoaWindow_CTCommon a_518,
                   Int a_519) {
    Ref self_17;
    self_17 = (Ref)LOCK((OID)this_539->self_2);
    CocoaEvent_CTCommon superTest_18;
    NEW (CocoaEvent_CTCommon, superTest_18, WORDS(sizeof(struct _WindowEvent_CTCommon)));
    ((_WindowEvent_CTCommon)superTest_18)->GCINFO = __GC___WindowEvent_CTCommon;
    ((_WindowEvent_CTCommon)superTest_18)->Tag = 2;
    ((_WindowEvent_CTCommon)superTest_18)->a = (WindowEventType_CTCommon)1;
    Msg d_22;
    d_22 = eventDispatcher_4(this_539->self_2,
                             superTest_18,
                             5,
                             Inherit,
                             Inherit);
    TUP0 d_23;
    d_23 = a_518->initWindow_CTCommon(a_518, this_539->this_15, 0);
    CONS x_542;
    NEW (CONS, x_542, WORDS(sizeof(struct CONS)));
    x_542->GCINFO = __GC__CONS+((5 * (BITS32)0));
    x_542->hd = (POLY)a_518;
    x_542->tl = ((S_203)STATEOF(self_17))->activeWindows_3;
    ((S_203)STATEOF(self_17))->activeWindows_3 = (LIST)x_542;
    UNLOCK((OID)self_17);
    return (TUP0)0;
}
static Msg f_549 (T_534 this_544,
                  CocoaEvent_CTCommon a_520,
                  Int a_521,
                  Time a_522,
                  Time a_523) {
    return eventDispatcher_4(this_544->self_2,
                             a_520,
                             a_521,
                             a_522,
                             a_523);
}
static ApplicationState_CTCommon f_553 (T_534 this_550,
                                        Int a_525) {
    CLOS x_552;
    x_552 = this_550->x_524;
    return ((ApplicationState_CTCommon(*)(CLOS, Int))(x_552->Code))(x_552,
                                                                    a_525);
}
static TUP0 f_558 (T_534 this_554,
                   CocoaWindow_CTCommon a_527,
                   Int a_528) {
    CLOS x_557;
    x_557 = this_554->x_526;
    return ((TUP0(*)(CLOS, CocoaWindow_CTCommon, Int))(x_557->Code))(x_557,
                                                                     a_527,
                                                                     a_528);
}
static TUP0 f_564 (T_531 this_560,
                   CocoaWindow_CTCommon a_506,
                   Ref a_507) {
    Int x_20;
    x_20 = a_506->getId_CTCommon(a_506, 0);
    switch ((WORD)_sym_635_Prelude/* == */(x_20, this_560->id_6)) {
        case 1: { Ref self_10;
                  self_10 = a_507;
                  HandlesEvents_CTCommon x_563;
                  x_563 = a_506->l_CocoaWindow_CTCommon_HandlesWindowEvents_CTCommon_CTCommon->l_HandlesWindowEvents_CTCommon_HandlesEvents_CTCommon_CTCommon;
                  Bool d_21;
                  d_21 = x_563->handleEvent_CTCommon(x_563, this_560->c_5, 0);
                  return (TUP0)0;
                }
                break;
        case 0: { Ref self_11;
                  self_11 = a_507;
                  return (TUP0)0;
                }
                break;
    }
}
static TUP0 f_566 (T_530 this_559) {
    Ref self_7;
    self_7 = (Ref)LOCK((OID)this_559->self_2);
    T_531 x_565;
    NEW (T_531, x_565, WORDS(sizeof(struct T_531)));
    x_565->GCINFO = __GC__T_531;
    x_565->Code = f_564;
    x_565->c_5 = this_559->c_5;
    x_565->id_6 = this_559->id_6;
    TUP0 d_19;
    d_19 = forallListUnit_Prelude((BITS32)4,
                                  (CLOS)x_565,
                                  ((S_203)STATEOF(self_7))->activeWindows_3,
                                  self_7);
    UNLOCK((OID)self_7);
    return (TUP0)0;
}
 
void _init_NSTest () {
    static int INITIALIZED = 0;
    if (!INITIALIZED) {
        _init_Prelude();
        _init_POSIX();
        _init_CTCommon();
        _init_CTContainer();
        INITIALIZED = 1;
    }
}
 

