#include "CTTextField.extern.h"
// --------- TextField ----------------------------------------------
Int initTextField_CTTextField(World w, Int dummy) {
    __block NSTextField *cocoaTextField;
    dispatch_sync(dispatch_get_main_queue(), ^{
        NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];	
        cocoaTextField = [[NSTextField alloc] initWithFrame: NSMakeRect(0.0, 0.0, 120.0, 20.0)];
        [cocoaTextField setBezelStyle:NSRoundedBezelStyle];
        [cocoaTextField setStringValue: @"defaultTextFieldString"];
        [pool drain];
    });
    return (Int)cocoaTextField;
}

TUP0 textFieldSetText_CTTextField(Int cocoaRef, LIST str, Int dummy) {
	char* buf = listToChars(str);
    dispatch_async(dispatch_get_main_queue(), ^{
        NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
        NSTextField *thisTextField = (NSTextField*) cocoaRef;
        [thisTextField setStringValue: [NSString stringWithFormat:@"%s", buf]];
        [thisTextField setNeedsDisplay];
        [pool drain];
        free(buf);
    });
}

TUP0 textFieldSetPosition_CTTextField(Int cocoaRef, Position_CocoaDef pos, Int dummy) {
    int x = pos->x_CocoaDef;
    int y = pos->y_CocoaDef;
    dispatch_async(dispatch_get_main_queue(), ^{
        NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
        NSTextField *thisTextField = (NSTextField*) cocoaRef;
        NSPoint p = NSMakePoint(x,y); 
        [thisTextField setFrameOrigin: p];
        [thisTextField setNeedsDisplay];
        [pool drain]; 
    });
}                

Size_CocoaDef textFieldSetSize_CTTextField(Int cocoaRef, Size_CocoaDef size, Int dummy) {
    int width = size->width_CocoaDef;
    __block Size_CocoaDef newSize;
    dispatch_sync(dispatch_get_main_queue(), ^{    
        NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
        NSTextField *thisField = (NSTextField*) cocoaRef;
        NSRect rr = [thisField frame];
        NSSize newS = NSMakeSize(width, rr.size.height);
        [thisField setFrameSize: newS];
        rr = [thisField frame];
        NEW (Size_CocoaDef, newSize, WORDS(sizeof(struct Size_CocoaDef)));
        newSize->GCINFO = __GC__Size_CocoaDef;
        newSize->width_CocoaDef = rr.size.width -13; // compensate for x-borders
        newSize->height_CocoaDef = rr.size.height -11; // compensate for y-borders
        [pool drain]; 
    });
    return newSize;
}                            

void _init_external_CTTextField(void) {
    // Do nothing
}