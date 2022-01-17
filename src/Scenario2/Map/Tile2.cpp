#include "Tile2.h"
#include "TextureManager.h"

enum Tiles
{
	S0 = 0,

	I0 = 2,

	ISR = 3,
	ISL = 4,
	ISU = 5,
	ISD = 6,

	ISNW = 7,
	ISNE = 8,
	ISSE = 9,
	ISSW = 10,
};

static Uint8 currentMap[ROW - 2][COLUMN - 8] =
{
	{S0  , S0  , S0  , S0  , S0  , S0  , S0  , S0  , S0  , S0  , S0  , S0  , S0  , S0  , S0  , S0  , S0},
	{S0  , S0  , S0  , S0  , S0  , S0  , S0  , S0  , S0  , S0  , S0  , S0  , S0  , S0  , S0  , S0  , S0},
	{S0  , S0  , S0  , S0  , S0  , S0  , S0  , S0  , S0  , S0  , S0  , S0  , S0  , S0  , S0  , S0  , S0},
	{S0  , S0  , S0  , S0  , S0  , S0  , S0  , S0  , S0  , S0  , S0  , S0  , S0  , S0  , S0  , S0  , S0},
	{S0  , S0  , S0  , S0  , S0  , S0  , S0  , S0  , S0  , S0  , S0  , S0  , S0  , S0  , S0  , S0  , S0},
	{S0  , S0  , S0  , S0  , S0  , S0  , S0  , S0  , S0  , S0  , S0  , S0  , S0  , S0  , S0  , S0  , S0},
	{ISU , ISU , ISU , ISU , ISU , ISU , ISNE, S0  , S0  , S0  , ISNW, ISU , ISU , ISU , ISU , ISU , ISU},
	{I0  , I0  , I0  , I0  , I0  , I0  , ISR , S0  , S0  , S0  , ISL , I0  , I0  , I0  , I0  , I0  , I0},
	{I0  , I0  , I0  , I0  , I0  , I0  , ISR , S0  , S0  , S0  , ISL , I0  , I0  , I0  , I0  , I0  , I0},
	{I0  , I0  , I0  , I0  , I0  , I0  , ISR , S0  , S0  , S0  , ISL , I0  , I0  , I0  , I0  , I0  , I0},
	{ISD , ISD , ISD , ISD , ISD , ISD , ISSE, S0  , S0  , S0  , ISSW, ISD , ISD , ISD , ISD , ISD , ISD},
	{S0  , S0  , S0  , S0  , S0  , S0  , S0  , S0  , S0  , S0  , S0  , S0  , S0  , S0  , S0  , S0  , S0},
	{S0  , S0  , S0  , S0  , S0  , S0  , S0  , S0  , S0  , S0  , S0  , S0  , S0  , S0  , S0  , S0  , S0},
	{S0  , S0  , S0  , S0  , S0  , S0  , S0  , S0  , S0  , S0  , S0  , S0  , S0  , S0  , S0  , S0  , S0},
	{S0  , S0  , S0  , S0  , S0  , S0  , S0  , S0  , S0  , S0  , S0  , S0  , S0  , S0  , S0  , S0  , S0},
	{S0  , S0  , S0  , S0  , S0  , S0  , S0  , S0  , S0  , S0  , S0  , S0  , S0  , S0  , S0  , S0  , S0},
	{S0  , S0  , S0  , S0  , S0  , S0  , S0  , S0  , S0  , S0  , S0  , S0  , S0  , S0  , S0  , S0  , S0}
};

Tile2::Tile2(SDL_Renderer* renderer) : 
	Tile0(renderer)
{
	loadTextures();
}

Tile2::~Tile2(void)
{
	destroyTextures();
}

void Tile2::draw(void)
{
	for (size_t row = 0; row < ROW - 2; ++row)
	{
		for (size_t column = 0; column < COLUMN - 8; ++column)
		{
			destination.x = (column + 4) * SCALE;
			destination.y = (row + 1) * SCALE;

			switch (currentMap[row][column])
			{
				case S0:
				{
					TextureManager::draw(snow[0], destination, renderer);
					break;
				}
				case I0:
				{
					TextureManager::draw(ice, destination, renderer);
					break;
				}
				case ISR:
				{
					TextureManager::draw(iceToSnowRight, destination, renderer);
					break;
				}
				case ISL:
				{
					TextureManager::draw(iceToSnowLeft, destination, renderer);
					break;
				}
				case ISU:
				{
					TextureManager::draw(iceToSnowUp, destination, renderer);
					break;
				}
				case ISD:
				{
					TextureManager::draw(iceToSnowDown, destination, renderer);
					break;
				}
				case ISNW:
				{
					TextureManager::draw(iceToSnowNW, destination, renderer);
					break;
				}
				case ISNE:
				{
					TextureManager::draw(iceToSnowNE, destination, renderer);
					break;
				}
				case ISSE:
				{
					TextureManager::draw(iceToSnowSE, destination, renderer);
					break;
				}
				case ISSW:
				{
					TextureManager::draw(iceToSnowSW, destination, renderer);
					break;
				}
			}
		}
	}
}

void Tile2::loadTextures(void)
{
	snow[0] = TextureManager::load("Assets/General/Tiles/Scenario2/Snow.png", renderer);

	ice = TextureManager::load("Assets/General/Tiles/Scenario2/Ice.png", renderer);

	iceToSnowRight = TextureManager::load("Assets/General/Tiles/Scenario2/Ice to Snow Right.png", renderer);
	iceToSnowLeft = TextureManager::load("Assets/General/Tiles/Scenario2/Ice to Snow Left.png", renderer);
	iceToSnowUp = TextureManager::load("Assets/General/Tiles/Scenario2/Ice to Snow Up.png", renderer);
	iceToSnowDown = TextureManager::load("Assets/General/Tiles/Scenario2/Ice to Snow Down.png", renderer);

	iceToSnowNW = TextureManager::load("Assets/General/Tiles/Scenario2/Ice to Snow NW.png", renderer);
	iceToSnowNE = TextureManager::load("Assets/General/Tiles/Scenario2/Ice to Snow NE.png", renderer);
	iceToSnowSE = TextureManager::load("Assets/General/Tiles/Scenario2/Ice to Snow SE.png", renderer);
	iceToSnowSW = TextureManager::load("Assets/General/Tiles/Scenario2/Ice to Snow SW.png", renderer);
}

void Tile2::destroyTextures(void)
{
	TextureManager::destroy(snow[0]);

	TextureManager::destroy(ice);

	TextureManager::destroy(iceToSnowRight);
	TextureManager::destroy(iceToSnowLeft);
	TextureManager::destroy(iceToSnowUp);
	TextureManager::destroy(iceToSnowDown);

	TextureManager::destroy(iceToSnowNW);
	TextureManager::destroy(iceToSnowNE);
	TextureManager::destroy(iceToSnowSE);
	TextureManager::destroy(iceToSnowSW);
}
