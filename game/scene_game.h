
#ifndef _neko_scene_game_h_
#define _neko_scene_game_h_

#include "neko.h"
#include "neko_physics.h"

#define id_tilemap 1

namespace neko {

    namespace cc = cocos2d;

    using cc::experimental::TMXTiledMap;
    using cc::experimental::TMXLayer;
    using cc::Sprite;
    using cc::SpriteBatchNode;

    class GameScene : public cc::Layer {
        
        private:

        typedef GameScene self;
        typedef cc::Layer super;

        TMXTiledMap *map;

        TMXLayer *layer_base;
        TMXLayer *layer_collide;

        SpriteBatchNode *player_sprites;
        Sprite *player;

        Physics *phys;

        /**
         * update:game loop
         */
        void update(float delta);

        /**
         * on key down event - todo: keyboard manager class
         */
        void cb_key_down(cc::EventKeyboard::KeyCode code, cc::Event *e);

        /**
         * on key release event - todo: keyboard manager class
         */
        void cb_key_up(cc::EventKeyboard::KeyCode code, cc::Event *e);

        /**
         * load map, objects, init level
         */
        void init_map(const std::string& map_file);

        /**
         * add map entity data from a given object group
         */
        void init_map_entities(cc::TMXObjectGroup *group);

        /**
         * add collision data from a given layer
         */
        void init_map_collide(TMXLayer *layer);

        public:
        
        static cc::Scene* create_scene();
        
        virtual bool init();

        cc_createfunc(GameScene);

    };

}

#endif // _neko_scene_game_h_
