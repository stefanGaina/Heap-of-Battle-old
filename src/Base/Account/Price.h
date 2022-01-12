#pragma once
#include "Language.h"

enum class PriceValue
{
	empty = 0,
	infantry = 5,
	archer = 10,
	knight = 20,
	wing = 30,
	vamp = 40,
};

class Price
{
public:
	Price(PriceValue lastPrice);
	
	Uint8 get(State state);

private:
	PriceValue price[6];
};
