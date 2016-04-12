#include "TextureManager.h"

TextureManager::TextureManager() : fighterTex(NULL), enemyTex(NULL), rocketTex(NULL), effectsTex(NULL), buttonsTex(NULL)
{
}

ITexture **TextureManager::getFighterTexture() const
{
	return fighterTex;
}

ITexture **TextureManager::getEnemyTexture() const
{
	return enemyTex;
}

ITexture **TextureManager::getRocketTexture() const
{
	return rocketTex;
}

ITexture **TextureManager::getEffectsTexture() const
{
	return effectsTex;
}

ITexture **TextureManager::getButtonsTexture() const
{
	return buttonsTex;
}


void TextureManager::setFighterTexture(ITexture **texture)
{
	fighterTex = texture;
}

void TextureManager::setEnemyTexture(ITexture **texture)
{
	enemyTex = texture;
}

void TextureManager::setRocketTexture(ITexture **texture)
{
	rocketTex = texture;
}

void TextureManager::setEffectsTexture(ITexture **texture)
{
	effectsTex = texture;
}

void TextureManager::setButtonsTexture(ITexture **texture)
{
	buttonsTex = texture;
}


void TextureManager::loadTextures(IVideoDriver *video)
{
	path name = TEXTURE_PATH;
	fighterTex = new ITexture *;
	fighterTex[0] = video->getTexture(name + FIGHTER_NAME);

	enemyTex = new ITexture *[ENEMY_TEXTURES_COUNT];
	enemyTex[0] = video->getTexture(name + ENEMY01_NAME);
	enemyTex[1] = video->getTexture(name + ENEMY02_NAME);
	enemyTex[2] = video->getTexture(name + ENEMY03_NAME);
	enemyTex[3] = video->getTexture(name + ENEMY04_NAME);

	rocketTex = new ITexture *;
	rocketTex[0] = video->getTexture(name + ROCKET_NAME);
	
	effectsTex = new ITexture *;
	effectsTex[0] = video->getTexture(name + EFFECT_NAME);
	video->makeColorKeyTexture(effectsTex[0], { 0, 0, 0, 0 });

	buttonsTex = new ITexture *[BUTTON_TEXTURES_COUNT];
	buttonsTex[0] = video->getTexture(name + BUTTON_START_NAME);
	buttonsTex[1] = video->getTexture(name + BUTTON_OPTIONS_NAME);
	buttonsTex[2] = video->getTexture(name + BUTTON_BACK_NAME);
	buttonsTex[3] = video->getTexture(name + BUTTON_QUIT_NAME);
}

void TextureManager::drop()
{
	if (fighterTex)
	{
		if (fighterTex[0])
			fighterTex[0] = NULL;
		delete fighterTex;
	}

	if (enemyTex)
	{
		for (u32 i = 0; i < ENEMY_TEXTURES_COUNT; i++)
		{
			if (enemyTex[i])
				enemyTex[i] = NULL;
		}
		delete enemyTex;
	}

	if (rocketTex)
	{
		if (rocketTex[0])
			rocketTex[0] = NULL;
		delete rocketTex;
	}

	if (effectsTex)
	{
		if (effectsTex[0])
			effectsTex[0] = NULL;
		delete effectsTex;
	}

	if (buttonsTex)
	{
		for (u32 i = 0; i < BUTTON_TEXTURES_COUNT; i++)
		{
			if (buttonsTex[i])
				buttonsTex[i] = NULL;
		}
		delete buttonsTex;
	}
}