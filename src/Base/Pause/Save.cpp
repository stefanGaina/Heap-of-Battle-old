#include "Save.h"
#include <iostream>

Save::Save(void) : fout("save.txt", std::ios::out)
{
	if (!fout.is_open())
	{
		std::cout << "[ERROR]: Can't write in save.txt" << std::endl;
	}
}

Save::~Save(void)
{
	fout.close();
}

void Save::write(TileInfo* tile, Receipt human, Receipt orc, Faction turn, char scenario)
{
	//fout.open("save.txt");

	if (!fout.is_open())
	{
		std::cout << "[ERROR]: Can't write in save.txt" << std::endl;
	}
	else
	{
		fout << scenario << std::endl;

		for (Uint8 row = 0; row < ROW; ++row)
		{
			for (Uint8 column = 0; column < COLUMN; ++column)
			{
				fout << (int)tile->info[row][column].state << " ";
			}
			fout << std::endl;
		}
	}
	//fout.close();
}
