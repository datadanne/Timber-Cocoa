#ifndef COCOA_H_
#define COCOA_H_
#include "Prelude.h"
#include "CTCommon.h"
#include "CTButton.h"
#include "CTLabel.h"
#include "CTContainer.h"
#include "CTWindow.h"
#include "CTApplication.h"
 
struct Env_COCOA;
typedef struct Env_COCOA *Env_COCOA;
 
struct Env_COCOA {
    POLY GCINFO;
    TUP0 (*startApplication_COCOA) (Env_COCOA, CLOS, Int);
};
 
extern WORD __GC__Env_COCOA[];
 
void _init_COCOA ();
 
#include "COCOA.extern.h"
#endif
