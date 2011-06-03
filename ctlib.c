#include "ctlib.h"
#include "CocoaHelpers.m"

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