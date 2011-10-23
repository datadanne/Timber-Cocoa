#include "CTButton.extern.h"
                    
// --------- Button ----------------------------------------------
TUP0 buttonSetTitle_CTButton(Int cocoaRef, LIST s) {
	NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
	NSButton *thisButton = (NSButton*) cocoaRef;
	char* buf = listToChars(s);
	[thisButton setTitle:[NSString stringWithFormat:@"%s", buf]];
	[thisButton sizeToFit]; //setNeedsDisplay???
	[pool drain];
} 
TUP0 buttonSetPosition_CTButton(Int cocoaRef, Position_COCOA pos) {
	NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
	NSButton *thisButton = (NSButton*) cocoaRef;
//	NSPoint p = NSMakePoint(pos->x_COCOA-6,pos->y_COCOA-21); // TODO: Remove hardcoded offset.	
	NSPoint p = NSMakePoint(pos->x_COCOA,pos->y_COCOA); // TODO: Remove hardcoded offset.	
	[thisButton setFrameOrigin: p];
	[thisButton performSelectorOnMainThread:@selector(setNeedsDisplay) withObject:nil waitUntilDone:YES];
   	[pool drain]; 
}

Size_COCOA buttonSetSize_CTButton(Int cocoaRef, Size_COCOA size) {
	NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
	NSButton *thisButton = (NSButton*) cocoaRef;
    NSRect rr = [thisButton frame];
    //NSLog(@"%f, %f, %f, %f--bounds\n", rr.origin.x, rr.origin.y, rr.size.width, rr.size.height);
    NSSize newS = NSMakeSize(size->width_COCOA, rr.size.height); //TODO
    [thisButton setFrameSize: newS];
    rr = [thisButton frame];

    Size_COCOA toSize_22;
    NEW (Size_COCOA, toSize_22, WORDS(sizeof(struct Size_COCOA)));
    toSize_22->GCINFO = __GC__Size_COCOA;
    toSize_22->width_COCOA = rr.size.width;
    toSize_22->height_COCOA = rr.size.height;

   	[pool drain]; 
	return toSize_22;
}

Int initButton_CTButton(LIST s) {
	NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];	
	NSButton *thisButton = [[NSButton alloc] initWithFrame: NSMakeRect(0.0, 0.0, 120.0, 60.0)];
	char* buf = listToChars(s);
	[thisButton setBezelStyle:NSRoundedBezelStyle];
	[thisButton setTitle:[NSString stringWithFormat:@"%s", buf]];
	[thisButton sizeToFit];
	[pool drain];
	return (Int)thisButton;
}

void _init_external_CTButton(void) {
    // Nothing
}