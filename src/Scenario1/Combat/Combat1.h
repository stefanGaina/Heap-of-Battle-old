#pragma once
#include "Combat0.h"

class Combat1 : public Combat0
{
public:
	Combat1(SDL_Renderer* renderer, TileInfo* tile);

	void checkPortals(bool finishAnimation);

	Faction captureHumanAltar(void);
	Faction captureOrcAltar(void);
	
	Faction captureHumanTower(void);
	Faction captureOrcTower(void);

	Faction capturePoint(Coordinate point);
	Faction captureAltar(Faction point[3]);

	void boostFarms(void);
	void boostTowers(Flag flag);

	void trainFarm(State unit0, State unit1);
	void trainFarms(Uint8 turn, Flag flag);

private:
	void initializeInfo(void);
};
