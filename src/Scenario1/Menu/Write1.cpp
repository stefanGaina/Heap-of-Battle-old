#include "Write1.h"
#include "TextureManager.h"

VampWrite::VampWrite(SDL_Texture* vamp) :
	vamp(vamp)
{
}

Write1::Write1(SDL_Renderer* renderer) :
	Write0(renderer, 40), 
	human(TextureManager::createText(font, "Vamp", color.blue, renderer)),
	orc(TextureManager::createText(font, "Vamp", color.red, renderer))
{
}

void Write1::humanVamp(bool vamped)
{
	if (!vamped)
	{
		destination.x = 2 * SCALE;
		destination.y = 12 * SCALE;
		TextureManager::draw(human.vamp, destination, renderer);
	}
}

void Write1::orcVamp(bool vamped)
{
	if (!vamped)
	{
		destination.x = 22 * SCALE;
		destination.y = 12 * SCALE;
		TextureManager::draw(orc.vamp, destination, renderer);
	}
}
