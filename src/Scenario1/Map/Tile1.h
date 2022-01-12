#pragma once
#include "Tile0.h"

struct RiverBank
{
	SDL_Texture* left[2], * right[2];
};

class Tile1 : public Tile0
{
public:
	Tile1(SDL_Renderer* renderer);
	~Tile1(void);
	
	void draw(void);

private:
	void loadTextures(void);
	void destroyTextures(void);

	RiverBank riverBank;
	SDL_Texture* dirt[4], * water[2];
};
