#include "FocusTest.h"
 
struct S_461;
typedef struct S_461 *S_461;
struct T_1858;
typedef struct T_1858 *T_1858;
struct T_1857;
typedef struct T_1857 *T_1857;
struct T_1856;
typedef struct T_1856 *T_1856;
struct T_1855;
typedef struct T_1855 *T_1855;
struct T_1854;
typedef struct T_1854 *T_1854;
struct T_1853;
typedef struct T_1853 *T_1853;
struct T_1852;
typedef struct T_1852 *T_1852;
struct T_1851;
typedef struct T_1851 *T_1851;
struct T_1850;
typedef struct T_1850 *T_1850;
struct T_1849;
typedef struct T_1849 *T_1849;
struct T_1848;
typedef struct T_1848 *T_1848;
struct T_1847;
typedef struct T_1847 *T_1847;
 
struct S_461 {
    POLY GCINFO;
    Bool block_4;
};
struct T_1858 {
    POLY GCINFO;
    Bool (*Code) (T_1858, KeyEventType_CTCommon, Int);
    CLOS tabStop_18;
};
struct T_1857 {
    POLY GCINFO;
    TUP0 (*Code) (T_1857);
    AbsTime baseline;
    AbsTime deadline;
    Msg next;
    CLOS applicationDidFinishLaunching_24;
    CLOS tabStop_18;
    Button_CTButton button2_10;
    Button_CTButton button_9;
    Container_CTContainer c2_8;
    CocoaWindow_CTCommon w1_7;
    Env_COCOA osx_6;
    Ref self_3;
};
struct T_1856 {
    POLY GCINFO;
    Msg (*Code) (T_1856, Time, Time);
    CLOS applicationDidFinishLaunching_24;
    CLOS tabStop_18;
    Button_CTButton button2_10;
    Button_CTButton button_9;
    Container_CTContainer c2_8;
    CocoaWindow_CTCommon w1_7;
    Env_COCOA osx_6;
    Ref self_3;
};
struct T_1855 {
    POLY GCINFO;
    TUP0 (*Code) (T_1855);
    AbsTime baseline;
    AbsTime deadline;
    Msg next;
    Ref self_26;
    Container_CTContainer c2_8;
    Env_POSIX env_5;
};
struct T_1854 {
    POLY GCINFO;
    Bool (*Code) (T_1854, MouseEventType_CTCommon, Int);
    CLOS doNothing_21;
};
struct T_1853 {
    POLY GCINFO;
    Bool (*Code) (T_1853, MouseEventType_CTCommon, Int);
    Int x_42;
    App_CTCommon a_1829;
    CLOS tabClick_11;
};
struct T_1852 {
    POLY GCINFO;
    TUP0 (*Code) (T_1852);
    AbsTime baseline;
    AbsTime deadline;
    Msg next;
    App_CTCommon a_1829;
    CLOS doNothing_21;
    CLOS tabClick_11;
    Button_CTButton button2_10;
    Button_CTButton button_9;
    Container_CTContainer c2_8;
    CocoaWindow_CTCommon w1_7;
    Env_POSIX env_5;
    Ref self_3;
};
struct T_1851 {
    POLY GCINFO;
    Msg (*Code) (T_1851, App_CTCommon, Time, Time);
    CLOS doNothing_21;
    CLOS tabClick_11;
    Button_CTButton button2_10;
    Button_CTButton button_9;
    Container_CTContainer c2_8;
    CocoaWindow_CTCommon w1_7;
    Env_POSIX env_5;
    Ref self_3;
};
struct T_1850 {
    POLY GCINFO;
    Bool (*Code) (T_1850, BITS32, POLY, Int);
    Ref self_3;
};
struct T_1849 {
    POLY GCINFO;
    LIST (*Code) (T_1849);
    Ref self_20;
};
struct T_1848 {
    POLY GCINFO;
    Bool (*Code) (T_1848, BITS32, POLY, Int);
    Env_POSIX env_5;
    Ref self_3;
};
struct T_1847 {
    POLY GCINFO;
    Bool (*Code) (T_1847, BITS32, App_CTCommon, Int, POLY, Int);
    Env_POSIX env_5;
    Ref self_3;
};
 
static WORD __GC__S_461[];
static WORD __GC__T_1858[];
static WORD __GC__T_1857[];
static WORD __GC__T_1856[];
static WORD __GC__T_1855[];
static WORD __GC__T_1854[];
static WORD __GC__T_1853[];
static WORD __GC__T_1852[];
static WORD __GC__T_1851[];
static WORD __GC__T_1850[];
static WORD __GC__T_1849[];
static WORD __GC__T_1848[];
static WORD __GC__T_1847[];
static Msg f_1846 (Ref self_26,
                   Container_CTContainer c2_8,
                   Env_POSIX env_5,
                   Time a_1821,
                   Time a_1822);
static Bool f_1869 (T_1847 this_1860,
                    BITS32 a_1865,
                    App_CTCommon a_1795,
                    Int a_1796,
                    POLY a_1797,
                    Int a_1798);
static LIST f_1875 (T_1849 this_1874);
static Bool f_1878 (T_1848 this_1870,
                    BITS32 a_1873,
                    POLY a_1802,
                    Int a_1803);
static Bool f_1883 (T_1850 this_1879,
                    BITS32 a_1882,
                    POLY a_1806,
                    Int a_1807);
static Bool f_1898 (T_1853 this_1894,
                    MouseEventType_CTCommon a_1809,
                    Int a_1810);
static Bool f_1906 (T_1854 this_1902,
                    MouseEventType_CTCommon a_1813,
                    Int a_1814);
static Bool f_1913 (T_1854 this_1909,
                    MouseEventType_CTCommon a_1817,
                    Int a_1818);
static TUP0 f_1923 (T_1852 this_1888);
static Msg f_1924 (T_1851 this_1884,
                   App_CTCommon a_1829,
                   Time a_1830,
                   Time a_1831);
static Bool f_1937 (T_1858 this_1933,
                    KeyEventType_CTCommon a_1834,
                    Int a_1835);
static TUP0 f_1951 (T_1857 this_1928);
static Msg f_1952 (T_1856 this_1925, Time a_1841, Time a_1842);
static TUP0 f_1962 (T_1855 this_1953);
 
static WORD __GC__S_461[] = {WORDS(sizeof(struct S_461)), 0, 0};
static WORD __GC__T_1858[] = {WORDS(sizeof(struct T_1858)),
                              0,
                              WORDS(offsetof(struct T_1858, tabStop_18)),
                              0};
static WORD __GC__T_1857[] = {WORDS(sizeof(struct T_1857)),
                              0,
                              WORDS(offsetof(struct T_1857, applicationDidFinishLaunching_24)),
                              WORDS(offsetof(struct T_1857, tabStop_18)),
                              WORDS(offsetof(struct T_1857, button2_10)),
                              WORDS(offsetof(struct T_1857, button_9)),
                              WORDS(offsetof(struct T_1857, c2_8)),
                              WORDS(offsetof(struct T_1857, w1_7)),
                              WORDS(offsetof(struct T_1857, osx_6)),
                              WORDS(offsetof(struct T_1857, self_3)),
                              0};
static WORD __GC__T_1856[] = {WORDS(sizeof(struct T_1856)),
                              0,
                              WORDS(offsetof(struct T_1856, applicationDidFinishLaunching_24)),
                              WORDS(offsetof(struct T_1856, tabStop_18)),
                              WORDS(offsetof(struct T_1856, button2_10)),
                              WORDS(offsetof(struct T_1856, button_9)),
                              WORDS(offsetof(struct T_1856, c2_8)),
                              WORDS(offsetof(struct T_1856, w1_7)),
                              WORDS(offsetof(struct T_1856, osx_6)),
                              WORDS(offsetof(struct T_1856, self_3)),
                              0};
static WORD __GC__T_1855[] = {WORDS(sizeof(struct T_1855)),
                              0,
                              WORDS(offsetof(struct T_1855, self_26)),
                              WORDS(offsetof(struct T_1855, c2_8)),
                              WORDS(offsetof(struct T_1855, env_5)),
                              0};
static WORD __GC__T_1854[] = {WORDS(sizeof(struct T_1854)),
                              0,
                              WORDS(offsetof(struct T_1854, doNothing_21)),
                              0};
static WORD __GC__T_1853[] = {WORDS(sizeof(struct T_1853)),
                              0,
                              WORDS(offsetof(struct T_1853, a_1829)),
                              WORDS(offsetof(struct T_1853, tabClick_11)),
                              0};
static WORD __GC__T_1852[] = {WORDS(sizeof(struct T_1852)),
                              0,
                              WORDS(offsetof(struct T_1852, a_1829)),
                              WORDS(offsetof(struct T_1852, doNothing_21)),
                              WORDS(offsetof(struct T_1852, tabClick_11)),
                              WORDS(offsetof(struct T_1852, button2_10)),
                              WORDS(offsetof(struct T_1852, button_9)),
                              WORDS(offsetof(struct T_1852, c2_8)),
                              WORDS(offsetof(struct T_1852, w1_7)),
                              WORDS(offsetof(struct T_1852, env_5)),
                              WORDS(offsetof(struct T_1852, self_3)),
                              0};
static WORD __GC__T_1851[] = {WORDS(sizeof(struct T_1851)),
                              0,
                              WORDS(offsetof(struct T_1851, doNothing_21)),
                              WORDS(offsetof(struct T_1851, tabClick_11)),
                              WORDS(offsetof(struct T_1851, button2_10)),
                              WORDS(offsetof(struct T_1851, button_9)),
                              WORDS(offsetof(struct T_1851, c2_8)),
                              WORDS(offsetof(struct T_1851, w1_7)),
                              WORDS(offsetof(struct T_1851, env_5)),
                              WORDS(offsetof(struct T_1851, self_3)),
                              0};
static WORD __GC__T_1850[] = {WORDS(sizeof(struct T_1850)),
                              0,
                              WORDS(offsetof(struct T_1850, self_3)),
                              0};
static WORD __GC__T_1849[] = {WORDS(sizeof(struct T_1849)),
                              0,
                              WORDS(offsetof(struct T_1849, self_20)),
                              0};
static WORD __GC__T_1848[] = {WORDS(sizeof(struct T_1848)),
                              0,
                              WORDS(offsetof(struct T_1848, env_5)),
                              WORDS(offsetof(struct T_1848, self_3)),
                              0};
static WORD __GC__T_1847[] = {WORDS(sizeof(struct T_1847)),
                              0,
                              WORDS(offsetof(struct T_1847, env_5)),
                              WORDS(offsetof(struct T_1847, self_3)),
                              0};
CLOS root_FocusTest (World w_2, Int d_1845) {
    Ref self_3;
    NEW (Ref, self_3, WORDS(sizeof(struct Ref))+
                      WORDS(sizeof(struct S_461)));
    INITREF(self_3);
    ((S_461)STATEOF(self_3))->GCINFO = __GC__S_461;
    Env_POSIX env_5;
    env_5 = posix_POSIX(w_2, 0);
    Env_COCOA osx_6;
    osx_6 = cocoa_COCOA(w_2, 0);
    CocoaWindow_CTCommon w1_7;
    w1_7 = mkWindow_CTWindow((BITS32)0, (POLY)env_5, 0);
    Container_CTContainer c2_8;
    c2_8 = mkContainer_CTContainer((BITS32)0, (POLY)env_5, 0);
    Button_CTButton button_9;
    button_9 = mkCocoaButton_CTButton(env_5, 0);
    Button_CTButton button2_10;
    button2_10 = mkCocoaButton_CTButton(env_5, 0);
    CLOS tabClick_11;
    NEW (CLOS, tabClick_11, WORDS(sizeof(struct T_1847)));
    ((T_1847)tabClick_11)->GCINFO = __GC__T_1847;
    ((T_1847)tabClick_11)->Code = f_1869;
    ((T_1847)tabClick_11)->env_5 = env_5;
    ((T_1847)tabClick_11)->self_3 = self_3;
    CLOS tabStop_18;
    NEW (CLOS, tabStop_18, WORDS(sizeof(struct T_1848)));
    ((T_1848)tabStop_18)->GCINFO = __GC__T_1848;
    ((T_1848)tabStop_18)->Code = f_1878;
    ((T_1848)tabStop_18)->env_5 = env_5;
    ((T_1848)tabStop_18)->self_3 = self_3;
    CLOS doNothing_21;
    NEW (CLOS, doNothing_21, WORDS(sizeof(struct T_1850)));
    ((T_1850)doNothing_21)->GCINFO = __GC__T_1850;
    ((T_1850)doNothing_21)->Code = f_1883;
    ((T_1850)doNothing_21)->self_3 = self_3;
    CLOS applicationDidFinishLaunching_24;
    NEW (CLOS, applicationDidFinishLaunching_24, WORDS(sizeof(struct T_1851)));
    ((T_1851)applicationDidFinishLaunching_24)->GCINFO = __GC__T_1851;
    ((T_1851)applicationDidFinishLaunching_24)->Code = f_1924;
    ((T_1851)applicationDidFinishLaunching_24)->doNothing_21 = doNothing_21;
    ((T_1851)applicationDidFinishLaunching_24)->tabClick_11 = tabClick_11;
    ((T_1851)applicationDidFinishLaunching_24)->button2_10 = button2_10;
    ((T_1851)applicationDidFinishLaunching_24)->button_9 = button_9;
    ((T_1851)applicationDidFinishLaunching_24)->c2_8 = c2_8;
    ((T_1851)applicationDidFinishLaunching_24)->w1_7 = w1_7;
    ((T_1851)applicationDidFinishLaunching_24)->env_5 = env_5;
    ((T_1851)applicationDidFinishLaunching_24)->self_3 = self_3;
    ((S_461)STATEOF(self_3))->block_4 = (Bool)0;
    CLOS x_1844;
    NEW (CLOS, x_1844, WORDS(sizeof(struct T_1856)));
    ((T_1856)x_1844)->GCINFO = __GC__T_1856;
    ((T_1856)x_1844)->Code = f_1952;
    ((T_1856)x_1844)->applicationDidFinishLaunching_24 = applicationDidFinishLaunching_24;
    ((T_1856)x_1844)->tabStop_18 = tabStop_18;
    ((T_1856)x_1844)->button2_10 = button2_10;
    ((T_1856)x_1844)->button_9 = button_9;
    ((T_1856)x_1844)->c2_8 = c2_8;
    ((T_1856)x_1844)->w1_7 = w1_7;
    ((T_1856)x_1844)->osx_6 = osx_6;
    ((T_1856)x_1844)->self_3 = self_3;
    return x_1844;
}
static Msg f_1846 (Ref self_26,
                   Container_CTContainer c2_8,
                   Env_POSIX env_5,
                   Time a_1821,
                   Time a_1822) {
    Msg x_1823;
    NEW (Msg, x_1823, WORDS(sizeof(struct T_1855)));
    ((T_1855)x_1823)->GCINFO = __GC__T_1855;
    ((T_1855)x_1823)->Code = f_1962;
    ((T_1855)x_1823)->self_26 = self_26;
    ((T_1855)x_1823)->c2_8 = c2_8;
    ((T_1855)x_1823)->env_5 = env_5;
    return (Msg)ASYNC(x_1823, a_1821, a_1822);
}
static Bool f_1869 (T_1847 this_1860,
                    BITS32 a_1865,
                    App_CTCommon a_1795,
                    Int a_1796,
                    POLY a_1797,
                    Int a_1798) {
    Ref self_15;
    self_15 = (Ref)LOCK((OID)this_1860->self_3);
    WFile_POSIX x_1866;
    x_1866 = this_1860->env_5->stdout_POSIX;
    Int d_32;
    d_32 = x_1866->write_POSIX(x_1866,
                               _sym_20_Prelude/* ++ */((BITS32)1,
                                                       getStr("Sending KeyPressed \"Tab\" to window with ID: "),
                                                       _sym_20_Prelude/* ++ */((BITS32)1,
                                                                               show_723_Prelude(a_1796),
                                                                               getStr("\n"))),
                               0);
    _KeyPressed_CTCommon x_1867;
    NEW (_KeyPressed_CTCommon, x_1867, WORDS(sizeof(struct _KeyPressed_CTCommon)));
    x_1867->GCINFO = __GC___KeyPressed_CTCommon;
    x_1867->Tag = 1;
    x_1867->a = (CocoaKey_CTCommon)0;
    CocoaEvent_CTCommon foo_16;
    NEW (CocoaEvent_CTCommon, foo_16, WORDS(sizeof(struct _KeyEvent_CTCommon)));
    ((_KeyEvent_CTCommon)foo_16)->GCINFO = __GC___KeyEvent_CTCommon;
    ((_KeyEvent_CTCommon)foo_16)->Tag = 0;
    ((_KeyEvent_CTCommon)foo_16)->a = (KeyEventType_CTCommon)x_1867;
    _KeyPressed_CTCommon x_1868;
    NEW (_KeyPressed_CTCommon, x_1868, WORDS(sizeof(struct _KeyPressed_CTCommon)));
    x_1868->GCINFO = __GC___KeyPressed_CTCommon;
    x_1868->Tag = 1;
    x_1868->a = (CocoaKey_CTCommon)78;
    CocoaEvent_CTCommon superTest_17;
    NEW (CocoaEvent_CTCommon, superTest_17, WORDS(sizeof(struct _KeyEvent_CTCommon)));
    ((_KeyEvent_CTCommon)superTest_17)->GCINFO = __GC___KeyEvent_CTCommon;
    ((_KeyEvent_CTCommon)superTest_17)->Tag = 0;
    ((_KeyEvent_CTCommon)superTest_17)->a = (KeyEventType_CTCommon)x_1868;
    Msg d_33;
    d_33 = a_1795->eventDispatcher_CTCommon(a_1795,
                                            superTest_17,
                                            a_1796,
                                            Inherit,
                                            Inherit);
    UNLOCK((OID)self_15);
    return (Bool)1;
}
static LIST f_1875 (T_1849 this_1874) {
    switch ((WORD)((S_461)STATEOF(this_1874->self_20))->block_4) {
        case 1: return getStr("Tab shall not pass!\n");
        case 0: return getStr("It\'s ok. Tab may continue.\n");
    }
}
static Bool f_1878 (T_1848 this_1870,
                    BITS32 a_1873,
                    POLY a_1802,
                    Int a_1803) {
    Ref self_20;
    self_20 = (Ref)LOCK((OID)this_1870->self_3);
    ((S_461)STATEOF(self_20))->block_4 = not_Prelude(((S_461)STATEOF(self_20))->block_4);
    CLOS x_1876;
    NEW (CLOS, x_1876, WORDS(sizeof(struct T_1849)));
    ((T_1849)x_1876)->GCINFO = __GC__T_1849;
    ((T_1849)x_1876)->Code = f_1875;
    ((T_1849)x_1876)->self_20 = self_20;
    WFile_POSIX x_1877;
    x_1877 = this_1870->env_5->stdout_POSIX;
    Int d_34;
    d_34 = x_1877->write_POSIX(x_1877,
                               ((LIST(*)(CLOS))(x_1876->Code))(x_1876),
                               0);
    Bool x_1799;
    x_1799 = ((S_461)STATEOF(self_20))->block_4;
    UNLOCK((OID)self_20);
    return x_1799;
}
static Bool f_1883 (T_1850 this_1879,
                    BITS32 a_1882,
                    POLY a_1806,
                    Int a_1807) {
    Ref self_23;
    self_23 = (Ref)LOCK((OID)this_1879->self_3);
    UNLOCK((OID)self_23);
    return (Bool)1;
}
static Bool f_1898 (T_1853 this_1894,
                    MouseEventType_CTCommon a_1809,
                    Int a_1810) {
    CLOS x_1897;
    x_1897 = this_1894->tabClick_11;
    return ((Bool(*)(CLOS, BITS32, App_CTCommon, Int, POLY, Int))(x_1897->Code))(x_1897,
                                                                                 (BITS32)0,
                                                                                 this_1894->a_1829,
                                                                                 this_1894->x_42,
                                                                                 (POLY)a_1809,
                                                                                 a_1810);
}
static Bool f_1906 (T_1854 this_1902,
                    MouseEventType_CTCommon a_1813,
                    Int a_1814) {
    CLOS x_1905;
    x_1905 = this_1902->doNothing_21;
    return ((Bool(*)(CLOS, BITS32, POLY, Int))(x_1905->Code))(x_1905,
                                                              (BITS32)0,
                                                              (POLY)a_1813,
                                                              a_1814);
}
static Bool f_1913 (T_1854 this_1909,
                    MouseEventType_CTCommon a_1817,
                    Int a_1818) {
    CLOS x_1912;
    x_1912 = this_1909->doNothing_21;
    return ((Bool(*)(CLOS, BITS32, POLY, Int))(x_1912->Code))(x_1912,
                                                              (BITS32)0,
                                                              (POLY)a_1817,
                                                              a_1818);
}
static TUP0 f_1923 (T_1852 this_1888) {
    Ref self_26;
    self_26 = (Ref)LOCK((OID)this_1888->self_3);
    App_CTCommon x_1889;
    x_1889 = this_1888->a_1829;
    TUP0 d_35;
    d_35 = x_1889->showWindow_CTCommon(x_1889, this_1888->w1_7, 0);
    App_CTCommon x_1890;
    x_1890 = this_1888->a_1829;
    TUP0 d_36;
    d_36 = x_1890->setEnv_CTCommon(x_1890, this_1888->env_5, 0);
    Button_CTButton tabButton_27;
    tabButton_27 = mkCocoaButton_CTButton(this_1888->env_5, 0);
    Msg d_37;
    d_37 = tabButton_27->setTitle_CTButton(tabButton_27,
                                           getStr("TAB"),
                                           Inherit,
                                           Inherit);
    Position_CTCommon x_1891;
    NEW (Position_CTCommon, x_1891, WORDS(sizeof(struct Position_CTCommon)));
    x_1891->GCINFO = __GC__Position_CTCommon;
    x_1891->x_CTCommon = 20;
    x_1891->y_CTCommon = 200;
    HasPosition_CTCommon x_1892;
    x_1892 = tabButton_27->l_Button_CTButton_Component_CTCommon_CTButton->l_Component_CTCommon_HasSize_CTCommon_CTCommon->l_HasSize_CTCommon_HasPosition_CTCommon_CTCommon;
    Msg d_38;
    d_38 = x_1892->setPosition_CTCommon(x_1892,
                                        x_1891,
                                        Inherit,
                                        Inherit);
    CocoaWindow_CTCommon x_1893;
    x_1893 = this_1888->w1_7;
    Int x_42;
    x_42 = x_1893->getId_CTCommon(x_1893, 0);
    T_1853 x_1899;
    NEW (T_1853, x_1899, WORDS(sizeof(struct T_1853)));
    x_1899->GCINFO = __GC__T_1853;
    x_1899->Code = f_1898;
    x_1899->x_42 = x_42;
    x_1899->a_1829 = this_1888->a_1829;
    x_1899->tabClick_11 = this_1888->tabClick_11;
    HandlesMouseEvents_CTCommon x_1900;
    x_1900 = tabButton_27->l_Button_CTButton_HandlesMouseEvents_CTCommon_CTButton;
    TUP0 d_41;
    d_41 = x_1900->installMouseListener_CTCommon(x_1900,
                                                 (CLOS)x_1899,
                                                 0);
    IsFocusable_CTCommon x_1901;
    x_1901 = tabButton_27->l_Button_CTButton_Component_CTCommon_CTButton->l_Component_CTCommon_IsFocusable_CTCommon_CTCommon;
    TUP0 d_43;
    d_43 = x_1901->setIsFocusable_CTCommon(x_1901, (Bool)0, 0);
    T_1854 x_1907;
    NEW (T_1854, x_1907, WORDS(sizeof(struct T_1854)));
    x_1907->GCINFO = __GC__T_1854;
    x_1907->Code = f_1906;
    x_1907->doNothing_21 = this_1888->doNothing_21;
    HandlesMouseEvents_CTCommon x_1908;
    x_1908 = this_1888->button_9->l_Button_CTButton_HandlesMouseEvents_CTCommon_CTButton;
    TUP0 d_44;
    d_44 = x_1908->installMouseListener_CTCommon(x_1908,
                                                 (CLOS)x_1907,
                                                 0);
    T_1854 x_1914;
    NEW (T_1854, x_1914, WORDS(sizeof(struct T_1854)));
    x_1914->GCINFO = __GC__T_1854;
    x_1914->Code = f_1913;
    x_1914->doNothing_21 = this_1888->doNothing_21;
    HandlesMouseEvents_CTCommon x_1915;
    x_1915 = this_1888->button2_10->l_Button_CTButton_HandlesMouseEvents_CTCommon_CTButton;
    TUP0 d_45;
    d_45 = x_1915->installMouseListener_CTCommon(x_1915,
                                                 (CLOS)x_1914,
                                                 0);
    ContainsComponents_CTCommon x_1916;
    x_1916 = this_1888->w1_7->l_CocoaWindow_CTCommon_ContainsComponents_CTCommon_CTCommon;
    TUP0 d_46;
    d_46 = x_1916->addComponent_CTCommon(x_1916,
                                         tabButton_27->l_Button_CTButton_Component_CTCommon_CTButton,
                                         0);
    Button_CTButton x_1917;
    x_1917 = this_1888->button_9;
    Msg d_47;
    d_47 = x_1917->setTitle_CTButton(x_1917,
                                     getStr("Move"),
                                     Inherit,
                                     Inherit);
    Position_CTCommon x_1918;
    NEW (Position_CTCommon, x_1918, WORDS(sizeof(struct Position_CTCommon)));
    x_1918->GCINFO = __GC__Position_CTCommon;
    x_1918->x_CTCommon = 20;
    x_1918->y_CTCommon = 20;
    HasPosition_CTCommon x_1919;
    x_1919 = this_1888->button_9->l_Button_CTButton_Component_CTCommon_CTButton->l_Component_CTCommon_HasSize_CTCommon_CTCommon->l_HasSize_CTCommon_HasPosition_CTCommon_CTCommon;
    Msg d_48;
    d_48 = x_1919->setPosition_CTCommon(x_1919,
                                        x_1918,
                                        Inherit,
                                        Inherit);
    Position_CTCommon x_1920;
    NEW (Position_CTCommon, x_1920, WORDS(sizeof(struct Position_CTCommon)));
    x_1920->GCINFO = __GC__Position_CTCommon;
    x_1920->x_CTCommon = 0;
    x_1920->y_CTCommon = 55;
    HasPosition_CTCommon x_1921;
    x_1921 = this_1888->button2_10->l_Button_CTButton_Component_CTCommon_CTButton->l_Component_CTCommon_HasSize_CTCommon_CTCommon->l_HasSize_CTCommon_HasPosition_CTCommon_CTCommon;
    Msg d_51;
    d_51 = x_1921->setPosition_CTCommon(x_1921,
                                        x_1920,
                                        Inherit,
                                        Inherit);
    Button_CTButton x_1922;
    x_1922 = this_1888->button2_10;
    Msg d_54;
    d_54 = x_1922->setTitle_CTButton(x_1922,
                                     getStr("sec7add"),
                                     Inherit,
                                     Inherit);
    Msg d_55;
    d_55 = f_1846(self_26,
                  this_1888->c2_8,
                  this_1888->env_5,
                  primTimePlus(Inherit, sec(2)),
                  Inherit);
    UNLOCK((OID)self_26);
    return (TUP0)0;
}
static Msg f_1924 (T_1851 this_1884,
                   App_CTCommon a_1829,
                   Time a_1830,
                   Time a_1831) {
    Msg x_1828;
    NEW (Msg, x_1828, WORDS(sizeof(struct T_1852)));
    ((T_1852)x_1828)->GCINFO = __GC__T_1852;
    ((T_1852)x_1828)->Code = f_1923;
    ((T_1852)x_1828)->a_1829 = a_1829;
    ((T_1852)x_1828)->doNothing_21 = this_1884->doNothing_21;
    ((T_1852)x_1828)->tabClick_11 = this_1884->tabClick_11;
    ((T_1852)x_1828)->button2_10 = this_1884->button2_10;
    ((T_1852)x_1828)->button_9 = this_1884->button_9;
    ((T_1852)x_1828)->c2_8 = this_1884->c2_8;
    ((T_1852)x_1828)->w1_7 = this_1884->w1_7;
    ((T_1852)x_1828)->env_5 = this_1884->env_5;
    ((T_1852)x_1828)->self_3 = this_1884->self_3;
    return (Msg)ASYNC(x_1828, a_1830, a_1831);
}
static Bool f_1937 (T_1858 this_1933,
                    KeyEventType_CTCommon a_1834,
                    Int a_1835) {
    CLOS x_1936;
    x_1936 = this_1933->tabStop_18;
    return ((Bool(*)(CLOS, BITS32, POLY, Int))(x_1936->Code))(x_1936,
                                                              (BITS32)0,
                                                              (POLY)a_1834,
                                                              a_1835);
}
static TUP0 f_1951 (T_1857 this_1928) {
    Ref self_31;
    self_31 = (Ref)LOCK((OID)this_1928->self_3);
    Size_CTCommon x_1929;
    NEW (Size_CTCommon, x_1929, WORDS(sizeof(struct Size_CTCommon)));
    x_1929->GCINFO = __GC__Size_CTCommon;
    x_1929->width_CTCommon = 108;
    x_1929->height_CTCommon = 17;
    HasSize_CTCommon x_1930;
    x_1930 = this_1928->button_9->l_Button_CTButton_Component_CTCommon_CTButton->l_Component_CTCommon_HasSize_CTCommon_CTCommon;
    Msg d_68;
    d_68 = x_1930->setSize_CTCommon(x_1930, x_1929, Inherit, Inherit);
    Component_CTCommon x_1931;
    x_1931 = this_1928->button2_10->l_Button_CTButton_Component_CTCommon_CTButton;
    TUP0 d_71;
    d_71 = x_1931->setName_CTCommon(x_1931, getStr("sec7add"), 0);
    Component_CTCommon x_1932;
    x_1932 = this_1928->button_9->l_Button_CTButton_Component_CTCommon_CTButton;
    TUP0 d_72;
    d_72 = x_1932->setName_CTCommon(x_1932, getStr("Move"), 0);
    T_1858 x_1938;
    NEW (T_1858, x_1938, WORDS(sizeof(struct T_1858)));
    x_1938->GCINFO = __GC__T_1858;
    x_1938->Code = f_1937;
    x_1938->tabStop_18 = this_1928->tabStop_18;
    HandlesKeyEvents_CTCommon x_1939;
    x_1939 = this_1928->button_9->l_Button_CTButton_HandlesKeyEvents_CTCommon_CTButton;
    TUP0 d_73;
    d_73 = x_1939->installKeyListener_CTCommon(x_1939,
                                               (CLOS)x_1938,
                                               0);
    Component_CTCommon x_1940;
    x_1940 = this_1928->c2_8->l_Container_CTContainer_Component_CTCommon_CTContainer;
    TUP0 d_74;
    d_74 = x_1940->setName_CTCommon(x_1940,
                                    getStr("greenContainer "),
                                    0);
    Size_CTCommon x_1941;
    NEW (Size_CTCommon, x_1941, WORDS(sizeof(struct Size_CTCommon)));
    x_1941->GCINFO = __GC__Size_CTCommon;
    x_1941->width_CTCommon = 180;
    x_1941->height_CTCommon = 140;
    HasSize_CTCommon x_1942;
    x_1942 = this_1928->c2_8->l_Container_CTContainer_Component_CTCommon_CTContainer->l_Component_CTCommon_HasSize_CTCommon_CTCommon;
    Msg d_75;
    d_75 = x_1942->setSize_CTCommon(x_1942, x_1941, Inherit, Inherit);
    Position_CTCommon x_1943;
    NEW (Position_CTCommon, x_1943, WORDS(sizeof(struct Position_CTCommon)));
    x_1943->GCINFO = __GC__Position_CTCommon;
    x_1943->x_CTCommon = 0;
    x_1943->y_CTCommon = 0;
    HasPosition_CTCommon x_1944;
    x_1944 = this_1928->c2_8->l_Container_CTContainer_Component_CTCommon_CTContainer->l_Component_CTCommon_HasSize_CTCommon_CTCommon->l_HasSize_CTCommon_HasPosition_CTCommon_CTCommon;
    Msg d_78;
    d_78 = x_1944->setPosition_CTCommon(x_1944,
                                        x_1943,
                                        Inherit,
                                        Inherit);
    Color_CTCommon x_1945;
    NEW (Color_CTCommon, x_1945, WORDS(sizeof(struct Color_CTCommon)));
    x_1945->GCINFO = __GC__Color_CTCommon;
    x_1945->r_CTCommon = 0;
    x_1945->g_CTCommon = 255;
    x_1945->b_CTCommon = 0;
    HasBackgroundColor_CTCommon x_1946;
    x_1946 = this_1928->c2_8->l_Container_CTContainer_HasBackgroundColor_CTCommon_CTContainer;
    Msg d_81;
    d_81 = x_1946->setBackgroundColor_CTCommon(x_1946,
                                               x_1945,
                                               Inherit,
                                               Inherit);
    ContainsComponents_CTCommon x_1947;
    x_1947 = this_1928->c2_8->l_Container_CTContainer_ContainsComponents_CTCommon_CTContainer;
    TUP0 d_85;
    d_85 = x_1947->addComponent_CTCommon(x_1947,
                                         this_1928->button2_10->l_Button_CTButton_Component_CTCommon_CTButton,
                                         0);
    ContainsComponents_CTCommon x_1948;
    x_1948 = this_1928->c2_8->l_Container_CTContainer_ContainsComponents_CTCommon_CTContainer;
    TUP0 d_86;
    d_86 = x_1948->addComponent_CTCommon(x_1948,
                                         this_1928->button_9->l_Button_CTButton_Component_CTCommon_CTButton,
                                         0);
    ContainsComponents_CTCommon x_1949;
    x_1949 = this_1928->w1_7->l_CocoaWindow_CTCommon_ContainsComponents_CTCommon_CTCommon;
    TUP0 d_87;
    d_87 = x_1949->addComponent_CTCommon(x_1949,
                                         this_1928->c2_8->l_Container_CTContainer_Component_CTCommon_CTContainer,
                                         0);
    Env_COCOA x_1950;
    x_1950 = this_1928->osx_6;
    TUP0 d_88;
    d_88 = x_1950->startApplication_COCOA(x_1950,
                                          this_1928->applicationDidFinishLaunching_24,
                                          0);
    UNLOCK((OID)self_31);
    return (TUP0)0;
}
static Msg f_1952 (T_1856 this_1925, Time a_1841, Time a_1842) {
    Msg x_1843;
    NEW (Msg, x_1843, WORDS(sizeof(struct T_1857)));
    ((T_1857)x_1843)->GCINFO = __GC__T_1857;
    ((T_1857)x_1843)->Code = f_1951;
    ((T_1857)x_1843)->applicationDidFinishLaunching_24 = this_1925->applicationDidFinishLaunching_24;
    ((T_1857)x_1843)->tabStop_18 = this_1925->tabStop_18;
    ((T_1857)x_1843)->button2_10 = this_1925->button2_10;
    ((T_1857)x_1843)->button_9 = this_1925->button_9;
    ((T_1857)x_1843)->c2_8 = this_1925->c2_8;
    ((T_1857)x_1843)->w1_7 = this_1925->w1_7;
    ((T_1857)x_1843)->osx_6 = this_1925->osx_6;
    ((T_1857)x_1843)->self_3 = this_1925->self_3;
    return (Msg)ASYNC(x_1843, a_1841, a_1842);
}
static TUP0 f_1962 (T_1855 this_1953) {
    Ref self_28;
    self_28 = (Ref)LOCK((OID)this_1953->self_26);
    Button_CTButton button3_29;
    button3_29 = mkCocoaButton_CTButton(this_1953->env_5, 0);
    Container_CTContainer c3_30;
    c3_30 = mkContainer_CTContainer((BITS32)0,
                                    (POLY)this_1953->env_5,
                                    0);
    ContainsComponents_CTCommon x_1954;
    x_1954 = c3_30->l_Container_CTContainer_ContainsComponents_CTCommon_CTContainer;
    TUP0 d_56;
    d_56 = x_1954->addComponent_CTCommon(x_1954,
                                         button3_29->l_Button_CTButton_Component_CTCommon_CTButton,
                                         0);
    Size_CTCommon x_1955;
    NEW (Size_CTCommon, x_1955, WORDS(sizeof(struct Size_CTCommon)));
    x_1955->GCINFO = __GC__Size_CTCommon;
    x_1955->width_CTCommon = 180;
    x_1955->height_CTCommon = 50;
    HasSize_CTCommon x_1956;
    x_1956 = c3_30->l_Container_CTContainer_Component_CTCommon_CTContainer->l_Component_CTCommon_HasSize_CTCommon_CTCommon;
    Msg d_57;
    d_57 = x_1956->setSize_CTCommon(x_1956, x_1955, Inherit, Inherit);
    Position_CTCommon x_1957;
    NEW (Position_CTCommon, x_1957, WORDS(sizeof(struct Position_CTCommon)));
    x_1957->GCINFO = __GC__Position_CTCommon;
    x_1957->x_CTCommon = 0;
    x_1957->y_CTCommon = 100;
    HasPosition_CTCommon x_1958;
    x_1958 = c3_30->l_Container_CTContainer_Component_CTCommon_CTContainer->l_Component_CTCommon_HasSize_CTCommon_CTCommon->l_HasSize_CTCommon_HasPosition_CTCommon_CTCommon;
    Msg d_60;
    d_60 = x_1958->setPosition_CTCommon(x_1958,
                                        x_1957,
                                        Inherit,
                                        Inherit);
    Color_CTCommon x_1959;
    NEW (Color_CTCommon, x_1959, WORDS(sizeof(struct Color_CTCommon)));
    x_1959->GCINFO = __GC__Color_CTCommon;
    x_1959->r_CTCommon = 240;
    x_1959->g_CTCommon = 66;
    x_1959->b_CTCommon = 33;
    HasBackgroundColor_CTCommon x_1960;
    x_1960 = c3_30->l_Container_CTContainer_HasBackgroundColor_CTCommon_CTContainer;
    Msg d_63;
    d_63 = x_1960->setBackgroundColor_CTCommon(x_1960,
                                               x_1959,
                                               Inherit,
                                               Inherit);
    ContainsComponents_CTCommon x_1961;
    x_1961 = this_1953->c2_8->l_Container_CTContainer_ContainsComponents_CTCommon_CTContainer;
    TUP0 d_67;
    d_67 = x_1961->addComponent_CTCommon(x_1961,
                                         c3_30->l_Container_CTContainer_Component_CTCommon_CTContainer,
                                         0);
    UNLOCK((OID)self_28);
    return (TUP0)0;
}
 
void _init_FocusTest () {
    static int INITIALIZED = 0;
    if (!INITIALIZED) {
        _init_Prelude();
        _init_POSIX();
        _init_COCOA();
        INITIALIZED = 1;
    }
}
 

