#include "CTDropDown.extern.h"

@interface DropDownClickHandler : NSObject {
    float x;
    float y;
    float width;
    float height;   
    
    float lastEventX;
    float lastEventY;
} 
- (void) setCoordsX: (float) xarg andY: (float) yarg;
- (void) setWidth: (float) w andHeight: (float) h;
@end   

@implementation DropDownClickHandler   
- (id) init {
    if (self = [super init]) {
        lastEventX = -1;
        lastEventY = -1;
    }
        
    return self;
}   
-(void) dropDownClicked: (id) sender {
    Thread current_thread = CURRENT();
	TIMERGET(current_thread->msg->baseline);

    NSPopUpButton *pop = (NSPopUpButton*) sender;
    // Y coordinate needs to be set to (rootcontainer height - dropdown y),
    // since top left corner is 0,0 in Timber.
    float eventX = x + width/2;
    float eventY = [[[sender window] contentView] frame].size.height - y - height/2;
    NSInteger windowId = [[sender window] windowNumber];     
   	App_CocoaDef app = getApp(); 
    Position_CocoaDef pos = NULL;
    NEW (Position_CocoaDef, pos, WORDS(sizeof(struct Position_CocoaDef)));
    pos->GCINFO = __GC__Position_CocoaDef;
    pos->x_CocoaDef = eventX;
	pos->y_CocoaDef = eventY;	
	DEBUG("PopUp creating new mouseclick at: %f , %f\n", eventX, eventY);
    _MouseClicked_CocoaDef clicked;
    NEW (_MouseClicked_CocoaDef, clicked, WORDS(sizeof(struct _MouseClicked_CocoaDef)));
    clicked->GCINFO = __GC___MouseClicked_CocoaDef;
    clicked->Tag = 3;
    clicked->a = pos;
    InputEvent_CocoaDef receivedEvent;
    NEW (InputEvent_CocoaDef, receivedEvent, WORDS(sizeof(struct _MouseEvent_CocoaDef)));
    ((_MouseEvent_CocoaDef)receivedEvent)->GCINFO = __GC___MouseEvent_CocoaDef;
    ((_MouseEvent_CocoaDef)receivedEvent)->Tag = 1;
    ((_MouseEvent_CocoaDef)receivedEvent)->a = (MouseEventType_CocoaDef)clicked;    
    app->l_App_CocoaDef_AppImpl_CocoaDef_CocoaDef->sendInputEvent_CocoaDef(
        app->l_App_CocoaDef_AppImpl_CocoaDef_CocoaDef, (InputEvent_CocoaDef)receivedEvent, windowId, 0);
}  
- (void) setCoordsX: (float) xarg andY: (float) yarg {
    x = xarg;
    y = yarg;
}  
- (void) setWidth: (float) w andHeight: (float) h {
    width = w;
    height = h;
}
@end
