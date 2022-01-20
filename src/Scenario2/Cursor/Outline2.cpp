#include "Outline2.h"

Outline2::Outline2(SDL_Renderer* renderer) : 
	Outline0(renderer)
{
}

void Outline2::draw(void)
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
		}
	}
}
