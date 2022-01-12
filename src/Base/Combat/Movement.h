#pragma once
#include "TileInfo.h"
#include "Queue.h"

class Movement
{
public:
	Movement(TileInfo* tile, Coordinate* remember);

	void MoveUnit(Coordinate click, Queue* queue);
	bool isAttack(void);

protected:
	Move* findPath(Coordinate target);
	
private:
	TileInfo* tile;

	Coordinate* remember;

	bool attack;
};
