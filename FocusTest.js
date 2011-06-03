function root_FocusTest (w_2, d_1845) {
    var self_3 = { LOCKED: false }
    var env_5 = posix_POSIX(w_2, 0)
    var osx_6 = cocoa_COCOA(w_2, 0)
    var w1_7 = mkWindow_CTWindow(env_5, 0)
    var c2_8 = mkContainer_CTContainer(env_5, 0)
    var button_9 = mkCocoaButton_CTButton(env_5, 0)
    var button2_10 = mkCocoaButton_CTButton(env_5, 0)
    var tabClick_11 = function (a_1795, a_1796, a_1797, a_1798) {
                          var self_15 = LOCK(self_3)
                          var d_32 = env_5.stdout.write(_sym_20_Prelude/* ++ */("Sending KeyPressed \"Tab\" to window with ID: ",
                                                                                _sym_20_Prelude/* ++ */(show_723_Prelude(a_1796),
                                                                                                        "\n")),
                                                        0)
                          var foo_16 = {   tagName : 'keyevent',
                                           a : {   tagName : 'keypressed',
                                                   a : 'uparrow'
                                               }
                                       }
                          var superTest_17 = {   tagName : 'keyevent',
                                                 a : {   tagName : 'keypressed',
                                                         a : 'tab'
                                                     }
                                             }
                          var d_33 = a_1795.eventDispatcher(superTest_17,
                                                            a_1796,
                                                            Inherit,
                                                            Inherit)
                          UNLOCK(self_15)
                          return true
                      }
    var tabStop_18 = function (a_1802, a_1803) {
                         var self_20 = LOCK(self_3)
                         self_20.block = not_Prelude(self_20.block)
                         var d_34 = env_5.stdout.write(function () {
                                                           if (self_20.block) {
                                                               return "Tab shall not pass!\n"
                                                           } else {
                                                               return "It\'s ok. Tab may continue.\n"
                                                           }
                                                       }(),
                                                       0)
                         var x_1799 = self_20.block
                         UNLOCK(self_20)
                         return x_1799
                     }
    var doNothing_21 = function (a_1806, a_1807) {
                           var self_23 = LOCK(self_3)
                           UNLOCK(self_23)
                           return true
                       }
    var applicationDidFinishLaunching_24 = function (a_1829,
                                                     a_1830,
                                                     a_1831) {
                                               var x_1828 = function () {
                                                                var self_26 = LOCK(self_3)
                                                                var d_35 = a_1829.showWindow(w1_7,
                                                                                             0)
                                                                var d_36 = a_1829.setEnv(env_5, 0)
                                                                var tabButton_27 = mkCocoaButton_CTButton(env_5,
                                                                                                          0)
                                                                var d_37 = tabButton_27.setTitle("TAB",
                                                                                                 Inherit,
                                                                                                 Inherit)
                                                                var d_38 = tabButton_27.setPosition({   tagName : 'position',
                                                                                                        x : 20,
                                                                                                        y : 200
                                                                                                    },
                                                                                                    Inherit,
                                                                                                    Inherit)
                                                                var x_42 = w1_7.getId(0)
                                                                var d_41 = tabButton_27.installMouseListener(function (a_1809,
                                                                                                                       a_1810) { return tabClick_11(a_1829,
                                                                                                                                                    x_42,
                                                                                                                                                    a_1809,
                                                                                                                                                    a_1810) },
                                                                                                             0)
                                                                var d_43 = tabButton_27.setIsFocusable(false,
                                                                                                       0)
                                                                var d_44 = button_9.installMouseListener(function (a_1813,
                                                                                                                   a_1814) { return doNothing_21(a_1813,
                                                                                                                                                 a_1814) },
                                                                                                         0)
                                                                var d_45 = button2_10.installMouseListener(function (a_1817,
                                                                                                                     a_1818) { return doNothing_21(a_1817,
                                                                                                                                                   a_1818) },
                                                                                                           0)
                                                                var d_46 = w1_7.addComponent(tabButton_27,
                                                                                             0)
                                                                var d_47 = button_9.setTitle("Move",
                                                                                             Inherit,
                                                                                             Inherit)
                                                                var d_48 = button_9.setPosition({   tagName : 'position',
                                                                                                    x : 20,
                                                                                                    y : 20
                                                                                                },
                                                                                                Inherit,
                                                                                                Inherit)
                                                                var d_51 = button2_10.setPosition({   tagName : 'position',
                                                                                                      x : 0,
                                                                                                      y : 55
                                                                                                  },
                                                                                                  Inherit,
                                                                                                  Inherit)
                                                                var d_54 = button2_10.setTitle("sec7add",
                                                                                               Inherit,
                                                                                               Inherit)
                                                                function f_1846 (a_1821, a_1822) {
                                                                    var x_1823 = function () {
                                                                                     var self_28 = LOCK(self_26)
                                                                                     var button3_29 = mkCocoaButton_CTButton(env_5,
                                                                                                                             0)
                                                                                     var c3_30 = mkContainer_CTContainer(env_5,
                                                                                                                         0)
                                                                                     var d_56 = c3_30.addComponent(button3_29,
                                                                                                                   0)
                                                                                     var d_57 = c3_30.setSize({   tagName : 'size',
                                                                                                                  width : 180,
                                                                                                                  height : 50
                                                                                                              },
                                                                                                              Inherit,
                                                                                                              Inherit)
                                                                                     var d_60 = c3_30.setPosition({   tagName : 'position',
                                                                                                                      x : 0,
                                                                                                                      y : 100
                                                                                                                  },
                                                                                                                  Inherit,
                                                                                                                  Inherit)
                                                                                     var d_63 = c3_30.setBackgroundColor({   tagName : 'color',
                                                                                                                             r : 240,
                                                                                                                             g : 66,
                                                                                                                             b : 33
                                                                                                                         },
                                                                                                                         Inherit,
                                                                                                                         Inherit)
                                                                                     var d_67 = c2_8.addComponent(c3_30,
                                                                                                                  0)
                                                                                     UNLOCK(self_28)
                                                                                 }
                                                                    return ASYNC(x_1823,
                                                                                 a_1821,
                                                                                 a_1822)
                                                                }
                                                                var d_55 = f_1846(Inherit + 1000*(2),
                                                                                  Inherit)
                                                                UNLOCK(self_26)
                                                            }
                                               return ASYNC(x_1828, a_1830, a_1831)
                                           }
    self_3.block = false
    var x_1844 = function (a_1841, a_1842) {
                     var x_1843 = function () {
                                      var self_31 = LOCK(self_3)
                                      var d_68 = button_9.setSize({   tagName : 'size',
                                                                      width : 108,
                                                                      height : 17
                                                                  },
                                                                  Inherit,
                                                                  Inherit)
                                      var d_71 = button2_10.setName("sec7add", 0)
                                      var d_72 = button_9.setName("Move", 0)
                                      var d_73 = button_9.installKeyListener(function (a_1834,
                                                                                       a_1835) { return tabStop_18(a_1834,
                                                                                                                   a_1835) },
                                                                             0)
                                      var d_74 = c2_8.setName("greenContainer ", 0)
                                      var d_75 = c2_8.setSize({   tagName : 'size',
                                                                  width : 180,
                                                                  height : 140
                                                              },
                                                              Inherit,
                                                              Inherit)
                                      var d_78 = c2_8.setPosition({   tagName : 'position',
                                                                      x : 0,
                                                                      y : 0
                                                                  },
                                                                  Inherit,
                                                                  Inherit)
                                      var d_81 = c2_8.setBackgroundColor({   tagName : 'color',
                                                                             r : 0,
                                                                             g : 255,
                                                                             b : 0
                                                                         },
                                                                         Inherit,
                                                                         Inherit)
                                      var d_85 = c2_8.addComponent(button2_10, 0)
                                      var d_86 = c2_8.addComponent(button_9, 0)
                                      var d_87 = w1_7.addComponent(c2_8, 0)
                                      var d_88 = osx_6.startApplication(applicationDidFinishLaunching_24,
                                                                        0)
                                      UNLOCK(self_31)
                                  }
                     return ASYNC(x_1843, a_1841, a_1842)
                 }
    return x_1844
}