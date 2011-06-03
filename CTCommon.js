function c_560_CTCommon (v_562) {
    return v_562
}
function c_563_CTCommon (v_565) {
    return v_565
}
function c_566_CTCommon (v_568) {
    return v_568
}
function c_569_CTCommon (v_571) {
    return v_571
}
function c_572_CTCommon (v_574) {
    return v_574
}
function c_575_CTCommon (v_577) {
    return v_577
}
function c_578_CTCommon (v_580) {
    return v_580
}
function c_581_CTCommon (v_583) {
    return v_583
}
function c_584_CTCommon (v_586) {
    return v_586
}
function c_588_CTCommon (a_587) {
    return a_587
}
function c_590_CTCommon (a_589) {
    return a_589
}
function focusWrapper_CTCommon (this_219, focusable_220, d_1654) {
    var self_221 = { LOCKED: false }
    var setNextFocusTarget_225 = function (a_1615, a_1616) {
                                     var self_227 = LOCK(self_221)
                                     self_227.next = a_1615
                                     UNLOCK(self_227)
                                 }
    function focusResult_228 (a_259, a_1618) {
        switch (a_259) {
          case 'nothing': {
            return 'nothing'
            break
          }
          default: var x_262 = a_259.a
                   var x_260 = x_262.getIsFocusable(0)
                   if (x_260) {
                       var self_232 = a_1618
                       var x_1617 = {   tagName : 'just',
                                        a : x_262
                                    }
                       return x_1617
                   } else {
                       var self_233 = a_1618
                       var x_261 = x_262.getNextFocusTarget(0)
                       return x_261
                   }
        }
    }
    var getNextFocusTarget_234 = function (a_1621) {
                                     var self_235 = LOCK(self_221)
                                     var x_263 = focusResult_228(self_235.next, self_235)
                                     UNLOCK(self_235)
                                     return x_263
                                 }
    var setPreviousFocusTarget_236 = function (a_1624, a_1625) {
                                         var self_238 = LOCK(self_221)
                                         self_238.previous = a_1624
                                         UNLOCK(self_238)
                                     }
    var getPreviousFocusTarget_239 = function (a_1629) {
                                         var self_240 = LOCK(self_221)
                                         var x_1626 = self_240.previous
                                         UNLOCK(self_240)
                                         return x_1626
                                     }
    var setIsFocusable_241 = function (a_1632, a_1633) {
                                 var self_243 = LOCK(self_221)
                                 self_243.isFocusable = a_1632
                                 UNLOCK(self_243)
                             }
    var getIsFocusable_244 = function (a_1637) {
                                 var self_245 = LOCK(self_221)
                                 var x_1634 = self_245.isFocusable
                                 UNLOCK(self_245)
                                 return x_1634
                             }
    self_221.next = {   tagName : 'just',
                        a : this_219
                    }
    self_221.previous = {   tagName : 'just',
                            a : this_219
                        }
    self_221.isFocusable = focusable_220
    var x_1638 = getIsFocusable_244
    var x_1640 = getNextFocusTarget_234
    var x_1642 = getPreviousFocusTarget_239
    var x_1644 = setIsFocusable_241
    var x_1647 = setNextFocusTarget_225
    var x_1650 = setPreviousFocusTarget_236
    var x_1653 = {   tagName : 'isfocusable',
                     getIsFocusable : function (a_1639) {
                         return x_1638(a_1639)
                     },
                     getNextFocusTarget : function (a_1641) {
                         return x_1640(a_1641)
                     },
                     getPreviousFocusTarget : function (a_1643) {
                         return x_1642(a_1643)
                     },
                     setIsFocusable : function (a_1645, a_1646) {
                         return x_1644(a_1645, a_1646)
                     },
                     setNextFocusTarget : function (a_1648, a_1649) {
                         return x_1647(a_1648, a_1649)
                     },
                     setPreviousFocusTarget : function (a_1651, a_1652) {
                         return x_1650(a_1651, a_1652)
                     }
                 }
    return x_1653
}
function dynamicHandleEvent_CTCommon (a_264, a_265, a_1655) {
    switch (a_265) {
      case 'nothing': {
        return false
        break
      }
      default: var x_268 = a_265.a
               var x_266 = x_268(a_264, 0)
               return x_266
    }
}
function boolToMaybe_CTCommon (a_269, a_270) {
    switch (a_269.tagName) {
      case 'just': {
        var x_274 = a_269.a
        if (a_270) {
            return {   tagName : 'just',
                       a : x_274
                   }
        }
        break
      }
    }
    if (a_270) {
        return 'nothing'
    } else {
        return 'nothing'
    }
}
function showName_CTCommon (a_275, a_1656) {
    switch (a_275) {
      case 'nothing': {
        return "Nothing"
        break
      }
      default: var x_277 = a_275.a
               var x_276 = x_277.getName(0)
               return x_276
    }
}
function _sym_257_CTCommon/* == */ (a_1657, a_1658) {
    return compareState_CTCommon(a_1657, a_1658)
}
function _sym_258_CTCommon/* /= */ (a_1659, a_1660) {
    return compareState_CTCommon(a_1659, a_1660)
}
var eqCocoaState_CTCommon = {   tagName : 'eq',
                                _sym_159_Prelude/* == */ : function (a_1661, a_1662) {
                                    return compareState_CTCommon(a_1661, a_1662)
                                },
                                _sym_160_Prelude/* /= */ : function (a_1663, a_1664) {
                                    return compareState_CTCommon(a_1663, a_1664)
                                }
                            }
function _sym_255_CTCommon/* == */ (a_1665, a_1666) {
    return compareKeys_CTCommon(a_1665, a_1666)
}
function _sym_256_CTCommon/* /= */ (a_1667, a_1668) {
    return compareKeys_CTCommon(a_1667, a_1668)
}
var eqCocoaKey_CTCommon = {   tagName : 'eq',
                              _sym_159_Prelude/* == */ : function (a_1669, a_1670) {
                                  return compareKeys_CTCommon(a_1669, a_1670)
                              },
                              _sym_160_Prelude/* /= */ : function (a_1671, a_1672) {
                                  return compareKeys_CTCommon(a_1671, a_1672)
                              }
                          }