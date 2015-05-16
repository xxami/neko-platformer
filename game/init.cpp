
#include "neko.h"
#include "init.h"
#include "scene_start.h"

namespace neko {

    using namespace cocos2d;

    empty_constructor(NekoPlatformer);
    emptry_destructor(NekoPlatformer);

    void NekoPlatformer::initGLContextAttrs() {
        GLContextAttrs glContextAttrs = {
            8, 8, 8, 8, 24, 8,
        };
        GLView::setGLContextAttrs(glContextAttrs);
    }

    /**
     * setup / init starting scene
     */
    bool NekoPlatformer::applicationDidFinishLaunching() {
        auto director = Director::getInstance();
        auto glview = director->getOpenGLView();

        if (!glview) {
            glview = GLViewImpl::create("neko-platformer");
            
            /**
             * todo: glview->setFrameSize()
             */
            glview->setFrameSize(Neko::screen_width, Neko::screen_height);
            director->setOpenGLView(glview);
        }

        /**
         * display fps @ debug
         */
        #ifdef cc_debug
        director->setDisplayStats(true);
        #endif

        /**
         * fps_max default 1.0 / 60
         */
        #ifdef cc_platform_desktop
        cc_log("set fps_max to %d", Neko::fps_max);
        director->setAnimationInterval(1.0 / Neko::fps_max);
        #endif

        auto scene = IntroScene::createScene();
        director->runWithScene(scene);

        return true;
    }

    /**
     * handle inactive window
     * pause game/animation/sound?
     */
    void NekoPlatformer::applicationDidEnterBackground() {
        Director::getInstance()->stopAnimation();
    }

    /**
     * handle reactivated window
     * resume game/animation/sound?
     */
    void NekoPlatformer::applicationWillEnterForeground() {
        Director::getInstance()->startAnimation();
    }

}