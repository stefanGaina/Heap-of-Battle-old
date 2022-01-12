#pragma once
#include "Write.h"
#include "Frame.h"
#include "Icon.h"

class Menu0
{
public:
	Menu0(SDL_Renderer* renderer);

	void draw(Receipt human, Receipt orc, Faction turn);
	void set(State type = State::NEUTRAL, Uint8 actionsLeft = 0, bool hasAttacked = false, bool vampState = false);

private:
	State type;
	Uint8 actionsLeft;
	bool hasAttacked;

	Write write;

	Frame frame;

	Icon icon;
};
