#include "Unit.h"
#include "TextureManager.h"

Unit::Unit(TileInfo* tile, SDL_Renderer* renderer) : tile(tile), renderer(renderer), destination({ 0, 0, SCALE, SCALE })
{
	human.spawn.x = 17;
	human.spawn.y = 8;

	orc.spawn.x = 1;
	orc.spawn.y = 16;

	action[0] = EMPTY;
	action[1] = INFANTRY_ACTION;
	action[2] = ARCHER_ACTION;
	action[3] = KNIGHT_ACTION;
	action[4] = WING_ACTION;
	
	loadTextures();
}

Unit::~Unit(void)
{
	destroyTextures();
}

void Unit::draw(Coordinate location)
{
	destination.x = location.y * SCALE;
	destination.y = location.x * SCALE;

	if (tile->info[location.x][location.y].notSelected)
	{
		TextureManager::draw(selectCircle, destination, renderer);
	}
	switch (tile->info[location.x][location.y].show)
	{
		case Show::human_infantry:
		{
			TextureManager::draw(human.infantry, destination, renderer);
			break;
		}
		case Show::human_archer:
		{
			TextureManager::draw(human.archer, destination, renderer);
			break;
		}
		case Show::human_knight:
		{
			TextureManager::draw(human.knight, destination, renderer);
			break;
		}
		case Show::human_wing:
		{
			TextureManager::draw(human.wing, destination, renderer);
			break;
		}
		case Show::orc_infantry:
		{
			TextureManager::draw(orc.infantry, destination, renderer);
			break;
		}
		case Show::orc_archer:
		{
			TextureManager::draw(orc.archer, destination, renderer);
			break;
		}
		case Show::orc_knight:
		{
			TextureManager::draw(orc.knight, destination, renderer);
			break;
		}
		case Show::orc_wing:
		{
			TextureManager::draw(orc.wing, destination, renderer);
		}
	}
}

void Unit::reset(Coordinate position, Uint8 actions)
{
	tile->info[position.x][position.y].actionsLeft = actions;
	tile->info[position.x][position.y].hasAttacked = false;
	tile->info[position.x][position.y].notSelected = true;
}

Uint8 index(State unit)
{
	if (unit > State::NEUTRAL)
	{
		return (Uint8)unit;
	}
	return -(Sint8)unit;
}

void Unit::refresh(Faction turn)
{
	State unit[2];

	if (turn == Faction::HUMAN)
	{
		unit[0] = State::HUMAN_INFANTRY;
		unit[1] = State::HUMAN_WING;
	}
	else
	{
		unit[0] = State::ORC_WING;
		unit[1] = State::ORC_INFANTRY;
	}
	for (Uint8 row = 1; row < ROW - 1; ++row)
	{
		for (Uint8 column = 4; column < COLUMN - 4; ++column)
		{
			if (tile->info[row][column].state >= unit[0] && tile->info[row][column].state <= unit[1])
			{
				reset({ row, column }, action[index(tile->info[row][column].state)]);
			}
			else
			{
				tile->info[row][column].notSelected = false;
			}
		}
	}
}

bool Unit::humanSpawnAvailable(void)
{
	return tile->info[human.spawn.x][human.spawn.y].state == State::NEUTRAL;
}

bool Unit::orcSpawnAvailable(void)
{
	return tile->info[orc.spawn.x][orc.spawn.y].state == State::NEUTRAL;
}

void Unit::train(State unit, Coordinate spawn)
{
	tile->info[spawn.x][spawn.y].state = unit;
	tile->info[spawn.x][spawn.y].show = (Show)unit;

	reset(spawn, action[index(unit)] + 1);

	tile->info[spawn.x][spawn.y].notSelected = false;
}

void Unit::boostSpawns(void)
{
	++tile->info[human.spawn.x][human.spawn.y].actionsLeft;
	++tile->info[orc.spawn.x][orc.spawn.y].actionsLeft;
}

Uint8 Unit::getAction(Uint8 index)
{
	return action[index];
}

void Unit::loadTextures(void)
{
	selectCircle = TextureManager::load("Assets/General/Green.png", renderer);

	human.infantry = TextureManager::load("Assets/Human/Units/Infantry/Figure.png", renderer);
	human.archer = TextureManager::load("Assets/Human/Units/Archer/Figure.png", renderer);
	human.knight = TextureManager::load("Assets/Human/Units/Knight/Figure.png", renderer);
	human.wing = TextureManager::load("Assets/Human/Units/Wing/Figure.png", renderer);

	orc.infantry = TextureManager::load("Assets/Orc/Units/Infantry/Figure.png", renderer);
	orc.archer = TextureManager::load("Assets/Orc/Units/Archer/Figure.png", renderer);
	orc.knight = TextureManager::load("Assets/Orc/Units/Knight/Figure.png", renderer);
	orc.wing = TextureManager::load("Assets/Orc/Units/Wing/Figure.png", renderer);
}

void Unit::destroyTextures(void)
{
	TextureManager::destroy(selectCircle);

	TextureManager::destroy(human.infantry);
	TextureManager::destroy(human.archer);
	TextureManager::destroy(human.knight);
	TextureManager::destroy(human.wing);

	TextureManager::destroy(orc.infantry);
	TextureManager::destroy(orc.archer);
	TextureManager::destroy(orc.knight);
	TextureManager::destroy(orc.wing);
}
