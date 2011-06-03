#include "CTButton.h"
#include "CTButton.extern.c"
 
struct S_467;
typedef struct S_467 *S_467;
struct T_2243;
typedef struct T_2243 *T_2243;
struct T_2242;
typedef struct T_2242 *T_2242;
struct T_2241;
typedef struct T_2241 *T_2241;
struct T_2240;
typedef struct T_2240 *T_2240;
struct T_2239;
typedef struct T_2239 *T_2239;
struct T_2238;
typedef struct T_2238 *T_2238;
struct T_2237;
typedef struct T_2237 *T_2237;
struct T_2236;
typedef struct T_2236 *T_2236;
struct T_2235;
typedef struct T_2235 *T_2235;
struct T_2234;
typedef struct T_2234 *T_2234;
struct T_2233;
typedef struct T_2233 *T_2233;
struct T_2232;
typedef struct T_2232 *T_2232;
struct T_2231;
typedef struct T_2231 *T_2231;
struct T_2230;
typedef struct T_2230 *T_2230;
struct T_2229;
typedef struct T_2229 *T_2229;
struct T_2228;
typedef struct T_2228 *T_2228;
struct T_2227;
typedef struct T_2227 *T_2227;
struct T_2226;
typedef struct T_2226 *T_2226;
struct T_2225;
typedef struct T_2225 *T_2225;
struct T_2224;
typedef struct T_2224 *T_2224;
struct T_2223;
typedef struct T_2223 *T_2223;
struct T_2222;
typedef struct T_2222 *T_2222;
struct T_2221;
typedef struct T_2221 *T_2221;
struct T_2220;
typedef struct T_2220 *T_2220;
struct T_2219;
typedef struct T_2219 *T_2219;
struct T_2218;
typedef struct T_2218 *T_2218;
struct T_2217;
typedef struct T_2217 *T_2217;
struct T_2216;
typedef struct T_2216 *T_2216;
struct T_2215;
typedef struct T_2215 *T_2215;
 
struct S_467 {
    POLY GCINFO;
    CocoaState_CTCommon myState_10;
    Position_CTCommon position_11;
    Size_CTCommon size_12;
    Maybe_Prelude mouseEventHandler_13;
    Maybe_Prelude keyEventHandler_14;
    LIST title_15;
    LIST name_16;
};
struct T_2243 {
    POLY GCINFO;
    TUP0 (*installKeyListener_CTCommon) (T_2243, CLOS, Int);
    CLOS x_2205;
};
struct T_2242 {
    POLY GCINFO;
    TUP0 (*installMouseListener_CTCommon) (T_2242, CLOS, Int);
    CLOS x_2202;
};
struct T_2241 {
    POLY GCINFO;
    Maybe_Prelude (*handleEvent_CTCommon) (T_2241,
                                           CocoaEvent_CTCommon,
                                           LIST,
                                           Int);
    CLOS x_2188;
};
struct T_2240 {
    POLY GCINFO;
    Msg (*setPosition_CTCommon) (T_2240,
                                 Position_CTCommon,
                                 Time,
                                 Time);
    Position_CTCommon (*getPosition_CTCommon) (T_2240, Int);
    CLOS x_2176;
    CLOS x_2178;
};
struct T_2239 {
    POLY GCINFO;
    HasPosition_CTCommon l_HasSize_CTCommon_HasPosition_CTCommon_CTCommon;
    Msg (*setSize_CTCommon) (T_2239, Size_CTCommon, Time, Time);
    Size_CTCommon (*getSize_CTCommon) (T_2239, Int);
    CLOS x_2182;
    CLOS x_2184;
};
struct T_2238 {
    POLY GCINFO;
    TUP0 (*setNextFocusTarget_CTCommon) (T_2238, Maybe_Prelude, Int);
    Maybe_Prelude (*getNextFocusTarget_CTCommon) (T_2238, Int);
    TUP0 (*setPreviousFocusTarget_CTCommon) (T_2238,
                                             Maybe_Prelude,
                                             Int);
    Maybe_Prelude (*getPreviousFocusTarget_CTCommon) (T_2238, Int);
    TUP0 (*setIsFocusable_CTCommon) (T_2238, Bool, Int);
    Bool (*getIsFocusable_CTCommon) (T_2238, Int);
    CLOS x_2161;
    CLOS x_2163;
    CLOS x_2165;
    CLOS x_2167;
    CLOS x_2170;
    CLOS x_2173;
};
struct T_2237 {
    POLY GCINFO;
    IsFocusable_CTCommon l_Component_CTCommon_IsFocusable_CTCommon_CTCommon;
    HasSize_CTCommon l_Component_CTCommon_HasSize_CTCommon_CTCommon;
    HandlesEvents_CTCommon l_Component_CTCommon_HandlesEvents_CTCommon_CTCommon;
    CocoaID_CTCommon id_CTCommon;
    TUP0 (*init_CTCommon) (T_2237, App_CTCommon, Int);
    TUP0 (*destroy_CTCommon) (T_2237, Int);
    TUP0 (*setName_CTCommon) (T_2237, LIST, Int);
    LIST (*getName_CTCommon) (T_2237, Int);
    CLOS x_2192;
    CLOS x_2194;
    CLOS x_2196;
    CLOS x_2199;
};
struct T_2236 {
    POLY GCINFO;
    Component_CTCommon l_Button_CTButton_Component_CTCommon_CTButton;
    HandlesMouseEvents_CTCommon l_Button_CTButton_HandlesMouseEvents_CTCommon_CTButton;
    HandlesKeyEvents_CTCommon l_Button_CTButton_HandlesKeyEvents_CTCommon_CTButton;
    Msg (*setTitle_CTButton) (T_2236, LIST, Time, Time);
    LIST (*getTitle_CTButton) (T_2236, Int);
    CLOS x_2208;
    CLOS x_2210;
};
struct T_2235 {
    POLY GCINFO;
    TUP0 (*Code) (T_2235, App_CTCommon, Int);
    Button_CTButton this_61;
    CocoaID_CTCommon id_17;
    Ref self_9;
};
struct T_2234 {
    POLY GCINFO;
    Maybe_Prelude (*Code) (T_2234, CocoaEvent_CTCommon, LIST, Int);
    Button_CTButton this_61;
    Ref self_9;
};
struct T_2233 {
    POLY GCINFO;
    Bool (*Code) (T_2233, Int);
    IsFocusable_CTCommon focus_52;
};
struct T_2232 {
    POLY GCINFO;
    TUP0 (*Code) (T_2232, Bool, Int);
    IsFocusable_CTCommon focus_52;
};
struct T_2231 {
    POLY GCINFO;
    Maybe_Prelude (*Code) (T_2231, Int);
    IsFocusable_CTCommon focus_52;
};
struct T_2230 {
    POLY GCINFO;
    TUP0 (*Code) (T_2230, Maybe_Prelude, Int);
    IsFocusable_CTCommon focus_52;
};
struct T_2229 {
    POLY GCINFO;
    Maybe_Prelude (*Code) (T_2229, Int);
    IsFocusable_CTCommon focus_52;
    Ref self_9;
    Env_POSIX env_8;
};
struct T_2228 {
    POLY GCINFO;
    TUP0 (*Code) (T_2228, Maybe_Prelude, Int);
    IsFocusable_CTCommon focus_52;
    Ref self_9;
    Env_POSIX env_8;
};
struct T_2227 {
    POLY GCINFO;
    TUP0 (*Code) (T_2227, LIST, Int);
    Ref self_9;
};
struct T_2226 {
    POLY GCINFO;
    TUP0 (*Code) (T_2226, CLOS, Int);
    Ref self_9;
};
struct T_2225 {
    POLY GCINFO;
    TUP0 (*Code) (T_2225, CLOS, Int);
    Ref self_9;
};
struct T_2224 {
    POLY GCINFO;
    TUP0 (*Code) (T_2224, Int);
    Ref self_9;
};
struct T_2223 {
    POLY GCINFO;
    Size_CTCommon (*Code) (T_2223, Int);
    Ref self_9;
};
struct T_2222 {
    POLY GCINFO;
    TUP0 (*Code) (T_2222);
    AbsTime baseline;
    AbsTime deadline;
    Msg next;
    Size_CTCommon a_2093;
    Ref self_9;
};
struct T_2221 {
    POLY GCINFO;
    Msg (*Code) (T_2221, Size_CTCommon, Time, Time);
    Ref self_9;
};
struct T_2220 {
    POLY GCINFO;
    Position_CTCommon (*Code) (T_2220, Int);
    Ref self_9;
};
struct T_2219 {
    POLY GCINFO;
    TUP0 (*Code) (T_2219);
    AbsTime baseline;
    AbsTime deadline;
    Msg next;
    Position_CTCommon a_2081;
    CocoaID_CTCommon id_17;
    Ref self_9;
};
struct T_2218 {
    POLY GCINFO;
    Msg (*Code) (T_2218, Position_CTCommon, Time, Time);
    CocoaID_CTCommon id_17;
    Ref self_9;
};
struct T_2217 {
    POLY GCINFO;
    LIST (*Code) (T_2217, Int);
    Ref self_9;
};
struct T_2216 {
    POLY GCINFO;
    TUP0 (*Code) (T_2216);
    AbsTime baseline;
    AbsTime deadline;
    Msg next;
    LIST a_2069;
    CocoaID_CTCommon id_17;
    Ref self_9;
};
struct T_2215 {
    POLY GCINFO;
    Msg (*Code) (T_2215, LIST, Time, Time);
    CocoaID_CTCommon id_17;
    Ref self_9;
};
 
static WORD __GC__S_467[];
static WORD __GC__T_2243[];
static WORD __GC__T_2242[];
static WORD __GC__T_2241[];
static WORD __GC__T_2240[];
static WORD __GC__T_2239[];
static WORD __GC__T_2238[];
static WORD __GC__T_2237[];
static WORD __GC__T_2236[];
static WORD __GC__T_2235[];
static WORD __GC__T_2234[];
static WORD __GC__T_2233[];
static WORD __GC__T_2232[];
static WORD __GC__T_2231[];
static WORD __GC__T_2230[];
static WORD __GC__T_2229[];
static WORD __GC__T_2228[];
static WORD __GC__T_2227[];
static WORD __GC__T_2226[];
static WORD __GC__T_2225[];
static WORD __GC__T_2224[];
static WORD __GC__T_2223[];
static WORD __GC__T_2222[];
static WORD __GC__T_2221[];
static WORD __GC__T_2220[];
static WORD __GC__T_2219[];
static WORD __GC__T_2218[];
static WORD __GC__T_2217[];
static WORD __GC__T_2216[];
static WORD __GC__T_2215[];
static TUP0 inithelper_41 (CocoaID_CTCommon id_17, Ref self_42);
static TUP0 f_2251 (T_2216 this_2249);
static Msg f_2252 (T_2215 this_2245,
                   LIST a_2069,
                   Time a_2070,
                   Time a_2071);
static LIST f_2255 (T_2217 this_2253, Int a_2075);
static TUP0 f_2262 (T_2219 this_2260);
static Msg f_2263 (T_2218 this_2256,
                   Position_CTCommon a_2081,
                   Time a_2082,
                   Time a_2083);
static Position_CTCommon f_2266 (T_2220 this_2264, Int a_2087);
static TUP0 f_2272 (T_2222 this_2271);
static Msg f_2273 (T_2221 this_2267,
                   Size_CTCommon a_2093,
                   Time a_2094,
                   Time a_2095);
static Size_CTCommon f_2276 (T_2223 this_2274, Int a_2099);
static TUP0 f_2279 (T_2224 this_2277, Int a_2102);
static LIST f_2282 (T_2217 this_2280, Int a_2106);
static TUP0 f_2287 (T_2225 this_2283, CLOS a_2111, Int a_2112);
static TUP0 f_2292 (T_2226 this_2288, CLOS a_2119, Int a_2120);
static TUP0 f_2296 (T_2227 this_2293, LIST a_2125, Int a_2126);
static TUP0 f_2303 (T_2228 this_2297,
                    Maybe_Prelude a_2129,
                    Int a_2130);
static Maybe_Prelude f_2309 (T_2229 this_2304, Int a_2133);
static TUP0 f_2314 (T_2230 this_2310,
                    Maybe_Prelude a_2136,
                    Int a_2137);
static Maybe_Prelude f_2318 (T_2231 this_2315, Int a_2139);
static TUP0 f_2323 (T_2232 this_2319, Bool a_2142, Int a_2143);
static Bool f_2327 (T_2233 this_2324, Int a_2145);
static Maybe_Prelude f_2334 (T_2234 this_2328,
                             CocoaEvent_CTCommon a_2154,
                             LIST a_2155,
                             Int a_2156);
static TUP0 f_2338 (T_2235 this_2335,
                    App_CTCommon a_2159,
                    Int a_2160);
static Bool f_2342 (T_2238 this_2339, Int a_2162);
static Maybe_Prelude f_2346 (T_2238 this_2343, Int a_2164);
static Maybe_Prelude f_2350 (T_2238 this_2347, Int a_2166);
static TUP0 f_2355 (T_2238 this_2351, Bool a_2168, Int a_2169);
static TUP0 f_2360 (T_2238 this_2356,
                    Maybe_Prelude a_2171,
                    Int a_2172);
static TUP0 f_2365 (T_2238 this_2361,
                    Maybe_Prelude a_2174,
                    Int a_2175);
static Position_CTCommon f_2370 (T_2240 this_2367, Int a_2177);
static Msg f_2376 (T_2240 this_2371,
                   Position_CTCommon a_2179,
                   Time a_2180,
                   Time a_2181);
static Size_CTCommon f_2381 (T_2239 this_2378, Int a_2183);
static Msg f_2387 (T_2239 this_2382,
                   Size_CTCommon a_2185,
                   Time a_2186,
                   Time a_2187);
static Maybe_Prelude f_2394 (T_2241 this_2389,
                             CocoaEvent_CTCommon a_2189,
                             LIST a_2190,
                             Int a_2191);
static TUP0 f_2399 (T_2237 this_2396, Int a_2193);
static LIST f_2403 (T_2237 this_2400, Int a_2195);
static TUP0 f_2408 (T_2237 this_2404,
                    App_CTCommon a_2197,
                    Int a_2198);
static TUP0 f_2413 (T_2237 this_2409, LIST a_2200, Int a_2201);
static TUP0 f_2419 (T_2242 this_2415, CLOS a_2203, Int a_2204);
static TUP0 f_2425 (T_2243 this_2421, CLOS a_2206, Int a_2207);
static LIST f_2430 (T_2236 this_2427, Int a_2209);
static Msg f_2436 (T_2236 this_2431,
                   LIST a_2211,
                   Time a_2212,
                   Time a_2213);
 
WORD __GC__Button_CTButton[] = {WORDS(sizeof(struct Button_CTButton)),
                                0,
                                WORDS(offsetof(struct Button_CTButton, l_Button_CTButton_Component_CTCommon_CTButton)),
                                WORDS(offsetof(struct Button_CTButton, l_Button_CTButton_HandlesMouseEvents_CTCommon_CTButton)),
                                WORDS(offsetof(struct Button_CTButton, l_Button_CTButton_HandlesKeyEvents_CTCommon_CTButton)),
                                0};
static WORD __GC__S_467[] = {WORDS(sizeof(struct S_467)),
                             0,
                             WORDS(offsetof(struct S_467, myState_10)),
                             WORDS(offsetof(struct S_467, position_11)),
                             WORDS(offsetof(struct S_467, size_12)),
                             WORDS(offsetof(struct S_467, mouseEventHandler_13)),
                             WORDS(offsetof(struct S_467, keyEventHandler_14)),
                             WORDS(offsetof(struct S_467, title_15)),
                             WORDS(offsetof(struct S_467, name_16)),
                             0};
static WORD __GC__T_2243[] = {WORDS(sizeof(struct T_2243)),
                              0,
                              WORDS(offsetof(struct T_2243, x_2205)),
                              0};
static WORD __GC__T_2242[] = {WORDS(sizeof(struct T_2242)),
                              0,
                              WORDS(offsetof(struct T_2242, x_2202)),
                              0};
static WORD __GC__T_2241[] = {WORDS(sizeof(struct T_2241)),
                              0,
                              WORDS(offsetof(struct T_2241, x_2188)),
                              0};
static WORD __GC__T_2240[] = {WORDS(sizeof(struct T_2240)),
                              0,
                              WORDS(offsetof(struct T_2240, x_2176)),
                              WORDS(offsetof(struct T_2240, x_2178)),
                              0};
static WORD __GC__T_2239[] = {WORDS(sizeof(struct T_2239)),
                              0,
                              WORDS(offsetof(struct T_2239, l_HasSize_CTCommon_HasPosition_CTCommon_CTCommon)),
                              WORDS(offsetof(struct T_2239, x_2182)),
                              WORDS(offsetof(struct T_2239, x_2184)),
                              0};
static WORD __GC__T_2238[] = {WORDS(sizeof(struct T_2238)),
                              0,
                              WORDS(offsetof(struct T_2238, x_2161)),
                              WORDS(offsetof(struct T_2238, x_2163)),
                              WORDS(offsetof(struct T_2238, x_2165)),
                              WORDS(offsetof(struct T_2238, x_2167)),
                              WORDS(offsetof(struct T_2238, x_2170)),
                              WORDS(offsetof(struct T_2238, x_2173)),
                              0};
static WORD __GC__T_2237[] = {WORDS(sizeof(struct T_2237)),
                              0,
                              WORDS(offsetof(struct T_2237, l_Component_CTCommon_IsFocusable_CTCommon_CTCommon)),
                              WORDS(offsetof(struct T_2237, l_Component_CTCommon_HasSize_CTCommon_CTCommon)),
                              WORDS(offsetof(struct T_2237, l_Component_CTCommon_HandlesEvents_CTCommon_CTCommon)),
                              WORDS(offsetof(struct T_2237, id_CTCommon)),
                              WORDS(offsetof(struct T_2237, x_2192)),
                              WORDS(offsetof(struct T_2237, x_2194)),
                              WORDS(offsetof(struct T_2237, x_2196)),
                              WORDS(offsetof(struct T_2237, x_2199)),
                              0};
static WORD __GC__T_2236[] = {WORDS(sizeof(struct T_2236)),
                              0,
                              WORDS(offsetof(struct T_2236, l_Button_CTButton_Component_CTCommon_CTButton)),
                              WORDS(offsetof(struct T_2236, l_Button_CTButton_HandlesMouseEvents_CTCommon_CTButton)),
                              WORDS(offsetof(struct T_2236, l_Button_CTButton_HandlesKeyEvents_CTCommon_CTButton)),
                              WORDS(offsetof(struct T_2236, x_2208)),
                              WORDS(offsetof(struct T_2236, x_2210)),
                              0};
static WORD __GC__T_2235[] = {WORDS(sizeof(struct T_2235)),
                              0,
                              WORDS(offsetof(struct T_2235, this_61)),
                              WORDS(offsetof(struct T_2235, id_17)),
                              WORDS(offsetof(struct T_2235, self_9)),
                              0};
static WORD __GC__T_2234[] = {WORDS(sizeof(struct T_2234)),
                              0,
                              WORDS(offsetof(struct T_2234, this_61)),
                              WORDS(offsetof(struct T_2234, self_9)),
                              0};
static WORD __GC__T_2233[] = {WORDS(sizeof(struct T_2233)),
                              0,
                              WORDS(offsetof(struct T_2233, focus_52)),
                              0};
static WORD __GC__T_2232[] = {WORDS(sizeof(struct T_2232)),
                              0,
                              WORDS(offsetof(struct T_2232, focus_52)),
                              0};
static WORD __GC__T_2231[] = {WORDS(sizeof(struct T_2231)),
                              0,
                              WORDS(offsetof(struct T_2231, focus_52)),
                              0};
static WORD __GC__T_2230[] = {WORDS(sizeof(struct T_2230)),
                              0,
                              WORDS(offsetof(struct T_2230, focus_52)),
                              0};
static WORD __GC__T_2229[] = {WORDS(sizeof(struct T_2229)),
                              0,
                              WORDS(offsetof(struct T_2229, focus_52)),
                              WORDS(offsetof(struct T_2229, self_9)),
                              WORDS(offsetof(struct T_2229, env_8)),
                              0};
static WORD __GC__T_2228[] = {WORDS(sizeof(struct T_2228)),
                              0,
                              WORDS(offsetof(struct T_2228, focus_52)),
                              WORDS(offsetof(struct T_2228, self_9)),
                              WORDS(offsetof(struct T_2228, env_8)),
                              0};
static WORD __GC__T_2227[] = {WORDS(sizeof(struct T_2227)),
                              0,
                              WORDS(offsetof(struct T_2227, self_9)),
                              0};
static WORD __GC__T_2226[] = {WORDS(sizeof(struct T_2226)),
                              0,
                              WORDS(offsetof(struct T_2226, self_9)),
                              0};
static WORD __GC__T_2225[] = {WORDS(sizeof(struct T_2225)),
                              0,
                              WORDS(offsetof(struct T_2225, self_9)),
                              0};
static WORD __GC__T_2224[] = {WORDS(sizeof(struct T_2224)),
                              0,
                              WORDS(offsetof(struct T_2224, self_9)),
                              0};
static WORD __GC__T_2223[] = {WORDS(sizeof(struct T_2223)),
                              0,
                              WORDS(offsetof(struct T_2223, self_9)),
                              0};
static WORD __GC__T_2222[] = {WORDS(sizeof(struct T_2222)),
                              0,
                              WORDS(offsetof(struct T_2222, a_2093)),
                              WORDS(offsetof(struct T_2222, self_9)),
                              0};
static WORD __GC__T_2221[] = {WORDS(sizeof(struct T_2221)),
                              0,
                              WORDS(offsetof(struct T_2221, self_9)),
                              0};
static WORD __GC__T_2220[] = {WORDS(sizeof(struct T_2220)),
                              0,
                              WORDS(offsetof(struct T_2220, self_9)),
                              0};
static WORD __GC__T_2219[] = {WORDS(sizeof(struct T_2219)),
                              0,
                              WORDS(offsetof(struct T_2219, a_2081)),
                              WORDS(offsetof(struct T_2219, id_17)),
                              WORDS(offsetof(struct T_2219, self_9)),
                              0};
static WORD __GC__T_2218[] = {WORDS(sizeof(struct T_2218)),
                              0,
                              WORDS(offsetof(struct T_2218, id_17)),
                              WORDS(offsetof(struct T_2218, self_9)),
                              0};
static WORD __GC__T_2217[] = {WORDS(sizeof(struct T_2217)),
                              0,
                              WORDS(offsetof(struct T_2217, self_9)),
                              0};
static WORD __GC__T_2216[] = {WORDS(sizeof(struct T_2216)),
                              0,
                              WORDS(offsetof(struct T_2216, a_2069)),
                              WORDS(offsetof(struct T_2216, id_17)),
                              WORDS(offsetof(struct T_2216, self_9)),
                              0};
static WORD __GC__T_2215[] = {WORDS(sizeof(struct T_2215)),
                              0,
                              WORDS(offsetof(struct T_2215, id_17)),
                              WORDS(offsetof(struct T_2215, self_9)),
                              0};
Component_CTCommon c_418_CTButton (Button_CTButton v_420) {
    return v_420->l_Button_CTButton_Component_CTCommon_CTButton;
}
HandlesMouseEvents_CTCommon c_421_CTButton (Button_CTButton v_423) {
    return v_423->l_Button_CTButton_HandlesMouseEvents_CTCommon_CTButton;
}
HandlesKeyEvents_CTCommon c_424_CTButton (Button_CTButton v_426) {
    return v_426->l_Button_CTButton_HandlesKeyEvents_CTCommon_CTButton;
}
IsFocusable_CTCommon c_428_CTButton (Button_CTButton a_427) {
    return a_427->l_Button_CTButton_Component_CTCommon_CTButton->l_Component_CTCommon_IsFocusable_CTCommon_CTCommon;
}
HasSize_CTCommon c_430_CTButton (Button_CTButton a_429) {
    return a_429->l_Button_CTButton_Component_CTCommon_CTButton->l_Component_CTCommon_HasSize_CTCommon_CTCommon;
}
HandlesEvents_CTCommon c_432_CTButton (Button_CTButton a_431) {
    return a_431->l_Button_CTButton_Component_CTCommon_CTButton->l_Component_CTCommon_HandlesEvents_CTCommon_CTCommon;
}
HasPosition_CTCommon c_434_CTButton (Button_CTButton a_433) {
    return a_433->l_Button_CTButton_Component_CTCommon_CTButton->l_Component_CTCommon_HasSize_CTCommon_CTCommon->l_HasSize_CTCommon_HasPosition_CTCommon_CTCommon;
}
Button_CTButton mkCocoaButton_CTButton (Env_POSIX env_8,
                                        Int d_2214) {
    Ref self_9;
    NEW (Ref, self_9, WORDS(sizeof(struct Ref))+
                      WORDS(sizeof(struct S_467)));
    INITREF(self_9);
    ((S_467)STATEOF(self_9))->GCINFO = __GC__S_467;
    CocoaID_CTCommon id_17;
    id_17 = mkCocoaID_CTCommon(0);
    CLOS setTitle_18;
    NEW (CLOS, setTitle_18, WORDS(sizeof(struct T_2215)));
    ((T_2215)setTitle_18)->GCINFO = __GC__T_2215;
    ((T_2215)setTitle_18)->Code = f_2252;
    ((T_2215)setTitle_18)->id_17 = id_17;
    ((T_2215)setTitle_18)->self_9 = self_9;
    CLOS getTitle_23;
    NEW (CLOS, getTitle_23, WORDS(sizeof(struct T_2217)));
    ((T_2217)getTitle_23)->GCINFO = __GC__T_2217;
    ((T_2217)getTitle_23)->Code = f_2255;
    ((T_2217)getTitle_23)->self_9 = self_9;
    CLOS setPosition_25;
    NEW (CLOS, setPosition_25, WORDS(sizeof(struct T_2218)));
    ((T_2218)setPosition_25)->GCINFO = __GC__T_2218;
    ((T_2218)setPosition_25)->Code = f_2263;
    ((T_2218)setPosition_25)->id_17 = id_17;
    ((T_2218)setPosition_25)->self_9 = self_9;
    CLOS getPosition_30;
    NEW (CLOS, getPosition_30, WORDS(sizeof(struct T_2220)));
    ((T_2220)getPosition_30)->GCINFO = __GC__T_2220;
    ((T_2220)getPosition_30)->Code = f_2266;
    ((T_2220)getPosition_30)->self_9 = self_9;
    CLOS setSize_32;
    NEW (CLOS, setSize_32, WORDS(sizeof(struct T_2221)));
    ((T_2221)setSize_32)->GCINFO = __GC__T_2221;
    ((T_2221)setSize_32)->Code = f_2273;
    ((T_2221)setSize_32)->self_9 = self_9;
    CLOS getSize_35;
    NEW (CLOS, getSize_35, WORDS(sizeof(struct T_2223)));
    ((T_2223)getSize_35)->GCINFO = __GC__T_2223;
    ((T_2223)getSize_35)->Code = f_2276;
    ((T_2223)getSize_35)->self_9 = self_9;
    CLOS destroy_37;
    NEW (CLOS, destroy_37, WORDS(sizeof(struct T_2224)));
    ((T_2224)destroy_37)->GCINFO = __GC__T_2224;
    ((T_2224)destroy_37)->Code = f_2279;
    ((T_2224)destroy_37)->self_9 = self_9;
    CLOS getName_39;
    NEW (CLOS, getName_39, WORDS(sizeof(struct T_2217)));
    ((T_2217)getName_39)->GCINFO = __GC__T_2217;
    ((T_2217)getName_39)->Code = f_2282;
    ((T_2217)getName_39)->self_9 = self_9;
    CLOS installKeyListener_43;
    NEW (CLOS, installKeyListener_43, WORDS(sizeof(struct T_2225)));
    ((T_2225)installKeyListener_43)->GCINFO = __GC__T_2225;
    ((T_2225)installKeyListener_43)->Code = f_2287;
    ((T_2225)installKeyListener_43)->self_9 = self_9;
    CLOS installMouseListener_46;
    NEW (CLOS, installMouseListener_46, WORDS(sizeof(struct T_2226)));
    ((T_2226)installMouseListener_46)->GCINFO = __GC__T_2226;
    ((T_2226)installMouseListener_46)->Code = f_2292;
    ((T_2226)installMouseListener_46)->self_9 = self_9;
    CLOS setName_49;
    NEW (CLOS, setName_49, WORDS(sizeof(struct T_2227)));
    ((T_2227)setName_49)->GCINFO = __GC__T_2227;
    ((T_2227)setName_49)->Code = f_2296;
    ((T_2227)setName_49)->self_9 = self_9;
    IsFocusable_CTCommon focus_52;
    CLOS setNextFocusTarget_53;
    CLOS getNextFocusTarget_54;
    CLOS setPreviousFocusTarget_55;
    CLOS getPreviousFocusTarget_56;
    CLOS setIsFocusable_57;
    CLOS getIsFocusable_58;
    CLOS handleEvent_59;
    CLOS init_60;
    CLOS x_2161;
    CLOS x_2163;
    CLOS x_2165;
    CLOS x_2167;
    CLOS x_2170;
    CLOS x_2173;
    CLOS x_2176;
    CLOS x_2178;
    CLOS x_2182;
    CLOS x_2184;
    CLOS x_2188;
    CLOS x_2192;
    CLOS x_2194;
    CLOS x_2196;
    CLOS x_2199;
    CLOS x_2202;
    CLOS x_2205;
    CLOS x_2208;
    CLOS x_2210;
    T_2238 x_2366;
    T_2240 x_2377;
    T_2239 x_2388;
    T_2241 x_2395;
    T_2237 x_2414;
    T_2242 x_2420;
    T_2243 x_2426;
    Button_CTButton this_61;
    Component_CTCommon x_1738;
    x_2176 = getPosition_30;
    x_2178 = setPosition_25;
    NEW (T_2240, x_2377, WORDS(sizeof(struct T_2240)));
    x_2377->GCINFO = __GC__T_2240;
    x_2377->getPosition_CTCommon = f_2370;
    x_2377->setPosition_CTCommon = f_2376;
    x_2377->x_2176 = x_2176;
    x_2377->x_2178 = x_2178;
    x_2182 = getSize_35;
    x_2184 = setSize_32;
    NEW (T_2239, x_2388, WORDS(sizeof(struct T_2239)));
    x_2388->GCINFO = __GC__T_2239;
    x_2388->l_HasSize_CTCommon_HasPosition_CTCommon_CTCommon = (HasPosition_CTCommon)x_2377;
    x_2388->getSize_CTCommon = f_2381;
    x_2388->setSize_CTCommon = f_2387;
    x_2388->x_2182 = x_2182;
    x_2388->x_2184 = x_2184;
    x_2192 = destroy_37;
    x_2194 = getName_39;
    x_2199 = setName_49;
    x_2202 = installMouseListener_46;
    NEW (T_2242, x_2420, WORDS(sizeof(struct T_2242)));
    x_2420->GCINFO = __GC__T_2242;
    x_2420->installMouseListener_CTCommon = f_2419;
    x_2420->x_2202 = x_2202;
    x_2205 = installKeyListener_43;
    NEW (T_2243, x_2426, WORDS(sizeof(struct T_2243)));
    x_2426->GCINFO = __GC__T_2243;
    x_2426->installKeyListener_CTCommon = f_2425;
    x_2426->x_2205 = x_2205;
    x_2208 = getTitle_23;
    x_2210 = setTitle_18;
    {   Array roots = CYCLIC_BEGIN(22,0);
        focus_52 = (IsFocusable_CTCommon)roots->elems[0];
        setNextFocusTarget_53 = (CLOS)roots->elems[1];
        getNextFocusTarget_54 = (CLOS)roots->elems[2];
        setPreviousFocusTarget_55 = (CLOS)roots->elems[3];
        getPreviousFocusTarget_56 = (CLOS)roots->elems[4];
        setIsFocusable_57 = (CLOS)roots->elems[5];
        getIsFocusable_58 = (CLOS)roots->elems[6];
        handleEvent_59 = (CLOS)roots->elems[7];
        init_60 = (CLOS)roots->elems[8];
        x_2161 = (CLOS)roots->elems[9];
        x_2163 = (CLOS)roots->elems[10];
        x_2165 = (CLOS)roots->elems[11];
        x_2167 = (CLOS)roots->elems[12];
        x_2170 = (CLOS)roots->elems[13];
        x_2173 = (CLOS)roots->elems[14];
        x_2188 = (CLOS)roots->elems[15];
        x_2196 = (CLOS)roots->elems[16];
        x_2366 = (T_2238)roots->elems[17];
        x_2395 = (T_2241)roots->elems[18];
        x_2414 = (T_2237)roots->elems[19];
        this_61 = (Button_CTButton)roots->elems[20];
        x_1738 = (Component_CTCommon)roots->elems[21];
        focus_52 = focusWrapper_CTCommon(x_1738, (Bool)1, 0);
        roots->elems[0] = (POLY)focus_52;
        NEW (CLOS, setNextFocusTarget_53, WORDS(sizeof(struct T_2228)));
        roots->elems[1] = (POLY)setNextFocusTarget_53;
        ((T_2228)(CLOS)roots->elems[1])->GCINFO = __GC__T_2228;
        ((T_2228)(CLOS)roots->elems[1])->Code = f_2303;
        ((T_2228)(CLOS)roots->elems[1])->focus_52 = focus_52;
        ((T_2228)(CLOS)roots->elems[1])->self_9 = self_9;
        ((T_2228)(CLOS)roots->elems[1])->env_8 = env_8;
        NEW (CLOS, getNextFocusTarget_54, WORDS(sizeof(struct T_2229)));
        roots->elems[2] = (POLY)getNextFocusTarget_54;
        ((T_2229)(CLOS)roots->elems[2])->GCINFO = __GC__T_2229;
        ((T_2229)(CLOS)roots->elems[2])->Code = f_2309;
        ((T_2229)(CLOS)roots->elems[2])->focus_52 = focus_52;
        ((T_2229)(CLOS)roots->elems[2])->self_9 = self_9;
        ((T_2229)(CLOS)roots->elems[2])->env_8 = env_8;
        NEW (CLOS, setPreviousFocusTarget_55, WORDS(sizeof(struct T_2230)));
        roots->elems[3] = (POLY)setPreviousFocusTarget_55;
        ((T_2230)(CLOS)roots->elems[3])->GCINFO = __GC__T_2230;
        ((T_2230)(CLOS)roots->elems[3])->Code = f_2314;
        ((T_2230)(CLOS)roots->elems[3])->focus_52 = focus_52;
        NEW (CLOS, getPreviousFocusTarget_56, WORDS(sizeof(struct T_2231)));
        roots->elems[4] = (POLY)getPreviousFocusTarget_56;
        ((T_2231)(CLOS)roots->elems[4])->GCINFO = __GC__T_2231;
        ((T_2231)(CLOS)roots->elems[4])->Code = f_2318;
        ((T_2231)(CLOS)roots->elems[4])->focus_52 = focus_52;
        NEW (CLOS, setIsFocusable_57, WORDS(sizeof(struct T_2232)));
        roots->elems[5] = (POLY)setIsFocusable_57;
        ((T_2232)(CLOS)roots->elems[5])->GCINFO = __GC__T_2232;
        ((T_2232)(CLOS)roots->elems[5])->Code = f_2323;
        ((T_2232)(CLOS)roots->elems[5])->focus_52 = focus_52;
        NEW (CLOS, getIsFocusable_58, WORDS(sizeof(struct T_2233)));
        roots->elems[6] = (POLY)getIsFocusable_58;
        ((T_2233)(CLOS)roots->elems[6])->GCINFO = __GC__T_2233;
        ((T_2233)(CLOS)roots->elems[6])->Code = f_2327;
        ((T_2233)(CLOS)roots->elems[6])->focus_52 = focus_52;
        NEW (CLOS, handleEvent_59, WORDS(sizeof(struct T_2234)));
        roots->elems[7] = (POLY)handleEvent_59;
        ((T_2234)(CLOS)roots->elems[7])->GCINFO = __GC__T_2234;
        ((T_2234)(CLOS)roots->elems[7])->Code = f_2334;
        ((T_2234)(CLOS)roots->elems[7])->this_61 = this_61;
        ((T_2234)(CLOS)roots->elems[7])->self_9 = self_9;
        NEW (CLOS, init_60, WORDS(sizeof(struct T_2235)));
        roots->elems[8] = (POLY)init_60;
        ((T_2235)(CLOS)roots->elems[8])->GCINFO = __GC__T_2235;
        ((T_2235)(CLOS)roots->elems[8])->Code = f_2338;
        ((T_2235)(CLOS)roots->elems[8])->this_61 = this_61;
        ((T_2235)(CLOS)roots->elems[8])->id_17 = id_17;
        ((T_2235)(CLOS)roots->elems[8])->self_9 = self_9;
        x_2161 = getIsFocusable_58;
        roots->elems[9] = (POLY)x_2161;
        x_2163 = getNextFocusTarget_54;
        roots->elems[10] = (POLY)x_2163;
        x_2165 = getPreviousFocusTarget_56;
        roots->elems[11] = (POLY)x_2165;
        x_2167 = setIsFocusable_57;
        roots->elems[12] = (POLY)x_2167;
        x_2170 = setNextFocusTarget_53;
        roots->elems[13] = (POLY)x_2170;
        x_2173 = setPreviousFocusTarget_55;
        roots->elems[14] = (POLY)x_2173;
        x_2188 = handleEvent_59;
        roots->elems[15] = (POLY)x_2188;
        x_2196 = init_60;
        roots->elems[16] = (POLY)x_2196;
        NEW (T_2238, x_2366, WORDS(sizeof(struct T_2238)));
        roots->elems[17] = (POLY)x_2366;
        ((T_2238)roots->elems[17])->GCINFO = __GC__T_2238;
        ((T_2238)roots->elems[17])->getIsFocusable_CTCommon = f_2342;
        ((T_2238)roots->elems[17])->getNextFocusTarget_CTCommon = f_2346;
        ((T_2238)roots->elems[17])->getPreviousFocusTarget_CTCommon = f_2350;
        ((T_2238)roots->elems[17])->setIsFocusable_CTCommon = f_2355;
        ((T_2238)roots->elems[17])->setNextFocusTarget_CTCommon = f_2360;
        ((T_2238)roots->elems[17])->setPreviousFocusTarget_CTCommon = f_2365;
        ((T_2238)roots->elems[17])->x_2161 = x_2161;
        ((T_2238)roots->elems[17])->x_2163 = x_2163;
        ((T_2238)roots->elems[17])->x_2165 = x_2165;
        ((T_2238)roots->elems[17])->x_2167 = x_2167;
        ((T_2238)roots->elems[17])->x_2170 = x_2170;
        ((T_2238)roots->elems[17])->x_2173 = x_2173;
        NEW (T_2241, x_2395, WORDS(sizeof(struct T_2241)));
        roots->elems[18] = (POLY)x_2395;
        ((T_2241)roots->elems[18])->GCINFO = __GC__T_2241;
        ((T_2241)roots->elems[18])->handleEvent_CTCommon = f_2394;
        ((T_2241)roots->elems[18])->x_2188 = x_2188;
        NEW (T_2237, x_2414, WORDS(sizeof(struct T_2237)));
        roots->elems[19] = (POLY)x_2414;
        ((T_2237)roots->elems[19])->GCINFO = __GC__T_2237;
        ((T_2237)roots->elems[19])->l_Component_CTCommon_IsFocusable_CTCommon_CTCommon = (IsFocusable_CTCommon)x_2366;
        ((T_2237)roots->elems[19])->l_Component_CTCommon_HasSize_CTCommon_CTCommon = (HasSize_CTCommon)x_2388;
        ((T_2237)roots->elems[19])->l_Component_CTCommon_HandlesEvents_CTCommon_CTCommon = (HandlesEvents_CTCommon)x_2395;
        ((T_2237)roots->elems[19])->id_CTCommon = id_17;
        ((T_2237)roots->elems[19])->destroy_CTCommon = f_2399;
        ((T_2237)roots->elems[19])->getName_CTCommon = f_2403;
        ((T_2237)roots->elems[19])->init_CTCommon = f_2408;
        ((T_2237)roots->elems[19])->setName_CTCommon = f_2413;
        ((T_2237)roots->elems[19])->x_2192 = x_2192;
        ((T_2237)roots->elems[19])->x_2194 = x_2194;
        ((T_2237)roots->elems[19])->x_2196 = x_2196;
        ((T_2237)roots->elems[19])->x_2199 = x_2199;
        NEW (Button_CTButton, this_61, WORDS(sizeof(struct T_2236)));
        roots->elems[20] = (POLY)this_61;
        ((T_2236)(Button_CTButton)roots->elems[20])->GCINFO = __GC__T_2236;
        ((T_2236)(Button_CTButton)roots->elems[20])->l_Button_CTButton_Component_CTCommon_CTButton = (Component_CTCommon)x_2414;
        ((T_2236)(Button_CTButton)roots->elems[20])->l_Button_CTButton_HandlesMouseEvents_CTCommon_CTButton = (HandlesMouseEvents_CTCommon)x_2420;
        ((T_2236)(Button_CTButton)roots->elems[20])->l_Button_CTButton_HandlesKeyEvents_CTCommon_CTButton = (HandlesKeyEvents_CTCommon)x_2426;
        ((T_2236)(Button_CTButton)roots->elems[20])->getTitle_CTButton = f_2430;
        ((T_2236)(Button_CTButton)roots->elems[20])->setTitle_CTButton = f_2436;
        ((T_2236)(Button_CTButton)roots->elems[20])->x_2208 = x_2208;
        ((T_2236)(Button_CTButton)roots->elems[20])->x_2210 = x_2210;
        x_1738 = this_61->l_Button_CTButton_Component_CTCommon_CTButton;
        roots->elems[21] = (POLY)x_1738;
        CYCLIC_END(roots, hp);
    }
    ((S_467)STATEOF(self_9))->myState_10 = (CocoaState_CTCommon)1;
    Position_CTCommon x_2437;
    NEW (Position_CTCommon, x_2437, WORDS(sizeof(struct Position_CTCommon)));
    x_2437->GCINFO = __GC__Position_CTCommon;
    x_2437->x_CTCommon = 0;
    x_2437->y_CTCommon = 0;
    ((S_467)STATEOF(self_9))->position_11 = x_2437;
    Size_CTCommon x_2438;
    NEW (Size_CTCommon, x_2438, WORDS(sizeof(struct Size_CTCommon)));
    x_2438->GCINFO = __GC__Size_CTCommon;
    x_2438->width_CTCommon = 108;
    x_2438->height_CTCommon = 17;
    ((S_467)STATEOF(self_9))->size_12 = x_2438;
    ((S_467)STATEOF(self_9))->mouseEventHandler_13 = (Maybe_Prelude)1;
    ((S_467)STATEOF(self_9))->keyEventHandler_14 = (Maybe_Prelude)1;
    ((S_467)STATEOF(self_9))->title_15 = getStr("TestButton");
    ((S_467)STATEOF(self_9))->name_16 = getStr("button");
    return this_61;
}
static TUP0 inithelper_41 (CocoaID_CTCommon id_17, Ref self_42) {
    Msg d_86;
    d_86 = buttonSetTitle_CTButton(id_17,
                                   ((S_467)STATEOF(self_42))->title_15,
                                   Inherit,
                                   Inherit);
    Msg d_87;
    d_87 = buttonSetPosition_CTButton(id_17,
                                      ((S_467)STATEOF(self_42))->position_11,
                                      Inherit,
                                      Inherit);
    return (TUP0)0;
}
static TUP0 f_2251 (T_2216 this_2249) {
    Ref self_20;
    self_20 = (Ref)LOCK((OID)this_2249->self_9);
    ((S_467)STATEOF(self_20))->title_15 = this_2249->a_2069;
    CocoaState_CTCommon x_2250;
    x_2250 = ((S_467)STATEOF(self_20))->myState_10;
    switch ((WORD)x_2250) {
        case 2: { Ref self_21;
                  self_21 = self_20;
                  Msg d_81;
                  d_81 = buttonSetTitle_CTButton(this_2249->id_17,
                                                 this_2249->a_2069,
                                                 Inherit,
                                                 Inherit);
                  UNLOCK((OID)self_20);
                  return (TUP0)0;
                }
                break;
        case 0: { Ref self_22;
                  self_22 = self_20;
                  UNLOCK((OID)self_20);
                  return (TUP0)0;
                }
                break;
        case 1: { Ref self_22;
                  self_22 = self_20;
                  UNLOCK((OID)self_20);
                  return (TUP0)0;
                }
                break;
    }
}
static Msg f_2252 (T_2215 this_2245,
                   LIST a_2069,
                   Time a_2070,
                   Time a_2071) {
    Msg x_2068;
    NEW (Msg, x_2068, WORDS(sizeof(struct T_2216)));
    ((T_2216)x_2068)->GCINFO = __GC__T_2216;
    ((T_2216)x_2068)->Code = f_2251;
    ((T_2216)x_2068)->a_2069 = a_2069;
    ((T_2216)x_2068)->id_17 = this_2245->id_17;
    ((T_2216)x_2068)->self_9 = this_2245->self_9;
    return (Msg)ASYNC(x_2068, a_2070, a_2071);
}
static LIST f_2255 (T_2217 this_2253, Int a_2075) {
    Ref self_24;
    self_24 = (Ref)LOCK((OID)this_2253->self_9);
    LIST x_2072;
    x_2072 = ((S_467)STATEOF(self_24))->title_15;
    UNLOCK((OID)self_24);
    return x_2072;
}
static TUP0 f_2262 (T_2219 this_2260) {
    Ref self_27;
    self_27 = (Ref)LOCK((OID)this_2260->self_9);
    CocoaState_CTCommon x_2261;
    x_2261 = ((S_467)STATEOF(self_27))->myState_10;
    switch ((WORD)x_2261) {
        case 2: { Msg d_84;
                  d_84 = buttonSetPosition_CTButton(this_2260->id_17,
                                                    this_2260->a_2081,
                                                    Inherit,
                                                    Inherit);
                  break;
                }
                break;
        case 0: break;
        case 1: break;
    }
    ((S_467)STATEOF(self_27))->position_11 = this_2260->a_2081;
    UNLOCK((OID)self_27);
    return (TUP0)0;
}
static Msg f_2263 (T_2218 this_2256,
                   Position_CTCommon a_2081,
                   Time a_2082,
                   Time a_2083) {
    Msg x_2080;
    NEW (Msg, x_2080, WORDS(sizeof(struct T_2219)));
    ((T_2219)x_2080)->GCINFO = __GC__T_2219;
    ((T_2219)x_2080)->Code = f_2262;
    ((T_2219)x_2080)->a_2081 = a_2081;
    ((T_2219)x_2080)->id_17 = this_2256->id_17;
    ((T_2219)x_2080)->self_9 = this_2256->self_9;
    return (Msg)ASYNC(x_2080, a_2082, a_2083);
}
static Position_CTCommon f_2266 (T_2220 this_2264, Int a_2087) {
    Ref self_31;
    self_31 = (Ref)LOCK((OID)this_2264->self_9);
    Position_CTCommon x_2084;
    x_2084 = ((S_467)STATEOF(self_31))->position_11;
    UNLOCK((OID)self_31);
    return x_2084;
}
static TUP0 f_2272 (T_2222 this_2271) {
    Ref self_34;
    self_34 = (Ref)LOCK((OID)this_2271->self_9);
    ((S_467)STATEOF(self_34))->size_12 = this_2271->a_2093;
    UNLOCK((OID)self_34);
    return (TUP0)0;
}
static Msg f_2273 (T_2221 this_2267,
                   Size_CTCommon a_2093,
                   Time a_2094,
                   Time a_2095) {
    Msg x_2092;
    NEW (Msg, x_2092, WORDS(sizeof(struct T_2222)));
    ((T_2222)x_2092)->GCINFO = __GC__T_2222;
    ((T_2222)x_2092)->Code = f_2272;
    ((T_2222)x_2092)->a_2093 = a_2093;
    ((T_2222)x_2092)->self_9 = this_2267->self_9;
    return (Msg)ASYNC(x_2092, a_2094, a_2095);
}
static Size_CTCommon f_2276 (T_2223 this_2274, Int a_2099) {
    Ref self_36;
    self_36 = (Ref)LOCK((OID)this_2274->self_9);
    Size_CTCommon x_2096;
    x_2096 = ((S_467)STATEOF(self_36))->size_12;
    UNLOCK((OID)self_36);
    return x_2096;
}
static TUP0 f_2279 (T_2224 this_2277, Int a_2102) {
    Ref self_38;
    self_38 = (Ref)LOCK((OID)this_2277->self_9);
    ((S_467)STATEOF(self_38))->myState_10 = (CocoaState_CTCommon)0;
    UNLOCK((OID)self_38);
    return (TUP0)0;
}
static LIST f_2282 (T_2217 this_2280, Int a_2106) {
    Ref self_40;
    self_40 = (Ref)LOCK((OID)this_2280->self_9);
    LIST x_2103;
    x_2103 = ((S_467)STATEOF(self_40))->name_16;
    UNLOCK((OID)self_40);
    return x_2103;
}
static TUP0 f_2287 (T_2225 this_2283, CLOS a_2111, Int a_2112) {
    Ref self_45;
    self_45 = (Ref)LOCK((OID)this_2283->self_9);
    _Just_Prelude x_2286;
    NEW (_Just_Prelude, x_2286, WORDS(sizeof(struct _Just_Prelude)));
    x_2286->GCINFO = __GC___Just_Prelude+((4 * (BITS32)0));
    x_2286->a = (POLY)a_2111;
    ((S_467)STATEOF(self_45))->keyEventHandler_14 = (Maybe_Prelude)x_2286;
    UNLOCK((OID)self_45);
    return (TUP0)0;
}
static TUP0 f_2292 (T_2226 this_2288, CLOS a_2119, Int a_2120) {
    Ref self_48;
    self_48 = (Ref)LOCK((OID)this_2288->self_9);
    _Just_Prelude x_2291;
    NEW (_Just_Prelude, x_2291, WORDS(sizeof(struct _Just_Prelude)));
    x_2291->GCINFO = __GC___Just_Prelude+((4 * (BITS32)0));
    x_2291->a = (POLY)a_2119;
    ((S_467)STATEOF(self_48))->mouseEventHandler_13 = (Maybe_Prelude)x_2291;
    UNLOCK((OID)self_48);
    return (TUP0)0;
}
static TUP0 f_2296 (T_2227 this_2293, LIST a_2125, Int a_2126) {
    Ref self_51;
    self_51 = (Ref)LOCK((OID)this_2293->self_9);
    ((S_467)STATEOF(self_51))->name_16 = a_2125;
    UNLOCK((OID)self_51);
    return (TUP0)0;
}
static TUP0 f_2303 (T_2228 this_2297,
                    Maybe_Prelude a_2129,
                    Int a_2130) {
    Ref self_63;
    self_63 = (Ref)LOCK((OID)this_2297->self_9);
    switch ((WORD)isJust_Prelude((BITS32)0, a_2129)) {
        case 1: { LIST x_90;
                  x_90 = showName_CTCommon((BITS32)0, a_2129, self_63);
                  WFile_POSIX x_2300;
                  x_2300 = this_2297->env_8->stdout_POSIX;
                  Int d_89;
                  d_89 = x_2300->write_POSIX(x_2300,
                                             _sym_20_Prelude/* ++ */((BITS32)1,
                                                                     ((S_467)STATEOF(self_63))->name_16,
                                                                     _sym_20_Prelude/* ++ */((BITS32)1,
                                                                                             getStr(" is changing focus to "),
                                                                                             x_90)),
                                             0);
                  break;
                }
                break;
        case 0: { WFile_POSIX x_2301;
                  x_2301 = this_2297->env_8->stdout_POSIX;
                  Int d_91;
                  d_91 = x_2301->write_POSIX(x_2301,
                                             _sym_20_Prelude/* ++ */((BITS32)1,
                                                                     ((S_467)STATEOF(self_63))->name_16,
                                                                     getStr(" is changing focus to NOTHING\n")),
                                             0);
                  break;
                }
                break;
    }
    IsFocusable_CTCommon x_2302;
    x_2302 = this_2297->focus_52;
    TUP0 res_66;
    res_66 = x_2302->setNextFocusTarget_CTCommon(x_2302, a_2129, 0);
    UNLOCK((OID)self_63);
    return (TUP0)0;
}
static Maybe_Prelude f_2309 (T_2229 this_2304, Int a_2133) {
    Ref self_67;
    self_67 = (Ref)LOCK((OID)this_2304->self_9);
    IsFocusable_CTCommon x_2306;
    x_2306 = this_2304->focus_52;
    Maybe_Prelude res_68;
    res_68 = x_2306->getNextFocusTarget_CTCommon(x_2306, 0);
    switch ((WORD)isJust_Prelude((BITS32)0, res_68)) {
        case 1: { WFile_POSIX x_2307;
                  x_2307 = this_2304->env_8->stdout_POSIX;
                  Int d_93;
                  d_93 = x_2307->write_POSIX(x_2307,
                                             _sym_20_Prelude/* ++ */((BITS32)1,
                                                                     ((S_467)STATEOF(self_67))->name_16,
                                                                     getStr(" is asked for getNextFocusTarget, returning TRUE\n")),
                                             0);
                  break;
                }
                break;
        case 0: { WFile_POSIX x_2308;
                  x_2308 = this_2304->env_8->stdout_POSIX;
                  Int d_94;
                  d_94 = x_2308->write_POSIX(x_2308,
                                             _sym_20_Prelude/* ++ */((BITS32)1,
                                                                     ((S_467)STATEOF(self_67))->name_16,
                                                                     getStr(" is asked for getNextFocusTarget, returing FALSE\n")),
                                             0);
                  break;
                }
                break;
    }
    UNLOCK((OID)self_67);
    return res_68;
}
static TUP0 f_2314 (T_2230 this_2310,
                    Maybe_Prelude a_2136,
                    Int a_2137) {
    IsFocusable_CTCommon x_2313;
    x_2313 = this_2310->focus_52;
    return x_2313->setPreviousFocusTarget_CTCommon(x_2313,
                                                   a_2136,
                                                   a_2137);
}
static Maybe_Prelude f_2318 (T_2231 this_2315, Int a_2139) {
    IsFocusable_CTCommon x_2317;
    x_2317 = this_2315->focus_52;
    return x_2317->getPreviousFocusTarget_CTCommon(x_2317, a_2139);
}
static TUP0 f_2323 (T_2232 this_2319, Bool a_2142, Int a_2143) {
    IsFocusable_CTCommon x_2322;
    x_2322 = this_2319->focus_52;
    return x_2322->setIsFocusable_CTCommon(x_2322, a_2142, a_2143);
}
static Bool f_2327 (T_2233 this_2324, Int a_2145) {
    IsFocusable_CTCommon x_2326;
    x_2326 = this_2324->focus_52;
    return x_2326->getIsFocusable_CTCommon(x_2326, a_2145);
}
static Maybe_Prelude f_2334 (T_2234 this_2328,
                             CocoaEvent_CTCommon a_2154,
                             LIST a_2155,
                             Int a_2156) {
    switch (a_2154->Tag) {
        case 0: { KeyEventType_CTCommon x_100;
                  x_100 = ((_KeyEvent_CTCommon)a_2154)->a;
                  Ref self_73;
                  self_73 = (Ref)LOCK((OID)this_2328->self_9);
                  Bool x_97;
                  x_97 = dynamicHandleEvent_CTCommon((BITS32)0,
                                                     (POLY)x_100,
                                                     ((S_467)STATEOF(self_73))->keyEventHandler_14,
                                                     self_73);
                  _Just_Prelude x_2332;
                  NEW (_Just_Prelude, x_2332, WORDS(sizeof(struct _Just_Prelude)));
                  x_2332->GCINFO = __GC___Just_Prelude+((4 * (BITS32)0));
                  x_2332->a = (POLY)this_2328->this_61->l_Button_CTButton_Component_CTCommon_CTButton;
                  Maybe_Prelude x_2146;
                  x_2146 = boolToMaybe_CTCommon((BITS32)0,
                                                (Maybe_Prelude)x_2332,
                                                x_97);
                  UNLOCK((OID)self_73);
                  return x_2146;
                }
                break;
        case 1: { MouseEventType_CTCommon x_101;
                  x_101 = ((_MouseEvent_CTCommon)a_2154)->a;
                  Ref self_76;
                  self_76 = (Ref)LOCK((OID)this_2328->self_9);
                  Bool x_98;
                  x_98 = dynamicHandleEvent_CTCommon((BITS32)0,
                                                     (POLY)x_101,
                                                     ((S_467)STATEOF(self_76))->mouseEventHandler_13,
                                                     self_76);
                  _Just_Prelude x_2333;
                  NEW (_Just_Prelude, x_2333, WORDS(sizeof(struct _Just_Prelude)));
                  x_2333->GCINFO = __GC___Just_Prelude+((4 * (BITS32)0));
                  x_2333->a = (POLY)this_2328->this_61->l_Button_CTButton_Component_CTCommon_CTButton;
                  Maybe_Prelude x_2149;
                  x_2149 = boolToMaybe_CTCommon((BITS32)0,
                                                (Maybe_Prelude)x_2333,
                                                x_98);
                  UNLOCK((OID)self_76);
                  return x_2149;
                }
                break;
        default: { Ref self_78;
                   self_78 = (Ref)LOCK((OID)this_2328->self_9);
                   UNLOCK((OID)self_78);
                   return (Maybe_Prelude)1;
                 }
                 break;
    }
}
static TUP0 f_2338 (T_2235 this_2335,
                    App_CTCommon a_2159,
                    Int a_2160) {
    Ref self_80;
    self_80 = (Ref)LOCK((OID)this_2335->self_9);
    ((S_467)STATEOF(self_80))->myState_10 = (CocoaState_CTCommon)2;
    TUP0 d_102;
    d_102 = initButton_CTButton(this_2335->this_61, a_2159, 0);
    TUP0 d_103;
    d_103 = inithelper_41(this_2335->id_17, self_80);
    UNLOCK((OID)self_80);
    return (TUP0)0;
}
static Bool f_2342 (T_2238 this_2339, Int a_2162) {
    CLOS x_2341;
    x_2341 = this_2339->x_2161;
    return ((Bool(*)(CLOS, Int))(x_2341->Code))(x_2341, a_2162);
}
static Maybe_Prelude f_2346 (T_2238 this_2343, Int a_2164) {
    CLOS x_2345;
    x_2345 = this_2343->x_2163;
    return ((Maybe_Prelude(*)(CLOS, Int))(x_2345->Code))(x_2345,
                                                         a_2164);
}
static Maybe_Prelude f_2350 (T_2238 this_2347, Int a_2166) {
    CLOS x_2349;
    x_2349 = this_2347->x_2165;
    return ((Maybe_Prelude(*)(CLOS, Int))(x_2349->Code))(x_2349,
                                                         a_2166);
}
static TUP0 f_2355 (T_2238 this_2351, Bool a_2168, Int a_2169) {
    CLOS x_2354;
    x_2354 = this_2351->x_2167;
    return ((TUP0(*)(CLOS, Bool, Int))(x_2354->Code))(x_2354,
                                                      a_2168,
                                                      a_2169);
}
static TUP0 f_2360 (T_2238 this_2356,
                    Maybe_Prelude a_2171,
                    Int a_2172) {
    CLOS x_2359;
    x_2359 = this_2356->x_2170;
    return ((TUP0(*)(CLOS, Maybe_Prelude, Int))(x_2359->Code))(x_2359,
                                                               a_2171,
                                                               a_2172);
}
static TUP0 f_2365 (T_2238 this_2361,
                    Maybe_Prelude a_2174,
                    Int a_2175) {
    CLOS x_2364;
    x_2364 = this_2361->x_2173;
    return ((TUP0(*)(CLOS, Maybe_Prelude, Int))(x_2364->Code))(x_2364,
                                                               a_2174,
                                                               a_2175);
}
static Position_CTCommon f_2370 (T_2240 this_2367, Int a_2177) {
    CLOS x_2369;
    x_2369 = this_2367->x_2176;
    return ((Position_CTCommon(*)(CLOS, Int))(x_2369->Code))(x_2369,
                                                             a_2177);
}
static Msg f_2376 (T_2240 this_2371,
                   Position_CTCommon a_2179,
                   Time a_2180,
                   Time a_2181) {
    CLOS x_2375;
    x_2375 = this_2371->x_2178;
    return ((Msg(*)(CLOS, Position_CTCommon, Time, Time))(x_2375->Code))(x_2375,
                                                                         a_2179,
                                                                         a_2180,
                                                                         a_2181);
}
static Size_CTCommon f_2381 (T_2239 this_2378, Int a_2183) {
    CLOS x_2380;
    x_2380 = this_2378->x_2182;
    return ((Size_CTCommon(*)(CLOS, Int))(x_2380->Code))(x_2380,
                                                         a_2183);
}
static Msg f_2387 (T_2239 this_2382,
                   Size_CTCommon a_2185,
                   Time a_2186,
                   Time a_2187) {
    CLOS x_2386;
    x_2386 = this_2382->x_2184;
    return ((Msg(*)(CLOS, Size_CTCommon, Time, Time))(x_2386->Code))(x_2386,
                                                                     a_2185,
                                                                     a_2186,
                                                                     a_2187);
}
static Maybe_Prelude f_2394 (T_2241 this_2389,
                             CocoaEvent_CTCommon a_2189,
                             LIST a_2190,
                             Int a_2191) {
    CLOS x_2393;
    x_2393 = this_2389->x_2188;
    return ((Maybe_Prelude(*)(CLOS, CocoaEvent_CTCommon, LIST, Int))(x_2393->Code))(x_2393,
                                                                                    a_2189,
                                                                                    a_2190,
                                                                                    a_2191);
}
static TUP0 f_2399 (T_2237 this_2396, Int a_2193) {
    CLOS x_2398;
    x_2398 = this_2396->x_2192;
    return ((TUP0(*)(CLOS, Int))(x_2398->Code))(x_2398, a_2193);
}
static LIST f_2403 (T_2237 this_2400, Int a_2195) {
    CLOS x_2402;
    x_2402 = this_2400->x_2194;
    return ((LIST(*)(CLOS, Int))(x_2402->Code))(x_2402, a_2195);
}
static TUP0 f_2408 (T_2237 this_2404,
                    App_CTCommon a_2197,
                    Int a_2198) {
    CLOS x_2407;
    x_2407 = this_2404->x_2196;
    return ((TUP0(*)(CLOS, App_CTCommon, Int))(x_2407->Code))(x_2407,
                                                              a_2197,
                                                              a_2198);
}
static TUP0 f_2413 (T_2237 this_2409, LIST a_2200, Int a_2201) {
    CLOS x_2412;
    x_2412 = this_2409->x_2199;
    return ((TUP0(*)(CLOS, LIST, Int))(x_2412->Code))(x_2412,
                                                      a_2200,
                                                      a_2201);
}
static TUP0 f_2419 (T_2242 this_2415, CLOS a_2203, Int a_2204) {
    CLOS x_2418;
    x_2418 = this_2415->x_2202;
    return ((TUP0(*)(CLOS, CLOS, Int))(x_2418->Code))(x_2418,
                                                      a_2203,
                                                      a_2204);
}
static TUP0 f_2425 (T_2243 this_2421, CLOS a_2206, Int a_2207) {
    CLOS x_2424;
    x_2424 = this_2421->x_2205;
    return ((TUP0(*)(CLOS, CLOS, Int))(x_2424->Code))(x_2424,
                                                      a_2206,
                                                      a_2207);
}
static LIST f_2430 (T_2236 this_2427, Int a_2209) {
    CLOS x_2429;
    x_2429 = this_2427->x_2208;
    return ((LIST(*)(CLOS, Int))(x_2429->Code))(x_2429, a_2209);
}
static Msg f_2436 (T_2236 this_2431,
                   LIST a_2211,
                   Time a_2212,
                   Time a_2213) {
    CLOS x_2435;
    x_2435 = this_2431->x_2210;
    return ((Msg(*)(CLOS, LIST, Time, Time))(x_2435->Code))(x_2435,
                                                            a_2211,
                                                            a_2212,
                                                            a_2213);
}
 
void _init_CTButton () {
    static int INITIALIZED = 0;
    if (!INITIALIZED) {
        _init_Prelude();
        _init_CTCommon();
        _init_POSIX();
        INITIALIZED = 1;
    }
}
 

