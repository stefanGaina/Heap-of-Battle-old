#include "Corpse0.h"
#include "TextureManager.h"

Corpse0::Corpse0(SDL_Renderer* renderer) : renderer(renderer), destination({ 0, 0, SCALE, SCALE })
{
	texture = TextureManager::load("Assets/General/Misc/Corpse.png", renderer);
}

Corpse0::~Corpse0(void)
{
	TextureManager::destroy(texture);
}
