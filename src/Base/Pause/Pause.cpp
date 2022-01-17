#include "Pause.h"
#include "TextureManager.h"

Pause::Pause(SDL_Renderer* renderer) : 
	background(TextureManager::load("Assets/General/Pause/Black.png", renderer)),
	parchment(TextureManager::load("Assets/General/Pause/Parchment.png", renderer)),
	Enable(false), victory(renderer), renderer(renderer)
{
	SDL_SetTextureBlendMode(background, SDL_BLENDMODE_BLEND);
	SDL_SetTextureAlphaMod(background, 100);
}

Pause::~Pause(void)
{
	TextureManager::destroy(background);
	TextureManager::destroy(parchment);
}

void Pause::draw(void)
{
	if (isEnabled())
	{
		TextureManager::draw(background, { 0, 0, COLUMN * SCALE, ROW * SCALE }, renderer);
		TextureManager::draw(parchment, { 6 * SCALE, 3 * SCALE, 13 * SCALE, 13 * SCALE }, renderer);
	}
}
