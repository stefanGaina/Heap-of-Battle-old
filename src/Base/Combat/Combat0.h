#pragma once
#include "Animation.h"
#include "Highlight.h"
#include "Movement.h"
#include "Unit.h"

class Combat0
{
public:
	Combat0(SDL_Renderer* renderer, TileInfo* tile = nullptr);

	virtual void train(State unit) = 0;
	virtual void boostSpawns(void) = 0;

	void draw(void);
	void refresh(Faction turn);
	void engage(Engage engaged = Engage::NO, Coordinate click = { 0, 0 });

	bool canMove(Coordinate click);
	bool canAct(Coordinate unit);

	State getState(Coordinate click);
	Uint8 getActions(Coordinate click);
	bool getAttacked(Coordinate click);
	Engage getEngaged(void);
	TileInfo* getTileInfo(void);

	Animation animation;
	Highlight highlight;
	Movement movement;
	Queue queue;
	Unit unit;

protected:
	TileInfo tile;
	
	Coordinate remember;

private:
	Engage engaged;
};
