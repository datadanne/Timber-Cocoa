#include "CTLabel.extern.h"

Int initLabel_CTLabel(TUP0 dummy) {
    __block NSTextField *textField;
    dispatch_sync(dispatch_get_main_queue(), ^{
        NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];	
        textField = [[NSTextField alloc] initWithFrame:NSMakeRect(10, 10, 200, 17)];
        [textField setStringValue:@"defaultLabelString"];
        [textField setBezeled:NO];
        [textField setDrawsBackground:NO];
        [textField setEditable:NO];
        [textField setSelectable:NO];
        [pool drain];
    });
	return (Int)textField;
}

TUP0 labelSetTextColor_CTLabel(Int cocoaRef, Color_CocoaDef color) {
    NSColor color = NSColor colorWithCalibratedRed:color->r_CocoaDef/255.0 
        green:color->g_CocoaDef/255.0 blue:color->b_CocoaDef/255.0 alpha:1.0
    dispatch_async(dispatch_get_main_queue(), ^{
        NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];	
        NSTextField *thisLabel = (NSTextField*) cocoaRef;
        [thisLabel setTextColor:[color]];
        [thisLabel setNeedsDisplay];
        [pool drain]; 
    });
}                         

TUP0 labelSetText_CTLabel(Int cocoaRef, LIST str) {
    char* buf = listToChars(str); 
    dispatch_async(dispatch_get_main_queue(), ^{
        NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
        NSTextField *thisLabel = (NSTextField*) cocoaRef;
        [thisLabel setStringValue:[NSString stringWithFormat:@"%s", buf]];
        [thisLabel setNeedsDisplay];
        [pool drain];
    });
}

TUP0 labelSetSize_CTLabel(Int cocoaRef, Size_CocoaDef size) {
    NSSize size0 = NSMakeSize(size->width_CocoaDef, size->height_CocoaDef);
    dispatch_async(dispatch_get_main_queue(), ^{
        NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
        NSTextField *thisLabel = (NSTextField*) cocoaRef;
        [thisLabel setFrameSize: size0];
        [pool drain];
    });
}

TUP0 labelSetPosition_CTLabel(Int cocoaRef, Position_CocoaDef pos) {
    NSPoint p = NSMakePoint(pos->x_CocoaDef,pos->y_CocoaDef);
    dispatch_async(dispatch_get_main_queue(), ^{
        NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
        NSTextField *thisLabel = (NSTextField*) cocoaRef;
        [thisLabel setFrameOrigin: p];
        [thisLabel performSelectorOnMainThread:@selector(setNeedsDisplay) withObject:nil waitUntilDone:YES];
        [pool drain]; 
    });
}                                            

void _init_external_CTLabel(void) {
    // Nothing
}