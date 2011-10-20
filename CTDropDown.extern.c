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
     
   	App_CTCommon app = getApp(); 

    // FIRE AWAY EVENT =DDD  
    Position_CTCommon x_5110 = NULL;
    NEW (Position_CTCommon, x_5110, WORDS(sizeof(struct Position_CTCommon)));
    x_5110->GCINFO = __GC__Position_CTCommon;
    x_5110->x_CTCommon = eventX;
	x_5110->y_CTCommon = eventY;
	
	DEBUG("PopUp creating new mouseclick at: %f , %f\n", eventX, eventY);
    
    _MouseClicked_CTCommon x_5111;
    NEW (_MouseClicked_CTCommon, x_5111, WORDS(sizeof(struct _MouseClicked_CTCommon)));
    x_5111->GCINFO = __GC___MouseClicked_CTCommon;
    x_5111->Tag = 3;
    x_5111->a = x_5110;
    
    InputEvent_CTCommon receivedEvent;
    NEW (InputEvent_CTCommon, receivedEvent, WORDS(sizeof(struct _MouseEvent_CTCommon)));
    ((_MouseEvent_CTCommon)receivedEvent)->GCINFO = __GC___MouseEvent_CTCommon;
    ((_MouseEvent_CTCommon)receivedEvent)->Tag = 1;
    ((_MouseEvent_CTCommon)receivedEvent)->a = (MouseEventType_CTCommon)x_5111;    
 
    app->sendInputEvent_CTCommon(app, (InputEvent_CTCommon)receivedEvent, windowId, 0);
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
Msg dropDownAddOption_CTDropDown(CocoaID_CTCommon id, LIST s, Time start, Time stop) {
	NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
	DEBUG("external method setTitle :DD");
	NSPopUpButton *thisDropDown = (NSPopUpButton*) COCOA_REF(id);
	DEBUG("DropDown OK %p!", thisDropDown);
	char* buf = listToChars(s);
	[thisDropDown addItemWithTitle:[NSString stringWithFormat:@"%s", buf]];
	[thisDropDown setNeedsDisplay];
	[pool drain];
} 
Msg dropDownSetPosition_CTDropDown(CocoaID_CTCommon id, Position_CTCommon pos, Time start, Time stop) {
	NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
	DEBUG("setting POS externally..");
	
	NSPopUpButton *thisDropDown = (NSPopUpButton*) COCOA_REF(id);
	
	DEBUG("DropDown(pos) OK %p!", thisDropDown);                                                    
	
    [[thisDropDown target] setCoordsX: pos->x_CTCommon andY: pos->y_CTCommon];
	
	NSPoint p = NSMakePoint(pos->x_CTCommon-5,pos->y_CTCommon-20); // TODO: Remove hardcoded offset.
	
	[thisDropDown setFrameOrigin: p];
	[thisDropDown performSelectorOnMainThread:@selector(setNeedsDisplay) withObject:nil waitUntilDone:YES];
   	[pool drain]; 
} 

Msg dropDownSetSize_CTDropDown(CocoaID_CTCommon id, Size_CTCommon size, Time start, Time stop) {
	NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
	DEBUG("dropdown setting SIZE externally..");
	
	NSPopUpButton *thisDropDown = (NSPopUpButton*) COCOA_REF(id);

    [[thisDropDown target] setWidth: size->width_CTCommon andHeight: size->height_CTCommon];
	
    NSSize s = NSMakeSize(size->width_CTCommon, size->height_CTCommon);

	[thisDropDown setFrameSize: s];
	[thisDropDown performSelectorOnMainThread:@selector(setNeedsDisplay) withObject:nil waitUntilDone:YES];
   	[pool drain]; 
}
/*
- (void) setCoordsX: (float) xarg andY: (float) yarg;
- (void) setWidth: (float) w andHeight: (float) h;
- (void) setLastEventX: (float) xarg andY: (float) yarg;
*/
/*Msg dropDownSetLastClickPosition_CTDropDown(CocoaID_CTCommon id, Position_CTCommon pos, Time start, Time stop) {
	NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
	DEBUG("setting POS externally..");
	
	NSPopUpButton *thisDropDown = (NSPopUpButton*) COCOA_REF(id);
   
    [[thisDropDown target] setLastEventX: pos->x_CTCommon andY: pos->y_CTCommon];
   
   	[pool drain]; 
} */

LIST dropDownGetSelectedOption_CTDropDown(CocoaID_CTCommon id, Int dummy) {
	NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];	
	NSPopUpButton *thisDropDown = (NSPopUpButton*) COCOA_REF(id);
    
    //char *buf;

    //*buf = [[thisDropDown titleOfSelectedItem] UTF8String];

    DEBUG("EXT! DropDown - selected option %s\n", [[thisDropDown titleOfSelectedItem] UTF8String]);

   	[pool drain]; 
    
    const char *optionStr = [[thisDropDown titleOfSelectedItem] UTF8String]; 
          
    
    // LIST s = getStr([[thisDropDown titleOfSelectedItem] UTF8String]); 
    
    LIST s = getStr((char *) optionStr);
    return s;
}
/*Msg updateExpandedPos_CTDropDown(CocoaID_CTCommon id, Position_CTCommon pos, Time start, Time stop) {
	NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];

	NSPopUpButton *thisDropDown = (NSPopUpButton*) COCOA_REF(id);
     
    DropDownClickHandler *ch = (DropDownClickHandler*) [thisDropDown target];
    
    [ch setCoordsX: pos->x_CTCommon andY: pos->y_CTCommon];

    [pool release];
} */                                         

TUP0 initDropDown_CTDropDown(DropDown_CTDropDown dropDown, App_CTCommon app, Int dummy) {
	NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];	
	DEBUG("Initializing NSDropDown: ");
	internal_CocoaID_CTCommon thisDropDown = (internal_CocoaID_CTCommon)(dropDown->l_DropDown_CTDropDown_Component_CTCommon_CTDropDown->id_CTCommon);

	NSPopUpButton *cocoaDropDown = [[NSPopUpButton alloc] initWithFrame: NSMakeRect(20.0, 20.0, 120.0, 60.0) pullsDown:FALSE];
	[cocoaDropDown setBezelStyle:NSRoundedBezelStyle];
	[cocoaDropDown setTitle: @"KNAPP!"];
	
	thisDropDown->this = cocoaDropDown;
	DEBUG("DropDown OK %p!", thisDropDown->this);
    
    // ACTION-handler
    DropDownClickHandler *dropper = [[DropDownClickHandler alloc] init];
    [cocoaDropDown setAction: @selector(dropDownClicked:)];
    [cocoaDropDown setTarget: dropper];
    
    
    
	[pool drain];
	return 0;
} 

void _init_external_CTDropDown(void) {
}