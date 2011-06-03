function root_CocoaTest (w_2, d_232) {
    var self_3 = { LOCKED: false }
    var env_4 = posix_POSIX(w_2, 0)
    var osx_5 = cocoa_Cocoa(w_2, 0)
    var x_231 = function (a_228, a_229) {
                    var x_230 = function () {
                                    var self_6 = LOCK(self_3)
                                    var d_7 = env_4.stdout.write("Timber: Calling showWindow\n", 0)
                                    var d_8 = osx_5.showWindow(Inherit, Inherit)
                                    var d_9 = env_4.stdout.write("Timber: Window gone?\n", 0)
                                    UNLOCK(self_6)
                                }
                    return ASYNC(x_230, a_228, a_229)
                }
    return x_231
}