#pragma once
#include "Corpse0.h"

class Corpse3 : private Corpse0
{
public:
	Corpse3(SDL_Renderer* renderer);

	void draw(void);
};
