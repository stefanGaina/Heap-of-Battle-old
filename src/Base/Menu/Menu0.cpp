#include "Menu0.h"

Menu0::Menu0(SDL_Renderer* renderer) : 
	frame(renderer)
{
}

void Menu0::remember(Uint8 actionsLeft, bool hasAttacked)
{
	this->actionsLeft = actionsLeft;
	this->hasAttacked = hasAttacked;
}
