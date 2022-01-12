#pragma once
#include "Language.h"

class Building0
{
public:
	Building0(SDL_Renderer* renderer);

	virtual void draw(void) = 0;

protected:
	SDL_Renderer* renderer;
};
