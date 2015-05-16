
#ifndef _neko_scene_start_h_
#define _neko_scene_start_h_

#include "cocos2d.h"
#include "neko.h"

namespace neko {

	using namespace cocos2d;

	class IntroScene : public cocos2d::Layer
	{
		private:

		/**
		 * offscreen texture used to render game
		 * before upscaling to higher resolutions
		 */
		RenderTexture *game;

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
