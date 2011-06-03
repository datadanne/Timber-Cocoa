function root_NewTest (w_2, d_3017) {
    var self_3 = { LOCKED: false }
    var env_5 = posix_POSIX(w_2, 0)
    var osx_6 = cocoa_COCOA(w_2, 0)
    var w1_7 = mkWindow_CTWindow(env_5, 0)
    var w2_8 = mkWindow_CTWindow(env_5, 0)
    var c1_9 = mkContainer_CTContainer(env_5, 0)
    var c2_10 = mkContainer_CTContainer(env_5, 0)
    var button_11 = mkCocoaButton_CTButton(env_5, 0)
    var teest_12 = mkCocoaLabel_CTLabel(0)
    var moveUp_13 = function (a_2936, a_2937, a_2938) {
                        var self_16 = LOCK(self_3)
                        var q_17 = a_2936.getPosition(0)
                        var d_50 = a_2936.setPosition({   tagName : 'position',
                                                          x : q_17.x,
                                                          y : _sym_620_Prelude/* + */(q_17.y, 5)
                                                      },
                                                      Inherit,
                                                      Inherit)
                        UNLOCK(self_16)
                        return true
                    }
    var react_18 = function (a_2941, a_2942, a_2943) {
                       var self_21 = LOCK(self_3)
                       UNLOCK(self_21)
                       return true
                   }
    var reactor_22 = function (a_2946, a_2947, a_2948) {
                         var self_25 = LOCK(self_3)
                         UNLOCK(self_25)
                         return true
                     }
    var moveUp2_26 = function (a_2951, a_2952, a_2953) {
                         var self_29 = LOCK(self_3)
                         self_29.count = _sym_620_Prelude/* + */(self_29.count, 1)
                         var q_30 = a_2951.getPosition(0)
                         var d_53 = a_2951.setPosition({   tagName : 'position',
                                                           x : _sym_620_Prelude/* + */(q_30.x, 5),
                                                           y : _sym_620_Prelude/* + */(q_30.y, 5)
                                                       },
                                                       Inherit,
                                                       Inherit)
                         var d_56 = button_11.setTitle(_sym_20_Prelude/* ++ */("Move (",
                                                                               _sym_20_Prelude/* ++ */(show_723_Prelude(self_29.count),
                                                                                                       ")")),
                                                       Inherit,
                                                       Inherit)
                         UNLOCK(self_29)
                         return true
                     }
    var greenclicked_31 = function (a_2956, a_2957, a_2958, a_2959) {
                              var self_35 = LOCK(self_3)
                              var d_57 = env_5.stdout.write(_sym_20_Prelude/* ++ */("green clicked!!!: ",
                                                                                    _sym_20_Prelude/* ++ */(show_723_Prelude(a_2957),
                                                                                                            "\n")),
                                                            0)
                              var superTest_36 = {   tagName : 'keyevent',
                                                     a : {   tagName : 'keypressed',
                                                             a : 'tab'
                                                         }
                                                 }
                              var d_58 = a_2956.eventDispatcher(superTest_36,
                                                                a_2957,
                                                                Inherit,
                                                                Inherit)
                              UNLOCK(self_35)
                              return true
                          }
    var applicationDidFinishLaunching_37 = function (a_2991,
                                                     a_2992,
                                                     a_2993) {
                                               var x_2990 = function () {
                                                                var self_39 = LOCK(self_3)
                                                                var d_59 = a_2991.setEnv(env_5, 0)
                                                                var d_60 = a_2991.showWindow(w2_8,
                                                                                             0)
                                                                var d_61 = a_2991.showWindow(w1_7,
                                                                                             0)
                                                                var x_63 = w1_7.getId(0)
                                                                var d_62 = c2_10.installMouseListener(function (a_2961,
                                                                                                                a_2962) { return greenclicked_31(a_2991,
                                                                                                                                                 x_63,
                                                                                                                                                 a_2961,
                                                                                                                                                 a_2962) },
                                                                                                      0)
                                                                var d_64 = c1_9.setBackgroundColor({   tagName : 'color',
                                                                                                       r : 255,
                                                                                                       g : 0,
                                                                                                       b : 255
                                                                                                   },
                                                                                                   Inherit,
                                                                                                   Inherit)
                                                                function f_3021 (a_2983, a_2984) {
                                                                    var x_2985 = function () {
                                                                                     var self_40 = LOCK(self_39)
                                                                                     var d_69 = env_5.stdout.write("---- IN AFTER 4 SEC!!! ----\n",
                                                                                                                   0)
                                                                                     var d_70 = c1_9.setBackgroundColor({   tagName : 'color',
                                                                                                                            r : 0,
                                                                                                                            g : 0,
                                                                                                                            b : 255
                                                                                                                        },
                                                                                                                        Inherit,
                                                                                                                        Inherit)
                                                                                     var d_74 = c1_9.setSize({   tagName : 'size',
                                                                                                                 width : 50,
                                                                                                                 height : 50
                                                                                                             },
                                                                                                             Inherit,
                                                                                                             Inherit)
                                                                                     var d_77 = c1_9.setPosition({   tagName : 'position',
                                                                                                                     x : 0,
                                                                                                                     y : 100
                                                                                                                 },
                                                                                                                 Inherit,
                                                                                                                 Inherit)
                                                                                     var d_80 = button_11.setTitle("Move",
                                                                                                                   Inherit,
                                                                                                                   Inherit)
                                                                                     var d_81 = button_11.setPosition({   tagName : 'position',
                                                                                                                          x : 20,
                                                                                                                          y : 20
                                                                                                                      },
                                                                                                                      Inherit,
                                                                                                                      Inherit)
                                                                                     function f_3020 (a_2965,
                                                                                                      a_2966) {
                                                                                         var x_2967 = function () {
                                                                                                          var self_41 = LOCK(self_40)
                                                                                                          var d_85 = w2_8.hide(0)
                                                                                                          var d_86 = teest_12.setPosition({   tagName : 'position',
                                                                                                                                              x : 20,
                                                                                                                                              y : 150
                                                                                                                                          },
                                                                                                                                          Inherit,
                                                                                                                                          Inherit)
                                                                                                          UNLOCK(self_41)
                                                                                                      }
                                                                                         return ASYNC(x_2967,
                                                                                                      a_2965,
                                                                                                      a_2966)
                                                                                     }
                                                                                     var d_84 = f_3020(Inherit + 1000*(3),
                                                                                                       Inherit)
                                                                                     function f_3019 (a_2970,
                                                                                                      a_2971) {
                                                                                         var x_2972 = function () {
                                                                                                          var self_42 = LOCK(self_40)
                                                                                                          var d_90 = w2_8.setVisible(0)
                                                                                                          var d_91 = teest_12.setPosition({   tagName : 'position',
                                                                                                                                              x : 30,
                                                                                                                                              y : 150
                                                                                                                                          },
                                                                                                                                          Inherit,
                                                                                                                                          Inherit)
                                                                                                          var d_94 = teest_12.setSize({   tagName : 'size',
                                                                                                                                          width : 200,
                                                                                                                                          height : 200
                                                                                                                                      },
                                                                                                                                      Inherit,
                                                                                                                                      Inherit)
                                                                                                          var d_97 = teest_12.setTextColor({   tagName : 'color',
                                                                                                                                               r : 255,
                                                                                                                                               g : 0,
                                                                                                                                               b : 0
                                                                                                                                           },
                                                                                                                                           Inherit,
                                                                                                                                           Inherit)
                                                                                                          UNLOCK(self_42)
                                                                                                      }
                                                                                         return ASYNC(x_2972,
                                                                                                      a_2970,
                                                                                                      a_2971)
                                                                                     }
                                                                                     var d_89 = f_3019(Inherit + 1000*(4),
                                                                                                       Inherit)
                                                                                     function f_3018 (a_2978,
                                                                                                      a_2979) {
                                                                                         var x_2980 = function () {
                                                                                                          var self_43 = LOCK(self_40)
                                                                                                          var d_102 = button_11.installMouseListener(function (a_2974,
                                                                                                                                                               a_2975) { return moveUp2_26(c1_9,
                                                                                                                                                                                           a_2974,
                                                                                                                                                                                           a_2975) },
                                                                                                                                                     0)
                                                                                                          var d_103 = w2_8.destroyWindow(0)
                                                                                                          var newbutton_44 = mkCocoaButton_CTButton(env_5,
                                                                                                                                                    0)
                                                                                                          var d_104 = newbutton_44.setPosition({   tagName : 'position',
                                                                                                                                                   x : 0,
                                                                                                                                                   y : 55
                                                                                                                                               },
                                                                                                                                               Inherit,
                                                                                                                                               Inherit)
                                                                                                          var d_107 = newbutton_44.setTitle("sec7add",
                                                                                                                                            Inherit,
                                                                                                                                            Inherit)
                                                                                                          var d_108 = w1_7.addComponent(newbutton_44,
                                                                                                                                        0)
                                                                                                          var d_109 = teest_12.setPosition({   tagName : 'position',
                                                                                                                                               x : 40,
                                                                                                                                               y : 150
                                                                                                                                           },
                                                                                                                                           Inherit,
                                                                                                                                           Inherit)
                                                                                                          var d_112 = w1_7.setFocus(button_11,
                                                                                                                                    Inherit,
                                                                                                                                    Inherit)
                                                                                                          UNLOCK(self_43)
                                                                                                      }
                                                                                         return ASYNC(x_2980,
                                                                                                      a_2978,
                                                                                                      a_2979)
                                                                                     }
                                                                                     var d_101 = f_3018(Inherit + 1000*(7),
                                                                                                        Inherit)
                                                                                     UNLOCK(self_40)
                                                                                 }
                                                                    return ASYNC(x_2985,
                                                                                 a_2983,
                                                                                 a_2984)
                                                                }
                                                                var d_68 = f_3021(Inherit + 1000*(4),
                                                                                  Inherit)
                                                                UNLOCK(self_39)
                                                            }
                                               return ASYNC(x_2990, a_2992, a_2993)
                                           }
    function loopIt_45 (cmp_46, a_2996, a_2997) {
        var x_2998 = function () {
                         var self_47 = LOCK(self_3)
                         var q_48 = cmp_46.getPosition(0)
                         var d_113 = cmp_46.setPosition({   tagName : 'position',
                                                            x : _sym_620_Prelude/* + */(q_48.x, 1),
                                                            y : _sym_620_Prelude/* + */(q_48.y, 1)
                                                        },
                                                        Inherit,
                                                        Inherit)
                         var d_116 = loopIt_45(cmp_46, Inherit + (200), Inherit)
                         UNLOCK(self_47)
                     }
        return ASYNC(x_2998, a_2996, a_2997)
    }
    self_3.count = 0
    var x_3016 = function (a_3013, a_3014) {
                     var x_3015 = function () {
                                      var self_49 = LOCK(self_3)
                                      var d_117 = loopIt_45(c2_10, Inherit, Inherit)
                                      var d_118 = button_11.setSize({   tagName : 'size',
                                                                        width : 108,
                                                                        height : 17
                                                                    },
                                                                    Inherit,
                                                                    Inherit)
                                      var d_121 = button_11.installMouseListener(function (a_3000,
                                                                                           a_3001) { return moveUp_13(c1_9,
                                                                                                                      a_3000,
                                                                                                                      a_3001) },
                                                                                 0)
                                      var d_122 = button_11.setTitle("prehandlZZZZ",
                                                                     Inherit,
                                                                     Inherit)
                                      var d_123 = teest_12.setSize({   tagName : 'size',
                                                                       width : 100,
                                                                       height : 50
                                                                   },
                                                                   Inherit,
                                                                   Inherit)
                                      var d_126 = teest_12.setPosition({   tagName : 'position',
                                                                           x : 0,
                                                                           y : 150
                                                                       },
                                                                       Inherit,
                                                                       Inherit)
                                      var d_129 = teest_12.setText("TEZT", Inherit, Inherit)
                                      var d_130 = c1_9.setSize({   tagName : 'size',
                                                                   width : 100,
                                                                   height : 100
                                                               },
                                                               Inherit,
                                                               Inherit)
                                      var d_133 = c2_10.setSize({   tagName : 'size',
                                                                    width : 180,
                                                                    height : 140
                                                                },
                                                                Inherit,
                                                                Inherit)
                                      var d_136 = c2_10.setPosition({   tagName : 'position',
                                                                        x : 0,
                                                                        y : 0
                                                                    },
                                                                    Inherit,
                                                                    Inherit)
                                      var d_139 = c2_10.setBackgroundColor({   tagName : 'color',
                                                                               r : 0,
                                                                               g : 255,
                                                                               b : 0
                                                                           },
                                                                           Inherit,
                                                                           Inherit)
                                      var d_143 = w1_7.addComponent(teest_12, 0)
                                      var d_144 = w1_7.addComponent(c1_9, 0)
                                      var d_145 = w1_7.addComponent(c2_10, 0)
                                      var d_146 = w1_7.installWindowListener(function (a_3003,
                                                                                       a_3004) { return react_18(w1_7,
                                                                                                                 a_3003,
                                                                                                                 a_3004) },
                                                                             0)
                                      var d_147 = w2_8.installWindowListener(function (a_3006,
                                                                                       a_3007) { return reactor_22(w2_8,
                                                                                                                   a_3006,
                                                                                                                   a_3007) },
                                                                             0)
                                      var d_148 = c2_10.addComponent(button_11, 0)
                                      var d_149 = osx_6.startApplication(applicationDidFinishLaunching_37,
                                                                         0)
                                      UNLOCK(self_49)
                                  }
                     return ASYNC(x_3015, a_3013, a_3014)
                 }
    return x_3016
}