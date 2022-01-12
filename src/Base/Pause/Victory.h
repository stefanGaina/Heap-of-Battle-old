#pragma once
#include "Language.h"

struct Art
{
	Art(SDL_Texture* texture);
	~Art(void);

	SDL_Texture* texture;
};

class Victory
{
public:
	Victory(SDL_Renderer* renderer);

	void draw(void);

	void set(Faction faction);

private:
	SDL_Renderer* renderer;
	SDL_Rect destination;

	Art human, orc;

	Faction faction;
};
