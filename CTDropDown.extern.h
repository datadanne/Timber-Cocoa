#ifndef CTDROPDOWN_EXTERN_H_
#define CTDROPDOWN_EXTERN_H_

#import <Cocoa/Cocoa.h>


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
//- (void) setLastEventX: (float) xarg andY: (float) yarg;

/*@property (assign) float x;
@property (assign) float y;
@property (assign) float width;
@property (assign) float height;*/

@end   

Int initDropDown_CTDropDown(TUP0);
TUP0 optionWasSelected_CTDropDown(Int, LIST);
TUP0 dropDownAddOption_CTDropDown(Int,LIST);
LIST dropDownGetSelectedOption_CTDropDown(Int);
TUP0 dropDownSetPosition_CTDropDown(Int,Position_CocoaDef);
TUP0 dropDownSetSize_CTDropDown(Int, Size_CocoaDef);

#endif