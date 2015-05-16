
#ifndef  _neko_init_h_
#define  _neko_init_h_

#include "neko.h"

namespace neko {

    using namespace cocos2d;

    class  NekoPlatformer : private cocos2d::Application
    {
        public:

        NekoPlatformer();
        virtual ~NekoPlatformer();
        
        virtual void initGLContextAttrs();
        virtual bool applicationDidFinishLaunching();
        virtual void applicationDidEnterBackground();
        virtual void applicationWillEnterForeground();

    };

}

#endif // _neko_init_h
