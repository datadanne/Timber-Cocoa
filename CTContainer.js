function c_668_CTContainer (v_670) {
    return v_670
}
function c_671_CTContainer (v_673) {
    return v_673
}
function c_674_CTContainer (v_676) {
    return v_676
}
function c_677_CTContainer (v_679) {
    return v_679
}
function c_680_CTContainer (v_682) {
    return v_682
}
function c_684_CTContainer (a_683) {
    return a_683
}
function c_686_CTContainer (a_685) {
    return a_685
}
function c_688_CTContainer (a_687) {
    return a_687
}
function c_690_CTContainer (a_689) {
    return a_689
}
function inInterval_CTContainer (v_795,
                                 v_797,
                                 x_123,
                                 startPos_124,
                                 width_125) {
    return v_795._sym_158_Prelude/* >= */(x_123,
                                          startPos_124) && v_795._sym_156_Prelude/* <= */(x_123,
                                                                                          v_797._sym_161_Prelude/* + */(startPos_124,
                                                                                                                        width_125))
}
function mkContainer_CTContainer (e_9, d_4221) {
    var self_10 = { LOCKED: false }
    var id_22 = mkCocoaID_CTCommon(0)
    var setPosition_23 = function (a_4053, a_4054, a_4055) {
                             var x_4052 = function () {
                                              var self_25 = LOCK(self_10)
                                              switch (self_25.myState) {
                                                case 'active': {
                                                  var d_127 = containerSetPosition_CTContainer(id_22,
                                                                                               a_4053,
                                                                                               Inherit,
                                                                                               Inherit)
                                                  break
                                                  break
                                                }
                                                default: break
                                              }
                                              self_25.position = a_4053
                                              UNLOCK(self_25)
                                          }
                             return ASYNC(x_4052, a_4054, a_4055)
                         }
    var getPosition_28 = function (a_4059) {
                             var self_29 = LOCK(self_10)
                             var x_4056 = self_29.position
                             UNLOCK(self_29)
                             return x_4056
                         }
    var setSize_30 = function (a_4065, a_4066, a_4067) {
                         var x_4064 = function () {
                                          var self_32 = LOCK(self_10)
                                          switch (self_32.myState) {
                                            case 'active': {
                                              var d_130 = containerSetSize_CTContainer(id_22,
                                                                                       a_4065,
                                                                                       Inherit,
                                                                                       Inherit)
                                              break
                                              break
                                            }
                                            default: break
                                          }
                                          self_32.size = a_4065
                                          UNLOCK(self_32)
                                      }
                         return ASYNC(x_4064, a_4066, a_4067)
                     }
    var getSize_35 = function (a_4071) {
                         var self_36 = LOCK(self_10)
                         var x_4068 = self_36.size
                         UNLOCK(self_36)
                         return x_4068
                     }
    var setBackgroundColor_37 = function (a_4077, a_4078, a_4079) {
                                    var x_4076 = function () {
                                                     var self_39 = LOCK(self_10)
                                                     switch (self_39.myState) {
                                                       case 'active': {
                                                         var d_133 = containerSetBackgroundColor_CTContainer(id_22,
                                                                                                             a_4077,
                                                                                                             Inherit,
                                                                                                             Inherit)
                                                         break
                                                         break
                                                       }
                                                       default: break
                                                     }
                                                     self_39.color = a_4077
                                                     UNLOCK(self_39)
                                                 }
                                    return ASYNC(x_4076, a_4078, a_4079)
                                }
    var getBackgroundColor_42 = function (a_4083) {
                                    var self_43 = LOCK(self_10)
                                    var x_4080 = self_43.color
                                    UNLOCK(self_43)
                                    return x_4080
                                }
    var destroy_44 = function (a_4086) {
                         var self_45 = LOCK(self_10)
                         self_45.myState = 'destroyed'
                         UNLOCK(self_45)
                     }
    var getComponents_46 = function (a_4090) {
                               var self_47 = LOCK(self_10)
                               var x_4087 = self_47.myComponents
                               UNLOCK(self_47)
                               return x_4087
                           }
    var getName_48 = function (a_4094) {
                         var self_49 = LOCK(self_10)
                         var x_4091 = self_49.name
                         UNLOCK(self_49)
                         return x_4091
                     }
    var getNextFocusTarget_50 = function (a_4099) {
                                    var self_51 = LOCK(self_10)
                                    if (_sym_689_Prelude/* > */(length_Prelude(self_51.myComponents),
                                                                0)) {
                                        var self_52 = self_51
                                        var x_4095 = {   tagName : 'just',
                                                         a : last_Prelude(self_52.myComponents)
                                                     }
                                        UNLOCK(self_51)
                                        return x_4095
                                    } else {
                                        var self_53 = self_51
                                        var x_4096 = self_53.nextFocusTarget
                                        UNLOCK(self_51)
                                        return x_4096
                                    }
                                }
    function posget_54 (a_135) {
        switch (a_135.tagName) {
          case 'mousepressed': {
            var x_136 = a_135.a
            return x_136
            break
          }
          case 'mousereleased': {
            var x_137 = a_135.a
            return x_137
            break
          }
          case 'mouseclicked': {
            var x_138 = a_135.a
            return x_138
            break
          }
          default: {
            RAISE(1)
          }
        }
    }
    function getType_58 (a_139) {
        switch (a_139.tagName) {
          case 'mousepressed': {
            var x_143 = a_139.a
            return function (eta_1424) { return {   tagName : 'mousepressed',
                                                    a : eta_1424
                                                } }
            break
          }
          case 'mousereleased': {
            var x_144 = a_139.a
            return function (eta_1428) { return {   tagName : 'mousereleased',
                                                    a : eta_1428
                                                } }
            break
          }
          case 'mouseclicked': {
            var x_145 = a_139.a
            return function (eta_1432) { return {   tagName : 'mouseclicked',
                                                    a : eta_1432
                                                } }
            break
          }
          default: {
            RAISE(1)
          }
        }
    }
    function inithelper_59 (self_60) {
        var d_146 = containerSetSize_CTContainer(id_22,
                                                 self_60.size,
                                                 Inherit,
                                                 Inherit)
        var d_147 = containerSetBackgroundColor_CTContainer(id_22,
                                                            self_60.color,
                                                            Inherit,
                                                            Inherit)
        var d_148 = containerSetPosition_CTContainer(id_22,
                                                     self_60.position,
                                                     Inherit,
                                                     Inherit)
    }
    var installKeyListener_61 = function (a_4104, a_4105) {
                                    var self_63 = LOCK(self_10)
                                    self_63.keyEventHandler = {   tagName : 'just',
                                                                  a : a_4104
                                                              }
                                    UNLOCK(self_63)
                                }
    var installMouseListener_64 = function (a_4112, a_4113) {
                                      var self_66 = LOCK(self_10)
                                      self_66.mouseEventHandler = {   tagName : 'just',
                                                                      a : a_4112
                                                                  }
                                      UNLOCK(self_66)
                                  }
    var setName_67 = function (a_4118, a_4119) {
                         var self_69 = LOCK(self_10)
                         self_69.name = a_4118
                         UNLOCK(self_69)
                     }
    var setNextFocusTarget_70 = function (a_4122, a_4123) {
                                    var self_72 = LOCK(self_10)
                                    self_72.nextFocusTarget = a_4122
                                    if (_sym_689_Prelude/* > */(length_Prelude(self_72.myComponents),
                                                                0)) {
                                        var self_73 = self_72
                                        var d_149 = head_Prelude(self_73.myComponents).setNextFocusTarget(self_73.nextFocusTarget,
                                                                                                          0)
                                        if (isJust_Prelude(self_73.nextFocusTarget)) {
                                            var d_151 = fromJust_Prelude(self_73.nextFocusTarget).setPreviousFocusTarget({   tagName : 'just',
                                                                                                                             a : head_Prelude(self_73.myComponents)
                                                                                                                         },
                                                                                                                         0)
                                            break
                                        }
                                        UNLOCK(self_72)
                                    } else {
                                        var self_76 = self_72
                                        UNLOCK(self_72)
                                    }
                                }
    var x_4160 = getNextFocusTarget_50
    var x_4167 = setNextFocusTarget_70
    var x_4173 = getPosition_28
    var x_4175 = setPosition_23
    var x_4179 = getSize_35
    var x_4181 = setSize_30
    var x_4189 = destroy_44
    var x_4191 = getName_48
    var x_4196 = setName_67
    var x_4202 = getComponents_46
    var x_4204 = installMouseListener_64
    var x_4207 = installKeyListener_61
    var x_4210 = getBackgroundColor_42
    var x_4212 = setBackgroundColor_37
    var mouseEventDispatcher_84 = function() { return arguments.callee.Code.apply(this,arguments) }
    var this_86 = {}
    var x_3398 = {}
    var focus_77 = focusWrapper_CTCommon(x_3398, false, 0)
    var setPreviousFocusTarget_78 = function (a_4126,
                                              a_4127) { return focus_77.setPreviousFocusTarget(a_4126,
                                                                                               a_4127) }
    var getPreviousFocusTarget_79 = function (a_4129) { return focus_77.getPreviousFocusTarget(a_4129) }
    var setIsFocusable_80 = function (a_4132,
                                      a_4133) { return focus_77.setIsFocusable(a_4132, a_4133) }
    var getIsFocusable_81 = function (a_4135) { return focus_77.getIsFocusable(a_4135) }
    var addComponent_82 = function (a_4138, a_4139) {
                              var self_88 = LOCK(self_10)
                              var d_152 = function () {
                                              if (_sym_689_Prelude/* > */(length_Prelude(self_88.myComponents),
                                                                          0)) {
                                                  return function (self_89) {
                                                             var newestCmp_90 = head_Prelude(self_89.myComponents)
                                                             var x_154 = newestCmp_90.getNextFocusTarget(0)
                                                             var d_153 = a_4138.setNextFocusTarget(x_154,
                                                                                                   0)
                                                             var d_155 = newestCmp_90.setNextFocusTarget({   tagName : 'just',
                                                                                                             a : a_4138
                                                                                                         },
                                                                                                         0)
                                                             var d_156 = a_4138.setPreviousFocusTarget({   tagName : 'just',
                                                                                                           a : newestCmp_90
                                                                                                       },
                                                                                                       0)
                                                         }
                                              } else {
                                                  return function (self_91) {
                                                             var d_157 = a_4138.setNextFocusTarget(self_91.nextFocusTarget,
                                                                                                   0)
                                                             var x_159 = focus_77.getPreviousFocusTarget(0)
                                                             var d_158 = a_4138.setPreviousFocusTarget(x_159,
                                                                                                       0)
                                                             if (isJust_Prelude(self_91.nextFocusTarget)) {
                                                                 var d_161 = fromJust_Prelude(self_91.nextFocusTarget).setPreviousFocusTarget({   tagName : 'just',
                                                                                                                                                  a : a_4138
                                                                                                                                              },
                                                                                                                                              0)
                                                                 break
                                                             }
                                                             self_91.nextFocusTarget = {   tagName : 'just',
                                                                                           a : a_4138
                                                                                       }
                                                         }
                                              }
                                          }()(self_88)
                              self_88.myComponents = [a_4138].concat(self_88.myComponents)
                              if (compareState_CTCommon(self_88.myState,
                                                        'active') && isJust_Prelude(self_88.appRef)) {
                                  var self_94 = self_88
                                  var d_162 = a_4138.init(fromJust_Prelude(self_94.appRef), 0)
                                  var d_163 = containerAddComponent_CTContainer(id_22,
                                                                                a_4138.id,
                                                                                Inherit,
                                                                                Inherit)
                                  UNLOCK(self_88)
                              } else {
                                  var self_95 = self_88
                                  UNLOCK(self_88)
                              }
                          }
    var handleEvent_83 = function (a_4142, a_4143, a_4144) {
                             switch (a_4142.tagName) {
                               case 'mouseevent': {
                                 var x_167 = a_4142.a
                                 var self_98 = LOCK(self_10)
                                 var x_164 = mouseEventDispatcher_84(x_167, a_4143, self_98)
                                 UNLOCK(self_98)
                                 return x_164
                                 break
                               }
                               default: {
                                 RAISE(1)
                               }
                             }
                         }
    mouseEventDispatcher_84.Code = function (a_4149, a_4150, a_4151) {
                                       a_4151.currentEventHasBeenConsumedBy = 'nothing'
                                       var pos_102 = posget_54(a_4149)
                                       var et_103 = getType_58(a_4149)
                                       var pos2_104 = {   tagName : 'position',
                                                          x : _sym_621_Prelude/* - */(pos_102.x,
                                                                                      a_4151.position.x),
                                                          y : _sym_621_Prelude/* - */(pos_102.y,
                                                                                      a_4151.position.y)
                                                      }
                                       var eventInNewCoordsystem_105 = getType_58(a_4149)(pos_102)
                                       var d_170 = forallListUnit_Prelude(function (a_4146,
                                                                                    a_4147) {
                                                                              if (isNothing_Prelude(a_4147.currentEventHasBeenConsumedBy)) {
                                                                                  var self_108 = a_4147
                                                                                  var cmpPos_109 = a_4146.getPosition(0)
                                                                                  var cmpSize_110 = a_4146.getSize(0)
                                                                                  if (inInterval_CTContainer(ordInt_Prelude,
                                                                                                             numInt_Prelude,
                                                                                                             pos2_104.x,
                                                                                                             cmpPos_109.x,
                                                                                                             cmpSize_110.width) && inInterval_CTContainer(ordInt_Prelude,
                                                                                                                                                          numInt_Prelude,
                                                                                                                                                          pos2_104.y,
                                                                                                                                                          cmpPos_109.y,
                                                                                                                                                          cmpSize_110.height)) {
                                                                                      var x_172 = a_4146.handleEvent({   tagName : 'mouseevent',
                                                                                                                         a : eventInNewCoordsystem_105
                                                                                                                     },
                                                                                                                     a_4150,
                                                                                                                     0)
                                                                                      self_108.currentEventHasBeenConsumedBy = x_172
                                                                                      break
                                                                                  }
                                                                              } else {
                                                                                  var self_113 = a_4147
                                                                              }
                                                                          },
                                                                          a_4151.myComponents,
                                                                          a_4151)
                                       if (isNothing_Prelude(a_4151.currentEventHasBeenConsumedBy)) {
                                           var x_174 = dynamicHandleEvent_CTCommon(a_4149,
                                                                                   a_4151.mouseEventHandler,
                                                                                   a_4151)
                                           a_4151.currentEventHasBeenConsumedBy = boolToMaybe_CTCommon({   tagName : 'just',
                                                                                                           a : this_86
                                                                                                       },
                                                                                                       x_174)
                                           break
                                       }
                                       var x_4148 = a_4151.currentEventHasBeenConsumedBy
                                       return x_4148
                                   }
    var init_85 = function (a_4156, a_4157) {
                      var self_117 = LOCK(self_10)
                      self_117.myState = 'active'
                      self_117.appRef = {   tagName : 'just',
                                            a : a_4156
                                        }
                      var d_175 = initContainer_CTContainer(this_86, a_4156, 0)
                      var d_176 = inithelper_59(self_117)
                      var d_177 = forallListUnit_Prelude(function (a_4152, a_4153) {
                                                             var d_178 = a_4152.init(a_4156, 0)
                                                             var d_179 = containerAddComponent_CTContainer(id_22,
                                                                                                           a_4152.id,
                                                                                                           Inherit,
                                                                                                           Inherit)
                                                         },
                                                         self_117.myComponents,
                                                         self_117)
                      UNLOCK(self_117)
                  }
    var x_4158 = getIsFocusable_81
    var x_4162 = getPreviousFocusTarget_79
    var x_4164 = setIsFocusable_80
    var x_4170 = setPreviousFocusTarget_78
    var x_4185 = handleEvent_83
    var x_4193 = init_85
    var x_4199 = addComponent_82
    this_86 = UPDATE(this_86, {   tagName : 'container',
                                  getIsFocusable : function (a_4159) {
                                      return x_4158(a_4159)
                                  },
                                  getNextFocusTarget : function (a_4161) {
                                      return x_4160(a_4161)
                                  },
                                  getPreviousFocusTarget : function (a_4163) {
                                      return x_4162(a_4163)
                                  },
                                  setIsFocusable : function (a_4165, a_4166) {
                                      return x_4164(a_4165, a_4166)
                                  },
                                  setNextFocusTarget : function (a_4168, a_4169) {
                                      return x_4167(a_4168, a_4169)
                                  },
                                  setPreviousFocusTarget : function (a_4171, a_4172) {
                                      return x_4170(a_4171, a_4172)
                                  },
                                  getPosition : function (a_4174) {
                                      return x_4173(a_4174)
                                  },
                                  setPosition : function (a_4176, a_4177, a_4178) {
                                      return x_4175(a_4176, a_4177, a_4178)
                                  },
                                  getSize : function (a_4180) {
                                      return x_4179(a_4180)
                                  },
                                  setSize : function (a_4182, a_4183, a_4184) {
                                      return x_4181(a_4182, a_4183, a_4184)
                                  },
                                  handleEvent : function (a_4186, a_4187, a_4188) {
                                      return x_4185(a_4186, a_4187, a_4188)
                                  },
                                  destroy : function (a_4190) {
                                      return x_4189(a_4190)
                                  },
                                  getName : function (a_4192) {
                                      return x_4191(a_4192)
                                  },
                                  id : id_22,
                                  init : function (a_4194, a_4195) {
                                      return x_4193(a_4194, a_4195)
                                  },
                                  setName : function (a_4197, a_4198) {
                                      return x_4196(a_4197, a_4198)
                                  },
                                  addComponent : function (a_4200, a_4201) {
                                      return x_4199(a_4200, a_4201)
                                  },
                                  getComponents : function (a_4203) {
                                      return x_4202(a_4203)
                                  },
                                  installMouseListener : function (a_4205, a_4206) {
                                      return x_4204(a_4205, a_4206)
                                  },
                                  installKeyListener : function (a_4208, a_4209) {
                                      return x_4207(a_4208, a_4209)
                                  },
                                  getBackgroundColor : function (a_4211) {
                                      return x_4210(a_4211)
                                  },
                                  setBackgroundColor : function (a_4213, a_4214, a_4215) {
                                      return x_4212(a_4213, a_4214, a_4215)
                                  }
                              })
    x_3398 = UPDATE(x_3398, this_86)
    var handleEvent_120 = function (a_4218, a_4219, a_4220) {
                              var self_122 = LOCK(self_10)
                              UNLOCK(self_122)
                              return 'nothing'
                          }
    self_10.myState = 'inactive'
    self_10.myComponents = []
    self_10.position = {   tagName : 'position',
                           x : 0,
                           y : 0
                       }
    self_10.size = {   tagName : 'size',
                       width : 0,
                       height : 0
                   }
    self_10.color = {   tagName : 'color',
                        r : 255,
                        g : 255,
                        b : 255
                    }
    self_10.keyEventHandler = 'nothing'
    self_10.appRef = 'nothing'
    self_10.mouseEventHandler = 'nothing'
    self_10.currentEventHasBeenConsumedBy = 'nothing'
    self_10.nextFocusTarget = 'nothing'
    self_10.name = "Container"
    return this_86
}