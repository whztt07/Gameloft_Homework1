#pragma once

#include "Global.h"
#include "Rocket.h"
#include "TextureManager.h"

#define ROCKET_FIGHTER_SPEED	800
#define ROCKET_ENEMY_SPEED		400

#define ROCKET_ELIPSE_BOUND { 5.f, 5.f, 5.f }

class RocketHolder
{
private:

	list<Rocket> fRockets;
	list<Rocket> eRockets;

public:

	list<Rocket>		getFRockets() const;
	list<Rocket>		getERockets() const;

	void				setFRockets(list<Rocket> rockets);
	void				setERockets(list<Rocket> rockets);

	void				addFighterRocket(ISceneManager *manager, IVideoDriver *video, TextureManager *&texManager, IMetaTriangleSelector *world, vector3df position);	
	void				addEnemyRocket(ISceneManager *manager, IVideoDriver *video, TextureManager *&texManager, ITriangleSelector *world, vector3df position);
	
	array<ISceneNode *>	checkRockets(array<u32> *Findecies, array<u32> *Eindecies);
	void				fly(f32 delta);
	void				drop();
};