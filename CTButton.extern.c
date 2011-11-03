#include "CTButton.extern.h"
#import <Cocoa/Cocoa.h>
                    
// --------- Button ----------------------------------------------
Size_CocoaDef buttonSetTitle_CTButton(Int cocoaRef, LIST s, Int dummy) {
    char* buf = listToChars(s);
    __block Size_CocoaDef newSize;
    dispatch_sync(dispatch_get_main_queue(), ^{
        NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
        NSButton *thisButton = (NSButton*) cocoaRef;
        [thisButton setTitle:[NSString stringWithFormat:@"%s", buf]];
        [thisButton sizeToFit]; 
        
        NSRect rr = [thisButton frame];
        NEW (Size_CocoaDef, newSize, WORDS(sizeof(struct Size_CocoaDef)));
        newSize->GCINFO = __GC__Size_CocoaDef;
        newSize->width_CocoaDef = rr.size.width -13; // compensate for x-borders
        newSize->height_CocoaDef = rr.size.height -11; // compensate for y-borders
        
        [pool drain];
        free(buf);
    });
    return newSize;
} 

TUP0 buttonSetPosition_CTButton(Int cocoaRef, Position_CocoaDef pos, Int dummy) {
    int x = pos->x_CocoaDef -6; // subtract x-border
    int y = pos->y_CocoaDef -4; // subtract y-border
    dispatch_async(dispatch_get_main_queue(), ^{
        NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
        NSButton *thisButton = (NSButton*) cocoaRef;
        NSPoint p = NSMakePoint(x,y);
        [thisButton setFrameOrigin: p];
        [thisButton setNeedsDisplay];
        [pool drain]; 
    });
}

Size_CocoaDef buttonSetSize_CTButton(Int cocoaRef, Size_CocoaDef size, Int dummy) {
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
        newSize->width_CocoaDef = rr.size.width -13; // compensate for x-borders
        newSize->height_CocoaDef = rr.size.height -11; // compensate for y-borders
        [pool drain]; 
    });
    return newSize;
}

Int initButton_CTButton(World w, Int dummy) {
    __block NSButton *thisButton;
    dispatch_sync(dispatch_get_main_queue(), ^{
        NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];	
        thisButton = [[NSButton alloc] initWithFrame: NSMakeRect(0.0, 0.0, 120.0, 60.0)];
        [thisButton setBezelStyle:NSRoundedBezelStyle];
        [thisButton setTitle:@"Click me!"];
        [thisButton sizeToFit];
        [pool drain];
    });
    return (Int)thisButton;
}

void _init_external_CTButton(void) {
    // Do nothing
}