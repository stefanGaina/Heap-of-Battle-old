#include "Menu2.h"

Menu2::Menu2(SDL_Renderer* renderer) : 
	Menu0(renderer), icon(renderer), write(renderer)
{
}

void Menu2::draw(Receipt human, Receipt orc, Faction turn)
{
	if (turn == Faction::HUMAN)
	{
		frame.humanAlways();
		write.humanAlways(human, orc);
		icon.humanAlways();

		if (type != State::NEUTRAL)
		{
			frame.humanStandard();

			switch (type)
			{
				case State::HUMAN_KEEP_1:
				{
					frame.humanKeep();
					write.humanKeep();
					icon.humanKeep();
					break;
				}
				case State::HUMAN_KEEP_2:
				{
					frame.humanKeep();
					write.humanKeep();
					icon.humanKeep();
					break;
				}
				default:
				{
					frame.humanAttack(hasAttacked);
					write.humanUnit(actionsLeft);
					icon.humanUnit(type, hasAttacked);
				}
			}
		}
	}
	else
	{
		frame.orcAlways();
		write.orcAlways(human, orc);
		icon.orcAlways();

		if (type != State::NEUTRAL)
		{
			frame.orcStandard();

			switch (type)
			{

			}
		}
	}
}

void Menu2::set(State state, Uint8 actionsLeft, bool hasAttacked)
{
	type = state;
	remember(actionsLeft, hasAttacked);
}
