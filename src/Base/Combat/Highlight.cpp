#include "Highlight.h"
#include "TextureManager.h"

Highlight::Highlight(TileInfo* tile, Coordinate* remember, SDL_Renderer* renderer) : highlight(Color::BLUE), tile(tile), remember(remember), renderer(renderer)
{
	loadTextures();
}

Highlight::~Highlight(void)
{
	destroyTextures();
}

void Highlight::draw(Color highlight, Coordinate location)
{
	if (highlight == Color::BLUE)
	{
		TextureManager::draw(human.highlight, { location.y * SCALE, location.x * SCALE, SCALE, SCALE }, renderer);
	}
	else
	{
		if (highlight == Color::RED)
		{
			TextureManager::draw(orc.highlight, { location.y * SCALE, location.x * SCALE, SCALE, SCALE }, renderer);
		}
	}
}

void Highlight::set(Color highlight)
{
	this->highlight = highlight;
}

void Highlight::path(Coordinate current, Uint8 actions, Uint8 distance)
{
	if (distance < tile->info[current.x][current.y].distance)
	{
		tile->info[current.x][current.y].distance = distance;
	}
	tile->info[current.x][current.y].highlight = highlight;

	if (actions > 0)
	{
		if (tile->info[current.x][current.y - 1].state == State::NEUTRAL)
		{
			--current.y;
			path(current, actions - 1, distance + 1);
			++current.y;
		}
		else
		{
			if (canAttack(tile->info[remember->x][remember->y].state, tile->info[current.x][current.y - 1].state) && !tile->info[remember->x][remember->y].hasAttacked)
			{

				if (distance + 1 < tile->info[current.x][current.y - 1].distance)
				{
					tile->info[current.x][current.y - 1].distance = distance + 1;
				}
				tile->info[current.x][current.y - 1].highlight = highlight;
			}
		}
		if (tile->info[current.x - 1][current.y].state == State::NEUTRAL)
		{
			--current.x;
			path(current, actions - 1, distance + 1);
			++current.x;
		}
		else
		{
			if (canAttack(tile->info[remember->x][remember->y].state, tile->info[current.x - 1][current.y].state) && !tile->info[remember->x][remember->y].hasAttacked)
			{
				if (distance + 1 < tile->info[current.x - 1][current.y].distance)
				{
					tile->info[current.x - 1][current.y].distance = distance + 1;
				}
				tile->info[current.x - 1][current.y].highlight = highlight;
			}
		}
		if (tile->info[current.x][current.y + 1].state == State::NEUTRAL)
		{
			++current.y;
			path(current, actions - 1, distance + 1);
			--current.y;
		}
		else
		{
			if (canAttack(tile->info[remember->x][remember->y].state, tile->info[current.x][current.y + 1].state) && !tile->info[remember->x][remember->y].hasAttacked)
			{
				if (distance + 1 < tile->info[current.x][current.y + 1].distance)
				{
					tile->info[current.x][current.y + 1].distance = distance + 1;
				}
				tile->info[current.x][current.y + 1].highlight = highlight;
			}
		}
		if (tile->info[current.x + 1][current.y].state == State::NEUTRAL)
		{
			++current.x;
			path(current, actions - 1, distance + 1);
			--current.x;
		}
		else
		{
			if (canAttack(tile->info[remember->x][remember->y].state, tile->info[current.x + 1][current.y].state) && !tile->info[remember->x][remember->y].hasAttacked)
			{
				if (distance + 1 < tile->info[current.x + 1][current.y].distance)
				{
					tile->info[current.x + 1][current.y].distance = distance + 1;
				}
				tile->info[current.x + 1][current.y].highlight = highlight;
			}
		}
	}
}

void Highlight::reset(Uint8 x, Uint8 y, Uint8 actions)
{
	Uint8 row, column, maxRow, maxColumn;

	//maxRow = (x + actions) < ROW ? (x + actions) : ROW - 1;
	//maxColumn = (y + actions) < COLUMN ? (x + actions) : COLUMN - 1;

	for (row = 0; row < ROW; ++row)
	{
		for (column = 0; column < COLUMN; ++column)
		{
			tile->info[row][column].highlight = Color::UNHIGHLIGHT;
			tile->info[row][column].distance = 10;
		}
	}
}

bool Highlight::canAttack(State attacker, State defender)
{
	if (defender == State::BLANK || attacker >= State::HUMAN_INFANTRY && defender >= State::HUMAN_INFANTRY || attacker <= State::ORC_INFANTRY && defender <= State::ORC_INFANTRY)
	{
		return false;
	}
	if (attacker >= State::HUMAN_INFANTRY)
	{
		if (attacker == State::HUMAN_INFANTRY && defender >= State::ORC_KNIGHT && defender <= State::ORC_INFANTRY)
		{
			return true;
		}
		if (attacker == State::HUMAN_ARCHER && defender >= State::ORC_WING && defender <= State::ORC_INFANTRY && defender != State::ORC_KNIGHT)
		{
			return true;
		}
		if (attacker == State::HUMAN_KNIGHT && defender >= State::ORC_KNIGHT && defender <= State::ORC_ARCHER)
		{
			return true;
		}
		if (attacker == State::HUMAN_WING && defender >= State::ORC_WING && defender <= State::ORC_INFANTRY && defender != State::ORC_ARCHER)
		{
			return true;
		}
	}
	if (attacker == State::ORC_INFANTRY && defender >= State::HUMAN_INFANTRY && defender <= State::HUMAN_KNIGHT)
	{
		return true;
	}
	if (attacker == State::ORC_ARCHER && defender >= State::HUMAN_INFANTRY && defender <= State::HUMAN_WING && defender != State::HUMAN_KNIGHT)
	{
		return true;
	}
	if (attacker == State::ORC_KNIGHT && defender >= State::HUMAN_ARCHER && defender <= State::HUMAN_KNIGHT)
	{
		return true;
	}
	if (attacker == State::ORC_WING && defender >= State::HUMAN_INFANTRY && defender <= State::HUMAN_WING && defender != State::HUMAN_ARCHER)
	{
		return true;
	}
	return false;
}

bool Highlight::validMovement(Color highlight)
{
	return this->highlight == highlight;
}

void Highlight::loadTextures(void)
{
	human.highlight = TextureManager::load("Assets/Human/Blue.png", renderer);
	SDL_SetTextureBlendMode(human.highlight, SDL_BLENDMODE_BLEND);
	SDL_SetTextureAlphaMod(human.highlight, 40);

	orc.highlight = TextureManager::load("Assets/Orc/Red.png", renderer);
	SDL_SetTextureBlendMode(orc.highlight, SDL_BLENDMODE_BLEND);
	SDL_SetTextureAlphaMod(orc.highlight, 40);
}

void Highlight::destroyTextures(void)
{
	TextureManager::destroy(human.highlight);
	TextureManager::destroy(orc.highlight);
}
