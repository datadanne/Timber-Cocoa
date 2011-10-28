#include "CTTextField.extern.h"
// --------- TextField ----------------------------------------------
Int initTextField_CTTextField(TUP0 d) {
	NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];	
	NSTextField *cocoaTextField = [[NSTextField alloc] initWithFrame: NSMakeRect(20.0, 20.0, 120.0, 60.0)];
	[cocoaTextField setBezelStyle:NSRoundedBezelStyle];
	[cocoaTextField setStringValue: @"defaultTextFieldString"];
	[pool drain];
	return (Int)cocoaTextField;
}

TUP0 textFieldSetText_CTTextField(Int cocoaRef, LIST str) {
	NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
    NSTextField *thisTextField = (NSTextField*) cocoaRef;
	char* buf = listToChars(str);
	[thisTextField setStringValue: [NSString stringWithFormat:@"%s", buf]];
	[thisTextField setNeedsDisplay];
	[pool drain];
}

TUP0 textFieldSetPosition_CTTextField(Int cocoaRef, Position_CocoaDef pos) {
	NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
    NSTextField *thisTextField = (NSTextField*) cocoaRef;
	NSPoint p = NSMakePoint(pos->x_CocoaDef-5,pos->y_CocoaDef-20); // TODO: Remove hardcoded offset.
	
	[thisTextField setFrameOrigin: p];
    //remove performSelectorOnMainThread when executing on the main thread
	[thisTextField performSelectorOnMainThread:@selector(setNeedsDisplay) withObject:nil waitUntilDone:YES];
   	[pool drain]; 
}                                            

void _init_external_CTTextField(void) {
    // Nothing
}