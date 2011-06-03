function root_Test (w_2, d_905) {
    var self_3 = { LOCKED: false }
    var env_4 = posix_POSIX(w_2, 0)
    var osx_5 = cocoa_COCOA(w_2, 0)
    var printApplicationState_6 = function (a_871, a_872) {
                                      var x_870 = function () {
                                                      var self_7 = LOCK(self_3)
                                                      var p_8 = osx_5.getApplicationState(0)
                                                      switch (p_8) {
                                                        case 'running': {
                                                          var self_9 = self_7
                                                          var d_29 = env_4.stdout.write("ApplicationState: Running\n",
                                                                                        0)
                                                          UNLOCK(self_7)
                                                          break
                                                        }
                                                        case 'stopped': {
                                                          var self_10 = self_7
                                                          var d_30 = env_4.stdout.write("ApplicationState: Stopped\n",
                                                                                        0)
                                                          UNLOCK(self_7)
                                                          break
                                                        }
                                                      }
                                                  }
                                      return ASYNC(x_870, a_871, a_872)
                                  }
    function printComponentList_12 (window_13, a_877, a_878) {
        var x_879 = function () {
                        var self_14 = LOCK(self_3)
                        var d_32 = env_4.stdout.write("---\n", 0)
                        var d_33 = forallListUnit_Prelude(function (a_873, a_874) {
                                                              var d_34 = env_4.stdout.write("found a component in list!\n",
                                                                                            0)
                                                          },
                                                          window_13.myComponents,
                                                          self_14)
                        var d_35 = env_4.stdout.write("---\n", 0)
                        UNLOCK(self_14)
                    }
        return ASYNC(x_879, a_877, a_878)
    }
    var printWindowList_17 = function (a_887, a_888) {
                                 var x_886 = function () {
                                                 var self_18 = LOCK(self_3)
                                                 var d_36 = forallListUnit_Prelude(function (a_880,
                                                                                             a_881) {
                                                                                       var d_37 = env_4.stdout.write("window detected in list!\n",
                                                                                                                     0)
                                                                                   },
                                                                                   osx_5.windows,
                                                                                   self_18)
                                                 var d_38 = env_4.stdout.write("no more windows..\n",
                                                                               0)
                                                 UNLOCK(self_18)
                                             }
                                 return ASYNC(x_886, a_887, a_888)
                             }
    var x_904 = function (a_901, a_902) {
                    var x_903 = function () {
                                    var self_21 = LOCK(self_3)
                                    var d_39 = osx_5.startApplication(Inherit, Inherit)
                                    var window_22 = mkNSWindow_NSTest(0)
                                    var d_40 = printWindowList_17(Inherit, Inherit)
                                    function f_907 (a_896, a_897) {
                                        var x_898 = function () {
                                                        var self_23 = LOCK(self_21)
                                                        var window2_24 = mkNSWindow_NSTest(0)
                                                        var window3_25 = mkNSWindow_NSTest(0)
                                                        var button2_26 = mkButton_NSTest(0)
                                                        var d_42 = window_22.addButton(button2_26,
                                                                                       Inherit,
                                                                                       Inherit)
                                                        var button_27 = mkButton_NSTest(0)
                                                        var d_43 = window2_24.addButton(button_27,
                                                                                        Inherit,
                                                                                        Inherit)
                                                        var d_44 = printApplicationState_6(Inherit,
                                                                                           Inherit)
                                                        var d_45 = printComponentList_12(window_22,
                                                                                         Inherit,
                                                                                         Inherit)
                                                        function f_906 (a_891, a_892) {
                                                            var x_893 = function () {
                                                                            var self_28 = LOCK(self_23)
                                                                            var d_47 = printWindowList_17(Inherit,
                                                                                                          Inherit)
                                                                            var d_48 = button_27.setTitle("Hello",
                                                                                                          Inherit,
                                                                                                          Inherit)
                                                                            var d_49 = printComponentList_12(window_22,
                                                                                                             Inherit,
                                                                                                             Inherit)
                                                                            UNLOCK(self_28)
                                                                        }
                                                            return ASYNC(x_893, a_891, a_892)
                                                        }
                                                        var d_46 = f_906(Inherit + 1000*(2),
                                                                         Inherit)
                                                        UNLOCK(self_23)
                                                    }
                                        return ASYNC(x_898, a_896, a_897)
                                    }
                                    var d_41 = f_907(Inherit + 1000*(2), Inherit)
                                    UNLOCK(self_21)
                                }
                    return ASYNC(x_903, a_901, a_902)
                }
    return x_904
}