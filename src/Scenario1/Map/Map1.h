#pragma once
#include "Map0.h"
#include "Tile1.h"
#include "Building1.h"
#include "Corpse1.h"
#include "Grid1.h"

class Map1 : public Map0
{
public:
	Map1(SDL_Renderer* renderer);

	void draw(void);

	Building1 building;

private:
	Tile1 tile;

	Corpse1 corpse;

	Grid1 grid;
};
