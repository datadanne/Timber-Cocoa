#include "CTLabel.h"
#include "CTLabel.extern.c"
 
struct S_479;
typedef struct S_479 *S_479;
struct T_1932;
typedef struct T_1932 *T_1932;
struct T_1931;
typedef struct T_1931 *T_1931;
struct T_1930;
typedef struct T_1930 *T_1930;
struct T_1929;
typedef struct T_1929 *T_1929;
struct T_1928;
typedef struct T_1928 *T_1928;
struct T_1927;
typedef struct T_1927 *T_1927;
struct T_1926;
typedef struct T_1926 *T_1926;
struct T_1925;
typedef struct T_1925 *T_1925;
struct T_1924;
typedef struct T_1924 *T_1924;
struct T_1923;
typedef struct T_1923 *T_1923;
struct T_1922;
typedef struct T_1922 *T_1922;
struct T_1921;
typedef struct T_1921 *T_1921;
struct T_1920;
typedef struct T_1920 *T_1920;
struct T_1919;
typedef struct T_1919 *T_1919;
struct T_1918;
typedef struct T_1918 *T_1918;
struct T_1917;
typedef struct T_1917 *T_1917;
struct T_1916;
typedef struct T_1916 *T_1916;
struct T_1915;
typedef struct T_1915 *T_1915;
struct T_1914;
typedef struct T_1914 *T_1914;
struct T_1913;
typedef struct T_1913 *T_1913;
struct T_1912;
typedef struct T_1912 *T_1912;
struct T_1911;
typedef struct T_1911 *T_1911;
struct T_1910;
typedef struct T_1910 *T_1910;
struct T_1909;
typedef struct T_1909 *T_1909;
struct T_1908;
typedef struct T_1908 *T_1908;
struct T_1907;
typedef struct T_1907 *T_1907;
struct T_1906;
typedef struct T_1906 *T_1906;
struct T_1905;
typedef struct T_1905 *T_1905;
struct T_1904;
typedef struct T_1904 *T_1904;
struct T_1903;
typedef struct T_1903 *T_1903;
struct T_1902;
typedef struct T_1902 *T_1902;
 
struct S_479 {
    POLY GCINFO;
    Position_CTCommon position_13;
    Size_CTCommon size_14;
    Maybe_Prelude mouseEventHandler_15;
    Color_CTCommon textColor_16;
    LIST text_17;
};
struct T_1932 {
    POLY GCINFO;
    TUP0 (*installMouseListener_CTCommon) (T_1932, CLOS, Int);
    CLOS x_1886;
};
struct T_1931 {
    POLY GCINFO;
    Maybe_Prelude (*handleEvent_CTCommon) (T_1931,
                                           CocoaEvent_CTCommon,
                                           LIST,
                                           Int);
    CLOS x_1877;
};
struct T_1930 {
    POLY GCINFO;
    TUP0 (*setPosition_CTCommon) (T_1930, Position_CTCommon, Int);
    Position_CTCommon (*getPosition_CTCommon) (T_1930, Int);
    CLOS x_1850;
    CLOS x_1852;
};
struct T_1929 {
    POLY GCINFO;
    HasPosition_CTCommon l_HasSize_CTCommon_HasPosition_CTCommon_CTCommon;
    TUP0 (*setSize_CTCommon) (T_1929, Size_CTCommon, Int);
    Size_CTCommon (*getSize_CTCommon) (T_1929, Int);
    CLOS x_1855;
    CLOS x_1857;
};
struct T_1928 {
    POLY GCINFO;
    TUP0 (*setIsFocusable_CTCommon) (T_1928, Bool, Int);
    Bool (*getIsFocusable_CTCommon) (T_1928, Int);
    CLOS x_1845;
    CLOS x_1847;
};
struct T_1927 {
    POLY GCINFO;
    IsFocusable_CTCommon l_AbstractComponent_CTCommon_IsFocusable_CTCommon_CTCommon;
    HasSize_CTCommon l_AbstractComponent_CTCommon_HasSize_CTCommon_CTCommon;
    TUP0 (*setName_CTCommon) (T_1927, LIST, Int);
    LIST (*getName_CTCommon) (T_1927, Int);
    TUP0 (*setParent_CTCommon) (T_1927, Maybe_Prelude, Int);
    Maybe_Prelude (*getParent_CTCommon) (T_1927, Int);
    TUP0 (*setState_CTCommon) (T_1927, CocoaState_CTCommon, Int);
    CocoaState_CTCommon (*getState_CTCommon) (T_1927, Int);
    LIST (*getAllComponents_CTCommon) (T_1927, Int);
    CLOS x_1860;
    CLOS x_1862;
    CLOS x_1864;
    CLOS x_1866;
    CLOS x_1868;
    CLOS x_1871;
    CLOS x_1874;
};
struct T_1926 {
    POLY GCINFO;
    AbstractComponent_CTCommon l_Component_CTCommon_AbstractComponent_CTCommon_CTCommon;
    HandlesEvents_CTCommon l_Component_CTCommon_HandlesEvents_CTCommon_CTCommon;
    CocoaID_CTCommon id_CTCommon;
    TUP0 (*init_CTCommon) (T_1926, App_CTCommon, Int);
    TUP0 (*destroy_CTCommon) (T_1926, Int);
    CLOS x_1881;
    CLOS x_1883;
};
struct T_1925 {
    POLY GCINFO;
    Component_CTCommon l_Label_CTLabel_Component_CTCommon_CTLabel;
    HandlesMouseEvents_CTCommon l_Label_CTLabel_HandlesMouseEvents_CTCommon_CTLabel;
    Msg (*setText_CTLabel) (T_1925, LIST, Time, Time);
    LIST (*getText_CTLabel) (T_1925, Int);
    Msg (*setTextColor_CTLabel) (T_1925, Color_CTCommon, Time, Time);
    Color_CTCommon (*getTextColor_CTLabel) (T_1925, Int);
    CLOS x_1889;
    CLOS x_1891;
    CLOS x_1893;
    CLOS x_1897;
};
struct T_1924 {
    POLY GCINFO;
    TUP0 (*Code) (T_1924, App_CTCommon, Int);
    Label_CTLabel this_64;
    AbstractComponent_CTCommon base_19;
    CocoaID_CTCommon id_18;
    Ref self_12;
};
struct T_1923 {
    POLY GCINFO;
    Maybe_Prelude (*Code) (T_1923, CocoaEvent_CTCommon, LIST, Int);
    Label_CTLabel this_64;
    Ref self_12;
};
struct T_1922 {
    POLY GCINFO;
    TUP0 (*Code) (T_1922, CLOS, Int);
    Ref self_12;
};
struct T_1921 {
    POLY GCINFO;
    TUP0 (*Code) (T_1921, Int);
    AbstractComponent_CTCommon base_19;
    Ref self_12;
};
struct T_1920 {
    POLY GCINFO;
    Size_CTCommon (*Code) (T_1920, Int);
    Ref self_12;
};
struct T_1919 {
    POLY GCINFO;
    TUP0 (*Code) (T_1919, Size_CTCommon, Int);
    Ref self_12;
};
struct T_1918 {
    POLY GCINFO;
    Position_CTCommon (*Code) (T_1918, Int);
    Ref self_12;
};
struct T_1917 {
    POLY GCINFO;
    TUP0 (*Code) (T_1917, Position_CTCommon, Int);
    AbstractComponent_CTCommon base_19;
    CocoaID_CTCommon id_18;
    Ref self_12;
};
struct T_1916 {
    POLY GCINFO;
    Color_CTCommon (*Code) (T_1916, Int);
    Ref self_12;
};
struct T_1915 {
    POLY GCINFO;
    TUP0 (*Code) (T_1915);
    AbsTime baseline;
    AbsTime deadline;
    Msg next;
    Color_CTCommon a_1799;
    AbstractComponent_CTCommon base_19;
    CocoaID_CTCommon id_18;
    Ref self_12;
};
struct T_1914 {
    POLY GCINFO;
    Msg (*Code) (T_1914, Color_CTCommon, Time, Time);
    AbstractComponent_CTCommon base_19;
    CocoaID_CTCommon id_18;
    Ref self_12;
};
struct T_1913 {
    POLY GCINFO;
    LIST (*Code) (T_1913, Int);
    Ref self_12;
};
struct T_1912 {
    POLY GCINFO;
    TUP0 (*Code) (T_1912);
    AbsTime baseline;
    AbsTime deadline;
    Msg next;
    LIST a_1787;
    AbstractComponent_CTCommon base_19;
    CocoaID_CTCommon id_18;
    Ref self_12;
};
struct T_1911 {
    POLY GCINFO;
    Msg (*Code) (T_1911, LIST, Time, Time);
    AbstractComponent_CTCommon base_19;
    CocoaID_CTCommon id_18;
    Ref self_12;
};
struct T_1910 {
    POLY GCINFO;
    LIST (*Code) (T_1910, Int);
    AbstractComponent_CTCommon base_19;
};
struct T_1909 {
    POLY GCINFO;
    TUP0 (*Code) (T_1909, CocoaState_CTCommon, Int);
    AbstractComponent_CTCommon base_19;
};
struct T_1908 {
    POLY GCINFO;
    CocoaState_CTCommon (*Code) (T_1908, Int);
    AbstractComponent_CTCommon base_19;
};
struct T_1907 {
    POLY GCINFO;
    LIST (*Code) (T_1907, Int);
    AbstractComponent_CTCommon base_19;
};
struct T_1906 {
    POLY GCINFO;
    TUP0 (*Code) (T_1906, LIST, Int);
    AbstractComponent_CTCommon base_19;
};
struct T_1905 {
    POLY GCINFO;
    Bool (*Code) (T_1905, Int);
    AbstractComponent_CTCommon base_19;
};
struct T_1904 {
    POLY GCINFO;
    TUP0 (*Code) (T_1904, Bool, Int);
    AbstractComponent_CTCommon base_19;
};
struct T_1903 {
    POLY GCINFO;
    Maybe_Prelude (*Code) (T_1903, Int);
    AbstractComponent_CTCommon base_19;
};
struct T_1902 {
    POLY GCINFO;
    TUP0 (*Code) (T_1902, Maybe_Prelude, Int);
    AbstractComponent_CTCommon base_19;
};
 
static WORD __GC__S_479[];
static WORD __GC__T_1932[];
static WORD __GC__T_1931[];
static WORD __GC__T_1930[];
static WORD __GC__T_1929[];
static WORD __GC__T_1928[];
static WORD __GC__T_1927[];
static WORD __GC__T_1926[];
static WORD __GC__T_1925[];
static WORD __GC__T_1924[];
static WORD __GC__T_1923[];
static WORD __GC__T_1922[];
static WORD __GC__T_1921[];
static WORD __GC__T_1920[];
static WORD __GC__T_1919[];
static WORD __GC__T_1918[];
static WORD __GC__T_1917[];
static WORD __GC__T_1916[];
static WORD __GC__T_1915[];
static WORD __GC__T_1914[];
static WORD __GC__T_1913[];
static WORD __GC__T_1912[];
static WORD __GC__T_1911[];
static WORD __GC__T_1910[];
static WORD __GC__T_1909[];
static WORD __GC__T_1908[];
static WORD __GC__T_1907[];
static WORD __GC__T_1906[];
static WORD __GC__T_1905[];
static WORD __GC__T_1904[];
static WORD __GC__T_1903[];
static WORD __GC__T_1902[];
static TUP0 inithelper_60 (CocoaID_CTCommon id_18, Ref self_61);
static TUP0 f_1938 (T_1902 this_1934,
                    Maybe_Prelude a_1758,
                    Int a_1759);
static Maybe_Prelude f_1942 (T_1903 this_1939, Int a_1761);
static TUP0 f_1947 (T_1904 this_1943, Bool a_1764, Int a_1765);
static Bool f_1951 (T_1905 this_1948, Int a_1767);
static TUP0 f_1956 (T_1906 this_1952, LIST a_1770, Int a_1771);
static LIST f_1960 (T_1907 this_1957, Int a_1773);
static CocoaState_CTCommon f_1964 (T_1908 this_1961, Int a_1775);
static TUP0 f_1969 (T_1909 this_1965,
                    CocoaState_CTCommon a_1778,
                    Int a_1779);
static LIST f_1973 (T_1910 this_1970, Int a_1781);
static TUP0 f_1980 (T_1912 this_1978);
static Msg f_1981 (T_1911 this_1974,
                   LIST a_1787,
                   Time a_1788,
                   Time a_1789);
static LIST f_1984 (T_1913 this_1982, Int a_1793);
static TUP0 f_1991 (T_1915 this_1989);
static Msg f_1992 (T_1914 this_1985,
                   Color_CTCommon a_1799,
                   Time a_1800,
                   Time a_1801);
static Color_CTCommon f_1995 (T_1916 this_1993, Int a_1805);
static TUP0 f_2000 (T_1917 this_1996,
                    Position_CTCommon a_1808,
                    Int a_1809);
static Position_CTCommon f_2003 (T_1918 this_2001, Int a_1813);
static TUP0 f_2007 (T_1919 this_2004,
                    Size_CTCommon a_1816,
                    Int a_1817);
static Size_CTCommon f_2010 (T_1920 this_2008, Int a_1821);
static TUP0 f_2014 (T_1921 this_2011, Int a_1824);
static TUP0 f_2019 (T_1922 this_2015, CLOS a_1829, Int a_1830);
static Maybe_Prelude f_2025 (T_1923 this_2020,
                             CocoaEvent_CTCommon a_1838,
                             LIST a_1839,
                             Int a_1840);
static TUP0 f_2030 (T_1924 this_2026,
                    App_CTCommon a_1843,
                    Int a_1844);
static Bool f_2034 (T_1928 this_2031, Int a_1846);
static TUP0 f_2039 (T_1928 this_2035, Bool a_1848, Int a_1849);
static Position_CTCommon f_2044 (T_1930 this_2041, Int a_1851);
static TUP0 f_2049 (T_1930 this_2045,
                    Position_CTCommon a_1853,
                    Int a_1854);
static Size_CTCommon f_2054 (T_1929 this_2051, Int a_1856);
static TUP0 f_2059 (T_1929 this_2055,
                    Size_CTCommon a_1858,
                    Int a_1859);
static LIST f_2064 (T_1927 this_2061, Int a_1861);
static LIST f_2068 (T_1927 this_2065, Int a_1863);
static Maybe_Prelude f_2072 (T_1927 this_2069, Int a_1865);
static CocoaState_CTCommon f_2076 (T_1927 this_2073, Int a_1867);
static TUP0 f_2081 (T_1927 this_2077, LIST a_1869, Int a_1870);
static TUP0 f_2086 (T_1927 this_2082,
                    Maybe_Prelude a_1872,
                    Int a_1873);
static TUP0 f_2091 (T_1927 this_2087,
                    CocoaState_CTCommon a_1875,
                    Int a_1876);
static Maybe_Prelude f_2098 (T_1931 this_2093,
                             CocoaEvent_CTCommon a_1878,
                             LIST a_1879,
                             Int a_1880);
static TUP0 f_2103 (T_1926 this_2100, Int a_1882);
static TUP0 f_2108 (T_1926 this_2104,
                    App_CTCommon a_1884,
                    Int a_1885);
static TUP0 f_2114 (T_1932 this_2110, CLOS a_1887, Int a_1888);
static LIST f_2119 (T_1925 this_2116, Int a_1890);
static Color_CTCommon f_2123 (T_1925 this_2120, Int a_1892);
static Msg f_2129 (T_1925 this_2124,
                   LIST a_1894,
                   Time a_1895,
                   Time a_1896);
static Msg f_2135 (T_1925 this_2130,
                   Color_CTCommon a_1898,
                   Time a_1899,
                   Time a_1900);
 
WORD __GC__Label_CTLabel[] = {WORDS(sizeof(struct Label_CTLabel)),
                              0,
                              WORDS(offsetof(struct Label_CTLabel, l_Label_CTLabel_Component_CTCommon_CTLabel)),
                              WORDS(offsetof(struct Label_CTLabel, l_Label_CTLabel_HandlesMouseEvents_CTCommon_CTLabel)),
                              0};
static WORD __GC__S_479[] = {WORDS(sizeof(struct S_479)),
                             0,
                             WORDS(offsetof(struct S_479, position_13)),
                             WORDS(offsetof(struct S_479, size_14)),
                             WORDS(offsetof(struct S_479, mouseEventHandler_15)),
                             WORDS(offsetof(struct S_479, textColor_16)),
                             WORDS(offsetof(struct S_479, text_17)),
                             0};
static WORD __GC__T_1932[] = {WORDS(sizeof(struct T_1932)),
                              0,
                              WORDS(offsetof(struct T_1932, x_1886)),
                              0};
static WORD __GC__T_1931[] = {WORDS(sizeof(struct T_1931)),
                              0,
                              WORDS(offsetof(struct T_1931, x_1877)),
                              0};
static WORD __GC__T_1930[] = {WORDS(sizeof(struct T_1930)),
                              0,
                              WORDS(offsetof(struct T_1930, x_1850)),
                              WORDS(offsetof(struct T_1930, x_1852)),
                              0};
static WORD __GC__T_1929[] = {WORDS(sizeof(struct T_1929)),
                              0,
                              WORDS(offsetof(struct T_1929, l_HasSize_CTCommon_HasPosition_CTCommon_CTCommon)),
                              WORDS(offsetof(struct T_1929, x_1855)),
                              WORDS(offsetof(struct T_1929, x_1857)),
                              0};
static WORD __GC__T_1928[] = {WORDS(sizeof(struct T_1928)),
                              0,
                              WORDS(offsetof(struct T_1928, x_1845)),
                              WORDS(offsetof(struct T_1928, x_1847)),
                              0};
static WORD __GC__T_1927[] = {WORDS(sizeof(struct T_1927)),
                              0,
                              WORDS(offsetof(struct T_1927, l_AbstractComponent_CTCommon_IsFocusable_CTCommon_CTCommon)),
                              WORDS(offsetof(struct T_1927, l_AbstractComponent_CTCommon_HasSize_CTCommon_CTCommon)),
                              WORDS(offsetof(struct T_1927, x_1860)),
                              WORDS(offsetof(struct T_1927, x_1862)),
                              WORDS(offsetof(struct T_1927, x_1864)),
                              WORDS(offsetof(struct T_1927, x_1866)),
                              WORDS(offsetof(struct T_1927, x_1868)),
                              WORDS(offsetof(struct T_1927, x_1871)),
                              WORDS(offsetof(struct T_1927, x_1874)),
                              0};
static WORD __GC__T_1926[] = {WORDS(sizeof(struct T_1926)),
                              0,
                              WORDS(offsetof(struct T_1926, l_Component_CTCommon_AbstractComponent_CTCommon_CTCommon)),
                              WORDS(offsetof(struct T_1926, l_Component_CTCommon_HandlesEvents_CTCommon_CTCommon)),
                              WORDS(offsetof(struct T_1926, id_CTCommon)),
                              WORDS(offsetof(struct T_1926, x_1881)),
                              WORDS(offsetof(struct T_1926, x_1883)),
                              0};
static WORD __GC__T_1925[] = {WORDS(sizeof(struct T_1925)),
                              0,
                              WORDS(offsetof(struct T_1925, l_Label_CTLabel_Component_CTCommon_CTLabel)),
                              WORDS(offsetof(struct T_1925, l_Label_CTLabel_HandlesMouseEvents_CTCommon_CTLabel)),
                              WORDS(offsetof(struct T_1925, x_1889)),
                              WORDS(offsetof(struct T_1925, x_1891)),
                              WORDS(offsetof(struct T_1925, x_1893)),
                              WORDS(offsetof(struct T_1925, x_1897)),
                              0};
static WORD __GC__T_1924[] = {WORDS(sizeof(struct T_1924)),
                              0,
                              WORDS(offsetof(struct T_1924, this_64)),
                              WORDS(offsetof(struct T_1924, base_19)),
                              WORDS(offsetof(struct T_1924, id_18)),
                              WORDS(offsetof(struct T_1924, self_12)),
                              0};
static WORD __GC__T_1923[] = {WORDS(sizeof(struct T_1923)),
                              0,
                              WORDS(offsetof(struct T_1923, this_64)),
                              WORDS(offsetof(struct T_1923, self_12)),
                              0};
static WORD __GC__T_1922[] = {WORDS(sizeof(struct T_1922)),
                              0,
                              WORDS(offsetof(struct T_1922, self_12)),
                              0};
static WORD __GC__T_1921[] = {WORDS(sizeof(struct T_1921)),
                              0,
                              WORDS(offsetof(struct T_1921, base_19)),
                              WORDS(offsetof(struct T_1921, self_12)),
                              0};
static WORD __GC__T_1920[] = {WORDS(sizeof(struct T_1920)),
                              0,
                              WORDS(offsetof(struct T_1920, self_12)),
                              0};
static WORD __GC__T_1919[] = {WORDS(sizeof(struct T_1919)),
                              0,
                              WORDS(offsetof(struct T_1919, self_12)),
                              0};
static WORD __GC__T_1918[] = {WORDS(sizeof(struct T_1918)),
                              0,
                              WORDS(offsetof(struct T_1918, self_12)),
                              0};
static WORD __GC__T_1917[] = {WORDS(sizeof(struct T_1917)),
                              0,
                              WORDS(offsetof(struct T_1917, base_19)),
                              WORDS(offsetof(struct T_1917, id_18)),
                              WORDS(offsetof(struct T_1917, self_12)),
                              0};
static WORD __GC__T_1916[] = {WORDS(sizeof(struct T_1916)),
                              0,
                              WORDS(offsetof(struct T_1916, self_12)),
                              0};
static WORD __GC__T_1915[] = {WORDS(sizeof(struct T_1915)),
                              0,
                              WORDS(offsetof(struct T_1915, a_1799)),
                              WORDS(offsetof(struct T_1915, base_19)),
                              WORDS(offsetof(struct T_1915, id_18)),
                              WORDS(offsetof(struct T_1915, self_12)),
                              0};
static WORD __GC__T_1914[] = {WORDS(sizeof(struct T_1914)),
                              0,
                              WORDS(offsetof(struct T_1914, base_19)),
                              WORDS(offsetof(struct T_1914, id_18)),
                              WORDS(offsetof(struct T_1914, self_12)),
                              0};
static WORD __GC__T_1913[] = {WORDS(sizeof(struct T_1913)),
                              0,
                              WORDS(offsetof(struct T_1913, self_12)),
                              0};
static WORD __GC__T_1912[] = {WORDS(sizeof(struct T_1912)),
                              0,
                              WORDS(offsetof(struct T_1912, a_1787)),
                              WORDS(offsetof(struct T_1912, base_19)),
                              WORDS(offsetof(struct T_1912, id_18)),
                              WORDS(offsetof(struct T_1912, self_12)),
                              0};
static WORD __GC__T_1911[] = {WORDS(sizeof(struct T_1911)),
                              0,
                              WORDS(offsetof(struct T_1911, base_19)),
                              WORDS(offsetof(struct T_1911, id_18)),
                              WORDS(offsetof(struct T_1911, self_12)),
                              0};
static WORD __GC__T_1910[] = {WORDS(sizeof(struct T_1910)),
                              0,
                              WORDS(offsetof(struct T_1910, base_19)),
                              0};
static WORD __GC__T_1909[] = {WORDS(sizeof(struct T_1909)),
                              0,
                              WORDS(offsetof(struct T_1909, base_19)),
                              0};
static WORD __GC__T_1908[] = {WORDS(sizeof(struct T_1908)),
                              0,
                              WORDS(offsetof(struct T_1908, base_19)),
                              0};
static WORD __GC__T_1907[] = {WORDS(sizeof(struct T_1907)),
                              0,
                              WORDS(offsetof(struct T_1907, base_19)),
                              0};
static WORD __GC__T_1906[] = {WORDS(sizeof(struct T_1906)),
                              0,
                              WORDS(offsetof(struct T_1906, base_19)),
                              0};
static WORD __GC__T_1905[] = {WORDS(sizeof(struct T_1905)),
                              0,
                              WORDS(offsetof(struct T_1905, base_19)),
                              0};
static WORD __GC__T_1904[] = {WORDS(sizeof(struct T_1904)),
                              0,
                              WORDS(offsetof(struct T_1904, base_19)),
                              0};
static WORD __GC__T_1903[] = {WORDS(sizeof(struct T_1903)),
                              0,
                              WORDS(offsetof(struct T_1903, base_19)),
                              0};
static WORD __GC__T_1902[] = {WORDS(sizeof(struct T_1902)),
                              0,
                              WORDS(offsetof(struct T_1902, base_19)),
                              0};
Component_CTCommon c_397_CTLabel (Label_CTLabel v_399) {
    return v_399->l_Label_CTLabel_Component_CTCommon_CTLabel;
}
HandlesMouseEvents_CTCommon c_400_CTLabel (Label_CTLabel v_402) {
    return v_402->l_Label_CTLabel_HandlesMouseEvents_CTCommon_CTLabel;
}
AbstractComponent_CTCommon c_404_CTLabel (Label_CTLabel a_403) {
    return a_403->l_Label_CTLabel_Component_CTCommon_CTLabel->l_Component_CTCommon_AbstractComponent_CTCommon_CTCommon;
}
HandlesEvents_CTCommon c_406_CTLabel (Label_CTLabel a_405) {
    return a_405->l_Label_CTLabel_Component_CTCommon_CTLabel->l_Component_CTCommon_HandlesEvents_CTCommon_CTCommon;
}
IsFocusable_CTCommon c_408_CTLabel (Label_CTLabel a_407) {
    return a_407->l_Label_CTLabel_Component_CTCommon_CTLabel->l_Component_CTCommon_AbstractComponent_CTCommon_CTCommon->l_AbstractComponent_CTCommon_IsFocusable_CTCommon_CTCommon;
}
HasSize_CTCommon c_410_CTLabel (Label_CTLabel a_409) {
    return a_409->l_Label_CTLabel_Component_CTCommon_CTLabel->l_Component_CTCommon_AbstractComponent_CTCommon_CTCommon->l_AbstractComponent_CTCommon_HasSize_CTCommon_CTCommon;
}
HasPosition_CTCommon c_412_CTLabel (Label_CTLabel a_411) {
    return a_411->l_Label_CTLabel_Component_CTCommon_CTLabel->l_Component_CTCommon_AbstractComponent_CTCommon_CTCommon->l_AbstractComponent_CTCommon_HasSize_CTCommon_CTCommon->l_HasSize_CTCommon_HasPosition_CTCommon_CTCommon;
}
Label_CTLabel mkCocoaLabel_CTLabel (Int d_1901) {
    Ref self_12;
    NEW (Ref, self_12, WORDS(sizeof(struct Ref))+
                       WORDS(sizeof(struct S_479)));
    INITREF(self_12);
    ((S_479)STATEOF(self_12))->GCINFO = __GC__S_479;
    CocoaID_CTCommon id_18;
    id_18 = mkCocoaID_CTCommon(0);
    AbstractComponent_CTCommon base_19;
    base_19 = basicComponent_CTCommon((Bool)0,
                                      (Maybe_Prelude)1,
                                      getStr("Label"),
                                      0);
    CLOS setParent_20;
    NEW (CLOS, setParent_20, WORDS(sizeof(struct T_1902)));
    ((T_1902)setParent_20)->GCINFO = __GC__T_1902;
    ((T_1902)setParent_20)->Code = f_1938;
    ((T_1902)setParent_20)->base_19 = base_19;
    CLOS getParent_21;
    NEW (CLOS, getParent_21, WORDS(sizeof(struct T_1903)));
    ((T_1903)getParent_21)->GCINFO = __GC__T_1903;
    ((T_1903)getParent_21)->Code = f_1942;
    ((T_1903)getParent_21)->base_19 = base_19;
    CLOS setIsFocusable_22;
    NEW (CLOS, setIsFocusable_22, WORDS(sizeof(struct T_1904)));
    ((T_1904)setIsFocusable_22)->GCINFO = __GC__T_1904;
    ((T_1904)setIsFocusable_22)->Code = f_1947;
    ((T_1904)setIsFocusable_22)->base_19 = base_19;
    CLOS getIsFocusable_23;
    NEW (CLOS, getIsFocusable_23, WORDS(sizeof(struct T_1905)));
    ((T_1905)getIsFocusable_23)->GCINFO = __GC__T_1905;
    ((T_1905)getIsFocusable_23)->Code = f_1951;
    ((T_1905)getIsFocusable_23)->base_19 = base_19;
    CLOS setName_24;
    NEW (CLOS, setName_24, WORDS(sizeof(struct T_1906)));
    ((T_1906)setName_24)->GCINFO = __GC__T_1906;
    ((T_1906)setName_24)->Code = f_1956;
    ((T_1906)setName_24)->base_19 = base_19;
    CLOS getName_25;
    NEW (CLOS, getName_25, WORDS(sizeof(struct T_1907)));
    ((T_1907)getName_25)->GCINFO = __GC__T_1907;
    ((T_1907)getName_25)->Code = f_1960;
    ((T_1907)getName_25)->base_19 = base_19;
    CLOS getState_26;
    NEW (CLOS, getState_26, WORDS(sizeof(struct T_1908)));
    ((T_1908)getState_26)->GCINFO = __GC__T_1908;
    ((T_1908)getState_26)->Code = f_1964;
    ((T_1908)getState_26)->base_19 = base_19;
    CLOS setState_27;
    NEW (CLOS, setState_27, WORDS(sizeof(struct T_1909)));
    ((T_1909)setState_27)->GCINFO = __GC__T_1909;
    ((T_1909)setState_27)->Code = f_1969;
    ((T_1909)setState_27)->base_19 = base_19;
    CLOS getAllComponents_28;
    NEW (CLOS, getAllComponents_28, WORDS(sizeof(struct T_1910)));
    ((T_1910)getAllComponents_28)->GCINFO = __GC__T_1910;
    ((T_1910)getAllComponents_28)->Code = f_1973;
    ((T_1910)getAllComponents_28)->base_19 = base_19;
    CLOS setText_29;
    NEW (CLOS, setText_29, WORDS(sizeof(struct T_1911)));
    ((T_1911)setText_29)->GCINFO = __GC__T_1911;
    ((T_1911)setText_29)->Code = f_1981;
    ((T_1911)setText_29)->base_19 = base_19;
    ((T_1911)setText_29)->id_18 = id_18;
    ((T_1911)setText_29)->self_12 = self_12;
    CLOS getText_34;
    NEW (CLOS, getText_34, WORDS(sizeof(struct T_1913)));
    ((T_1913)getText_34)->GCINFO = __GC__T_1913;
    ((T_1913)getText_34)->Code = f_1984;
    ((T_1913)getText_34)->self_12 = self_12;
    CLOS setTextColor_36;
    NEW (CLOS, setTextColor_36, WORDS(sizeof(struct T_1914)));
    ((T_1914)setTextColor_36)->GCINFO = __GC__T_1914;
    ((T_1914)setTextColor_36)->Code = f_1992;
    ((T_1914)setTextColor_36)->base_19 = base_19;
    ((T_1914)setTextColor_36)->id_18 = id_18;
    ((T_1914)setTextColor_36)->self_12 = self_12;
    CLOS getTextColor_41;
    NEW (CLOS, getTextColor_41, WORDS(sizeof(struct T_1916)));
    ((T_1916)getTextColor_41)->GCINFO = __GC__T_1916;
    ((T_1916)getTextColor_41)->Code = f_1995;
    ((T_1916)getTextColor_41)->self_12 = self_12;
    CLOS setPosition_43;
    NEW (CLOS, setPosition_43, WORDS(sizeof(struct T_1917)));
    ((T_1917)setPosition_43)->GCINFO = __GC__T_1917;
    ((T_1917)setPosition_43)->Code = f_2000;
    ((T_1917)setPosition_43)->base_19 = base_19;
    ((T_1917)setPosition_43)->id_18 = id_18;
    ((T_1917)setPosition_43)->self_12 = self_12;
    CLOS getPosition_48;
    NEW (CLOS, getPosition_48, WORDS(sizeof(struct T_1918)));
    ((T_1918)getPosition_48)->GCINFO = __GC__T_1918;
    ((T_1918)getPosition_48)->Code = f_2003;
    ((T_1918)getPosition_48)->self_12 = self_12;
    CLOS setSize_50;
    NEW (CLOS, setSize_50, WORDS(sizeof(struct T_1919)));
    ((T_1919)setSize_50)->GCINFO = __GC__T_1919;
    ((T_1919)setSize_50)->Code = f_2007;
    ((T_1919)setSize_50)->self_12 = self_12;
    CLOS getSize_53;
    NEW (CLOS, getSize_53, WORDS(sizeof(struct T_1920)));
    ((T_1920)getSize_53)->GCINFO = __GC__T_1920;
    ((T_1920)getSize_53)->Code = f_2010;
    ((T_1920)getSize_53)->self_12 = self_12;
    CLOS destroy_55;
    NEW (CLOS, destroy_55, WORDS(sizeof(struct T_1921)));
    ((T_1921)destroy_55)->GCINFO = __GC__T_1921;
    ((T_1921)destroy_55)->Code = f_2014;
    ((T_1921)destroy_55)->base_19 = base_19;
    ((T_1921)destroy_55)->self_12 = self_12;
    CLOS installMouseListener_57;
    NEW (CLOS, installMouseListener_57, WORDS(sizeof(struct T_1922)));
    ((T_1922)installMouseListener_57)->GCINFO = __GC__T_1922;
    ((T_1922)installMouseListener_57)->Code = f_2019;
    ((T_1922)installMouseListener_57)->self_12 = self_12;
    CLOS handleEvent_62;
    CLOS init_63;
    CLOS x_1845;
    CLOS x_1847;
    CLOS x_1850;
    CLOS x_1852;
    CLOS x_1855;
    CLOS x_1857;
    CLOS x_1860;
    CLOS x_1862;
    CLOS x_1864;
    CLOS x_1866;
    CLOS x_1868;
    CLOS x_1871;
    CLOS x_1874;
    CLOS x_1877;
    CLOS x_1881;
    CLOS x_1883;
    CLOS x_1886;
    CLOS x_1889;
    CLOS x_1891;
    CLOS x_1893;
    CLOS x_1897;
    T_1928 x_2040;
    T_1930 x_2050;
    T_1929 x_2060;
    T_1927 x_2092;
    T_1931 x_2099;
    T_1926 x_2109;
    T_1932 x_2115;
    Label_CTLabel this_64;
    x_1845 = getIsFocusable_23;
    x_1847 = setIsFocusable_22;
    NEW (T_1928, x_2040, WORDS(sizeof(struct T_1928)));
    x_2040->GCINFO = __GC__T_1928;
    x_2040->getIsFocusable_CTCommon = f_2034;
    x_2040->setIsFocusable_CTCommon = f_2039;
    x_2040->x_1845 = x_1845;
    x_2040->x_1847 = x_1847;
    x_1850 = getPosition_48;
    x_1852 = setPosition_43;
    NEW (T_1930, x_2050, WORDS(sizeof(struct T_1930)));
    x_2050->GCINFO = __GC__T_1930;
    x_2050->getPosition_CTCommon = f_2044;
    x_2050->setPosition_CTCommon = f_2049;
    x_2050->x_1850 = x_1850;
    x_2050->x_1852 = x_1852;
    x_1855 = getSize_53;
    x_1857 = setSize_50;
    NEW (T_1929, x_2060, WORDS(sizeof(struct T_1929)));
    x_2060->GCINFO = __GC__T_1929;
    x_2060->l_HasSize_CTCommon_HasPosition_CTCommon_CTCommon = (HasPosition_CTCommon)x_2050;
    x_2060->getSize_CTCommon = f_2054;
    x_2060->setSize_CTCommon = f_2059;
    x_2060->x_1855 = x_1855;
    x_2060->x_1857 = x_1857;
    x_1860 = getAllComponents_28;
    x_1862 = getName_25;
    x_1864 = getParent_21;
    x_1866 = getState_26;
    x_1868 = setName_24;
    x_1871 = setParent_20;
    x_1874 = setState_27;
    NEW (T_1927, x_2092, WORDS(sizeof(struct T_1927)));
    x_2092->GCINFO = __GC__T_1927;
    x_2092->l_AbstractComponent_CTCommon_IsFocusable_CTCommon_CTCommon = (IsFocusable_CTCommon)x_2040;
    x_2092->l_AbstractComponent_CTCommon_HasSize_CTCommon_CTCommon = (HasSize_CTCommon)x_2060;
    x_2092->getAllComponents_CTCommon = f_2064;
    x_2092->getName_CTCommon = f_2068;
    x_2092->getParent_CTCommon = f_2072;
    x_2092->getState_CTCommon = f_2076;
    x_2092->setName_CTCommon = f_2081;
    x_2092->setParent_CTCommon = f_2086;
    x_2092->setState_CTCommon = f_2091;
    x_2092->x_1860 = x_1860;
    x_2092->x_1862 = x_1862;
    x_2092->x_1864 = x_1864;
    x_2092->x_1866 = x_1866;
    x_2092->x_1868 = x_1868;
    x_2092->x_1871 = x_1871;
    x_2092->x_1874 = x_1874;
    x_1881 = destroy_55;
    x_1886 = installMouseListener_57;
    NEW (T_1932, x_2115, WORDS(sizeof(struct T_1932)));
    x_2115->GCINFO = __GC__T_1932;
    x_2115->installMouseListener_CTCommon = f_2114;
    x_2115->x_1886 = x_1886;
    x_1889 = getText_34;
    x_1891 = getTextColor_41;
    x_1893 = setText_29;
    x_1897 = setTextColor_36;
    {   Array roots = CYCLIC_BEGIN(7,0);
        handleEvent_62 = (CLOS)roots->elems[0];
        init_63 = (CLOS)roots->elems[1];
        x_1877 = (CLOS)roots->elems[2];
        x_1883 = (CLOS)roots->elems[3];
        x_2099 = (T_1931)roots->elems[4];
        x_2109 = (T_1926)roots->elems[5];
        this_64 = (Label_CTLabel)roots->elems[6];
        NEW (CLOS, handleEvent_62, WORDS(sizeof(struct T_1923)));
        roots->elems[0] = (POLY)handleEvent_62;
        ((T_1923)(CLOS)roots->elems[0])->GCINFO = __GC__T_1923;
        ((T_1923)(CLOS)roots->elems[0])->Code = f_2025;
        ((T_1923)(CLOS)roots->elems[0])->this_64 = this_64;
        ((T_1923)(CLOS)roots->elems[0])->self_12 = self_12;
        NEW (CLOS, init_63, WORDS(sizeof(struct T_1924)));
        roots->elems[1] = (POLY)init_63;
        ((T_1924)(CLOS)roots->elems[1])->GCINFO = __GC__T_1924;
        ((T_1924)(CLOS)roots->elems[1])->Code = f_2030;
        ((T_1924)(CLOS)roots->elems[1])->this_64 = this_64;
        ((T_1924)(CLOS)roots->elems[1])->base_19 = base_19;
        ((T_1924)(CLOS)roots->elems[1])->id_18 = id_18;
        ((T_1924)(CLOS)roots->elems[1])->self_12 = self_12;
        x_1877 = handleEvent_62;
        roots->elems[2] = (POLY)x_1877;
        x_1883 = init_63;
        roots->elems[3] = (POLY)x_1883;
        NEW (T_1931, x_2099, WORDS(sizeof(struct T_1931)));
        roots->elems[4] = (POLY)x_2099;
        ((T_1931)roots->elems[4])->GCINFO = __GC__T_1931;
        ((T_1931)roots->elems[4])->handleEvent_CTCommon = f_2098;
        ((T_1931)roots->elems[4])->x_1877 = x_1877;
        NEW (T_1926, x_2109, WORDS(sizeof(struct T_1926)));
        roots->elems[5] = (POLY)x_2109;
        ((T_1926)roots->elems[5])->GCINFO = __GC__T_1926;
        ((T_1926)roots->elems[5])->l_Component_CTCommon_AbstractComponent_CTCommon_CTCommon = (AbstractComponent_CTCommon)x_2092;
        ((T_1926)roots->elems[5])->l_Component_CTCommon_HandlesEvents_CTCommon_CTCommon = (HandlesEvents_CTCommon)x_2099;
        ((T_1926)roots->elems[5])->id_CTCommon = id_18;
        ((T_1926)roots->elems[5])->destroy_CTCommon = f_2103;
        ((T_1926)roots->elems[5])->init_CTCommon = f_2108;
        ((T_1926)roots->elems[5])->x_1881 = x_1881;
        ((T_1926)roots->elems[5])->x_1883 = x_1883;
        NEW (Label_CTLabel, this_64, WORDS(sizeof(struct T_1925)));
        roots->elems[6] = (POLY)this_64;
        ((T_1925)(Label_CTLabel)roots->elems[6])->GCINFO = __GC__T_1925;
        ((T_1925)(Label_CTLabel)roots->elems[6])->l_Label_CTLabel_Component_CTCommon_CTLabel = (Component_CTCommon)x_2109;
        ((T_1925)(Label_CTLabel)roots->elems[6])->l_Label_CTLabel_HandlesMouseEvents_CTCommon_CTLabel = (HandlesMouseEvents_CTCommon)x_2115;
        ((T_1925)(Label_CTLabel)roots->elems[6])->getText_CTLabel = f_2119;
        ((T_1925)(Label_CTLabel)roots->elems[6])->getTextColor_CTLabel = f_2123;
        ((T_1925)(Label_CTLabel)roots->elems[6])->setText_CTLabel = f_2129;
        ((T_1925)(Label_CTLabel)roots->elems[6])->setTextColor_CTLabel = f_2135;
        ((T_1925)(Label_CTLabel)roots->elems[6])->x_1889 = x_1889;
        ((T_1925)(Label_CTLabel)roots->elems[6])->x_1891 = x_1891;
        ((T_1925)(Label_CTLabel)roots->elems[6])->x_1893 = x_1893;
        ((T_1925)(Label_CTLabel)roots->elems[6])->x_1897 = x_1897;
        CYCLIC_END(roots, hp);
    }
    Position_CTCommon x_2136;
    NEW (Position_CTCommon, x_2136, WORDS(sizeof(struct Position_CTCommon)));
    x_2136->GCINFO = __GC__Position_CTCommon;
    x_2136->x_CTCommon = 0;
    x_2136->y_CTCommon = 0;
    ((S_479)STATEOF(self_12))->position_13 = x_2136;
    Size_CTCommon x_2137;
    NEW (Size_CTCommon, x_2137, WORDS(sizeof(struct Size_CTCommon)));
    x_2137->GCINFO = __GC__Size_CTCommon;
    x_2137->width_CTCommon = 0;
    x_2137->height_CTCommon = 0;
    ((S_479)STATEOF(self_12))->size_14 = x_2137;
    ((S_479)STATEOF(self_12))->mouseEventHandler_15 = (Maybe_Prelude)1;
    Color_CTCommon x_2138;
    NEW (Color_CTCommon, x_2138, WORDS(sizeof(struct Color_CTCommon)));
    x_2138->GCINFO = __GC__Color_CTCommon;
    x_2138->r_CTCommon = 0;
    x_2138->g_CTCommon = 0;
    x_2138->b_CTCommon = 0;
    ((S_479)STATEOF(self_12))->textColor_16 = x_2138;
    ((S_479)STATEOF(self_12))->text_17 = getStr("Default Label");
    return this_64;
}
static TUP0 inithelper_60 (CocoaID_CTCommon id_18, Ref self_61) {
    Msg d_84;
    d_84 = labelSetText_CTLabel(id_18,
                                ((S_479)STATEOF(self_61))->text_17,
                                Inherit,
                                Inherit);
    Msg d_85;
    d_85 = labelSetPosition_CTLabel(id_18,
                                    ((S_479)STATEOF(self_61))->position_13,
                                    Inherit,
                                    Inherit);
    Msg d_86;
    d_86 = labelSetSize_CTLabel(id_18,
                                ((S_479)STATEOF(self_61))->size_14,
                                Inherit,
                                Inherit);
    Msg d_87;
    d_87 = labelSetTextColor_CTLabel(id_18,
                                     ((S_479)STATEOF(self_61))->textColor_16,
                                     Inherit,
                                     Inherit);
    return (TUP0)0;
}
static TUP0 f_1938 (T_1902 this_1934,
                    Maybe_Prelude a_1758,
                    Int a_1759) {
    AbstractComponent_CTCommon x_1937;
    x_1937 = this_1934->base_19;
    return x_1937->setParent_CTCommon(x_1937, a_1758, a_1759);
}
static Maybe_Prelude f_1942 (T_1903 this_1939, Int a_1761) {
    AbstractComponent_CTCommon x_1941;
    x_1941 = this_1939->base_19;
    return x_1941->getParent_CTCommon(x_1941, a_1761);
}
static TUP0 f_1947 (T_1904 this_1943, Bool a_1764, Int a_1765) {
    IsFocusable_CTCommon x_1946;
    x_1946 = this_1943->base_19->l_AbstractComponent_CTCommon_IsFocusable_CTCommon_CTCommon;
    return x_1946->setIsFocusable_CTCommon(x_1946, a_1764, a_1765);
}
static Bool f_1951 (T_1905 this_1948, Int a_1767) {
    IsFocusable_CTCommon x_1950;
    x_1950 = this_1948->base_19->l_AbstractComponent_CTCommon_IsFocusable_CTCommon_CTCommon;
    return x_1950->getIsFocusable_CTCommon(x_1950, a_1767);
}
static TUP0 f_1956 (T_1906 this_1952, LIST a_1770, Int a_1771) {
    AbstractComponent_CTCommon x_1955;
    x_1955 = this_1952->base_19;
    return x_1955->setName_CTCommon(x_1955, a_1770, a_1771);
}
static LIST f_1960 (T_1907 this_1957, Int a_1773) {
    AbstractComponent_CTCommon x_1959;
    x_1959 = this_1957->base_19;
    return x_1959->getName_CTCommon(x_1959, a_1773);
}
static CocoaState_CTCommon f_1964 (T_1908 this_1961, Int a_1775) {
    AbstractComponent_CTCommon x_1963;
    x_1963 = this_1961->base_19;
    return x_1963->getState_CTCommon(x_1963, a_1775);
}
static TUP0 f_1969 (T_1909 this_1965,
                    CocoaState_CTCommon a_1778,
                    Int a_1779) {
    AbstractComponent_CTCommon x_1968;
    x_1968 = this_1965->base_19;
    return x_1968->setState_CTCommon(x_1968, a_1778, a_1779);
}
static LIST f_1973 (T_1910 this_1970, Int a_1781) {
    AbstractComponent_CTCommon x_1972;
    x_1972 = this_1970->base_19;
    return x_1972->getAllComponents_CTCommon(x_1972, a_1781);
}
static TUP0 f_1980 (T_1912 this_1978) {
    Ref self_31;
    self_31 = (Ref)LOCK((OID)this_1978->self_12);
    ((S_479)STATEOF(self_31))->text_17 = this_1978->a_1787;
    AbstractComponent_CTCommon x_1979;
    x_1979 = this_1978->base_19;
    CocoaState_CTCommon x_72;
    x_72 = x_1979->getState_CTCommon(x_1979, 0);
    switch ((WORD)x_72) {
        case 2: { Ref self_32;
                  self_32 = self_31;
                  Msg d_73;
                  d_73 = labelSetText_CTLabel(this_1978->id_18,
                                              this_1978->a_1787,
                                              Inherit,
                                              Inherit);
                  UNLOCK((OID)self_31);
                  return (TUP0)0;
                }
                break;
        case 0: { Ref self_33;
                  self_33 = self_31;
                  UNLOCK((OID)self_31);
                  return (TUP0)0;
                }
                break;
        case 1: { Ref self_33;
                  self_33 = self_31;
                  UNLOCK((OID)self_31);
                  return (TUP0)0;
                }
                break;
    }
}
static Msg f_1981 (T_1911 this_1974,
                   LIST a_1787,
                   Time a_1788,
                   Time a_1789) {
    Msg x_1786;
    NEW (Msg, x_1786, WORDS(sizeof(struct T_1912)));
    ((T_1912)x_1786)->GCINFO = __GC__T_1912;
    ((T_1912)x_1786)->Code = f_1980;
    ((T_1912)x_1786)->a_1787 = a_1787;
    ((T_1912)x_1786)->base_19 = this_1974->base_19;
    ((T_1912)x_1786)->id_18 = this_1974->id_18;
    ((T_1912)x_1786)->self_12 = this_1974->self_12;
    return (Msg)ASYNC(x_1786, a_1788, a_1789);
}
static LIST f_1984 (T_1913 this_1982, Int a_1793) {
    Ref self_35;
    self_35 = (Ref)LOCK((OID)this_1982->self_12);
    LIST x_1790;
    x_1790 = ((S_479)STATEOF(self_35))->text_17;
    UNLOCK((OID)self_35);
    return x_1790;
}
static TUP0 f_1991 (T_1915 this_1989) {
    Ref self_38;
    self_38 = (Ref)LOCK((OID)this_1989->self_12);
    AbstractComponent_CTCommon x_1990;
    x_1990 = this_1989->base_19;
    CocoaState_CTCommon x_76;
    x_76 = x_1990->getState_CTCommon(x_1990, 0);
    switch ((WORD)x_76) {
        case 2: { Msg d_77;
                  d_77 = labelSetTextColor_CTLabel(this_1989->id_18,
                                                   this_1989->a_1799,
                                                   Inherit,
                                                   Inherit);
                  break;
                }
                break;
        case 0: break;
        case 1: break;
    }
    ((S_479)STATEOF(self_38))->textColor_16 = this_1989->a_1799;
    UNLOCK((OID)self_38);
    return (TUP0)0;
}
static Msg f_1992 (T_1914 this_1985,
                   Color_CTCommon a_1799,
                   Time a_1800,
                   Time a_1801) {
    Msg x_1798;
    NEW (Msg, x_1798, WORDS(sizeof(struct T_1915)));
    ((T_1915)x_1798)->GCINFO = __GC__T_1915;
    ((T_1915)x_1798)->Code = f_1991;
    ((T_1915)x_1798)->a_1799 = a_1799;
    ((T_1915)x_1798)->base_19 = this_1985->base_19;
    ((T_1915)x_1798)->id_18 = this_1985->id_18;
    ((T_1915)x_1798)->self_12 = this_1985->self_12;
    return (Msg)ASYNC(x_1798, a_1800, a_1801);
}
static Color_CTCommon f_1995 (T_1916 this_1993, Int a_1805) {
    Ref self_42;
    self_42 = (Ref)LOCK((OID)this_1993->self_12);
    Color_CTCommon x_1802;
    x_1802 = ((S_479)STATEOF(self_42))->textColor_16;
    UNLOCK((OID)self_42);
    return x_1802;
}
static TUP0 f_2000 (T_1917 this_1996,
                    Position_CTCommon a_1808,
                    Int a_1809) {
    Ref self_45;
    self_45 = (Ref)LOCK((OID)this_1996->self_12);
    AbstractComponent_CTCommon x_1999;
    x_1999 = this_1996->base_19;
    CocoaState_CTCommon x_80;
    x_80 = x_1999->getState_CTCommon(x_1999, 0);
    switch ((WORD)x_80) {
        case 2: { Msg d_81;
                  d_81 = labelSetPosition_CTLabel(this_1996->id_18,
                                                  a_1808,
                                                  Inherit,
                                                  Inherit);
                  break;
                }
                break;
        case 0: break;
        case 1: break;
    }
    ((S_479)STATEOF(self_45))->position_13 = a_1808;
    UNLOCK((OID)self_45);
    return (TUP0)0;
}
static Position_CTCommon f_2003 (T_1918 this_2001, Int a_1813) {
    Ref self_49;
    self_49 = (Ref)LOCK((OID)this_2001->self_12);
    Position_CTCommon x_1810;
    x_1810 = ((S_479)STATEOF(self_49))->position_13;
    UNLOCK((OID)self_49);
    return x_1810;
}
static TUP0 f_2007 (T_1919 this_2004,
                    Size_CTCommon a_1816,
                    Int a_1817) {
    Ref self_52;
    self_52 = (Ref)LOCK((OID)this_2004->self_12);
    ((S_479)STATEOF(self_52))->size_14 = a_1816;
    UNLOCK((OID)self_52);
    return (TUP0)0;
}
static Size_CTCommon f_2010 (T_1920 this_2008, Int a_1821) {
    Ref self_54;
    self_54 = (Ref)LOCK((OID)this_2008->self_12);
    Size_CTCommon x_1818;
    x_1818 = ((S_479)STATEOF(self_54))->size_14;
    UNLOCK((OID)self_54);
    return x_1818;
}
static TUP0 f_2014 (T_1921 this_2011, Int a_1824) {
    Ref self_56;
    self_56 = (Ref)LOCK((OID)this_2011->self_12);
    AbstractComponent_CTCommon x_2013;
    x_2013 = this_2011->base_19;
    TUP0 d_83;
    d_83 = x_2013->setState_CTCommon(x_2013,
                                     (CocoaState_CTCommon)0,
                                     0);
    UNLOCK((OID)self_56);
    return (TUP0)0;
}
static TUP0 f_2019 (T_1922 this_2015, CLOS a_1829, Int a_1830) {
    Ref self_59;
    self_59 = (Ref)LOCK((OID)this_2015->self_12);
    _Just_Prelude x_2018;
    NEW (_Just_Prelude, x_2018, WORDS(sizeof(struct _Just_Prelude)));
    x_2018->GCINFO = __GC___Just_Prelude+((4 * (BITS32)0));
    x_2018->a = (POLY)a_1829;
    ((S_479)STATEOF(self_59))->mouseEventHandler_15 = (Maybe_Prelude)x_2018;
    UNLOCK((OID)self_59);
    return (TUP0)0;
}
static Maybe_Prelude f_2025 (T_1923 this_2020,
                             CocoaEvent_CTCommon a_1838,
                             LIST a_1839,
                             Int a_1840) {
    switch (a_1838->Tag) {
        case 1: { MouseEventType_CTCommon x_92;
                  x_92 = ((_MouseEvent_CTCommon)a_1838)->a;
                  Ref self_67;
                  self_67 = (Ref)LOCK((OID)this_2020->self_12);
                  Bool x_90;
                  x_90 = dynamicHandleEvent_CTCommon((BITS32)0,
                                                     (POLY)x_92,
                                                     ((S_479)STATEOF(self_67))->mouseEventHandler_15,
                                                     self_67);
                  _Just_Prelude x_2024;
                  NEW (_Just_Prelude, x_2024, WORDS(sizeof(struct _Just_Prelude)));
                  x_2024->GCINFO = __GC___Just_Prelude+((4 * (BITS32)0));
                  x_2024->a = (POLY)this_2020->this_64->l_Label_CTLabel_Component_CTCommon_CTLabel;
                  Maybe_Prelude x_1833;
                  x_1833 = boolToMaybe_CTCommon((BITS32)0,
                                                (Maybe_Prelude)x_2024,
                                                x_90);
                  UNLOCK((OID)self_67);
                  return x_1833;
                }
                break;
        default: { Ref self_69;
                   self_69 = (Ref)LOCK((OID)this_2020->self_12);
                   UNLOCK((OID)self_69);
                   return (Maybe_Prelude)1;
                 }
                 break;
    }
}
static TUP0 f_2030 (T_1924 this_2026,
                    App_CTCommon a_1843,
                    Int a_1844) {
    Ref self_71;
    self_71 = (Ref)LOCK((OID)this_2026->self_12);
    AbstractComponent_CTCommon x_2029;
    x_2029 = this_2026->base_19;
    TUP0 d_93;
    d_93 = x_2029->setState_CTCommon(x_2029,
                                     (CocoaState_CTCommon)2,
                                     0);
    TUP0 d_94;
    d_94 = initLabel_CTLabel(this_2026->this_64, a_1843, 0);
    TUP0 d_95;
    d_95 = inithelper_60(this_2026->id_18, self_71);
    UNLOCK((OID)self_71);
    return (TUP0)0;
}
static Bool f_2034 (T_1928 this_2031, Int a_1846) {
    CLOS x_2033;
    x_2033 = this_2031->x_1845;
    return ((Bool(*)(CLOS, Int))(x_2033->Code))(x_2033, a_1846);
}
static TUP0 f_2039 (T_1928 this_2035, Bool a_1848, Int a_1849) {
    CLOS x_2038;
    x_2038 = this_2035->x_1847;
    return ((TUP0(*)(CLOS, Bool, Int))(x_2038->Code))(x_2038,
                                                      a_1848,
                                                      a_1849);
}
static Position_CTCommon f_2044 (T_1930 this_2041, Int a_1851) {
    CLOS x_2043;
    x_2043 = this_2041->x_1850;
    return ((Position_CTCommon(*)(CLOS, Int))(x_2043->Code))(x_2043,
                                                             a_1851);
}
static TUP0 f_2049 (T_1930 this_2045,
                    Position_CTCommon a_1853,
                    Int a_1854) {
    CLOS x_2048;
    x_2048 = this_2045->x_1852;
    return ((TUP0(*)(CLOS, Position_CTCommon, Int))(x_2048->Code))(x_2048,
                                                                   a_1853,
                                                                   a_1854);
}
static Size_CTCommon f_2054 (T_1929 this_2051, Int a_1856) {
    CLOS x_2053;
    x_2053 = this_2051->x_1855;
    return ((Size_CTCommon(*)(CLOS, Int))(x_2053->Code))(x_2053,
                                                         a_1856);
}
static TUP0 f_2059 (T_1929 this_2055,
                    Size_CTCommon a_1858,
                    Int a_1859) {
    CLOS x_2058;
    x_2058 = this_2055->x_1857;
    return ((TUP0(*)(CLOS, Size_CTCommon, Int))(x_2058->Code))(x_2058,
                                                               a_1858,
                                                               a_1859);
}
static LIST f_2064 (T_1927 this_2061, Int a_1861) {
    CLOS x_2063;
    x_2063 = this_2061->x_1860;
    return ((LIST(*)(CLOS, Int))(x_2063->Code))(x_2063, a_1861);
}
static LIST f_2068 (T_1927 this_2065, Int a_1863) {
    CLOS x_2067;
    x_2067 = this_2065->x_1862;
    return ((LIST(*)(CLOS, Int))(x_2067->Code))(x_2067, a_1863);
}
static Maybe_Prelude f_2072 (T_1927 this_2069, Int a_1865) {
    CLOS x_2071;
    x_2071 = this_2069->x_1864;
    return ((Maybe_Prelude(*)(CLOS, Int))(x_2071->Code))(x_2071,
                                                         a_1865);
}
static CocoaState_CTCommon f_2076 (T_1927 this_2073, Int a_1867) {
    CLOS x_2075;
    x_2075 = this_2073->x_1866;
    return ((CocoaState_CTCommon(*)(CLOS, Int))(x_2075->Code))(x_2075,
                                                               a_1867);
}
static TUP0 f_2081 (T_1927 this_2077, LIST a_1869, Int a_1870) {
    CLOS x_2080;
    x_2080 = this_2077->x_1868;
    return ((TUP0(*)(CLOS, LIST, Int))(x_2080->Code))(x_2080,
                                                      a_1869,
                                                      a_1870);
}
static TUP0 f_2086 (T_1927 this_2082,
                    Maybe_Prelude a_1872,
                    Int a_1873) {
    CLOS x_2085;
    x_2085 = this_2082->x_1871;
    return ((TUP0(*)(CLOS, Maybe_Prelude, Int))(x_2085->Code))(x_2085,
                                                               a_1872,
                                                               a_1873);
}
static TUP0 f_2091 (T_1927 this_2087,
                    CocoaState_CTCommon a_1875,
                    Int a_1876) {
    CLOS x_2090;
    x_2090 = this_2087->x_1874;
    return ((TUP0(*)(CLOS, CocoaState_CTCommon, Int))(x_2090->Code))(x_2090,
                                                                     a_1875,
                                                                     a_1876);
}
static Maybe_Prelude f_2098 (T_1931 this_2093,
                             CocoaEvent_CTCommon a_1878,
                             LIST a_1879,
                             Int a_1880) {
    CLOS x_2097;
    x_2097 = this_2093->x_1877;
    return ((Maybe_Prelude(*)(CLOS, CocoaEvent_CTCommon, LIST, Int))(x_2097->Code))(x_2097,
                                                                                    a_1878,
                                                                                    a_1879,
                                                                                    a_1880);
}
static TUP0 f_2103 (T_1926 this_2100, Int a_1882) {
    CLOS x_2102;
    x_2102 = this_2100->x_1881;
    return ((TUP0(*)(CLOS, Int))(x_2102->Code))(x_2102, a_1882);
}
static TUP0 f_2108 (T_1926 this_2104,
                    App_CTCommon a_1884,
                    Int a_1885) {
    CLOS x_2107;
    x_2107 = this_2104->x_1883;
    return ((TUP0(*)(CLOS, App_CTCommon, Int))(x_2107->Code))(x_2107,
                                                              a_1884,
                                                              a_1885);
}
static TUP0 f_2114 (T_1932 this_2110, CLOS a_1887, Int a_1888) {
    CLOS x_2113;
    x_2113 = this_2110->x_1886;
    return ((TUP0(*)(CLOS, CLOS, Int))(x_2113->Code))(x_2113,
                                                      a_1887,
                                                      a_1888);
}
static LIST f_2119 (T_1925 this_2116, Int a_1890) {
    CLOS x_2118;
    x_2118 = this_2116->x_1889;
    return ((LIST(*)(CLOS, Int))(x_2118->Code))(x_2118, a_1890);
}
static Color_CTCommon f_2123 (T_1925 this_2120, Int a_1892) {
    CLOS x_2122;
    x_2122 = this_2120->x_1891;
    return ((Color_CTCommon(*)(CLOS, Int))(x_2122->Code))(x_2122,
                                                          a_1892);
}
static Msg f_2129 (T_1925 this_2124,
                   LIST a_1894,
                   Time a_1895,
                   Time a_1896) {
    CLOS x_2128;
    x_2128 = this_2124->x_1893;
    return ((Msg(*)(CLOS, LIST, Time, Time))(x_2128->Code))(x_2128,
                                                            a_1894,
                                                            a_1895,
                                                            a_1896);
}
static Msg f_2135 (T_1925 this_2130,
                   Color_CTCommon a_1898,
                   Time a_1899,
                   Time a_1900) {
    CLOS x_2134;
    x_2134 = this_2130->x_1897;
    return ((Msg(*)(CLOS, Color_CTCommon, Time, Time))(x_2134->Code))(x_2134,
                                                                      a_1898,
                                                                      a_1899,
                                                                      a_1900);
}
 
void _init_CTLabel () {
    static int INITIALIZED = 0;
    if (!INITIALIZED) {
        _init_Prelude();
        _init_CTCommon();
        INITIALIZED = 1;
    }
}
 

