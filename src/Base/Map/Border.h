#pragma once
#include "Language.h"

struct Corner
{
	SDL_Texture* NorthWest, * NorthEast, * SouthEast, * SouthWest;
};

struct Wall
{
	Corner corner;
	SDL_Texture* vertical[2], * horizontal[2];
};

struct Stone
{
	Wall wall;
	SDL_Texture* stone[2];
};

class Border
{
public:
	Border(SDL_Renderer* renderer);
	~Border(void);

	void draw(void);
	void change(void);

private:
	void loadTextures(void);
	void destroyTextures(void);

	SDL_Renderer* renderer;

	SDL_Rect destination;
	
	Stone* current, human, orc;
};
