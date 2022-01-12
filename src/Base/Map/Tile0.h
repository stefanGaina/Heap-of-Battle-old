#pragma once
#include "Language.h"

class Tile0
{
public:
	Tile0(SDL_Renderer* renderer);

	virtual void draw(void) = 0;

protected:
	SDL_Renderer* renderer;
	SDL_Rect destination;
};
