#include "Corpse1.h"
#include "TextureManager.h"

Corpse1::Corpse1(SDL_Renderer* renderer) : Corpse0(renderer)
{
}

void Corpse1::draw(void)
{
	destination.x = 6 * SCALE;
	destination.y = 4 * SCALE;
	TextureManager::draw(texture, destination, renderer);

	destination.x += 2 * SCALE;
	destination.y += SCALE;
	TextureManager::draw(texture, destination, renderer);

	destination.x -= 3 * SCALE;
	destination.y += 2 * SCALE;
	TextureManager::draw(texture, destination, renderer);

	destination.x = 19 * SCALE;
	destination.y = 11 * SCALE;
	TextureManager::draw(texture, destination, renderer);

	destination.x -= SCALE;
	destination.y += 3 * SCALE;
	TextureManager::draw(texture, destination, renderer);

	destination.x -= 2 * SCALE;
	destination.y -= SCALE;
	TextureManager::draw(texture, destination, renderer);
}
