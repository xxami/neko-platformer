
#ifndef _neko_scene_game_intro_h_
#define _neko_scene_game_intro_h_

#include "neko.h"

namespace neko {

    namespace cc = cocos2d;

    /**
     * main scene
     * display/contain intro/menu screen
     */
    class GameIntroScene : public cc::Layer {
        
        private:

        typedef GameIntroScene self;
        typedef cc::Layer super;

        public:
        
        static cc::Scene* create_scene();
        
        virtual bool init();

        cc_createfunc(GameIntroScene);

    };

}

#endif // _neko_scene_game_intro_h_
