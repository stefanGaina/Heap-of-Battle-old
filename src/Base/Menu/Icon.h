#pragma once
#include "Language.h"

class Icon
{
public:
	Icon(SDL_Renderer* renderer);
	~Icon(void);

	void draw(Faction turn, State type, bool hasAttacked);

private:
	void humanUnit(SDL_Texture* figure, SDL_Texture* attack, bool hasAttacked);
	void orcUnit(SDL_Texture* figure, SDL_Texture* attack, bool hasAttacked);

	SDL_Renderer* renderer;
	SDL_Rect destination;

	SDL_Texture* pause;

	struct Icons
	{
		SDL_Texture* pass;
		SDL_Texture* infantry, * archer, * knight, * wing;
		SDL_Texture* infantryAttack, * archerAttack, * knightAttack, * wingAttack;
	}human, orc;
};
