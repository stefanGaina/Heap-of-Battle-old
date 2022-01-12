#pragma once
#include "Language.h"

class Grid0
{
public:
	Grid0(SDL_Renderer* renderer);

	virtual void draw(void) = 0;

protected:
	SDL_Renderer* renderer;
};
