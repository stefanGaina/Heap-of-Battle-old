#pragma once
#include "Building0.h"

class Building3 : private Building0
{
public:
	Building3(SDL_Renderer* renderer);
	~Building3(void);

	void draw(void);

};