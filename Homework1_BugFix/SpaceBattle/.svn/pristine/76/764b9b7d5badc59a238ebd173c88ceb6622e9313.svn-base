#include "EnemyHolder.h"

list<Enemy> EnemyHolder::getEnemyList() const
{
	return enemyList;
}


void EnemyHolder::setEnemyList(list<Enemy> newList)
{
	enemyList = newList;
}


vector3df EnemyHolder::getRandomEnemyPosition() const
{
	vector3df result = IDLE_VECTOR;
	while (result == vector3df(IDLE_VECTOR))
	{
		u32 index = rand() % enemyList.size();
		u32 count = 0;
		for (auto &i : enemyList)
		{
			if (count == index && !i.isDead())
			{
				result = i.getPosition();
				return result;
			}
			count++;
		}
	}
	return result;
}

bool EnemyHolder::createEnemies(ISceneManager *manager, TextureManager *&texManager, rectf limits)
{
	Direction direction = RIGHT;
	for (u32 i = 0; i < ENEMY_COUNT; i++)
	{
		u32 type = rand() % ENEMY_TYPE_COUNT;
		if (i % ENEMY_LINE_COUNT == 0 && i)
			direction = (direction == RIGHT ? LEFT : RIGHT);

		f32 yStep = i % ENEMY_LINE_COUNT;
		if (direction == LEFT)
			yStep++;

		vector3df position = { limits.UpperLeftCorner.Y - (i / ENEMY_LINE_COUNT) * ENEMY_VERTICAL_MARGIN, 0.f, limits.UpperLeftCorner.X + yStep * ENEMY_HOTIZONTAL_MARGIN };
		vector3df end = position;
		vector3df start = position;

		switch (direction)
		{
		case RIGHT:
			end.Z += ENEMY_HOTIZONTAL_MARGIN;
			break;
		case LEFT:
			start.Z -= ENEMY_HOTIZONTAL_MARGIN;
			break;
		}
		end.X = limits.LowerRightCorner.Y;
		rectf path = { start.Z, start.X, end.Z, end.X };

		enemyList.push_back({ manager, texManager, type, direction, position, path });
	}

	return true;
}

IMetaTriangleSelector *EnemyHolder::createSelectors(ISceneManager *manager)
{
	IMetaTriangleSelector *result = manager->createMetaTriangleSelector();
	for (auto &i : enemyList)
		result->addTriangleSelector(i.createTriangleSelector(manager));
	return result;
}

bool EnemyHolder::checkNode(ISceneNode *check, ISceneManager *manager, u32 *score, ISoundEngine *sound, bool soundPlay, vector3df *position)
{
	for (auto &i : enemyList)
	{
		if (check == i.getNode())
		{
			i.damage(i.getDamage());
			(*score) += i.getDamage();
			if (i.isDead())
			{
				if (soundPlay)
				{
					ISound *bang = sound->play2D("sounds/bang.wav", false, true);
					bang->setVolume(0.1f);
					bang->setIsPaused(false);
					bang->drop();
				}
				(*score) += i.getDamage() * 2;
				(*position) = i.getPosition();
				i.moveFromField();
				break;
			}
		}
	}

	for (auto &i : enemyList)
		if (!i.isDead())
			return false;

	return true;
}

void EnemyHolder::fly(f32 delta)
{
	for (auto &i : enemyList)
		if (!i.isDead())
			i.fly(delta);
}

bool EnemyHolder::step()
{
	for (auto &i : enemyList)
	{
		if (!i.isDead())
		{
			Direction temp = i.getDirection();
			i.setDirection(DOWN);
			if (i.fly(0))
				return true;
			i.setDirection(temp);
		}
	}
	return false;
}

void EnemyHolder::drop()
{
	for (auto &i : enemyList)
		i.drop();

	enemyList.clear();
}