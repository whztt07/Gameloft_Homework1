#pragma once

#include "IrrLicht.h"
#include "Irrklang.h"
#include "Fighter.h"
#include "EnemyHolder.h"
#include "RocketHolder.h"
#include "Timer.h"
#include "Gui.h"
#include "Effect.h"
#include "TextureManager.h"
#include <time.h>

enum State
{
	MENU,
	OPTIONS,
	INGAME,
	PAUSE,
	OVER,
	EXIT
};

#define ENEMY_FIELD_SIZE	{ -250.f, 180.f, 250.f, -160.f }
#define FIGHTER_LINE_SIZE	{ -180.f, 0.f, -250.f, -180.f, 0.f, 250.f }

#define SCENE_SKYBOX_ROTATION	{ 0.f, 180.f, 0.f }
#define SCENE_SKYBOX_SCALE		{ 0.8f, 1.f, 1.f }

class Game
{
private:

	Irrlicht		*engine;
	ISoundEngine	*sound;
	
	Fighter			*fighter;
	EnemyHolder		*enemies;
	RocketHolder	*rockets;
	GUI				*gui;
	Effect			*effects;
	ISound			*gameMusic;
	TextureManager	*texManager;

	rectf			enemyField;
	line3df			fighterLine;

	State			state;
	Time			timer;

	u32				score;
	bool			soundPlay;

	void toLevel(bool pause);

	void menu();
	void game();

	bool addFighter();
	bool addEnemies();

	void applyEnemiesMoves();
	void applyFighterMoves();
	void applyRocketsMoves();
	void applyEffects();

	void drop();

public:

	Game();
	void loop();

};