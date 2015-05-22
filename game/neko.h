
#ifndef _neko_neko_h
#define _neko_neko_h

#include "cocos2d.h"
#include "anticaps.h"
#include "neko_macros.h"

namespace neko {

    namespace cc = cocos2d;

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