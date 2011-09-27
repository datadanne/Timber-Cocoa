#include "CTDropDown.extern.h"
                    
// --------- DropDown ----------------------------------------------
Msg dropDownAddOption_CTDropDown(CocoaID_CTCommon id, LIST s, Time start, Time stop) {
	NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
	DEBUG("external method setTitle :DD");
	NSPopUpButton *thisDropDown = (NSPopUpButton*) COCOA_REF(id);
	DEBUG("DropDown OK %p!", thisDropDown);
	char* buf = listToChars(s);
	[thisDropDown addItemWithTitle:[NSString stringWithFormat:@"%s", buf]];
	[thisDropDown setNeedsDisplay];
	[pool drain];
} 
Msg dropDownSetPosition_CTDropDown(CocoaID_CTCommon id, Position_CTCommon pos, Time start, Time stop) {
	NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
	DEBUG("setting POS externally..");
	
	NSPopUpButton *thisDropDown = (NSPopUpButton*) COCOA_REF(id);
	
	DEBUG("DropDown(pos) OK %p!", thisDropDown);
	NSPoint p = NSMakePoint(pos->x_CTCommon-5,pos->y_CTCommon-20); // TODO: Remove hardcoded offset.
	
	[thisDropDown setFrameOrigin: p];
	[thisDropDown performSelectorOnMainThread:@selector(setNeedsDisplay) withObject:nil waitUntilDone:YES];
   	[pool drain]; 
}                                            

TUP0 initDropDown_CTDropDown(DropDown_CTDropDown dropDown, App_CTCommon app, Int dummy) {
	NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];	
	DEBUG("Initializing NSDropDown: ");
	internal_CocoaID_CTCommon thisDropDown = (internal_CocoaID_CTCommon)(dropDown->l_DropDown_CTDropDown_Component_CTCommon_CTDropDown->id_CTCommon);

	NSPopUpButton *cocoaDropDown = [[NSPopUpButton alloc] initWithFrame: NSMakeRect(20.0, 20.0, 120.0, 60.0) pullsDown:FALSE];
	[cocoaDropDown setBezelStyle:NSRoundedBezelStyle];
	[cocoaDropDown setTitle: @"KNAPP!"];
	
	thisDropDown->this = cocoaDropDown;
	DEBUG("DropDown OK %p!", thisDropDown->this);

	[pool drain];
	return 0;
} 

void _init_external_CTDropDown(void) {
    // Nothing
}