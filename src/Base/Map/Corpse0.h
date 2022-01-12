#pragma once
#include "Language.h"

class Corpse0
{
public:
	Corpse0(SDL_Renderer* renderer);
	~Corpse0(void);

	virtual void draw(void) = 0;

protected:
	SDL_Renderer* renderer;
	SDL_Rect destination;
	
	SDL_Texture* texture;
};
