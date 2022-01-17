#include "Victory.h"
#include "TextureManager.h"

Art::Art(SDL_Texture* texture) : 
	texture(texture)
{
}

Art::~Art(void)
{
	TextureManager::destroy(texture);
}

Victory::Victory(SDL_Renderer* renderer) : 
	human(TextureManager::load("Assets/Human/Icons/Victory.png", renderer)), faction(Faction::NEUTRAL), renderer(renderer),
	orc(TextureManager::load("Assets/Orc/Icons/Victory.png", renderer)), destination({ 7 * SCALE, 5 * SCALE , 11 * SCALE, 9 * SCALE })
{
}

void Victory::draw(void)
{
	switch (faction)
	{
		case Faction::NEUTRAL:
		{
			break;
		}
		case Faction::HUMAN:
		{
			TextureManager::draw(human.texture, destination, renderer);
			break;
		}
		case Faction::ORC:
		{
			TextureManager::draw(orc.texture, destination, renderer);
			break;
		}
	}
}

void Victory::set(Faction faction)
{
	this->faction = faction;
}
