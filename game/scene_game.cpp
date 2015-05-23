
#include "neko.h"
#include "scene_game.h"

namespace neko {

    namespace cc = cocos2d;

    using cc::Vec2;
    using cc::experimental::TMXTiledMap;
    using cc::experimental::TMXLayer;

    /**
     * GameIntroScene
     */

    cc::Scene* GameScene::create_scene() {
        auto scene = cc::Scene::create();
        auto layer = self::create();
        scene->addChild(layer);

        return scene;
    }

    bool GameScene::init() {
        if (!super::init()) return false;

        this->init_map("maps/test.tmx");

        return true;
    }

    /**
     * load map, objects, init level
     */
    void GameScene::init_map(const std::string& map_file) {
        cc_log("loading map :: %s", map_file.c_str());
        this->map = TMXTiledMap::create(map_file);
        this->map->setScale(neko_remap(1.0f));
        this->layer_base = map->getLayer("base");
        this->init_map_collide(map->getLayer("collisions"));

        this->addChild(this->map, 0, id_tilemap);
    }

    /**
     * add collision data from a given layer
     */
    void GameScene::init_map_collide(TMXLayer *layer) {
        cc_assert(layer != nullptr, "no collision data found in map");
        /**
         * add/process valid collision layer
         */
        this->layer_collide = layer;
        this->layer_collide->setVisible(false);
    }

}
