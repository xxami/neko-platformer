
#ifndef _neko_neko_macros_h
#define _neko_neko_macros_h

#include "cocos2d.h"
#include "anticaps.h"

#define empty_constructor(name) name::name() { }
#define emptry_destructor(name) name::~name() { }

#define empty {}

#if (cc_target_platform == cc_platform_win32)
    #define cc_platform_desktop 1
#elif (cc_target_platform == cc_platform_linux)
    #define cc_platform_desktop 1
#elif (cc_target_platform == cc_platform_mac)
    #define cc_platform_desktop 1
#endif

#define cc_event_dispatch_graphed(__expr1, __expr2) \
    this->_eventDispatcher->addEventListenerWithSceneGraphPriority( \
    __expr1, __expr2)

/**
 * set to 1 to jump straight to the game
 * scene for quick testing
 */
#ifdef cc_debug
    #define debug_game_quick 1
#endif

/**
 * used to map coordinates and scale values
 * to the correct value depending on the resolution
 */
#define neko_remap(__expr) (__expr) * neko::Neko::game_scale
#define neko_remap2(__expr1, __expr2) \
    (__expr1) * neko::Neko::game_scale, \
    (__expr2) * neko::Neko::game_scale

/**
 * neko key constants
 */
#define neko_key_return 35

 #endif // _neko_neko_macros_h