#pragma once
#include "Grid0.h"

class Grid1 : public Grid0
{
public:
	Grid1(SDL_Renderer* renderer);
	
	void draw(void);

private:
	void horizontalBlack(void);
	void verticalBlack(void);

	void horizontalGray(void);
	void verticalGray(void);
};
