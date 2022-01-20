#pragma once
#include "Language.h"

#include <SDL_ttf.h>

class TextMenu
{
public:
	TextMenu(SDL_Renderer* renderer);
	~TextMenu(void);

	void draw(void);

private:
	SDL_Renderer* renderer;

	TTF_Font* font;
	SDL_Color black, red;

	SDL_Texture* heap, * of, * battle, * version;
	SDL_Texture* digit1, * newGame, * loadGame, * exit;
};
