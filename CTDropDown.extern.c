#include "CTDropDown.extern.h"
 
@implementation DropDownClickHandler   

- (id) init {
    if (self = [super init]) {
        lastEventX = -1;
        lastEventY = -1;
    }
        
    return self;
}   

-(void) dropDownClicked: (id) sender {
    NSPopUpButton *pop = (NSPopUpButton*) sender;
    //NSLog(@"DROPDOWN GOT CLICKED!!!\n new option is: %@", [pop titleOfSelectedItem]); 
        
    /* -- constants
    topAndBottomOffset = 4                        
    rightOffset = 6 
    expandedOptionHeight = 18
    -- */  
                    
    // int optionsToAddHeightOf = [sender numberOfItems] - [sender indexOfSelectedItem];
    // 
    // float eventX = x + 15;
    // float eventY = y + 4 + optionsToAddHeightOf*18 + 9;
    
    float eventX;
    float eventY;    
    
    /*if (lastEventX != -1 && lastEventY != -1) {
        eventX = lastEventX;
        lastEventX = -1;
        
        eventY = lastEventY;
        lastEventY = -1;
    } else {  */
        eventX = x + width/2;
        eventY = y + height/2;
    //}

    NSInteger windowId = [[sender window] windowNumber];
     
   	App_COCOA app = getApp(); 

    // FIRE AWAY EVENT =DDD  
    Position_COCOA x_5110 = NULL;
    NEW (Position_COCOA, x_5110, WORDS(sizeof(struct Position_COCOA)));
    x_5110->GCINFO = __GC__Position_COCOA;
    x_5110->x_COCOA = eventX;
	x_5110->y_COCOA = eventY;
	
	DEBUG("PopUp creating new mouseclick at: %f , %f\n", eventX, eventY);
    
    _MouseClicked_COCOA x_5111;
    NEW (_MouseClicked_COCOA, x_5111, WORDS(sizeof(struct _MouseClicked_COCOA)));
    x_5111->GCINFO = __GC___MouseClicked_COCOA;
    x_5111->Tag = 3;
    x_5111->a = x_5110;
    
    InputEvent_COCOA receivedEvent;
    NEW (InputEvent_COCOA, receivedEvent, WORDS(sizeof(struct _MouseEvent_COCOA)));
    ((_MouseEvent_COCOA)receivedEvent)->GCINFO = __GC___MouseEvent_COCOA;
    ((_MouseEvent_COCOA)receivedEvent)->Tag = 1;
    ((_MouseEvent_COCOA)receivedEvent)->a = (MouseEventType_COCOA)x_5111;    
 
    app->l_App_COCOA_AppImpl_COCOA_COCOA->sendInputEvent_COCOA(app->l_App_COCOA_AppImpl_COCOA_COCOA, (InputEvent_COCOA)receivedEvent, windowId, 0);
}  

- (void) setCoordsX: (float) xarg andY: (float) yarg {
    x = xarg;
    y = yarg;
}  

- (void) setWidth: (float) w andHeight: (float) h {
    width = w;
    height = h;
}

/*- (void) setLastEventX: (float) xarg andY: (float) yarg {
    lastEventX = xarg;
    lastEventY = yarg;
} */           

@end

// --------- DropDown ----------------------------------------------

Int initDropDown_CTDropDown(TUP0 dummy) {
	NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];	
	NSPopUpButton *cocoaDropDown = [[NSPopUpButton alloc] initWithFrame: NSMakeRect(20.0, 20.0, 120.0, 60.0) pullsDown:FALSE];
	[cocoaDropDown setBezelStyle:NSRoundedBezelStyle];
	[cocoaDropDown setTitle: @"dropDownDefaultTitle"];
	
    // ACTION-handler
    DropDownClickHandler *dropper = [[DropDownClickHandler alloc] init];
    [cocoaDropDown setAction: @selector(dropDownClicked:)];
    [cocoaDropDown setTarget: dropper];
	[pool drain];
	return (Int)cocoaDropDown;
} 

TUP0 dropDownAddOption_CTDropDown(Int cocoaRef,LIST str) {
    NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
	NSPopUpButton *thisDropDown = (NSPopUpButton*) cocoaRef;
	char* buf = listToChars(str);
	[thisDropDown addItemWithTitle:[NSString stringWithFormat:@"%s", buf]];
	[thisDropDown setNeedsDisplay];
	[pool drain];
}
LIST dropDownGetSelectedOption_CTDropDown(Int cocoaRef) {
	NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];	
	NSPopUpButton *thisDropDown = (NSPopUpButton*) cocoaRef;

    const char *optionStr = [[thisDropDown titleOfSelectedItem] UTF8String]; 
    LIST s = getStr((char *) optionStr);
    [pool drain]; 
    
    return s;
}

TUP0 dropDownSetPosition_CTDropDown(Int cocoaRef,Position_COCOA pos) {
	NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];

    NSPopUpButton *thisDropDown = (NSPopUpButton*) cocoaRef;
    [[thisDropDown target] setCoordsX: pos->x_COCOA andY: pos->y_COCOA];
	
	NSPoint p = NSMakePoint(pos->x_COCOA-5,pos->y_COCOA-20); // TODO: Remove hardcoded offset.
	
	[thisDropDown setFrameOrigin: p];
	[thisDropDown performSelectorOnMainThread:@selector(setNeedsDisplay) withObject:nil waitUntilDone:YES];
   	[pool drain]; 
}

TUP0 dropDownSetSize_CTDropDown(Int cocoaRef, Size_COCOA size) {
	NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];	
	NSPopUpButton *thisDropDown = (NSPopUpButton*) cocoaRef;

    [[thisDropDown target] setWidth: size->width_COCOA andHeight: size->height_COCOA];
	
    NSSize s = NSMakeSize(size->width_COCOA, size->height_COCOA);

	[thisDropDown setFrameSize: s];
	[thisDropDown performSelectorOnMainThread:@selector(setNeedsDisplay) withObject:nil waitUntilDone:YES];
   	[pool drain]; 
}
/*
- (void) setCoordsX: (float) xarg andY: (float) yarg;
- (void) setWidth: (float) w andHeight: (float) h;
- (void) setLastEventX: (float) xarg andY: (float) yarg;
*/
/*Msg dropDownSetLastClickPosition_CTDropDown(CocoaID_COCOA id, Position_COCOA pos, Time start, Time stop) {
	NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
	DEBUG("setting POS externally..");
	
	NSPopUpButton *thisDropDown = (NSPopUpButton*) cocoaRef;
   
    [[thisDropDown target] setLastEventX: pos->x_COCOA andY: pos->y_COCOA];
   
   	[pool drain]; 
} */

/*Msg updateExpandedPos_CTDropDown(CocoaID_COCOA id, Position_COCOA pos, Time start, Time stop) {
	NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];

	NSPopUpButton *thisDropDown = (NSPopUpButton*) cocoaRef;
     
    DropDownClickHandler *ch = (DropDownClickHandler*) [thisDropDown target];
    
    [ch setCoordsX: pos->x_COCOA andY: pos->y_COCOA];

    [pool release];
} */ 

void _init_external_CTDropDown(void) {
}