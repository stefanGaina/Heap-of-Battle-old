#pragma once
#include "TileInfo.h"
#include "AnimationTexture.h"
#include "Queue.h"

class Animation : private AnimationTexture
{
public:
	Animation(TileInfo* tile, SDL_Renderer* renderer);

	void draw(void);
	void set(Queue* queue);

	bool get(void);

private:
	SDL_Rect destination;

	Textures* unit;
	SDL_Texture** death;
	SDL_Texture* toAnimate;

	TileInfo* tile;

	Transport current;

	Sint8 distance;

	bool animating;
};
