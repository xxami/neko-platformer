
#ifndef _neko_scene_game_h_
#define _neko_scene_game_h_

#include "neko.h"

#define id_tilemap 1

namespace neko {

    namespace cc = cocos2d;

    using cc::experimental::TMXTiledMap;
    using cc::experimental::TMXLayer;

    class GameScene : public cc::Layer {
        
        private:

        typedef GameScene self;
        typedef cc::Layer super;

        TMXTiledMap *map;

        TMXLayer *layer_base;
        TMXLayer *layer_collide;

        /**
         * load map, objects, init level
         */
        void init_map(const std::string& map_file);

        public:
        
        static cc::Scene* create_scene();
        
        virtual bool init();

        cc_createfunc(GameScene);

    };

}

#endif // _neko_scene_game_h_
