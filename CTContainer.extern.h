#ifndef CTCONTAINER_EXTERN_H_
#define CTCONTAINER_EXTERN_H_

#include "CocoaDef.h"

Int initContainer_CTContainer(World,Int);
TUP0 destroyContainer_CTContainer(Int,Int);
TUP0 containerSetBackgroundColor_CTContainer(Int,Color_CocoaDef,Int);
TUP0 containerSetSize_CTContainer(Int,Size_CocoaDef,Int);
TUP0 containerSetPosition_CTContainer(Int,Position_CocoaDef,Int);
TUP0 containerAddComponent_CTContainer(Int,Int,Int);
TUP0 containerRemoveComponent_CTContainer(Int,Int,Int);

#endif