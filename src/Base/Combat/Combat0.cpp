#include "Combat0.h"

Combat0::Combat0(SDL_Renderer* renderer, TileInfo* tile) : 
	animation(&this->tile, renderer), highlight(&this->tile, &remember, renderer), 
	movement(&this->tile, &remember), unit(&this->tile, renderer), engaged(Engage::NO)
{
	if (tile != nullptr)
	{
		for (size_t row = 0; row < ROW; ++row)
		{
			for (size_t column = 0; column < COLUMN; ++column)
			{
				this->tile.info[row][column].state = tile->info[row][column].state;
				this->tile.info[row][column].show = tile->info[row][column].show;
				this->tile.info[row][column].highlight = Color::UNHIGHLIGHT;
				this->tile.info[row][column].distance = 10;
				this->tile.info[row][column].actionsLeft = tile->info[row][column].actionsLeft;
				this->tile.info[row][column].hasAttacked = tile->info[row][column].hasAttacked;
				this->tile.info[row][column].notSelected = tile->info[row][column].notSelected;
			}
		}
	}
}

void Combat0::draw(void)
{
	for (Uint8 row = 1; row < ROW - 1; ++row)
	{
		for (Uint8 column = 4; column < COLUMN - 4; ++column)
		{
			highlight.draw(tile.info[row][column].highlight, { row, column });
			unit.draw({ row, column });
		}
	}
	animation.draw();
}

void Combat0::refresh(Faction turn)
{
	engaged = Engage::NO;

	unit.refresh(turn);
	highlight.reset(remember.x, remember.y, tile.info[remember.x][remember.y].actionsLeft);
}

void Combat0::engage(Engage engaged, Coordinate click)
{
	this->engaged = engaged;

	if (engaged == Engage::UNIT)
	{
		remember = click;
		tile.info[click.x][click.y].notSelected = false;
		highlight.path(click, tile.info[click.x][click.y].actionsLeft);
	}
}

bool Combat0::canMove(Coordinate click)
{
	if (highlight.validMovement(tile.info[click.x][click.y].highlight) && (remember.x != click.x || remember.y != click.y))
	{
		return true;
	}
	highlight.reset(remember.x, remember.y, tile.info[remember.x][remember.y].actionsLeft);
	return false;
}

bool Combat0::canAct(Coordinate unit)
{
	highlight.reset(unit.x, unit.y);

	if (tile.info[unit.x][unit.y].actionsLeft > 0)
	{
		highlight.path(unit, tile.info[unit.x][unit.y].actionsLeft);
		remember = unit;
		return true;
	}
	engaged = Engage::NO;
	return false;
}

State Combat0::getState(Coordinate click)
{
	return tile.info[click.x][click.y].state;
}

Uint8 Combat0::getActions(Coordinate click)
{
	return tile.info[click.x][click.y].actionsLeft;
}

bool Combat0::getAttacked(Coordinate click)
{
	return tile.info[click.x][click.y].hasAttacked;
}

Engage Combat0::getEngaged(void)
{
	return engaged;
}

TileInfo* Combat0::getTileInfo(void)
{
	return &tile;
}
