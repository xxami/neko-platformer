
#ifndef _neko_neko_h// lol
#define _neko_neko_h
#include "cocos2d.h"
#include "anticaps.h"

#if (cc_target_platform == cc_platform_win32)
    #define cc_platform_desktop 1
#elif (cc_target_platform == cc_platform_linux)
    #define cc_platform_desktop 1
#elif (cc_target_platform == cc_platform_mac)
    #define cc_platform_desktop 1
#endif

#endif // _neko_neko_h