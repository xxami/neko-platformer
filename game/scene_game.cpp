
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
        map = TMXTiledMap::create(map_file);
        map->setScale(neko_remap(1.0f));

        layer_base = map->getLayer("base");
        layer_collide = map->getLayer("collisions");

        this->addChild(map, 0, id_tilemap);
    }

}
