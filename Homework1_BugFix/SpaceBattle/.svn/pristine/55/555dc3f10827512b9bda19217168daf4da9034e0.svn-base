#include "Rocket.h"

Rocket::Rocket() : GameObject(), path()
{
}

line3df Rocket::getPath() const
{
	return path;
}


void Rocket::setPath(const line3df newPath)
{
	path = newPath;
}


bool Rocket::createRocket(ISceneManager *manager, IVideoDriver *video, vector3df position, Direction direction)
{
	vector3df end = position;
	switch(direction)
	{
	case UP:
		end.X = ROCKET_END_PATH;
		break;
	case DOWN:
		end.X = -ROCKET_END_PATH;
		break;
	}
	path = line3df(position, end);
	
	name = "export/rocket.x";
	createNode(manager);
	
	vector3df rotation;
	switch(direction)
	{
	case UP:
		rotation = ROCKET_ROTATION_UP;
		break;
	case DOWN:
		rotation = ROCKET_ROTATION_DONW;
		break;
	}
	node->setRotation(rotation);
	node->setPosition(position);
	health = MAX_HEALTH;

	return true;
}

ISceneNode *Rocket::checkCollision()
{
	vector3df pos = node->getPosition();
	if (pos.X > path.start.X && pos.X >= path.end.X)
		health = 0;

	else if (pos.X < path.start.X && pos.X <= path.end.X)
		health = 0;
	
	if (isDead())
		return NULL;
	
	for (auto i : collisions)
	{
		if (i->collisionOccurred())
		{
			health = 0;
			return (i->getCollisionNode());
		}
	}

	return NULL;
}

bool Rocket::checkEnd() const
{
	if (node->getPosition().X > path.start.X && node->getPosition().X >= path.end.X)
		return true;
	if (node->getPosition().X < path.start.X && node->getPosition().X <= path.end.X)
		return true;
	return false;
}