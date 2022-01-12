#pragma once
#include "Language.h"

struct CursorTexture
{
	CursorTexture(SDL_Texture* cursor);
	~CursorTexture(void);

	SDL_Texture* cursor;
};

class Cursor
{
public:
	Cursor(SDL_Renderer* renderer);

	void draw(Mouse mouse);

	void change(void);

private:
	SDL_Renderer* renderer;
	SDL_Rect destination;

	CursorTexture human, orc;

	SDL_Texture* current;
};
