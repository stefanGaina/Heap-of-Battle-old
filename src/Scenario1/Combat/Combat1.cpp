#include "Combat1.h"

Combat1::Combat1(SDL_Renderer* renderer, TileInfo* tile) : 
	Combat0(renderer, tile), human({ 17, 8 }, &this->tile), orc({ 1, 16 }, &this->tile)
{
	if (tile == nullptr)
	{
		initializeInfo();
	}
}

void Combat1::train(State unit)
{
	Coordinate spawn;
	
	if (unit > State::NEUTRAL)
	{
		spawn = human.get();
	}
	else
	{
		spawn = orc.get();
	}
	this->unit.train(unit, spawn);
	engage(Engage::UNIT, spawn);
}

void Combat1::checkPortals(bool finishAnimation)
{
	if (finishAnimation)
	{
		if (tile.info[2][4].state == State::NEUTRAL || highlight.canAttack(tile.info[13][5].state, tile.info[2][4].state))
		{
			tile.info[2][4].state = tile.info[13][5].state;
			tile.info[2][4].show = tile.info[13][5].show;
			tile.info[2][4].actionsLeft = tile.info[13][5].actionsLeft;
			tile.info[2][4].hasAttacked = tile.info[13][5].hasAttacked;
			tile.info[2][4].notSelected = tile.info[13][5].notSelected;

			tile.info[13][5].state = State::NEUTRAL;
			tile.info[13][5].show = Show::NOTHING;
			tile.info[13][5].notSelected = false;

			if (remember.x == 13 && remember.y == 5 && tile.info[2][4].actionsLeft > 0)
			{
				remember = { 2, 4 };
				highlight.reset(13, 5, 20); //
				highlight.path({ 2, 4 }, tile.info[2][4].actionsLeft);
			}
		}
		if (tile.info[16][20].state == State::NEUTRAL || highlight.canAttack(tile.info[5][19].state, tile.info[16][20].state))
		{
			tile.info[16][20].state = tile.info[5][19].state;
			tile.info[16][20].show = tile.info[5][19].show;
			tile.info[16][20].actionsLeft = tile.info[5][19].actionsLeft;
			tile.info[16][20].hasAttacked = tile.info[5][19].hasAttacked;
			tile.info[16][20].notSelected = tile.info[5][19].notSelected;

			tile.info[5][19].state = State::NEUTRAL;
			tile.info[5][19].show = Show::NOTHING;
			tile.info[5][19].notSelected = false;

			if (remember.x == 5 && remember.y == 19 && tile.info[16][20].actionsLeft > 0)
			{
				remember = { 16, 20 };
				highlight.reset(16, 20, 20); //
				highlight.path({ 16, 20 }, tile.info[16][20].actionsLeft);
			}
		}
	}
}

Faction Combat1::captureAltar(Faction point[3])
{
	struct { Uint8 human, orc; } counter = { 0, 0 };

	for (size_t i = 0; i < 3; ++i)
	{
		if (point[i] == Faction::HUMAN)
		{
			++counter.human;
		}
		if (point[i] == Faction::ORC)
		{
			++counter.orc;
		}
	}
	if (counter.human >= 2)
	{
		return Faction::HUMAN;
	}
	if (counter.orc >= 2)
	{
		return Faction::ORC;
	}
	return Faction::NEUTRAL;
}

Faction Combat1::captureHumanAltar(void)
{
	Faction point[3] = { capturePoint({ 7, 7 }) , capturePoint({ 7, 8 }) , capturePoint({ 7, 9 }) };

	return captureAltar(point);
}

Faction Combat1::captureOrcAltar(void)
{
	Faction point[3] = { capturePoint({ 11, 15 }) , capturePoint({ 11, 16 }) , capturePoint({ 11, 17 }) };

	return captureAltar(point);
}

Faction Combat1::capturePoint(Coordinate point)
{
	if (tile.info[point.x][point.y].state > State::NEUTRAL)
	{
		return Faction::HUMAN;
	}
	if (tile.info[point.x][point.y].state < State::NEUTRAL)
	{
		return Faction::ORC;
	}
	return Faction::NEUTRAL;
}

Faction Combat1::captureHumanTower(void)
{
	Faction point[3] = { capturePoint({ 8, 6 }) , capturePoint({ 9, 6 }) , capturePoint({ 10, 6 }) };

	return captureAltar(point);
}

Faction Combat1::captureOrcTower(void)
{
	Faction point[3] = { capturePoint({ 8, 18 }) , capturePoint({ 9, 18 }) , capturePoint({ 10, 18 }) };

	return captureAltar(point);
}

void Combat1::trainFarm(State unit0, State unit1)
{
	tile.info[17][17].state = unit0;
	tile.info[17][17].show = (Show)unit0;

	tile.info[1][7].state = unit1;
	tile.info[1][7].show = (Show)unit1;
}

void Combat1::trainFarms(Uint8 turn, Flag flag)
{
	if (++turn % 5 == 0)
	{
		if (flag.human == flag.orc)
		{
			if (flag.human == Faction::HUMAN)
			{
				trainFarm(State::HUMAN_ARCHER, State::HUMAN_ARCHER);
			}
			else
			{
				trainFarm(State::ORC_ARCHER, State::ORC_ARCHER);
			}
		}
		else
		{
			if (flag.human == Faction::HUMAN)
			{
				trainFarm(State::HUMAN_INFANTRY, State::ORC_INFANTRY);
			}
			else
			{
				trainFarm(State::ORC_INFANTRY, State::HUMAN_INFANTRY);
			}
		}
	}
}

void Combat1::boostSpawns(void)
{
	human.boostSpawn();
	orc.boostSpawn();
}

void Combat1::boostFarms(void)
{
	static const Coordinate farmSpawn[2] = { {1, 7}, {17, 17} };

	++tile.info[farmSpawn[0].x][farmSpawn[1].y].actionsLeft;
	++tile.info[farmSpawn[1].x][farmSpawn[1].y].actionsLeft;
}

void Combat1::boostTowers(Flag flag)
{
	if (flag.human == Faction::HUMAN)
	{
		if (capturePoint({ 8, 6 }) == Faction::HUMAN)
		{
			++tile.info[8][6].actionsLeft;
		}
		if (capturePoint({ 9, 6 }) == Faction::HUMAN)
		{
			++tile.info[9][6].actionsLeft;
		}
		if (capturePoint({ 10, 6 }) == Faction::HUMAN)
		{
			++tile.info[10][6].actionsLeft;
		}
	}
	else
	{
		if (capturePoint({ 8, 6 }) == Faction::ORC)
		{
			++tile.info[8][6].actionsLeft;
		}
		if (capturePoint({ 9, 6 }) == Faction::ORC)
		{
			++tile.info[9][6].actionsLeft;
		}
		if (capturePoint({ 10, 6 }) == Faction::ORC)
		{
			++tile.info[10][6].actionsLeft;
		}
	}
	if (flag.orc == Faction::ORC)
	{
		if (capturePoint({ 8, 18 }) == Faction::ORC)
		{
			++tile.info[8][18].actionsLeft;
		}
		if (capturePoint({ 9, 18 }) == Faction::ORC)
		{
			++tile.info[9][18].actionsLeft;
		}
		if (capturePoint({ 10, 18 }) == Faction::ORC)
		{
			++tile.info[10][18].actionsLeft;
		}
	}
	else
	{
		if (capturePoint({ 8, 18 }) == Faction::HUMAN)
		{
			++tile.info[8][18].actionsLeft;
		}
		if (capturePoint({ 9, 18 }) == Faction::HUMAN)
		{
			++tile.info[9][18].actionsLeft;
		}
		if (capturePoint({ 10, 18 }) == Faction::HUMAN)
		{
			++tile.info[10][18].actionsLeft;
		}
	}
}

void Combat1::initializeInfo(void)
{
	tile.info[12][1].state = State::VAMP_HUMAN_KEEP;
	tile.info[12][2].state = State::VAMP_HUMAN_KEEP;
	tile.info[12][3].state = State::VAMP_HUMAN_KEEP;

	tile.info[12][23].state = State::VAMP_ORC_KEEP;
	tile.info[12][22].state = State::VAMP_ORC_KEEP;
	tile.info[12][21].state = State::VAMP_ORC_KEEP;

	for (size_t row = 14; row < 18; ++row)
	{
		for (size_t column = 4; column < 8; ++column)
		{
			tile.info[row][column].state = State::HUMAN_KEEP;
			tile.info[ROW - 1 - row][COLUMN - 1 - column].state = State::ORC_KEEP;
		}
	}
	for (size_t row = 1; row < 10; ++row) // river
	{
		for (size_t column = 10; column < 15; ++column)
		{
			tile.info[row][column].state = State::BLANK;
			tile.info[ROW - 1 - row][column].state = State::BLANK;
		}
	}
	for (size_t column = 10; column < 15; ++column) // bridges
	{
		tile.info[3][column].state = State::NEUTRAL;
		tile.info[4][column].state = State::NEUTRAL;

		tile.info[14][column].state = State::NEUTRAL;
		tile.info[15][column].state = State::NEUTRAL;
	}
	for (size_t row = 8; row < 11; ++row)
	{
		for (size_t column = 7; column < 10; ++column)
		{
			tile.info[row][column].state = State::HUMAN_ALTAR;
			tile.info[ROW - 1 - row][COLUMN - 1 - column].state = State::ORC_ALTAR;
		}
	}
	for (size_t row = 9; row < 11; ++row)
	{
		for (size_t column = 4; column < 6; ++column)
		{
			tile.info[row][column].state = State::HUMAN_TOWER;
			tile.info[ROW - 1 - row][COLUMN - 1 - column].state = State::ORC_TOWER;
		}
	}
	for (size_t row = 1; row < 3; ++row)
	{
		for (size_t column = 8; column < 10; ++column)
		{
			tile.info[row][column].state = State::ORC_FARM;
			tile.info[ROW - 1 - row][COLUMN - 1 - column].state = State::HUMAN_FARM;
		}
	}
	// portals
	tile.info[1][4].state = State::BLANK;
	tile.info[13][4].state = State::BLANK;
	tile.info[5][20].state = State::BLANK;
	tile.info[17][20].state = State::BLANK;
}
