#pragma once

#include "IrrLicht.h"
#include "GameObject.h"

enum Canon
{
	LEFTCANON,
	RIGHTCANON
};

#define FIGHTER_CANON_MARGIN	16

#define FIGHTER_SPEED			200
#define FIGHTER_FIRE_TIME		400
#define FIGHTER_DAMAGE			10

#define FIGHTER_ROTATION		{ 60.f, 90.f, 0.f }

class Fighter : public GameObject
{

private:

	Canon	canon;

public:

	Fighter();

	Canon		getCanon() const;

	void		setCanon(const Canon newCanon);

	bool		fly(f32 delta);
	vector3df	fire();

};