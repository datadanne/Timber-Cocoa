#include "CTContainer.extern.h"
#import "CTContainer.extern.m"


// --------- Container ----------------------------------------------
Msg containerAddComponent_CTContainer (CocoaID_COCOA container, Int buttonRef, Time start, Time stop) {
    NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
	
	CocoaView *thisView = (CocoaView*) COCOA_REF(container);
	NSObject *object = (NSObject*) buttonRef;

	[thisView performSelectorOnMainThread:@selector(addSubview:) withObject:object waitUntilDone:YES];
    [thisView setNeedsDisplay:YES];
    [pool drain];

}
Msg containerSetBackgroundColor_CTContainer (CocoaID_COCOA id, Color_COCOA c, Time start, Time stop) { 
	NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
	CocoaView *thisView = (CocoaView*) COCOA_REF(id);

    int r = c->r_COCOA;
    int g = c->g_COCOA;
    int b = c->b_COCOA;
	[thisView setBackgroundColor:r:g:b];
    
	[pool drain];
} 
Msg containerSetSize_CTContainer (CocoaID_COCOA id, Size_COCOA pos, Time start, Time stop) {
	NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
	DEBUG("setting containerSize ext!\n");
	CocoaView *thisView = (CocoaView*) (((internal_CocoaID_COCOA) id)->this); 
	[thisView setFrameSize: NSMakeSize(pos->width_COCOA, pos->height_COCOA)];
	[pool drain];
}
Msg containerSetPosition_CTContainer (CocoaID_COCOA id, Position_COCOA pos, Time start, Time stop) {
	NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
    DEBUG("setting position on container ext!\n");
	CocoaView *thisContainer = (CocoaView*) COCOA_REF(id);
	[thisContainer setFrameOrigin: NSMakePoint(pos->x_COCOA,pos->y_COCOA)];
   	[pool drain]; 
}
TUP0 initContainer_CTContainer (/*Container_CTContainer container*/CocoaID_COCOA id, App_COCOA app, Int dummy) {
    internal_CocoaID_COCOA thisContainer = (internal_CocoaID_COCOA)id;
    
    NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
	DEBUG("Initializing NSContainer: \n");
	
    CocoaView *cocoaView = [[CocoaView alloc] initWithFrame: NSMakeRect(0, 0, 0.0, 0.0)];

	thisContainer->this = cocoaView;

	DEBUG("Container OK! %p\n", cocoaView);
	[pool drain];

	return 0;
}
Msg destroyContainer_CTContainer (CocoaID_COCOA container, Time start, Time stop) {
    NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
    CocoaView *thisView = (CocoaView*) COCOA_REF(container);
    [thisView release];
    [pool drain];
}

Msg containerRemoveComponent_CTContainer (CocoaID_COCOA container, CocoaID_COCOA newCmp, Time start, Time stop) {
    NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
	CocoaView *thisView = (CocoaView*) COCOA_REF(container);
	NSView *object = (NSView*) COCOA_REF(newCmp);
    [object performSelectorOnMainThread:@selector(removeFromSuperview) withObject:nil waitUntilDone:YES];
    [pool drain];
}

void _init_external_CTContainer(void) {
    // Nothing
}