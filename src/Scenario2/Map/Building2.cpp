#include "Building2.h"
#include "TextureManager.h"

Building2::Building2(SDL_Renderer* renderer) : Building0(renderer), destination({ 0, 0, SCALE, SCALE }), destination3x3({ 0, 0, 3 * SCALE, 3 * SCALE })
{
	loadTextures();
}

Building2::~Building2(void)
{
	destroyTextures();
}

void Building2::draw(void)
{
	destination3x3.x = 4 * SCALE;
	destination3x3.y = 4 * SCALE;
	TextureManager::draw(human.barrack, destination3x3, renderer);

	destination3x3.y += 4 * SCALE;
	TextureManager::draw(human.factory, destination3x3, renderer);

	destination3x3.y += 4 * SCALE;
	TextureManager::draw(human.barrack, destination3x3, renderer);

	destination3x3.x += 14 * SCALE;
	destination3x3.y -= 8 * SCALE;
	TextureManager::draw(orc.barrack, destination3x3, renderer);

	destination3x3.y += 4 * SCALE;
	TextureManager::draw(orc.factory, destination3x3, renderer);

	destination3x3.y += 4 * SCALE;
	TextureManager::draw(orc.barrack, destination3x3, renderer);

	destination3x3.x = 11 * SCALE;
	destination3x3.y = SCALE;
	TextureManager::draw(mine.active, destination3x3, renderer);

	destination3x3.x = 11 * SCALE;
	destination3x3.y += 7 * SCALE;
	TextureManager::draw(laboratory, destination3x3, renderer);

	destination3x3.y += 7 * SCALE;
	TextureManager::draw(mine.passive, destination3x3, renderer);

	destination.x = 10 * SCALE;
	destination.y = SCALE;
	TextureManager::draw(portal, destination, renderer);
	
	destination.x += 4 * SCALE;
	TextureManager::draw(portal, destination, renderer);

	destination.y += 16 * SCALE;
	TextureManager::draw(portal, destination, renderer);

	destination.x -= 4 * SCALE;
	TextureManager::draw(portal, destination, renderer);
}

void Building2::loadTextures(void)
{
	human.barrack = TextureManager::load("Assets/Human/Buildings/Barrack.png", renderer);
	orc.barrack = TextureManager::load("Assets/Orc/Buildings/Barrack.png", renderer);

	human.factory = TextureManager::load("Assets/Human/Buildings/Factory.png", renderer);
	orc.factory = TextureManager::load("Assets/Orc/Buildings/Factory.png", renderer);

	mine.active = TextureManager::load("Assets/General/Buildings/Mine Active.png", renderer);
	mine.passive = TextureManager::load("Assets/General/Buildings/Mine Passive.png", renderer);

	laboratory = TextureManager::load("Assets/General/Buildings/Laboratory.png", renderer);
	portal = TextureManager::load("Assets/General/Misc/Portal Winter.png", renderer);
}

void Building2::destroyTextures(void)
{
	TextureManager::destroy(human.barrack);
	TextureManager::destroy(orc.barrack);

	TextureManager::destroy(human.factory);
	TextureManager::destroy(orc.factory);

	TextureManager::destroy(mine.active);
	TextureManager::destroy(mine.passive);

	TextureManager::destroy(laboratory);
	TextureManager::destroy(portal);
}
