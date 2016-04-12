#include "RocketHolder.h"

list<Rocket> RocketHolder::getFRockets() const
{
	return fRockets;
}

list<Rocket> RocketHolder::getERockets() const
{
	return eRockets;
}

void RocketHolder::setFRockets(list<Rocket> rockets)
{
	fRockets = rockets;
}

void RocketHolder::setERockets(list<Rocket> rockets)
{
	eRockets = rockets;
}

void RocketHolder::addFighterRocket(ISceneManager *manager, IVideoDriver *video, TextureManager *&texManager, IMetaTriangleSelector *world, vector3df position)
{
	Rocket r;
	if (r.createRocket(manager, video, position, UP))
	{
		ISceneNodeAnimatorCollisionResponse *anim = manager->createCollisionResponseAnimator(world, r.getNode(), ROCKET_ELIPSE_BOUND, IDLE_VECTOR);
		if (anim)
			r.addCollision(anim);
		r.getNode()->setMaterialTexture(0, texManager->getRocketTexture()[0]);
		fRockets.push_back(r);
	}
}

void RocketHolder::addEnemyRocket(ISceneManager *manager, IVideoDriver *video, TextureManager *&texManager, ITriangleSelector *world, vector3df position)
{
	Rocket r;
	if (r.createRocket(manager, video, position, DOWN))
	{
		ISceneNodeAnimatorCollisionResponse *anim = manager->createCollisionResponseAnimator(world, r.getNode(), ROCKET_ELIPSE_BOUND, IDLE_VECTOR);
		if (anim)
			r.addCollision(anim);
		r.getNode()->setMaterialTexture(0, texManager->getRocketTexture()[0]);
		eRockets.push_back(r);
	}
}

array<ISceneNode *> RocketHolder::checkRockets(array<u32> *Findecies, array<u32> *Eindecies)
{
	array<ISceneNode *> nodes;

	u32 count = 0;
	for (auto &i : fRockets)
	{
		if (!i.isDead())
		{
			if (i.checkEnd())
			{
				i.drop();
				i.setHealth(0);
				Findecies->push_back(count);
				continue;
			}

			ISceneNode *buff = i.checkCollision();
			if (buff)
			{
				nodes.push_back(buff);
				i.drop();
				i.setHealth(0);
				Findecies->push_back(count);
			}
		}
		count++;
	}

	count = 0;
	for (auto &i : eRockets)
	{
		if (!i.isDead())
		{
			if (i.checkEnd())
			{
				i.drop();
				i.setHealth(0);
				Eindecies->push_back(count);
				continue;
			}

			ISceneNode *buff = i.checkCollision();
			if (buff)
			{
				nodes.push_back(buff);
				i.drop();
				i.setHealth(0);
				Eindecies->push_back(count);
			}
		}
		count++;
	}

	return nodes;
}

void RocketHolder::fly(f32 delta)
{
	for (auto &i : fRockets)
	{
		if (!i.isDead())
		{
			vector3df pos = i.getPosition();
			pos.X += delta * ROCKET_FIGHTER_SPEED;
			i.setPosition(pos);
		}
	}

	for (auto &i : eRockets)
	{
		if (!i.isDead())
		{
			vector3df pos = i.getPosition();
			pos.X -= delta * ROCKET_ENEMY_SPEED;
			i.setPosition(pos);
		}
	}
}

void RocketHolder::drop()
{
	for (auto &i : fRockets)
		i.drop();

	for (auto &i : eRockets)
		i.drop();

	fRockets.clear();
	eRockets.clear();
}