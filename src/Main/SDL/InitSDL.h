#pragma once
#include <SDL.h>

class InitSDL
{
public:
	InitSDL(const char* title, Uint32 xPosition, Uint32 yPosition, Uint16 screenWidth, Uint16 screenHeight, bool isFullscreen);
	~InitSDL(void);

	SDL_Renderer* getRenderer(void);

private:
	SDL_Renderer* renderer;
	SDL_Window* window;
};
