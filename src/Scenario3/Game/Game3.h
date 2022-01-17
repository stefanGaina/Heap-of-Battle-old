#pragma once
#include "Game0.h"
#include "Map3.h"
#include "Sound3.h"

class Game3 : public Game0
{
public:
	Game3(SDL_Renderer* renderer, const Mouse& mouse);

	void render(void);
	void handleEvents(void);

private:
	Map3 map;
	Sound3 sound;
};
