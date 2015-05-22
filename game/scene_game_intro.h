
#ifndef _neko_scene_game_intro_h_
#define _neko_scene_game_intro_h_

#include "neko.h"

namespace neko {

    namespace cc = cocos2d;

    class GameIntroScene : public cc::Layer {
        
        private:

        typedef GameIntroScene self;
        typedef cc::Layer super;

        /**
         * callback for a touch/click on screen - skip intro
         */
        void cb_touch_end(cc::Touch* touch, cc::Event *e);

        public:
        
        static cc::Scene* create_scene();
        
        virtual bool init();

        cc_createfunc(GameIntroScene);

    };

}

#endif // _neko_scene_game_intro_h_
