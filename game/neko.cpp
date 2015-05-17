
#include "neko.h"

namespace neko {

	using namespace cocos2d;

	/**
	 * contain globals
	 */
	namespace Neko {

		/**
		 * resolution of the device screen
		 */
		int screen_width = 640;
		int screen_height = 360;

		/**
		 * resolution of the game/render
		 */
		int game_width = 640;
		int game_height = 360;

		/**
		 * how much to scale the 640x360
		 * render texture so it fills the screen
		 */
		int game_scale = 1;

		/**
		 * maximum framerate for desktop platforms
		 */
		int fps_max = 300;

	};

}
