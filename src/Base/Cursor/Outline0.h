#pragma once
#include "Enable.h"
#include "Language.h"

class Outline0 : public Enable
{
public:
	Outline0(SDL_Renderer* renderer);
		
	virtual void draw(void) = 0;
	void set(Coordinate hover, State state);

	void change(void);

protected:
	void square(Coordinate hover, Uint8 lenght);

	Coordinate hover;

	State type;

private:
	SDL_Renderer* renderer;

	const SDL_Color* current, human, orc;
};
