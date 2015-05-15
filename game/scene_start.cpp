
#include "scene_start.h"

using namespace cocos2d;

namespace neko {

    Scene* IntroScene::createScene() {
        auto scene = Scene::create();
        auto layer = IntroScene::create();
        scene->addChild(layer);
        return scene;
    }

    bool IntroScene::init()
    {
        if (!Layer::init()) {
            return false;
        }
        
        Size visibleSize = Director::getInstance()->getVisibleSize();
        Vec2 origin = Director::getInstance()->getVisibleOrigin();        
        auto label = Label::createWithTTF("Hello World", "fonts/Marker Felt.ttf", 24);
        label->setPosition(Vec2(origin.x + visibleSize.width/2,
            origin.y + visibleSize.height - label->getContentSize().height));
        this->addChild(label, 1);

        return true;
    }

}