function cocoaApplication_NSTest (d_529) {
    var self_2 = { LOCKED: false }
    function eventDispatcher_4 (c_5, id_6, a_510, a_511) {
        var x_512 = function () {
                        var self_7 = LOCK(self_2)
                        var d_19 = forallListUnit_Prelude(function (a_506, a_507) {
                                                              var x_20 = a_506.getId(0)
                                                              if (_sym_635_Prelude/* == */(x_20,
                                                                                           id_6)) {
                                                                  var self_10 = a_507
                                                                  var d_21 = a_506.handleEvent(c_5,
                                                                                               0)
                                                              } else {
                                                                  var self_11 = a_507
                                                              }
                                                          },
                                                          self_7.activeWindows,
                                                          self_7)
                        UNLOCK(self_7)
                    }
        return ASYNC(x_512, a_510, a_511)
    }
    var getApplicationState_12 = function (a_515) {
                                     var self_13 = LOCK(self_2)
                                     UNLOCK(self_13)
                                     return 'running'
                                 }
    var x_524 = getApplicationState_12
    var this_15 = {}
    var showWindow_14 = function (a_518, a_519) {
                            var self_17 = LOCK(self_2)
                            var superTest_18 = {   tagName : 'windowevent',
                                                   a : 'windowclosed'
                                               }
                            var d_22 = eventDispatcher_4(superTest_18, 5, Inherit, Inherit)
                            var d_23 = a_518.initWindow(this_15, 0)
                            self_17.activeWindows = [a_518].concat(self_17.activeWindows)
                            UNLOCK(self_17)
                        }
    var x_526 = showWindow_14
    this_15 = UPDATE(this_15, {   tagName : 'app',
                                  eventDispatcher : function (a_520, a_521, a_522, a_523) {
                                      return eventDispatcher_4(a_520, a_521, a_522, a_523)
                                  },
                                  getApplicationState : function (a_525) {
                                      return x_524(a_525)
                                  },
                                  showWindow : function (a_527, a_528) {
                                      return x_526(a_527, a_528)
                                  }
                              })
    self_2.activeWindows = []
    return this_15
}