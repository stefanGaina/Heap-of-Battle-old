#include "Map1.h"
#include "TextureManager.h"

Map1::Map1(SDL_Renderer* renderer) : Map0(renderer), tile(renderer), building(renderer), corpse(renderer), grid(renderer)
{
}

void Map1::draw(void)
{
	border.draw();
	tile.draw();
	building.draw();
	corpse.draw();
	grid.draw();
}
