#include "NSButton.h"
#include "NSButton.extern.c"
 
struct S_382;
typedef struct S_382 *S_382;
struct T_1437;
typedef struct T_1437 *T_1437;
struct T_1436;
typedef struct T_1436 *T_1436;
struct T_1435;
typedef struct T_1435 *T_1435;
struct T_1434;
typedef struct T_1434 *T_1434;
struct T_1433;
typedef struct T_1433 *T_1433;
struct T_1432;
typedef struct T_1432 *T_1432;
struct T_1431;
typedef struct T_1431 *T_1431;
struct T_1430;
typedef struct T_1430 *T_1430;
struct T_1429;
typedef struct T_1429 *T_1429;
struct T_1428;
typedef struct T_1428 *T_1428;
struct T_1427;
typedef struct T_1427 *T_1427;
struct T_1426;
typedef struct T_1426 *T_1426;
struct T_1425;
typedef struct T_1425 *T_1425;
struct T_1424;
typedef struct T_1424 *T_1424;
struct T_1423;
typedef struct T_1423 *T_1423;
struct T_1422;
typedef struct T_1422 *T_1422;
struct T_1421;
typedef struct T_1421 *T_1421;
struct T_1420;
typedef struct T_1420 *T_1420;
struct T_1419;
typedef struct T_1419 *T_1419;
 
struct S_382 {
    POLY GCINFO;
    CocoaState_NSTest myState_10;
    Position_NSTest position_11;
    Size_NSTest size_12;
    Maybe_Prelude mouseEventHandler_13;
    LIST title_14;
};
struct T_1437 {
    POLY GCINFO;
    TUP0 (*installMouseListener_NSTest) (T_1437, CLOS, Int);
    CLOS x_1409;
};
struct T_1436 {
    POLY GCINFO;
    Bool (*handleEvent_NSTest) (T_1436, CocoaEvent_NSTest, Int);
    CLOS x_1401;
};
struct T_1435 {
    POLY GCINFO;
    Msg (*setPosition_NSTest) (T_1435, Position_NSTest, Time, Time);
    Position_NSTest (*getPosition_NSTest) (T_1435, Int);
    CLOS x_1389;
    CLOS x_1391;
};
struct T_1434 {
    POLY GCINFO;
    HasPosition_NSTest l_HasSize_NSTest_HasPosition_NSTest_NSTest;
    Msg (*setSize_NSTest) (T_1434, Size_NSTest, Time, Time);
    Size_NSTest (*getSize_NSTest) (T_1434, Int);
    CLOS x_1395;
    CLOS x_1397;
};
struct T_1433 {
    POLY GCINFO;
    HasSize_NSTest l_Component_NSTest_HasSize_NSTest_NSTest;
    HandlesEvents_NSTest l_Component_NSTest_HandlesEvents_NSTest_NSTest;
    CocoaID_NSTest id_NSTest;
    TUP0 (*init_NSTest) (T_1433, App_NSTest, Int);
    TUP0 (*destroy_NSTest) (T_1433, Int);
    CLOS x_1404;
    CLOS x_1406;
};
struct T_1432 {
    POLY GCINFO;
    Component_NSTest l_Button_NSButton_Component_NSTest_NSButton;
    HandlesMouseEvents_NSTest l_Button_NSButton_HandlesMouseEvents_NSTest_NSButton;
    Msg (*setTitle_NSButton) (T_1432, LIST, Time, Time);
    LIST (*getTitle_NSButton) (T_1432, Int);
    CLOS x_1412;
    CLOS x_1414;
};
struct T_1431 {
    POLY GCINFO;
    TUP0 (*Code) (T_1431, App_NSTest, Int);
    Button_NSButton this_54;
    CocoaID_NSTest id_15;
    Ref self_9;
};
struct T_1430 {
    POLY GCINFO;
    Bool (*Code) (T_1430, CocoaEvent_NSTest, Int);
    CLOS handleMouseEvent_40;
    Ref self_9;
};
struct T_1429 {
    POLY GCINFO;
    TUP0 (*Code) (T_1429, CLOS, Int);
    Ref self_9;
};
struct T_1428 {
    POLY GCINFO;
    TUP0 (*Code) (T_1428, Int);
    Ref self_9;
};
struct T_1427 {
    POLY GCINFO;
    Size_NSTest (*Code) (T_1427, Int);
    Ref self_9;
};
struct T_1426 {
    POLY GCINFO;
    TUP0 (*Code) (T_1426);
    AbsTime baseline;
    AbsTime deadline;
    Msg next;
    Size_NSTest a_1358;
    Ref self_9;
};
struct T_1425 {
    POLY GCINFO;
    Msg (*Code) (T_1425, Size_NSTest, Time, Time);
    Ref self_9;
};
struct T_1424 {
    POLY GCINFO;
    Position_NSTest (*Code) (T_1424, Int);
    Ref self_9;
};
struct T_1423 {
    POLY GCINFO;
    TUP0 (*Code) (T_1423);
    AbsTime baseline;
    AbsTime deadline;
    Msg next;
    Position_NSTest a_1346;
    CocoaID_NSTest id_15;
    Ref self_9;
};
struct T_1422 {
    POLY GCINFO;
    Msg (*Code) (T_1422, Position_NSTest, Time, Time);
    CocoaID_NSTest id_15;
    Ref self_9;
};
struct T_1421 {
    POLY GCINFO;
    LIST (*Code) (T_1421, Int);
    Ref self_9;
};
struct T_1420 {
    POLY GCINFO;
    TUP0 (*Code) (T_1420);
    AbsTime baseline;
    AbsTime deadline;
    Msg next;
    LIST a_1334;
    CocoaID_NSTest id_15;
    Ref self_9;
};
struct T_1419 {
    POLY GCINFO;
    Msg (*Code) (T_1419, LIST, Time, Time);
    CocoaID_NSTest id_15;
    Ref self_9;
};
 
static WORD __GC__S_382[];
static WORD __GC__T_1437[];
static WORD __GC__T_1436[];
static WORD __GC__T_1435[];
static WORD __GC__T_1434[];
static WORD __GC__T_1433[];
static WORD __GC__T_1432[];
static WORD __GC__T_1431[];
static WORD __GC__T_1430[];
static WORD __GC__T_1429[];
static WORD __GC__T_1428[];
static WORD __GC__T_1427[];
static WORD __GC__T_1426[];
static WORD __GC__T_1425[];
static WORD __GC__T_1424[];
static WORD __GC__T_1423[];
static WORD __GC__T_1422[];
static WORD __GC__T_1421[];
static WORD __GC__T_1420[];
static WORD __GC__T_1419[];
static TUP0 inithelper_51 (CocoaID_NSTest id_15, Ref self_52);
static TUP0 f_1446 (T_1420 this_1444);
static Msg f_1447 (T_1419 this_1440,
                   LIST a_1334,
                   Time a_1335,
                   Time a_1336);
static LIST f_1450 (T_1421 this_1448, Int a_1340);
static TUP0 f_1457 (T_1423 this_1455);
static Msg f_1458 (T_1422 this_1451,
                   Position_NSTest a_1346,
                   Time a_1347,
                   Time a_1348);
static Position_NSTest f_1461 (T_1424 this_1459, Int a_1352);
static TUP0 f_1467 (T_1426 this_1466);
static Msg f_1468 (T_1425 this_1462,
                   Size_NSTest a_1358,
                   Time a_1359,
                   Time a_1360);
static Size_NSTest f_1471 (T_1427 this_1469, Int a_1364);
static TUP0 f_1474 (T_1428 this_1472, Int a_1367);
static TUP0 f_1479 (T_1429 this_1475, CLOS a_1372, Int a_1373);
static Bool f_1485 (CLOS this_1480,
                    BITS32 a_1484,
                    POLY a_1376,
                    Maybe_Prelude a_1377,
                    Ref a_1378);
static Bool f_1490 (T_1430 this_1486,
                    CocoaEvent_NSTest a_1383,
                    Int a_1384);
static TUP0 f_1494 (T_1431 this_1491,
                    App_NSTest a_1387,
                    Int a_1388);
static Position_NSTest f_1498 (T_1435 this_1495, Int a_1390);
static Msg f_1504 (T_1435 this_1499,
                   Position_NSTest a_1392,
                   Time a_1393,
                   Time a_1394);
static Size_NSTest f_1509 (T_1434 this_1506, Int a_1396);
static Msg f_1515 (T_1434 this_1510,
                   Size_NSTest a_1398,
                   Time a_1399,
                   Time a_1400);
static Bool f_1521 (T_1436 this_1517,
                    CocoaEvent_NSTest a_1402,
                    Int a_1403);
static TUP0 f_1526 (T_1433 this_1523, Int a_1405);
static TUP0 f_1531 (T_1433 this_1527,
                    App_NSTest a_1407,
                    Int a_1408);
static TUP0 f_1537 (T_1437 this_1533, CLOS a_1410, Int a_1411);
static LIST f_1542 (T_1432 this_1539, Int a_1413);
static Msg f_1548 (T_1432 this_1543,
                   LIST a_1415,
                   Time a_1416,
                   Time a_1417);
 
WORD __GC__Button_NSButton[] = {WORDS(sizeof(struct Button_NSButton)),
                                0,
                                WORDS(offsetof(struct Button_NSButton, l_Button_NSButton_Component_NSTest_NSButton)),
                                WORDS(offsetof(struct Button_NSButton, l_Button_NSButton_HandlesMouseEvents_NSTest_NSButton)),
                                0};
static WORD __GC__S_382[] = {WORDS(sizeof(struct S_382)),
                             0,
                             WORDS(offsetof(struct S_382, myState_10)),
                             WORDS(offsetof(struct S_382, position_11)),
                             WORDS(offsetof(struct S_382, size_12)),
                             WORDS(offsetof(struct S_382, mouseEventHandler_13)),
                             WORDS(offsetof(struct S_382, title_14)),
                             0};
static WORD __GC__T_1437[] = {WORDS(sizeof(struct T_1437)),
                              0,
                              WORDS(offsetof(struct T_1437, x_1409)),
                              0};
static WORD __GC__T_1436[] = {WORDS(sizeof(struct T_1436)),
                              0,
                              WORDS(offsetof(struct T_1436, x_1401)),
                              0};
static WORD __GC__T_1435[] = {WORDS(sizeof(struct T_1435)),
                              0,
                              WORDS(offsetof(struct T_1435, x_1389)),
                              WORDS(offsetof(struct T_1435, x_1391)),
                              0};
static WORD __GC__T_1434[] = {WORDS(sizeof(struct T_1434)),
                              0,
                              WORDS(offsetof(struct T_1434, l_HasSize_NSTest_HasPosition_NSTest_NSTest)),
                              WORDS(offsetof(struct T_1434, x_1395)),
                              WORDS(offsetof(struct T_1434, x_1397)),
                              0};
static WORD __GC__T_1433[] = {WORDS(sizeof(struct T_1433)),
                              0,
                              WORDS(offsetof(struct T_1433, l_Component_NSTest_HasSize_NSTest_NSTest)),
                              WORDS(offsetof(struct T_1433, l_Component_NSTest_HandlesEvents_NSTest_NSTest)),
                              WORDS(offsetof(struct T_1433, id_NSTest)),
                              WORDS(offsetof(struct T_1433, x_1404)),
                              WORDS(offsetof(struct T_1433, x_1406)),
                              0};
static WORD __GC__T_1432[] = {WORDS(sizeof(struct T_1432)),
                              0,
                              WORDS(offsetof(struct T_1432, l_Button_NSButton_Component_NSTest_NSButton)),
                              WORDS(offsetof(struct T_1432, l_Button_NSButton_HandlesMouseEvents_NSTest_NSButton)),
                              WORDS(offsetof(struct T_1432, x_1412)),
                              WORDS(offsetof(struct T_1432, x_1414)),
                              0};
static WORD __GC__T_1431[] = {WORDS(sizeof(struct T_1431)),
                              0,
                              WORDS(offsetof(struct T_1431, this_54)),
                              WORDS(offsetof(struct T_1431, id_15)),
                              WORDS(offsetof(struct T_1431, self_9)),
                              0};
static WORD __GC__T_1430[] = {WORDS(sizeof(struct T_1430)),
                              0,
                              WORDS(offsetof(struct T_1430, handleMouseEvent_40)),
                              WORDS(offsetof(struct T_1430, self_9)),
                              0};
static WORD __GC__T_1429[] = {WORDS(sizeof(struct T_1429)),
                              0,
                              WORDS(offsetof(struct T_1429, self_9)),
                              0};
static WORD __GC__T_1428[] = {WORDS(sizeof(struct T_1428)),
                              0,
                              WORDS(offsetof(struct T_1428, self_9)),
                              0};
static WORD __GC__T_1427[] = {WORDS(sizeof(struct T_1427)),
                              0,
                              WORDS(offsetof(struct T_1427, self_9)),
                              0};
static WORD __GC__T_1426[] = {WORDS(sizeof(struct T_1426)),
                              0,
                              WORDS(offsetof(struct T_1426, a_1358)),
                              WORDS(offsetof(struct T_1426, self_9)),
                              0};
static WORD __GC__T_1425[] = {WORDS(sizeof(struct T_1425)),
                              0,
                              WORDS(offsetof(struct T_1425, self_9)),
                              0};
static WORD __GC__T_1424[] = {WORDS(sizeof(struct T_1424)),
                              0,
                              WORDS(offsetof(struct T_1424, self_9)),
                              0};
static WORD __GC__T_1423[] = {WORDS(sizeof(struct T_1423)),
                              0,
                              WORDS(offsetof(struct T_1423, a_1346)),
                              WORDS(offsetof(struct T_1423, id_15)),
                              WORDS(offsetof(struct T_1423, self_9)),
                              0};
static WORD __GC__T_1422[] = {WORDS(sizeof(struct T_1422)),
                              0,
                              WORDS(offsetof(struct T_1422, id_15)),
                              WORDS(offsetof(struct T_1422, self_9)),
                              0};
static WORD __GC__T_1421[] = {WORDS(sizeof(struct T_1421)),
                              0,
                              WORDS(offsetof(struct T_1421, self_9)),
                              0};
static WORD __GC__T_1420[] = {WORDS(sizeof(struct T_1420)),
                              0,
                              WORDS(offsetof(struct T_1420, a_1334)),
                              WORDS(offsetof(struct T_1420, id_15)),
                              WORDS(offsetof(struct T_1420, self_9)),
                              0};
static WORD __GC__T_1419[] = {WORDS(sizeof(struct T_1419)),
                              0,
                              WORDS(offsetof(struct T_1419, id_15)),
                              WORDS(offsetof(struct T_1419, self_9)),
                              0};
Component_NSTest c_322_NSButton (Button_NSButton v_324) {
    return v_324->l_Button_NSButton_Component_NSTest_NSButton;
}
HandlesMouseEvents_NSTest c_325_NSButton (Button_NSButton v_327) {
    return v_327->l_Button_NSButton_HandlesMouseEvents_NSTest_NSButton;
}
HasSize_NSTest c_329_NSButton (Button_NSButton a_328) {
    return a_328->l_Button_NSButton_Component_NSTest_NSButton->l_Component_NSTest_HasSize_NSTest_NSTest;
}
HandlesEvents_NSTest c_331_NSButton (Button_NSButton a_330) {
    return a_330->l_Button_NSButton_Component_NSTest_NSButton->l_Component_NSTest_HandlesEvents_NSTest_NSTest;
}
HasPosition_NSTest c_333_NSButton (Button_NSButton a_332) {
    return a_332->l_Button_NSButton_Component_NSTest_NSButton->l_Component_NSTest_HasSize_NSTest_NSTest->l_HasSize_NSTest_HasPosition_NSTest_NSTest;
}
Button_NSButton mkButton_NSButton (BITS32 a_1438,
                                   POLY env_8,
                                   Int d_1418) {
    Ref self_9;
    NEW (Ref, self_9, WORDS(sizeof(struct Ref))+
                      WORDS(sizeof(struct S_382)));
    INITREF(self_9);
    ((S_382)STATEOF(self_9))->GCINFO = __GC__S_382;
    CocoaID_NSTest id_15;
    id_15 = mkCocoaID_NSTest(0);
    CLOS setTitle_16;
    NEW (CLOS, setTitle_16, WORDS(sizeof(struct T_1419)));
    ((T_1419)setTitle_16)->GCINFO = __GC__T_1419;
    ((T_1419)setTitle_16)->Code = f_1447;
    ((T_1419)setTitle_16)->id_15 = id_15;
    ((T_1419)setTitle_16)->self_9 = self_9;
    CLOS getTitle_21;
    NEW (CLOS, getTitle_21, WORDS(sizeof(struct T_1421)));
    ((T_1421)getTitle_21)->GCINFO = __GC__T_1421;
    ((T_1421)getTitle_21)->Code = f_1450;
    ((T_1421)getTitle_21)->self_9 = self_9;
    CLOS setPosition_23;
    NEW (CLOS, setPosition_23, WORDS(sizeof(struct T_1422)));
    ((T_1422)setPosition_23)->GCINFO = __GC__T_1422;
    ((T_1422)setPosition_23)->Code = f_1458;
    ((T_1422)setPosition_23)->id_15 = id_15;
    ((T_1422)setPosition_23)->self_9 = self_9;
    CLOS getPosition_28;
    NEW (CLOS, getPosition_28, WORDS(sizeof(struct T_1424)));
    ((T_1424)getPosition_28)->GCINFO = __GC__T_1424;
    ((T_1424)getPosition_28)->Code = f_1461;
    ((T_1424)getPosition_28)->self_9 = self_9;
    CLOS setSize_30;
    NEW (CLOS, setSize_30, WORDS(sizeof(struct T_1425)));
    ((T_1425)setSize_30)->GCINFO = __GC__T_1425;
    ((T_1425)setSize_30)->Code = f_1468;
    ((T_1425)setSize_30)->self_9 = self_9;
    CLOS getSize_33;
    NEW (CLOS, getSize_33, WORDS(sizeof(struct T_1427)));
    ((T_1427)getSize_33)->GCINFO = __GC__T_1427;
    ((T_1427)getSize_33)->Code = f_1471;
    ((T_1427)getSize_33)->self_9 = self_9;
    CLOS destroy_35;
    NEW (CLOS, destroy_35, WORDS(sizeof(struct T_1428)));
    ((T_1428)destroy_35)->GCINFO = __GC__T_1428;
    ((T_1428)destroy_35)->Code = f_1474;
    ((T_1428)destroy_35)->self_9 = self_9;
    CLOS installMouseListener_37;
    NEW (CLOS, installMouseListener_37, WORDS(sizeof(struct T_1429)));
    ((T_1429)installMouseListener_37)->GCINFO = __GC__T_1429;
    ((T_1429)installMouseListener_37)->Code = f_1479;
    ((T_1429)installMouseListener_37)->self_9 = self_9;
    CLOS handleMouseEvent_40;
    NEW (CLOS, handleMouseEvent_40, WORDS(sizeof(struct CLOS)));
    handleMouseEvent_40->GCINFO = __GC__CLOS;
    handleMouseEvent_40->Code = ((void(*)(void))f_1485);
    CLOS handleEvent_47;
    NEW (CLOS, handleEvent_47, WORDS(sizeof(struct T_1430)));
    ((T_1430)handleEvent_47)->GCINFO = __GC__T_1430;
    ((T_1430)handleEvent_47)->Code = f_1490;
    ((T_1430)handleEvent_47)->handleMouseEvent_40 = handleMouseEvent_40;
    ((T_1430)handleEvent_47)->self_9 = self_9;
    CLOS init_53;
    CLOS x_1389;
    CLOS x_1391;
    CLOS x_1395;
    CLOS x_1397;
    CLOS x_1401;
    CLOS x_1404;
    CLOS x_1406;
    CLOS x_1409;
    CLOS x_1412;
    CLOS x_1414;
    T_1435 x_1505;
    T_1434 x_1516;
    T_1436 x_1522;
    T_1433 x_1532;
    T_1437 x_1538;
    Button_NSButton this_54;
    x_1389 = getPosition_28;
    x_1391 = setPosition_23;
    NEW (T_1435, x_1505, WORDS(sizeof(struct T_1435)));
    x_1505->GCINFO = __GC__T_1435;
    x_1505->getPosition_NSTest = f_1498;
    x_1505->setPosition_NSTest = f_1504;
    x_1505->x_1389 = x_1389;
    x_1505->x_1391 = x_1391;
    x_1395 = getSize_33;
    x_1397 = setSize_30;
    NEW (T_1434, x_1516, WORDS(sizeof(struct T_1434)));
    x_1516->GCINFO = __GC__T_1434;
    x_1516->l_HasSize_NSTest_HasPosition_NSTest_NSTest = (HasPosition_NSTest)x_1505;
    x_1516->getSize_NSTest = f_1509;
    x_1516->setSize_NSTest = f_1515;
    x_1516->x_1395 = x_1395;
    x_1516->x_1397 = x_1397;
    x_1401 = handleEvent_47;
    NEW (T_1436, x_1522, WORDS(sizeof(struct T_1436)));
    x_1522->GCINFO = __GC__T_1436;
    x_1522->handleEvent_NSTest = f_1521;
    x_1522->x_1401 = x_1401;
    x_1404 = destroy_35;
    x_1409 = installMouseListener_37;
    NEW (T_1437, x_1538, WORDS(sizeof(struct T_1437)));
    x_1538->GCINFO = __GC__T_1437;
    x_1538->installMouseListener_NSTest = f_1537;
    x_1538->x_1409 = x_1409;
    x_1412 = getTitle_21;
    x_1414 = setTitle_16;
    {   Array roots = CYCLIC_BEGIN(4,0);
        init_53 = (CLOS)roots->elems[0];
        x_1406 = (CLOS)roots->elems[1];
        x_1532 = (T_1433)roots->elems[2];
        this_54 = (Button_NSButton)roots->elems[3];
        NEW (CLOS, init_53, WORDS(sizeof(struct T_1431)));
        roots->elems[0] = (POLY)init_53;
        ((T_1431)(CLOS)roots->elems[0])->GCINFO = __GC__T_1431;
        ((T_1431)(CLOS)roots->elems[0])->Code = f_1494;
        ((T_1431)(CLOS)roots->elems[0])->this_54 = this_54;
        ((T_1431)(CLOS)roots->elems[0])->id_15 = id_15;
        ((T_1431)(CLOS)roots->elems[0])->self_9 = self_9;
        x_1406 = init_53;
        roots->elems[1] = (POLY)x_1406;
        NEW (T_1433, x_1532, WORDS(sizeof(struct T_1433)));
        roots->elems[2] = (POLY)x_1532;
        ((T_1433)roots->elems[2])->GCINFO = __GC__T_1433;
        ((T_1433)roots->elems[2])->l_Component_NSTest_HasSize_NSTest_NSTest = (HasSize_NSTest)x_1516;
        ((T_1433)roots->elems[2])->l_Component_NSTest_HandlesEvents_NSTest_NSTest = (HandlesEvents_NSTest)x_1522;
        ((T_1433)roots->elems[2])->id_NSTest = id_15;
        ((T_1433)roots->elems[2])->destroy_NSTest = f_1526;
        ((T_1433)roots->elems[2])->init_NSTest = f_1531;
        ((T_1433)roots->elems[2])->x_1404 = x_1404;
        ((T_1433)roots->elems[2])->x_1406 = x_1406;
        NEW (Button_NSButton, this_54, WORDS(sizeof(struct T_1432)));
        roots->elems[3] = (POLY)this_54;
        ((T_1432)(Button_NSButton)roots->elems[3])->GCINFO = __GC__T_1432;
        ((T_1432)(Button_NSButton)roots->elems[3])->l_Button_NSButton_Component_NSTest_NSButton = (Component_NSTest)x_1532;
        ((T_1432)(Button_NSButton)roots->elems[3])->l_Button_NSButton_HandlesMouseEvents_NSTest_NSButton = (HandlesMouseEvents_NSTest)x_1538;
        ((T_1432)(Button_NSButton)roots->elems[3])->getTitle_NSButton = f_1542;
        ((T_1432)(Button_NSButton)roots->elems[3])->setTitle_NSButton = f_1548;
        ((T_1432)(Button_NSButton)roots->elems[3])->x_1412 = x_1412;
        ((T_1432)(Button_NSButton)roots->elems[3])->x_1414 = x_1414;
        CYCLIC_END(roots, hp);
    }
    ((S_382)STATEOF(self_9))->myState_10 = (CocoaState_NSTest)1;
    Position_NSTest x_1549;
    NEW (Position_NSTest, x_1549, WORDS(sizeof(struct Position_NSTest)));
    x_1549->GCINFO = __GC__Position_NSTest;
    x_1549->x_NSTest = 0;
    x_1549->y_NSTest = 0;
    ((S_382)STATEOF(self_9))->position_11 = x_1549;
    Size_NSTest x_1550;
    NEW (Size_NSTest, x_1550, WORDS(sizeof(struct Size_NSTest)));
    x_1550->GCINFO = __GC__Size_NSTest;
    x_1550->width_NSTest = 0;
    x_1550->height_NSTest = 0;
    ((S_382)STATEOF(self_9))->size_12 = x_1550;
    ((S_382)STATEOF(self_9))->mouseEventHandler_13 = (Maybe_Prelude)1;
    ((S_382)STATEOF(self_9))->title_14 = getStr("TestButton");
    return this_54;
}
static TUP0 inithelper_51 (CocoaID_NSTest id_15, Ref self_52) {
    Msg d_70;
    d_70 = buttonSetTitle_NSButton(id_15,
                                   ((S_382)STATEOF(self_52))->title_14,
                                   Inherit,
                                   Inherit);
    Msg d_71;
    d_71 = buttonSetPosition_NSButton(id_15,
                                      ((S_382)STATEOF(self_52))->position_11,
                                      Inherit,
                                      Inherit);
    return (TUP0)0;
}
static TUP0 f_1446 (T_1420 this_1444) {
    Ref self_18;
    self_18 = (Ref)LOCK((OID)this_1444->self_9);
    ((S_382)STATEOF(self_18))->title_14 = this_1444->a_1334;
    CocoaState_NSTest x_1445;
    x_1445 = ((S_382)STATEOF(self_18))->myState_10;
    switch ((WORD)x_1445) {
        case 2: { Ref self_19;
                  self_19 = self_18;
                  Msg d_57;
                  d_57 = buttonSetTitle_NSButton(this_1444->id_15,
                                                 this_1444->a_1334,
                                                 Inherit,
                                                 Inherit);
                  UNLOCK((OID)self_18);
                  return (TUP0)0;
                }
                break;
        case 0: { Ref self_20;
                  self_20 = self_18;
                  UNLOCK((OID)self_18);
                  return (TUP0)0;
                }
                break;
        case 1: { Ref self_20;
                  self_20 = self_18;
                  UNLOCK((OID)self_18);
                  return (TUP0)0;
                }
                break;
    }
}
static Msg f_1447 (T_1419 this_1440,
                   LIST a_1334,
                   Time a_1335,
                   Time a_1336) {
    Msg x_1333;
    NEW (Msg, x_1333, WORDS(sizeof(struct T_1420)));
    ((T_1420)x_1333)->GCINFO = __GC__T_1420;
    ((T_1420)x_1333)->Code = f_1446;
    ((T_1420)x_1333)->a_1334 = a_1334;
    ((T_1420)x_1333)->id_15 = this_1440->id_15;
    ((T_1420)x_1333)->self_9 = this_1440->self_9;
    return (Msg)ASYNC(x_1333, a_1335, a_1336);
}
static LIST f_1450 (T_1421 this_1448, Int a_1340) {
    Ref self_22;
    self_22 = (Ref)LOCK((OID)this_1448->self_9);
    LIST x_1337;
    x_1337 = ((S_382)STATEOF(self_22))->title_14;
    UNLOCK((OID)self_22);
    return x_1337;
}
static TUP0 f_1457 (T_1423 this_1455) {
    Ref self_25;
    self_25 = (Ref)LOCK((OID)this_1455->self_9);
    CocoaState_NSTest x_1456;
    x_1456 = ((S_382)STATEOF(self_25))->myState_10;
    switch ((WORD)x_1456) {
        case 2: { Msg d_60;
                  d_60 = buttonSetPosition_NSButton(this_1455->id_15,
                                                    this_1455->a_1346,
                                                    Inherit,
                                                    Inherit);
                  break;
                }
                break;
        case 0: break;
        case 1: break;
    }
    ((S_382)STATEOF(self_25))->position_11 = this_1455->a_1346;
    UNLOCK((OID)self_25);
    return (TUP0)0;
}
static Msg f_1458 (T_1422 this_1451,
                   Position_NSTest a_1346,
                   Time a_1347,
                   Time a_1348) {
    Msg x_1345;
    NEW (Msg, x_1345, WORDS(sizeof(struct T_1423)));
    ((T_1423)x_1345)->GCINFO = __GC__T_1423;
    ((T_1423)x_1345)->Code = f_1457;
    ((T_1423)x_1345)->a_1346 = a_1346;
    ((T_1423)x_1345)->id_15 = this_1451->id_15;
    ((T_1423)x_1345)->self_9 = this_1451->self_9;
    return (Msg)ASYNC(x_1345, a_1347, a_1348);
}
static Position_NSTest f_1461 (T_1424 this_1459, Int a_1352) {
    Ref self_29;
    self_29 = (Ref)LOCK((OID)this_1459->self_9);
    Position_NSTest x_1349;
    x_1349 = ((S_382)STATEOF(self_29))->position_11;
    UNLOCK((OID)self_29);
    return x_1349;
}
static TUP0 f_1467 (T_1426 this_1466) {
    Ref self_32;
    self_32 = (Ref)LOCK((OID)this_1466->self_9);
    ((S_382)STATEOF(self_32))->size_12 = this_1466->a_1358;
    UNLOCK((OID)self_32);
    return (TUP0)0;
}
static Msg f_1468 (T_1425 this_1462,
                   Size_NSTest a_1358,
                   Time a_1359,
                   Time a_1360) {
    Msg x_1357;
    NEW (Msg, x_1357, WORDS(sizeof(struct T_1426)));
    ((T_1426)x_1357)->GCINFO = __GC__T_1426;
    ((T_1426)x_1357)->Code = f_1467;
    ((T_1426)x_1357)->a_1358 = a_1358;
    ((T_1426)x_1357)->self_9 = this_1462->self_9;
    return (Msg)ASYNC(x_1357, a_1359, a_1360);
}
static Size_NSTest f_1471 (T_1427 this_1469, Int a_1364) {
    Ref self_34;
    self_34 = (Ref)LOCK((OID)this_1469->self_9);
    Size_NSTest x_1361;
    x_1361 = ((S_382)STATEOF(self_34))->size_12;
    UNLOCK((OID)self_34);
    return x_1361;
}
static TUP0 f_1474 (T_1428 this_1472, Int a_1367) {
    Ref self_36;
    self_36 = (Ref)LOCK((OID)this_1472->self_9);
    ((S_382)STATEOF(self_36))->myState_10 = (CocoaState_NSTest)0;
    UNLOCK((OID)self_36);
    return (TUP0)0;
}
static TUP0 f_1479 (T_1429 this_1475, CLOS a_1372, Int a_1373) {
    Ref self_39;
    self_39 = (Ref)LOCK((OID)this_1475->self_9);
    _Just_Prelude x_1478;
    NEW (_Just_Prelude, x_1478, WORDS(sizeof(struct _Just_Prelude)));
    x_1478->GCINFO = __GC___Just_Prelude+((4 * (BITS32)0));
    x_1478->a = (POLY)a_1372;
    ((S_382)STATEOF(self_39))->mouseEventHandler_13 = (Maybe_Prelude)x_1478;
    UNLOCK((OID)self_39);
    return (TUP0)0;
}
static Bool f_1485 (CLOS this_1480,
                    BITS32 a_1484,
                    POLY a_1376,
                    Maybe_Prelude a_1377,
                    Ref a_1378) {
    switch ((WORD)a_1377) {
        case 1: return (Bool)0;
        default: { CLOS x_65;
                   x_65 = (CLOS)((_Just_Prelude)a_1377)->a;
                   Bool x_64;
                   x_64 = ((Bool(*)(CLOS, POLY, Int))(x_65->Code))(x_65, a_1376, 0);
                   return x_64;
                 }
                 break;
    }
}
static Bool f_1490 (T_1430 this_1486,
                    CocoaEvent_NSTest a_1383,
                    Int a_1384) {
    switch (a_1383->Tag) {
        case 1: { MouseEventType_NSTest x_69;
                  x_69 = ((_MouseEvent_NSTest)a_1383)->a;
                  Ref self_49;
                  self_49 = (Ref)LOCK((OID)this_1486->self_9);
                  CLOS x_1489;
                  x_1489 = this_1486->handleMouseEvent_40;
                  Bool x_67;
                  x_67 = ((Bool(*)(CLOS, BITS32, POLY, Maybe_Prelude, Ref))(x_1489->Code))(x_1489,
                                                                                           (BITS32)0,
                                                                                           (POLY)x_69,
                                                                                           ((S_382)STATEOF(self_49))->mouseEventHandler_13,
                                                                                           self_49);
                  UNLOCK((OID)self_49);
                  return x_67;
                }
                break;
        default: { Ref self_50;
                   self_50 = (Ref)LOCK((OID)this_1486->self_9);
                   UNLOCK((OID)self_50);
                   return (Bool)0;
                 }
                 break;
    }
}
static TUP0 f_1494 (T_1431 this_1491,
                    App_NSTest a_1387,
                    Int a_1388) {
    Ref self_56;
    self_56 = (Ref)LOCK((OID)this_1491->self_9);
    ((S_382)STATEOF(self_56))->myState_10 = (CocoaState_NSTest)2;
    TUP0 d_72;
    d_72 = initButton_NSButton(this_1491->this_54, a_1387, 0);
    TUP0 d_73;
    d_73 = inithelper_51(this_1491->id_15, self_56);
    UNLOCK((OID)self_56);
    return (TUP0)0;
}
static Position_NSTest f_1498 (T_1435 this_1495, Int a_1390) {
    CLOS x_1497;
    x_1497 = this_1495->x_1389;
    return ((Position_NSTest(*)(CLOS, Int))(x_1497->Code))(x_1497,
                                                           a_1390);
}
static Msg f_1504 (T_1435 this_1499,
                   Position_NSTest a_1392,
                   Time a_1393,
                   Time a_1394) {
    CLOS x_1503;
    x_1503 = this_1499->x_1391;
    return ((Msg(*)(CLOS, Position_NSTest, Time, Time))(x_1503->Code))(x_1503,
                                                                       a_1392,
                                                                       a_1393,
                                                                       a_1394);
}
static Size_NSTest f_1509 (T_1434 this_1506, Int a_1396) {
    CLOS x_1508;
    x_1508 = this_1506->x_1395;
    return ((Size_NSTest(*)(CLOS, Int))(x_1508->Code))(x_1508, a_1396);
}
static Msg f_1515 (T_1434 this_1510,
                   Size_NSTest a_1398,
                   Time a_1399,
                   Time a_1400) {
    CLOS x_1514;
    x_1514 = this_1510->x_1397;
    return ((Msg(*)(CLOS, Size_NSTest, Time, Time))(x_1514->Code))(x_1514,
                                                                   a_1398,
                                                                   a_1399,
                                                                   a_1400);
}
static Bool f_1521 (T_1436 this_1517,
                    CocoaEvent_NSTest a_1402,
                    Int a_1403) {
    CLOS x_1520;
    x_1520 = this_1517->x_1401;
    return ((Bool(*)(CLOS, CocoaEvent_NSTest, Int))(x_1520->Code))(x_1520,
                                                                   a_1402,
                                                                   a_1403);
}
static TUP0 f_1526 (T_1433 this_1523, Int a_1405) {
    CLOS x_1525;
    x_1525 = this_1523->x_1404;
    return ((TUP0(*)(CLOS, Int))(x_1525->Code))(x_1525, a_1405);
}
static TUP0 f_1531 (T_1433 this_1527,
                    App_NSTest a_1407,
                    Int a_1408) {
    CLOS x_1530;
    x_1530 = this_1527->x_1406;
    return ((TUP0(*)(CLOS, App_NSTest, Int))(x_1530->Code))(x_1530,
                                                            a_1407,
                                                            a_1408);
}
static TUP0 f_1537 (T_1437 this_1533, CLOS a_1410, Int a_1411) {
    CLOS x_1536;
    x_1536 = this_1533->x_1409;
    return ((TUP0(*)(CLOS, CLOS, Int))(x_1536->Code))(x_1536,
                                                      a_1410,
                                                      a_1411);
}
static LIST f_1542 (T_1432 this_1539, Int a_1413) {
    CLOS x_1541;
    x_1541 = this_1539->x_1412;
    return ((LIST(*)(CLOS, Int))(x_1541->Code))(x_1541, a_1413);
}
static Msg f_1548 (T_1432 this_1543,
                   LIST a_1415,
                   Time a_1416,
                   Time a_1417) {
    CLOS x_1547;
    x_1547 = this_1543->x_1414;
    return ((Msg(*)(CLOS, LIST, Time, Time))(x_1547->Code))(x_1547,
                                                            a_1415,
                                                            a_1416,
                                                            a_1417);
}
 
void _init_NSButton () {
    static int INITIALIZED = 0;
    if (!INITIALIZED) {
        _init_Prelude();
        _init_NSTest();
        INITIALIZED = 1;
    }
}
 

