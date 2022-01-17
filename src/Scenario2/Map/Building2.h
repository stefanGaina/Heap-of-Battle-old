#pragma once
#include "Building0.h"

struct plm
{
	SDL_Texture* barrack;
	SDL_Texture* factory;
};

struct Mine
{
	SDL_Texture* active, * passive, * current;
};

class Building2 : private Building0
{
public:
	Building2(SDL_Renderer* renderer);
	~Building2(void);

	void draw(void);

private:
	void loadTextures(void);
	void destroyTextures(void);

	SDL_Rect destination, destination3x3;

	SDL_Texture* laboratory;
	SDL_Texture* portal;

	Mine mine;

	plm human, orc;
};
