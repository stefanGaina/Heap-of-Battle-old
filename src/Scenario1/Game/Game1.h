#pragma once
#include "Game0.h"
#include "Account1.h"
#include "Combat1.h"
#include "Map1.h"
#include "Menu1.h"
#include "Sound1.h"
#include "Outline1.h"

class Game1 : public Game0
{
public:
	Game1(SDL_Renderer* renderer, const Mouse& mouse, TileInfo* tile = nullptr, Receipt human = { 10, 15 }, Receipt orc = { 0,15 }, Uint8 turn = 1);

	void render(void);
	void handleEvents(void);

private:
	void pauseGame(void);
	void passTurn(void);

	void humanNo(State state, Coordinate click = { 0,0 });
	bool humanBuilding(State state);

	void orcNo(State state, Coordinate = { 0,0 });
	bool orcBuilding(State state);
	
	bool caseUnit(Coordinate click);

	void updateAltars(void);
	void updateFarms(void);
	void updateTowers(void);

	void checkVictory(void);

	Account1 account;

	Combat1 combat;

	Map1 map;

	Menu1 menu;

	Sound1 sound;

	Outline1 outline;
};
