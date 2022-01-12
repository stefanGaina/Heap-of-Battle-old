#pragma once
#include "Language.h"

class CursorMenu
{
public:
	CursorMenu(SDL_Renderer* renderer);
	~CursorMenu(void);

	void draw(const Mouse& mouse);

private:
	SDL_Renderer* renderer;
	SDL_Rect destination;

	SDL_Texture* texture;
};
