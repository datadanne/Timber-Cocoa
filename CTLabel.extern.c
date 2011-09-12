#include "CTLabel.extern.h"


Msg labelSetTextColor_CTLabel (CocoaID_CTCommon id, Color_CTCommon c, Time start, Time stop) {     
	NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
	DEBUG("Setting label text..");                                    
	
	NSTextField *thisLabel = (NSTextField*) COCOA_REF(id);
	DEBUG("Label pointer OK %p!", thisLabel);

	[thisLabel setTextColor:[NSColor colorWithCalibratedRed:c->r_CTCommon/255 green:c->g_CTCommon blue:c->b_CTCommon alpha:1.0]];
	[thisLabel setNeedsDisplay];
	
	[pool drain]; 
}                         

Msg labelSetText_CTLabel (CocoaID_CTCommon id, LIST s, Time start, Time stop) {
	NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
	DEBUG("Setting label text..");                                    
	
	NSTextField *thisLabel = (NSTextField*) COCOA_REF(id);
	DEBUG("Label pointer OK %p!", thisLabel);
	
	char* buf = listToChars(s); 
	
    [thisLabel setStringValue:[NSString stringWithFormat:@"%s", buf]];
	[thisLabel setNeedsDisplay];
	
	[pool drain];
}               
Msg labelSetSize_CTLabel (CocoaID_CTCommon id, Size_CTCommon pos, Time start, Time stop) {
	NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
	DEBUG("setting containerSize ext!");
	NSView *thisView = (NSView*) (((internal_CocoaID_CTCommon) id)->this); 
	[thisView setFrameSize: NSMakeSize(pos->width_CTCommon, pos->height_CTCommon)];
	[pool drain];
} 
Msg labelSetPosition_CTLabel (CocoaID_CTCommon id, Position_CTCommon pos, Time start, Time stop) {
	NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
	DEBUG("setting POS externally..");
	
	NSTextField *thisLabel = (NSTextField*) COCOA_REF(id);
	
	DEBUG("Button(pos) OK %p!", thisLabel);
	NSPoint p = NSMakePoint(pos->x_CTCommon-5,pos->y_CTCommon-20); // TODO: Remove hardcoded offset.
	
	[thisLabel setFrameOrigin: p];
	[thisLabel performSelectorOnMainThread:@selector(setNeedsDisplay) withObject:nil waitUntilDone:YES];
   	[pool drain]; 
}                                            

TUP0 initLabel_CTLabel (Label_CTLabel label, App_CTCommon app, Int dummy) {
	NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];	
	DEBUG("Initializing NSLabel: ");
	internal_CocoaID_CTCommon thisLabel = (internal_CocoaID_CTCommon)(label->l_Label_CTLabel_Component_CTCommon_CTLabel->id_CTCommon);

	NSTextField *textField = [[NSTextField alloc] initWithFrame:NSMakeRect(10, 10, 200, 17)];
    [textField setStringValue:@"My Label"];
    [textField setBezeled:NO];
    [textField setDrawsBackground:NO];
    [textField setEditable:NO];
    [textField setSelectable:NO];
	
	thisLabel->this = textField;
	DEBUG("Label OK %p!", thisLabel->this);

	[pool drain];
	return 0;
}