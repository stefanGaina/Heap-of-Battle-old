#pragma once
#include "Map0.h"
#include "Tile2.h"
#include "Building2.h"
#include "Corpse2.h"
#include "Grid2.h"

class Map2 : public Map0
{
public:
	Map2(SDL_Renderer* renderer);

	void draw(void);
	
	Building2 building;

private:
	Tile2 tile;

	Corpse2 corpse;

	Grid2 grid;
};
