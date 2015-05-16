
#ifndef _neko_scene_start_h_
#define _neko_scene_start_h_

#include "neko.h"

namespace neko {

	using namespace cocos2d;

	class IntroScene : public Layer
	{
		private:

		typedef IntroScene self;
		typedef Layer super;

		/**
		 * offscreen texture used to render game
		 * before upscaling to higher resolutions
		 */
		RenderTexture *render_game;

		Sprite *title_bkg;

		Sprite *menu_bkg;

		public:
	    
	    /**
	     * scene setup
	     */
	    static Scene* createScene();
	    
	    virtual bool init();

	    cc_createfunc(IntroScene);
	};

}

#endif // _neko_scene_start_h_
