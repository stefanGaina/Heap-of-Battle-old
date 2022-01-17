#pragma once
#include "Language.h"

enum class PriceValue
{
	EMPTY = 0,
	INFANTRY = 5,
	ARCHER = 10,
	KNIGHT = 20,
	WING = 30,
	VAMP = 40,
};

class Price
{
public:
	Price(PriceValue lastPrice);
	
	Uint8 get(State state);

private:
	PriceValue price[6];
};
