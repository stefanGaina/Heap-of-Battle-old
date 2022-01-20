#pragma once
#include "TileInfo.h"

class Save
{
public:
	void write(TileInfo* tile, Receipt human, Receipt orc, Uint16 turn, char scenario);
};
