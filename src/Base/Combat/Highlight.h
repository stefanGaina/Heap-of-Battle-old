#pragma once
#include "TileInfo.h"

struct HighlightTexture
{
	HighlightTexture(SDL_Texture* highlight);
	~HighlightTexture(void);

	SDL_Texture* highlight;
};

class Highlight
{
public:
	Highlight(TileInfo* tile, Coordinate* remember, SDL_Renderer* renderer);

	void draw(Color highlight, Coordinate location);
	void set(Color highlight);
	
	void path(Coordinate current, Uint8 actions, Uint8 distance = 0);
	void reset(Uint8 x, Uint8 y, Uint8 actions = 0);

	bool validMovement(Color highlight);
	bool canAttack(State attacker, State defender);
	
private:
	SDL_Renderer* renderer;
	SDL_Rect destination;

	TileInfo* tile;
	Coordinate* remember;

	Color highlight;
	
	HighlightTexture human, orc;
};
