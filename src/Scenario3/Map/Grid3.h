#pragma once
#include "Grid0.h"

class Grid3 : private Grid0
{
public:
	Grid3(SDL_Renderer* renderer);

	void draw(void);

};