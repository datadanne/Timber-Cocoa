#ifndef COCOA_H_
#define COCOA_H_
#include "Prelude.h"
 
struct Env_Cocoa;
typedef struct Env_Cocoa *Env_Cocoa;
 
struct Env_Cocoa {
    POLY GCINFO;
    Msg (*showWindow_Cocoa) (Env_Cocoa, Time, Time);
};
 
extern WORD __GC__Env_Cocoa[];
 
void _init_Cocoa ();
 
#include "Cocoa.extern.h"
#endif
