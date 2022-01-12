#pragma once
#include <SDL_ttf.h>
#include "Language.h"

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

class Write
{
public:
	Write(SDL_Renderer* renderer);
	~Write(void);

	void draw(Faction turn, State type, Receipt human, Receipt orc, Uint8 actionsLeft);

private:
	void variableValueText(SDL_Texture*& texture, SDL_Color color, Uint8 value);

	SDL_Renderer* renderer;
	SDL_Rect destination;
	TTF_Font* font;
	
	Colors color;

	IncomeText current, neutral;

	Text human, orc;

	SDL_Texture* price[5];
};
