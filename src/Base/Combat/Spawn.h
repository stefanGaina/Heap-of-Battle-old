#pragma once
#include "TileInfo.h"

class Spawn
{
public:
	Spawn(const Coordinate spawn, TileInfo* tile);

	bool spawnAvailable(void) const;
	void boostSpawn(void) const;

	Coordinate get(void) const;

private:
	const Coordinate spawn;
	TileInfo* const tile;
};