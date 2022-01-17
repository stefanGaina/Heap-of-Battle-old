#include "Menu1.h"

Menu1::Menu1(SDL_Renderer* renderer) : 
	Menu0(renderer), icon(renderer), write(renderer)
{
}

void Menu1::draw(Receipt human, Receipt orc, Faction turn)
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
				case State::HUMAN_KEEP:
				{
					frame.humanKeep();
					write.humanKeep();
					write.humanVamp(this->human.vamped);
					icon.humanKeep();
					break;
				}
				case State::HUMAN_ALTAR:
				{
					write.humanUnit(1);
					break;
				}
				case State::HUMAN_FARM:
				{
					write.humanUnit(2);
					break;
				}
				case State::HUMAN_TOWER:
				{
					write.humanUnit(3);
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
				case State::ORC_KEEP:
				{
					frame.orcKeep();
					write.orcKeep();
					write.orcVamp(this->human.vamped);
					icon.orcKeep();
					break;
				}
				case State::ORC_ALTAR:
				{
					write.orcUnit(1);
					break;
				}
				case State::ORC_FARM:
				{
					write.orcUnit(2);
					break;
				}
				case State::ORC_TOWER:
				{
					write.orcUnit(3);
					break;
				}
				default:
				{
					frame.orcAttack(hasAttacked);
					write.orcUnit(actionsLeft);
					icon.orcUnit(type, hasAttacked);
				}
			}
		}
	}
}

void Menu1::set(State state, Uint8 actionsLeft, bool hasAttacked, bool vampState)
{
	type = state;

	if (state == State::HUMAN_KEEP)
	{
		human.vamped = vampState;
	}
	else if (state == State::ORC_KEEP)
	{
		orc.vamped = vampState;
	}
	else
	{
		remember(actionsLeft, hasAttacked);
	}
}
