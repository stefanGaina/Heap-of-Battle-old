#include "Building1.h"
#include "TextureManager.h"

Building1::Building1(SDL_Renderer* renderer) : Building0(renderer), destination({ 0, 0, SCALE, SCALE }), destination2x2({ 0, 0, 2 * SCALE, 2 * SCALE }), destination3x3({ 0, 0, 3 * SCALE, 3 * SCALE }),
												destination4x4({ 0, 0, 4 * SCALE, 4 * SCALE }), destinationBridge({ 10 * SCALE, 0, 5 * SCALE, 2 * SCALE })
{
	loadTextures();

	initializeCurrent();
}

Building1::~Building1(void)
{
	destroyTextures();
}

void Building1::draw(void)
{
	destination4x4.x = 4 * SCALE;
	destination4x4.y = 14 * SCALE;
	TextureManager::draw(human.current.keep, destination4x4, renderer);

	destination4x4.x = 17 * SCALE;
	destination4x4.y = SCALE;
	TextureManager::draw(orc.current.keep, destination4x4, renderer);

	destination3x3.x = 7 * SCALE;
	destination3x3.y = 8 * SCALE;
	TextureManager::draw(human.current.altar, destination3x3, renderer);

	destination3x3.x += 8 * SCALE;
	TextureManager::draw(orc.current.altar, destination3x3, renderer);

	destination2x2.x = 15 * SCALE;
	destination2x2.y = 16 * SCALE;
	TextureManager::draw(human.current.farm, destination2x2, renderer);

	destination2x2.x = 8 * SCALE;
	destination2x2.y = SCALE;
	TextureManager::draw(orc.current.farm, destination2x2, renderer);

	destination2x2.x = 4 * SCALE;
	destination2x2.y = 9 * SCALE;
	TextureManager::draw(human.current.tower, destination2x2, renderer);

	destination2x2.x = 19 * SCALE;
	destination2x2.y -= SCALE;
	TextureManager::draw(orc.current.tower, destination2x2, renderer);

	destination.x = 4 * SCALE;
	destination.y = SCALE;
	TextureManager::draw(portal, destination, renderer);

	destination.y = 13 * SCALE;
	TextureManager::draw(portal, destination, renderer);

	destination.x = 20 * SCALE;
	destination.y = 17 * SCALE;
	TextureManager::draw(portal, destination, renderer);

	destination.y = 5 * SCALE;
	TextureManager::draw(portal, destination, renderer);

	destinationBridge.y = 3 * SCALE - 9; // -9 for alignment
	TextureManager::draw(bridge, destinationBridge, renderer);

	destinationBridge.y += SCALE;
	TextureManager::draw(bridge, destinationBridge, renderer);

	destinationBridge.y = 14 * SCALE - 9;
	TextureManager::draw(bridge, destinationBridge, renderer);

	destinationBridge.y += SCALE;
	TextureManager::draw(bridge, destinationBridge, renderer);
}

void Building1::updateAltars(Flag flag)
{
	if (flag.human == Faction::HUMAN)
	{
		human.current.altar = human.altar.activated;
	}
	else
	{
		if (flag.human == Faction::ORC)
		{
			human.current.altar = human.altar.deactivated;
		}
	}
	if (flag.orc == Faction::ORC)
	{
		orc.current.altar = orc.altar.activated;
	}
	else
	{
		if (flag.orc == Faction::HUMAN)
		{
			orc.current.altar = orc.altar.deactivated;
		}
	}
}

void Building1::updateFarms(Flag flag)
{
	updateFarm(human.current.farm, flag.human);
	updateFarm(orc.current.farm, flag.orc);
}

void Building1::updateTowers(Flag flag)
{
	updateTower(human.current.tower, flag.human);
	updateTower(orc.current.tower, flag.orc);
}

void Building1::updateFarm(SDL_Texture*& farm, Faction faction)
{
	if (faction == Faction::HUMAN)
	{
		farm = human.farm;
	}
	if (faction == Faction::ORC)
	{
		farm = orc.farm;
	}
}

void Building1::updateTower(SDL_Texture*& tower, Faction faction)
{
	if (faction == Faction::HUMAN)
	{
		tower = human.tower;
	}
	if (faction == Faction::ORC)
	{
		tower = orc.tower;
	}
}

void Building1::vampHumanKeep(void)
{
	human.current.keep = human.keep.vamped;
}

void Building1::vampOrcKeep(void)
{
	orc.current.keep = orc.keep.vamped;
}

void Building1::victory(Faction faction)
{
	switch (faction)
	{
		case Faction::HUMAN:
		{
			orc.current.keep = orc.keep.destroyed;
			break;
		}
		case Faction::ORC:
		{
			human.current.keep = human.keep.destroyed;
		}
	}
}

void Building1::loadTextures(void)
{
	human.keep.stock = TextureManager::load("Assets/Human/Buildings/Keep.png", renderer);
	human.keep.vamped = TextureManager::load("Assets/Human/Buildings/Keep Vamped.png", renderer);
	human.keep.destroyed = TextureManager::load("Assets/Human/Buildings/Keep Destroyed.png", renderer);
	orc.keep.stock = TextureManager::load("Assets/Orc/Buildings/Keep.png", renderer);
	orc.keep.vamped = TextureManager::load("Assets/Orc/Buildings/Keep Vamped.png", renderer);
	orc.keep.destroyed = TextureManager::load("Assets/Orc/Buildings/Keep Destroyed.png", renderer);

	human.altar.activated = TextureManager::load("Assets/Human/Buildings/Altar Activated.png", renderer);
	human.altar.deactivated = TextureManager::load("Assets/Human/Buildings/Altar Deactivated.png", renderer);
	orc.altar.activated = TextureManager::load("Assets/Orc/Buildings/Altar Activated.png", renderer);
	orc.altar.deactivated = TextureManager::load("Assets/Orc/Buildings/Altar Deactivated.png", renderer);

	human.farm = TextureManager::load("Assets/Human/Buildings/Farm.png", renderer);
	human.tower = TextureManager::load("Assets/Human/Buildings/Tower.png", renderer);
	orc.farm = TextureManager::load("Assets/Orc/Buildings/Farm.png", renderer);
	orc.tower = TextureManager::load("Assets/Orc/Buildings/Tower.png", renderer);

	bridge = TextureManager::load("Assets/General/Misc/Bridge.png", renderer);
	portal = TextureManager::load("Assets/General/Misc/Portal Summer.png", renderer);
}

void Building1::destroyTextures(void)
{
	TextureManager::destroy(human.keep.stock);
	TextureManager::destroy(human.keep.vamped);
	TextureManager::destroy(human.keep.destroyed);
	TextureManager::destroy(orc.keep.stock);
	TextureManager::destroy(orc.keep.vamped);
	TextureManager::destroy(orc.keep.destroyed);

	TextureManager::destroy(human.altar.activated);
	TextureManager::destroy(human.altar.deactivated);
	TextureManager::destroy(orc.altar.activated);
	TextureManager::destroy(orc.altar.deactivated);

	TextureManager::destroy(human.farm);
	TextureManager::destroy(human.tower);
	TextureManager::destroy(orc.farm);
	TextureManager::destroy(orc.tower);

	TextureManager::destroy(bridge);
	TextureManager::destroy(portal);
}

void Building1::initializeCurrent(void)
{
	human.current.keep = human.keep.stock;
	human.current.altar = human.altar.activated;
	human.current.farm = human.farm;
	human.current.tower = human.tower;

	orc.current.keep = orc.keep.stock;
	orc.current.altar = orc.altar.activated;
	orc.current.farm = orc.farm;
	orc.current.tower = orc.tower;
}
