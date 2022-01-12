#pragma once
#include "Grid0.h"

class Grid2 : public Grid0
{
public:
	Grid2(SDL_Renderer* renderer);

	void draw(void);

private:
	void horizontalBlack(void);
	void verticalBlack(void);

	void horizontalGray(void);
	void verticalGray(void);
};
