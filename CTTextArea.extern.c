#include "CTTextArea.extern.h"
                    
// --------- TextArea ----------------------------------------------
Msg textAreaSetText_CTTextArea(CocoaID_CTCommon id, LIST s, Time start, Time stop) {
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

Msg textAreaSetPosition_CTTextArea(CocoaID_CTCommon id, Position_CTCommon pos, Time start, Time stop) {
	NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
	DEBUG("setting POS externally..");
	
	NSScrollView *scrollView = (NSScrollView*) COCOA_REF(id);
	NSTextView *theTextView = [scrollView documentView];
	
	
	DEBUG("TextArea(pos) OK %p!", scrollView);
	NSPoint p = NSMakePoint(pos->x_CTCommon-5,pos->y_CTCommon-20); // TODO: Remove hardcoded offset.
	
	[scrollView setFrameOrigin: p];
	
    [theTextView setNeedsDisplay:YES];
    [theTextView displayIfNeeded];
   	[pool drain]; 
}

Msg textAreaSetSize_CTTextArea (CocoaID_CTCommon id, Size_CTCommon pos, Time start, Time stop) {
	NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
	DEBUG("setting containerSize ext!\n");
    NSScrollView *scrollView = (NSScrollView*) COCOA_REF(id);
	NSTextView *theTextView = [scrollView documentView];

	[scrollView setFrameSize: NSMakeSize(pos->width_CTCommon,pos->height_CTCommon)];
	
	[theTextView setMinSize:NSMakeSize(pos->width_CTCommon, pos->height_CTCommon)];
    [theTextView setMaxSize:NSMakeSize(FLT_MAX, FLT_MAX)];
    [theTextView setVerticallyResizable:YES];
    [theTextView setHorizontallyResizable:NO];
    [theTextView setAutoresizingMask:NSViewWidthSizable];

    [[theTextView textContainer] setContainerSize:NSMakeSize(FLT_MAX, FLT_MAX)];
    
    [theTextView setNeedsDisplay:YES];
	[pool drain];
}

TUP0 textAreaSetHorizontalScroll_CTTextArea(CocoaID_CTCommon id, Bool enabled, int dummy) {
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

TUP0 textAreaSetVerticalScroll_CTTextArea(CocoaID_CTCommon id, Bool enabled, int dummy) {
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

TUP0 initTextArea_CTTextArea(TextArea_CTTextArea textArea, App_CTCommon app, Int dummy) {
	NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];	
	DEBUG("Initializing NSScrollView: ");
	internal_CocoaID_CTCommon scrollViewID = (internal_CocoaID_CTCommon)(textArea->l_TextArea_CTTextArea_Component_CTCommon_CTTextArea->id_CTCommon);

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

