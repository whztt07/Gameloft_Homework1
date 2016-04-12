#pragma once;

#include "Global.h"

#define TEXTURE_PATH			"textures/"
#define FIGHTER_NAME			"fighter.tga"
#define ENEMY01_NAME			"enemies_01.tga"
#define ENEMY02_NAME			"enemies_02.tga"
#define ENEMY03_NAME			"enemies_03.tga"
#define ENEMY04_NAME			"enemies_04.tga"
#define ENEMY05_NAME			"enemies_05.tga"
#define ROCKET_NAME				"rocket.tga"
#define EFFECT_NAME				"particle_atlas_additive.tga"
#define BUTTON_START_NAME		"Start.png"
#define BUTTON_OPTIONS_NAME		"Options.png"
#define BUTTON_BACK_NAME		"Back.png"
#define BUTTON_QUIT_NAME		"Quit.png"

#define ENEMY_TEXTURES_COUNT	5
#define BUTTON_TEXTURES_COUNT	4


class TextureManager
{

private:

	ITexture **fighterTex;
	ITexture **enemyTex;
	ITexture **rocketTex;
	ITexture **effectsTex;
	ITexture **buttonsTex;

public:


	TextureManager();

	ITexture **getFighterTexture() const;
	ITexture **getEnemyTexture() const;
	ITexture **getRocketTexture() const;
	ITexture **getEffectsTexture() const;
	ITexture **getButtonsTexture() const;

	void setFighterTexture(ITexture **texture);
	void setEnemyTexture(ITexture **texture);
	void setRocketTexture(ITexture **texture);
	void setEffectsTexture(ITexture **texture);
	void setButtonsTexture(ITexture **texture);

	void loadTextures(IVideoDriver *video);

	void drop();

};