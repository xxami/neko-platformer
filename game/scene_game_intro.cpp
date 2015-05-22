
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

        auto keybd_listener = cc::EventListenerKeyboard::create();

        /**
         * skip intro when return is pressed
         */
        keybd_listener->onKeyReleased = [](cc::EventKeyboard::KeyCode key,
            cc::Event *e) {
            if ((int)key == neko_key_return) {
                cc::Director::getInstance()->replaceScene(
                    GameScene::create_scene());
            }
            else {
                cc_log("key press - code :: %d", key);
            }
        };

        auto touch_listener = cc::EventListenerTouchOneByOne::create();
        touch_listener->onTouchEnded = cc_callback2(GameIntroScene::cb_touch_end, this);

        /**
         * unused
         */
        touch_listener->onTouchBegan = [](cc::Touch *t, cc::Event *e) {
            return true;
        };

        /**
         * unused
         */
        touch_listener->onTouchMoved = [](cc::Touch *t, cc::Event *e) {
            return;
        };

        cc_event_dispatch_graphed(touch_listener, this);
        cc_event_dispatch_graphed(keybd_listener, this);

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
