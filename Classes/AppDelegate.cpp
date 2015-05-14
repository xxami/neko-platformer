
#include "AppDelegate.h"
#include "HelloWorldScene.h"

using namespace cocos2d;

namespace neko {

     AppDelegate::AppDelegate() {
        /**
         * construct
         */
    }

    AppDelegate::~AppDelegate() {
        /**
         * destruct
         */
    }

    void AppDelegate::initGLContextAttrs() {
        GLContextAttrs glContextAttrs = {8, 8, 8, 8, 24, 8};
        GLView::setGLContextAttrs(glContextAttrs);
    }

    static int register_all_packages() {
        return 0;
    }

    /**
     * setup / init starting scene
     */
    bool AppDelegate::applicationDidFinishLaunching() {
        auto director = Director::getInstance();
        auto glview = director->getOpenGLView();

        if (!glview) {
            glview = GLViewImpl::create("neko-platformer");
            director->setOpenGLView(glview);
        }

        /**
         * display fps @ debug
         */
        #ifdef COCOS2D_DEBUG
        director->setDisplayStats(true);
        #endif

        /**
         * fps_max default 1.0 / 60
         */
        #ifdef CC_PLATFORM_DESKTOP
        director->setAnimationInterval(1.0 / FPS_MAX);
        #endif

        register_all_packages();
        auto scene = HelloWorld::createScene();
        director->runWithScene(scene);

        return true;
    }

    /**
     * handle inactive window
     * pause game/animation/sound?
     */
    void AppDelegate::applicationDidEnterBackground() {
        Director::getInstance()->stopAnimation();
    }

    /**
     * handle reactivated window
     * resume game/animation/sound?
     */
    void AppDelegate::applicationWillEnterForeground() {
        Director::getInstance()->startAnimation();
    }

}