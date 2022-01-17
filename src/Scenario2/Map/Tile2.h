#pragma once
#include "Tile0.h"

class Tile2 : private Tile0
{
public:
	Tile2(SDL_Renderer* renderer);
	~Tile2(void);

	void draw(void);

private:
	void loadTextures(void);
	void destroyTextures(void);
	
	SDL_Texture* snow[2];
	SDL_Texture* ice;
	SDL_Texture* iceToSnowRight;
	SDL_Texture* iceToSnowLeft;
	SDL_Texture* iceToSnowUp;
	SDL_Texture* iceToSnowDown;
	SDL_Texture* iceToSnowNW;
	SDL_Texture* iceToSnowNE;
	SDL_Texture* iceToSnowSE;
	SDL_Texture* iceToSnowSW;
};
