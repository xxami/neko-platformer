
#ifndef _neko_scene_start_h_
#define _neko_scene_start_h_

#include "cocos2d.h"
#include "neko.h"

namespace neko {

	class IntroScene : public cocos2d::Layer
	{
		public:
	    
	    static cocos2d::Scene* createScene();
	    virtual bool init();
	    
	    cc_createfunc(IntroScene);
	};

}

#endif // _neko_scene_start_h_
