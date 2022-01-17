#pragma once
#include "Corpse0.h"

class Corpse2 : private Corpse0
{
public:
	Corpse2(SDL_Renderer* renderer);

	void draw(void);
};
