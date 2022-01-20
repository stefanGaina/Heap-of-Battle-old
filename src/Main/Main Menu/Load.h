#pragma once
#include "TileInfo.h"

#include <fstream>

class Load
{
public:
	void read(void);

	char getScenario(void);
	Receipt getHumanReceipt(void);
	Receipt getOrcReceipt(void);
	Uint8 getTurn(void);
	TileInfo* getTileInfo(void);

private:
	char scenario;

	Uint16 turn;
	Receipt human, orc;

	TileInfo tile;
};
