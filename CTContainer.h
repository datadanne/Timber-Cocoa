#ifndef CTCONTAINER_H_
#define CTCONTAINER_H_
#include "Prelude.h"
#include "POSIX.h"
#include "CTCommon.h"
 
struct Container_CTContainer;
typedef struct Container_CTContainer *Container_CTContainer;
 
struct Container_CTContainer {
    POLY GCINFO;
    Component_CTCommon l_Container_CTContainer_Component_CTCommon_CTContainer;
    ContainsComponents_CTCommon l_Container_CTContainer_ContainsComponents_CTCommon_CTContainer;
    HandlesMouseEvents_CTCommon l_Container_CTContainer_HandlesMouseEvents_CTCommon_CTContainer;
    HandlesKeyEvents_CTCommon l_Container_CTContainer_HandlesKeyEvents_CTCommon_CTContainer;
    HasBackgroundColor_CTCommon l_Container_CTContainer_HasBackgroundColor_CTCommon_CTContainer;
};
 
extern WORD __GC__Container_CTContainer[];
Component_CTCommon c_668_CTContainer (Container_CTContainer v_670);
ContainsComponents_CTCommon c_671_CTContainer (Container_CTContainer v_673);
HandlesMouseEvents_CTCommon c_674_CTContainer (Container_CTContainer v_676);
HandlesKeyEvents_CTCommon c_677_CTContainer (Container_CTContainer v_679);
HasBackgroundColor_CTCommon c_680_CTContainer (Container_CTContainer v_682);
IsFocusable_CTCommon c_684_CTContainer (Container_CTContainer a_683);
HasSize_CTCommon c_686_CTContainer (Container_CTContainer a_685);
HandlesEvents_CTCommon c_688_CTContainer (Container_CTContainer a_687);
HasPosition_CTCommon c_690_CTContainer (Container_CTContainer a_689);
Bool inInterval_CTContainer (BITS32 a_4262,
                             Ord_Prelude v_795,
                             Num_Prelude v_797,
                             POLY x_123,
                             POLY startPos_124,
                             POLY width_125);
Container_CTContainer mkContainer_CTContainer (BITS32 a_4263,
                                               POLY e_9,
                                               Int d_4221);
 
void _init_CTContainer ();
 
#include "CTContainer.extern.h"
#endif
