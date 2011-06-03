function root_Paint (w_2, d_1235) {
    var self_3 = { LOCKED: false }
    var env_5 = posix_POSIX(w_2, 0)
    var osx_6 = cocoa_COCOA(w_2, 0)
    var w1_7 = mkWindow_CTWindow(env_5, 0)
    var c2_8 = mkContainer_CTContainer(env_5, 0)
    var button_9 = mkCocoaButton_CTButton(env_5, 0)
    var button2_10 = mkCocoaButton_CTButton(env_5, 0)
    var label_11 = mkCocoaLabel_CTLabel(0)
    function posget_12 (a_27) {
        switch (a_27.tagName) {
          case 'mousepressed': {
            var x_28 = a_27.a
            return x_28
            break
          }
          case 'mousereleased': {
            var x_29 = a_27.a
            return x_29
            break
          }
          case 'mouseclicked': {
            var x_30 = a_27.a
            return x_30
            break
          }
          default: {
            RAISE(1)
          }
        }
    }
    var drawPixel_16 = function (a_1212, a_1213, a_1214) {
                           var self_19 = LOCK(self_3)
                           var blackBox_20 = mkContainer_CTContainer(env_5, 0)
                           var d_31 = blackBox_20.setSize({   tagName : 'size',
                                                              width : 5,
                                                              height : 5
                                                          },
                                                          Inherit,
                                                          Inherit)
                           var d_34 = label_11.setText(_sym_20_Prelude/* ++ */("Pixel Count: ",
                                                                               show_723_Prelude(self_19.pixelCount)),
                                                       Inherit,
                                                       Inherit)
                           var pos_21 = posget_12(a_1213)
                           var d_35 = blackBox_20.setBackgroundColor({   tagName : 'color',
                                                                         r : pos_21.x % 255,
                                                                         g : pos_21.y % 255,
                                                                         b : (2 * (pos_21.y - pos_21.x)) % 255
                                                                     },
                                                                     Inherit,
                                                                     Inherit)
                           var d_39 = blackBox_20.setPosition(pos_21, Inherit, Inherit)
                           self_19.pixelCount = _sym_620_Prelude/* + */(1, self_19.pixelCount)
                           function f_1236 (a_1207, a_1208) {
                               var x_1209 = function () {
                                                var self_22 = LOCK(self_19)
                                                var d_41 = w1_7.addComponent(blackBox_20, 0)
                                                UNLOCK(self_22)
                                            }
                               return ASYNC(x_1209, a_1207, a_1208)
                           }
                           var d_40 = f_1236(Inherit + (100), Inherit)
                           UNLOCK(self_19)
                           return true
                       }
    var applicationDidFinishLaunching_23 = function (a_1220,
                                                     a_1221,
                                                     a_1222) {
                                               var x_1219 = function () {
                                                                var self_25 = LOCK(self_3)
                                                                var d_42 = a_1220.setEnv(env_5, 0)
                                                                var d_43 = a_1220.showWindow(w1_7,
                                                                                             0)
                                                                UNLOCK(self_25)
                                                            }
                                               return ASYNC(x_1219, a_1221, a_1222)
                                           }
    self_3.pixelCount = 0
    var x_1234 = function (a_1231, a_1232) {
                     var x_1233 = function () {
                                      var self_26 = LOCK(self_3)
                                      var d_44 = label_11.setSize({   tagName : 'size',
                                                                      width : 300,
                                                                      height : 50
                                                                  },
                                                                  Inherit,
                                                                  Inherit)
                                      var d_47 = label_11.setPosition({   tagName : 'position',
                                                                          x : 50,
                                                                          y : 200
                                                                      },
                                                                      Inherit,
                                                                      Inherit)
                                      var d_50 = label_11.setText("PainTimber. Paint slowly or I will segfault. :(",
                                                                  Inherit,
                                                                  Inherit)
                                      var d_51 = w1_7.addComponent(label_11, 0)
                                      var d_52 = w1_7.installMouseListener(function (a_1224,
                                                                                     a_1225) { return drawPixel_16(c2_8,
                                                                                                                   a_1224,
                                                                                                                   a_1225) },
                                                                           0)
                                      var d_53 = osx_6.startApplication(applicationDidFinishLaunching_23,
                                                                        0)
                                      UNLOCK(self_26)
                                  }
                     return ASYNC(x_1233, a_1231, a_1232)
                 }
    return x_1234
}