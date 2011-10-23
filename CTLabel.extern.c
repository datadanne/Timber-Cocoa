#include "CTLabel.extern.h"


Msg labelSetTextColor_CTLabel (CocoaID_COCOA id, Color_COCOA c, Time start, Time stop) {     
	NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
	DEBUG("Setting label text..");                                    
	
	NSTextField *thisLabel = (NSTextField*) COCOA_REF(id);
	DEBUG("Label pointer OK %p!", thisLabel);

	[thisLabel setTextColor:[NSColor colorWithCalibratedRed:c->r_COCOA/255.0 green:c->g_COCOA/255.0 blue:c->b_COCOA/255.0 alpha:1.0]];
	[thisLabel setNeedsDisplay];
	
	[pool drain]; 
}                         

Msg labelSetText_CTLabel (CocoaID_COCOA id, LIST s, Time start, Time stop) {
	NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
	DEBUG("Setting label text..");                                    
	
	NSTextField *thisLabel = (NSTextField*) COCOA_REF(id);
	DEBUG("Label pointer OK %p!", thisLabel);
	
	char* buf = listToChars(s); 
	
    [thisLabel setStringValue:[NSString stringWithFormat:@"%s", buf]];
	[thisLabel setNeedsDisplay];
	
	[pool drain];
}               
Msg labelSetSize_CTLabel (CocoaID_COCOA id, Size_COCOA pos, Time start, Time stop) {
	NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
	DEBUG("setting containerSize ext!");
	NSView *thisView = (NSView*) (((internal_CocoaID_COCOA) id)->this); 
	[thisView setFrameSize: NSMakeSize(pos->width_COCOA, pos->height_COCOA)];
	[pool drain];
} 
Msg labelSetPosition_CTLabel (CocoaID_COCOA id, Position_COCOA pos, Time start, Time stop) {
	NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
	DEBUG("setting POS externally..");
	
	NSTextField *thisLabel = (NSTextField*) COCOA_REF(id);
	
	DEBUG("Button(pos) OK %p!", thisLabel);
	NSPoint p = NSMakePoint(pos->x_COCOA,pos->y_COCOA); // TODO: Remove hardcoded offset.
	
	[thisLabel setFrameOrigin: p];
	[thisLabel performSelectorOnMainThread:@selector(setNeedsDisplay) withObject:nil waitUntilDone:YES];
   	[pool drain]; 
}                                            

TUP0 initLabel_CTLabel (Label_CTLabel label, App_COCOA app, Int dummy) {
	NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];	
	DEBUG("Initializing NSLabel: ");
	internal_CocoaID_COCOA thisLabel = (internal_CocoaID_COCOA)(label->l_Label_CTLabel_Component_COCOA_CTLabel->id_COCOA);

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

void _init_external_CTLabel(void) {
    // Nothing
}