#include "CocoaTest.h"
 
struct S_128;
typedef struct S_128 *S_128;
struct T_234;
typedef struct T_234 *T_234;
struct T_233;
typedef struct T_233 *T_233;
 
struct S_128 {
    POLY GCINFO;
};
struct T_234 {
    POLY GCINFO;
    TUP0 (*Code) (T_234);
    AbsTime baseline;
    AbsTime deadline;
    Msg next;
    Env_Cocoa osx_5;
    Env_POSIX env_4;
    Ref self_3;
};
struct T_233 {
    POLY GCINFO;
    Msg (*Code) (T_233, Time, Time);
    Env_Cocoa osx_5;
    Env_POSIX env_4;
    Ref self_3;
};
 
static WORD __GC__S_128[];
static WORD __GC__T_234[];
static WORD __GC__T_233[];
static TUP0 f_243 (T_234 this_239);
static Msg f_244 (T_233 this_236, Time a_228, Time a_229);
 
static WORD __GC__S_128[] = {WORDS(sizeof(struct S_128)), 0, 0};
static WORD __GC__T_234[] = {WORDS(sizeof(struct T_234)),
                             0,
                             WORDS(offsetof(struct T_234, osx_5)),
                             WORDS(offsetof(struct T_234, env_4)),
                             WORDS(offsetof(struct T_234, self_3)),
                             0};
static WORD __GC__T_233[] = {WORDS(sizeof(struct T_233)),
                             0,
                             WORDS(offsetof(struct T_233, osx_5)),
                             WORDS(offsetof(struct T_233, env_4)),
                             WORDS(offsetof(struct T_233, self_3)),
                             0};
CLOS root_CocoaTest (World w_2, Int d_232) {
    Ref self_3;
    NEW (Ref, self_3, WORDS(sizeof(struct Ref))+
                      WORDS(sizeof(struct S_128)));
    INITREF(self_3);
    ((S_128)STATEOF(self_3))->GCINFO = __GC__S_128;
    Env_POSIX env_4;
    env_4 = posix_POSIX(w_2, 0);
    Env_Cocoa osx_5;
    osx_5 = cocoa_Cocoa(w_2, 0);
    CLOS x_231;
    NEW (CLOS, x_231, WORDS(sizeof(struct T_233)));
    ((T_233)x_231)->GCINFO = __GC__T_233;
    ((T_233)x_231)->Code = f_244;
    ((T_233)x_231)->osx_5 = osx_5;
    ((T_233)x_231)->env_4 = env_4;
    ((T_233)x_231)->self_3 = self_3;
    return x_231;
}
static TUP0 f_243 (T_234 this_239) {
    Ref self_6;
    self_6 = (Ref)LOCK((OID)this_239->self_3);
    WFile_POSIX x_240;
    x_240 = this_239->env_4->stdout_POSIX;
    Int d_7;
    d_7 = x_240->write_POSIX(x_240,
                             getStr("Timber: Calling showWindow\n"),
                             0);
    Env_Cocoa x_241;
    x_241 = this_239->osx_5;
    Msg d_8;
    d_8 = x_241->showWindow_Cocoa(x_241, Inherit, Inherit);
    WFile_POSIX x_242;
    x_242 = this_239->env_4->stdout_POSIX;
    Int d_9;
    d_9 = x_242->write_POSIX(x_242,
                             getStr("Timber: Window gone?\n"),
                             0);
    UNLOCK((OID)self_6);
    return (TUP0)0;
}
static Msg f_244 (T_233 this_236, Time a_228, Time a_229) {
    Msg x_230;
    NEW (Msg, x_230, WORDS(sizeof(struct T_234)));
    ((T_234)x_230)->GCINFO = __GC__T_234;
    ((T_234)x_230)->Code = f_243;
    ((T_234)x_230)->osx_5 = this_236->osx_5;
    ((T_234)x_230)->env_4 = this_236->env_4;
    ((T_234)x_230)->self_3 = this_236->self_3;
    return (Msg)ASYNC(x_230, a_228, a_229);
}
 
void _init_CocoaTest () {
    static int INITIALIZED = 0;
    if (!INITIALIZED) {
        _init_Prelude();
        _init_Cocoa();
        _init_POSIX();
        INITIALIZED = 1;
    }
}
 

