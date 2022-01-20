#include "Account0.h"

Income0::Income0(Receipt receipt) : 
	gold(receipt.gold), yield(receipt.yield)
{
}

Receipt Income0::get(void)
{
	return { gold.get(), yield.get() };
}

Income::Income(Receipt human, Receipt orc) : 
	human(human), orc(orc)
{
}

Account0::Account0(Receipt human, Receipt orc, Uint8 turn) : 
	price(PriceValue::VAMP), income(human, orc), turn(turn)
{
}

bool Account0::canAfford(State unit)
{
	Uint8 price = this->price.get(unit);

	if (unit > State::NEUTRAL)
	{
		if (income.human.gold.get() >= price)
		{
			income.human.gold.update(-price);
			return true;
		}
	}
	else if (income.orc.gold.get() >= price)
	{
		income.orc.gold.update(-price);
		return true;
	}
	return false;
}

void Account0::addYield(void)
{
	if (turn.isHuman())
	{
		income.human.gold.update(income.human.yield.get());
	}
	else
	{
		income.orc.gold.update(income.orc.yield.get());
	}
}
