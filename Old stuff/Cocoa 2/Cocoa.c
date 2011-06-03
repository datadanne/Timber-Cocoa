#include "Cocoa.h"
#include "Cocoa.extern.c"
 
 
 
 
WORD __GC__Env_Cocoa[] = {WORDS(sizeof(struct Env_Cocoa)), 0, 0};
 
void _init_Cocoa () {
    static int INITIALIZED = 0;
    if (!INITIALIZED) {
        _init_Prelude();
        INITIALIZED = 1;
    }
}
 

