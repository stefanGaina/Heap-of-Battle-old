#include "Menu0.h"

Menu0::Menu0(SDL_Renderer* renderer) : write(renderer), frame(renderer), icon(renderer)
{
}

void Menu0::draw(Receipt human, Receipt orc, Faction turn)
{
	frame.draw(turn, type, hasAttacked);
	icon.draw(turn, type, hasAttacked);
	write.draw(turn, type, human, orc, actionsLeft);
}

void Menu0::set(State type, Uint8 actionsLeft, bool hasAttacked, bool vampState)
{
	this->type = type;
	this->actionsLeft = actionsLeft;
	this->hasAttacked = hasAttacked;
}
