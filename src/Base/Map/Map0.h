#pragma once
#include "Border.h"

class Map0
{
public:
	Map0(SDL_Renderer* renderer);

	virtual void draw(void) = 0;

	Border border;
};
