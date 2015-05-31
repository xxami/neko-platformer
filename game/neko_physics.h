
#ifndef _neko_neko_physics_h_
#define _neko_neko_physics_h_

#include "neko.h"

namespace neko {

	namespace cc = cocos2d;

	/**
	 * base class for physics objects
	 */
	class PhysicsObject : public cc::Node {

		private:

		typedef PhysicsObject self;
		typedef cc::Node super;

		public:

		virtual bool init();

		cc_createfunc(PhysicsObject);

	};

	/**
	 * manage physics simulation and collisions
	 */
	class Physics : public cc::Node {

		private:

		typedef Physics self;
		typedef cc::Node super;

		public:

		virtual bool init();

		cc_createfunc(Physics);

	};

}

#endif // _neko_neko_physics_h_