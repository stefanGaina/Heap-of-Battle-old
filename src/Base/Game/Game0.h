#pragma once
#include "Run.h"
#include "Cursor.h"
#include "Pause.h"

class Game0 : public Run
{
public:
	Game0(SDL_Renderer* renderer, const Mouse& mouse);

	virtual void render(void) = 0;
	virtual void handleEvents(void) = 0;
	
protected:
	Cursor cursor;

	Pause pause;

	Mouse mouse;

	SDL_Renderer* renderer;
};
