function c_391_CTLabel (v_393) {
    return v_393
}
function c_394_CTLabel (v_396) {
    return v_396
}
function c_398_CTLabel (a_397) {
    return a_397
}
function c_400_CTLabel (a_399) {
    return a_399
}
function c_402_CTLabel (a_401) {
    return a_401
}
function c_404_CTLabel (a_403) {
    return a_403
}
function mkCocoaLabel_CTLabel (d_1831) {
    var self_12 = { LOCKED: false }
    var id_20 = mkCocoaID_CTCommon(0)
    var destroy_21 = function (a_1680) {
                         var self_22 = LOCK(self_12)
                         self_22.myState = 'destroyed'
                         UNLOCK(self_22)
                     }
    var getName_23 = function (a_1684) {
                         var self_24 = LOCK(self_12)
                         var x_1681 = self_24.name
                         UNLOCK(self_24)
                         return x_1681
                     }
    var getPosition_25 = function (a_1688) {
                             var self_26 = LOCK(self_12)
                             var x_1685 = self_26.position
                             UNLOCK(self_26)
                             return x_1685
                         }
    var getSize_27 = function (a_1692) {
                         var self_28 = LOCK(self_12)
                         var x_1689 = self_28.size
                         UNLOCK(self_28)
                         return x_1689
                     }
    var getText_29 = function (a_1696) {
                         var self_30 = LOCK(self_12)
                         var x_1693 = self_30.text
                         UNLOCK(self_30)
                         return x_1693
                     }
    var getTextColor_31 = function (a_1700) {
                              var self_32 = LOCK(self_12)
                              var x_1697 = self_32.textColor
                              UNLOCK(self_32)
                              return x_1697
                          }
    function inithelper_33 (self_34) {
        var d_76 = labelSetText_CTLabel(id_20,
                                        self_34.text,
                                        Inherit,
                                        Inherit)
        var d_77 = labelSetPosition_CTLabel(id_20,
                                            self_34.position,
                                            Inherit,
                                            Inherit)
        var d_78 = labelSetSize_CTLabel(id_20,
                                        self_34.size,
                                        Inherit,
                                        Inherit)
        var d_79 = labelSetTextColor_CTLabel(id_20,
                                             self_34.textColor,
                                             Inherit,
                                             Inherit)
    }
    var installMouseListener_35 = function (a_1705, a_1706) {
                                      var self_37 = LOCK(self_12)
                                      self_37.mouseEventHandler = {   tagName : 'just',
                                                                      a : a_1705
                                                                  }
                                      UNLOCK(self_37)
                                  }
    var setName_38 = function (a_1711, a_1712) {
                         var self_40 = LOCK(self_12)
                         self_40.name = a_1711
                         UNLOCK(self_40)
                     }
    var setPosition_41 = function (a_1718, a_1719, a_1720) {
                             var x_1717 = function () {
                                              var self_43 = LOCK(self_12)
                                              switch (self_43.myState) {
                                                case 'active': {
                                                  var d_81 = labelSetPosition_CTLabel(id_20,
                                                                                      a_1718,
                                                                                      Inherit,
                                                                                      Inherit)
                                                  break
                                                  break
                                                }
                                                default: break
                                              }
                                              self_43.position = a_1718
                                              UNLOCK(self_43)
                                          }
                             return ASYNC(x_1717, a_1719, a_1720)
                         }
    var setSize_46 = function (a_1726, a_1727, a_1728) {
                         var x_1725 = function () {
                                          var self_48 = LOCK(self_12)
                                          self_48.size = a_1726
                                          UNLOCK(self_48)
                                      }
                         return ASYNC(x_1725, a_1727, a_1728)
                     }
    var setText_49 = function (a_1734, a_1735, a_1736) {
                         var x_1733 = function () {
                                          var self_51 = LOCK(self_12)
                                          self_51.text = a_1734
                                          switch (self_51.myState) {
                                            case 'active': {
                                              var self_52 = self_51
                                              var d_83 = labelSetText_CTLabel(id_20,
                                                                              a_1734,
                                                                              Inherit,
                                                                              Inherit)
                                              UNLOCK(self_51)
                                              break
                                            }
                                            default: var self_53 = self_51
                                                     UNLOCK(self_51)
                                          }
                                      }
                         return ASYNC(x_1733, a_1735, a_1736)
                     }
    var setTextColor_54 = function (a_1742, a_1743, a_1744) {
                              var x_1741 = function () {
                                               var self_56 = LOCK(self_12)
                                               switch (self_56.myState) {
                                                 case 'active': {
                                                   var d_86 = labelSetTextColor_CTLabel(id_20,
                                                                                        a_1742,
                                                                                        Inherit,
                                                                                        Inherit)
                                                   break
                                                   break
                                                 }
                                                 default: break
                                               }
                                               self_56.textColor = a_1742
                                               UNLOCK(self_56)
                                           }
                              return ASYNC(x_1741, a_1743, a_1744)
                          }
    var x_1790 = getPosition_25
    var x_1792 = setPosition_41
    var x_1796 = getSize_27
    var x_1798 = setSize_46
    var x_1806 = destroy_21
    var x_1808 = getName_23
    var x_1813 = setName_38
    var x_1816 = installMouseListener_35
    var x_1819 = getText_29
    var x_1821 = getTextColor_31
    var x_1823 = setText_49
    var x_1827 = setTextColor_54
    var this_68 = {}
    var x_1426 = {}
    var focus_59 = focusWrapper_CTCommon(x_1426, false, 0)
    var setNextFocusTarget_60 = function (a_1747,
                                          a_1748) { return focus_59.setNextFocusTarget(a_1747,
                                                                                       a_1748) }
    var getNextFocusTarget_61 = function (a_1750) { return focus_59.getNextFocusTarget(a_1750) }
    var setPreviousFocusTarget_62 = function (a_1753,
                                              a_1754) { return focus_59.setPreviousFocusTarget(a_1753,
                                                                                               a_1754) }
    var getPreviousFocusTarget_63 = function (a_1756) { return focus_59.getPreviousFocusTarget(a_1756) }
    var setIsFocusable_64 = function (a_1759,
                                      a_1760) { return focus_59.setIsFocusable(a_1759, a_1760) }
    var getIsFocusable_65 = function (a_1762) { return focus_59.getIsFocusable(a_1762) }
    var handleEvent_66 = function (a_1768, a_1769, a_1770) {
                             switch (a_1768.tagName) {
                               case 'mouseevent': {
                                 var x_92 = a_1768.a
                                 var self_71 = LOCK(self_12)
                                 var x_90 = dynamicHandleEvent_CTCommon(x_92,
                                                                        self_71.mouseEventHandler,
                                                                        self_71)
                                 var x_1763 = boolToMaybe_CTCommon({   tagName : 'just',
                                                                       a : this_68
                                                                   },
                                                                   x_90)
                                 UNLOCK(self_71)
                                 return x_1763
                                 break
                               }
                               default: {
                                 var self_73 = LOCK(self_12)
                                 UNLOCK(self_73)
                                 return 'nothing'
                               }
                             }
                         }
    var init_67 = function (a_1773, a_1774) {
                      var self_75 = LOCK(self_12)
                      self_75.myState = 'active'
                      var d_93 = initLabel_CTLabel(this_68, a_1773, 0)
                      var d_94 = inithelper_33(self_75)
                      UNLOCK(self_75)
                  }
    var x_1775 = getIsFocusable_65
    var x_1777 = getNextFocusTarget_61
    var x_1779 = getPreviousFocusTarget_63
    var x_1781 = setIsFocusable_64
    var x_1784 = setNextFocusTarget_60
    var x_1787 = setPreviousFocusTarget_62
    var x_1802 = handleEvent_66
    var x_1810 = init_67
    this_68 = UPDATE(this_68, {   tagName : 'label',
                                  getIsFocusable : function (a_1776) {
                                      return x_1775(a_1776)
                                  },
                                  getNextFocusTarget : function (a_1778) {
                                      return x_1777(a_1778)
                                  },
                                  getPreviousFocusTarget : function (a_1780) {
                                      return x_1779(a_1780)
                                  },
                                  setIsFocusable : function (a_1782, a_1783) {
                                      return x_1781(a_1782, a_1783)
                                  },
                                  setNextFocusTarget : function (a_1785, a_1786) {
                                      return x_1784(a_1785, a_1786)
                                  },
                                  setPreviousFocusTarget : function (a_1788, a_1789) {
                                      return x_1787(a_1788, a_1789)
                                  },
                                  getPosition : function (a_1791) {
                                      return x_1790(a_1791)
                                  },
                                  setPosition : function (a_1793, a_1794, a_1795) {
                                      return x_1792(a_1793, a_1794, a_1795)
                                  },
                                  getSize : function (a_1797) {
                                      return x_1796(a_1797)
                                  },
                                  setSize : function (a_1799, a_1800, a_1801) {
                                      return x_1798(a_1799, a_1800, a_1801)
                                  },
                                  handleEvent : function (a_1803, a_1804, a_1805) {
                                      return x_1802(a_1803, a_1804, a_1805)
                                  },
                                  destroy : function (a_1807) {
                                      return x_1806(a_1807)
                                  },
                                  getName : function (a_1809) {
                                      return x_1808(a_1809)
                                  },
                                  id : id_20,
                                  init : function (a_1811, a_1812) {
                                      return x_1810(a_1811, a_1812)
                                  },
                                  setName : function (a_1814, a_1815) {
                                      return x_1813(a_1814, a_1815)
                                  },
                                  installMouseListener : function (a_1817, a_1818) {
                                      return x_1816(a_1817, a_1818)
                                  },
                                  getText : function (a_1820) {
                                      return x_1819(a_1820)
                                  },
                                  getTextColor : function (a_1822) {
                                      return x_1821(a_1822)
                                  },
                                  setText : function (a_1824, a_1825, a_1826) {
                                      return x_1823(a_1824, a_1825, a_1826)
                                  },
                                  setTextColor : function (a_1828, a_1829, a_1830) {
                                      return x_1827(a_1828, a_1829, a_1830)
                                  }
                              })
    x_1426 = UPDATE(x_1426, this_68)
    self_12.myState = 'inactive'
    self_12.position = {   tagName : 'position',
                           x : 0,
                           y : 0
                       }
    self_12.size = {   tagName : 'size',
                       width : 0,
                       height : 0
                   }
    self_12.mouseEventHandler = 'nothing'
    self_12.textColor = {   tagName : 'color',
                            r : 0,
                            g : 0,
                            b : 0
                        }
    self_12.text = "Default Label"
    self_12.name = "label"
    return this_68
}