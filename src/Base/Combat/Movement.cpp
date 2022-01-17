#include "Movement.h"

Movement::Movement(TileInfo* tile, Coordinate* remember) : 
	tile(tile), remember(remember), attack(false)
{
}

Move* Movement::findPath(Coordinate target)
{
	Move* path = new Move[7];

	for (size_t reset = 0; reset < 7; ++reset)
	{
		path[reset] = Move::STOP;
	}
	Sint8 distance = tile->info[target.x][target.y].distance - 1;

	if (tile->info[target.x][target.y].state != State::NEUTRAL) // if it's an attack
	{
		if (tile->info[target.x][target.y - 1].distance == distance)
		{
			--target.y;
			path[distance--] = Move::ATTACK_RIGHT;
		}
		else
		{
			if (tile->info[target.x - 1][target.y].distance == distance)
			{
				--target.x;
				path[distance--] = Move::ATTACK_DOWN;
			}
			else
			{
				if (tile->info[target.x][target.y + 1].distance == distance)
				{
					++target.y;
					path[distance--] = Move::ATTACK_LEFT;
				}
				else
				{
					if (tile->info[target.x + 1][target.y].distance == distance)
					{
						++target.x;
						path[distance--] = Move::ATTACK_UP;
					}
				}
			}
		}
	}
	for (; distance >= 0; --distance)
	{
		if (tile->info[target.x][target.y - 1].distance == distance)
		{
			--target.y;
			path[distance] = Move::RIGHT;
			continue;
		}
		if (tile->info[target.x - 1][target.y].distance == distance)
		{
			--target.x;
			path[distance] = Move::DOWN;
			continue;
		}
		if (tile->info[target.x][target.y + 1].distance == distance)
		{
			++target.y;
			path[distance] = Move::LEFT;
			continue;
		}
		if (tile->info[target.x + 1][target.y].distance == distance)
		{
			++target.x;
			path[distance] = Move::UP;
		}
	}
	return path;
}

void Movement::MoveUnit(Coordinate click, Queue* queue)
{
	queue->put({ tile->info[remember->x][remember->y].state, findPath(click), *remember, click });

	tile->info[remember->x][remember->y].actionsLeft -= tile->info[click.x][click.y].distance;
	attack = false;
	
	if(tile->info[click.x][click.y].state != State::NEUTRAL)
	{
		tile->info[remember->x][remember->y].hasAttacked = true;
		attack = true;
	}
	tile->info[click.x][click.y].state = tile->info[remember->x][remember->y].state;
	tile->info[click.x][click.y].actionsLeft = tile->info[remember->x][remember->y].actionsLeft;
	tile->info[click.x][click.y].hasAttacked = tile->info[remember->x][remember->y].hasAttacked;
	
	tile->info[remember->x][remember->y].state = State::NEUTRAL;
}

bool Movement::isAttack(void)
{
	return attack;
}
