
#ifndef _neko_neko_h
#define _neko_neko_h
#include "cocos2d.h"
#include "anticaps.h"

#define empty_constructor(name) name::name() { }
#define emptry_destructor(name) name::~name() { }

#if (cc_target_platform == cc_platform_win32)
    #define cc_platform_desktop 1
#elif (cc_target_platform == cc_platform_linux)
    #define cc_platform_desktop 1
#elif (cc_target_platform == cc_platform_mac)
    #define cc_platform_desktop 1
#endif

#define neko_game_width 640
#define neko_game_height 360

#endif // _neko_neko_h