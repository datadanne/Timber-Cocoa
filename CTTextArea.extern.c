#include "CTTextArea.extern.h"

// --------- TextArea ----------------------------------------------
Int initTextArea_CTTextArea(TUP0 d) {
    NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];	

    // CODE TO MAKE A SCROLL VIEW!
    NSScrollView *scrollView = [[NSScrollView alloc] initWithFrame:NSMakeRect(0, 0, 100, 100)];
    NSSize contentSize = [scrollView contentSize];

    [scrollView setBorderType:NSNoBorder];
    [scrollView setHasVerticalScroller:NO];
    [scrollView setHasHorizontalScroller:NO];

    NSTextView *theTextView = [[NSTextView alloc] initWithFrame:NSMakeRect(0, 0, contentSize.width, contentSize.height)];
    [theTextView setMinSize:NSMakeSize(0.0, contentSize.height)];
    [theTextView setMaxSize:NSMakeSize(FLT_MAX, FLT_MAX)];
//    [theTextView setVerticallyResizable:YES];
//    [theTextView setHorizontallyResizable:NO];
    [theTextView setAutoresizingMask:NSViewWidthSizable];

    [[theTextView textContainer]
    setContainerSize:NSMakeSize(contentSize.width, FLT_MAX)];
    [[theTextView textContainer] setWidthTracksTextView:YES];
    [scrollView setDocumentView:theTextView];
    [theTextView setString: @"defaultTextAreaString"];

	[pool drain];
	return (Int)scrollView;
}

TUP0 textAreaSetText_CTTextArea(Int cocoaRef, LIST str) {
	NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
	DEBUG("external method setTitle :DD");
    NSScrollView *scrollView = (NSScrollView*) cocoaRef;
	NSTextView *theTextView = [scrollView documentView];
	char* buf = listToChars(str);
	[theTextView setString:[NSString stringWithFormat:@"%s", buf]];
	
    [theTextView setNeedsDisplay:YES];
    [theTextView displayIfNeeded];
	[pool drain];
} 

TUP0 textAreaSetPosition_CTTextArea(Int cocoaRef, Position_CocoaDef pos) {
	NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];	
    NSScrollView *scrollView = (NSScrollView*) cocoaRef;
	NSTextView *theTextView = [scrollView documentView];
	
	NSPoint p = NSMakePoint(pos->x_CocoaDef-5,pos->y_CocoaDef-20); // TODO: Remove hardcoded offset.
	
	[scrollView setFrameOrigin: p];
	
    [theTextView setNeedsDisplay:YES];
    [theTextView displayIfNeeded];
   	[pool drain]; 
}
TUP0 textAreaSetSize_CTTextArea(Int cocoaRef, Size_CocoaDef size) {
	NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
    NSScrollView *scrollView = (NSScrollView*) cocoaRef;
	NSTextView *theTextView = [scrollView documentView];

	[scrollView setFrameSize: NSMakeSize(size->width_CocoaDef,size->height_CocoaDef)];
	
	[theTextView setMinSize:NSMakeSize(size->width_CocoaDef, size->height_CocoaDef)];
    [theTextView setMaxSize:NSMakeSize(FLT_MAX, FLT_MAX)];
    [theTextView setVerticallyResizable:YES];
    [theTextView setHorizontallyResizable:NO];
    [theTextView setAutoresizingMask:NSViewWidthSizable];

    [[theTextView textContainer] setContainerSize:NSMakeSize(FLT_MAX, FLT_MAX)];
    
    [theTextView setNeedsDisplay:YES];
	[pool drain];
}

TUP0 textAreaSetHorizontalScroll_CTTextArea(Int cocoaRef, Bool enabled) {
	NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];

    NSScrollView *scrollView = (NSScrollView*) cocoaRef;
    NSTextView *theTextView = [scrollView documentView];

    // Horizontal scrolling
    [scrollView setHasHorizontalScroller:enabled];
    [theTextView setHorizontallyResizable:enabled];
    [[theTextView textContainer] setContainerSize:NSMakeSize(FLT_MAX, FLT_MAX)];
    
    [theTextView setNeedsDisplay:YES];
	[pool drain];
}

TUP0 textAreaSetVerticalScroll_CTTextArea(Int cocoaRef, Bool enabled) {
	NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];

    NSScrollView *scrollView = (NSScrollView*) cocoaRef;
    NSTextView *theTextView = [scrollView documentView];
    
    // Vertical scrolling
    [scrollView setHasVerticalScroller:enabled];
    [theTextView setVerticallyResizable:enabled];
//    NSUInteger mask = (enabled) ? [theTextView autoresizingMask]:0;
//    [theTextView setAutoresizingMask:(mask | NSViewHeightSizable)];
    [[theTextView textContainer] setContainerSize:NSMakeSize(FLT_MAX, FLT_MAX)];
    
    [theTextView setNeedsDisplay:YES];
	[pool drain];

}                               

float x = 0;
float y = 0;   

TUP0 textAreaScrollTo_CTTextArea(Int cocoaRef, Float dx, Float dy) {
    // printf("textarea was begged to scroll.. deltaX %f deltaY %f\n", dx, dy);  
    NSScrollView *scrollview = (NSScrollView*) cocoaRef;
	NSTextView *theTextView = [scrollview documentView];
    NSClipView *theClipView = [scrollview contentView];
    
    y += dy;
    
    // TODO: find out max scroll values..
    if (y < NSMinY(theTextView.frame)) y = NSMinY(theTextView.frame);
    if (y > NSMaxY(theTextView.frame)) y = NSMaxY(theTextView.frame);                                                 
    
    
    x += dx;
    
    // TODO: find out max scroll values.. 
    if (x < NSMinX(theTextView.frame)) x = NSMinX(theTextView.frame);    
    if (x > NSMaxX(theTextView.frame)) x = NSMaxX(theTextView.frame); 
    
    [theClipView scrollPoint: NSMakePoint(x, y)]; 
    
    //printf("scrolling to x%f, y%f\n", x, y);
}

void _init_external_CTTextArea(void) {
    // Nothing
}
