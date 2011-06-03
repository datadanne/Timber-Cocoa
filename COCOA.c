#include "COCOA.h"
#include "COCOA.extern.c"
 
 
 
 
WORD __GC__Env_COCOA[] = {WORDS(sizeof(struct Env_COCOA)), 0, 0};
 
void _init_COCOA () {
    static int INITIALIZED = 0;
    if (!INITIALIZED) {
        _init_Prelude();
        _init_CTCommon();
        _init_CTButton();
        _init_CTLabel();
        _init_CTContainer();
        _init_CTWindow();
        _init_CTApplication();
        INITIALIZED = 1;
    }
}
 

