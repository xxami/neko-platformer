
#include "neko.h"
#include "scene_game_intro.h"
#include "scene_game.h"

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
        auto listener = cc::EventListenerTouchOneByOne::create();
        listener->onTouchEnded = cc_callback2(GameIntroScene::cb_touch_end, this);

        /**
         * unused
         */
        listener->onTouchBegan = [](cc::Touch *t, cc::Event *e) {
            return true;
        };

        /**
         * unused
         */
        listener->onTouchMoved = [](cc::Touch *t, cc::Event *e) {
            return;
        };

        cc_event_dispatch_graphed(listener, this);
        return true;
    }

    /**
     * callback for a touch/click on screen - skip intro
     */
    void GameIntroScene::cb_touch_end(cc::Touch* touch, cc::Event *e) {
        cc::Director::getInstance()->replaceScene(
            GameScene::create_scene());
    }

}
