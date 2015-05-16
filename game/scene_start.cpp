
#include "neko.h"
#include "scene_start.h"

namespace neko {

    using namespace cocos2d;

    Scene* IntroScene::createScene() {
        auto scene = Scene::create();
        auto layer = IntroScene::create();
        scene->addChild(layer);
        return scene;
    }

    bool IntroScene::init()
    {
        if (!super::init()) return false;

        this->render_game = RenderTexture::create(Neko::game_width, Neko::game_height,
            Texture2D::PixelFormat::RGBA8888);
        this->render_game->begin();

        /**
         * offscreen render
         */
        this->title_bkg = Sprite::create("sprites/static/golden-boy.png");
        this->title_bkg->setPosition(Vec2(Neko::game_width / 2,
            Neko::game_height / 2));
        this->title_bkg->visit();


        this->render_game->end();
        this->render_game->getSprite()->getTexture()->setAliasTexParameters();

        /**
         * onscreen render
         */
        Sprite *render_screen = Sprite::createWithTexture(
            this->render_game->getSprite()->getTexture());
        render_screen->setFlippedX(false);
        render_screen->setFlippedY(true);
        render_screen->setScale(Neko::game_scale, Neko::game_scale);
        render_screen->setPosition(Vec2(Neko::screen_width / 2,
            Neko::screen_height / 2));
        this->addChild(render_screen);
        return true;
    }

}