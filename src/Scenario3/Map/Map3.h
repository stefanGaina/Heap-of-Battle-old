#pragma once
#include "Map0.h"
#include "Tile3.h"
#include "Building3.h"
#include "Corpse3.h"
#include "Grid3.h"

class Map3 : public Map0
{
public:
	Map3(SDL_Renderer* renderer);

	void draw(void);

	Building3 building;

private:
	Tile3 tile;

	Corpse3 corpse;

	Grid3 grid;
};
