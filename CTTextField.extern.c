#include "CTTextField.extern.h"
                    
// --------- TextField ----------------------------------------------
Msg textFieldSetText_CTTextField(CocoaID_CTCommon id, LIST s, Time start, Time stop) {
	NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
	DEBUG("external method setTitle :DD");
	NSTextField *thisTextField = (NSTextField*) COCOA_REF(id);
	DEBUG("TextField OK %p!", thisTextField);
	char* buf = listToChars(s);
	[thisTextField setStringValue:[NSString stringWithFormat:@"%s", buf]];
	[thisTextField setNeedsDisplay];
	[pool drain];
} 
Msg textFieldSetPosition_CTTextField(CocoaID_CTCommon id, Position_CTCommon pos, Time start, Time stop) {
	NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
	DEBUG("setting POS externally..");
	
	NSTextField *thisTextField = (NSTextField*) COCOA_REF(id);
	
	DEBUG("TextField(pos) OK %p!", thisTextField);
	NSPoint p = NSMakePoint(pos->x_CTCommon-5,pos->y_CTCommon-20); // TODO: Remove hardcoded offset.
	
	[thisTextField setFrameOrigin: p];
	[thisTextField performSelectorOnMainThread:@selector(setNeedsDisplay) withObject:nil waitUntilDone:YES];
   	[pool drain]; 
}                                            

TUP0 initTextField_CTTextField(TextField_CTTextField textField, App_CTCommon app, Int dummy) {
	NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];	
	DEBUG("Initializing NSTextField: ");
	internal_CocoaID_CTCommon thisTextField = (internal_CocoaID_CTCommon)(textField->l_TextField_CTTextField_Component_CTCommon_CTTextField->id_CTCommon);

	NSTextField *cocoaTextField = [[NSTextField alloc] initWithFrame: NSMakeRect(20.0, 20.0, 120.0, 60.0)];
	[cocoaTextField setBezelStyle:NSRoundedBezelStyle];
	[cocoaTextField setStringValue: @"TEXT"];
	
	thisTextField->this = cocoaTextField;
	DEBUG("TextField OK %p!", thisTextField->this);

	[pool drain];
	return 0;
} 

