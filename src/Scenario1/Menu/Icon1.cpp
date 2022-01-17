#include "Icon1.h"
#include "TextureManager.h"

Icon1::Icon1(SDL_Renderer* renderer) :
	Icon0(renderer, TextureManager::load("assets/Human/Icons/Vamp.png", renderer),
		TextureManager::load("assets/Orc/Icons/Vamp.png", renderer))
{
}
