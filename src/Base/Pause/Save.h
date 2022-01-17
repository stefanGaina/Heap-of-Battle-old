#pragma once
#include "TileInfo.h"

#include <fstream>

class Save
{
public:
	Save(void);
	~Save(void);
	
	void write(TileInfo* tile, Receipt human, Receipt orc, Faction turn, char scenario);

private:
	std::fstream fout;
};
