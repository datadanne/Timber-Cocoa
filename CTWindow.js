function mkWindow_CTWindow (env_8, d_3693) {
    var self_9 = { LOCKED: false }
    var windowId_20 = mkCocoaID_CTCommon(0)
    var rootContainer_21 = mkContainer_CTContainer(env_8, 0)
    var addComponent_22 = function (a_3601,
                                    a_3602) { return rootContainer_21.addComponent(a_3601, a_3602) }
    var getComponents_23 = function (a_3604) { return rootContainer_21.getComponents(a_3604) }
    var getId_24 = function (a_3608) {
                       var self_25 = LOCK(self_9)
                       var x_3605 = self_25.nr
                       UNLOCK(self_25)
                       return x_3605
                   }
    var initWindow_26 = function (a_3611, a_3612) {
                            var self_28 = LOCK(self_9)
                            var x_103 = initCocoaWindow_CTWindow(self_28.this_19, a_3611, 0)
                            self_28.nr = x_103
                            var d_104 = rootContainer_21.init(a_3611, 0)
                            self_28.state = 'active'
                            self_28.isVisible = true
                            var d_105 = setContentViewForWindow_CTWindow(self_28.this_19,
                                                                         rootContainer_21.id,
                                                                         0)
                            UNLOCK(self_28)
                        }
    var destroyWindow_29 = function (a_3615) {
                               var self_30 = LOCK(self_9)
                               if (compareState_CTCommon(self_30.state, 'active')) {
                                   var self_31 = self_30
                                   self_31.state = 'destroyed'
                                   var d_106 = rootContainer_21.destroy(0)
                                   var d_107 = destroyCocoaWindow_CTWindow(windowId_20, 0)
                                   UNLOCK(self_30)
                               } else {
                                   var self_32 = self_30
                                   UNLOCK(self_30)
                               }
                           }
    function setFocus_33 (cmp_34, a_3618, a_3619) {
        var x_3620 = function () {
                         var self_35 = LOCK(self_9)
                         self_35.currentFocus = {   tagName : 'just',
                                                    a : cmp_34
                                                }
                         if (compareState_CTCommon(self_35.state, 'active')) {
                             var self_36 = self_35
                             var d_108 = windowSetFocus_CTWindow(windowId_20, cmp_34.id, 0)
                             UNLOCK(self_35)
                         } else {
                             var self_37 = self_35
                             UNLOCK(self_35)
                         }
                     }
        return ASYNC(x_3620, a_3618, a_3619)
    }
    var handleEvent_38 = function (a_3629, a_3630, a_3631) {
                             switch (a_3629.tagName) {
                               case 'keyevent': {
                                 var x_147 = a_3629.a
                                 var self_41 = LOCK(self_9)
                                 switch (x_147.tagName) {
                                   case 'keypressed': {
                                     var x_137 = x_147.a
                                     var x_111 = self_41
                                     x_111.consumed = false
                                     if (isJust_Prelude(x_111.currentFocus)) {
                                         var x_113 = fromJust_Prelude(x_111.currentFocus).handleEvent({   tagName : 'keyevent',
                                                                                                          a : x_147
                                                                                                      },
                                                                                                      a_3630,
                                                                                                      0)
                                         x_111.consumed = isJust_Prelude(x_113)
                                         break
                                     }
                                     if (_sym_679_Prelude/* == */(x_111.consumed, false)) {
                                         var d_115 = function () {
                                                         if (compareKeys_CTCommon(x_137, 'tab')) {
                                                             return function (self_46) {
                                                                        if (isNothing_Prelude(self_46.currentFocus)) {
                                                                            var x_117 = rootContainer_21.getNextFocusTarget(0)
                                                                            self_46.currentFocus = x_117
                                                                            break
                                                                        }
                                                                        if (isJust_Prelude(self_46.currentFocus)) {
                                                                            var x_119 = fromJust_Prelude(self_46.currentFocus).getNextFocusTarget(0)
                                                                            self_46.nextFocus = x_119
                                                                            break
                                                                        }
                                                                        var d_120 = function () {
                                                                                        if (isNothing_Prelude(self_46.nextFocus)) {
                                                                                            return function (self_51) {
                                                                                                       var x_121 = rootContainer_21.getNextFocusTarget(0)
                                                                                                       self_51.currentFocus = x_121
                                                                                                       if (isJust_Prelude(self_51.currentFocus)) {
                                                                                                           var x_123 = fromJust_Prelude(self_51.currentFocus).getNextFocusTarget(0)
                                                                                                           self_51.nextFocus = x_123
                                                                                                           break
                                                                                                       }
                                                                                                   }
                                                                                        } else {
                                                                                            return function (self_54) { return 'tuple0' }
                                                                                        }
                                                                                    }()(self_46)
                                                                        if (isJust_Prelude(self_46.nextFocus)) {
                                                                            var next_56 = fromJust_Prelude(self_46.nextFocus).getNextFocusTarget(0)
                                                                            self_46.currentFocus = self_46.nextFocus
                                                                            var d_125 = setFocus_33(fromJust_Prelude(self_46.nextFocus),
                                                                                                    Inherit,
                                                                                                    Inherit)
                                                                            break
                                                                        }
                                                                    }
                                                         } else {
                                                             if (compareKeys_CTCommon(x_137,
                                                                                      'capslock')) {
                                                                 return function (self_58) {
                                                                            if (isNothing_Prelude(self_58.currentFocus)) {
                                                                                var x_127 = rootContainer_21.getPreviousFocusTarget(0)
                                                                                self_58.currentFocus = x_127
                                                                                break
                                                                            }
                                                                            if (isJust_Prelude(self_58.currentFocus)) {
                                                                                var x_129 = fromJust_Prelude(self_58.currentFocus).getPreviousFocusTarget(0)
                                                                                self_58.previousFocus = x_129
                                                                                break
                                                                            }
                                                                            var d_130 = function () {
                                                                                            if (isNothing_Prelude(self_58.previousFocus)) {
                                                                                                return function (self_63) {
                                                                                                           var x_131 = rootContainer_21.getPreviousFocusTarget(0)
                                                                                                           self_63.currentFocus = x_131
                                                                                                           if (isJust_Prelude(self_63.currentFocus)) {
                                                                                                               var x_133 = fromJust_Prelude(self_63.currentFocus).getPreviousFocusTarget(0)
                                                                                                               self_63.previousFocus = x_133
                                                                                                               break
                                                                                                           }
                                                                                                       }
                                                                                            } else {
                                                                                                return function (self_66) { return 'tuple0' }
                                                                                            }
                                                                                        }()(self_58)
                                                                            if (isJust_Prelude(self_58.previousFocus)) {
                                                                                var next_68 = fromJust_Prelude(self_58.previousFocus).getPreviousFocusTarget(0)
                                                                                self_58.currentFocus = self_58.previousFocus
                                                                                var d_135 = setFocus_33(fromJust_Prelude(self_58.previousFocus),
                                                                                                        Inherit,
                                                                                                        Inherit)
                                                                                break
                                                                            }
                                                                        }
                                                             } else {
                                                                 return function (self_70) { return 'tuple0' }
                                                             }
                                                         }
                                                     }()(x_111)
                                         break
                                     }
                                     var x_136 = dynamicHandleEvent_CTCommon(x_147,
                                                                             x_111.keyListener,
                                                                             x_111)
                                     var x_3621 = boolToMaybe_CTCommon('nothing', x_136)
                                     UNLOCK(self_41)
                                     return x_3621
                                     break
                                   }
                                   default: {
                                     RAISE(1)
                                   }
                                 }
                                 break
                               }
                               case 'windowevent': {
                                 var x_148 = a_3629.a
                                 var self_74 = LOCK(self_9)
                                 switch (x_148) {
                                   case 'windowclosed': {
                                     function f_3694 (self_76) {
                                         if (compareState_CTCommon(self_76.state, 'active')) {
                                             self_76.state = 'inactive'
                                             break
                                         }
                                     }
                                     var d_139 = f_3694(self_74)
                                     break
                                     break
                                   }
                                   default: break
                                 }
                                 var x_142 = dynamicHandleEvent_CTCommon(x_148,
                                                                         self_74.windowListener,
                                                                         self_74)
                                 var x_3624 = boolToMaybe_CTCommon('nothing', x_142)
                                 UNLOCK(self_74)
                                 return x_3624
                                 break
                               }
                               case 'mouseevent': {
                                 var x_149 = a_3629.a
                                 var self_82 = LOCK(self_9)
                                 var cmp_83 = rootContainer_21.handleEvent({   tagName : 'mouseevent',
                                                                               a : x_149
                                                                           },
                                                                           a_3630,
                                                                           0)
                                 var d_143 = function () {
                                                 if (isJust_Prelude(cmp_83)) {
                                                     return function (self_84) {
                                                                var x_145 = fromJust_Prelude(cmp_83).getIsFocusable(0)
                                                                if (x_145) {
                                                                    var d_146 = setFocus_33(fromJust_Prelude(cmp_83),
                                                                                            Inherit,
                                                                                            Inherit)
                                                                    break
                                                                }
                                                            }
                                                 } else {
                                                     return function (self_87) { return 'tuple0' }
                                                 }
                                             }()(self_82)
                                 UNLOCK(self_82)
                                 return cmp_83
                                 break
                               }
                             }
                         }
    var installWindowListener_88 = function (a_3636, a_3637) {
                                       var self_90 = LOCK(self_9)
                                       self_90.windowListener = {   tagName : 'just',
                                                                    a : a_3636
                                                                }
                                       UNLOCK(self_90)
                                   }
    var installKeyListener_91 = function (a_3644, a_3645) {
                                    var self_93 = LOCK(self_9)
                                    self_93.keyListener = {   tagName : 'just',
                                                              a : a_3644
                                                          }
                                    UNLOCK(self_93)
                                }
    var installMouseListener_94 = function (a_3650,
                                            a_3651) { return rootContainer_21.installMouseListener(a_3650,
                                                                                                   a_3651) }
    var hide_95 = function (a_3656) {
                      var self_96 = LOCK(self_9)
                      if (compareState_CTCommon(self_96.state,
                                                'active') && _sym_679_Prelude/* == */(self_96.isVisible,
                                                                                      true)) {
                          var self_97 = self_96
                          var d_150 = windowSetHidden_CTWindow(windowId_20, Inherit, Inherit)
                          self_97.isVisible = false
                          UNLOCK(self_96)
                          return true
                      } else {
                          var self_98 = self_96
                          UNLOCK(self_96)
                          return false
                      }
                  }
    var setVisible_99 = function (a_3659) {
                            var self_100 = LOCK(self_9)
                            if (compareState_CTCommon(self_100.state,
                                                      'active') && _sym_679_Prelude/* == */(self_100.isVisible,
                                                                                            false)) {
                                var self_101 = self_100
                                var d_151 = windowSetVisible_CTWindow(windowId_20,
                                                                      Inherit,
                                                                      Inherit)
                                self_101.isVisible = true
                                UNLOCK(self_100)
                                return true
                            } else {
                                var self_102 = self_100
                                UNLOCK(self_100)
                                return false
                            }
                        }
    self_9.keyListener = 'nothing'
    self_9.windowListener = 'nothing'
    self_9.nr = 0
    self_9.state = 'inactive'
    self_9.isVisible = false
    self_9.currentFocus = 'nothing'
    self_9.nextFocus = 'nothing'
    self_9.previousFocus = 'nothing'
    self_9.consumed = false
    var x_3660 = addComponent_22
    var x_3663 = getComponents_23
    var x_3665 = installKeyListener_91
    var x_3668 = handleEvent_38
    var x_3672 = installWindowListener_88
    var x_3675 = installMouseListener_94
    var x_3678 = destroyWindow_29
    var x_3680 = getId_24
    var x_3682 = hide_95
    var x_3684 = initWindow_26
    var x_3690 = setVisible_99
    self_9.this_19 = {   tagName : 'cocoawindow',
                         addComponent : function (a_3661, a_3662) {
                             return x_3660(a_3661, a_3662)
                         },
                         getComponents : function (a_3664) {
                             return x_3663(a_3664)
                         },
                         installKeyListener : function (a_3666, a_3667) {
                             return x_3665(a_3666, a_3667)
                         },
                         handleEvent : function (a_3669, a_3670, a_3671) {
                             return x_3668(a_3669, a_3670, a_3671)
                         },
                         installWindowListener : function (a_3673, a_3674) {
                             return x_3672(a_3673, a_3674)
                         },
                         installMouseListener : function (a_3676, a_3677) {
                             return x_3675(a_3676, a_3677)
                         },
                         destroyWindow : function (a_3679) {
                             return x_3678(a_3679)
                         },
                         getId : function (a_3681) {
                             return x_3680(a_3681)
                         },
                         hide : function (a_3683) {
                             return x_3682(a_3683)
                         },
                         initWindow : function (a_3685, a_3686) {
                             return x_3684(a_3685, a_3686)
                         },
                         setFocus : function (a_3687, a_3688, a_3689) {
                             return setFocus_33(a_3687, a_3688, a_3689)
                         },
                         setVisible : function (a_3691) {
                             return x_3690(a_3691)
                         },
                         windowId : windowId_20
                     }
    var x_3692 = self_9.this_19
    return x_3692
}