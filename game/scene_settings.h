
#ifndef _neko_scene_settings_h_
#define _neko_scene_settings_h_

#include "neko.h"

namespace neko {

    namespace cc = cocos2d;

    /**
     * main scene
     * display/contain intro/menu screen
     */
    class SettingsScene : public cc::Layer {
        
        private:

        typedef SettingsScene self;
        typedef cc::Layer super;

        public:
        
        static cc::Scene* create_scene();
        
        virtual bool init();

        cc_createfunc(SettingsScene);

    };

}

#endif // _neko_scene_settings_h_
