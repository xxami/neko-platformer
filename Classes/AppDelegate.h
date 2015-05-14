
#ifndef  _APP_DELEGATE_H_
#define  _APP_DELEGATE_H_

#include "cocos2d.h"

/**
 * maximum fps for desktop targets
 * mobile targets are vsync enabled
 */
#define FPS_MAX 160

#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
    #define CC_PLATFORM_DESKTOP 1
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_LINUX)
    #define CC_PLATFORM_DESKTOP 1
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_MAC)
    #define CC_PLATFORM_DESKTOP 1
#endif

namespace neko {

    class  AppDelegate : private cocos2d::Application
    {
        public:

        AppDelegate();
        virtual ~AppDelegate();
        virtual void initGLContextAttrs();
        virtual bool applicationDidFinishLaunching();
        virtual void applicationDidEnterBackground();
        virtual void applicationWillEnterForeground();

    };

}

#endif // _APP_DELEGATE_H_
