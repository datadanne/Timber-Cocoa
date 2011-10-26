#include "CTLabel.extern.h"

Int initLabel_CTLabel(TUP0 dummy) {
	NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];	
	NSTextField *textField = [[NSTextField alloc] initWithFrame:NSMakeRect(10, 10, 200, 17)];
    [textField setStringValue:@"defaultLabelString"];
    [textField setBezeled:NO];
    [textField setDrawsBackground:NO];
    [textField setEditable:NO];
    [textField setSelectable:NO];
	[pool drain];
	return (Int)textField;
}

TUP0 labelSetTextColor_CTLabel(Int cocoaRef, Color_CocoaDef color) {
	NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];	
    NSTextField *thisLabel = (NSTextField*) cocoaRef;
	[thisLabel setTextColor:[NSColor colorWithCalibratedRed:color->r_CocoaDef/255.0 green:color->g_CocoaDef/255.0 blue:color->b_CocoaDef/255.0 alpha:1.0]];
	[thisLabel setNeedsDisplay];
	[pool drain]; 
}                         

TUP0 labelSetText_CTLabel(Int cocoaRef, LIST str) {
	NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
    NSTextField *thisLabel = (NSTextField*) cocoaRef;
	char* buf = listToChars(str); 
    [thisLabel setStringValue:[NSString stringWithFormat:@"%s", buf]];
	[thisLabel setNeedsDisplay];
	[pool drain];
}

TUP0 labelSetSize_CTLabel(Int cocoaRef, Size_CocoaDef size) {
	NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
    NSTextField *thisLabel = (NSTextField*) cocoaRef;
	[thisLabel setFrameSize: NSMakeSize(size->width_CocoaDef, size->height_CocoaDef)];
	[pool drain];
}

TUP0 labelSetPosition_CTLabel(Int cocoaRef, Position_CocoaDef pos) {
	NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
    NSTextField *thisLabel = (NSTextField*) cocoaRef;
	NSPoint p = NSMakePoint(pos->x_CocoaDef,pos->y_CocoaDef); // TODO: Remove hardcoded offset.
	[thisLabel setFrameOrigin: p];
	[thisLabel performSelectorOnMainThread:@selector(setNeedsDisplay) withObject:nil waitUntilDone:YES];
   	[pool drain]; 
}                                            

void _init_external_CTLabel(void) {
    // Nothing
}