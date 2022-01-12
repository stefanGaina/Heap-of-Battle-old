#pragma once
#include "Game0.h"
#include "Account2.h"
#include "Combat2.h"
#include "Map2.h"
#include "Menu2.h"
#include "Sound2.h"
#include "Outline2.h"

class Game2 : public Game0
{
public:
	Game2(SDL_Renderer* renderer, const Mouse& mouse);

	void render(void);
	void handleEvents(void);
	
private:
	void pauseGame(void);
	void passTurn(void);
	void checkVictory(void);

	void humanNo(State state, Coordinate click = { 0,0 });
	bool humanBuilding(State state);

	void orcNo(State state, Coordinate = { 0,0 });
	bool orcBuilding(State state);

	bool caseUnit(Coordinate click);

	Account2 account;

	Combat2 combat;

	Map2 map;

	Menu2 menu;

	Sound2 sound;

	Outline2 outline;
};
