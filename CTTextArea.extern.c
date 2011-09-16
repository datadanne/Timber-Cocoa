#include "CTTextArea.extern.h"
                    
// --------- TextArea ----------------------------------------------
Msg textAreaSetText_CTTextArea(CocoaID_CTCommon id, LIST s, Time start, Time stop) {
	NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
	DEBUG("external method setTitle :DD");
	NSScrollView *scrollview = (NSScrollView*) COCOA_REF(id);
	NSTextView *theTextView = [scrollview documentView];
	char* buf = listToChars(s);
	[theTextView setString:[NSString stringWithFormat:@"%s", buf]];
	//[scrollview setNeedsDisplay];
	[pool drain];
} 
Msg textAreaSetPosition_CTTextArea(CocoaID_CTCommon id, Position_CTCommon pos, Time start, Time stop) {
	NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
	DEBUG("setting POS externally..");
	
	NSScrollView *thisTextArea = (NSScrollView*) COCOA_REF(id);
	
	DEBUG("TextArea(pos) OK %p!", thisTextArea);
	NSPoint p = NSMakePoint(pos->x_CTCommon-5,pos->y_CTCommon-20); // TODO: Remove hardcoded offset.
	
	[thisTextArea setFrameOrigin: p];
	[thisTextArea performSelectorOnMainThread:@selector(setNeedsDisplay) withObject:nil waitUntilDone:YES];
   	[pool drain]; 
}

Msg textAreaSetSize_CTTextArea (CocoaID_CTCommon id, Size_CTCommon pos, Time start, Time stop) {
	NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
	DEBUG("setting containerSize ext!\n");
    NSScrollView *thisTextArea = (NSScrollView*) COCOA_REF(id);
	NSTextView *theTextView = [thisTextArea documentView];

	[thisTextArea setFrameSize: NSMakeSize(pos->width_CTCommon,pos->height_CTCommon)];
	
	[theTextView setMinSize:NSMakeSize(pos->width_CTCommon, pos->height_CTCommon)];
    [theTextView setMaxSize:NSMakeSize(FLT_MAX, FLT_MAX)];
    [theTextView setVerticallyResizable:YES];
    [theTextView setHorizontallyResizable:NO];
    [theTextView setAutoresizingMask:NSViewWidthSizable];

    [[theTextView textContainer] setContainerSize:NSMakeSize(FLT_MAX, FLT_MAX)];
    
    
	[pool drain];
}

Msg textAreaSetHorizontalScroll_CTTextArea(CocoaID_CTCommon id, Bool enabled, Time start, Time stop) {
    NSScrollView *scrollview = (NSScrollView*) COCOA_REF(id);
	NSTextView *theTextView = [scrollview documentView];

    // Horizontal scrolling
    [[theTextView enclosingScrollView] setHasHorizontalScroller:YES];
    [theTextView setHorizontallyResizable:YES];
    [theTextView setAutoresizingMask:(NSViewWidthSizable | NSViewHeightSizable)];
    [[theTextView textContainer] setContainerSize:NSMakeSize(FLT_MAX, FLT_MAX)];
    [[theTextView textContainer] setWidthTracksTextView:NO];
}

Msg textAreaSetVerticalScroll_CTTextArea(CocoaID_CTCommon id, Bool enabled, Time start, Time stop) {
    
}                               

TUP0 initTextArea_CTTextArea(TextArea_CTTextArea textArea, App_CTCommon app, Int dummy) {
	NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];	
	DEBUG("Initializing NSScrollView: ");
	internal_CocoaID_CTCommon thisTextArea = (internal_CocoaID_CTCommon)(textArea->l_TextArea_CTTextArea_Component_CTCommon_CTTextArea->id_CTCommon);

    // CODE TO MAKE A SCROLL VIEW!
    NSScrollView *scrollview = [[NSScrollView alloc] initWithFrame:NSMakeRect(0, 0, 100, 100)];

    NSSize contentSize = [scrollview contentSize];

    [scrollview setBorderType:NSNoBorder];
    [scrollview setHasVerticalScroller:YES];
    [scrollview setHasHorizontalScroller:NO];
    [scrollview setAutoresizingMask:NSViewWidthSizable | NSViewHeightSizable];

    NSTextView *theTextView = [[NSTextView alloc] initWithFrame:NSMakeRect(0, 0, contentSize.width, contentSize.height)];
    [theTextView setMinSize:NSMakeSize(0.0, contentSize.height)];
    [theTextView setMaxSize:NSMakeSize(FLT_MAX, FLT_MAX)];
    [theTextView setVerticallyResizable:YES];
    [theTextView setHorizontallyResizable:NO];
    [theTextView setAutoresizingMask:NSViewWidthSizable];

    [[theTextView textContainer]
    setContainerSize:NSMakeSize(contentSize.width, FLT_MAX)];
    [[theTextView textContainer] setWidthTracksTextView:YES];

    [scrollview setDocumentView:theTextView];

    // Horizontal scrolling
    [[theTextView enclosingScrollView] setHasHorizontalScroller:YES];
    [theTextView setHorizontallyResizable:YES];
    [theTextView setAutoresizingMask:(NSViewWidthSizable | NSViewHeightSizable)];
    [[theTextView textContainer] setContainerSize:NSMakeSize(FLT_MAX, FLT_MAX)];
    [[theTextView textContainer] setWidthTracksTextView:NO];

    [theTextView setString: @"TEXT"];
	thisTextArea->this = scrollview;

	[pool drain];
	return 0;
} 

