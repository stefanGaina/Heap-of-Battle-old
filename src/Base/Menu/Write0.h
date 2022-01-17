#pragma once
#include "Language.h"

#include <SDL_ttf.h>

struct Colors
{
	Colors(void);

	SDL_Color gold, gray, blue, red;
};

struct IncomeText
{
	IncomeText(SDL_Texture* gold, SDL_Texture* yield);
	~IncomeText(void);

	SDL_Texture* gold, * yield;
};

struct Text
{
	~Text(void);

	SDL_Texture* digit[6];
	SDL_Texture* gold, * yield, * pause, * pass, * passTurn, * train, * act;
};

class Write0
{
public:
	Write0(SDL_Renderer* renderer, Uint8 lastPrice);
	~Write0(void);

	void humanAlways(Receipt human, Receipt orc);
	void orcAlways(Receipt human, Receipt orc);

	void humanKeep(void);
	void orcKeep(void);

	void humanUnit(Uint8 actionsLeft);
	void orcUnit(Uint8 actionsLeft);

protected:
	void variableValueText(SDL_Texture*& texture, SDL_Color color, Uint8 value);

	SDL_Renderer* renderer;
	SDL_Rect destination;

	TTF_Font* font;
	Colors color;
	
private:
	IncomeText current, neutral;

	Text human, orc;

	SDL_Texture* price[5];
};
