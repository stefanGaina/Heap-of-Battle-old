#pragma once
#include "Frame.h"

class Menu0
{
public:
	Menu0(SDL_Renderer* renderer);

	virtual void draw(Receipt human, Receipt orc, Faction turn) = 0;

protected:
	void remember(Uint8 actionsLeft, bool hasAttacked);

	Frame frame;

	State type;
	Uint8 actionsLeft;
	bool hasAttacked;
};
