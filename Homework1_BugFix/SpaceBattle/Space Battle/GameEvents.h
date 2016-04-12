#pragma once

//#include "IrrLicht.h"
#include "Global.h"

struct MouseState
{
	position2di Position;
	bool		LButtonDown;
};

class GameEvents : public IEventReceiver
{
private:
	bool		keys[KEY_KEY_CODES_COUNT];
	position2di	mousePosition;
	bool		leftButtonPressed;

public:

	GameEvents();

	bool		OnEvent(const SEvent &event);
	bool		isKeyDown(EKEY_CODE key) const;
	position2di	getMousePosition() const;
	bool		isLeftButtonPressed() const;
	void		setMousePosition(vector3df position);
	void		zeroMouse();

};