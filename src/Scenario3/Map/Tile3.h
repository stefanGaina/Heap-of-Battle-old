#pragma once
#include "Tile0.h"

class Tile3 : private Tile0
{
public:
	Tile3(SDL_Renderer* renderer);
	~Tile3(void);

	void draw(void);

private:
	SDL_Texture* grass[2];

};