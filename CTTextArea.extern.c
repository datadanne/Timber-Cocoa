#include "CTTextArea.extern.h"

// --------- TextArea ----------------------------------------------
Int initTextArea_CTTextArea(TUP0 d) {
    __block NSScrollView *scrollView;
    dispatch_sync(dispatch_get_main_queue(), ^{
        NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];	
        scrollView = [[NSScrollView alloc] initWithFrame:NSMakeRect(0, 0, 100, 100)];
        NSSize contentSize = [scrollView contentSize];
        [scrollView setBorderType:NSNoBorder];
        [scrollView setHasVerticalScroller:NO];
        [scrollView setHasHorizontalScroller:NO];
        NSTextView *theTextView = [[NSTextView alloc] 
        initWithFrame:NSMakeRect(0, 0, contentSize.width, contentSize.height)];
        [theTextView setMinSize:NSMakeSize(0.0, contentSize.height)];
        [theTextView setMaxSize:NSMakeSize(FLT_MAX, FLT_MAX)];
        // [theTextView setVerticallyResizable:YES];
        // [theTextView setHorizontallyResizable:NO];
        [theTextView setAutoresizingMask:NSViewWidthSizable];
        [[theTextView textContainer]
         setContainerSize:NSMakeSize(contentSize.width, FLT_MAX)];
        [[theTextView textContainer] setWidthTracksTextView:YES];
        [scrollView setDocumentView:theTextView];
        [theTextView setString: @"defaultTextAreaString"];
        [pool drain];
    });
	return (Int)scrollView;
}

TUP0 textAreaSetText_CTTextArea(Int cocoaRef, LIST str) {
	char* buf = listToChars(str);
    dispatch_async(dispatch_get_main_queue(), ^{
        NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
        NSScrollView *scrollView = (NSScrollView*) cocoaRef;
        NSTextView *theTextView = [scrollView documentView];
        [theTextView setString:[NSString stringWithFormat:@"%s", buf]];
        [theTextView setNeedsDisplay:YES];
        [theTextView displayIfNeeded];
        [pool drain];
        free(buf);
    });
} 

TUP0 textAreaSetPosition_CTTextArea(Int cocoaRef, Position_CocoaDef pos) {
    int x = pos->x_CocoaDef-5; // TODO: Remove hardcoded offset.
    int y = pos->y_CocoaDef-20;
    dispatch_async(dispatch_get_main_queue(), ^{
        NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];	
        NSScrollView *scrollView = (NSScrollView*) cocoaRef;
        NSTextView *theTextView = [scrollView documentView];
        NSPoint p = NSMakePoint(x,y);
        [scrollView setFrameOrigin: p];
        [theTextView setNeedsDisplay:YES];
        [theTextView displayIfNeeded];
        [pool drain]; 
    });
}
TUP0 textAreaSetSize_CTTextArea(Int cocoaRef, Size_CocoaDef size) {
    int width = size->width_CocoaDef;
    int height = size->height_CocoaDef;
    dispatch_async(dispatch_get_main_queue(), ^{
        NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
        NSScrollView *scrollView = (NSScrollView*) cocoaRef;
        NSTextView *theTextView = [scrollView documentView];
        [scrollView setFrameSize: NSMakeSize(width,height)];
        [theTextView setMinSize:NSMakeSize(width,height)];
        [theTextView setMaxSize:NSMakeSize(FLT_MAX, FLT_MAX)];
        [theTextView setVerticallyResizable:YES];
        [theTextView setHorizontallyResizable:YES];//???
        [theTextView setAutoresizingMask:NSViewWidthSizable];
        [[theTextView textContainer] setContainerSize:NSMakeSize(FLT_MAX, FLT_MAX)];
        [theTextView setNeedsDisplay:YES];
        [pool drain];
    });
}

TUP0 textAreaSetHorizontalScroll_CTTextArea(Int cocoaRef, Bool enabled) {
    dispatch_async(dispatch_get_main_queue(), ^{
        NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
        NSScrollView *scrollView = (NSScrollView*) cocoaRef;
        NSTextView *theTextView = [scrollView documentView];
        [scrollView setHasHorizontalScroller:enabled];
        [theTextView setHorizontallyResizable:enabled];
        [[theTextView textContainer] setContainerSize:NSMakeSize(FLT_MAX, FLT_MAX)];
        [theTextView setNeedsDisplay:YES];
        [pool drain];
    });
}

TUP0 textAreaSetVerticalScroll_CTTextArea(Int cocoaRef, Bool enabled) {
    dispatch_async(dispatch_get_main_queue(), ^{
        NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
        NSScrollView *scrollView = (NSScrollView*) cocoaRef;
        NSTextView *theTextView = [scrollView documentView];
        [scrollView setHasVerticalScroller:enabled];
        [theTextView setVerticallyResizable:enabled];
        // NSUInteger mask = (enabled) ? [theTextView autoresizingMask]:0;
        // [theTextView setAutoresizingMask:(mask | NSViewHeightSizable)];
        [[theTextView textContainer] setContainerSize:NSMakeSize(FLT_MAX, FLT_MAX)];
    
        [theTextView setNeedsDisplay:YES];
        [pool drain];
    });
}                               

static float x = 0;
static float y = 0;   

TUP0 textAreaScrollTo_CTTextArea(Int cocoaRef, Float dx, Float dy) {
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
    // Nothing
}
