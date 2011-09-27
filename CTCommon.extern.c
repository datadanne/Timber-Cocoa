#include "CTCommon.extern.h"

struct Callback {
	WORD * GCINFO;
	TUP0 (*Code) (Callback, Time, Time);
};

// these functions are used to convert from LIST to char*
int length (LIST list) {
    switch ((int)list) {
        case 0: return 0;
        default: return (1 + length(((CONS)list)->tl));
    }
}

char *listToChars(LIST str) {
	int len;
    char* buf; 
	int size = length(str);

    NEW(char*, buf, WORDS(sizeof(char) * size+1));   
    len = 0;
    while (str && len < size) {
      buf[len++] = (Char)(Int)((CONS)str)->hd;
      str = ((CONS)str)->tl;
    }
	buf[len] = 0;
	
    return buf;
}

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
    /*if(ia->this == ib->this)
        printf("gonna return true\n");
    else
        printf("gonna return false\n");*/
    return (ia->this == ib->this);
}

Bool compareComponents_CTCommon (Bool targetValue, Component_CTCommon a, Component_CTCommon b) {
    internal_CocoaID_CTCommon ia = (internal_CocoaID_CTCommon)(a->id_CTCommon);
    internal_CocoaID_CTCommon ib = (internal_CocoaID_CTCommon)(b->id_CTCommon);   
    /*printf("comparing ids. #1: %p, #2:%p \n", ia->this, ib->this);  
    if(ia->this == ib->this)
        printf("gonna return true\n");
    else
        printf("gonna return false\n");*/
    return (targetValue == (ia->this == ib->this));
}

Bool compareKeys_CTCommon(Bool targetValue, CocoaKey_CTCommon aKey, CocoaKey_CTCommon anotherKey) {
    return (targetValue == (((int)aKey == (int)anotherKey)));
}

Bool compareState_CTCommon(Bool targetValue, CocoaState_CTCommon aState, CocoaState_CTCommon anotherState) {
    return (targetValue == (((int)aState == (int)anotherState)));
}

void _init_external_CTCommon(void) {
    // Nothing
}