#include "CTApplication.h"
 
struct S_306;
typedef struct S_306 *S_306;
struct T_1447;
typedef struct T_1447 *T_1447;
struct T_1446;
typedef struct T_1446 *T_1446;
struct T_1445;
typedef struct T_1445 *T_1445;
struct T_1444;
typedef struct T_1444 *T_1444;
struct T_1443;
typedef struct T_1443 *T_1443;
struct T_1442;
typedef struct T_1442 *T_1442;
struct T_1441;
typedef struct T_1441 *T_1441;
struct T_1440;
typedef struct T_1440 *T_1440;
struct T_1439;
typedef struct T_1439 *T_1439;
 
struct S_306 {
    POLY GCINFO;
    LIST activeWindows_3;
    LIST modifiers_4;
    Maybe_Prelude env_5;
};
struct T_1447 {
    POLY GCINFO;
    TUP0 (*showWindow_CTCommon) (T_1447, CocoaWindow_CTCommon, Int);
    ApplicationState_CTCommon (*getApplicationState_CTCommon) (T_1447,
                                                               Int);
    Msg (*eventDispatcher_CTCommon) (T_1447,
                                     CocoaEvent_CTCommon,
                                     Int,
                                     Time,
                                     Time);
    TUP0 (*setEnv_CTCommon) (T_1447, Env_POSIX, Int);
    CLOS x_1424;
    CLOS x_1429;
    CLOS x_1431;
    CLOS x_1434;
};
struct T_1446 {
    POLY GCINFO;
    TUP0 (*Code) (T_1446, CocoaWindow_CTCommon, Int);
    App_CTCommon this_39;
    Ref self_2;
};
struct T_1445 {
    POLY GCINFO;
    TUP0 (*Code) (T_1445, Env_POSIX, Int);
    Ref self_2;
};
struct T_1444 {
    POLY GCINFO;
    ApplicationState_CTCommon (*Code) (T_1444, Int);
    Ref self_2;
};
struct T_1443 {
    POLY GCINFO;
    TUP0 (*Code) (T_1443);
    AbsTime baseline;
    AbsTime deadline;
    Msg next;
    CocoaEvent_CTCommon a_1409;
    Int a_1410;
    Ref self_2;
};
struct T_1442 {
    POLY GCINFO;
    TUP0 (*Code) (T_1442);
    AbsTime baseline;
    AbsTime deadline;
    Msg next;
    KeyEventType_CTCommon x_62;
    Int a_1410;
    Ref self_2;
};
struct T_1441 {
    POLY GCINFO;
    Msg (*Code) (T_1441, CocoaEvent_CTCommon, Int, Time, Time);
    Ref self_2;
};
struct T_1440 {
    POLY GCINFO;
    TUP0 (*Code) (T_1440, CocoaWindow_CTCommon, Ref);
    CocoaEvent_CTCommon recvEvent_13;
    Int windowId_14;
};
struct T_1439 {
    POLY GCINFO;
    TUP0 (*Code) (T_1439);
    AbsTime baseline;
    AbsTime deadline;
    Msg next;
    CocoaEvent_CTCommon recvEvent_13;
    Int windowId_14;
    Ref self_2;
};
 
static WORD __GC__S_306[];
static WORD __GC__T_1447[];
static WORD __GC__T_1446[];
static WORD __GC__T_1445[];
static WORD __GC__T_1444[];
static WORD __GC__T_1443[];
static WORD __GC__T_1442[];
static WORD __GC__T_1441[];
static WORD __GC__T_1440[];
static WORD __GC__T_1439[];
static Msg sendToWindow_12 (Ref self_2,
                            CocoaEvent_CTCommon recvEvent_13,
                            Int windowId_14,
                            Time a_1396,
                            Time a_1397);
static TUP0 updateList_6 (CocoaKey_CTCommon key_7, Ref self_8);
static LIST f_1391 (CocoaKey_CTCommon key_7, LIST a_44);
static TUP0 f_1457 (T_1442 this_1454);
static TUP0 f_1459 (T_1443 this_1458);
static Msg f_1460 (T_1441 this_1449,
                   CocoaEvent_CTCommon a_1409,
                   Int a_1410,
                   Time a_1411,
                   Time a_1412);
static ApplicationState_CTCommon f_1463 (T_1444 this_1461,
                                         Int a_1415);
static TUP0 f_1468 (T_1445 this_1464,
                    Env_POSIX a_1418,
                    Int a_1419);
static TUP0 f_1473 (T_1446 this_1469,
                    CocoaWindow_CTCommon a_1422,
                    Int a_1423);
static Msg f_1480 (T_1447 this_1474,
                   CocoaEvent_CTCommon a_1425,
                   Int a_1426,
                   Time a_1427,
                   Time a_1428);
static ApplicationState_CTCommon f_1484 (T_1447 this_1481,
                                         Int a_1430);
static TUP0 f_1489 (T_1447 this_1485,
                    Env_POSIX a_1432,
                    Int a_1433);
static TUP0 f_1494 (T_1447 this_1490,
                    CocoaWindow_CTCommon a_1435,
                    Int a_1436);
static TUP0 f_1500 (T_1440 this_1496,
                    CocoaWindow_CTCommon a_1392,
                    Ref a_1393);
static TUP0 f_1502 (T_1439 this_1495);
 
static WORD __GC__S_306[] = {WORDS(sizeof(struct S_306)),
                             0,
                             WORDS(offsetof(struct S_306, activeWindows_3)),
                             WORDS(offsetof(struct S_306, modifiers_4)),
                             WORDS(offsetof(struct S_306, env_5)),
                             0};
static WORD __GC__T_1447[] = {WORDS(sizeof(struct T_1447)),
                              0,
                              WORDS(offsetof(struct T_1447, x_1424)),
                              WORDS(offsetof(struct T_1447, x_1429)),
                              WORDS(offsetof(struct T_1447, x_1431)),
                              WORDS(offsetof(struct T_1447, x_1434)),
                              0};
static WORD __GC__T_1446[] = {WORDS(sizeof(struct T_1446)),
                              0,
                              WORDS(offsetof(struct T_1446, this_39)),
                              WORDS(offsetof(struct T_1446, self_2)),
                              0};
static WORD __GC__T_1445[] = {WORDS(sizeof(struct T_1445)),
                              0,
                              WORDS(offsetof(struct T_1445, self_2)),
                              0};
static WORD __GC__T_1444[] = {WORDS(sizeof(struct T_1444)),
                              0,
                              WORDS(offsetof(struct T_1444, self_2)),
                              0};
static WORD __GC__T_1443[] = {WORDS(sizeof(struct T_1443)),
                              0,
                              WORDS(offsetof(struct T_1443, a_1409)),
                              WORDS(offsetof(struct T_1443, self_2)),
                              0};
static WORD __GC__T_1442[] = {WORDS(sizeof(struct T_1442)),
                              0,
                              WORDS(offsetof(struct T_1442, x_62)),
                              WORDS(offsetof(struct T_1442, self_2)),
                              0};
static WORD __GC__T_1441[] = {WORDS(sizeof(struct T_1441)),
                              0,
                              WORDS(offsetof(struct T_1441, self_2)),
                              0};
static WORD __GC__T_1440[] = {WORDS(sizeof(struct T_1440)),
                              0,
                              WORDS(offsetof(struct T_1440, recvEvent_13)),
                              0};
static WORD __GC__T_1439[] = {WORDS(sizeof(struct T_1439)),
                              0,
                              WORDS(offsetof(struct T_1439, recvEvent_13)),
                              WORDS(offsetof(struct T_1439, self_2)),
                              0};
App_CTCommon cocoaApplication_CTApplication (Int d_1437) {
    Ref self_2;
    NEW (Ref, self_2, WORDS(sizeof(struct Ref))+
                      WORDS(sizeof(struct S_306)));
    INITREF(self_2);
    ((S_306)STATEOF(self_2))->GCINFO = __GC__S_306;
    CLOS eventDispatcher_20;
    NEW (CLOS, eventDispatcher_20, WORDS(sizeof(struct T_1441)));
    ((T_1441)eventDispatcher_20)->GCINFO = __GC__T_1441;
    ((T_1441)eventDispatcher_20)->Code = f_1460;
    ((T_1441)eventDispatcher_20)->self_2 = self_2;
    CLOS getApplicationState_33;
    NEW (CLOS, getApplicationState_33, WORDS(sizeof(struct T_1444)));
    ((T_1444)getApplicationState_33)->GCINFO = __GC__T_1444;
    ((T_1444)getApplicationState_33)->Code = f_1463;
    ((T_1444)getApplicationState_33)->self_2 = self_2;
    CLOS setEnv_35;
    NEW (CLOS, setEnv_35, WORDS(sizeof(struct T_1445)));
    ((T_1445)setEnv_35)->GCINFO = __GC__T_1445;
    ((T_1445)setEnv_35)->Code = f_1468;
    ((T_1445)setEnv_35)->self_2 = self_2;
    CLOS showWindow_38;
    CLOS x_1424;
    CLOS x_1429;
    CLOS x_1431;
    CLOS x_1434;
    App_CTCommon this_39;
    x_1424 = eventDispatcher_20;
    x_1429 = getApplicationState_33;
    x_1431 = setEnv_35;
    {   Array roots = CYCLIC_BEGIN(3,0);
        showWindow_38 = (CLOS)roots->elems[0];
        x_1434 = (CLOS)roots->elems[1];
        this_39 = (App_CTCommon)roots->elems[2];
        NEW (CLOS, showWindow_38, WORDS(sizeof(struct T_1446)));
        roots->elems[0] = (POLY)showWindow_38;
        ((T_1446)(CLOS)roots->elems[0])->GCINFO = __GC__T_1446;
        ((T_1446)(CLOS)roots->elems[0])->Code = f_1473;
        ((T_1446)(CLOS)roots->elems[0])->this_39 = this_39;
        ((T_1446)(CLOS)roots->elems[0])->self_2 = self_2;
        x_1434 = showWindow_38;
        roots->elems[1] = (POLY)x_1434;
        NEW (App_CTCommon, this_39, WORDS(sizeof(struct T_1447)));
        roots->elems[2] = (POLY)this_39;
        ((T_1447)(App_CTCommon)roots->elems[2])->GCINFO = __GC__T_1447;
        ((T_1447)(App_CTCommon)roots->elems[2])->eventDispatcher_CTCommon = f_1480;
        ((T_1447)(App_CTCommon)roots->elems[2])->getApplicationState_CTCommon = f_1484;
        ((T_1447)(App_CTCommon)roots->elems[2])->setEnv_CTCommon = f_1489;
        ((T_1447)(App_CTCommon)roots->elems[2])->showWindow_CTCommon = f_1494;
        ((T_1447)(App_CTCommon)roots->elems[2])->x_1424 = x_1424;
        ((T_1447)(App_CTCommon)roots->elems[2])->x_1429 = x_1429;
        ((T_1447)(App_CTCommon)roots->elems[2])->x_1431 = x_1431;
        ((T_1447)(App_CTCommon)roots->elems[2])->x_1434 = x_1434;
        CYCLIC_END(roots, hp);
    }
    ((S_306)STATEOF(self_2))->activeWindows_3 = (LIST)0;
    ((S_306)STATEOF(self_2))->modifiers_4 = (LIST)0;
    ((S_306)STATEOF(self_2))->env_5 = (Maybe_Prelude)1;
    return this_39;
}
static Msg sendToWindow_12 (Ref self_2,
                            CocoaEvent_CTCommon recvEvent_13,
                            Int windowId_14,
                            Time a_1396,
                            Time a_1397) {
    Msg x_1398;
    NEW (Msg, x_1398, WORDS(sizeof(struct T_1439)));
    ((T_1439)x_1398)->GCINFO = __GC__T_1439;
    ((T_1439)x_1398)->Code = f_1502;
    ((T_1439)x_1398)->recvEvent_13 = recvEvent_13;
    ((T_1439)x_1398)->windowId_14 = windowId_14;
    ((T_1439)x_1398)->self_2 = self_2;
    return (Msg)ASYNC(x_1398, a_1396, a_1397);
}
static TUP0 updateList_6 (CocoaKey_CTCommon key_7, Ref self_8) {
    switch ((WORD)elem_Prelude((BITS32)0,
                               eqCocoaKey_CTCommon,
                               (POLY)key_7,
                               ((S_306)STATEOF(self_8))->modifiers_4)) {
        case 1: { Ref self_9;
                  self_9 = self_8;
                  ((S_306)STATEOF(self_9))->modifiers_4 = f_1391(key_7,
                                                                 ((S_306)STATEOF(self_9))->modifiers_4);
                  return (TUP0)0;
                }
                break;
        case 0: { Ref self_11;
                  self_11 = self_8;
                  CONS x_1503;
                  NEW (CONS, x_1503, WORDS(sizeof(struct CONS)));
                  x_1503->GCINFO = __GC__CONS+((5 * (BITS32)0));
                  x_1503->hd = (POLY)key_7;
                  x_1503->tl = ((S_306)STATEOF(self_11))->modifiers_4;
                  ((S_306)STATEOF(self_11))->modifiers_4 = (LIST)x_1503;
                  return (TUP0)0;
                }
                break;
    }
}
static LIST f_1391 (CocoaKey_CTCommon key_7, LIST a_44) {
    MUTLIST x_1438;
    x_1438 = MUTLISTINIT((BITS32)0);
    while ((Bool)1) {
        switch ((WORD)a_44) {
            case 0: return MUTLISTEXTRACT((BITS32)0, x_1438);
            default: { CocoaKey_CTCommon x_45;
                       LIST x_46;
                       x_45 = (CocoaKey_CTCommon)((CONS)a_44)->hd;
                       x_46 = ((CONS)a_44)->tl;
                       switch ((WORD)compareKeys_CTCommon(x_45, key_7)) {
                           case 1: { MUTLISTEXTEND((BITS32)0, x_1438, (POLY)x_45);
                                     a_44 = x_46;
                                     continue;
                                   }
                                   break;
                           case 0: { a_44 = x_46;
                                     continue;
                                   }
                                   break;
                       }
                     }
                     break;
        }
    }
    RAISE(1);
}
static TUP0 f_1457 (T_1442 this_1454) {
    Ref self_23;
    self_23 = (Ref)LOCK((OID)this_1454->self_2);
    KeyEventType_CTCommon x_1455;
    x_1455 = this_1454->x_62;
    switch (x_1455->Tag) {
        case 1: { CocoaKey_CTCommon x_60;
                  x_60 = ((_KeyPressed_CTCommon)x_1455)->a;
                  Ref x_52;
                  x_52 = self_23;
                  switch ((WORD)x_60) {
                      case 78: { TUP0 d_54;
                                 d_54 = updateList_6(x_60, x_52);
                                 break;
                               }
                               break;
                      case 70: { TUP0 d_55;
                                 d_55 = updateList_6(x_60, x_52);
                                 break;
                               }
                               break;
                      case 67: { TUP0 d_56;
                                 d_56 = updateList_6(x_60, x_52);
                                 break;
                               }
                               break;
                      case 71: { TUP0 d_57;
                                 d_57 = updateList_6(x_60, x_52);
                                 break;
                               }
                               break;
                      case 0: break;
                      case 1: break;
                      case 2: break;
                      case 3: break;
                      case 4: break;
                      case 5: break;
                      case 6: break;
                      case 7: break;
                      case 8: break;
                      case 9: break;
                      case 10: break;
                      case 11: break;
                      case 12: break;
                      case 13: break;
                      case 14: break;
                      case 15: break;
                      case 16: break;
                      case 17: break;
                      case 18: break;
                      case 19: break;
                      case 20: break;
                      case 21: break;
                      case 22: break;
                      case 23: break;
                      case 24: break;
                      case 25: break;
                      case 26: break;
                      case 27: break;
                      case 28: break;
                      case 29: break;
                      case 30: break;
                      case 31: break;
                      case 32: break;
                      case 33: break;
                      case 34: break;
                      case 35: break;
                      case 36: break;
                      case 37: break;
                      case 38: break;
                      case 39: break;
                      case 40: break;
                      case 41: break;
                      case 42: break;
                      case 43: break;
                      case 44: break;
                      case 45: break;
                      case 46: break;
                      case 47: break;
                      case 48: break;
                      case 49: break;
                      case 50: break;
                      case 51: break;
                      case 52: break;
                      case 53: break;
                      case 54: break;
                      case 55: break;
                      case 56: break;
                      case 57: break;
                      case 58: break;
                      case 59: break;
                      case 60: break;
                      case 61: break;
                      case 62: break;
                      case 63: break;
                      case 64: break;
                      case 65: break;
                      case 66: break;
                      case 68: break;
                      case 69: break;
                      case 72: break;
                      case 73: break;
                      case 74: break;
                      case 75: break;
                      case 76: break;
                      case 77: break;
                      case 79: break;
                      case 80: break;
                      case 81: break;
                      case 82: break;
                      case 83: break;
                      case 84: break;
                      case 85: break;
                      case 86: break;
                      case 87: break;
                      case 88: break;
                      case 89: break;
                      case 90: break;
                      case 91: break;
                      case 92: break;
                      case 93: break;
                      case 94: break;
                      case 95: break;
                      case 96: break;
                      case 97: break;
                      case 98: break;
                      case 99: break;
                      case 100: break;
                      case 101: break;
                      case 102: break;
                      case 103: break;
                      case 104: break;
                      case 105: break;
                      case 106: break;
                      case 107: break;
                      case 108: break;
                      case 109: break;
                      case 110: break;
                      case 111: break;
                      case 112: break;
                      case 113: break;
                      case 114: break;
                      case 115: break;
                      case 116: break;
                      case 117: break;
                      case 118: break;
                      case 119: break;
                      case 120: break;
                      case 121: break;
                      case 122: break;
                      case 123: break;
                      case 124: break;
                      case 125: break;
                      case 126: break;
                  }
                  _KeyEvent_CTCommon x_1456;
                  NEW (_KeyEvent_CTCommon, x_1456, WORDS(sizeof(struct _KeyEvent_CTCommon)));
                  x_1456->GCINFO = __GC___KeyEvent_CTCommon;
                  x_1456->Tag = 0;
                  x_1456->a = this_1454->x_62;
                  Msg d_59;
                  d_59 = sendToWindow_12(this_1454->self_2,
                                         (CocoaEvent_CTCommon)x_1456,
                                         this_1454->a_1410,
                                         Inherit,
                                         Inherit);
                  UNLOCK((OID)self_23);
                  return (TUP0)0;
                }
                break;
        default: RAISE(1);
    }
}
static TUP0 f_1459 (T_1443 this_1458) {
    Ref self_32;
    self_32 = (Ref)LOCK((OID)this_1458->self_2);
    Msg d_61;
    d_61 = sendToWindow_12(this_1458->self_2,
                           this_1458->a_1409,
                           this_1458->a_1410,
                           Inherit,
                           Inherit);
    UNLOCK((OID)self_32);
    return (TUP0)0;
}
static Msg f_1460 (T_1441 this_1449,
                   CocoaEvent_CTCommon a_1409,
                   Int a_1410,
                   Time a_1411,
                   Time a_1412) {
    switch (a_1409->Tag) {
        case 0: { KeyEventType_CTCommon x_62;
                  x_62 = ((_KeyEvent_CTCommon)a_1409)->a;
                  Msg x_1403;
                  NEW (Msg, x_1403, WORDS(sizeof(struct T_1442)));
                  ((T_1442)x_1403)->GCINFO = __GC__T_1442;
                  ((T_1442)x_1403)->Code = f_1457;
                  ((T_1442)x_1403)->x_62 = x_62;
                  ((T_1442)x_1403)->a_1410 = a_1410;
                  ((T_1442)x_1403)->self_2 = this_1449->self_2;
                  return (Msg)ASYNC(x_1403, a_1411, a_1412);
                }
                break;
        default: { Msg x_1408;
                   NEW (Msg, x_1408, WORDS(sizeof(struct T_1443)));
                   ((T_1443)x_1408)->GCINFO = __GC__T_1443;
                   ((T_1443)x_1408)->Code = f_1459;
                   ((T_1443)x_1408)->a_1409 = a_1409;
                   ((T_1443)x_1408)->a_1410 = a_1410;
                   ((T_1443)x_1408)->self_2 = this_1449->self_2;
                   return (Msg)ASYNC(x_1408, a_1411, a_1412);
                 }
                 break;
    }
}
static ApplicationState_CTCommon f_1463 (T_1444 this_1461,
                                         Int a_1415) {
    Ref self_34;
    self_34 = (Ref)LOCK((OID)this_1461->self_2);
    UNLOCK((OID)self_34);
    return (ApplicationState_CTCommon)1;
}
static TUP0 f_1468 (T_1445 this_1464,
                    Env_POSIX a_1418,
                    Int a_1419) {
    Ref self_37;
    self_37 = (Ref)LOCK((OID)this_1464->self_2);
    _Just_Prelude x_1467;
    NEW (_Just_Prelude, x_1467, WORDS(sizeof(struct _Just_Prelude)));
    x_1467->GCINFO = __GC___Just_Prelude+((4 * (BITS32)0));
    x_1467->a = (POLY)a_1418;
    ((S_306)STATEOF(self_37))->env_5 = (Maybe_Prelude)x_1467;
    UNLOCK((OID)self_37);
    return (TUP0)0;
}
static TUP0 f_1473 (T_1446 this_1469,
                    CocoaWindow_CTCommon a_1422,
                    Int a_1423) {
    Ref self_41;
    self_41 = (Ref)LOCK((OID)this_1469->self_2);
    TUP0 d_63;
    d_63 = a_1422->initWindow_CTCommon(a_1422, this_1469->this_39, 0);
    CONS x_1472;
    NEW (CONS, x_1472, WORDS(sizeof(struct CONS)));
    x_1472->GCINFO = __GC__CONS+((5 * (BITS32)0));
    x_1472->hd = (POLY)a_1422;
    x_1472->tl = ((S_306)STATEOF(self_41))->activeWindows_3;
    ((S_306)STATEOF(self_41))->activeWindows_3 = (LIST)x_1472;
    UNLOCK((OID)self_41);
    return (TUP0)0;
}
static Msg f_1480 (T_1447 this_1474,
                   CocoaEvent_CTCommon a_1425,
                   Int a_1426,
                   Time a_1427,
                   Time a_1428) {
    CLOS x_1479;
    x_1479 = this_1474->x_1424;
    return ((Msg(*)(CLOS, CocoaEvent_CTCommon, Int, Time, Time))(x_1479->Code))(x_1479,
                                                                                a_1425,
                                                                                a_1426,
                                                                                a_1427,
                                                                                a_1428);
}
static ApplicationState_CTCommon f_1484 (T_1447 this_1481,
                                         Int a_1430) {
    CLOS x_1483;
    x_1483 = this_1481->x_1429;
    return ((ApplicationState_CTCommon(*)(CLOS, Int))(x_1483->Code))(x_1483,
                                                                     a_1430);
}
static TUP0 f_1489 (T_1447 this_1485,
                    Env_POSIX a_1432,
                    Int a_1433) {
    CLOS x_1488;
    x_1488 = this_1485->x_1431;
    return ((TUP0(*)(CLOS, Env_POSIX, Int))(x_1488->Code))(x_1488,
                                                           a_1432,
                                                           a_1433);
}
static TUP0 f_1494 (T_1447 this_1490,
                    CocoaWindow_CTCommon a_1435,
                    Int a_1436) {
    CLOS x_1493;
    x_1493 = this_1490->x_1434;
    return ((TUP0(*)(CLOS, CocoaWindow_CTCommon, Int))(x_1493->Code))(x_1493,
                                                                      a_1435,
                                                                      a_1436);
}
static TUP0 f_1500 (T_1440 this_1496,
                    CocoaWindow_CTCommon a_1392,
                    Ref a_1393) {
    Int x_48;
    x_48 = a_1392->getId_CTCommon(a_1392, 0);
    switch ((WORD)_sym_635_Prelude/* == */(x_48,
                                           this_1496->windowId_14)) {
        case 1: { Ref self_18;
                  self_18 = a_1393;
                  HandlesEvents_CTCommon x_1499;
                  x_1499 = a_1392->l_CocoaWindow_CTCommon_HandlesWindowEvents_CTCommon_CTCommon->l_HandlesWindowEvents_CTCommon_HandlesEvents_CTCommon_CTCommon;
                  Maybe_Prelude d_49;
                  d_49 = x_1499->handleEvent_CTCommon(x_1499,
                                                      this_1496->recvEvent_13,
                                                      ((S_306)STATEOF(self_18))->modifiers_4,
                                                      0);
                  return (TUP0)0;
                }
                break;
        case 0: { Ref self_19;
                  self_19 = a_1393;
                  return (TUP0)0;
                }
                break;
    }
}
static TUP0 f_1502 (T_1439 this_1495) {
    Ref self_15;
    self_15 = (Ref)LOCK((OID)this_1495->self_2);
    T_1440 x_1501;
    NEW (T_1440, x_1501, WORDS(sizeof(struct T_1440)));
    x_1501->GCINFO = __GC__T_1440;
    x_1501->Code = f_1500;
    x_1501->recvEvent_13 = this_1495->recvEvent_13;
    x_1501->windowId_14 = this_1495->windowId_14;
    TUP0 d_47;
    d_47 = forallListUnit_Prelude((BITS32)4,
                                  (CLOS)x_1501,
                                  ((S_306)STATEOF(self_15))->activeWindows_3,
                                  self_15);
    UNLOCK((OID)self_15);
    return (TUP0)0;
}
 
void _init_CTApplication () {
    static int INITIALIZED = 0;
    if (!INITIALIZED) {
        _init_Prelude();
        _init_CTCommon();
        INITIALIZED = 1;
    }
}
 

