
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

		/**
		 * objects this object should collide with
		 */
		std::vector<PhysicsObject*> collide_objects;

		public:

		/**
		 * set object as static or dynamic
		 */
		void setStatic(bool is_static);

		/**
		 * add objects this object should collide with
		 */
		void collideWith(int first, ...);

		/**
		 * set the gravity for this object
		 */
		void setGravity(int x, int y);

		/**
		 * set the velocity for this object
		 */
		void setVelocity(int x, int y);

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

		/**
		 * actively simulated
		 */
		std::unordered_map<int, PhysicsObject*> dynamic_objects;

		/**
		 * objects that can affect actively simulated objects
		 */
		std::unordered_map<int, PhysicsObject*>  static_objects;

		public:

		/**
		 * return PhysicsObject by object id
		 */
		PhysicsObject *getPhysicsObjectById(int id);

		/**
		 * simulate physics for all objects in this universe
		 */
		void simulate(float delta);

		/**
		 * add physics object to this universe
		 */
		void addObject(int object_id, PhysicsObject *pobj);

		/**
		 * stop simulating physics for this object
		 */
		void removeObject(int object_id);

		virtual bool init();

		cc_createfunc(Physics);

	};

}

#endif // _neko_neko_physics_h_