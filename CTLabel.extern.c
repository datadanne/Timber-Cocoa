#include "CTLabel.extern.h"
#import <Cocoa/Cocoa.h>

Int initLabel_CTLabel(World w, Int dummy) {
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

TUP0 labelSetTextColor_CTLabel(Int cocoaRef, Color_CocoaDef color, Int dummy) {
    float r = color->r_CocoaDef/255.0;
    float g = color->g_CocoaDef/255.0;
    float b = color->b_CocoaDef/255.0;
    dispatch_async(dispatch_get_main_queue(), ^{
        NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];	
        NSTextField *thisLabel = (NSTextField*) cocoaRef;
        NSColor *color = [NSColor colorWithCalibratedRed:r green:g blue:b alpha:1.0];
        [thisLabel setTextColor:color];
        [thisLabel setNeedsDisplay];
        [pool drain]; 
    });
}                         

TUP0 labelSetText_CTLabel(Int cocoaRef, LIST str, Int dummy) {
    char* buf = listToChars(str); 
    dispatch_async(dispatch_get_main_queue(), ^{
        NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
        NSTextField *thisLabel = (NSTextField*) cocoaRef;
        [thisLabel setStringValue:[NSString stringWithFormat:@"%s", buf]];
        [thisLabel setNeedsDisplay];
        [pool drain];
        free(buf);
    });
}

TUP0 labelSetSize_CTLabel(Int cocoaRef, Size_CocoaDef size, Int dummy) {
    int width = size->width_CocoaDef;
    int height = size->height_CocoaDef;
    dispatch_async(dispatch_get_main_queue(), ^{
        NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
        NSTextField *thisLabel = (NSTextField*) cocoaRef;
        NSSize size0 = NSMakeSize(width,height);
        [thisLabel setFrameSize: size0];
        [pool drain];
    });
}

TUP0 labelSetPosition_CTLabel(Int cocoaRef, Position_CocoaDef pos, Int dummy) {
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
    // Do nothing
}