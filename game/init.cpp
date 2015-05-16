
#include "neko.h"
#include "init.h"
#include "scene_start.h"

#define fps_max 300

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
             * resolution for desktop targets
             * no support for fullscreen currently
             */
            #ifdef cc_platform_desktop
            Size res = glview->getFrameSize();
            cc_log("glview->getVisibleSize return: %.2fx%.2f", res.width, res.height);

            if (res.width > 1920 && res.height > 1080) {
                cc_log("set resolution to 1920x1080");
                glview->setFrameSize(1920, 1080);
            }
            else if (res.width > 1280 && res.height > 720) {
                cc_log("set resolution to 1280x720");
                glview->setFrameSize(1280, 720);
            }
            else {
                cc_log("set resolution to 640x360");
                glview->setFrameSize(640, 360);
            }
            #endif

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
        cc_log("set fps_max to %d", fps_max);
        director->setAnimationInterval(1.0 / fps_max);
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