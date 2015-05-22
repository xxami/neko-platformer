
#ifndef _neko_scene_game_h_
#define _neko_scene_game_h_

#include "neko.h"

#define id_tilemap 1

namespace neko {

    namespace cc = cocos2d;

    class GameScene : public cc::Layer {
        
        private:

        typedef GameScene self;
        typedef cc::Layer super;

        public:
        
        static cc::Scene* create_scene();
        
        virtual bool init();

        cc_createfunc(GameScene);

    };

}

#endif // _neko_scene_game_h_
