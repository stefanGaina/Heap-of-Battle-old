#pragma once
#include "Language.h"

struct Icons
{
	SDL_Texture* pass, * lastIcon;
	SDL_Texture* infantry, * archer, * knight, * wing;
	SDL_Texture* infantryAttack, * archerAttack, * knightAttack, * wingAttack;
};

class Icon0
{
public:
	Icon0(SDL_Renderer* renderer, SDL_Texture* humanLastIcon, SDL_Texture* orcLastIcon);
	~Icon0(void);

	//virtual void draw(Faction turn, State type, bool hasAttacked) = 0;

	void humanAlways(void);
	void orcAlways(void);

	void humanKeep(void);
	void orcKeep(void);

	void humanUnit(State unit, bool hasAttacked = true);
	void orcUnit(State unit, bool hasAttacked = true);

protected:
	SDL_Renderer* renderer;
	SDL_Rect destination;

private:
	void humanUnit(SDL_Texture* figure);
	void orcUnit(SDL_Texture* figure);
	void unitAttack(SDL_Texture* attack, bool hasAttacked);

	SDL_Texture* pause;
	Icons human, orc;
};
