#pragma once
#include "TileInfo.h"

enum Action
{
	EMPTY = 0,
	INFANTRY_ACTION = 2,
	ARCHER_ACTION = 3,
	KNIGHT_ACTION = 4,
	WING_ACTION = 4,

	UNITS = 4,
};

struct Figure
{
	Coordinate spawn; // TO DO

	SDL_Texture* infantry, * archer, * knight, * wing;
};

class Unit
{
public:
	Unit(TileInfo* tile, SDL_Renderer* renderer);
	~Unit(void);

	void draw(Coordinate location);
	void refresh(Faction turn);
	void train(State unit, Coordinate spawn);

	void boostSpawns(void);
	bool humanSpawnAvailable(void);
	bool orcSpawnAvailable(void);

	Uint8 getAction(Uint8 index);

private:
	void reset(Coordinate position, Uint8 action);

	void loadTextures(void);
	void destroyTextures(void);

	SDL_Renderer* renderer;
	SDL_Rect destination;

	TileInfo* tile;

	Uint8 action[UNITS + 1];

	SDL_Texture* selectCircle;

	Figure human, orc;
};
