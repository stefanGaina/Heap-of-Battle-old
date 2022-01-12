#pragma once
#include "Language.h"

class Frame
{
public:
	Frame(SDL_Renderer* renderer);
	~Frame(void);

	void draw(Faction turn, State type, bool hasAttacked);

private:
	SDL_Renderer* renderer;
	SDL_Rect destination;

	SDL_Texture* texture;
};
