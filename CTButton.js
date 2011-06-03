function c_418_CTButton (v_420) {
    return v_420
}
function c_421_CTButton (v_423) {
    return v_423
}
function c_424_CTButton (v_426) {
    return v_426
}
function c_428_CTButton (a_427) {
    return a_427
}
function c_430_CTButton (a_429) {
    return a_429
}
function c_432_CTButton (a_431) {
    return a_431
}
function c_434_CTButton (a_433) {
    return a_433
}
function mkCocoaButton_CTButton (env_8, d_2214) {
    var self_9 = { LOCKED: false }
    var id_17 = mkCocoaID_CTCommon(0)
    var setTitle_18 = function (a_2069, a_2070, a_2071) {
                          var x_2068 = function () {
                                           var self_20 = LOCK(self_9)
                                           self_20.title = a_2069
                                           switch (self_20.myState) {
                                             case 'active': {
                                               var self_21 = self_20
                                               var d_81 = buttonSetTitle_CTButton(id_17,
                                                                                  a_2069,
                                                                                  Inherit,
                                                                                  Inherit)
                                               UNLOCK(self_20)
                                               break
                                             }
                                             default: var self_22 = self_20
                                                      UNLOCK(self_20)
                                           }
                                       }
                          return ASYNC(x_2068, a_2070, a_2071)
                      }
    var getTitle_23 = function (a_2075) {
                          var self_24 = LOCK(self_9)
                          var x_2072 = self_24.title
                          UNLOCK(self_24)
                          return x_2072
                      }
    var setPosition_25 = function (a_2081, a_2082, a_2083) {
                             var x_2080 = function () {
                                              var self_27 = LOCK(self_9)
                                              switch (self_27.myState) {
                                                case 'active': {
                                                  var d_84 = buttonSetPosition_CTButton(id_17,
                                                                                        a_2081,
                                                                                        Inherit,
                                                                                        Inherit)
                                                  break
                                                  break
                                                }
                                                default: break
                                              }
                                              self_27.position = a_2081
                                              UNLOCK(self_27)
                                          }
                             return ASYNC(x_2080, a_2082, a_2083)
                         }
    var getPosition_30 = function (a_2087) {
                             var self_31 = LOCK(self_9)
                             var x_2084 = self_31.position
                             UNLOCK(self_31)
                             return x_2084
                         }
    var setSize_32 = function (a_2093, a_2094, a_2095) {
                         var x_2092 = function () {
                                          var self_34 = LOCK(self_9)
                                          self_34.size = a_2093
                                          UNLOCK(self_34)
                                      }
                         return ASYNC(x_2092, a_2094, a_2095)
                     }
    var getSize_35 = function (a_2099) {
                         var self_36 = LOCK(self_9)
                         var x_2096 = self_36.size
                         UNLOCK(self_36)
                         return x_2096
                     }
    var destroy_37 = function (a_2102) {
                         var self_38 = LOCK(self_9)
                         self_38.myState = 'destroyed'
                         UNLOCK(self_38)
                     }
    var getName_39 = function (a_2106) {
                         var self_40 = LOCK(self_9)
                         var x_2103 = self_40.name
                         UNLOCK(self_40)
                         return x_2103
                     }
    function inithelper_41 (self_42) {
        var d_86 = buttonSetTitle_CTButton(id_17,
                                           self_42.title,
                                           Inherit,
                                           Inherit)
        var d_87 = buttonSetPosition_CTButton(id_17,
                                              self_42.position,
                                              Inherit,
                                              Inherit)
    }
    var installKeyListener_43 = function (a_2111, a_2112) {
                                    var self_45 = LOCK(self_9)
                                    self_45.keyEventHandler = {   tagName : 'just',
                                                                  a : a_2111
                                                              }
                                    UNLOCK(self_45)
                                }
    var installMouseListener_46 = function (a_2119, a_2120) {
                                      var self_48 = LOCK(self_9)
                                      self_48.mouseEventHandler = {   tagName : 'just',
                                                                      a : a_2119
                                                                  }
                                      UNLOCK(self_48)
                                  }
    var setName_49 = function (a_2125, a_2126) {
                         var self_51 = LOCK(self_9)
                         self_51.name = a_2125
                         UNLOCK(self_51)
                     }
    var x_2176 = getPosition_30
    var x_2178 = setPosition_25
    var x_2182 = getSize_35
    var x_2184 = setSize_32
    var x_2192 = destroy_37
    var x_2194 = getName_39
    var x_2199 = setName_49
    var x_2202 = installMouseListener_46
    var x_2205 = installKeyListener_43
    var x_2208 = getTitle_23
    var x_2210 = setTitle_18
    var this_61 = {}
    var x_1738 = {}
    var focus_52 = focusWrapper_CTCommon(x_1738, true, 0)
    var setNextFocusTarget_53 = function (a_2129, a_2130) {
                                    var self_63 = LOCK(self_9)
                                    if (isJust_Prelude(a_2129)) {
                                        var x_90 = showName_CTCommon(a_2129, self_63)
                                        var d_89 = env_8.stdout.write(_sym_20_Prelude/* ++ */(self_63.name,
                                                                                              _sym_20_Prelude/* ++ */(" is changing focus to ",
                                                                                                                      x_90)),
                                                                      0)
                                        break
                                    } else {
                                        var d_91 = env_8.stdout.write(_sym_20_Prelude/* ++ */(self_63.name,
                                                                                              " is changing focus to NOTHING\n"),
                                                                      0)
                                        break
                                    }
                                    var res_66 = focus_52.setNextFocusTarget(a_2129, 0)
                                    UNLOCK(self_63)
                                }
    var getNextFocusTarget_54 = function (a_2133) {
                                    var self_67 = LOCK(self_9)
                                    var res_68 = focus_52.getNextFocusTarget(0)
                                    if (isJust_Prelude(res_68)) {
                                        var d_93 = env_8.stdout.write(_sym_20_Prelude/* ++ */(self_67.name,
                                                                                              " is asked for getNextFocusTarget, returning TRUE\n"),
                                                                      0)
                                        break
                                    } else {
                                        var d_94 = env_8.stdout.write(_sym_20_Prelude/* ++ */(self_67.name,
                                                                                              " is asked for getNextFocusTarget, returing FALSE\n"),
                                                                      0)
                                        break
                                    }
                                    UNLOCK(self_67)
                                    return res_68
                                }
    var setPreviousFocusTarget_55 = function (a_2136,
                                              a_2137) { return focus_52.setPreviousFocusTarget(a_2136,
                                                                                               a_2137) }
    var getPreviousFocusTarget_56 = function (a_2139) { return focus_52.getPreviousFocusTarget(a_2139) }
    var setIsFocusable_57 = function (a_2142,
                                      a_2143) { return focus_52.setIsFocusable(a_2142, a_2143) }
    var getIsFocusable_58 = function (a_2145) { return focus_52.getIsFocusable(a_2145) }
    var handleEvent_59 = function (a_2154, a_2155, a_2156) {
                             switch (a_2154.tagName) {
                               case 'keyevent': {
                                 var x_100 = a_2154.a
                                 var self_73 = LOCK(self_9)
                                 var x_97 = dynamicHandleEvent_CTCommon(x_100,
                                                                        self_73.keyEventHandler,
                                                                        self_73)
                                 var x_2146 = boolToMaybe_CTCommon({   tagName : 'just',
                                                                       a : this_61
                                                                   },
                                                                   x_97)
                                 UNLOCK(self_73)
                                 return x_2146
                                 break
                               }
                               case 'mouseevent': {
                                 var x_101 = a_2154.a
                                 var self_76 = LOCK(self_9)
                                 var x_98 = dynamicHandleEvent_CTCommon(x_101,
                                                                        self_76.mouseEventHandler,
                                                                        self_76)
                                 var x_2149 = boolToMaybe_CTCommon({   tagName : 'just',
                                                                       a : this_61
                                                                   },
                                                                   x_98)
                                 UNLOCK(self_76)
                                 return x_2149
                                 break
                               }
                               default: {
                                 var self_78 = LOCK(self_9)
                                 UNLOCK(self_78)
                                 return 'nothing'
                               }
                             }
                         }
    var init_60 = function (a_2159, a_2160) {
                      var self_80 = LOCK(self_9)
                      self_80.myState = 'active'
                      var d_102 = initButton_CTButton(this_61, a_2159, 0)
                      var d_103 = inithelper_41(self_80)
                      UNLOCK(self_80)
                  }
    var x_2161 = getIsFocusable_58
    var x_2163 = getNextFocusTarget_54
    var x_2165 = getPreviousFocusTarget_56
    var x_2167 = setIsFocusable_57
    var x_2170 = setNextFocusTarget_53
    var x_2173 = setPreviousFocusTarget_55
    var x_2188 = handleEvent_59
    var x_2196 = init_60
    this_61 = UPDATE(this_61, {   tagName : 'button',
                                  getIsFocusable : function (a_2162) {
                                      return x_2161(a_2162)
                                  },
                                  getNextFocusTarget : function (a_2164) {
                                      return x_2163(a_2164)
                                  },
                                  getPreviousFocusTarget : function (a_2166) {
                                      return x_2165(a_2166)
                                  },
                                  setIsFocusable : function (a_2168, a_2169) {
                                      return x_2167(a_2168, a_2169)
                                  },
                                  setNextFocusTarget : function (a_2171, a_2172) {
                                      return x_2170(a_2171, a_2172)
                                  },
                                  setPreviousFocusTarget : function (a_2174, a_2175) {
                                      return x_2173(a_2174, a_2175)
                                  },
                                  getPosition : function (a_2177) {
                                      return x_2176(a_2177)
                                  },
                                  setPosition : function (a_2179, a_2180, a_2181) {
                                      return x_2178(a_2179, a_2180, a_2181)
                                  },
                                  getSize : function (a_2183) {
                                      return x_2182(a_2183)
                                  },
                                  setSize : function (a_2185, a_2186, a_2187) {
                                      return x_2184(a_2185, a_2186, a_2187)
                                  },
                                  handleEvent : function (a_2189, a_2190, a_2191) {
                                      return x_2188(a_2189, a_2190, a_2191)
                                  },
                                  destroy : function (a_2193) {
                                      return x_2192(a_2193)
                                  },
                                  getName : function (a_2195) {
                                      return x_2194(a_2195)
                                  },
                                  id : id_17,
                                  init : function (a_2197, a_2198) {
                                      return x_2196(a_2197, a_2198)
                                  },
                                  setName : function (a_2200, a_2201) {
                                      return x_2199(a_2200, a_2201)
                                  },
                                  installMouseListener : function (a_2203, a_2204) {
                                      return x_2202(a_2203, a_2204)
                                  },
                                  installKeyListener : function (a_2206, a_2207) {
                                      return x_2205(a_2206, a_2207)
                                  },
                                  getTitle : function (a_2209) {
                                      return x_2208(a_2209)
                                  },
                                  setTitle : function (a_2211, a_2212, a_2213) {
                                      return x_2210(a_2211, a_2212, a_2213)
                                  }
                              })
    x_1738 = UPDATE(x_1738, this_61)
    self_9.myState = 'inactive'
    self_9.position = {   tagName : 'position',
                          x : 0,
                          y : 0
                      }
    self_9.size = {   tagName : 'size',
                      width : 108,
                      height : 17
                  }
    self_9.mouseEventHandler = 'nothing'
    self_9.keyEventHandler = 'nothing'
    self_9.title = "TestButton"
    self_9.name = "button"
    return this_61
}