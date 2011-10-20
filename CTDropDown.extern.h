#ifndef _COCOA_NSDROPDOWN_TIMBER_
#define _COCOA_NSDROPDOWN_TIMBER_

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

#endif