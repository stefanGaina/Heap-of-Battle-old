#pragma once
#include "Menu0.h"
#include "Icon2.h"
#include "Write2.h"

class Menu2 : public Menu0
{
public:
	Menu2(SDL_Renderer* renderer);

	void draw(Receipt human, Receipt orc, Faction turn);

	void set(State state = State::NEUTRAL, Uint8 actionsLeft = 0, bool hasAttacked = false);

private:
	Icon2 icon;
	Write2 write;
};
