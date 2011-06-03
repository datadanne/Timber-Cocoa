#include "CTCommon.h"
#include "CTCommon.extern.c"
 
struct S_613;
typedef struct S_613 *S_613;
struct T_1677;
typedef struct T_1677 *T_1677;
struct T_1676;
typedef struct T_1676 *T_1676;
struct T_1675;
typedef struct T_1675 *T_1675;
struct T_1674;
typedef struct T_1674 *T_1674;
struct T_1673;
typedef struct T_1673 *T_1673;
 
struct S_613 {
    POLY GCINFO;
    Maybe_Prelude next_222;
    Maybe_Prelude previous_223;
    Bool isFocusable_224;
};
struct T_1677 {
    POLY GCINFO;
    TUP0 (*setNextFocusTarget_CTCommon) (T_1677, Maybe_Prelude, Int);
    Maybe_Prelude (*getNextFocusTarget_CTCommon) (T_1677, Int);
    TUP0 (*setPreviousFocusTarget_CTCommon) (T_1677,
                                             Maybe_Prelude,
                                             Int);
    Maybe_Prelude (*getPreviousFocusTarget_CTCommon) (T_1677, Int);
    TUP0 (*setIsFocusable_CTCommon) (T_1677, Bool, Int);
    Bool (*getIsFocusable_CTCommon) (T_1677, Int);
    CLOS x_1650;
    CLOS x_1647;
    CLOS x_1644;
    CLOS x_1642;
    CLOS x_1640;
    CLOS x_1638;
};
struct T_1676 {
    POLY GCINFO;
    Bool (*Code) (T_1676, Int);
    Ref self_221;
};
struct T_1675 {
    POLY GCINFO;
    TUP0 (*Code) (T_1675, Bool, Int);
    Ref self_221;
};
struct T_1674 {
    POLY GCINFO;
    Maybe_Prelude (*Code) (T_1674, Int);
    Ref self_221;
};
struct T_1673 {
    POLY GCINFO;
    TUP0 (*Code) (T_1673, Maybe_Prelude, Int);
    Ref self_221;
};
 
static WORD __GC__S_613[];
static WORD __GC__T_1677[];
static WORD __GC__T_1676[];
static WORD __GC__T_1675[];
static WORD __GC__T_1674[];
static WORD __GC__T_1673[];
Eq_Prelude eqCocoaState_CTCommon;
Eq_Prelude eqCocoaKey_CTCommon;
static Maybe_Prelude focusResult_228 (Maybe_Prelude a_259,
                                      Ref a_1618);
static TUP0 f_1682 (T_1673 this_1679,
                    Maybe_Prelude a_1615,
                    Int a_1616);
static Maybe_Prelude f_1685 (T_1674 this_1683, Int a_1621);
static TUP0 f_1689 (T_1673 this_1686,
                    Maybe_Prelude a_1624,
                    Int a_1625);
static Maybe_Prelude f_1692 (T_1674 this_1690, Int a_1629);
static TUP0 f_1696 (T_1675 this_1693, Bool a_1632, Int a_1633);
static Bool f_1699 (T_1676 this_1697, Int a_1637);
static Bool f_1705 (T_1677 this_1702, Int a_1639);
static Maybe_Prelude f_1709 (T_1677 this_1706, Int a_1641);
static Maybe_Prelude f_1713 (T_1677 this_1710, Int a_1643);
static TUP0 f_1718 (T_1677 this_1714, Bool a_1645, Int a_1646);
static TUP0 f_1723 (T_1677 this_1719,
                    Maybe_Prelude a_1648,
                    Int a_1649);
static TUP0 f_1728 (T_1677 this_1724,
                    Maybe_Prelude a_1651,
                    Int a_1652);
static Bool f_1736 (Eq_Prelude this_1733,
                    POLY a_1734,
                    POLY a_1735);
static Bool f_1740 (Eq_Prelude this_1737,
                    POLY a_1738,
                    POLY a_1739);
static Bool f_1744 (Eq_Prelude this_1741,
                    POLY a_1742,
                    POLY a_1743);
static Bool f_1748 (Eq_Prelude this_1745,
                    POLY a_1746,
                    POLY a_1747);
 
WORD __GC__ApplicationState_CTCommon[] = {WORDS(sizeof(struct ApplicationState_CTCommon)),
                                          0,
                                          0};
WORD __GC__CocoaState_CTCommon[] = {WORDS(sizeof(struct CocoaState_CTCommon)),
                                    0,
                                    0};
WORD __GC__WindowEventType_CTCommon[] = {WORDS(sizeof(struct WindowEventType_CTCommon)),
                                         0,
                                         0};
WORD __GC__Position_CTCommon[] = {WORDS(sizeof(struct Position_CTCommon)),
                                  0,
                                  0};
WORD __GC__MouseEventType_CTCommon[] = {WORDS(sizeof(struct MouseEventType_CTCommon)),
                                        0,
                                        0};
WORD __GC___MouseMoved_CTCommon[] = {WORDS(sizeof(struct _MouseMoved_CTCommon)),
                                     0,
                                     WORDS(offsetof(struct _MouseMoved_CTCommon, a)),
                                     0};
WORD __GC___MouseReleased_CTCommon[] = {WORDS(sizeof(struct _MouseReleased_CTCommon)),
                                        0,
                                        WORDS(offsetof(struct _MouseReleased_CTCommon, a)),
                                        0};
WORD __GC___MousePressed_CTCommon[] = {WORDS(sizeof(struct _MousePressed_CTCommon)),
                                       0,
                                       WORDS(offsetof(struct _MousePressed_CTCommon, a)),
                                       0};
WORD __GC___MouseClicked_CTCommon[] = {WORDS(sizeof(struct _MouseClicked_CTCommon)),
                                       0,
                                       WORDS(offsetof(struct _MouseClicked_CTCommon, a)),
                                       0};
WORD __GC__CocoaKey_CTCommon[] = {WORDS(sizeof(struct CocoaKey_CTCommon)),
                                  0,
                                  0};
WORD __GC__KeyEventType_CTCommon[] = {WORDS(sizeof(struct KeyEventType_CTCommon)),
                                      0,
                                      0};
WORD __GC___KeyReleased_CTCommon[] = {WORDS(sizeof(struct _KeyReleased_CTCommon)),
                                      0,
                                      WORDS(offsetof(struct _KeyReleased_CTCommon, a)),
                                      0};
WORD __GC___KeyPressed_CTCommon[] = {WORDS(sizeof(struct _KeyPressed_CTCommon)),
                                     0,
                                     WORDS(offsetof(struct _KeyPressed_CTCommon, a)),
                                     0};
WORD __GC__CocoaEvent_CTCommon[] = {WORDS(sizeof(struct CocoaEvent_CTCommon)),
                                    0,
                                    0};
WORD __GC___KeyEvent_CTCommon[] = {WORDS(sizeof(struct _KeyEvent_CTCommon)),
                                   0,
                                   WORDS(offsetof(struct _KeyEvent_CTCommon, a)),
                                   0};
WORD __GC___MouseEvent_CTCommon[] = {WORDS(sizeof(struct _MouseEvent_CTCommon)),
                                     0,
                                     WORDS(offsetof(struct _MouseEvent_CTCommon, a)),
                                     0};
WORD __GC___WindowEvent_CTCommon[] = {WORDS(sizeof(struct _WindowEvent_CTCommon)),
                                      0,
                                      WORDS(offsetof(struct _WindowEvent_CTCommon, a)),
                                      0};
WORD __GC__Size_CTCommon[] = {WORDS(sizeof(struct Size_CTCommon)),
                              0,
                              0};
WORD __GC__Color_CTCommon[] = {WORDS(sizeof(struct Color_CTCommon)),
                               0,
                               0};
WORD __GC__HasPosition_CTCommon[] = {WORDS(sizeof(struct HasPosition_CTCommon)),
                                     0,
                                     0};
WORD __GC__HasSize_CTCommon[] = {WORDS(sizeof(struct HasSize_CTCommon)),
                                 0,
                                 WORDS(offsetof(struct HasSize_CTCommon, l_HasSize_CTCommon_HasPosition_CTCommon_CTCommon)),
                                 0};
WORD __GC__HasBackgroundColor_CTCommon[] = {WORDS(sizeof(struct HasBackgroundColor_CTCommon)),
                                            0,
                                            0};
WORD __GC__CocoaID_CTCommon[] = {WORDS(sizeof(struct CocoaID_CTCommon)),
                                 0,
                                 0};
WORD __GC__HandlesKeyEvents_CTCommon[] = {WORDS(sizeof(struct HandlesKeyEvents_CTCommon)),
                                          0,
                                          0};
WORD __GC__HandlesMouseEvents_CTCommon[] = {WORDS(sizeof(struct HandlesMouseEvents_CTCommon)),
                                            0,
                                            0};
WORD __GC__HandlesEvents_CTCommon[] = {WORDS(sizeof(struct HandlesEvents_CTCommon)),
                                       0,
                                       0};
WORD __GC__HandlesWindowEvents_CTCommon[] = {WORDS(sizeof(struct HandlesWindowEvents_CTCommon)),
                                             0,
                                             WORDS(offsetof(struct HandlesWindowEvents_CTCommon, l_HandlesWindowEvents_CTCommon_HandlesEvents_CTCommon_CTCommon)),
                                             0};
WORD __GC__IsFocusable_CTCommon[] = {WORDS(sizeof(struct IsFocusable_CTCommon)),
                                     0,
                                     0};
WORD __GC__Component_CTCommon[] = {WORDS(sizeof(struct Component_CTCommon)),
                                   0,
                                   WORDS(offsetof(struct Component_CTCommon, l_Component_CTCommon_IsFocusable_CTCommon_CTCommon)),
                                   WORDS(offsetof(struct Component_CTCommon, l_Component_CTCommon_HasSize_CTCommon_CTCommon)),
                                   WORDS(offsetof(struct Component_CTCommon, l_Component_CTCommon_HandlesEvents_CTCommon_CTCommon)),
                                   WORDS(offsetof(struct Component_CTCommon, id_CTCommon)),
                                   0};
WORD __GC__ContainsComponents_CTCommon[] = {WORDS(sizeof(struct ContainsComponents_CTCommon)),
                                            0,
                                            0};
WORD __GC__CocoaWindow_CTCommon[] = {WORDS(sizeof(struct CocoaWindow_CTCommon)),
                                     0,
                                     WORDS(offsetof(struct CocoaWindow_CTCommon, l_CocoaWindow_CTCommon_ContainsComponents_CTCommon_CTCommon)),
                                     WORDS(offsetof(struct CocoaWindow_CTCommon, l_CocoaWindow_CTCommon_HandlesKeyEvents_CTCommon_CTCommon)),
                                     WORDS(offsetof(struct CocoaWindow_CTCommon, l_CocoaWindow_CTCommon_HandlesWindowEvents_CTCommon_CTCommon)),
                                     WORDS(offsetof(struct CocoaWindow_CTCommon, l_CocoaWindow_CTCommon_HandlesMouseEvents_CTCommon_CTCommon)),
                                     WORDS(offsetof(struct CocoaWindow_CTCommon, windowId_CTCommon)),
                                     0};
WORD __GC__App_CTCommon[] = {WORDS(sizeof(struct App_CTCommon)),
                             0,
                             0};
static WORD __GC__S_613[] = {WORDS(sizeof(struct S_613)),
                             0,
                             WORDS(offsetof(struct S_613, next_222)),
                             WORDS(offsetof(struct S_613, previous_223)),
                             0};
static WORD __GC__T_1677[] = {WORDS(sizeof(struct T_1677)),
                              0,
                              WORDS(offsetof(struct T_1677, x_1650)),
                              WORDS(offsetof(struct T_1677, x_1647)),
                              WORDS(offsetof(struct T_1677, x_1644)),
                              WORDS(offsetof(struct T_1677, x_1642)),
                              WORDS(offsetof(struct T_1677, x_1640)),
                              WORDS(offsetof(struct T_1677, x_1638)),
                              0};
static WORD __GC__T_1676[] = {WORDS(sizeof(struct T_1676)),
                              0,
                              WORDS(offsetof(struct T_1676, self_221)),
                              0};
static WORD __GC__T_1675[] = {WORDS(sizeof(struct T_1675)),
                              0,
                              WORDS(offsetof(struct T_1675, self_221)),
                              0};
static WORD __GC__T_1674[] = {WORDS(sizeof(struct T_1674)),
                              0,
                              WORDS(offsetof(struct T_1674, self_221)),
                              0};
static WORD __GC__T_1673[] = {WORDS(sizeof(struct T_1673)),
                              0,
                              WORDS(offsetof(struct T_1673, self_221)),
                              0};
HasPosition_CTCommon c_560_CTCommon (HasSize_CTCommon v_562) {
    return v_562->l_HasSize_CTCommon_HasPosition_CTCommon_CTCommon;
}
HandlesEvents_CTCommon c_563_CTCommon (HandlesWindowEvents_CTCommon v_565) {
    return v_565->l_HandlesWindowEvents_CTCommon_HandlesEvents_CTCommon_CTCommon;
}
IsFocusable_CTCommon c_566_CTCommon (Component_CTCommon v_568) {
    return v_568->l_Component_CTCommon_IsFocusable_CTCommon_CTCommon;
}
HasSize_CTCommon c_569_CTCommon (Component_CTCommon v_571) {
    return v_571->l_Component_CTCommon_HasSize_CTCommon_CTCommon;
}
HandlesEvents_CTCommon c_572_CTCommon (Component_CTCommon v_574) {
    return v_574->l_Component_CTCommon_HandlesEvents_CTCommon_CTCommon;
}
ContainsComponents_CTCommon c_575_CTCommon (CocoaWindow_CTCommon v_577) {
    return v_577->l_CocoaWindow_CTCommon_ContainsComponents_CTCommon_CTCommon;
}
HandlesKeyEvents_CTCommon c_578_CTCommon (CocoaWindow_CTCommon v_580) {
    return v_580->l_CocoaWindow_CTCommon_HandlesKeyEvents_CTCommon_CTCommon;
}
HandlesWindowEvents_CTCommon c_581_CTCommon (CocoaWindow_CTCommon v_583) {
    return v_583->l_CocoaWindow_CTCommon_HandlesWindowEvents_CTCommon_CTCommon;
}
HandlesMouseEvents_CTCommon c_584_CTCommon (CocoaWindow_CTCommon v_586) {
    return v_586->l_CocoaWindow_CTCommon_HandlesMouseEvents_CTCommon_CTCommon;
}
HasPosition_CTCommon c_588_CTCommon (Component_CTCommon a_587) {
    return a_587->l_Component_CTCommon_HasSize_CTCommon_CTCommon->l_HasSize_CTCommon_HasPosition_CTCommon_CTCommon;
}
HandlesEvents_CTCommon c_590_CTCommon (CocoaWindow_CTCommon a_589) {
    return a_589->l_CocoaWindow_CTCommon_HandlesWindowEvents_CTCommon_CTCommon->l_HandlesWindowEvents_CTCommon_HandlesEvents_CTCommon_CTCommon;
}
IsFocusable_CTCommon focusWrapper_CTCommon (Component_CTCommon this_219,
                                            Bool focusable_220,
                                            Int d_1654) {
    Ref self_221;
    NEW (Ref, self_221, WORDS(sizeof(struct Ref))+
                        WORDS(sizeof(struct S_613)));
    INITREF(self_221);
    ((S_613)STATEOF(self_221))->GCINFO = __GC__S_613;
    CLOS setNextFocusTarget_225;
    NEW (CLOS, setNextFocusTarget_225, WORDS(sizeof(struct T_1673)));
    ((T_1673)setNextFocusTarget_225)->GCINFO = __GC__T_1673;
    ((T_1673)setNextFocusTarget_225)->Code = f_1682;
    ((T_1673)setNextFocusTarget_225)->self_221 = self_221;
    CLOS getNextFocusTarget_234;
    NEW (CLOS, getNextFocusTarget_234, WORDS(sizeof(struct T_1674)));
    ((T_1674)getNextFocusTarget_234)->GCINFO = __GC__T_1674;
    ((T_1674)getNextFocusTarget_234)->Code = f_1685;
    ((T_1674)getNextFocusTarget_234)->self_221 = self_221;
    CLOS setPreviousFocusTarget_236;
    NEW (CLOS, setPreviousFocusTarget_236, WORDS(sizeof(struct T_1673)));
    ((T_1673)setPreviousFocusTarget_236)->GCINFO = __GC__T_1673;
    ((T_1673)setPreviousFocusTarget_236)->Code = f_1689;
    ((T_1673)setPreviousFocusTarget_236)->self_221 = self_221;
    CLOS getPreviousFocusTarget_239;
    NEW (CLOS, getPreviousFocusTarget_239, WORDS(sizeof(struct T_1674)));
    ((T_1674)getPreviousFocusTarget_239)->GCINFO = __GC__T_1674;
    ((T_1674)getPreviousFocusTarget_239)->Code = f_1692;
    ((T_1674)getPreviousFocusTarget_239)->self_221 = self_221;
    CLOS setIsFocusable_241;
    NEW (CLOS, setIsFocusable_241, WORDS(sizeof(struct T_1675)));
    ((T_1675)setIsFocusable_241)->GCINFO = __GC__T_1675;
    ((T_1675)setIsFocusable_241)->Code = f_1696;
    ((T_1675)setIsFocusable_241)->self_221 = self_221;
    CLOS getIsFocusable_244;
    NEW (CLOS, getIsFocusable_244, WORDS(sizeof(struct T_1676)));
    ((T_1676)getIsFocusable_244)->GCINFO = __GC__T_1676;
    ((T_1676)getIsFocusable_244)->Code = f_1699;
    ((T_1676)getIsFocusable_244)->self_221 = self_221;
    _Just_Prelude x_1700;
    NEW (_Just_Prelude, x_1700, WORDS(sizeof(struct _Just_Prelude)));
    x_1700->GCINFO = __GC___Just_Prelude+((4 * (BITS32)0));
    x_1700->a = (POLY)this_219;
    ((S_613)STATEOF(self_221))->next_222 = (Maybe_Prelude)x_1700;
    _Just_Prelude x_1701;
    NEW (_Just_Prelude, x_1701, WORDS(sizeof(struct _Just_Prelude)));
    x_1701->GCINFO = __GC___Just_Prelude+((4 * (BITS32)0));
    x_1701->a = (POLY)this_219;
    ((S_613)STATEOF(self_221))->previous_223 = (Maybe_Prelude)x_1701;
    ((S_613)STATEOF(self_221))->isFocusable_224 = focusable_220;
    CLOS x_1638;
    x_1638 = getIsFocusable_244;
    CLOS x_1640;
    x_1640 = getNextFocusTarget_234;
    CLOS x_1642;
    x_1642 = getPreviousFocusTarget_239;
    CLOS x_1644;
    x_1644 = setIsFocusable_241;
    CLOS x_1647;
    x_1647 = setNextFocusTarget_225;
    CLOS x_1650;
    x_1650 = setPreviousFocusTarget_236;
    IsFocusable_CTCommon x_1653;
    NEW (IsFocusable_CTCommon, x_1653, WORDS(sizeof(struct T_1677)));
    ((T_1677)x_1653)->GCINFO = __GC__T_1677;
    ((T_1677)x_1653)->getIsFocusable_CTCommon = f_1705;
    ((T_1677)x_1653)->getNextFocusTarget_CTCommon = f_1709;
    ((T_1677)x_1653)->getPreviousFocusTarget_CTCommon = f_1713;
    ((T_1677)x_1653)->setIsFocusable_CTCommon = f_1718;
    ((T_1677)x_1653)->setNextFocusTarget_CTCommon = f_1723;
    ((T_1677)x_1653)->setPreviousFocusTarget_CTCommon = f_1728;
    ((T_1677)x_1653)->x_1650 = x_1650;
    ((T_1677)x_1653)->x_1647 = x_1647;
    ((T_1677)x_1653)->x_1644 = x_1644;
    ((T_1677)x_1653)->x_1642 = x_1642;
    ((T_1677)x_1653)->x_1640 = x_1640;
    ((T_1677)x_1653)->x_1638 = x_1638;
    return x_1653;
}
Bool dynamicHandleEvent_CTCommon (BITS32 a_1729,
                                  POLY a_264,
                                  Maybe_Prelude a_265,
                                  Ref a_1655) {
    switch ((WORD)a_265) {
        case 1: return (Bool)0;
        default: { CLOS x_268;
                   x_268 = (CLOS)((_Just_Prelude)a_265)->a;
                   Bool x_266;
                   x_266 = ((Bool(*)(CLOS, POLY, Int))(x_268->Code))(x_268, a_264, 0);
                   return x_266;
                 }
                 break;
    }
}
Maybe_Prelude boolToMaybe_CTCommon (BITS32 a_1730,
                                    Maybe_Prelude a_269,
                                    Bool a_270) {
    switch ((WORD)a_269) {
        case 1: break;
        default: { POLY x_274;
                   x_274 = ((_Just_Prelude)a_269)->a;
                   switch ((WORD)a_270) {
                       case 1: { _Just_Prelude x_1731;
                                 NEW (_Just_Prelude, x_1731, WORDS(sizeof(struct _Just_Prelude)));
                                 x_1731->GCINFO = __GC___Just_Prelude+((4 * a_1730));
                                 x_1731->a = x_274;
                                 return (Maybe_Prelude)x_1731;
                               }
                               break;
                       case 0: break;
                   }
                 }
                 break;
    }
    switch ((WORD)a_270) {
        case 0: return (Maybe_Prelude)1;
        case 1: return (Maybe_Prelude)1;
    }
}
LIST showName_CTCommon (BITS32 a_1732,
                        Maybe_Prelude a_275,
                        Ref a_1656) {
    switch ((WORD)a_275) {
        case 1: return getStr("Nothing");
        default: { Component_CTCommon x_277;
                   x_277 = (Component_CTCommon)((_Just_Prelude)a_275)->a;
                   LIST x_276;
                   x_276 = x_277->getName_CTCommon(x_277, 0);
                   return x_276;
                 }
                 break;
    }
}
Bool _sym_257_CTCommon/* == */ (CocoaState_CTCommon a_1657,
                                CocoaState_CTCommon a_1658) {
    return compareState_CTCommon(a_1657, a_1658);
}
Bool _sym_258_CTCommon/* /= */ (CocoaState_CTCommon a_1659,
                                CocoaState_CTCommon a_1660) {
    return compareState_CTCommon(a_1659, a_1660);
}
Bool _sym_255_CTCommon/* == */ (CocoaKey_CTCommon a_1665,
                                CocoaKey_CTCommon a_1666) {
    return compareKeys_CTCommon(a_1665, a_1666);
}
Bool _sym_256_CTCommon/* /= */ (CocoaKey_CTCommon a_1667,
                                CocoaKey_CTCommon a_1668) {
    return compareKeys_CTCommon(a_1667, a_1668);
}
static Maybe_Prelude focusResult_228 (Maybe_Prelude a_259,
                                      Ref a_1618) {
    switch ((WORD)a_259) {
        case 1: return (Maybe_Prelude)1;
        default: { Component_CTCommon x_262;
                   x_262 = (Component_CTCommon)((_Just_Prelude)a_259)->a;
                   IsFocusable_CTCommon x_1749;
                   x_1749 = x_262->l_Component_CTCommon_IsFocusable_CTCommon_CTCommon;
                   Bool x_260;
                   x_260 = x_1749->getIsFocusable_CTCommon(x_1749, 0);
                   switch ((WORD)x_260) {
                       case 1: { Ref self_232;
                                 self_232 = a_1618;
                                 Maybe_Prelude x_1617;
                                 NEW (Maybe_Prelude, x_1617, WORDS(sizeof(struct _Just_Prelude)));
                                 ((_Just_Prelude)x_1617)->GCINFO = __GC___Just_Prelude+((4 * (BITS32)0));
                                 ((_Just_Prelude)x_1617)->a = (POLY)x_262;
                                 return x_1617;
                               }
                               break;
                       case 0: { Ref self_233;
                                 self_233 = a_1618;
                                 IsFocusable_CTCommon x_1750;
                                 x_1750 = x_262->l_Component_CTCommon_IsFocusable_CTCommon_CTCommon;
                                 Maybe_Prelude x_261;
                                 x_261 = x_1750->getNextFocusTarget_CTCommon(x_1750, 0);
                                 return x_261;
                               }
                               break;
                   }
                 }
                 break;
    }
}
static TUP0 f_1682 (T_1673 this_1679,
                    Maybe_Prelude a_1615,
                    Int a_1616) {
    Ref self_227;
    self_227 = (Ref)LOCK((OID)this_1679->self_221);
    ((S_613)STATEOF(self_227))->next_222 = a_1615;
    UNLOCK((OID)self_227);
    return (TUP0)0;
}
static Maybe_Prelude f_1685 (T_1674 this_1683, Int a_1621) {
    Ref self_235;
    self_235 = (Ref)LOCK((OID)this_1683->self_221);
    Maybe_Prelude x_263;
    x_263 = focusResult_228(((S_613)STATEOF(self_235))->next_222,
                            self_235);
    UNLOCK((OID)self_235);
    return x_263;
}
static TUP0 f_1689 (T_1673 this_1686,
                    Maybe_Prelude a_1624,
                    Int a_1625) {
    Ref self_238;
    self_238 = (Ref)LOCK((OID)this_1686->self_221);
    ((S_613)STATEOF(self_238))->previous_223 = a_1624;
    UNLOCK((OID)self_238);
    return (TUP0)0;
}
static Maybe_Prelude f_1692 (T_1674 this_1690, Int a_1629) {
    Ref self_240;
    self_240 = (Ref)LOCK((OID)this_1690->self_221);
    Maybe_Prelude x_1626;
    x_1626 = ((S_613)STATEOF(self_240))->previous_223;
    UNLOCK((OID)self_240);
    return x_1626;
}
static TUP0 f_1696 (T_1675 this_1693, Bool a_1632, Int a_1633) {
    Ref self_243;
    self_243 = (Ref)LOCK((OID)this_1693->self_221);
    ((S_613)STATEOF(self_243))->isFocusable_224 = a_1632;
    UNLOCK((OID)self_243);
    return (TUP0)0;
}
static Bool f_1699 (T_1676 this_1697, Int a_1637) {
    Ref self_245;
    self_245 = (Ref)LOCK((OID)this_1697->self_221);
    Bool x_1634;
    x_1634 = ((S_613)STATEOF(self_245))->isFocusable_224;
    UNLOCK((OID)self_245);
    return x_1634;
}
static Bool f_1705 (T_1677 this_1702, Int a_1639) {
    CLOS x_1704;
    x_1704 = this_1702->x_1638;
    return ((Bool(*)(CLOS, Int))(x_1704->Code))(x_1704, a_1639);
}
static Maybe_Prelude f_1709 (T_1677 this_1706, Int a_1641) {
    CLOS x_1708;
    x_1708 = this_1706->x_1640;
    return ((Maybe_Prelude(*)(CLOS, Int))(x_1708->Code))(x_1708,
                                                         a_1641);
}
static Maybe_Prelude f_1713 (T_1677 this_1710, Int a_1643) {
    CLOS x_1712;
    x_1712 = this_1710->x_1642;
    return ((Maybe_Prelude(*)(CLOS, Int))(x_1712->Code))(x_1712,
                                                         a_1643);
}
static TUP0 f_1718 (T_1677 this_1714, Bool a_1645, Int a_1646) {
    CLOS x_1717;
    x_1717 = this_1714->x_1644;
    return ((TUP0(*)(CLOS, Bool, Int))(x_1717->Code))(x_1717,
                                                      a_1645,
                                                      a_1646);
}
static TUP0 f_1723 (T_1677 this_1719,
                    Maybe_Prelude a_1648,
                    Int a_1649) {
    CLOS x_1722;
    x_1722 = this_1719->x_1647;
    return ((TUP0(*)(CLOS, Maybe_Prelude, Int))(x_1722->Code))(x_1722,
                                                               a_1648,
                                                               a_1649);
}
static TUP0 f_1728 (T_1677 this_1724,
                    Maybe_Prelude a_1651,
                    Int a_1652) {
    CLOS x_1727;
    x_1727 = this_1724->x_1650;
    return ((TUP0(*)(CLOS, Maybe_Prelude, Int))(x_1727->Code))(x_1727,
                                                               a_1651,
                                                               a_1652);
}
static Bool f_1736 (Eq_Prelude this_1733,
                    POLY a_1734,
                    POLY a_1735) {
    CocoaState_CTCommon a_1661;
    CocoaState_CTCommon a_1662;
    a_1661 = (CocoaState_CTCommon)a_1734;
    a_1662 = (CocoaState_CTCommon)a_1735;
    return compareState_CTCommon(a_1661, a_1662);
}
static Bool f_1740 (Eq_Prelude this_1737,
                    POLY a_1738,
                    POLY a_1739) {
    CocoaState_CTCommon a_1663;
    CocoaState_CTCommon a_1664;
    a_1663 = (CocoaState_CTCommon)a_1738;
    a_1664 = (CocoaState_CTCommon)a_1739;
    return compareState_CTCommon(a_1663, a_1664);
}
static Bool f_1744 (Eq_Prelude this_1741,
                    POLY a_1742,
                    POLY a_1743) {
    CocoaKey_CTCommon a_1669;
    CocoaKey_CTCommon a_1670;
    a_1669 = (CocoaKey_CTCommon)a_1742;
    a_1670 = (CocoaKey_CTCommon)a_1743;
    return compareKeys_CTCommon(a_1669, a_1670);
}
static Bool f_1748 (Eq_Prelude this_1745,
                    POLY a_1746,
                    POLY a_1747) {
    CocoaKey_CTCommon a_1671;
    CocoaKey_CTCommon a_1672;
    a_1671 = (CocoaKey_CTCommon)a_1746;
    a_1672 = (CocoaKey_CTCommon)a_1747;
    return compareKeys_CTCommon(a_1671, a_1672);
}
 
void _init_CTCommon () {
    static int INITIALIZED = 0;
    if (!INITIALIZED) {
        _init_Prelude();
        _init_POSIX();
        NEW (Eq_Prelude, eqCocoaState_CTCommon, WORDS(sizeof(struct Eq_Prelude)));
        eqCocoaState_CTCommon->GCINFO = __GC__Eq_Prelude;
        eqCocoaState_CTCommon->_sym_159_Prelude/* == */ = f_1736;
        eqCocoaState_CTCommon->_sym_160_Prelude/* /= */ = f_1740;
        NEW (Eq_Prelude, eqCocoaKey_CTCommon, WORDS(sizeof(struct Eq_Prelude)));
        eqCocoaKey_CTCommon->GCINFO = __GC__Eq_Prelude;
        eqCocoaKey_CTCommon->_sym_159_Prelude/* == */ = f_1744;
        eqCocoaKey_CTCommon->_sym_160_Prelude/* /= */ = f_1748;
        INITIALIZED = 1;
    }
}
 

