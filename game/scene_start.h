
#ifndef _neko_scene_start_h_
#define _neko_scene_start_h_

#include "neko.h"

namespace neko {

    namespace cc = cocos2d;

    /**
     * display/manage title intro
     */
    class Intro : public cc::Layer {

        private:

        typedef Intro self;
        typedef cc::Layer super;

        cc::Sprite *title_bkg;

        public:

        virtual bool init();

        cc_createfunc(Intro);

    };

    /**
     * display/manage menu
     */
    class Menu : public cc::Layer {

        private:

        typedef Menu self;
        typedef cc::Layer super;

        cc::Sprite *menu_bkg;

        void cb_menu_item_play(cc::Ref *s);

        void cb_menu_item_settings(cc::Ref *s);

        public:

        virtual bool init();

        cc_createfunc(Menu);

    };

    /**
     * main scene
     * display/contain intro/menu screen
     */
    class IntroScene : public cc::Layer {
        
        private:

        typedef IntroScene self;
        typedef cc::Layer super;

        Intro *intro_layer;
        Menu *menu_layer;

        public:
        
        static cc::Scene* create_scene();
        
        virtual bool init();

        cc_createfunc(IntroScene);

    };

}

#endif // _neko_scene_start_h_
