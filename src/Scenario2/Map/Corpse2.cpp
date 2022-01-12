#include "Corpse2.h"
#include "TextureManager.h"

Corpse2::Corpse2(SDL_Renderer* renderer) : Corpse0(renderer)
{
}

void Corpse2::draw(void)
{
	destination.x = 9 * SCALE;
	destination.y = 5 * SCALE;
	TextureManager::draw(texture, destination, renderer);

	destination.x += SCALE;
	destination.y += 9 * SCALE;
	TextureManager::draw(texture, destination, renderer);

	destination.x += 2 * SCALE;
	destination.y -= 2 * SCALE;
	TextureManager::draw(texture, destination, renderer);

	destination.y -= 6 * SCALE;
	TextureManager::draw(texture, destination, renderer);

	destination.x += 2 * SCALE;
	destination.y -= 2 * SCALE;
	TextureManager::draw(texture, destination, renderer);

	destination.x += SCALE;
	destination.y += 9 * SCALE;
	TextureManager::draw(texture, destination, renderer);
}
