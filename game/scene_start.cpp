
#include "neko.h"
#include "scene_start.h"

namespace neko {

    namespace cc = cocos2d;

    using cc::Vec2;

    /**
     * Intro
     */

    bool Intro::init() {
        if (!super::init()) return false;
        this->title_bkg = cc::Sprite::create("sprites/static/peach-boy.png");
        this->title_bkg->setPosition(Vec2(Neko::screen_width / 2,
            Neko::screen_height / 2));
        this->title_bkg->getTexture()->setAliasTexParameters();
        this->title_bkg->setScale(Neko::game_scale, Neko::game_scale);
        this->addChild(this->title_bkg, 0);

        return true;
    }

    /**
     * Menu
     */

    bool Menu::init() {
        if (!super::init()) return false;

        this->menu_bkg = cc::Sprite::create("sprites/static/peach-boy-menu.png");
        this->menu_bkg->setPosition(Vec2(Neko::screen_width / 2,
            Neko::screen_height / 2));
        this->menu_bkg->getTexture()->setAliasTexParameters();
        this->menu_bkg->setScale(Neko::game_scale, Neko::game_scale);
        this->addChild(this->menu_bkg);

        auto menu_item_play = cc::Label::createWithBMFont("fonts/pixantiqua.fnt",
            "Play");
        menu_item_play->setPosition(Vec2(neko_remap2(Neko::game_width / 2,
            (Neko::game_height / 2) + 30)));
        menu_item_play->getTexture()->setAliasTexParameters();
        menu_item_play->setScale(neko_remap(2.0f));

        this->addChild(menu_item_play);

        auto menu_item_settings = cc::Label::createWithBMFont("fonts/pixantiqua.fnt",
            "Settings");
        menu_item_settings->setPosition(Vec2(neko_remap2(Neko::game_width / 2,
            (Neko::game_height / 2) - 30)));
        menu_item_settings->getTexture()->setAliasTexParameters();
        menu_item_settings->setScale(neko_remap(2.0f));

        this->addChild(menu_item_settings);

        return true;
    }

    /**
     * IntroScene
     */

    cc::Scene* IntroScene::create_scene() {
        auto scene = cc::Scene::create();
        auto layer = self::create();
        scene->addChild(layer);

        return scene;
    }

    bool IntroScene::init() {
        if (!super::init()) return false;
        
        this->intro_layer = Intro::create();
        this->intro_layer->setCascadeOpacityEnabled(true);

        this->menu_layer = Menu::create();
        this->menu_layer->setCascadeOpacityEnabled(true);

        this->intro_layer->setOpacity(0);
        this->menu_layer->setOpacity(0);

        this->addChild(this->intro_layer, 2);
        this->addChild(this->menu_layer, 1);

        auto menu_enter = cc::CallFunc::create([this] () {
            this->menu_layer->setOpacity(255);
        });

        this->intro_layer->runAction(cc::Sequence::create(
            cc::FadeIn::create(1.3f), cc::DelayTime::create(0.5f),
            menu_enter, cc::FadeOut::create(2.3f), nullptr));

        return true;
    }

}

