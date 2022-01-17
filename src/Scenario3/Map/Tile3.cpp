#include "Tile3.h"
#include "TextureManager.h"

enum Tiles
{
	G0 = 1,
};

static Uint8 currentMap[ROW - 2][COLUMN - 8] =
{
	{G0  , G0  , G0  , G0  , G0  , G0  , G0  , G0  , G0  , G0  , G0  , G0  , G0  , G0  , G0  , G0  , G0},
	{G0  , G0  , G0  , G0  , G0  , G0  , G0  , G0  , G0  , G0  , G0  , G0  , G0  , G0  , G0  , G0  , G0},
	{G0  , G0  , G0  , G0  , G0  , G0  , G0  , G0  , G0  , G0  , G0  , G0  , G0  , G0  , G0  , G0  , G0},
	{G0  , G0  , G0  , G0  , G0  , G0  , G0  , G0  , G0  , G0  , G0  , G0  , G0  , G0  , G0  , G0  , G0},
	{G0  , G0  , G0  , G0  , G0  , G0  , G0  , G0  , G0  , G0  , G0  , G0  , G0  , G0  , G0  , G0  , G0},
	{G0  , G0  , G0  , G0  , G0  , G0  , G0  , G0  , G0  , G0  , G0  , G0  , G0  , G0  , G0  , G0  , G0},
	{G0  , G0  , G0  , G0  , G0  , G0  , G0  , G0  , G0  , G0  , G0  , G0  , G0  , G0  , G0  , G0  , G0},
	{G0  , G0  , G0  , G0  , G0  , G0  , G0  , G0  , G0  , G0  , G0  , G0  , G0  , G0  , G0  , G0  , G0},
	{G0  , G0  , G0  , G0  , G0  , G0  , G0  , G0  , G0  , G0  , G0  , G0  , G0  , G0  , G0  , G0  , G0},
	{G0  , G0  , G0  , G0  , G0  , G0  , G0  , G0  , G0  , G0  , G0  , G0  , G0  , G0  , G0  , G0  , G0},
	{G0  , G0  , G0  , G0  , G0  , G0  , G0  , G0  , G0  , G0  , G0  , G0  , G0  , G0  , G0  , G0  , G0},
	{G0  , G0  , G0  , G0  , G0  , G0  , G0  , G0  , G0  , G0  , G0  , G0  , G0  , G0  , G0  , G0  , G0},
	{G0  , G0  , G0  , G0  , G0  , G0  , G0  , G0  , G0  , G0  , G0  , G0  , G0  , G0  , G0  , G0  , G0},
	{G0  , G0  , G0  , G0  , G0  , G0  , G0  , G0  , G0  , G0  , G0  , G0  , G0  , G0  , G0  , G0  , G0},
	{G0  , G0  , G0  , G0  , G0  , G0  , G0  , G0  , G0  , G0  , G0  , G0  , G0  , G0  , G0  , G0  , G0},
	{G0  , G0  , G0  , G0  , G0  , G0  , G0  , G0  , G0  , G0  , G0  , G0  , G0  , G0  , G0  , G0  , G0},
	{G0  , G0  , G0  , G0  , G0  , G0  , G0  , G0  , G0  , G0  , G0  , G0  , G0  , G0  , G0  , G0  , G0}
};

Tile3::Tile3(SDL_Renderer* renderer) : 
	Tile0(renderer)
{
	grass[0] = TextureManager::load("assets/General/Tiles/Scenario3/Grass.png", renderer);
	grass[1] = nullptr;
}

Tile3::~Tile3(void)
{
	TextureManager::destroy(grass[0]);
}

void Tile3::draw(void)
{
	for (size_t row = 0; row < ROW - 2; ++row)
	{
		for (size_t column = 0; column < COLUMN - 8; ++column)
		{
			destination.x = (column + 4) * SCALE;
			destination.y = (row + 1) * SCALE;

			switch (currentMap[row][column])
			{
				case G0:
				{
					TextureManager::draw(grass[0], destination, renderer);
					break;
				}
			}
		}
	}
}
