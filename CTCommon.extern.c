#include "CTCommon.extern.h"
#import "ctlib.c"

// --------- GC Handling ------------------------------------------------
WORD __internal__GC__CocoaID_CTCommon[] = {WORDS(sizeof(struct internal_CocoaID_CTCommon)), 0, 0};

CocoaID_CTCommon mkCocoaID_CTCommon(Int dummy) {
	internal_CocoaID_CTCommon cocoaObject;
	NEW(internal_CocoaID_CTCommon, cocoaObject, WORDS(sizeof(struct internal_CocoaID_CTCommon)));
	cocoaObject->GCINFO = __internal__GC__CocoaID_CTCommon;  
	cocoaObject->this 	= NULL;

	return (CocoaID_CTCommon) cocoaObject;
}

Bool compareCocoaIDs_CTCommon (CocoaID_CTCommon a, CocoaID_CTCommon b) {
    internal_CocoaID_CTCommon ia = (internal_CocoaID_CTCommon)a;
    internal_CocoaID_CTCommon ib = (internal_CocoaID_CTCommon)b;   
    printf("comparing ids. #1: %p, #2:%p \n", ia->this, ib->this);  
    if(ia->this == ib->this)
        printf("gonna return true\n");
    else
        printf("gonna return false\n");
    return (ia->this == ib->this);
}

Bool compareKeys_CTCommon(CocoaKey_CTCommon aKey, CocoaKey_CTCommon anotherKey) {
    return ((int)aKey == (int)anotherKey);
}

Bool compareState_CTCommon(CocoaState_CTCommon aKey, CocoaState_CTCommon anotherKey) {
    return ((int)aKey == (int)anotherKey);
}