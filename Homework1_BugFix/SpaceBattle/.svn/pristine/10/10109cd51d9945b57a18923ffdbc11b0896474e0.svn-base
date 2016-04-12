#include "Effect.h"

Effect::Effect() : fighterCanon(NULL)
{
	fighterEngine[0] = NULL;
	fighterEngine[1] = NULL;
}

void Effect::createEffects(ISceneManager *manager, ITexture *&texture)
{
	fighterEngine[0] = manager->addBillboardSceneNode(0, EFFECT_FIGHTER_ENGINE_SIZE);
	fighterEngine[0]->setMaterialTexture(0, texture);
	fighterEngine[0]->setMaterialFlag(EMF_LIGHTING, false);
	fighterEngine[0]->setMaterialType(EMT_TRANSPARENT_ADD_COLOR);
	fighterEngine[0]->getMaterial(0).getTextureMatrix(0).buildTextureTransform(EFFECT_FIGHTER_ENGINE_TRANSFORM);
	fighterEngine[0]->setVisible(false);

	fighterEngine[1] = manager->addBillboardSceneNode(0, EFFECT_FIGHTER_ENGINE_SIZE);
	fighterEngine[1]->setMaterialTexture(0, texture);
	fighterEngine[1]->setMaterialFlag(EMF_LIGHTING, false);
	fighterEngine[1]->setMaterialType(EMT_TRANSPARENT_ADD_COLOR);
	fighterEngine[1]->getMaterial(0).getTextureMatrix(0).buildTextureTransform(EFFECT_FIGHTER_ENGINE_TRANSFORM);
	fighterEngine[1]->setVisible(false);

	fighterCanon = manager->addBillboardSceneNode(0, EFFECT_FIGHTER_CANON_SIZE);
	fighterCanon->setMaterialTexture(0, texture);
	fighterCanon->setMaterialFlag(EMF_LIGHTING, false);
	fighterCanon->setMaterialType(EMT_TRANSPARENT_ADD_COLOR);
	fighterCanon->getMaterial(0).getTextureMatrix(0).buildTextureTransform(EFFECT_FIGHTER_CANON_TRANSFORM);
	fighterCanon->setVisible(false);
}

void Effect::addRocketUp(ISceneManager *manager, ITexture *&texture, vector3df position)
{
	IBillboardSceneNode *rocket = manager->addBillboardSceneNode(0, EFFECT_ROCKET_SIZE);
	rocket->setMaterialTexture(0, texture);
	rocket->setMaterialFlag(EMF_LIGHTING, false);
	rocket->setMaterialType(EMT_TRANSPARENT_ADD_COLOR);
	rocket->getMaterial(0).getTextureMatrix(0).buildTextureTransform(EFFECT_ROCKET_TRANSFORM_UP);
	rocket->setVisible(false);
	position.X -= EFFECT_ROCKET_MARGIN_X;
	rocket->setPosition(position);

	rocketUp.push_back(rocket);
}

void Effect::addRocketDown(ISceneManager *manager, ITexture *&texture, vector3df position)
{
	IBillboardSceneNode *rocket = manager->addBillboardSceneNode(0, EFFECT_ROCKET_SIZE);
	rocket->setMaterialTexture(0, texture);
	rocket->setMaterialFlag(EMF_LIGHTING, false);
	rocket->setMaterialType(EMT_TRANSPARENT_ADD_COLOR);
	rocket->getMaterial(0).getTextureMatrix(0).buildTextureTransform(EFFECT_ROCKET_TRANSFORM_DOWN);
	rocket->setVisible(false);
	position.X += EFFECT_ROCKET_MARGIN_X;
	rocket->setPosition(position);

	rocketDown.push_back(rocket);
}

void Effect::deleteRocketUp(array<u32> *indecies)
{
	if (indecies->size())
	{
		u32 index = 0;
		u32 step = 0;
		array<u32> &refer = (*indecies);
		for (auto i = rocketUp.begin(); i != rocketUp.end(); i++)
		{
			if (index == refer[step])
			{
				if ((*i))
				{
					(*i)->remove();
					(*i) = NULL;
				}
				step++;
				if (step == indecies->size())
					break;
			}
			index++;
		}
	}
}

void Effect::deleteRocketDown(array<u32> *indecies)
{
	if (indecies->size())
	{
		u32 index = 0;
		u32 step = 0;
		array<u32> &refer = (*indecies);
		for (auto i = rocketDown.begin(); i != rocketDown.end(); i++)
		{
			if (index == refer[step])
			{
				if ((*i))
				{
					(*i)->remove();
					(*i) = NULL;
				}
				step++;
				if (step == indecies->size())
					break;
			}
			index++;
		}
	}
}

void Effect::hideFighterCannon()
{
	if (fighterCanon)
		fighterCanon->setVisible(false);
}

void Effect::drawFighterEffects(vector3df position)
{
	if (!fighterEngine[0]->isVisible())
		fighterEngine[0]->setVisible(true);

	if (!fighterEngine[1]->isVisible())
		fighterEngine[1]->setVisible(true);

	position.X -= EFFECT_FIGHTER_ENGINE_MARGIN_X;
	position.Z -= EFFECT_FIGHTER_ENGINE_MARGIN_Z;
	fighterEngine[0]->setPosition(position);
	position.Z += EFFECT_FIGHTER_ENGINE_MARGIN_Z * 2;
	fighterEngine[1]->setPosition(position);
}

void Effect::addDeath(ISceneManager *manager, ITexture *&texture, vector3df position)
{
	IBillboardSceneNode *death = manager->addBillboardSceneNode(0, EFFECT_DEATH_SIZE);
	death->setMaterialTexture(0, texture);
	death->setMaterialFlag(EMF_LIGHTING, false);
	death->setMaterialType(EMT_TRANSPARENT_ADD_COLOR);
	death->getMaterial(0).getTextureMatrix(0).buildTextureTransform(-EFFECT_TEXTURE_ROTATION, EFFECT_TEXTURE_CENTER, { EFFECT_DEATH_START_POSITION_X, EFFECT_DEATH_START_POSITION_Y }, EFFECT_DEATH_SCALE);
	death->setPosition(position);

	deathEffect.push_back(death);
	deathFrames.push_back(1);
}





void Effect::drawFighterFireEffect(vector3df position)
{
	if (!fighterCanon->isVisible())
		fighterCanon->setVisible(true);
	
	position.X += EFFECT_FIGHTER_CANON_MARGIN_X;
	fighterCanon->setPosition(position);
}

void Effect::drawRocketUpEffect(f32 delta)
{
	for (auto &i : rocketUp)
	{
		if (i)
		{
			if (!i->isVisible())
				i->setVisible(true);
			vector3df pos = i->getPosition();
			pos.X += delta * ROCKET_FIGHTER_SPEED;
			i->setPosition(pos);
		}
	}
}

void Effect::drawRocketDownEffect(f32 delta)
{
	for (auto &i : rocketDown)
	{
		if (i)
		{
			if (!i->isVisible())
				i->setVisible(true);
			vector3df pos = i->getPosition();
			pos.X -= delta * ROCKET_ENEMY_SPEED;
			i->setPosition(pos);
		}
	}
}

void Effect::drawDeathEffect()
{
	auto iter = deathFrames.begin();
	for (auto &i : deathEffect)
	{
		u32 x = (*iter) % 5;
		u32 y = (*iter) / 5;
		i->getMaterial(0).getTextureMatrix(0).buildTextureTransform(-EFFECT_TEXTURE_ROTATION, EFFECT_TEXTURE_CENTER, { EFFECT_DEATH_START_POSITION_X + EFFECT_DEATH_MARGIN_X * x, EFFECT_DEATH_START_POSITION_Y + EFFECT_DEATH_MARGIN_Y * y}, EFFECT_DEATH_SCALE);
		(*iter)++;
		iter++;
	}

	deleteEndedDeaths();
}

void Effect::deleteEndedDeaths()
{
	auto iter = deathFrames.begin();
	for (auto i = deathEffect.begin(); i != deathEffect.end(); i++)
	{
		if ((*iter) > EFFECT_DEATH_FRAMES)
		{
			if ((*i))
			{
				(*i)->remove();
				(*i) = NULL;
			}
			iter = deathFrames.erase(iter);
			i = deathEffect.erase(i);
			if (i == deathEffect.end() || iter == deathFrames.end())
				break;
		}
	}
}

void Effect::drop()
{
	if (fighterEngine[0])
	{
		fighterEngine[0]->remove();
		fighterEngine[0] = NULL;
	}

	if (fighterEngine[1])
	{
		fighterEngine[1]->remove();
		fighterEngine[1] = NULL;
	}

	if (fighterCanon)
	{
		fighterCanon->remove();
		fighterCanon = NULL;
	}

	for (auto &i : rocketUp)
	{
		if (i)
		{
			i->remove();
			i = NULL;
		}
	}
	rocketUp.clear();

	for (auto &i : rocketDown)
	{
		if (i)
		{
			i->remove();
			i = NULL;
		}
	}
	rocketDown.clear();

	for (auto &i : deathEffect)
	{
		if (i)
		{
			i->remove();
			i = NULL;
		}
	}
	deathEffect.clear();

	deathFrames.clear();
}