#include "Pause.h"
#include "TextureManager.h"

Pause::Pause(SDL_Renderer* renderer) : Enable(false), victory(renderer), renderer(renderer)
{
	loadTextures();
}

Pause::~Pause(void)
{
	destroyTextures();
}

void Pause::draw(void)
{
	if (isEnabled())
	{
		TextureManager::draw(background, { 0, 0, COLUMN * SCALE, ROW * SCALE }, renderer);
		TextureManager::draw(parchment, { 6 * SCALE, 3 * SCALE, 13 * SCALE, 13 * SCALE }, renderer);
	}
}

void Pause::loadTextures(void)
{
	background = TextureManager::load("Assets/General/Pause/Black.png", renderer);
	SDL_SetTextureBlendMode(background, SDL_BLENDMODE_BLEND);
	SDL_SetTextureAlphaMod(background, 100);

	parchment = TextureManager::load("Assets/General/Pause/Parchment.png", renderer);
}

void Pause::destroyTextures(void)
{
	TextureManager::destroy(background);
	TextureManager::destroy(parchment);
}
