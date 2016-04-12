#pragma once

#include "Global.h"
#include "TextureManager.h"
#include <string>

#define START_BUTTON			101
#define RESUME_BUTTON			102
#define BACK_BUTTON				103
#define QUIT_BUTTON				104
#define OPTIONS_BUTTON			105

#define MUSIC_ENABLE			201
#define MUSIC_DISABLE			202
#define SOUND_ENABLE			203
#define SOUND_DISABLE			204
#define UNKNOWN					-1

#define BUTTON_WIDTH			170
#define BUTTON_HEIGHT			45
#define BUTTON_MARGIN			30

#define COMBOBOX_WIDTH			100
#define COMBOBOX_HEIGHT			20
#define COMBOBOX_MARGIN			20

#define SCORE_HEALTH_WIDTH		60
#define SCORE_HEALTH_HEIGHT		10
#define TEXT_MARGIN				10

#define SCORE_POSITION_H		944
#define SCORE_POSITION_V		40	

#define HEALTH_POSITION_H		944
#define HEALTH_POSITION_V		60

#define TRIPLE_BUTTON_START_V	299
#define TRIPLE_BUTTON_START_H	437
#define SINGLE_BUTTON_START_H	227

#define WHITE_COLOR				{255, 255, 255, 255}

class GUI
{

private:

	list<IGUIButton *>	buttons;
	IGUIStaticText		*score;
	IGUIStaticText		*health;
	IGUIStaticText		*result;
	IGUIComboBox		*musicBox;
	IGUIComboBox		*soundBox;

	void addButton(IGUIEnvironment *gui, ITexture *&texture, path name, const recti size, u32 btn);

public:

	GUI();

	void	setScore(const u32 score);
	void	setHealth(const s32 health);

	bool	isButtonPressed(u32 id) const;
	s32		getMusicSelection() const;
	s32		getSoundSelection() const;

	void	menu(IGUIEnvironment *gui, TextureManager *&manager);
	void	options(IGUIEnvironment *gui, TextureManager *&manager);
	void	pause(IGUIEnvironment *gui, TextureManager *&manager);
	void	game(IGUIEnvironment *gui, TextureManager *&manager);
	void	win(IGUIEnvironment *gui, TextureManager *&manager);
	void	lose(IGUIEnvironment *gui, TextureManager *&manager);

	void	drop(bool fScore = false, bool fHealth = false);

};