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
	__block CocoaView *thisView = (CocoaView*) COCOA_REF(id);
	printf("setting containerBgColor ext!\n");
	                        
	
    int r = 5;
    printf("R is ok =D\n");
    printf("can haz C? %p \n", c);
    int g = c->g_CTCommon;
    int b = c->b_CTCommon;
    
    printf("rgb is ok? \n"); 
    dispatch_sync(dispatch_get_main_queue(), ^{
        printf("can i run mainqueue plz?? %p\n", thisView); 
        printf("R: %d, G: %d, B: %d\n", r, g, b);
	    [thisView setBackgroundColor:r:g:b]; 
        printf("oh hello?? \n");
    });                         
    printf("im back!\n");
	[pool drain];
} 
Msg containerSetSize_CTContainer (CocoaID_CTCommon id, Size_CTCommon pos, Time start, Time stop) {
	NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
	printf("setting containerSize ext!\n");
	__block CocoaView *thisView = (CocoaView*) (((internal_CocoaID_CTCommon) id)->this); 
    dispatch_sync(dispatch_get_main_queue(), ^{
	    [thisView setFrameSize: NSMakeSize(pos->width_CTCommon, pos->height_CTCommon)];
    });
	[pool drain];
}
Msg containerSetPosition_CTContainer (CocoaID_CTCommon id, Position_CTCommon pos, Time start, Time stop) {
	NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
    printf("setting position on container ext!\n");
	__block CocoaView *thisContainer = (CocoaView*) COCOA_REF(id);
    dispatch_sync(dispatch_get_main_queue(), ^{
	    [thisContainer setFrameOrigin: NSMakePoint(pos->x_CTCommon,pos->y_CTCommon)];
    });
   	[pool drain]; 
}
TUP0 initContainer_CTContainer (/*Container_CTContainer container*/CocoaID_CTCommon id, App_CTCommon app, Int dummy) {
    internal_CocoaID_CTCommon thisContainer = (internal_CocoaID_CTCommon)id;//(internal_CocoaID_CTCommon)(container->l_Container_CTContainer_Component_CTCommon_CTContainer->id_CTCommon);	
	__block CocoaView *cocoaView;
    NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
	printf("Initializing NSContainer: \n");
	
    dispatch_sync(dispatch_get_main_queue(), ^{
        cocoaView = [[CocoaView alloc] initWithFrame: NSMakeRect(0, 0, 200.0, 200.0)];
    });

	thisContainer->this = cocoaView;

	printf("Container OK! %p\n", cocoaView);
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