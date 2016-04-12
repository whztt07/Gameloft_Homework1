#pragma once

#include "Global.h"

#define MAX_HEALTH 100

class GameObject
{

protected:

	ISceneNode									*node;
	list<ISceneNodeAnimator *>					animators;
	list<ISceneNodeAnimatorCollisionResponse *>	collisions;
	path										name;
	s32											health;

private:

	void addAllAnimators();

public:

			GameObject();
			GameObject(ISceneNode *node, list<ISceneNodeAnimator *> animators, list<ISceneNodeAnimatorCollisionResponse *> collisions, path name);
			GameObject(const GameObject &object);
			~GameObject();

			ISceneNode									*getNode() const;
			list<ISceneNodeAnimator *>					getAnimators() const;
			ISceneNodeAnimator							*getAnimatorByIndex(u32 index) const;
			list<ISceneNodeAnimatorCollisionResponse *>	getCollisions() const;
			ISceneNodeAnimatorCollisionResponse			*getCollisionByIndex(u32 index) const;
			path										getName() const;
			s32											getHealth() const;

			vector3df									getPosition() const;
			vector3df									getRotation() const;
			vector3df									getScale() const;

			void										setPosition(const vector3df position);
			void										setRotation(const vector3df rotation);
			void										setScale(const vector3df scale);

			void										setNode(ISceneNode *newNode);
			void										setAnimators(list<ISceneNodeAnimator *> newAnimators);
			void										setCollisions(list<ISceneNodeAnimatorCollisionResponse *>	newCollisions);
			void										setName(const path newName);
			void										setHealth(const s32 newHealth);

			bool										createNode(ISceneManager *manager);
			ITriangleSelector							*createTriangleSelector(ISceneManager *manager) const;

			void										addAnimator(ISceneNodeAnimator *animator);
			void										addCollision(ISceneNodeAnimatorCollisionResponse *collision);

	virtual	bool										fly(f32 delta);
			void										damage(u32 dmg);
			bool 										isDead() const;

	virtual void 										drop();

};