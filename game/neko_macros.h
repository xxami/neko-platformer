
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
 * cc key constants
 */
#define cc_key_return cc::EventKeyboard::KeyCode::KEY_KP_ENTER
#define cc_key_enter cc::EventKeyboard::KeyCode::KEY_KP_ENTER
#define cc_key_w cc::EventKeyboard::KeyCode::KEY_W
#define cc_key_a cc::EventKeyboard::KeyCode::KEY_A
#define cc_key_s cc::EventKeyboard::KeyCode::KEY_S
#define cc_key_d cc::EventKeyboard::KeyCode::KEY_D
#define cc_key_space cc::EventKeyboard::KeyCode::KEY_SPACE
#define cc_key_up cc::EventKeyboard::KeyCode::KEY_UP_ARROW
#define cc_key_down cc::EventKeyboard::KeyCode::KEY_DOWN_ARROW
#define cc_key_left cc::EventKeyboard::KeyCode::KEY_LEFT_ARROW
#define cc_key_right cc::EventKeyboard::KeyCode::KEY_RIGHT_ARROW
#define cc_key_tilde cc::EventKeyboard::KeyCode::KEY_GRAVE

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
#define neko_key_enter 35
#define neko_key_w 146
#define neko_key_a 124
#define neko_key_s 142
#define neko_key_d 127
#define neko_key_space 59
#define neko_key_up 28
#define neko_key_down 29
#define neko_key_left 26
#define neko_key_right 27
#define neko_key_tilde 123

#endif // _neko_neko_macros_h
 