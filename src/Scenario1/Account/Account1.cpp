#include "Account1.h"

Objective::Objective(Faction faction) : 
	altar(faction), farm(faction), tower(faction)
{
}

Account1::Account1(Receipt human, Receipt orc) : 
	Account0(human, orc), human(Faction::HUMAN), orc(Faction::ORC), bonus(Faction::NEUTRAL)
{
}

void Account1::altars(Flag flag)
{
	human.altar.update(flag.human);
	orc.altar.update(flag.orc);

	switch (bonus)
	{
		case Faction::NEUTRAL:
		{
			if (human.altar.get() == orc.altar.get())
			{
				if (human.altar.get() == Faction::HUMAN)
				{
					income.orc.yield.update(-15);
					bonus = Faction::HUMAN;
				}
				else
				{
					income.human.yield.update(-15);
					bonus = Faction::ORC;
				}
			}
			break;
		}
		case Faction::HUMAN:
		{
			if (human.altar.get() != orc.altar.get())
			{
				income.orc.yield.update(15);
				bonus = Faction::NEUTRAL;
			}
			break;
		}
		case Faction::ORC:
		{
			if (human.altar.get() != orc.altar.get())
			{
				income.human.yield.update(15);
				bonus = Faction::NEUTRAL;
			}
		}
	}
}

void Account1::farms(Flag flag)
{
	human.farm.update(flag.human);
	orc.farm.update(flag.orc);
}

void Account1::towers(Flag flag)
{
	human.tower.update(flag.human);
	orc.tower.update(flag.orc);
}

void Account1::vamp(Faction faction)
{
	if (faction == Faction::HUMAN)
	{
		income.human.yield.update(10);
		human.vamp.set();
	}
	if (faction == Faction::ORC)
	{
		income.orc.yield.update(10);
		orc.vamp.set();
	}
}
