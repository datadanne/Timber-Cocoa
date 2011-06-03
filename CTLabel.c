#include "CTLabel.h"
#include "CTLabel.extern.c"
 
struct S_437;
typedef struct S_437 *S_437;
struct T_1859;
typedef struct T_1859 *T_1859;
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
struct T_1846;
typedef struct T_1846 *T_1846;
struct T_1845;
typedef struct T_1845 *T_1845;
struct T_1844;
typedef struct T_1844 *T_1844;
struct T_1843;
typedef struct T_1843 *T_1843;
struct T_1842;
typedef struct T_1842 *T_1842;
struct T_1841;
typedef struct T_1841 *T_1841;
struct T_1840;
typedef struct T_1840 *T_1840;
struct T_1839;
typedef struct T_1839 *T_1839;
struct T_1838;
typedef struct T_1838 *T_1838;
struct T_1837;
typedef struct T_1837 *T_1837;
struct T_1836;
typedef struct T_1836 *T_1836;
struct T_1835;
typedef struct T_1835 *T_1835;
struct T_1834;
typedef struct T_1834 *T_1834;
struct T_1833;
typedef struct T_1833 *T_1833;
struct T_1832;
typedef struct T_1832 *T_1832;
 
struct S_437 {
    POLY GCINFO;
    CocoaState_CTCommon myState_13;
    Position_CTCommon position_14;
    Size_CTCommon size_15;
    Maybe_Prelude mouseEventHandler_16;
    Color_CTCommon textColor_17;
    LIST text_18;
    LIST name_19;
};
struct T_1859 {
    POLY GCINFO;
    TUP0 (*installMouseListener_CTCommon) (T_1859, CLOS, Int);
    CLOS x_1816;
};
struct T_1858 {
    POLY GCINFO;
    Maybe_Prelude (*handleEvent_CTCommon) (T_1858,
                                           CocoaEvent_CTCommon,
                                           LIST,
                                           Int);
    CLOS x_1802;
};
struct T_1857 {
    POLY GCINFO;
    Msg (*setPosition_CTCommon) (T_1857,
                                 Position_CTCommon,
                                 Time,
                                 Time);
    Position_CTCommon (*getPosition_CTCommon) (T_1857, Int);
    CLOS x_1790;
    CLOS x_1792;
};
struct T_1856 {
    POLY GCINFO;
    HasPosition_CTCommon l_HasSize_CTCommon_HasPosition_CTCommon_CTCommon;
    Msg (*setSize_CTCommon) (T_1856, Size_CTCommon, Time, Time);
    Size_CTCommon (*getSize_CTCommon) (T_1856, Int);
    CLOS x_1796;
    CLOS x_1798;
};
struct T_1855 {
    POLY GCINFO;
    TUP0 (*setNextFocusTarget_CTCommon) (T_1855, Maybe_Prelude, Int);
    Maybe_Prelude (*getNextFocusTarget_CTCommon) (T_1855, Int);
    TUP0 (*setPreviousFocusTarget_CTCommon) (T_1855,
                                             Maybe_Prelude,
                                             Int);
    Maybe_Prelude (*getPreviousFocusTarget_CTCommon) (T_1855, Int);
    TUP0 (*setIsFocusable_CTCommon) (T_1855, Bool, Int);
    Bool (*getIsFocusable_CTCommon) (T_1855, Int);
    CLOS x_1775;
    CLOS x_1777;
    CLOS x_1779;
    CLOS x_1781;
    CLOS x_1784;
    CLOS x_1787;
};
struct T_1854 {
    POLY GCINFO;
    IsFocusable_CTCommon l_Component_CTCommon_IsFocusable_CTCommon_CTCommon;
    HasSize_CTCommon l_Component_CTCommon_HasSize_CTCommon_CTCommon;
    HandlesEvents_CTCommon l_Component_CTCommon_HandlesEvents_CTCommon_CTCommon;
    CocoaID_CTCommon id_CTCommon;
    TUP0 (*init_CTCommon) (T_1854, App_CTCommon, Int);
    TUP0 (*destroy_CTCommon) (T_1854, Int);
    TUP0 (*setName_CTCommon) (T_1854, LIST, Int);
    LIST (*getName_CTCommon) (T_1854, Int);
    CLOS x_1806;
    CLOS x_1808;
    CLOS x_1810;
    CLOS x_1813;
};
struct T_1853 {
    POLY GCINFO;
    Component_CTCommon l_Label_CTLabel_Component_CTCommon_CTLabel;
    HandlesMouseEvents_CTCommon l_Label_CTLabel_HandlesMouseEvents_CTCommon_CTLabel;
    Msg (*setText_CTLabel) (T_1853, LIST, Time, Time);
    LIST (*getText_CTLabel) (T_1853, Int);
    Msg (*setTextColor_CTLabel) (T_1853, Color_CTCommon, Time, Time);
    Color_CTCommon (*getTextColor_CTLabel) (T_1853, Int);
    CLOS x_1819;
    CLOS x_1821;
    CLOS x_1823;
    CLOS x_1827;
};
struct T_1852 {
    POLY GCINFO;
    TUP0 (*Code) (T_1852, App_CTCommon, Int);
    Label_CTLabel this_68;
    CocoaID_CTCommon id_20;
    Ref self_12;
};
struct T_1851 {
    POLY GCINFO;
    Maybe_Prelude (*Code) (T_1851, CocoaEvent_CTCommon, LIST, Int);
    Label_CTLabel this_68;
    Ref self_12;
};
struct T_1850 {
    POLY GCINFO;
    Bool (*Code) (T_1850, Int);
    IsFocusable_CTCommon focus_59;
};
struct T_1849 {
    POLY GCINFO;
    TUP0 (*Code) (T_1849, Bool, Int);
    IsFocusable_CTCommon focus_59;
};
struct T_1848 {
    POLY GCINFO;
    Maybe_Prelude (*Code) (T_1848, Int);
    IsFocusable_CTCommon focus_59;
};
struct T_1847 {
    POLY GCINFO;
    TUP0 (*Code) (T_1847, Maybe_Prelude, Int);
    IsFocusable_CTCommon focus_59;
};
struct T_1846 {
    POLY GCINFO;
    TUP0 (*Code) (T_1846);
    AbsTime baseline;
    AbsTime deadline;
    Msg next;
    Color_CTCommon a_1742;
    CocoaID_CTCommon id_20;
    Ref self_12;
};
struct T_1845 {
    POLY GCINFO;
    Msg (*Code) (T_1845, Color_CTCommon, Time, Time);
    CocoaID_CTCommon id_20;
    Ref self_12;
};
struct T_1844 {
    POLY GCINFO;
    TUP0 (*Code) (T_1844);
    AbsTime baseline;
    AbsTime deadline;
    Msg next;
    LIST a_1734;
    CocoaID_CTCommon id_20;
    Ref self_12;
};
struct T_1843 {
    POLY GCINFO;
    Msg (*Code) (T_1843, LIST, Time, Time);
    CocoaID_CTCommon id_20;
    Ref self_12;
};
struct T_1842 {
    POLY GCINFO;
    TUP0 (*Code) (T_1842);
    AbsTime baseline;
    AbsTime deadline;
    Msg next;
    Size_CTCommon a_1726;
    Ref self_12;
};
struct T_1841 {
    POLY GCINFO;
    Msg (*Code) (T_1841, Size_CTCommon, Time, Time);
    Ref self_12;
};
struct T_1840 {
    POLY GCINFO;
    TUP0 (*Code) (T_1840);
    AbsTime baseline;
    AbsTime deadline;
    Msg next;
    Position_CTCommon a_1718;
    CocoaID_CTCommon id_20;
    Ref self_12;
};
struct T_1839 {
    POLY GCINFO;
    Msg (*Code) (T_1839, Position_CTCommon, Time, Time);
    CocoaID_CTCommon id_20;
    Ref self_12;
};
struct T_1838 {
    POLY GCINFO;
    TUP0 (*Code) (T_1838, LIST, Int);
    Ref self_12;
};
struct T_1837 {
    POLY GCINFO;
    TUP0 (*Code) (T_1837, CLOS, Int);
    Ref self_12;
};
struct T_1836 {
    POLY GCINFO;
    Color_CTCommon (*Code) (T_1836, Int);
    Ref self_12;
};
struct T_1835 {
    POLY GCINFO;
    Size_CTCommon (*Code) (T_1835, Int);
    Ref self_12;
};
struct T_1834 {
    POLY GCINFO;
    Position_CTCommon (*Code) (T_1834, Int);
    Ref self_12;
};
struct T_1833 {
    POLY GCINFO;
    LIST (*Code) (T_1833, Int);
    Ref self_12;
};
struct T_1832 {
    POLY GCINFO;
    TUP0 (*Code) (T_1832, Int);
    Ref self_12;
};
 
static WORD __GC__S_437[];
static WORD __GC__T_1859[];
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
static WORD __GC__T_1846[];
static WORD __GC__T_1845[];
static WORD __GC__T_1844[];
static WORD __GC__T_1843[];
static WORD __GC__T_1842[];
static WORD __GC__T_1841[];
static WORD __GC__T_1840[];
static WORD __GC__T_1839[];
static WORD __GC__T_1838[];
static WORD __GC__T_1837[];
static WORD __GC__T_1836[];
static WORD __GC__T_1835[];
static WORD __GC__T_1834[];
static WORD __GC__T_1833[];
static WORD __GC__T_1832[];
static TUP0 inithelper_33 (CocoaID_CTCommon id_20, Ref self_34);
static TUP0 f_1863 (T_1832 this_1861, Int a_1680);
static LIST f_1866 (T_1833 this_1864, Int a_1684);
static Position_CTCommon f_1869 (T_1834 this_1867, Int a_1688);
static Size_CTCommon f_1872 (T_1835 this_1870, Int a_1692);
static LIST f_1875 (T_1833 this_1873, Int a_1696);
static Color_CTCommon f_1878 (T_1836 this_1876, Int a_1700);
static TUP0 f_1883 (T_1837 this_1879, CLOS a_1705, Int a_1706);
static TUP0 f_1887 (T_1838 this_1884, LIST a_1711, Int a_1712);
static TUP0 f_1894 (T_1840 this_1892);
static Msg f_1895 (T_1839 this_1888,
                   Position_CTCommon a_1718,
                   Time a_1719,
                   Time a_1720);
static TUP0 f_1901 (T_1842 this_1900);
static Msg f_1902 (T_1841 this_1896,
                   Size_CTCommon a_1726,
                   Time a_1727,
                   Time a_1728);
static TUP0 f_1909 (T_1844 this_1907);
static Msg f_1910 (T_1843 this_1903,
                   LIST a_1734,
                   Time a_1735,
                   Time a_1736);
static TUP0 f_1917 (T_1846 this_1915);
static Msg f_1918 (T_1845 this_1911,
                   Color_CTCommon a_1742,
                   Time a_1743,
                   Time a_1744);
static TUP0 f_1923 (T_1847 this_1919,
                    Maybe_Prelude a_1747,
                    Int a_1748);
static Maybe_Prelude f_1927 (T_1848 this_1924, Int a_1750);
static TUP0 f_1932 (T_1847 this_1928,
                    Maybe_Prelude a_1753,
                    Int a_1754);
static Maybe_Prelude f_1936 (T_1848 this_1933, Int a_1756);
static TUP0 f_1941 (T_1849 this_1937, Bool a_1759, Int a_1760);
static Bool f_1945 (T_1850 this_1942, Int a_1762);
static Maybe_Prelude f_1951 (T_1851 this_1946,
                             CocoaEvent_CTCommon a_1768,
                             LIST a_1769,
                             Int a_1770);
static TUP0 f_1955 (T_1852 this_1952,
                    App_CTCommon a_1773,
                    Int a_1774);
static Bool f_1959 (T_1855 this_1956, Int a_1776);
static Maybe_Prelude f_1963 (T_1855 this_1960, Int a_1778);
static Maybe_Prelude f_1967 (T_1855 this_1964, Int a_1780);
static TUP0 f_1972 (T_1855 this_1968, Bool a_1782, Int a_1783);
static TUP0 f_1977 (T_1855 this_1973,
                    Maybe_Prelude a_1785,
                    Int a_1786);
static TUP0 f_1982 (T_1855 this_1978,
                    Maybe_Prelude a_1788,
                    Int a_1789);
static Position_CTCommon f_1987 (T_1857 this_1984, Int a_1791);
static Msg f_1993 (T_1857 this_1988,
                   Position_CTCommon a_1793,
                   Time a_1794,
                   Time a_1795);
static Size_CTCommon f_1998 (T_1856 this_1995, Int a_1797);
static Msg f_2004 (T_1856 this_1999,
                   Size_CTCommon a_1799,
                   Time a_1800,
                   Time a_1801);
static Maybe_Prelude f_2011 (T_1858 this_2006,
                             CocoaEvent_CTCommon a_1803,
                             LIST a_1804,
                             Int a_1805);
static TUP0 f_2016 (T_1854 this_2013, Int a_1807);
static LIST f_2020 (T_1854 this_2017, Int a_1809);
static TUP0 f_2025 (T_1854 this_2021,
                    App_CTCommon a_1811,
                    Int a_1812);
static TUP0 f_2030 (T_1854 this_2026, LIST a_1814, Int a_1815);
static TUP0 f_2036 (T_1859 this_2032, CLOS a_1817, Int a_1818);
static LIST f_2041 (T_1853 this_2038, Int a_1820);
static Color_CTCommon f_2045 (T_1853 this_2042, Int a_1822);
static Msg f_2051 (T_1853 this_2046,
                   LIST a_1824,
                   Time a_1825,
                   Time a_1826);
static Msg f_2057 (T_1853 this_2052,
                   Color_CTCommon a_1828,
                   Time a_1829,
                   Time a_1830);
 
WORD __GC__Label_CTLabel[] = {WORDS(sizeof(struct Label_CTLabel)),
                              0,
                              WORDS(offsetof(struct Label_CTLabel, l_Label_CTLabel_Component_CTCommon_CTLabel)),
                              WORDS(offsetof(struct Label_CTLabel, l_Label_CTLabel_HandlesMouseEvents_CTCommon_CTLabel)),
                              0};
static WORD __GC__S_437[] = {WORDS(sizeof(struct S_437)),
                             0,
                             WORDS(offsetof(struct S_437, myState_13)),
                             WORDS(offsetof(struct S_437, position_14)),
                             WORDS(offsetof(struct S_437, size_15)),
                             WORDS(offsetof(struct S_437, mouseEventHandler_16)),
                             WORDS(offsetof(struct S_437, textColor_17)),
                             WORDS(offsetof(struct S_437, text_18)),
                             WORDS(offsetof(struct S_437, name_19)),
                             0};
static WORD __GC__T_1859[] = {WORDS(sizeof(struct T_1859)),
                              0,
                              WORDS(offsetof(struct T_1859, x_1816)),
                              0};
static WORD __GC__T_1858[] = {WORDS(sizeof(struct T_1858)),
                              0,
                              WORDS(offsetof(struct T_1858, x_1802)),
                              0};
static WORD __GC__T_1857[] = {WORDS(sizeof(struct T_1857)),
                              0,
                              WORDS(offsetof(struct T_1857, x_1790)),
                              WORDS(offsetof(struct T_1857, x_1792)),
                              0};
static WORD __GC__T_1856[] = {WORDS(sizeof(struct T_1856)),
                              0,
                              WORDS(offsetof(struct T_1856, l_HasSize_CTCommon_HasPosition_CTCommon_CTCommon)),
                              WORDS(offsetof(struct T_1856, x_1796)),
                              WORDS(offsetof(struct T_1856, x_1798)),
                              0};
static WORD __GC__T_1855[] = {WORDS(sizeof(struct T_1855)),
                              0,
                              WORDS(offsetof(struct T_1855, x_1775)),
                              WORDS(offsetof(struct T_1855, x_1777)),
                              WORDS(offsetof(struct T_1855, x_1779)),
                              WORDS(offsetof(struct T_1855, x_1781)),
                              WORDS(offsetof(struct T_1855, x_1784)),
                              WORDS(offsetof(struct T_1855, x_1787)),
                              0};
static WORD __GC__T_1854[] = {WORDS(sizeof(struct T_1854)),
                              0,
                              WORDS(offsetof(struct T_1854, l_Component_CTCommon_IsFocusable_CTCommon_CTCommon)),
                              WORDS(offsetof(struct T_1854, l_Component_CTCommon_HasSize_CTCommon_CTCommon)),
                              WORDS(offsetof(struct T_1854, l_Component_CTCommon_HandlesEvents_CTCommon_CTCommon)),
                              WORDS(offsetof(struct T_1854, id_CTCommon)),
                              WORDS(offsetof(struct T_1854, x_1806)),
                              WORDS(offsetof(struct T_1854, x_1808)),
                              WORDS(offsetof(struct T_1854, x_1810)),
                              WORDS(offsetof(struct T_1854, x_1813)),
                              0};
static WORD __GC__T_1853[] = {WORDS(sizeof(struct T_1853)),
                              0,
                              WORDS(offsetof(struct T_1853, l_Label_CTLabel_Component_CTCommon_CTLabel)),
                              WORDS(offsetof(struct T_1853, l_Label_CTLabel_HandlesMouseEvents_CTCommon_CTLabel)),
                              WORDS(offsetof(struct T_1853, x_1819)),
                              WORDS(offsetof(struct T_1853, x_1821)),
                              WORDS(offsetof(struct T_1853, x_1823)),
                              WORDS(offsetof(struct T_1853, x_1827)),
                              0};
static WORD __GC__T_1852[] = {WORDS(sizeof(struct T_1852)),
                              0,
                              WORDS(offsetof(struct T_1852, this_68)),
                              WORDS(offsetof(struct T_1852, id_20)),
                              WORDS(offsetof(struct T_1852, self_12)),
                              0};
static WORD __GC__T_1851[] = {WORDS(sizeof(struct T_1851)),
                              0,
                              WORDS(offsetof(struct T_1851, this_68)),
                              WORDS(offsetof(struct T_1851, self_12)),
                              0};
static WORD __GC__T_1850[] = {WORDS(sizeof(struct T_1850)),
                              0,
                              WORDS(offsetof(struct T_1850, focus_59)),
                              0};
static WORD __GC__T_1849[] = {WORDS(sizeof(struct T_1849)),
                              0,
                              WORDS(offsetof(struct T_1849, focus_59)),
                              0};
static WORD __GC__T_1848[] = {WORDS(sizeof(struct T_1848)),
                              0,
                              WORDS(offsetof(struct T_1848, focus_59)),
                              0};
static WORD __GC__T_1847[] = {WORDS(sizeof(struct T_1847)),
                              0,
                              WORDS(offsetof(struct T_1847, focus_59)),
                              0};
static WORD __GC__T_1846[] = {WORDS(sizeof(struct T_1846)),
                              0,
                              WORDS(offsetof(struct T_1846, a_1742)),
                              WORDS(offsetof(struct T_1846, id_20)),
                              WORDS(offsetof(struct T_1846, self_12)),
                              0};
static WORD __GC__T_1845[] = {WORDS(sizeof(struct T_1845)),
                              0,
                              WORDS(offsetof(struct T_1845, id_20)),
                              WORDS(offsetof(struct T_1845, self_12)),
                              0};
static WORD __GC__T_1844[] = {WORDS(sizeof(struct T_1844)),
                              0,
                              WORDS(offsetof(struct T_1844, a_1734)),
                              WORDS(offsetof(struct T_1844, id_20)),
                              WORDS(offsetof(struct T_1844, self_12)),
                              0};
static WORD __GC__T_1843[] = {WORDS(sizeof(struct T_1843)),
                              0,
                              WORDS(offsetof(struct T_1843, id_20)),
                              WORDS(offsetof(struct T_1843, self_12)),
                              0};
static WORD __GC__T_1842[] = {WORDS(sizeof(struct T_1842)),
                              0,
                              WORDS(offsetof(struct T_1842, a_1726)),
                              WORDS(offsetof(struct T_1842, self_12)),
                              0};
static WORD __GC__T_1841[] = {WORDS(sizeof(struct T_1841)),
                              0,
                              WORDS(offsetof(struct T_1841, self_12)),
                              0};
static WORD __GC__T_1840[] = {WORDS(sizeof(struct T_1840)),
                              0,
                              WORDS(offsetof(struct T_1840, a_1718)),
                              WORDS(offsetof(struct T_1840, id_20)),
                              WORDS(offsetof(struct T_1840, self_12)),
                              0};
static WORD __GC__T_1839[] = {WORDS(sizeof(struct T_1839)),
                              0,
                              WORDS(offsetof(struct T_1839, id_20)),
                              WORDS(offsetof(struct T_1839, self_12)),
                              0};
static WORD __GC__T_1838[] = {WORDS(sizeof(struct T_1838)),
                              0,
                              WORDS(offsetof(struct T_1838, self_12)),
                              0};
static WORD __GC__T_1837[] = {WORDS(sizeof(struct T_1837)),
                              0,
                              WORDS(offsetof(struct T_1837, self_12)),
                              0};
static WORD __GC__T_1836[] = {WORDS(sizeof(struct T_1836)),
                              0,
                              WORDS(offsetof(struct T_1836, self_12)),
                              0};
static WORD __GC__T_1835[] = {WORDS(sizeof(struct T_1835)),
                              0,
                              WORDS(offsetof(struct T_1835, self_12)),
                              0};
static WORD __GC__T_1834[] = {WORDS(sizeof(struct T_1834)),
                              0,
                              WORDS(offsetof(struct T_1834, self_12)),
                              0};
static WORD __GC__T_1833[] = {WORDS(sizeof(struct T_1833)),
                              0,
                              WORDS(offsetof(struct T_1833, self_12)),
                              0};
static WORD __GC__T_1832[] = {WORDS(sizeof(struct T_1832)),
                              0,
                              WORDS(offsetof(struct T_1832, self_12)),
                              0};
Component_CTCommon c_391_CTLabel (Label_CTLabel v_393) {
    return v_393->l_Label_CTLabel_Component_CTCommon_CTLabel;
}
HandlesMouseEvents_CTCommon c_394_CTLabel (Label_CTLabel v_396) {
    return v_396->l_Label_CTLabel_HandlesMouseEvents_CTCommon_CTLabel;
}
IsFocusable_CTCommon c_398_CTLabel (Label_CTLabel a_397) {
    return a_397->l_Label_CTLabel_Component_CTCommon_CTLabel->l_Component_CTCommon_IsFocusable_CTCommon_CTCommon;
}
HasSize_CTCommon c_400_CTLabel (Label_CTLabel a_399) {
    return a_399->l_Label_CTLabel_Component_CTCommon_CTLabel->l_Component_CTCommon_HasSize_CTCommon_CTCommon;
}
HandlesEvents_CTCommon c_402_CTLabel (Label_CTLabel a_401) {
    return a_401->l_Label_CTLabel_Component_CTCommon_CTLabel->l_Component_CTCommon_HandlesEvents_CTCommon_CTCommon;
}
HasPosition_CTCommon c_404_CTLabel (Label_CTLabel a_403) {
    return a_403->l_Label_CTLabel_Component_CTCommon_CTLabel->l_Component_CTCommon_HasSize_CTCommon_CTCommon->l_HasSize_CTCommon_HasPosition_CTCommon_CTCommon;
}
Label_CTLabel mkCocoaLabel_CTLabel (Int d_1831) {
    Ref self_12;
    NEW (Ref, self_12, WORDS(sizeof(struct Ref))+
                       WORDS(sizeof(struct S_437)));
    INITREF(self_12);
    ((S_437)STATEOF(self_12))->GCINFO = __GC__S_437;
    CocoaID_CTCommon id_20;
    id_20 = mkCocoaID_CTCommon(0);
    CLOS destroy_21;
    NEW (CLOS, destroy_21, WORDS(sizeof(struct T_1832)));
    ((T_1832)destroy_21)->GCINFO = __GC__T_1832;
    ((T_1832)destroy_21)->Code = f_1863;
    ((T_1832)destroy_21)->self_12 = self_12;
    CLOS getName_23;
    NEW (CLOS, getName_23, WORDS(sizeof(struct T_1833)));
    ((T_1833)getName_23)->GCINFO = __GC__T_1833;
    ((T_1833)getName_23)->Code = f_1866;
    ((T_1833)getName_23)->self_12 = self_12;
    CLOS getPosition_25;
    NEW (CLOS, getPosition_25, WORDS(sizeof(struct T_1834)));
    ((T_1834)getPosition_25)->GCINFO = __GC__T_1834;
    ((T_1834)getPosition_25)->Code = f_1869;
    ((T_1834)getPosition_25)->self_12 = self_12;
    CLOS getSize_27;
    NEW (CLOS, getSize_27, WORDS(sizeof(struct T_1835)));
    ((T_1835)getSize_27)->GCINFO = __GC__T_1835;
    ((T_1835)getSize_27)->Code = f_1872;
    ((T_1835)getSize_27)->self_12 = self_12;
    CLOS getText_29;
    NEW (CLOS, getText_29, WORDS(sizeof(struct T_1833)));
    ((T_1833)getText_29)->GCINFO = __GC__T_1833;
    ((T_1833)getText_29)->Code = f_1875;
    ((T_1833)getText_29)->self_12 = self_12;
    CLOS getTextColor_31;
    NEW (CLOS, getTextColor_31, WORDS(sizeof(struct T_1836)));
    ((T_1836)getTextColor_31)->GCINFO = __GC__T_1836;
    ((T_1836)getTextColor_31)->Code = f_1878;
    ((T_1836)getTextColor_31)->self_12 = self_12;
    CLOS installMouseListener_35;
    NEW (CLOS, installMouseListener_35, WORDS(sizeof(struct T_1837)));
    ((T_1837)installMouseListener_35)->GCINFO = __GC__T_1837;
    ((T_1837)installMouseListener_35)->Code = f_1883;
    ((T_1837)installMouseListener_35)->self_12 = self_12;
    CLOS setName_38;
    NEW (CLOS, setName_38, WORDS(sizeof(struct T_1838)));
    ((T_1838)setName_38)->GCINFO = __GC__T_1838;
    ((T_1838)setName_38)->Code = f_1887;
    ((T_1838)setName_38)->self_12 = self_12;
    CLOS setPosition_41;
    NEW (CLOS, setPosition_41, WORDS(sizeof(struct T_1839)));
    ((T_1839)setPosition_41)->GCINFO = __GC__T_1839;
    ((T_1839)setPosition_41)->Code = f_1895;
    ((T_1839)setPosition_41)->id_20 = id_20;
    ((T_1839)setPosition_41)->self_12 = self_12;
    CLOS setSize_46;
    NEW (CLOS, setSize_46, WORDS(sizeof(struct T_1841)));
    ((T_1841)setSize_46)->GCINFO = __GC__T_1841;
    ((T_1841)setSize_46)->Code = f_1902;
    ((T_1841)setSize_46)->self_12 = self_12;
    CLOS setText_49;
    NEW (CLOS, setText_49, WORDS(sizeof(struct T_1843)));
    ((T_1843)setText_49)->GCINFO = __GC__T_1843;
    ((T_1843)setText_49)->Code = f_1910;
    ((T_1843)setText_49)->id_20 = id_20;
    ((T_1843)setText_49)->self_12 = self_12;
    CLOS setTextColor_54;
    NEW (CLOS, setTextColor_54, WORDS(sizeof(struct T_1845)));
    ((T_1845)setTextColor_54)->GCINFO = __GC__T_1845;
    ((T_1845)setTextColor_54)->Code = f_1918;
    ((T_1845)setTextColor_54)->id_20 = id_20;
    ((T_1845)setTextColor_54)->self_12 = self_12;
    IsFocusable_CTCommon focus_59;
    CLOS setNextFocusTarget_60;
    CLOS getNextFocusTarget_61;
    CLOS setPreviousFocusTarget_62;
    CLOS getPreviousFocusTarget_63;
    CLOS setIsFocusable_64;
    CLOS getIsFocusable_65;
    CLOS handleEvent_66;
    CLOS init_67;
    CLOS x_1775;
    CLOS x_1777;
    CLOS x_1779;
    CLOS x_1781;
    CLOS x_1784;
    CLOS x_1787;
    CLOS x_1790;
    CLOS x_1792;
    CLOS x_1796;
    CLOS x_1798;
    CLOS x_1802;
    CLOS x_1806;
    CLOS x_1808;
    CLOS x_1810;
    CLOS x_1813;
    CLOS x_1816;
    CLOS x_1819;
    CLOS x_1821;
    CLOS x_1823;
    CLOS x_1827;
    T_1855 x_1983;
    T_1857 x_1994;
    T_1856 x_2005;
    T_1858 x_2012;
    T_1854 x_2031;
    T_1859 x_2037;
    Label_CTLabel this_68;
    Component_CTCommon x_1426;
    x_1790 = getPosition_25;
    x_1792 = setPosition_41;
    NEW (T_1857, x_1994, WORDS(sizeof(struct T_1857)));
    x_1994->GCINFO = __GC__T_1857;
    x_1994->getPosition_CTCommon = f_1987;
    x_1994->setPosition_CTCommon = f_1993;
    x_1994->x_1790 = x_1790;
    x_1994->x_1792 = x_1792;
    x_1796 = getSize_27;
    x_1798 = setSize_46;
    NEW (T_1856, x_2005, WORDS(sizeof(struct T_1856)));
    x_2005->GCINFO = __GC__T_1856;
    x_2005->l_HasSize_CTCommon_HasPosition_CTCommon_CTCommon = (HasPosition_CTCommon)x_1994;
    x_2005->getSize_CTCommon = f_1998;
    x_2005->setSize_CTCommon = f_2004;
    x_2005->x_1796 = x_1796;
    x_2005->x_1798 = x_1798;
    x_1806 = destroy_21;
    x_1808 = getName_23;
    x_1813 = setName_38;
    x_1816 = installMouseListener_35;
    NEW (T_1859, x_2037, WORDS(sizeof(struct T_1859)));
    x_2037->GCINFO = __GC__T_1859;
    x_2037->installMouseListener_CTCommon = f_2036;
    x_2037->x_1816 = x_1816;
    x_1819 = getText_29;
    x_1821 = getTextColor_31;
    x_1823 = setText_49;
    x_1827 = setTextColor_54;
    {   Array roots = CYCLIC_BEGIN(22,0);
        focus_59 = (IsFocusable_CTCommon)roots->elems[0];
        setNextFocusTarget_60 = (CLOS)roots->elems[1];
        getNextFocusTarget_61 = (CLOS)roots->elems[2];
        setPreviousFocusTarget_62 = (CLOS)roots->elems[3];
        getPreviousFocusTarget_63 = (CLOS)roots->elems[4];
        setIsFocusable_64 = (CLOS)roots->elems[5];
        getIsFocusable_65 = (CLOS)roots->elems[6];
        handleEvent_66 = (CLOS)roots->elems[7];
        init_67 = (CLOS)roots->elems[8];
        x_1775 = (CLOS)roots->elems[9];
        x_1777 = (CLOS)roots->elems[10];
        x_1779 = (CLOS)roots->elems[11];
        x_1781 = (CLOS)roots->elems[12];
        x_1784 = (CLOS)roots->elems[13];
        x_1787 = (CLOS)roots->elems[14];
        x_1802 = (CLOS)roots->elems[15];
        x_1810 = (CLOS)roots->elems[16];
        x_1983 = (T_1855)roots->elems[17];
        x_2012 = (T_1858)roots->elems[18];
        x_2031 = (T_1854)roots->elems[19];
        this_68 = (Label_CTLabel)roots->elems[20];
        x_1426 = (Component_CTCommon)roots->elems[21];
        focus_59 = focusWrapper_CTCommon(x_1426, (Bool)0, 0);
        roots->elems[0] = (POLY)focus_59;
        NEW (CLOS, setNextFocusTarget_60, WORDS(sizeof(struct T_1847)));
        roots->elems[1] = (POLY)setNextFocusTarget_60;
        ((T_1847)(CLOS)roots->elems[1])->GCINFO = __GC__T_1847;
        ((T_1847)(CLOS)roots->elems[1])->Code = f_1923;
        ((T_1847)(CLOS)roots->elems[1])->focus_59 = focus_59;
        NEW (CLOS, getNextFocusTarget_61, WORDS(sizeof(struct T_1848)));
        roots->elems[2] = (POLY)getNextFocusTarget_61;
        ((T_1848)(CLOS)roots->elems[2])->GCINFO = __GC__T_1848;
        ((T_1848)(CLOS)roots->elems[2])->Code = f_1927;
        ((T_1848)(CLOS)roots->elems[2])->focus_59 = focus_59;
        NEW (CLOS, setPreviousFocusTarget_62, WORDS(sizeof(struct T_1847)));
        roots->elems[3] = (POLY)setPreviousFocusTarget_62;
        ((T_1847)(CLOS)roots->elems[3])->GCINFO = __GC__T_1847;
        ((T_1847)(CLOS)roots->elems[3])->Code = f_1932;
        ((T_1847)(CLOS)roots->elems[3])->focus_59 = focus_59;
        NEW (CLOS, getPreviousFocusTarget_63, WORDS(sizeof(struct T_1848)));
        roots->elems[4] = (POLY)getPreviousFocusTarget_63;
        ((T_1848)(CLOS)roots->elems[4])->GCINFO = __GC__T_1848;
        ((T_1848)(CLOS)roots->elems[4])->Code = f_1936;
        ((T_1848)(CLOS)roots->elems[4])->focus_59 = focus_59;
        NEW (CLOS, setIsFocusable_64, WORDS(sizeof(struct T_1849)));
        roots->elems[5] = (POLY)setIsFocusable_64;
        ((T_1849)(CLOS)roots->elems[5])->GCINFO = __GC__T_1849;
        ((T_1849)(CLOS)roots->elems[5])->Code = f_1941;
        ((T_1849)(CLOS)roots->elems[5])->focus_59 = focus_59;
        NEW (CLOS, getIsFocusable_65, WORDS(sizeof(struct T_1850)));
        roots->elems[6] = (POLY)getIsFocusable_65;
        ((T_1850)(CLOS)roots->elems[6])->GCINFO = __GC__T_1850;
        ((T_1850)(CLOS)roots->elems[6])->Code = f_1945;
        ((T_1850)(CLOS)roots->elems[6])->focus_59 = focus_59;
        NEW (CLOS, handleEvent_66, WORDS(sizeof(struct T_1851)));
        roots->elems[7] = (POLY)handleEvent_66;
        ((T_1851)(CLOS)roots->elems[7])->GCINFO = __GC__T_1851;
        ((T_1851)(CLOS)roots->elems[7])->Code = f_1951;
        ((T_1851)(CLOS)roots->elems[7])->this_68 = this_68;
        ((T_1851)(CLOS)roots->elems[7])->self_12 = self_12;
        NEW (CLOS, init_67, WORDS(sizeof(struct T_1852)));
        roots->elems[8] = (POLY)init_67;
        ((T_1852)(CLOS)roots->elems[8])->GCINFO = __GC__T_1852;
        ((T_1852)(CLOS)roots->elems[8])->Code = f_1955;
        ((T_1852)(CLOS)roots->elems[8])->this_68 = this_68;
        ((T_1852)(CLOS)roots->elems[8])->id_20 = id_20;
        ((T_1852)(CLOS)roots->elems[8])->self_12 = self_12;
        x_1775 = getIsFocusable_65;
        roots->elems[9] = (POLY)x_1775;
        x_1777 = getNextFocusTarget_61;
        roots->elems[10] = (POLY)x_1777;
        x_1779 = getPreviousFocusTarget_63;
        roots->elems[11] = (POLY)x_1779;
        x_1781 = setIsFocusable_64;
        roots->elems[12] = (POLY)x_1781;
        x_1784 = setNextFocusTarget_60;
        roots->elems[13] = (POLY)x_1784;
        x_1787 = setPreviousFocusTarget_62;
        roots->elems[14] = (POLY)x_1787;
        x_1802 = handleEvent_66;
        roots->elems[15] = (POLY)x_1802;
        x_1810 = init_67;
        roots->elems[16] = (POLY)x_1810;
        NEW (T_1855, x_1983, WORDS(sizeof(struct T_1855)));
        roots->elems[17] = (POLY)x_1983;
        ((T_1855)roots->elems[17])->GCINFO = __GC__T_1855;
        ((T_1855)roots->elems[17])->getIsFocusable_CTCommon = f_1959;
        ((T_1855)roots->elems[17])->getNextFocusTarget_CTCommon = f_1963;
        ((T_1855)roots->elems[17])->getPreviousFocusTarget_CTCommon = f_1967;
        ((T_1855)roots->elems[17])->setIsFocusable_CTCommon = f_1972;
        ((T_1855)roots->elems[17])->setNextFocusTarget_CTCommon = f_1977;
        ((T_1855)roots->elems[17])->setPreviousFocusTarget_CTCommon = f_1982;
        ((T_1855)roots->elems[17])->x_1775 = x_1775;
        ((T_1855)roots->elems[17])->x_1777 = x_1777;
        ((T_1855)roots->elems[17])->x_1779 = x_1779;
        ((T_1855)roots->elems[17])->x_1781 = x_1781;
        ((T_1855)roots->elems[17])->x_1784 = x_1784;
        ((T_1855)roots->elems[17])->x_1787 = x_1787;
        NEW (T_1858, x_2012, WORDS(sizeof(struct T_1858)));
        roots->elems[18] = (POLY)x_2012;
        ((T_1858)roots->elems[18])->GCINFO = __GC__T_1858;
        ((T_1858)roots->elems[18])->handleEvent_CTCommon = f_2011;
        ((T_1858)roots->elems[18])->x_1802 = x_1802;
        NEW (T_1854, x_2031, WORDS(sizeof(struct T_1854)));
        roots->elems[19] = (POLY)x_2031;
        ((T_1854)roots->elems[19])->GCINFO = __GC__T_1854;
        ((T_1854)roots->elems[19])->l_Component_CTCommon_IsFocusable_CTCommon_CTCommon = (IsFocusable_CTCommon)x_1983;
        ((T_1854)roots->elems[19])->l_Component_CTCommon_HasSize_CTCommon_CTCommon = (HasSize_CTCommon)x_2005;
        ((T_1854)roots->elems[19])->l_Component_CTCommon_HandlesEvents_CTCommon_CTCommon = (HandlesEvents_CTCommon)x_2012;
        ((T_1854)roots->elems[19])->id_CTCommon = id_20;
        ((T_1854)roots->elems[19])->destroy_CTCommon = f_2016;
        ((T_1854)roots->elems[19])->getName_CTCommon = f_2020;
        ((T_1854)roots->elems[19])->init_CTCommon = f_2025;
        ((T_1854)roots->elems[19])->setName_CTCommon = f_2030;
        ((T_1854)roots->elems[19])->x_1806 = x_1806;
        ((T_1854)roots->elems[19])->x_1808 = x_1808;
        ((T_1854)roots->elems[19])->x_1810 = x_1810;
        ((T_1854)roots->elems[19])->x_1813 = x_1813;
        NEW (Label_CTLabel, this_68, WORDS(sizeof(struct T_1853)));
        roots->elems[20] = (POLY)this_68;
        ((T_1853)(Label_CTLabel)roots->elems[20])->GCINFO = __GC__T_1853;
        ((T_1853)(Label_CTLabel)roots->elems[20])->l_Label_CTLabel_Component_CTCommon_CTLabel = (Component_CTCommon)x_2031;
        ((T_1853)(Label_CTLabel)roots->elems[20])->l_Label_CTLabel_HandlesMouseEvents_CTCommon_CTLabel = (HandlesMouseEvents_CTCommon)x_2037;
        ((T_1853)(Label_CTLabel)roots->elems[20])->getText_CTLabel = f_2041;
        ((T_1853)(Label_CTLabel)roots->elems[20])->getTextColor_CTLabel = f_2045;
        ((T_1853)(Label_CTLabel)roots->elems[20])->setText_CTLabel = f_2051;
        ((T_1853)(Label_CTLabel)roots->elems[20])->setTextColor_CTLabel = f_2057;
        ((T_1853)(Label_CTLabel)roots->elems[20])->x_1819 = x_1819;
        ((T_1853)(Label_CTLabel)roots->elems[20])->x_1821 = x_1821;
        ((T_1853)(Label_CTLabel)roots->elems[20])->x_1823 = x_1823;
        ((T_1853)(Label_CTLabel)roots->elems[20])->x_1827 = x_1827;
        x_1426 = this_68->l_Label_CTLabel_Component_CTCommon_CTLabel;
        roots->elems[21] = (POLY)x_1426;
        CYCLIC_END(roots, hp);
    }
    ((S_437)STATEOF(self_12))->myState_13 = (CocoaState_CTCommon)1;
    Position_CTCommon x_2058;
    NEW (Position_CTCommon, x_2058, WORDS(sizeof(struct Position_CTCommon)));
    x_2058->GCINFO = __GC__Position_CTCommon;
    x_2058->x_CTCommon = 0;
    x_2058->y_CTCommon = 0;
    ((S_437)STATEOF(self_12))->position_14 = x_2058;
    Size_CTCommon x_2059;
    NEW (Size_CTCommon, x_2059, WORDS(sizeof(struct Size_CTCommon)));
    x_2059->GCINFO = __GC__Size_CTCommon;
    x_2059->width_CTCommon = 0;
    x_2059->height_CTCommon = 0;
    ((S_437)STATEOF(self_12))->size_15 = x_2059;
    ((S_437)STATEOF(self_12))->mouseEventHandler_16 = (Maybe_Prelude)1;
    Color_CTCommon x_2060;
    NEW (Color_CTCommon, x_2060, WORDS(sizeof(struct Color_CTCommon)));
    x_2060->GCINFO = __GC__Color_CTCommon;
    x_2060->r_CTCommon = 0;
    x_2060->g_CTCommon = 0;
    x_2060->b_CTCommon = 0;
    ((S_437)STATEOF(self_12))->textColor_17 = x_2060;
    ((S_437)STATEOF(self_12))->text_18 = getStr("Default Label");
    ((S_437)STATEOF(self_12))->name_19 = getStr("label");
    return this_68;
}
static TUP0 inithelper_33 (CocoaID_CTCommon id_20, Ref self_34) {
    Msg d_76;
    d_76 = labelSetText_CTLabel(id_20,
                                ((S_437)STATEOF(self_34))->text_18,
                                Inherit,
                                Inherit);
    Msg d_77;
    d_77 = labelSetPosition_CTLabel(id_20,
                                    ((S_437)STATEOF(self_34))->position_14,
                                    Inherit,
                                    Inherit);
    Msg d_78;
    d_78 = labelSetSize_CTLabel(id_20,
                                ((S_437)STATEOF(self_34))->size_15,
                                Inherit,
                                Inherit);
    Msg d_79;
    d_79 = labelSetTextColor_CTLabel(id_20,
                                     ((S_437)STATEOF(self_34))->textColor_17,
                                     Inherit,
                                     Inherit);
    return (TUP0)0;
}
static TUP0 f_1863 (T_1832 this_1861, Int a_1680) {
    Ref self_22;
    self_22 = (Ref)LOCK((OID)this_1861->self_12);
    ((S_437)STATEOF(self_22))->myState_13 = (CocoaState_CTCommon)0;
    UNLOCK((OID)self_22);
    return (TUP0)0;
}
static LIST f_1866 (T_1833 this_1864, Int a_1684) {
    Ref self_24;
    self_24 = (Ref)LOCK((OID)this_1864->self_12);
    LIST x_1681;
    x_1681 = ((S_437)STATEOF(self_24))->name_19;
    UNLOCK((OID)self_24);
    return x_1681;
}
static Position_CTCommon f_1869 (T_1834 this_1867, Int a_1688) {
    Ref self_26;
    self_26 = (Ref)LOCK((OID)this_1867->self_12);
    Position_CTCommon x_1685;
    x_1685 = ((S_437)STATEOF(self_26))->position_14;
    UNLOCK((OID)self_26);
    return x_1685;
}
static Size_CTCommon f_1872 (T_1835 this_1870, Int a_1692) {
    Ref self_28;
    self_28 = (Ref)LOCK((OID)this_1870->self_12);
    Size_CTCommon x_1689;
    x_1689 = ((S_437)STATEOF(self_28))->size_15;
    UNLOCK((OID)self_28);
    return x_1689;
}
static LIST f_1875 (T_1833 this_1873, Int a_1696) {
    Ref self_30;
    self_30 = (Ref)LOCK((OID)this_1873->self_12);
    LIST x_1693;
    x_1693 = ((S_437)STATEOF(self_30))->text_18;
    UNLOCK((OID)self_30);
    return x_1693;
}
static Color_CTCommon f_1878 (T_1836 this_1876, Int a_1700) {
    Ref self_32;
    self_32 = (Ref)LOCK((OID)this_1876->self_12);
    Color_CTCommon x_1697;
    x_1697 = ((S_437)STATEOF(self_32))->textColor_17;
    UNLOCK((OID)self_32);
    return x_1697;
}
static TUP0 f_1883 (T_1837 this_1879, CLOS a_1705, Int a_1706) {
    Ref self_37;
    self_37 = (Ref)LOCK((OID)this_1879->self_12);
    _Just_Prelude x_1882;
    NEW (_Just_Prelude, x_1882, WORDS(sizeof(struct _Just_Prelude)));
    x_1882->GCINFO = __GC___Just_Prelude+((4 * (BITS32)0));
    x_1882->a = (POLY)a_1705;
    ((S_437)STATEOF(self_37))->mouseEventHandler_16 = (Maybe_Prelude)x_1882;
    UNLOCK((OID)self_37);
    return (TUP0)0;
}
static TUP0 f_1887 (T_1838 this_1884, LIST a_1711, Int a_1712) {
    Ref self_40;
    self_40 = (Ref)LOCK((OID)this_1884->self_12);
    ((S_437)STATEOF(self_40))->name_19 = a_1711;
    UNLOCK((OID)self_40);
    return (TUP0)0;
}
static TUP0 f_1894 (T_1840 this_1892) {
    Ref self_43;
    self_43 = (Ref)LOCK((OID)this_1892->self_12);
    CocoaState_CTCommon x_1893;
    x_1893 = ((S_437)STATEOF(self_43))->myState_13;
    switch ((WORD)x_1893) {
        case 2: { Msg d_81;
                  d_81 = labelSetPosition_CTLabel(this_1892->id_20,
                                                  this_1892->a_1718,
                                                  Inherit,
                                                  Inherit);
                  break;
                }
                break;
        case 0: break;
        case 1: break;
    }
    ((S_437)STATEOF(self_43))->position_14 = this_1892->a_1718;
    UNLOCK((OID)self_43);
    return (TUP0)0;
}
static Msg f_1895 (T_1839 this_1888,
                   Position_CTCommon a_1718,
                   Time a_1719,
                   Time a_1720) {
    Msg x_1717;
    NEW (Msg, x_1717, WORDS(sizeof(struct T_1840)));
    ((T_1840)x_1717)->GCINFO = __GC__T_1840;
    ((T_1840)x_1717)->Code = f_1894;
    ((T_1840)x_1717)->a_1718 = a_1718;
    ((T_1840)x_1717)->id_20 = this_1888->id_20;
    ((T_1840)x_1717)->self_12 = this_1888->self_12;
    return (Msg)ASYNC(x_1717, a_1719, a_1720);
}
static TUP0 f_1901 (T_1842 this_1900) {
    Ref self_48;
    self_48 = (Ref)LOCK((OID)this_1900->self_12);
    ((S_437)STATEOF(self_48))->size_15 = this_1900->a_1726;
    UNLOCK((OID)self_48);
    return (TUP0)0;
}
static Msg f_1902 (T_1841 this_1896,
                   Size_CTCommon a_1726,
                   Time a_1727,
                   Time a_1728) {
    Msg x_1725;
    NEW (Msg, x_1725, WORDS(sizeof(struct T_1842)));
    ((T_1842)x_1725)->GCINFO = __GC__T_1842;
    ((T_1842)x_1725)->Code = f_1901;
    ((T_1842)x_1725)->a_1726 = a_1726;
    ((T_1842)x_1725)->self_12 = this_1896->self_12;
    return (Msg)ASYNC(x_1725, a_1727, a_1728);
}
static TUP0 f_1909 (T_1844 this_1907) {
    Ref self_51;
    self_51 = (Ref)LOCK((OID)this_1907->self_12);
    ((S_437)STATEOF(self_51))->text_18 = this_1907->a_1734;
    CocoaState_CTCommon x_1908;
    x_1908 = ((S_437)STATEOF(self_51))->myState_13;
    switch ((WORD)x_1908) {
        case 2: { Ref self_52;
                  self_52 = self_51;
                  Msg d_83;
                  d_83 = labelSetText_CTLabel(this_1907->id_20,
                                              this_1907->a_1734,
                                              Inherit,
                                              Inherit);
                  UNLOCK((OID)self_51);
                  return (TUP0)0;
                }
                break;
        case 0: { Ref self_53;
                  self_53 = self_51;
                  UNLOCK((OID)self_51);
                  return (TUP0)0;
                }
                break;
        case 1: { Ref self_53;
                  self_53 = self_51;
                  UNLOCK((OID)self_51);
                  return (TUP0)0;
                }
                break;
    }
}
static Msg f_1910 (T_1843 this_1903,
                   LIST a_1734,
                   Time a_1735,
                   Time a_1736) {
    Msg x_1733;
    NEW (Msg, x_1733, WORDS(sizeof(struct T_1844)));
    ((T_1844)x_1733)->GCINFO = __GC__T_1844;
    ((T_1844)x_1733)->Code = f_1909;
    ((T_1844)x_1733)->a_1734 = a_1734;
    ((T_1844)x_1733)->id_20 = this_1903->id_20;
    ((T_1844)x_1733)->self_12 = this_1903->self_12;
    return (Msg)ASYNC(x_1733, a_1735, a_1736);
}
static TUP0 f_1917 (T_1846 this_1915) {
    Ref self_56;
    self_56 = (Ref)LOCK((OID)this_1915->self_12);
    CocoaState_CTCommon x_1916;
    x_1916 = ((S_437)STATEOF(self_56))->myState_13;
    switch ((WORD)x_1916) {
        case 2: { Msg d_86;
                  d_86 = labelSetTextColor_CTLabel(this_1915->id_20,
                                                   this_1915->a_1742,
                                                   Inherit,
                                                   Inherit);
                  break;
                }
                break;
        case 0: break;
        case 1: break;
    }
    ((S_437)STATEOF(self_56))->textColor_17 = this_1915->a_1742;
    UNLOCK((OID)self_56);
    return (TUP0)0;
}
static Msg f_1918 (T_1845 this_1911,
                   Color_CTCommon a_1742,
                   Time a_1743,
                   Time a_1744) {
    Msg x_1741;
    NEW (Msg, x_1741, WORDS(sizeof(struct T_1846)));
    ((T_1846)x_1741)->GCINFO = __GC__T_1846;
    ((T_1846)x_1741)->Code = f_1917;
    ((T_1846)x_1741)->a_1742 = a_1742;
    ((T_1846)x_1741)->id_20 = this_1911->id_20;
    ((T_1846)x_1741)->self_12 = this_1911->self_12;
    return (Msg)ASYNC(x_1741, a_1743, a_1744);
}
static TUP0 f_1923 (T_1847 this_1919,
                    Maybe_Prelude a_1747,
                    Int a_1748) {
    IsFocusable_CTCommon x_1922;
    x_1922 = this_1919->focus_59;
    return x_1922->setNextFocusTarget_CTCommon(x_1922, a_1747, a_1748);
}
static Maybe_Prelude f_1927 (T_1848 this_1924, Int a_1750) {
    IsFocusable_CTCommon x_1926;
    x_1926 = this_1924->focus_59;
    return x_1926->getNextFocusTarget_CTCommon(x_1926, a_1750);
}
static TUP0 f_1932 (T_1847 this_1928,
                    Maybe_Prelude a_1753,
                    Int a_1754) {
    IsFocusable_CTCommon x_1931;
    x_1931 = this_1928->focus_59;
    return x_1931->setPreviousFocusTarget_CTCommon(x_1931,
                                                   a_1753,
                                                   a_1754);
}
static Maybe_Prelude f_1936 (T_1848 this_1933, Int a_1756) {
    IsFocusable_CTCommon x_1935;
    x_1935 = this_1933->focus_59;
    return x_1935->getPreviousFocusTarget_CTCommon(x_1935, a_1756);
}
static TUP0 f_1941 (T_1849 this_1937, Bool a_1759, Int a_1760) {
    IsFocusable_CTCommon x_1940;
    x_1940 = this_1937->focus_59;
    return x_1940->setIsFocusable_CTCommon(x_1940, a_1759, a_1760);
}
static Bool f_1945 (T_1850 this_1942, Int a_1762) {
    IsFocusable_CTCommon x_1944;
    x_1944 = this_1942->focus_59;
    return x_1944->getIsFocusable_CTCommon(x_1944, a_1762);
}
static Maybe_Prelude f_1951 (T_1851 this_1946,
                             CocoaEvent_CTCommon a_1768,
                             LIST a_1769,
                             Int a_1770) {
    switch (a_1768->Tag) {
        case 1: { MouseEventType_CTCommon x_92;
                  x_92 = ((_MouseEvent_CTCommon)a_1768)->a;
                  Ref self_71;
                  self_71 = (Ref)LOCK((OID)this_1946->self_12);
                  Bool x_90;
                  x_90 = dynamicHandleEvent_CTCommon((BITS32)0,
                                                     (POLY)x_92,
                                                     ((S_437)STATEOF(self_71))->mouseEventHandler_16,
                                                     self_71);
                  _Just_Prelude x_1950;
                  NEW (_Just_Prelude, x_1950, WORDS(sizeof(struct _Just_Prelude)));
                  x_1950->GCINFO = __GC___Just_Prelude+((4 * (BITS32)0));
                  x_1950->a = (POLY)this_1946->this_68->l_Label_CTLabel_Component_CTCommon_CTLabel;
                  Maybe_Prelude x_1763;
                  x_1763 = boolToMaybe_CTCommon((BITS32)0,
                                                (Maybe_Prelude)x_1950,
                                                x_90);
                  UNLOCK((OID)self_71);
                  return x_1763;
                }
                break;
        default: { Ref self_73;
                   self_73 = (Ref)LOCK((OID)this_1946->self_12);
                   UNLOCK((OID)self_73);
                   return (Maybe_Prelude)1;
                 }
                 break;
    }
}
static TUP0 f_1955 (T_1852 this_1952,
                    App_CTCommon a_1773,
                    Int a_1774) {
    Ref self_75;
    self_75 = (Ref)LOCK((OID)this_1952->self_12);
    ((S_437)STATEOF(self_75))->myState_13 = (CocoaState_CTCommon)2;
    TUP0 d_93;
    d_93 = initLabel_CTLabel(this_1952->this_68, a_1773, 0);
    TUP0 d_94;
    d_94 = inithelper_33(this_1952->id_20, self_75);
    UNLOCK((OID)self_75);
    return (TUP0)0;
}
static Bool f_1959 (T_1855 this_1956, Int a_1776) {
    CLOS x_1958;
    x_1958 = this_1956->x_1775;
    return ((Bool(*)(CLOS, Int))(x_1958->Code))(x_1958, a_1776);
}
static Maybe_Prelude f_1963 (T_1855 this_1960, Int a_1778) {
    CLOS x_1962;
    x_1962 = this_1960->x_1777;
    return ((Maybe_Prelude(*)(CLOS, Int))(x_1962->Code))(x_1962,
                                                         a_1778);
}
static Maybe_Prelude f_1967 (T_1855 this_1964, Int a_1780) {
    CLOS x_1966;
    x_1966 = this_1964->x_1779;
    return ((Maybe_Prelude(*)(CLOS, Int))(x_1966->Code))(x_1966,
                                                         a_1780);
}
static TUP0 f_1972 (T_1855 this_1968, Bool a_1782, Int a_1783) {
    CLOS x_1971;
    x_1971 = this_1968->x_1781;
    return ((TUP0(*)(CLOS, Bool, Int))(x_1971->Code))(x_1971,
                                                      a_1782,
                                                      a_1783);
}
static TUP0 f_1977 (T_1855 this_1973,
                    Maybe_Prelude a_1785,
                    Int a_1786) {
    CLOS x_1976;
    x_1976 = this_1973->x_1784;
    return ((TUP0(*)(CLOS, Maybe_Prelude, Int))(x_1976->Code))(x_1976,
                                                               a_1785,
                                                               a_1786);
}
static TUP0 f_1982 (T_1855 this_1978,
                    Maybe_Prelude a_1788,
                    Int a_1789) {
    CLOS x_1981;
    x_1981 = this_1978->x_1787;
    return ((TUP0(*)(CLOS, Maybe_Prelude, Int))(x_1981->Code))(x_1981,
                                                               a_1788,
                                                               a_1789);
}
static Position_CTCommon f_1987 (T_1857 this_1984, Int a_1791) {
    CLOS x_1986;
    x_1986 = this_1984->x_1790;
    return ((Position_CTCommon(*)(CLOS, Int))(x_1986->Code))(x_1986,
                                                             a_1791);
}
static Msg f_1993 (T_1857 this_1988,
                   Position_CTCommon a_1793,
                   Time a_1794,
                   Time a_1795) {
    CLOS x_1992;
    x_1992 = this_1988->x_1792;
    return ((Msg(*)(CLOS, Position_CTCommon, Time, Time))(x_1992->Code))(x_1992,
                                                                         a_1793,
                                                                         a_1794,
                                                                         a_1795);
}
static Size_CTCommon f_1998 (T_1856 this_1995, Int a_1797) {
    CLOS x_1997;
    x_1997 = this_1995->x_1796;
    return ((Size_CTCommon(*)(CLOS, Int))(x_1997->Code))(x_1997,
                                                         a_1797);
}
static Msg f_2004 (T_1856 this_1999,
                   Size_CTCommon a_1799,
                   Time a_1800,
                   Time a_1801) {
    CLOS x_2003;
    x_2003 = this_1999->x_1798;
    return ((Msg(*)(CLOS, Size_CTCommon, Time, Time))(x_2003->Code))(x_2003,
                                                                     a_1799,
                                                                     a_1800,
                                                                     a_1801);
}
static Maybe_Prelude f_2011 (T_1858 this_2006,
                             CocoaEvent_CTCommon a_1803,
                             LIST a_1804,
                             Int a_1805) {
    CLOS x_2010;
    x_2010 = this_2006->x_1802;
    return ((Maybe_Prelude(*)(CLOS, CocoaEvent_CTCommon, LIST, Int))(x_2010->Code))(x_2010,
                                                                                    a_1803,
                                                                                    a_1804,
                                                                                    a_1805);
}
static TUP0 f_2016 (T_1854 this_2013, Int a_1807) {
    CLOS x_2015;
    x_2015 = this_2013->x_1806;
    return ((TUP0(*)(CLOS, Int))(x_2015->Code))(x_2015, a_1807);
}
static LIST f_2020 (T_1854 this_2017, Int a_1809) {
    CLOS x_2019;
    x_2019 = this_2017->x_1808;
    return ((LIST(*)(CLOS, Int))(x_2019->Code))(x_2019, a_1809);
}
static TUP0 f_2025 (T_1854 this_2021,
                    App_CTCommon a_1811,
                    Int a_1812) {
    CLOS x_2024;
    x_2024 = this_2021->x_1810;
    return ((TUP0(*)(CLOS, App_CTCommon, Int))(x_2024->Code))(x_2024,
                                                              a_1811,
                                                              a_1812);
}
static TUP0 f_2030 (T_1854 this_2026, LIST a_1814, Int a_1815) {
    CLOS x_2029;
    x_2029 = this_2026->x_1813;
    return ((TUP0(*)(CLOS, LIST, Int))(x_2029->Code))(x_2029,
                                                      a_1814,
                                                      a_1815);
}
static TUP0 f_2036 (T_1859 this_2032, CLOS a_1817, Int a_1818) {
    CLOS x_2035;
    x_2035 = this_2032->x_1816;
    return ((TUP0(*)(CLOS, CLOS, Int))(x_2035->Code))(x_2035,
                                                      a_1817,
                                                      a_1818);
}
static LIST f_2041 (T_1853 this_2038, Int a_1820) {
    CLOS x_2040;
    x_2040 = this_2038->x_1819;
    return ((LIST(*)(CLOS, Int))(x_2040->Code))(x_2040, a_1820);
}
static Color_CTCommon f_2045 (T_1853 this_2042, Int a_1822) {
    CLOS x_2044;
    x_2044 = this_2042->x_1821;
    return ((Color_CTCommon(*)(CLOS, Int))(x_2044->Code))(x_2044,
                                                          a_1822);
}
static Msg f_2051 (T_1853 this_2046,
                   LIST a_1824,
                   Time a_1825,
                   Time a_1826) {
    CLOS x_2050;
    x_2050 = this_2046->x_1823;
    return ((Msg(*)(CLOS, LIST, Time, Time))(x_2050->Code))(x_2050,
                                                            a_1824,
                                                            a_1825,
                                                            a_1826);
}
static Msg f_2057 (T_1853 this_2052,
                   Color_CTCommon a_1828,
                   Time a_1829,
                   Time a_1830) {
    CLOS x_2056;
    x_2056 = this_2052->x_1827;
    return ((Msg(*)(CLOS, Color_CTCommon, Time, Time))(x_2056->Code))(x_2056,
                                                                      a_1828,
                                                                      a_1829,
                                                                      a_1830);
}
 
void _init_CTLabel () {
    static int INITIALIZED = 0;
    if (!INITIALIZED) {
        _init_Prelude();
        _init_CTCommon();
        INITIALIZED = 1;
    }
}
 

