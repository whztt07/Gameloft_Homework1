#include "Fighter.h"

Fighter::Fighter() : GameObject(), canon(RIGHTCANON)
{
}

Canon Fighter::getCanon() const
{
	return canon;
}

void Fighter::setCanon(const Canon newCanon)
{
	canon = newCanon;
}

bool Fighter::fly(f32 delta)
{
	vector3df pos = node->getPosition();
	f32 path = FIGHTER_SPEED * delta;
		pos.Z += path;

	node->setPosition(pos);
	return false;
}

vector3df Fighter::fire()
{
	vector3df pos = node->getPosition();
	switch(canon)
	{
	case RIGHTCANON:
		pos.Z += FIGHTER_CANON_MARGIN;
		canon = LEFTCANON;
		break;
			
	case LEFTCANON:
		pos.Z -= FIGHTER_CANON_MARGIN;
		canon = RIGHTCANON;
		break;
	}
	return pos;
}