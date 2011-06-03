function root_LockTest (w_2, d_272) {
    var self_3 = { LOCKED: false }
    var env_4 = posix_POSIX(w_2, 0)
    var osx_5 = cocoa_COCOA(w_2, 0)
    var x_271 = function (a_268, a_269) {
                    var x_270 = function () {
                                    var self_6 = LOCK(self_3)
                                    var superTest_7 = {   tagName : 'keyevent',
                                                          a : {   tagName : 'keypressed',
                                                                  a : 'tab'
                                                              }
                                                      }
                                    UNLOCK(self_6)
                                }
                    return ASYNC(x_270, a_268, a_269)
                }
    return x_271
}