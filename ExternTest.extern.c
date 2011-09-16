#include <stdio.h>
#include "POSIX.h"

typedef struct Callback *Callback;

struct Callback {
    POLY GCINFO;
    TUP0 (*Code) (Callback, LIST, Int);
    Env_POSIX env_5;
    Ref self_4;
};

TUP0 doAllTheThings_ExternTest(CLOS func, Int dum) {
    Callback cb = (Callback) func;
    int i;
    for(i = 0; i < 1000000;i++);
    cb->Code(cb, getStr("--- EXTERN C CALL TO TIMBER ---\n"), 0);
	return 0;
}

