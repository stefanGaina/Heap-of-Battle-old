#include "Price.h"

Price::Price(PriceValue lastPrice)
{
	price[0] = PriceValue::empty;
	price[1] = PriceValue::infantry;
	price[2] = PriceValue::archer;
	price[3] = PriceValue::knight;
	price[4] = PriceValue::wing;
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
