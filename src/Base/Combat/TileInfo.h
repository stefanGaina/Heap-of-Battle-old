#pragma once
#include "Language.h"

struct Info
{
	State state;
	Show show;
	Color highlight;
	Uint8 distance;
	Uint8 actionsLeft;

	bool hasAttacked;
	bool notSelected;
};

class TileInfo
{
public:
	TileInfo(void);
	
	Info info[ROW][COLUMN];
};
