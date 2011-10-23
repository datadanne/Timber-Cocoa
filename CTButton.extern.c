#include "CTButton.extern.h"
                    
// --------- Button ----------------------------------------------
Msg buttonSetTitle_CTButton(CocoaID_COCOA id, LIST s, Time start, Time stop) {
	NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
	DEBUG("external method setTitle :DD");
	NSButton *thisButton = (NSButton*) COCOA_REF(id);
	DEBUG("Button OK %p!", thisButton);
	char* buf = listToChars(s);
	[thisButton setTitle:[NSString stringWithFormat:@"%s", buf]];
	[thisButton setNeedsDisplay];
	[pool drain];
} 
Msg buttonSetPosition_CTButton(CocoaID_COCOA id, Position_COCOA pos, Time start, Time stop) {
	NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
	DEBUG("setting POS externally..");
	
	NSButton *thisButton = (NSButton*) COCOA_REF(id);
	
	DEBUG("Button(pos) OK %p!", thisButton);
	NSPoint p = NSMakePoint(pos->x_COCOA-6,pos->y_COCOA-21); // TODO: Remove hardcoded offset.
	
	[thisButton setFrameOrigin: p];
	[thisButton performSelectorOnMainThread:@selector(setNeedsDisplay) withObject:nil waitUntilDone:YES];
   	[pool drain]; 
}
Msg buttonSetSize_CTButton(CocoaID_COCOA id, Size_COCOA size, Time start, Time stop) {
	NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
	NSButton *thisButton = (NSButton*) COCOA_REF(id);
                 
    NSRect rr = [thisButton frame];
    NSLog(@"%f, %f, %f, %f--bounds\n", rr.origin.x, rr.origin.y, rr.size.width, rr.size.height);
    
    //[thisButton setBounds: NSMakeRect(rr.origin.x, rr.origin.y, size->width_COCOA, size->height_COCOA)];
    //[thisButton setFrame: NSMakeRect(rr.origin.x, rr.origin.y, size->width_COCOA, size->height_COCOA)];
    
    NSSize newS = NSMakeSize(size->width_COCOA, rr.size.height);
    [thisButton setFrameSize: newS];
    //for(int i=0;i<1000;i++);
    
    rr = [thisButton frame];
    NSLog(@"--%f, %f, %f, %f\n", rr.origin.x, rr.origin.y, rr.size.width, rr.size.height);


   	[pool drain];     
}

Msg buttonHighlight_CTButton(CocoaID_COCOA id, Time start, Time stop) {
	NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
	NSButton *thisButton = (NSButton*) COCOA_REF(id);	
	[thisButton highlight:YES];
   	[pool drain]; 
}                           

TUP0 initButton_CTButton(Button_CTButton button, App_COCOA app, Int dummy) {
	NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];	
	DEBUG("Initializing NSButton: ");
	internal_CocoaID_COCOA thisButton = (internal_CocoaID_COCOA)(button->l_Button_CTButton_Component_COCOA_CTButton->id_COCOA);

	NSButton *cocoaButton = [[NSButton alloc] initWithFrame: NSMakeRect(0.0, 0.0, 120.0, 60.0)];
	[cocoaButton setBezelStyle:NSRoundedBezelStyle];
	[cocoaButton setTitle: @"KNAPP!"];
	
	thisButton->this = cocoaButton;
	DEBUG("Button OK %p!", thisButton->this);

	[pool drain];
	return 0;
}

void _init_external_CTButton(void) {
    // Nothing
}