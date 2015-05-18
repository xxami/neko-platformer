
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

        auto test_item = cc::Label::createWithBMFont("fonts/pixantiqua.fnt",
            "Play");
        test_item->setPosition(Vec2(Neko::screen_width / 2,
            Neko::screen_height / 2));
        test_item->getTexture()->setAliasTexParameters();
        test_item->setScale(2.0f * Neko::game_scale);
        this->addChild(test_item);


        return true;
    }

    /**
     * IntroScene
     */

    cc::Scene* IntroScene::createScene() {
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

        auto title_fade_in = cc::FadeIn::create(1.3f);
        auto title_fade_out = cc::FadeOut::create(2.3f);

        auto menu_enter = cc::CallFunc::create([&s = this->menu_layer]() {
            //auto menu_fade_in = cc::FadeIn::create(1.3f);
            //s->runAction(menu_fade_in);
            s->setOpacity(255);
        });

        this->intro_layer->runAction(
            cc::Sequence::create(title_fade_in, menu_enter,
                title_fade_out, nullptr));

        return true;
    }

}

