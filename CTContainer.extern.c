#include "CTContainer.extern.h"
#import "CTContainer.extern.m"

Int initContainer_CTContainer(TUP0 dmy) {
    __block CocoaView *cocoaView;
    dispatch_sync(dispatch_get_main_queue(), ^{
        NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
        cocoaView = [[CocoaView alloc] initWithFrame: NSMakeRect(0, 0, 1.0, 1.0)];
        [pool drain];
    });
    return (Int)cocoaView;
}

TUP0 destroyContainer_CTContainer(Int cocoaRef) {
    dispatch_async(dispatch_get_main_queue(), ^{
        NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
        CocoaView *thisView = (CocoaView*)cocoaRef;
        [thisView release];
        [pool drain];
    });
}
TUP0 containerSetBackgroundColor_CTContainer(Int containerRef, Color_CocoaDef color) {    
    int r = color->r_CocoaDef;
    int g = color->g_CocoaDef;
    int b = color->b_CocoaDef;
    dispatch_async(dispatch_get_main_queue(), ^{
        NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
        CocoaView *thisView = (CocoaView*) containerRef;
        [thisView setBackgroundColor:r:g:b];
        [pool drain];
    });
} 

TUP0 containerSetSize_CTContainer(Int containerRef, Size_CocoaDef size) {
    NSSize size0 = NSMakeSize(size->width_CocoaDef, size->height_CocoaDef);
    dispatch_async(dispatch_get_main_queue(), ^{
        NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
        CocoaView *thisView = (CocoaView*) containerRef;
        [thisView setFrameSize: size0];
        [pool drain];
    });
}

TUP0 containerSetPosition_CTContainer(Int containerRef, Position_CocoaDef pos) {
    NSPoint p = NSMakePoint(pos->x_CocoaDef,pos->y_CocoaDef);
    dispatch_async(dispatch_get_main_queue(), ^{
        NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
        CocoaView *thisContainer = (CocoaView*) containerRef;
        [thisContainer setFrameOrigin: p];
        [pool drain]; 
    });
}

TUP0 containerAddComponent_CTContainer(Int containerRef, Int cmpRef) {
    dispatch_async(dispatch_get_main_queue(), ^{
        NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
        CocoaView *thisView = (CocoaView*) containerRef;
        NSObject *object = (NSObject*) cmpRef;
        [thisView performSelectorOnMainThread:@selector(addSubview:) withObject:object waitUntilDone:YES];
        [thisView setNeedsDisplay:YES];
        [pool drain];
    });
}

TUP0 containerRemoveComponent_CTContainer(Int containerRef, Int cmpRef) {
    dispatch_async(dispatch_get_main_queue(), ^{
        NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
        CocoaView *thisView = (CocoaView*) containerRef;
        NSView *object = (NSView*) cmpRef;
        [object performSelectorOnMainThread:@selector(removeFromSuperview) withObject:nil waitUntilDone:YES];
        [pool drain];
    });
}

void _init_external_CTContainer(void) {
}