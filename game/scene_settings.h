
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

        /**
         * reference everything for redraw()
         */
        cc::Sprite *menu_bkg;
        cc::Label *label_back;
        cc::Label *label_resolution;
        cc::MenuItemLabel *menu_item_back;
        cc::MenuItemLabel *menu_item_resolution;
        cc::Menu *menu;

        void cb_menu_item_back(cc::Ref *s);

        void cb_menu_item_resolution(cc::Ref *s);

        /**
         * refresh resolution dependant sections
         */
        void refresh_scale();

        public:
        
        static cc::Scene* create_scene();
        
        virtual bool init();

        cc_createfunc(SettingsScene);

    };

}

#endif // _neko_scene_settings_h_
