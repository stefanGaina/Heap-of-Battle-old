#include "Outline1.h"

Outline1::Outline1(SDL_Renderer* renderer) : Outline0(renderer)
{
}

void Outline1::draw(void)
{
	if (isEnabled())
	{
		switch (type)
		{
			case State::NEUTRAL:
			{
				square(hover, 1);
				break;
			}
			case State::HUMAN_KEEP:
			{
				square({ 4, 14 }, 4);
				break;
			}
			case State::ORC_KEEP:
			{
				square({ 17, 1 }, 4);
				break;
			}
			case State::HUMAN_ALTAR:
			{
				square({ 7, 8 }, 3);
				break;
			}
			case State::ORC_ALTAR:
			{
				square({ 15, 8 }, 3);
				break;
			}
			case State::HUMAN_FARM:
			{
				square({ 15, 16 }, 2);
				break;
			}
			case State::ORC_FARM:
			{
				square({ 8, 1 }, 2);
				break;
			}
			case State::HUMAN_TOWER:
			{
				square({ 4, 9 }, 2);
				break;
			}
			case State::ORC_TOWER:
			{
				square({ 19, 8 }, 2);
				break;
			}
		}
	}
}
