#include "Price.h"

Price::Price(PriceValue lastPrice)
{
	price[0] = PriceValue::EMPTY;
	price[1] = PriceValue::INFANTRY;
	price[2] = PriceValue::ARCHER;
	price[3] = PriceValue::KNIGHT;
	price[4] = PriceValue::WING;
	price[5] = lastPrice;
}

Uint8 Price::get(State state)
{
	if (state > State::NEUTRAL)
	{
		return (Uint8)price[(Uint8)state];
	}
	return (Uint8)price[-(Sint8)state];
}
