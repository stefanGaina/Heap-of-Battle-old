#include "InitSDL.h"
#include "Log.h"

#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include <SDL_image.h>

InitSDL::InitSDL(const char* title, Uint32 xPosition, Uint32 yPosition, Uint16 screenWidth, Uint16 screenHeight, bool isFullscreen)
{
	window = nullptr;
	renderer = nullptr;

	Uint8 flag = isFullscreen ? SDL_WINDOW_FULLSCREEN : 0;
	
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		ERROR(SDL_GetError());
	}
	if (TTF_Init() == -1)
	{
		ERROR(SDL_GetError());
	}
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
	{
		ERROR(SDL_GetError());
	}
	window = SDL_CreateWindow(title, xPosition, yPosition, screenWidth, screenHeight, flag);

	if (window == nullptr)
	{
		ERROR(SDL_GetError());
	}
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
	SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF); // white

	if (renderer == nullptr)
	{
		ERROR(SDL_GetError());
	}
	SDL_ShowCursor(SDL_DISABLE);
}

InitSDL::~InitSDL(void)
{
	SDL_DestroyWindow(window);
	window = nullptr;

	SDL_DestroyRenderer(renderer);
	renderer = nullptr;

	TTF_Quit();
	IMG_Quit();
	Mix_Quit();
	SDL_Quit();
}

SDL_Renderer* InitSDL::getRenderer(void)
{
	return renderer;
}
