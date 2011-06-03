#include "CTButton.extern.h"
                    
// --------- Button ----------------------------------------------
Msg buttonSetTitle_CTButton(CocoaID_CTCommon id, LIST s, Time start, Time stop) {
	NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
	DEBUG("external method setTitle :DD");
	NSButton *thisButton = (NSButton*) COCOA_REF(id);
	DEBUG("Button OK %p!", thisButton);
	char* buf = listToChars(s);
	[thisButton setTitle:[NSString stringWithFormat:@"%s", buf]];
	[thisButton setNeedsDisplay];
	[pool drain];
} 
Msg buttonSetPosition_CTButton(CocoaID_CTCommon id, Position_CTCommon pos, Time start, Time stop) {
	NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
	DEBUG("setting POS externally..");
	
	NSButton *thisButton = (NSButton*) COCOA_REF(id);
	
	DEBUG("Button(pos) OK %p!", thisButton);
	NSPoint p = NSMakePoint(pos->x_CTCommon-5,pos->y_CTCommon-20); // TODO: Remove hardcoded offset.
	
	[thisButton setFrameOrigin: p];
	[thisButton performSelectorOnMainThread:@selector(setNeedsDisplay) withObject:nil waitUntilDone:YES];
   	[pool drain]; 
}                                            

TUP0 initButton_CTButton(Button_CTButton button, App_CTCommon app, Int dummy) {
	NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];	
	DEBUG("Initializing NSButton: ");
	internal_CocoaID_CTCommon thisButton = (internal_CocoaID_CTCommon)(button->l_Button_CTButton_Component_CTCommon_CTButton->id_CTCommon);

	NSButton *cocoaButton = [[NSButton alloc] initWithFrame: NSMakeRect(20.0, 20.0, 120.0, 60.0)];
	[cocoaButton setBezelStyle:NSRoundedBezelStyle];
	[cocoaButton setTitle: @"KNAPP!"];
	
	thisButton->this = cocoaButton;
	DEBUG("Button OK %p!", thisButton->this);

	[pool drain];
	return 0;
} 

