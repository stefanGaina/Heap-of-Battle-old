#include "Load.h"
#include "Log.h"

std::istream& operator>> (std::istream& stream, State& state)
{
	int temp;
	stream >> temp;
	state = (State)temp;

	return stream;
}

void Load::read(void)
{
	std::fstream fin("save.txt", std::ios::in);
#ifdef DEBUG
	if (!fin.is_open())
	{
		ERROR("Can't read from save.txt");
	}
#endif
	fin >> scenario;

	switch (scenario)
	{
		case 't':
		{
			break;
		}
		case '1':
		{
			fin >> human.gold >> human.yield >> orc.gold >> orc.yield >> turn;

			for (size_t row = 0; row < ROW; ++row)
			{
				for (size_t column = 0; column < COLUMN; ++column)
				{
					fin >> tile.info[row][column].state >> tile.info[row][column].actionsLeft >> tile.info[row][column].hasAttacked >> tile.info[row][column].notSelected;
					
					if (tile.info[row][column].state >= State::ORC_WING && tile.info[row][column].state <= State::ORC_INFANTRY || tile.info[row][column].state >= State::HUMAN_INFANTRY && tile.info[row][column].state <= State::HUMAN_WING)
					{
						tile.info[row][column].show = (Show)tile.info[row][column].state;
					}
					else
					{
						tile.info[row][column].show = Show::NOTHING;
					}
				}
			}
			break;
		}
		case '2':
		{
			break;
		}
		case '3':
		{

		}
	}
}

TileInfo* Load::getTileInfo(void)
{
	return &tile;
}

Receipt Load::getHumanReceipt(void)
{
	return human;
}

Receipt Load::getOrcReceipt(void)
{
	return orc;
}

Uint8 Load::getTurn(void)
{
	return turn;
}

char Load::getScenario(void)
{
	return scenario;
}
