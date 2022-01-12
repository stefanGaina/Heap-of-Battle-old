#pragma once
#include "Building0.h"

struct Current
{
	SDL_Texture* keep, * altar, * farm, * tower;
};

struct Altar
{
	SDL_Texture* activated, * deactivated;
};

struct Keep
{
	SDL_Texture* stock, * vamped, * destroyed;
};

struct Texture
{
	Current current;

	Keep keep;
	Altar altar;
	SDL_Texture* farm;
	SDL_Texture* tower;
};

class Building1 : public Building0
{
public:
	Building1(SDL_Renderer* renderer);
	~Building1(void);

	void draw(void);

	void updateAltars(Flag flag);
	void updateFarms(Flag flag);
	void updateTowers(Flag flag);

	void updateFarm(SDL_Texture*& farm, Faction faction);
	void updateTower(SDL_Texture*& farm, Faction faction);

	void vampHumanKeep(void);
	void vampOrcKeep(void);
	
	void victory(Faction faction);

private:
	void loadTextures(void);
	void destroyTextures(void);

	void initializeCurrent(void);

	SDL_Rect destination, destination2x2, destination3x3, destination4x4, destinationBridge;

	SDL_Texture* portal, * bridge;

	Texture human, orc;
};
