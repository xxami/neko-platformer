
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

namespace neko {

	using namespace cocos2d;

	/**
	 * contain globals
	 */
	namespace Neko {

		/**
		 * resolution of the device screen
		 */
		extern int screen_width;
		extern int screen_height;

		/**
		 * resolution of the game/render
		 */
		extern int game_width;
		extern int game_height;

		/**
		 * how much to scale the 640x360
		 * render texture so it fills the screen
		 */
		extern int game_scale;

		/**
		 * maximum framerate for desktop platforms
		 */
		extern int fps_max;

	};

}

#endif // _neko_neko_h