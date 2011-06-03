function c_322_NSButton (v_324) {
    return v_324
}
function c_325_NSButton (v_327) {
    return v_327
}
function c_329_NSButton (a_328) {
    return a_328
}
function c_331_NSButton (a_330) {
    return a_330
}
function c_333_NSButton (a_332) {
    return a_332
}
function mkButton_NSButton (env_8, d_1418) {
    var self_9 = { LOCKED: false }
    var id_15 = mkCocoaID_NSTest(0)
    var setTitle_16 = function (a_1334, a_1335, a_1336) {
                          var x_1333 = function () {
                                           var self_18 = LOCK(self_9)
                                           self_18.title = a_1334
                                           switch (self_18.myState) {
                                             case 'active': {
                                               var self_19 = self_18
                                               var d_57 = buttonSetTitle_NSButton(id_15,
                                                                                  a_1334,
                                                                                  Inherit,
                                                                                  Inherit)
                                               UNLOCK(self_18)
                                               break
                                             }
                                             default: var self_20 = self_18
                                                      UNLOCK(self_18)
                                           }
                                       }
                          return ASYNC(x_1333, a_1335, a_1336)
                      }
    var getTitle_21 = function (a_1340) {
                          var self_22 = LOCK(self_9)
                          var x_1337 = self_22.title
                          UNLOCK(self_22)
                          return x_1337
                      }
    var setPosition_23 = function (a_1346, a_1347, a_1348) {
                             var x_1345 = function () {
                                              var self_25 = LOCK(self_9)
                                              switch (self_25.myState) {
                                                case 'active': {
                                                  var d_60 = buttonSetPosition_NSButton(id_15,
                                                                                        a_1346,
                                                                                        Inherit,
                                                                                        Inherit)
                                                  break
                                                  break
                                                }
                                                default: break
                                              }
                                              self_25.position = a_1346
                                              UNLOCK(self_25)
                                          }
                             return ASYNC(x_1345, a_1347, a_1348)
                         }
    var getPosition_28 = function (a_1352) {
                             var self_29 = LOCK(self_9)
                             var x_1349 = self_29.position
                             UNLOCK(self_29)
                             return x_1349
                         }
    var setSize_30 = function (a_1358, a_1359, a_1360) {
                         var x_1357 = function () {
                                          var self_32 = LOCK(self_9)
                                          self_32.size = a_1358
                                          UNLOCK(self_32)
                                      }
                         return ASYNC(x_1357, a_1359, a_1360)
                     }
    var getSize_33 = function (a_1364) {
                         var self_34 = LOCK(self_9)
                         var x_1361 = self_34.size
                         UNLOCK(self_34)
                         return x_1361
                     }
    var destroy_35 = function (a_1367) {
                         var self_36 = LOCK(self_9)
                         self_36.myState = 'destroyed'
                         UNLOCK(self_36)
                     }
    var installMouseListener_37 = function (a_1372, a_1373) {
                                      var self_39 = LOCK(self_9)
                                      self_39.mouseEventHandler = {   tagName : 'just',
                                                                      a : a_1372
                                                                  }
                                      UNLOCK(self_39)
                                  }
    var handleMouseEvent_40 = function (a_1376, a_1377, a_1378) {
                                  switch (a_1377) {
                                    case 'nothing': {
                                      return false
                                      break
                                    }
                                    default: var x_65 = a_1377.a
                                             var x_64 = x_65(a_1376, 0)
                                             return x_64
                                  }
                              }
    var handleEvent_47 = function (a_1383, a_1384) {
                             switch (a_1383.tagName) {
                               case 'mouseevent': {
                                 var x_69 = a_1383.a
                                 var self_49 = LOCK(self_9)
                                 var x_67 = handleMouseEvent_40(x_69,
                                                                self_49.mouseEventHandler,
                                                                self_49)
                                 UNLOCK(self_49)
                                 return x_67
                                 break
                               }
                               default: {
                                 var self_50 = LOCK(self_9)
                                 UNLOCK(self_50)
                                 return false
                               }
                             }
                         }
    function inithelper_51 (self_52) {
        var d_70 = buttonSetTitle_NSButton(id_15,
                                           self_52.title,
                                           Inherit,
                                           Inherit)
        var d_71 = buttonSetPosition_NSButton(id_15,
                                              self_52.position,
                                              Inherit,
                                              Inherit)
    }
    var x_1389 = getPosition_28
    var x_1391 = setPosition_23
    var x_1395 = getSize_33
    var x_1397 = setSize_30
    var x_1401 = handleEvent_47
    var x_1404 = destroy_35
    var x_1409 = installMouseListener_37
    var x_1412 = getTitle_21
    var x_1414 = setTitle_16
    var this_54 = {}
    var init_53 = function (a_1387, a_1388) {
                      var self_56 = LOCK(self_9)
                      self_56.myState = 'active'
                      var d_72 = initButton_NSButton(this_54, a_1387, 0)
                      var d_73 = inithelper_51(self_56)
                      UNLOCK(self_56)
                  }
    var x_1406 = init_53
    this_54 = UPDATE(this_54, {   tagName : 'button',
                                  getPosition : function (a_1390) {
                                      return x_1389(a_1390)
                                  },
                                  setPosition : function (a_1392, a_1393, a_1394) {
                                      return x_1391(a_1392, a_1393, a_1394)
                                  },
                                  getSize : function (a_1396) {
                                      return x_1395(a_1396)
                                  },
                                  setSize : function (a_1398, a_1399, a_1400) {
                                      return x_1397(a_1398, a_1399, a_1400)
                                  },
                                  handleEvent : function (a_1402, a_1403) {
                                      return x_1401(a_1402, a_1403)
                                  },
                                  destroy : function (a_1405) {
                                      return x_1404(a_1405)
                                  },
                                  id : id_15,
                                  init : function (a_1407, a_1408) {
                                      return x_1406(a_1407, a_1408)
                                  },
                                  installMouseListener : function (a_1410, a_1411) {
                                      return x_1409(a_1410, a_1411)
                                  },
                                  getTitle : function (a_1413) {
                                      return x_1412(a_1413)
                                  },
                                  setTitle : function (a_1415, a_1416, a_1417) {
                                      return x_1414(a_1415, a_1416, a_1417)
                                  }
                              })
    self_9.myState = 'inactive'
    self_9.position = {   tagName : 'position',
                          x : 0,
                          y : 0
                      }
    self_9.size = {   tagName : 'size',
                      width : 0,
                      height : 0
                  }
    self_9.mouseEventHandler = 'nothing'
    self_9.title = "TestButton"
    return this_54
}