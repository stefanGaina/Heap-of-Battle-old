#include "Building3.h"
#include "TextureManager.h"

Building3::Building3(SDL_Renderer* renderer) :
	Building0(renderer)
{
	human.keep = TextureManager::load("assets/Human/Buildings/Keep.png", renderer);
	orc.keep = TextureManager::load("assets/Orc/Buildings/Keep.png", renderer);
}

Building3::~Building3(void)
{

}

void Building3::draw(void)
{
	TextureManager::draw(human.keep, { 5 * SCALE, 10 * SCALE, 4 * SCALE, 4 * SCALE }, renderer);
	TextureManager::draw(orc.keep, { 15 * SCALE, 10 * SCALE, 4 * SCALE, 4 * SCALE }, renderer);
}
