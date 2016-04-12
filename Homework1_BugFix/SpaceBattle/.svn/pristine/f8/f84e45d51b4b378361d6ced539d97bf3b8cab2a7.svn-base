#pragma once

#include "Global.h"
#include "GameObject.h"

#define ROCKET_END_PATH					250

#define ROCKET_ROTATION_UP				{ 0.f, 0.f, -90.f }
#define ROCKET_ROTATION_DONW			{ 0.f, 0.f, 90.f }

class Rocket : public GameObject
{

private:

	line3df						path;

public:

	Rocket();

	line3df						getPath() const;

	void						setPath(const line3df newPath);

	bool						createRocket(ISceneManager *manager, IVideoDriver *video, vector3df position, Direction direction);

	ISceneNode					*checkCollision();
	bool						checkEnd() const;

};