#include "CTDropDown.extern.h"

#import "CTDropDown.extern.m"

// --------- DropDown ----------------------------------------------

Int initDropDown_CTDropDown(World w, Int dummy) {
    __block NSPopUpButton *cocoaDropDown;
    dispatch_sync(dispatch_get_main_queue(), ^{
	    NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];	
	    cocoaDropDown = [[NSPopUpButton alloc] initWithFrame: NSMakeRect(0.0, 0.0, 120.0, DROPDOWN_HEIGHT) pullsDown:FALSE];
	    [cocoaDropDown setBezelStyle:NSRoundedBezelStyle];
	    [cocoaDropDown setTitle: @"dropDownDefaultTitle"];
	
        // ACTION-handler
        DropDownClickHandler *dropper = [[DropDownClickHandler alloc] init];
        [cocoaDropDown setAction: @selector(dropDownClicked:)];
        [cocoaDropDown setTarget: dropper];
	    [pool drain];
    });
	return (Int)cocoaDropDown;
} 

TUP0 dropDownAddOption_CTDropDown(Int cocoaRef, LIST str, Int dummy) {
	char* buf = listToChars(str);    
    dispatch_async(dispatch_get_main_queue(), ^{
        NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
	    NSPopUpButton *thisDropDown = (NSPopUpButton*) cocoaRef;
	    [thisDropDown addItemWithTitle:[NSString stringWithFormat:@"%s", buf]];
	    [thisDropDown setNeedsDisplay];
	    [pool drain];
        free(buf);
    });
}

LIST dropDownGetSelectedOption_CTDropDown(Int cocoaRef, Int dummy) {
    __block LIST s;
    dispatch_sync(dispatch_get_main_queue(), ^{
	    NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];	
	    NSPopUpButton *thisDropDown = (NSPopUpButton*) cocoaRef;
        const char *optionStr = [[thisDropDown titleOfSelectedItem] UTF8String]; 
        s = getStr((char *) optionStr);
        [pool drain]; 
    });
    return s;
}

TUP0 dropDownSetPosition_CTDropDown(Int cocoaRef, Position_CocoaDef pos, Int dummy) {
    int x = pos->x_CocoaDef;
    int y = pos->y_CocoaDef;
    dispatch_async(dispatch_get_main_queue(), ^{
	    NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
        NSPopUpButton *thisDropDown = (NSPopUpButton*) cocoaRef;
        [[thisDropDown target] setCoordsX: x andY: y];
        NSPoint p = NSMakePoint(x,y);
	    [thisDropDown setFrameOrigin: p];
	    [thisDropDown setNeedsDisplay];
   	    [pool drain]; 
    });
}

Size_CocoaDef dropDownSetSize_CTDropDown(Int cocoaRef, Size_CocoaDef size, Int dummy) {
    int width = size->width_CocoaDef;
    __block Size_CocoaDef newSize;
    dispatch_sync(dispatch_get_main_queue(), ^{
	    NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];	
	    NSPopUpButton *thisDropDown = (NSPopUpButton*) cocoaRef;
        [[thisDropDown target] setWidth: width andHeight: DROPDOWN_HEIGHT];	
        NSSize s = NSMakeSize(width, DROPDOWN_HEIGHT);
	    [thisDropDown setFrameSize: s];    
        NSRect rr = [thisDropDown frame];
        NEW (Size_CocoaDef, newSize, WORDS(sizeof(struct Size_CocoaDef)));
        newSize->GCINFO = __GC__Size_CocoaDef;
        newSize->width_CocoaDef = rr.size.width;
        newSize->height_CocoaDef = DROPDOWN_HEIGHT;
	    [thisDropDown setNeedsDisplay];
   	    [pool drain]; 
    });
    return newSize;
}

void _init_external_CTDropDown(void) {
    // Do nothing
}