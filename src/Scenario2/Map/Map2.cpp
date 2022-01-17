#include "Map2.h"

Map2::Map2(SDL_Renderer* renderer) : 
	Map0(renderer), tile(renderer), building(renderer), corpse(renderer), grid(renderer)
{
}

void Map2::draw(void)
{
	border.draw();
	tile.draw();
	building.draw();
	corpse.draw();
	grid.draw();
}
