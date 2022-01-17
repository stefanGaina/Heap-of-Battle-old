#include "Frame.h"
#include "TextureManager.h"

Frame::Frame(SDL_Renderer* renderer) : 
	renderer(renderer), destination({ 0, 0, 3 * SCALE + 7, SCALE + 15 }),
	texture(TextureManager::load("Assets/General/Icons/Frame.png", renderer))
{
}

Frame::~Frame(void)
{
	TextureManager::destroy(texture);
}

void Frame::humanAlways(void)
{
	destination.x = SCALE - 5;
	destination.y = SCALE - 7;
	TextureManager::draw(texture, destination, renderer);

	destination.y += SCALE;
	TextureManager::draw(texture, destination, renderer);

	destination.y += 13 * SCALE;
	TextureManager::draw(texture, destination, renderer);

	destination.y += 2 * SCALE;
	TextureManager::draw(texture, destination, renderer);
}

void Frame::orcAlways(void)
{
	destination.x = 21 * SCALE - 5;
	destination.y = SCALE - 7;
	TextureManager::draw(texture, destination, renderer);

	destination.y += SCALE;
	TextureManager::draw(texture, destination, renderer);

	destination.y += 13 * SCALE;
	TextureManager::draw(texture, destination, renderer);

	destination.y += 2 * SCALE;
	TextureManager::draw(texture, destination, renderer);
}

void Frame::humanStandard(void)
{
	destination.x = SCALE - 5;
	destination.y = 4 * SCALE - 7;
	TextureManager::draw(texture, destination, renderer);
}

void Frame::orcStandard(void)
{
	destination.x = 21 * SCALE - 5;
	destination.y = 4 * SCALE - 7;
	TextureManager::draw(texture, destination, renderer);
}

void Frame::humanKeep(void)
{
	for (destination.y = 6 * SCALE - 7; destination.y <= 12 * SCALE - 7; destination.y += 2 * SCALE)
	{
		TextureManager::draw(texture, destination, renderer);
	}
}

void Frame::orcKeep(void)
{
	for (destination.y = 6 * SCALE - 7; destination.y <= 12 * SCALE - 7; destination.y += 2 * SCALE)
	{
		TextureManager::draw(texture, destination, renderer);
	}
}

void Frame::humanAttack(bool hasAttacked)
{
	if (!hasAttacked)
	{
		destination.x = SCALE - 2;
		destination.y = 6 * SCALE - 8;
		destination.w = SCALE + 5;
		TextureManager::draw(texture, destination, renderer);
		destination.w = 3 * SCALE + 7;
	}
}

void Frame::orcAttack(bool hasAttacked)
{
	if (!hasAttacked)
	{
		destination.x = 23 * SCALE - 2;
		destination.y = 6 * SCALE - 8;
		destination.w = SCALE + 5;
		TextureManager::draw(texture, destination, renderer);
		destination.w = 3 * SCALE + 7;
	}
}
