#pragma once
#include "Write0.h"

struct VampWrite
{
	VampWrite(SDL_Texture* vamp);

	SDL_Texture* vamp;
};

class Write1 : public Write0
{
public:
	Write1(SDL_Renderer* renderer);

	void humanVamp(bool vamped);
	void orcVamp(bool vamped);

private:
	VampWrite human, orc;
};
