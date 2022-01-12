#include "Game0.h"

Game0::Game0(SDL_Renderer* renderer, const Mouse& mouse) 
	: cursor(renderer), pause(renderer), mouse(mouse), renderer(renderer)
{
}
