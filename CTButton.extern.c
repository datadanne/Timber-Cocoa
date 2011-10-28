#include "CTButton.extern.h"
                    
// --------- Button ----------------------------------------------
TUP0 buttonSetTitle_CTButton(Int cocoaRef, LIST s) {
    char* buf = listToChars(s);
    dispatch_async(dispatch_get_main_queue(), ^{
        NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
        NSButton *thisButton = (NSButton*) cocoaRef;
        [thisButton setTitle:[NSString stringWithFormat:@"%s", buf]];
        [thisButton sizeToFit]; //setNeedsDisplay???
        [pool drain];
    });
} 

TUP0 buttonSetPosition_CTButton(Int cocoaRef, Position_CocoaDef pos) {
    int x = pos->x_CocoaDef;
    int y = pos->y_CocoaDef;
    dispatch_async(dispatch_get_main_queue(), ^{
        NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
        NSButton *thisButton = (NSButton*) cocoaRef;
        NSPoint p = NSMakePoint(x,y);
        [thisButton setFrameOrigin: p];
        [thisButton performSelectorOnMainThread:@selector(setNeedsDisplay) withObject:nil waitUntilDone:YES];
        [pool drain]; 
    });
}

Size_CocoaDef buttonSetSize_CTButton(Int cocoaRef, Size_CocoaDef size) {
    int width = size->width_CocoaDef;
    __block Size_CocoaDef newSize;
    dispatch_sync(dispatch_get_main_queue(), ^{    
        NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
        NSButton *thisButton = (NSButton*) cocoaRef;
        NSRect rr = [thisButton frame];
        NSSize newS = NSMakeSize(width, rr.size.height);
        [thisButton setFrameSize: newS];
        rr = [thisButton frame];
        NEW (Size_CocoaDef, newSize, WORDS(sizeof(struct Size_CocoaDef)));
        newSize->GCINFO = __GC__Size_CocoaDef;
        newSize->width_CocoaDef = rr.size.width;
        newSize->height_CocoaDef = rr.size.height;
        [pool drain]; 
    });
    return newSize;
}

Int initButton_CTButton(LIST s) {
	char* buf = listToChars(s);
    __block NSButton *thisButton;
    dispatch_sync(dispatch_get_main_queue(), ^{
        NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];	
        thisButton = [[NSButton alloc] initWithFrame: NSMakeRect(0.0, 0.0, 120.0, 60.0)];
        [thisButton setBezelStyle:NSRoundedBezelStyle];
        [thisButton setTitle:[NSString stringWithFormat:@"%s", buf]];
        [thisButton sizeToFit];
        [pool drain];
    });
    return (Int)thisButton;
}

void _init_external_CTButton(void) {
    // Nothing
}