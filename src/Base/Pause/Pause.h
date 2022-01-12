#pragma once
#include "Enable.h"
#include "Victory.h"
#include "Save.h"

class Pause : public Enable
{
public:
	Pause(SDL_Renderer* renderer);
	~Pause(void);

	void draw(void);

	Victory victory;

	Save save;

private:
	void loadTextures(void);
	void destroyTextures(void);

	SDL_Renderer* renderer;

	SDL_Texture* background, * parchment;
};
