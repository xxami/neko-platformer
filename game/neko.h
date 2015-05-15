
#ifndef _NEKO_NEKO_H_ // lol
#define _NEKO_NEKO_H_

#include "anticaps.h"

#if (cc_target_platform == cc_platform_win32)
    #define cc_platform_desktop 1
#elif (cc_target_platform == cc_platform_linux)
    #define cc_platform_desktop 1
#elif (cc_target_platform == cc_platform_mac)
    #define cc_platform_desktop 1
#endif

#endif // _NEKO_NEKO_H_