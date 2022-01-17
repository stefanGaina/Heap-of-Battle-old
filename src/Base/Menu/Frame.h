#pragma once
#include "Language.h"

class Frame
{
public:
	Frame(SDL_Renderer* renderer);
	~Frame(void);

	void humanAlways(void);
	void orcAlways(void);

	void humanStandard(void);
	void orcStandard(void);

	void humanKeep(void);
	void orcKeep(void);

	void humanAttack(bool hasAttacked);
	void orcAttack(bool hasAttacked);

private:
	SDL_Renderer* renderer;
	SDL_Rect destination;

	SDL_Texture* texture;
};
