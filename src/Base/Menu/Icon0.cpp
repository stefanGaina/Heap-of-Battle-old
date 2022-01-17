#include "Icon0.h"
#include "TextureManager.h"

Icon0::Icon0(SDL_Renderer* renderer, SDL_Texture* humanLastIcon, SDL_Texture* orcLastIcon) : 
	renderer(renderer), destination({ 0, 0, SCALE, SCALE })
{
	human.infantry = TextureManager::load("Assets/Human/Units/Infantry/Icons/Figure.png", renderer);
	human.archer = TextureManager::load("Assets/Human//Units/Archer/Icons/Figure.png", renderer);
	human.knight = TextureManager::load("Assets/Human/Units/Knight/Icons/Figure.png", renderer);
	human.wing = TextureManager::load("Assets/Human/Units/Wing/Icons/Figure.png", renderer);

	human.infantryAttack = TextureManager::load("Assets/Human/Units/Infantry/Icons/Attack.png", renderer);
	human.archerAttack = TextureManager::load("Assets/Human/Units/Archer/Icons/Attack.png", renderer);
	human.knightAttack = TextureManager::load("Assets/Human/Units/Knight/Icons/Attack.png", renderer);
	human.wingAttack = TextureManager::load("Assets/Human/Units/Wing/Icons/Attack.png", renderer);

	orc.infantry = TextureManager::load("Assets/Orc/Units/Infantry/Icons/Figure.png", renderer);
	orc.archer = TextureManager::load("Assets/Orc/Units/Archer/Icons/Figure.png", renderer);
	orc.knight = TextureManager::load("Assets/Orc/Units/Knight/Icons/Figure.png", renderer);
	orc.wing = TextureManager::load("Assets/Orc/Units/Wing/Icons/Figure.png", renderer);

	orc.infantryAttack = TextureManager::load("Assets/Orc/Units/Infantry/Icons/Attack.png", renderer);
	orc.archerAttack = TextureManager::load("Assets/Orc/Units/Archer/Icons/Attack.png", renderer);
	orc.knightAttack = TextureManager::load("Assets/Orc/Units/Knight/Icons/Attack.png", renderer);
	orc.wingAttack = TextureManager::load("Assets/Orc/Units/Wing/Icons/Attack.png", renderer);

	human.lastIcon = humanLastIcon;
	orc.lastIcon = orcLastIcon;
	human.pass = TextureManager::load("Assets/Human/Icons/Pass Turn.png", renderer);
	orc.pass = TextureManager::load("Assets/Orc/Icons/Pass Turn.png", renderer);

	pause = TextureManager::load("Assets/General/Icons/Pause.png", renderer);
}

Icon0::~Icon0(void)
{
	TextureManager::destroy(human.infantry);
	TextureManager::destroy(human.archer);
	TextureManager::destroy(human.knight);
	TextureManager::destroy(human.wing);

	TextureManager::destroy(human.infantryAttack);
	TextureManager::destroy(human.archerAttack);
	TextureManager::destroy(human.knightAttack);
	TextureManager::destroy(human.wingAttack);

	TextureManager::destroy(orc.infantry);
	TextureManager::destroy(orc.archer);
	TextureManager::destroy(orc.knight);
	TextureManager::destroy(orc.wing);

	TextureManager::destroy(orc.infantryAttack);
	TextureManager::destroy(orc.archerAttack);
	TextureManager::destroy(orc.knightAttack);
	TextureManager::destroy(orc.wingAttack);

	TextureManager::destroy(human.lastIcon);
	TextureManager::destroy(orc.lastIcon);
	TextureManager::destroy(human.pass);
	TextureManager::destroy(orc.pass);

	TextureManager::destroy(pause);
}

void Icon0::humanAlways(void)
{
	destination.x = SCALE;
	destination.y = 15 * SCALE;
	TextureManager::draw(pause, destination, renderer);

	destination.y += 2 * SCALE;
	TextureManager::draw(human.pass, destination, renderer);
}

void Icon0::orcAlways(void)
{
	destination.x = 23 * SCALE;
	destination.y = 15 * SCALE;
	TextureManager::draw(pause, destination, renderer);

	destination.y += 2 * SCALE;
	TextureManager::draw(orc.pass, destination, renderer);
}

void Icon0::humanKeep(void)
{
	destination.x = SCALE;
	destination.y = 4 * SCALE;
	TextureManager::draw(human.infantry, destination, renderer);

	destination.y += 2 * SCALE;
	TextureManager::draw(human.archer, destination, renderer);

	destination.y += 2 * SCALE;
	TextureManager::draw(human.knight, destination, renderer);

	destination.y += 2 * SCALE;
	TextureManager::draw(human.wing, destination, renderer);

	destination.y += 2 * SCALE;
	TextureManager::draw(human.lastIcon, destination, renderer);
}

void Icon0::orcKeep(void)
{
	destination.x = 23 * SCALE;
	destination.y = 4 * SCALE;
	TextureManager::draw(orc.infantry, destination, renderer);

	destination.y += 2 * SCALE;
	TextureManager::draw(orc.archer, destination, renderer);

	destination.y += 2 * SCALE;
	TextureManager::draw(orc.knight, destination, renderer);

	destination.y += 2 * SCALE;
	TextureManager::draw(orc.wing, destination, renderer);

	destination.y += 2 * SCALE;
	TextureManager::draw(orc.lastIcon, destination, renderer);
}

void Icon0::humanUnit(State unit, bool hasAttacked)
{
	switch (unit)
	{
		case State::HUMAN_INFANTRY:
		{
			humanUnit(human.infantry);
			unitAttack(human.infantryAttack, hasAttacked);
			break;
		}
		case State::HUMAN_ARCHER:
		{
			humanUnit(human.archer);
			unitAttack(human.archerAttack, hasAttacked);
			break;
		}
		case State::HUMAN_KNIGHT:
		{
			humanUnit(human.knight);
			unitAttack(human.knightAttack, hasAttacked);
			break;
		}
		case State::HUMAN_WING:
		{
			humanUnit(human.wing);
			unitAttack(human.wingAttack, hasAttacked);
		}
	}
}

void Icon0::orcUnit(State unit, bool hasAttacked)
{
	switch (unit)
	{
		case State::ORC_INFANTRY:
		{
			orcUnit(orc.infantry);
			unitAttack(orc.infantryAttack, hasAttacked);
			break;
		}
		case State::ORC_ARCHER:
		{
			orcUnit(orc.archer);
			unitAttack(orc.archerAttack, hasAttacked);
			break;
		}
		case State::ORC_KNIGHT:
		{
			orcUnit(orc.knight);
			unitAttack(orc.knightAttack, hasAttacked);
			break;
		}
		case State::ORC_WING:
		{
			orcUnit(orc.wing);
			unitAttack(orc.wingAttack, hasAttacked);
		}
	}
}

void Icon0::humanUnit(SDL_Texture* figure)
{
	destination.x = SCALE;
	destination.y = 4 * SCALE;
	TextureManager::draw(figure, destination, renderer);
}

void Icon0::orcUnit(SDL_Texture* figure)
{
	destination.x = 23 * SCALE;
	destination.y = 4 * SCALE;
	TextureManager::draw(figure, destination, renderer);
}

void Icon0::unitAttack(SDL_Texture* attack, bool hasAttacked)
{
	if (!hasAttacked)
	{
		destination.y += 2 * SCALE;
		TextureManager::draw(attack, destination, renderer);
	}
}
