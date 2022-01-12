#include "Combat2.h"

Combat2::Combat2(SDL_Renderer* renderer) : Combat0(renderer)
{
	initializeInfo();
}

void Combat2::initializeInfo(void)
{
	Uint8 row, column;

	for (row = 1; row < 4; ++row)
	{
		for (column = 11; column < 14; ++column)
		{
			tile.info[row][column].state = State::MINE;
			tile.info[row + 7][column].state = State::LABORATORY;
			tile.info[row + 14][column].state = State::MINE;
		}
	}
	for (row = 4; row < 7; ++row)
	{
		for (column = 4; column < 7; ++column)
		{
			tile.info[row][column].state = State::HUMAN_BARRACK;
			tile.info[row + 8][column].state = State::HUMAN_BARRACK;

			tile.info[row][column + 14].state = State::ORC_BARRACK;
			tile.info[row + 8][column + 14].state = State::ORC_BARRACK;
		}
	}
	for (row = 7; row < 12; ++row)
	{
		for (column = 4; column < 11; ++column)
		{
			tile.info[row][column].state = State::BLANK;
			tile.info[row ][column + 10].state = State::BLANK;
		}
	}

	//PORTALS
}