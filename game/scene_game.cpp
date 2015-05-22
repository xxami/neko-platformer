
#include "neko.h"
#include "scene_game.h"

namespace neko {

    namespace cc = cocos2d;

    using cc::Vec2;

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

        cc::TMXTiledMap *map;
        cc::TMXLayer *layer;

        map = cc::TMXTiledMap::create("maps/test.tmx");
        map->setPosition(Neko::screen_width / 2, Neko::screen_height / 2);
        this->addChild(map, 0, id_tilemap);

        return true;
    }

}
