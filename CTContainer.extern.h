#ifndef CTCONTAINER_EXTERN_H_
#define CTCONTAINER_EXTERN_H_

#import <Cocoa/Cocoa.h>

/* 
    Extended version of NSView, adds method for changing background color.
*/
@interface CocoaView : NSView {
@private
    int r;
    int g;
    int b;
}
-(void) setBackgroundColor:(int) ra:(int) ga:(int) ba;
@end

Int initContainer_CTContainer(TUP0);
TUP0 destroyContainer_CTContainer(Int);
TUP0 containerSetBackgroundColor_CTContainer(Int, Color_CocoaDef);
TUP0 containerSetSize_CTContainer(Int, Size_CocoaDef);
TUP0 containerSetPosition_CTContainer(Int, Position_CocoaDef);
TUP0 containerAddComponent_CTContainer(Int, Int);
TUP0 containerRemoveComponent_CTContainer(Int, Int);

#endif