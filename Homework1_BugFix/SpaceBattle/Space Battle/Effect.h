#pragma once

#include "Global.h"
#include "RocketHolder.h"

#define EFFECT_TEXTURE_ROTATION			1.570795f
#define EFFECT_TEXTURE_CENTER			{ 0.5f, 0.5f }

#define	EFFECT_FIGHTER_ENGINE_TRANSFORM	-EFFECT_TEXTURE_ROTATION, EFFECT_TEXTURE_CENTER, { 0.125f, 0.135f }, { 0.1f, 0.3f }
#define EFFECT_FIGHTER_ENGINE_SIZE		{ 30, 8 }
#define EFFECT_FIGHTER_ENGINE_MARGIN_X	25
#define EFFECT_FIGHTER_ENGINE_MARGIN_Z	6.5f

#define EFFECT_FIGHTER_CANON_TRANSFORM	-EFFECT_TEXTURE_ROTATION, EFFECT_TEXTURE_CENTER, { 0.5f, 0.06f }, { 0.12f, 0.12f }
#define EFFECT_FIGHTER_CANON_SIZE		{ 12, 12 }
#define EFFECT_FIGHTER_CANON_MARGIN_X	7
#define EFFECT_FIGHTER_CANON_TIME		100
	
#define EFFECT_ROCKET_TRANSFORM_UP		-EFFECT_TEXTURE_ROTATION, EFFECT_TEXTURE_CENTER, { 0.337f, 0.135f }, { 0.1f, 0.3f }
#define EFFECT_ROCKET_TRANSFORM_DOWN	EFFECT_TEXTURE_ROTATION, EFFECT_TEXTURE_CENTER, { 0.44f, 0.53f }, { 0.1f, 0.3f }
#define EFFECT_ROCKET_SIZE				{ 30, 8 }
#define EFFECT_ROCKET_MARGIN_X			15

#define EFFECT_DEATH_SIZE				{ 40, 40 }
#define EFFECT_DEATH_START_POSITION_X	0.516f
#define EFFECT_DEATH_START_POSITION_Y	0.17f
#define EFFECT_DEATH_MARGIN_X			0.1273f
#define EFFECT_DEATH_MARGIN_Y			0.123f
#define EFFECT_DEATH_SCALE				{ 0.1f, 0.1f }
#define EFFECT_DEATH_TIME				100
#define EFFECT_DEATH_FRAMES				10

class Effect
{

private:

	IBillboardSceneNode *fighterEngine[2];
	IBillboardSceneNode *fighterCanon;
	list<IBillboardSceneNode *> rocketUp;
	list<IBillboardSceneNode *> rocketDown;
	list<IBillboardSceneNode *> deathEffect;
	list<u32> deathFrames;

	void deleteEndedDeaths();

public:

	Effect();

	void createEffects(ISceneManager *manager, ITexture *&texture);
	void addRocketUp(ISceneManager *manager, ITexture *&texture, vector3df position);
	void addRocketDown(ISceneManager *manager, ITexture *&texture, vector3df position);
	void deleteRocketUp(array<u32> *indecies);
	void deleteRocketDown(array<u32> *indecies);
	void hideFighterCannon();
	void addDeath(ISceneManager *manager, ITexture *&texture, vector3df position);

	void drawFighterEffects(vector3df position);
	void drawFighterFireEffect(vector3df position);
	void drawRocketUpEffect(f32 delta);
	void drawRocketDownEffect(f32 delta);
	void drawDeathEffect();

	void drop();
};