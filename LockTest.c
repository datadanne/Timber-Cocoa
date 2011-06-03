#include "LockTest.h"
 
struct S_206;
typedef struct S_206 *S_206;
struct T_274;
typedef struct T_274 *T_274;
struct T_273;
typedef struct T_273 *T_273;
 
struct S_206 {
    POLY GCINFO;
};
struct T_274 {
    POLY GCINFO;
    TUP0 (*Code) (T_274);
    AbsTime baseline;
    AbsTime deadline;
    Msg next;
    Ref self_3;
};
struct T_273 {
    POLY GCINFO;
    Msg (*Code) (T_273, Time, Time);
    Ref self_3;
};
 
static WORD __GC__S_206[];
static WORD __GC__T_274[];
static WORD __GC__T_273[];
static TUP0 f_281 (T_274 this_279);
static Msg f_282 (T_273 this_276, Time a_268, Time a_269);
 
static WORD __GC__S_206[] = {WORDS(sizeof(struct S_206)), 0, 0};
static WORD __GC__T_274[] = {WORDS(sizeof(struct T_274)),
                             0,
                             WORDS(offsetof(struct T_274, self_3)),
                             0};
static WORD __GC__T_273[] = {WORDS(sizeof(struct T_273)),
                             0,
                             WORDS(offsetof(struct T_273, self_3)),
                             0};
CLOS root_LockTest (World w_2, Int d_272) {
    Ref self_3;
    NEW (Ref, self_3, WORDS(sizeof(struct Ref))+
                      WORDS(sizeof(struct S_206)));
    INITREF(self_3);
    ((S_206)STATEOF(self_3))->GCINFO = __GC__S_206;
    Env_POSIX env_4;
    env_4 = posix_POSIX(w_2, 0);
    Env_COCOA osx_5;
    osx_5 = cocoa_COCOA(w_2, 0);
    CLOS x_271;
    NEW (CLOS, x_271, WORDS(sizeof(struct T_273)));
    ((T_273)x_271)->GCINFO = __GC__T_273;
    ((T_273)x_271)->Code = f_282;
    ((T_273)x_271)->self_3 = self_3;
    return x_271;
}
static TUP0 f_281 (T_274 this_279) {
    Ref self_6;
    self_6 = (Ref)LOCK((OID)this_279->self_3);
    _KeyPressed_CTCommon x_280;
    NEW (_KeyPressed_CTCommon, x_280, WORDS(sizeof(struct _KeyPressed_CTCommon)));
    x_280->GCINFO = __GC___KeyPressed_CTCommon;
    x_280->Tag = 1;
    x_280->a = (CocoaKey_CTCommon)78;
    CocoaEvent_CTCommon superTest_7;
    NEW (CocoaEvent_CTCommon, superTest_7, WORDS(sizeof(struct _KeyEvent_CTCommon)));
    ((_KeyEvent_CTCommon)superTest_7)->GCINFO = __GC___KeyEvent_CTCommon;
    ((_KeyEvent_CTCommon)superTest_7)->Tag = 0;
    ((_KeyEvent_CTCommon)superTest_7)->a = (KeyEventType_CTCommon)x_280;
    UNLOCK((OID)self_6);
    return (TUP0)0;
}
static Msg f_282 (T_273 this_276, Time a_268, Time a_269) {
    Msg x_270;
    NEW (Msg, x_270, WORDS(sizeof(struct T_274)));
    ((T_274)x_270)->GCINFO = __GC__T_274;
    ((T_274)x_270)->Code = f_281;
    ((T_274)x_270)->self_3 = this_276->self_3;
    return (Msg)ASYNC(x_270, a_268, a_269);
}
 
void _init_LockTest () {
    static int INITIALIZED = 0;
    if (!INITIALIZED) {
        _init_Prelude();
        _init_POSIX();
        _init_COCOA();
        INITIALIZED = 1;
    }
}
 

