
#ifndef _neko_scene_start_h_
#define _neko_scene_start_h_

#include "neko.h"

namespace neko {

	using namespace cocos2d;

	/**
	 * display/manage title intro
	 */
	class Intro : public Layer {

		private:

		typedef Intro self;
		typedef Layer super;

		Sprite *title_bkg;

		public:

		virtual bool init();

		cc_createfunc(Intro);

	};

	/**
	 * display/manage menu
	 */
	class Menu : public Layer {

		private:

		typedef Menu self;
		typedef Layer super;

		Sprite *menu_bkg;

		public:

		virtual bool init();

		cc_createfunc(Menu);

	};

	/**
	 * main scene
	 * display/contain intro/menu screen
	 */
	class IntroScene : public Layer {
		
		private:

		typedef IntroScene self;
		typedef Layer super;

		Intro *intro_layer;
		Menu *menu_layer;

		public:
	    
	    static Scene* createScene();
	    
	    virtual bool init();

	    cc_createfunc(IntroScene);

	};

}

#endif // _neko_scene_start_h_
