
#include "neko.h"
#include "neko_physics.h"

namespace neko {

	namespace cc = cocos2d;

	bool PhysicsObject::init() {
		if (!super::init()) return false;

		return true;
	}

	bool Physics::init() {
		if (!super::init()) return false;

		return true;
	}

}