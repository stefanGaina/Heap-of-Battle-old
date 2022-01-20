#include "Save.h"
#include "Log.h"

#include <fstream>

void Save::write(TileInfo* tile, Receipt human, Receipt orc, Uint16 turn, char scenario)
{
	std::fstream fout("save.txt", std::ios::out);
#ifdef DEBUG
	if (!fout.is_open())
	{
		ERROR("Can't write in save.txt");
	}
#endif
	fout << scenario << std::endl;
	fout << (int)human.gold << " " << human.yield << " " << orc.gold << " " << orc.yield << " " << turn << std::endl;

	for (size_t row = 0; row < ROW; ++row)
	{
		for (size_t column = 0; column < COLUMN; ++column)
		{
			fout << (int)tile->info[row][column].state << " " << tile->info[row][column].actionsLeft << " " << tile->info[row][column].hasAttacked << " " << tile->info[row][column].notSelected << " ";
		}
		fout << std::endl;
	}
}
