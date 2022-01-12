#include "Tile1.h"
#include "TextureManager.h"

enum Tiles
{
	D0 = 11,
	D1 = 12,
	D2 = 13,
	D3 = 14,

	W0 = 15,
	W1 = 16,

	RBL0 = 17,
	RBL1 = 18,
	RBR0 = 19,
	RBR1 = 20,
};

static Uint8 currentMap[ROW - 2][COLUMN - 8] =
{
	{D1  , D2  , D3  , D1  , D1  , D1  , RBL1, W1  , W0  , W1  , RBR0, D2  , D1  , D1  , D1  , D1  , D1},
	{D1  , D3  , D0  , D0  , D1  , D1  , RBL1, W0  , W1  , W1  , RBR0, D3  , D1  , D1  , D1  , D1  , D1},
	{D3  , D0  , D0  , D0  , D0  , D1  , RBL0, W0  , W0  , W0  , RBR0, D1  , D1  , D1  , D1  , D1  , D1},
	{D2  , D3  , D0  , D0  , D0  , D1  , RBL0, W0  , W1  , W0  , RBR0, D1  , D1  , D1  , D1  , D1  , D1},
	{D2  , D3  , D0  , D0  , D0  , D3  , RBL0, W0  , W1  , W0  , RBR0, D0  , D0  , D0  , D0  , D1  , D1},
	{D3  , D0  , D0  , D0  , D3  , D2  , RBL0, W0  , W0  , W1  , RBR0, D2  , D3  , D0  , D0  , D0  , D0},
	{D0  , D0  , D0  , D1  , D1  , D1  , RBL0, W0  , W0  , W0  , RBR1, D0  , D0  , D0  , D0  , D0  , D2},
	{D0  , D0  , D1  , D1  , D1  , D1  , RBL1, W1  , W0  , W0  , RBR1, D1  , D1  , D1  , D1  , D1  , D1},
	{D1  , D1  , D1  , D1  , D1  , D1  , RBL0, W1  , W1  , W1  , RBR0, D1  , D1  , D1  , D1  , D1  , D1},
	{D1  , D1  , D1  , D1  , D1  , D1  , RBL1, W0  , W0  , W0  , RBR0, D1  , D1  , D1  , D1  , D0  , D0},
	{D2  , D0  , D0  , D0  , D0  , D0  , RBL0, W0  , W1  , W0  , RBR0, D1  , D1  , D1  , D0  , D0  , D3},
	{D0  , D0  , D0  , D0  , D3  , D2  , RBL0, W0  , W0  , W0  , RBR0, D2  , D3  , D0  , D0  , D3  , D2},
	{D1  , D1  , D0  , D0  , D0  , D0  , RBL0, W0  , W0  , W0  , RBR0, D3  , D0  , D0  , D0  , D3  , D2},
	{D1  , D1  , D1  , D1  , D1  , D1  , RBL0, W0  , W1  , W0  , RBR1, D1  , D0  , D0  , D0  , D0  , D3},
	{D1  , D1  , D1  , D1  , D1  , D1  , RBL0, W0  , W1  , W1  , RBR0, D1  , D0  , D0  , D0  , D0  , D0},
	{D1  , D1  , D1  , D1  , D1  , D3  , RBL1, W1  , W0  , W1  , RBR1, D1  , D1  , D0  , D0  , D3  , D1},
	{D1  , D1  , D1  , D1  , D1  , D2  , RBL1, W1  , W0  , W1  , RBR1, D1  , D1  , D1  , D3  , D2  , D1}
};

Tile1::Tile1(SDL_Renderer* renderer) : Tile0(renderer)
{
	loadTextures();
}

Tile1::~Tile1(void)
{
	destroyTextures();
}

void Tile1::draw(void)
{
	for (Uint8 row = 0; row < ROW - 2; ++row)
	{
		for (Uint8 column = 0; column < COLUMN - 8; ++column)
		{
			destination.x = (column + 4) * SCALE;
			destination.y = (row + 1) * SCALE;

			switch (currentMap[row][column])
			{
				case D0:
				{
					TextureManager::draw(dirt[0], destination, renderer);
					break;
				}
				case D1:
				{
					TextureManager::draw(dirt[1], destination, renderer);
					break;
				}
				case D2:
				{
					TextureManager::draw(dirt[2], destination, renderer);
					break;
				}
				case D3:
				{
					TextureManager::draw(dirt[3], destination, renderer);
					break;
				}
				case W0:
				{
					TextureManager::draw(water[0], destination, renderer);
					break;
				}
				case W1:
				{
					TextureManager::draw(water[1], destination, renderer);
					break;
				}
				case RBL0:
				{
					TextureManager::draw(riverBank.left[0], destination, renderer);
					break;
				}
				case RBL1:
				{
					TextureManager::draw(riverBank.left[1], destination, renderer);
					break;
				}
				case RBR0:
				{
					TextureManager::draw(riverBank.right[0], destination, renderer);
					break;
				}
				case RBR1:
				{
					TextureManager::draw(riverBank.right[1], destination, renderer);
				}
			}
		}
	}
}

void Tile1::loadTextures(void)
{
	dirt[0] = TextureManager::load("Assets/General/Tiles/Scenario1/Dirt.png", renderer);
	dirt[1] = TextureManager::load("Assets/General/Tiles/Scenario1/Dirt1.png", renderer);
	dirt[2] = TextureManager::load("Assets/General/Tiles/Scenario1/Dirt2.png", renderer);
	dirt[3] = TextureManager::load("Assets/General/Tiles/Scenario1/Dirt3.png", renderer);

	water[0] = TextureManager::load("Assets/General/Tiles/Scenario1/Water.png", renderer);
	water[1] = TextureManager::load("Assets/General/Tiles/Scenario1/Water1.png", renderer);

	riverBank.left[0] = TextureManager::load("Assets/General/Tiles/Scenario1/River Bank Left.png", renderer);
	riverBank.left[1] = TextureManager::load("Assets/General/Tiles/Scenario1/River Bank Left1.png", renderer);
	riverBank.right[0] = TextureManager::load("Assets/General/Tiles/Scenario1/River Bank Right.png", renderer);
	riverBank.right[1] = TextureManager::load("Assets/General/Tiles/Scenario1/River Bank Right1.png", renderer);
}

void Tile1::destroyTextures(void)
{
	for (Uint8 i = 0; i < 2; ++i)
	{
		TextureManager::destroy(dirt[i]);
		TextureManager::destroy(water[i]);
		TextureManager::destroy(riverBank.left[i]);
		TextureManager::destroy(riverBank.right[i]);
	}
	TextureManager::destroy(dirt[2]);
	TextureManager::destroy(dirt[3]);
}
