#include "Combat2.h"

Combat2::Combat2(SDL_Renderer* renderer) : 
	Combat0(renderer), 
	human{ {{ 3, 4 }, &this->tile }, {{ 15, 4 }, &this->tile} },
	orc{ {{ 3, 20 }, &this->tile }, {{ 15, 20 }, &this->tile} }
{
	initializeInfo();
}

void Combat2::train(State unit)
{
	Coordinate spawn;

	if (getEngaged() == Engage::KEEP_1)
	{
		unit > State::NEUTRAL ? spawn = human[0].get() : spawn = orc[0].get();
	}
	else
	{
		unit > State::NEUTRAL ? spawn = human[1].get() : spawn = orc[1].get();
	}
	this->unit.train(unit, spawn);
	keep = getEngaged();
	engage(Engage::UNIT, spawn);
}

void Combat2::boostSpawns(void)
{
	for (size_t i = 0; i < 2; ++i)
	{
		human[i].boostSpawn();
		orc[i].boostSpawn();
	}
}

Coordinate Combat2::getHumanSpawn(void)
{
	return keep == Engage::KEEP_1 ? human[0].get() : human[1].get();
}

Coordinate Combat2::getOrcSpawn(void)
{
	return keep == Engage::KEEP_1 ? orc[0].get() : orc[1].get();
}

bool Combat2::humanSpawnAvailable(void)
{
	return getEngaged() == Engage::KEEP_1 ? human[0].spawnAvailable() : human[1].spawnAvailable();
}

bool Combat2::orcSpawnAvailable(void)
{
	return getEngaged() == Engage::KEEP_1 ? orc[0].spawnAvailable() : orc[1].spawnAvailable();
}

void Combat2::initializeInfo(void)
{
	for (size_t row = 1; row < 4; ++row)
	{
		for (size_t column = 11; column < 14; ++column)
		{
			tile.info[row][column].state = State::MINE;
			tile.info[row + 7][column].state = State::LABORATORY;
			tile.info[row + 14][column].state = State::MINE;
		}
	}
	for (size_t row = 4; row < 7; ++row)
	{
		for (size_t column = 4; column < 7; ++column)
		{
			tile.info[row][column].state = State::HUMAN_KEEP_1;
			tile.info[row + 8][column].state = State::HUMAN_KEEP_2;

			tile.info[row][column + 14].state = State::ORC_KEEP_1;
			tile.info[row + 8][column + 14].state = State::ORC_KEEP_2;
		}
	}
	for (size_t row = 7; row < 12; ++row)
	{
		for (size_t column = 4; column < 11; ++column)
		{
			tile.info[row][column].state = State::BLANK;
			tile.info[row ][column + 10].state = State::BLANK;
		}
	}

	//PORTALS
}
