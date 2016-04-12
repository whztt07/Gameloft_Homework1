#include "Game.h"

Game::Game() : 
enemyField(ENEMY_FIELD_SIZE),
	fighterLine(line3df(FIGHTER_LINE_SIZE)), 
	enemies(new EnemyHolder()), 
	fighter(new Fighter()), 
	rockets(new RocketHolder()), 
	gui(new GUI()),
	effects(new Effect()),
	texManager(new TextureManager()),
	engine(new Irrlicht(L"Space Battle", dimension2du(WINDOW_WIDTH, WINDOW_HEIGHT))), 
	state(MENU), 
	sound(createIrrKlangDevice()), 
	score(0), 
	soundPlay(true)
{
	srand(time(NULL));
}

void Game::toLevel(bool pause)
{
	engine->hideCursor(true);
	engine->setCursorToCenter();
	engine->resetInput();

	if (!pause)
	{
		drop();
		if (!addFighter())
			exit(1);
		if (!addEnemies())
			exit(1);

		effects->createEffects(engine->getManager(), texManager->getEffectsTexture()[0]);
		timer.zeroTimes();
		engine->setTime(0);
	}
	gui->game(engine->getGUI(), texManager);
}

bool Game::addFighter()
{
	fighter->setName("export/fighter.x");
	bool result = fighter->createNode(engine->getManager());
	if (result)
	{
		fighter->setPosition(fighterLine.getMiddle());
		fighter->setRotation(FIGHTER_ROTATION);
		fighter->setHealth(MAX_HEALTH);
	}
	fighter->getNode()->setMaterialTexture(0, texManager->getFighterTexture()[0]);
	return result;
}

void Game::applyFighterMoves()
{
	vector3df initPos = fighter->getPosition();

	// Keyboard moves
	if (engine->isKeyPressed(KEY_LEFT))
		fighter->fly(-timer.delta);
	else if (engine->isKeyPressed(KEY_RIGHT))
		fighter->fly(timer.delta);

	// Mouse moves
	dimension2du center = engine->getCenter();
	vector2di mouse = engine->getCursorPosition();
	if (center.Width != mouse.X)
	{
		f32 move = (f32)(mouse.X - (s32)center.Width);
		fighter->fly(timer.delta * move);
		engine->setCursorPosition(center);
	}

	vector3df pos = fighter->getPosition();
	if (pos != initPos)
	{
		// Checking for bound
		if (pos.Z < fighterLine.start.Z)
			pos.Z = fighterLine.start.Z;
		else if (pos.Z > fighterLine.end.Z)
			pos.Z = fighterLine.end.Z;

		fighter->setPosition(pos);
	}
	effects->drawFighterEffects(pos);

	// Fire
	if ((engine->isKeyPressed(KEY_SPACE) || engine->isLeftMouseButtonPressed()) && (timer.now - timer.lastFire) >= FIGHTER_FIRE_TIME)
	{
		vector3df rPos = fighter->fire();
		rockets->addFighterRocket(engine->getManager(), engine->getVideo(), texManager, enemies->createSelectors(engine->getManager()), rPos);
		effects->addRocketUp(engine->getManager(), texManager->getEffectsTexture()[0], rPos);
		effects->drawFighterFireEffect(rPos);
		timer.lastFire = timer.now;
	}

	if ((timer.now - timer.lastFire) >= EFFECT_FIGHTER_CANON_TIME)
		effects->hideFighterCannon();
}

bool Game::addEnemies()
{
	return enemies->createEnemies(engine->getManager(), texManager, enemyField);
}

void Game::applyEnemiesMoves()
{
	// Flying sideway
	enemies->fly(timer.delta);

	// Flying down
	if((timer.now - timer.lastStep) >= ENEMY_STEP_TIME)
	{
		if (enemies->step())
		{
			state = OVER;
			engine->hideCursor(false);
			gui->lose(engine->getGUI(), texManager);
		}

		timer.lastStep = timer.now;
	}

	// Random enemy fires
	if((timer.now - timer.lastEnemyFire) >= ENEMY_FIRE_TIME)
	{
		vector3df rPos = enemies->getRandomEnemyPosition();
		rockets->addEnemyRocket(engine->getManager(), engine->getVideo(), texManager, fighter->createTriangleSelector(engine->getManager()), rPos);
		effects->addRocketDown(engine->getManager(), texManager->getEffectsTexture()[0], rPos);
		timer.lastEnemyFire = timer.now;
	}
}

void Game::applyRocketsMoves()
{
	// Fly thier ways
	rockets->fly(timer.delta);
	effects->drawRocketUpEffect(timer.delta);
	effects->drawRocketDownEffect(timer.delta);
	
	// Getting all nodes rockets hited & indecies for rockets
	array<u32> *Findecies, *Eindecies;
	Findecies = new array<u32>();
	Eindecies = new array<u32>();
	array<ISceneNode *> nodes = rockets->checkRockets(Findecies, Eindecies);
	effects->deleteRocketUp(Findecies);
	effects->deleteRocketDown(Eindecies);

	for (u32 i = 0; i < nodes.size(); i++)
	{
		vector3df pos = IDLE_VECTOR;

		// Checking fot fighter damage and death
		if (nodes[i] == fighter->getNode())
		{
			fighter->damage(FIGHTER_DAMAGE);
			if (fighter->isDead())
			{
				if (soundPlay)
				{
					ISound *bang = sound->play2D("sounds/bang.wav", false, true);
					bang->setVolume(0.1f);
					bang->setIsPaused(false);
					bang->drop();
				}
				state = OVER;
				engine->hideCursor(false);
				drop();
				gui->lose(engine->getGUI(), texManager);
				return;
			}
		}

		// Checking for enemies damage and death
		else if (enemies->checkNode(nodes[i], engine->getManager(), &score, sound, soundPlay, &pos))
		{
			state = OVER;
			engine->hideCursor(false);
			drop();
			gui->win(engine->getGUI(), texManager);
			return;
		}

		if (pos != vector3df(IDLE_VECTOR))
			effects->addDeath(engine->getManager(), texManager->getEffectsTexture()[0], pos);
	}

	// Refrashing score and health
	gui->setScore(score);
	if (!fighter->isDead())
		gui->setHealth(fighter->getHealth());
}

void Game::applyEffects()
{
	if (timer.now - timer.lastFrame >= EFFECT_DEATH_TIME)
	{
		effects->drawDeathEffect();
		timer.lastFrame = timer.now;
	}
}

void Game::menu()
{
	switch (state)
	{
	case MENU:
		if (gui->isButtonPressed(START_BUTTON))
		{
			state = INGAME;
			toLevel(false);
		}
		else if (gui->isButtonPressed(OPTIONS_BUTTON))
		{
			state = OPTIONS;
			gui->options(engine->getGUI(), texManager);
		}
		else if (gui->isButtonPressed(QUIT_BUTTON))
			state = EXIT;
		break;

	case OPTIONS:
		if (gui->isButtonPressed(BACK_BUTTON))
		{
			state = MENU;
			gui->menu(engine->getGUI(), texManager);
		}

		else if (gui->getMusicSelection() == MUSIC_ENABLE)
		{
			if (gameMusic->getIsPaused())
				gameMusic = sound->play2D("sounds/game.mp3", true, false, true);
		}

		else if (gui->getMusicSelection() == MUSIC_DISABLE)
			gameMusic->setIsPaused(true);

		if (gui->getSoundSelection() == SOUND_ENABLE)
			soundPlay = true;

		else if (gui->getSoundSelection() == SOUND_DISABLE)
			soundPlay = false;
		break;

	case PAUSE:
		if (gui->isButtonPressed(BACK_BUTTON))
		{
			state = MENU;
			drop();
			engine->hideCursor(false);
			gui->menu(engine->getGUI(), texManager);
		}

		else if (gui->isButtonPressed(RESUME_BUTTON))
		{
			state = INGAME;
			u32 delta = engine->getNow() - timer.pauseTime;
			timer.addDelta(delta);
			toLevel(true);
		}

		else if (gui->isButtonPressed(QUIT_BUTTON))
			state = EXIT;
		break;

	case OVER:
		timer.totalTime = engine->getNow();
		score -= timer.totalTime / 2;

		if (gui->isButtonPressed(START_BUTTON))
		{
			state = INGAME;
			toLevel(false);
		}
		else if (gui->isButtonPressed(BACK_BUTTON))
		{
			state = MENU;
			drop();
			engine->hideCursor(false);
			gui->menu(engine->getGUI(), texManager);
		}
		else if (gui->isButtonPressed(QUIT_BUTTON))
			state = EXIT;
		break;
	}
}

void Game::game()
{
	// Counting time since last frame
	timer.now = engine->getNow();
	timer.delta = (f32)(timer.now - timer.lastTime) / 1000.f;
	timer.lastTime = timer.now;

	// Apply game objects moves
	applyFighterMoves();
	applyEnemiesMoves();
	applyRocketsMoves();
	applyEffects();

	if (engine->isKeyPressed(KEY_ESCAPE))
	{
		state = PAUSE;
		timer.pauseTime = engine->getNow();
		gui->pause(engine->getGUI(), texManager);
		engine->hideCursor(false);
	}
}


void Game::drop()
{
	fighter->drop();
	enemies->drop();
	rockets->drop();
	effects->drop();
}

void Game::loop()
{
	// Creating background
	ISceneNode *skybox = engine->getSkyBox("textures/background.tga");
	skybox->setRotation(SCENE_SKYBOX_ROTATION);
	skybox->setScale(SCENE_SKYBOX_SCALE);

	// Textures
	texManager->loadTextures(engine->getVideo());

	// Light
	ILightSceneNode *light = engine->getManager()->addLightSceneNode(0, LIGHT_POSITION, WHITE_COLOR, LIGHT_RADIUS);

	// Menu
	gui->menu(engine->getGUI(), texManager);

	// Music
	gameMusic = sound->play2D("sounds/game.mp3", true, false, true);

	bool exitFlag = false;

	while (engine->run())
	{
		switch (state)
		{
		case MENU:
		case OPTIONS:
		case PAUSE:
		case OVER:
			menu();
			break;

		case INGAME:
			game();
			break;

		case EXIT:
			exitFlag = true;
			break;
		}

		if (exitFlag)
			break;

		engine->drawAll();
	}

	texManager->drop();
	engine->drop();
	sound->drop();
}