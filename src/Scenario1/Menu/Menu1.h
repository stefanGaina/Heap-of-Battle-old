#pragma once
#include "Menu0.h"
#include "Icon1.h"
#include "Write1.h"

struct Vamped
{
	bool vamped;
};

class Menu1 : public Menu0
{
public:
	Menu1(SDL_Renderer* renderer);

	void draw(Receipt human, Receipt orc, Faction turn);

	void set(State state = State::NEUTRAL, Uint8 actionsLeft = 0, bool hasAttacked = false, bool vampState = false);

private:
	Icon1 icon;
	Write1 write;

	Vamped human, orc;
};
