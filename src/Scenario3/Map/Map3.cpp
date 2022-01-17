#include "Map3.h"

Map3::Map3(SDL_Renderer* renderer) :
	Map0(renderer), tile(renderer), building(renderer), corpse(renderer), grid(renderer)
{
}

void Map3::draw(void)
{
	border.draw();
	tile.draw();
	building.draw();
	corpse.draw();
	grid.draw();
}
