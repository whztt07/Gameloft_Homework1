#include "Enemy.h"

Enemy::Enemy() : GameObject(), type(ENEMY0), ownDamage(DAMAGE0), limits({}), direction(RIGHT)
{
}

Enemy::Enemy(ISceneManager *manager, TextureManager *&texManager, u32 curType, Direction dir, vector3df position, rectf newLimits) : GameObject()
{
	path name = "export/";
	u32 index = 0;
	switch (curType)
	{
	case ENEMY0:
		name += "enemies_01.x";
		type = ENEMY0;
		ownDamage = DAMAGE0;
		index = 0;
		break;
	case ENEMY1:
		name += "enemies_02.x";
		type = ENEMY1;
		ownDamage = DAMAGE1;
		index = 1;
		break;
	case ENEMY2:
		name += "enemies_03.x";
		type = ENEMY2;
		ownDamage = DAMAGE2;
		index = 2;
		break;
	case ENEMY3:
		name += "enemies_04.x";
		type = ENEMY3;
		ownDamage = DAMAGE3;
		index = 3;
		break;
	case ENEMY4:
		name += "enemies_05.x";
		type = ENEMY4;
		ownDamage = DAMAGE4;
		index = 4;
		break;
	}

	this->name = name;
	if (!createNode(manager))
		return;

	limits = newLimits;
	direction = dir;
	node->setPosition(position);
	node->setRotation(ENEMY_ROTATION);
	node->addAnimator(manager->createRotationAnimator(ENEMY_ROTATION_SPEED));
	node->setMaterialTexture(0, texManager->getEnemyTexture()[index]);
}

EnemyType Enemy::getType() const
{
	return type;
}

Damage Enemy::getDamage() const
{
	return ownDamage;
}

rectf Enemy::getLimits() const
{
	return limits;
}

Direction Enemy::getDirection() const
{
	return direction;
}


void Enemy::setType(const EnemyType newType)
{
	type = newType;
}

void Enemy::setDamage(const Damage newDamage)
{
	ownDamage = newDamage;
}

void Enemy::setLimits(rectf newLimits)
{
	limits = newLimits;
}

void Enemy::setDirection(Direction newDirection)
{
	direction = newDirection;
}

void Enemy::moveFromField()
{
	node->removeAnimators();
	animators.clear();
	collisions.clear();
	node->setPosition(ENEMY_OUT_OF_FIELD);
}

bool Enemy::fly(f32 delta)
{
	vector3df pos = node->getPosition();
	if (direction != DOWN)
	{
		switch (direction)
		{
		case LEFT:
			pos.Z -= delta * ENEMY_SPEED;
			break;
		case RIGHT:
			pos.Z += delta * ENEMY_SPEED;
			break;
		}


		if (pos.Z < limits.UpperLeftCorner.X)
		{
			pos.Z = limits.UpperLeftCorner.X;
			direction = RIGHT;
		}
		else if (pos.Z > limits.LowerRightCorner.X)
		{
			pos.Z = limits.LowerRightCorner.X;
			direction = LEFT;
		}
	}
	else
	{
		pos.X -= ENEMY_STEP_SIZE;
		if (pos.X < limits.LowerRightCorner.Y)
			return true;
	}
	node->setPosition(pos);
	return false;
}