function cocoaApplication_CTApplication (d_1437) {
    var self_2 = { LOCKED: false }
    function updateList_6 (key_7, self_8) {
        if (elem_Prelude(eqCocoaKey_CTCommon, key_7, self_8.modifiers)) {
            var self_9 = self_8
            function f_1391 (a_44) {
                var x_1438 = []
                while (1) {
                    if (a_44.isNil()) {
                        return x_1438
                    } else {
                        var x_45 = a_44[0]
                        var x_46 = a_44.slice(1)
                        if (compareKeys_CTCommon(x_45, key_7)) {
                            x_1438.push(x_45)
                            a_44 = x_46
                            continue
                        } else {
                            a_44 = x_46
                            continue
                        }
                    }
                }
            }
            self_9.modifiers = f_1391(self_9.modifiers)
        } else {
            var self_11 = self_8
            self_11.modifiers = [key_7].concat(self_11.modifiers)
        }
    }
    function sendToWindow_12 (recvEvent_13,
                              windowId_14,
                              a_1396,
                              a_1397) {
        var x_1398 = function () {
                         var self_15 = LOCK(self_2)
                         var d_47 = forallListUnit_Prelude(function (a_1392, a_1393) {
                                                               var x_48 = a_1392.getId(0)
                                                               if (_sym_635_Prelude/* == */(x_48,
                                                                                            windowId_14)) {
                                                                   var self_18 = a_1393
                                                                   var d_49 = a_1392.handleEvent(recvEvent_13,
                                                                                                 self_18.modifiers,
                                                                                                 0)
                                                               } else {
                                                                   var self_19 = a_1393
                                                               }
                                                           },
                                                           self_15.activeWindows,
                                                           self_15)
                         UNLOCK(self_15)
                     }
        return ASYNC(x_1398, a_1396, a_1397)
    }
    var eventDispatcher_20 = function (a_1409,
                                       a_1410,
                                       a_1411,
                                       a_1412) {
                                 switch (a_1409.tagName) {
                                   case 'keyevent': {
                                     var x_62 = a_1409.a
                                     var x_1403 = function () {
                                                      var self_23 = LOCK(self_2)
                                                      switch (x_62.tagName) {
                                                        case 'keypressed': {
                                                          var x_60 = x_62.a
                                                          var x_52 = self_23
                                                          switch (x_60) {
                                                            case 'tab': {
                                                              var d_54 = updateList_6(x_60, x_52)
                                                              break
                                                              break
                                                            }
                                                            case 'shift': {
                                                              var d_55 = updateList_6(x_60, x_52)
                                                              break
                                                              break
                                                            }
                                                            case 'control': {
                                                              var d_56 = updateList_6(x_60, x_52)
                                                              break
                                                              break
                                                            }
                                                            case 'command': {
                                                              var d_57 = updateList_6(x_60, x_52)
                                                              break
                                                              break
                                                            }
                                                            default: break
                                                          }
                                                          var d_59 = sendToWindow_12({   tagName : 'keyevent',
                                                                                         a : x_62
                                                                                     },
                                                                                     a_1410,
                                                                                     Inherit,
                                                                                     Inherit)
                                                          UNLOCK(self_23)
                                                          break
                                                        }
                                                        default: {
                                                          RAISE(1)
                                                        }
                                                      }
                                                  }
                                     return ASYNC(x_1403, a_1411, a_1412)
                                     break
                                   }
                                   default: {
                                     var x_1408 = function () {
                                                      var self_32 = LOCK(self_2)
                                                      var d_61 = sendToWindow_12(a_1409,
                                                                                 a_1410,
                                                                                 Inherit,
                                                                                 Inherit)
                                                      UNLOCK(self_32)
                                                  }
                                     return ASYNC(x_1408, a_1411, a_1412)
                                   }
                                 }
                             }
    var getApplicationState_33 = function (a_1415) {
                                     var self_34 = LOCK(self_2)
                                     UNLOCK(self_34)
                                     return 'running'
                                 }
    var setEnv_35 = function (a_1418, a_1419) {
                        var self_37 = LOCK(self_2)
                        self_37.env = {   tagName : 'just',
                                          a : a_1418
                                      }
                        UNLOCK(self_37)
                    }
    var x_1424 = eventDispatcher_20
    var x_1429 = getApplicationState_33
    var x_1431 = setEnv_35
    var this_39 = {}
    var showWindow_38 = function (a_1422, a_1423) {
                            var self_41 = LOCK(self_2)
                            var d_63 = a_1422.initWindow(this_39, 0)
                            self_41.activeWindows = [a_1422].concat(self_41.activeWindows)
                            UNLOCK(self_41)
                        }
    var x_1434 = showWindow_38
    this_39 = UPDATE(this_39, {   tagName : 'app',
                                  eventDispatcher : function (a_1425, a_1426, a_1427, a_1428) {
                                      return x_1424(a_1425, a_1426, a_1427, a_1428)
                                  },
                                  getApplicationState : function (a_1430) {
                                      return x_1429(a_1430)
                                  },
                                  setEnv : function (a_1432, a_1433) {
                                      return x_1431(a_1432, a_1433)
                                  },
                                  showWindow : function (a_1435, a_1436) {
                                      return x_1434(a_1435, a_1436)
                                  }
                              })
    self_2.activeWindows = []
    self_2.modifiers = []
    self_2.env = 'nothing'
    return this_39
}