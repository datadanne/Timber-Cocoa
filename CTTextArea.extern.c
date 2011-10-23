#include "CTTextArea.extern.h"
                    
// --------- TextArea ----------------------------------------------
Msg textAreaSetText_CTTextArea(CocoaID_COCOA id, LIST s, Time start, Time stop) {
	NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
	DEBUG("external method setTitle :DD");
	NSScrollView *scrollView = (NSScrollView*) COCOA_REF(id);
	NSTextView *theTextView = [scrollView documentView];
	char* buf = listToChars(s);
	[theTextView setString:[NSString stringWithFormat:@"%s", buf]];
	
    [theTextView setNeedsDisplay:YES];
    [theTextView displayIfNeeded];
	[pool drain];
} 

Msg textAreaSetPosition_CTTextArea(CocoaID_COCOA id, Position_COCOA pos, Time start, Time stop) {
	NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
	DEBUG("setting POS externally..");
	
	NSScrollView *scrollView = (NSScrollView*) COCOA_REF(id);
	NSTextView *theTextView = [scrollView documentView];
	
	
	DEBUG("TextArea(pos) OK %p!", scrollView);
	NSPoint p = NSMakePoint(pos->x_COCOA-5,pos->y_COCOA-20); // TODO: Remove hardcoded offset.
	
	[scrollView setFrameOrigin: p];
	
    [theTextView setNeedsDisplay:YES];
    [theTextView displayIfNeeded];
   	[pool drain]; 
}

Msg textAreaSetSize_CTTextArea (CocoaID_COCOA id, Size_COCOA pos, Time start, Time stop) {
	NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
	DEBUG("setting containerSize ext!\n");
    NSScrollView *scrollView = (NSScrollView*) COCOA_REF(id);
	NSTextView *theTextView = [scrollView documentView];

	[scrollView setFrameSize: NSMakeSize(pos->width_COCOA,pos->height_COCOA)];
	
	[theTextView setMinSize:NSMakeSize(pos->width_COCOA, pos->height_COCOA)];
    [theTextView setMaxSize:NSMakeSize(FLT_MAX, FLT_MAX)];
    [theTextView setVerticallyResizable:YES];
    [theTextView setHorizontallyResizable:NO];
    [theTextView setAutoresizingMask:NSViewWidthSizable];

    [[theTextView textContainer] setContainerSize:NSMakeSize(FLT_MAX, FLT_MAX)];
    
    [theTextView setNeedsDisplay:YES];
	[pool drain];
}

TUP0 textAreaSetHorizontalScroll_CTTextArea(CocoaID_COCOA id, Bool enabled, int dummy) {
	NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];

    NSScrollView *scrollView = (NSScrollView*) COCOA_REF(id);
    NSTextView *theTextView = [scrollView documentView];

    // Horizontal scrolling
    [scrollView setHasHorizontalScroller:enabled];
    [theTextView setHorizontallyResizable:enabled];
    [[theTextView textContainer] setContainerSize:NSMakeSize(FLT_MAX, FLT_MAX)];
    
    [theTextView setNeedsDisplay:YES];
	[pool drain];
}

TUP0 textAreaSetVerticalScroll_CTTextArea(CocoaID_COCOA id, Bool enabled, int dummy) {
	NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];

    NSScrollView *scrollView = (NSScrollView*) COCOA_REF(id);
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

Msg textAreaScrollTo_CTTextArea(CocoaID_COCOA id, float dx, float dy, Time start, Time stop) {
    // printf("textarea was begged to scroll.. deltaX %f deltaY %f\n", dx, dy);  
    NSScrollView *scrollview = (NSScrollView*) COCOA_REF(id);
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
    
    printf("scrolling to x%f, y%f\n", x, y);
}

TUP0 initTextArea_CTTextArea(TextArea_CTTextArea textArea, App_COCOA app, Int dummy) {
	NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];	
	DEBUG("Initializing NSScrollView: ");
	internal_CocoaID_COCOA scrollViewID = (internal_CocoaID_COCOA)(textArea->l_TextArea_CTTextArea_Component_COCOA_CTTextArea->id_COCOA);

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

    [theTextView setString: @"TEXT"];
	scrollViewID->this = scrollView;

	[pool drain];
	return 0;
} 

void _init_external_CTTextArea(void) {
    // Nothing
}
