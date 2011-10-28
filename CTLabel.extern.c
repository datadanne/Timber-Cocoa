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
    int r = r_CocoaDef;
    int g = g_CocoaDef;
    int b = b_CocoaDef;
    dispatch_async(dispatch_get_main_queue(), ^{
        NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];	
        NSTextField *thisLabel = (NSTextField*) cocoaRef;
        NSColor color = NSColor colorWithCalibratedRed:color->r/255.0 
            green:color->g/255.0 blue:color->b/255.0 alpha:1.0
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
    int width = width_CocoaDef;
    int height = height_CocoaDef;
    dispatch_async(dispatch_get_main_queue(), ^{
        NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
        NSTextField *thisLabel = (NSTextField*) cocoaRef;
        NSSize size0 = NSMakeSize(size->width,size->height);
        [thisLabel setFrameSize: size0];
        [pool drain];
    });
}

TUP0 labelSetPosition_CTLabel(Int cocoaRef, Position_CocoaDef pos) {
    int x = pos->x_CocoaDef;
    int y = pos->y_CocoaDef;
    dispatch_async(dispatch_get_main_queue(), ^{
        NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
        NSTextField *thisLabel = (NSTextField*) cocoaRef;
        NSPoint p = NSMakePoint(x,y);
        [thisLabel setFrameOrigin: p];
        [thisLabel setNeedsDisplay];
        [pool drain]; 
    });
}                                            

void _init_external_CTLabel(void) {
    // Nothing
}