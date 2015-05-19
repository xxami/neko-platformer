
#include "neko.h"
#include "scene_settings.h"

namespace neko {

    namespace cc = cocos2d;

    using cc::Vec2;

    /**
     * SettingsScene
     */

    cc::Scene* SettingsScene::create_scene() {
        auto scene = cc::Scene::create();
        auto layer = self::create();
        scene->addChild(layer);

        return scene;
    }

    bool SettingsScene::init() {
        if (!super::init()) return false;
        return true;
    }

}
