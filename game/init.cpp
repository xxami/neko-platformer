
#include "neko.h"
#include "init.h"
#include "scene_start.h"

namespace neko {

    namespace cc = cocos2d;

    empty_constructor(NekoPlatformer);
    emptry_destructor(NekoPlatformer);

    void NekoPlatformer::initGLContextAttrs() {
        GLContextAttrs glContextAttrs = {
            8, 8, 8, 8, 24, 8,
        };
        cc::GLView::setGLContextAttrs(glContextAttrs);
    }

    /**
     * setup / init starting scene
     */
    bool NekoPlatformer::applicationDidFinishLaunching() {
        auto director = cc::Director::getInstance();
        auto glview = director->getOpenGLView();

        if (!glview) {
            glview = cc::GLViewImpl::create("neko-platformer");
            
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
        director->setAnimationInterval(1.0 / Neko::fps_max);
        #endif

        auto scene = IntroScene::create_scene();
        director->runWithScene(scene);

        return true;
    }

    /**
     * handle inactive window
     * pause game/animation/sound?
     */
    void NekoPlatformer::applicationDidEnterBackground() {
        cc::Director::getInstance()->stopAnimation();
    }

    /**
     * handle reactivated window
     * resume game/animation/sound?
     */
    void NekoPlatformer::applicationWillEnterForeground() {
        cc::Director::getInstance()->startAnimation();
    }

}