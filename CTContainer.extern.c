#include "CTContainer.extern.h"
#import "CTContainer.extern.m"


// --------- Container ----------------------------------------------
Msg containerAddComponent_CTContainer (CocoaID_CTCommon container, CocoaID_CTCommon button, Time start, Time stop) {
	CocoaView *thisView = (CocoaView*) COCOA_REF(container);
	NSObject *object = (NSObject*) COCOA_REF(button);

	[thisView performSelectorOnMainThread:@selector(addSubview:) withObject:object waitUntilDone:YES];
    [thisView setNeedsDisplay:YES];

}
Msg containerSetBackgroundColor_CTContainer (CocoaID_CTCommon id, Color_CTCommon c, Time start, Time stop) { 
	NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
	CocoaView *thisView = (CocoaView*) COCOA_REF(id);
	DEBUG("setting containerBgColor ext!");
	[thisView setBackgroundColor:c->r_CTCommon:c->g_CTCommon:c->b_CTCommon];
	[pool drain];
} 
Msg containerSetSize_CTContainer (CocoaID_CTCommon id, Size_CTCommon pos, Time start, Time stop) {
	NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
	DEBUG("setting containerSize ext!\n");
	CocoaView *thisView = (CocoaView*) (((internal_CocoaID_CTCommon) id)->this); 
	[thisView setFrameSize: NSMakeSize(pos->width_CTCommon, pos->height_CTCommon)];
	[pool drain];
}
Msg containerSetPosition_CTContainer (CocoaID_CTCommon id, Position_CTCommon pos, Time start, Time stop) {
	NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
	CocoaView *thisContainer = (CocoaView*) COCOA_REF(id);
	[thisContainer setFrameOrigin: NSMakePoint(pos->x_CTCommon,pos->y_CTCommon)];
   	[pool drain]; 
}
TUP0 initContainer_CTContainer (/*Container_CTContainer container*/CocoaID_CTCommon id, App_CTCommon app, Int dummy) {
    internal_CocoaID_CTCommon thisContainer = (internal_CocoaID_CTCommon)id;//(internal_CocoaID_CTCommon)(container->l_Container_CTContainer_Component_CTCommon_CTContainer->id_CTCommon);	
	CocoaView *cocoaView;
    NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
	DEBUG("Initializing NSContainer: ");
    cocoaView = [[CocoaView alloc] initWithFrame: NSMakeRect(0, 0, 200.0, 200.0)];

	thisContainer->this = cocoaView;

	DEBUG("Container OK!");
	[pool drain];

	return 0;
}
Msg destroyContainer_CTContainer (CocoaID_CTCommon container, Time start, Time stop) {
    NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
    CocoaView *thisView = (CocoaView*) COCOA_REF(container);
    [thisView release];
    [pool drain];
}

Msg containerRemoveComponent_CTContainer (CocoaID_CTCommon container, CocoaID_CTCommon newCmp, Time start, Time stop) {
    NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
	CocoaView *thisView = (CocoaView*) COCOA_REF(container);
	NSView *object = (NSView*) COCOA_REF(newCmp);
    [object performSelectorOnMainThread:@selector(removeFromSuperview) withObject:nil waitUntilDone:YES];
    [pool drain];
}

void _init_external_CTContainer(void) {
    // Nothing
}