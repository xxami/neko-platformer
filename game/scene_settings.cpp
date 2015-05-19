
#include "neko.h"
#include "scene_settings.h"
#include "scene_start.h"

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

        this->menu_bkg = cc::Sprite::create("sprites/static/peach-boy-menu.png");
        this->menu_bkg->getTexture()->setAliasTexParameters();

        this->label_back = cc::Label::createWithBMFont("fonts/pixantiqua.fnt",
            "Back");
        this->label_back->getTexture()->setAliasTexParameters();

        this->menu_item_back = cc::MenuItemLabel::create(this->label_back,
            cc_callback1(SettingsScene::cb_menu_item_back, this));

        this->label_resolution = cc::Label::createWithBMFont("fonts/pixantiqua.fnt",
            "Resolution: " + std::to_string(Neko::screen_width) + "x" +
            std::to_string(Neko::screen_height));
        this->label_resolution->getTexture()->setAliasTexParameters();

        this->menu_item_resolution = cc::MenuItemLabel::create(this->label_resolution,
            cc_callback1(SettingsScene::cb_menu_item_resolution, this));

        this->menu = cc::Menu::create(this->menu_item_back,
            this->menu_item_resolution, nullptr);

        this->refresh_scale();

        this->addChild(this->menu_bkg);
        this->addChild(this->menu);

        return true;
    }

    void SettingsScene::cb_menu_item_back(cc::Ref *s) {
        /**
         * not popped because resolution may have changed
         */
        cc::Director::getInstance()->replaceScene(
            IntroScene::create_scene());
    }

    void SettingsScene::cb_menu_item_resolution(cc::Ref *s) {
        if (Neko::game_scale == 1) {
            /**
             * switch to 1280x720
             */
            Neko::screen_width = 1280;
            Neko::screen_height = 720;
            Neko::game_scale = 2;
            this->menu_item_resolution->setString("Resolution: 1280x720");
        }
        else if (Neko::game_scale == 2) {
            /**
             * switch to 1920x1080
             */
            Neko::screen_width = 1920;
            Neko::screen_height = 1080;
            Neko::game_scale = 3;
            this->menu_item_resolution->setString("Resolution: 1920x1080");
        }
        else {
            /**
             * switch to default 640x360
             */
            Neko::screen_width = 640;
            Neko::screen_height = 360;
            Neko::game_scale = 1;
            this->menu_item_resolution->setString("Resolution: 640x360");
        }
        cc::Director::getInstance()->getOpenGLView()->setFrameSize(
            Neko::screen_width, Neko::screen_height);
        
        this->refresh_scale();
    }

    /**
     * refresh resolution dependant sections
     */
    void SettingsScene::refresh_scale() {
        this->menu_bkg->setPosition(Vec2(Neko::screen_width / 2,
            Neko::screen_height / 2));
        this->menu_bkg->setScale(Neko::game_scale, Neko::game_scale);

        this->label_back->disableEffect(cc::LabelEffect::ALL);
        this->label_back->enableShadow(cc::Color4B(0, 0, 0, 135),
            cc::Size(0, neko_remap(-1)), 0);
        this->menu_item_back->setScale(neko_remap(2.0f));

        this->label_resolution->disableEffect(cc::LabelEffect::ALL);
        this->label_resolution->enableShadow(cc::Color4B(0, 0, 0, 135),
            cc::Size(0, neko_remap(-1)), 0);
        this->menu_item_resolution->setScale(neko_remap(2.0f));

        this->menu->alignItemsVertically();
        auto pos = this->menu_item_back->getPosition();
        this->menu_item_back->setPosition(Vec2(pos.x, pos.y + (neko_remap(10))));
        pos = this->menu_item_resolution->getPosition();
        this->menu_item_resolution->setPosition(Vec2(pos.x, pos.y - (neko_remap(10))));
    }

}
