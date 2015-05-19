
#include "neko.h"
#include "scene_game_intro.h"

namespace neko {

    namespace cc = cocos2d;

    using cc::Vec2;

    /**
     * GameIntroScene
     */

    cc::Scene* GameIntroScene::create_scene() {
        auto scene = cc::Scene::create();
        auto layer = self::create();
        scene->addChild(layer);

        return scene;
    }

    bool GameIntroScene::init() {
        if (!super::init()) return false;
        return true;
    }

}
