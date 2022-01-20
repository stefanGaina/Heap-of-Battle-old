#pragma once
#include "Combat0.h"
#include "Spawn.h"

class Combat2 : public Combat0
{
public:
	Combat2(SDL_Renderer* renderer);

	void train(State unit);

	void boostSpawns(void);
	bool humanSpawnAvailable(void);
	bool orcSpawnAvailable(void);

	Coordinate getHumanSpawn(void);
	Coordinate getOrcSpawn(void);

	const Spawn human[2], orc[2];

private:
	void initializeInfo(void);

	Engage keep;
};
