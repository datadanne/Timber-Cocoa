#ifndef CTWINDOW_EXTERN_H_
#define CTWINDOW_EXTERN_H_

#include "rts.h"
#include "timber.h"

extern pthread_mutex_t rts;
extern int rootsDirty;

Bool compareKeys_CTWindow(CocoaKey_CocoaDef, CocoaKey_CocoaDef);

TUP2 initCocoaWindow_CTWindow(World,Int);
TUP0 destroyCocoaWindow_CTWindow(Int,Int);
TUP0 windowSetContentView_CTWindow(Int,Int,Int);
TUP0 windowSetHidden_CTWindow(Int,Int);
TUP0 windowSetVisible_CTWindow(Int,Int);
TUP0 windowSetSize_CTWindow(Int,Size_CocoaDef,Int);
TUP0 windowSetPosition_CTWindow(Int,Position_CocoaDef,Int);
TUP0 windowSetFocus_CTWindow(Int,Int,Int);
TUP0 windowSetResizable_CTWindow (Int,Bool,Int);

#endif