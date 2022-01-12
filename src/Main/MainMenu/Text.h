#pragma once
#include "Language.h"

#include <SDL_ttf.h>

class Text
{
public:
	Text(SDL_Renderer* renderer);
	~Text(void);

	void draw(void);

private:
	SDL_Renderer* renderer;

	SDL_Color color;
	TTF_Font* font;
};
