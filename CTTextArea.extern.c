#include "CTTextArea.extern.h"
#import <Cocoa/Cocoa.h>

// --------- TextArea ----------------------------------------------
Int initTextArea_CTTextArea(World w, Int dummy) {
    __block NSScrollView *scrollView;
    dispatch_sync(dispatch_get_main_queue(), ^{
        NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];	
        scrollView = [[NSScrollView alloc] initWithFrame:NSMakeRect(0, 0, 100, 100)];
        NSSize contentSize = [scrollView contentSize];
        [scrollView setBorderType: NSNoBorder];
        [scrollView setHasVerticalScroller: YES];
        [scrollView setHasHorizontalScroller: YES]; 
        
        NSTextView *theTextView = [[NSTextView alloc] 
                                    initWithFrame: NSMakeRect(0, 0, 1, 1)];

        [theTextView setMinSize:NSMakeSize(0.0, 0.0)];
        [theTextView setMaxSize:NSMakeSize(1.0, 1.0)];

        [theTextView setVerticallyResizable: YES];
        [theTextView setHorizontallyResizable: YES];       
        [theTextView setAutoresizingMask: (NSViewWidthSizable | NSViewHeightSizable)]; 
        
        [[theTextView textContainer] setContainerSize: NSMakeSize(1, 1)];
        [[theTextView textContainer] setWidthTracksTextView: NO];
        
        [scrollView setDocumentView: theTextView];
        
        [theTextView setString: @""];
        [pool drain];
    });
	return (Int)scrollView;
}

TUP0 textAreaSetText_CTTextArea(Int cocoaRef, LIST str, Int dummy) {
	char* buf = listToChars(str);
    dispatch_async(dispatch_get_main_queue(), ^{
        NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
        NSScrollView *scrollView = (NSScrollView*) cocoaRef;
        NSTextView *theTextView = [scrollView documentView];
        [theTextView setString: [NSString stringWithFormat:@"%s", buf]];
        [theTextView setNeedsDisplay: YES];
        [theTextView displayIfNeeded];
        [pool drain];
        free(buf);
    });
} 

TUP0 textAreaSetPosition_CTTextArea(Int cocoaRef, Position_CocoaDef pos, Int dummy) {
    int x = pos->x_CocoaDef;
    int y = pos->y_CocoaDef;
    dispatch_async(dispatch_get_main_queue(), ^{
        NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];	
        NSScrollView *scrollView = (NSScrollView*) cocoaRef;
        NSTextView *theTextView = [scrollView documentView];
        NSPoint p = NSMakePoint(x,y);
        [scrollView setFrameOrigin: p];
        [theTextView setNeedsDisplay: YES];
        [theTextView displayIfNeeded];
        [pool drain]; 
    });
}
TUP0 textAreaSetSize_CTTextArea(Int cocoaRef, Size_CocoaDef size, Int dummy) {
    int width = size->width_CocoaDef;
    int height = size->height_CocoaDef;
    dispatch_async(dispatch_get_main_queue(), ^{
        NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
        NSScrollView *scrollView = (NSScrollView*) cocoaRef;
        NSTextView *theTextView = [scrollView documentView];
        [scrollView setFrameSize: NSMakeSize(width,height)];
        [scrollView setNeedsDisplay:YES];
        [pool drain];
    });
}

TUP0 textAreaSetDocumentSize_CTTextArea(Int cocoaRef, Size_CocoaDef size, Int dummy) {   
    int width = size->width_CocoaDef;
    int height = size->height_CocoaDef;     
    dispatch_async(dispatch_get_main_queue(), ^{
        NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
        NSScrollView *scrollView = (NSScrollView*) cocoaRef;
        NSTextView *theTextView = [scrollView documentView];
       
        [theTextView setMaxSize: NSMakeSize(width, height)];   
        [[theTextView textContainer] setContainerSize: NSMakeSize(width, height)];

        [theTextView setNeedsDisplay:YES];
        [pool drain];
    });
}                         
                
// TODO: move to extended NSTextView to support more than one textarea!
static float x = 0;
static float y = 0;   

TUP0 textAreaScrollTo_CTTextArea(Int cocoaRef, Float dx, Float dy, Int dummy) {
    dispatch_async(dispatch_get_main_queue(), ^{
        NSScrollView *scrollview = (NSScrollView*) cocoaRef;
        NSTextView *theTextView = [scrollview documentView];
        NSClipView *theClipView = [scrollview contentView];
        y += dy;
        if (y < NSMinY(theTextView.frame)) y = NSMinY(theTextView.frame);
        if (y > NSMaxY(theTextView.frame)) y = NSMaxY(theTextView.frame);                                                     
        x += dx;
        if (x < NSMinX(theTextView.frame)) x = NSMinX(theTextView.frame);    
        if (x > NSMaxX(theTextView.frame)) x = NSMaxX(theTextView.frame);     
        [theClipView scrollPoint: NSMakePoint(x, y)]; 
    });
}

void _init_external_CTTextArea(void) {
    // Do nothing
}
