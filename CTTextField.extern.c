#include "CTTextField.extern.h"
// --------- TextField ----------------------------------------------
Int initTextField_CTTextField(TUP0 d) {
    __block NSTextField *cocoaTextField;
    dispatch_sync(dispatch_get_main_queue(), ^{
        NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];	
        cocoaTextField = [[NSTextField alloc] initWithFrame: NSMakeRect(20.0, 20.0, 120.0, 60.0)];
        [cocoaTextField setBezelStyle:NSRoundedBezelStyle];
        [cocoaTextField setStringValue: @"defaultTextFieldString"];
        [pool drain];
    });
    return (Int)cocoaTextField;
}

TUP0 textFieldSetText_CTTextField(Int cocoaRef, LIST str) {
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

TUP0 textFieldSetPosition_CTTextField(Int cocoaRef, Position_CocoaDef pos) {
    int x = pos->x_CocoaDef-5;
    int y = pos->y_CocoaDef-20; // TODO: Remove hardcoded offset.
    dispatch_async(dispatch_get_main_queue(), ^{
        NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
        NSTextField *thisTextField = (NSTextField*) cocoaRef;
        NSPoint p = NSMakePoint(x,y); 
        [thisTextField setFrameOrigin: p];
        [thisTextField setNeedsDisplay];
        [pool drain]; 
    });
}                                            

void _init_external_CTTextField(void) {
    // Nothing
}