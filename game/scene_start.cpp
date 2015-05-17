
#include "neko.h"
#include "scene_start.h"

namespace neko {

    using namespace cocos2d;

    /**
     * Intro
     */

    bool Intro::init() {
        if (!super::init()) return false;
        this->title_bkg = Sprite::create("sprites/static/peach-boy.png");
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
        this->menu_bkg = Sprite::create("sprites/static/peach-boy-menu.png");
        this->menu_bkg->setPosition(Vec2(Neko::screen_width / 2,
            Neko::screen_height / 2));
        this->menu_bkg->getTexture()->setAliasTexParameters();
        this->menu_bkg->setScale(Neko::game_scale, Neko::game_scale);
        this->addChild(this->menu_bkg);

        return true;
    }

    /**
     * IntroScene
     */

    Scene* IntroScene::createScene() {
        auto scene = Scene::create();
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

        auto title_fade_in = FadeIn::create(1.3f);
        auto menu_fade_in = FadeIn::create(1.3f);
        auto title_fade_out = FadeOut::create(2.3f);

        this->intro_layer->runAction(
            Sequence::create(title_fade_in, title_fade_out, nullptr));

        this->menu_layer->runAction(
            Sequence::create(menu_fade_in, nullptr));

        return true;
    }

}

