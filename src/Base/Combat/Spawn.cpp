#include "Spawn.h"

Spawn::Spawn(const Coordinate spawn, TileInfo* tile) :
	spawn(spawn), tile(tile)
{
}

bool Spawn::spawnAvailable(void) const
{
	return tile->info[spawn.x][spawn.y].state == State::NEUTRAL;
}

void Spawn::boostSpawn(void) const
{
	++tile->info[spawn.x][spawn.y].actionsLeft;
}

Coordinate Spawn::get(void) const
{
	return spawn;
}
