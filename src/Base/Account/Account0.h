#pragma once
#include "Turn.h"
#include "Price.h"
#include "Finance.h"

struct Income0
{
	Income0(Receipt receipt);

	Receipt get(void);
	
	Finance gold, yield;
};

struct Income
{
	Income(Receipt human, Receipt orc);
	
	Income0 human, orc;
};

class Account0
{
public:
	Account0(Receipt human, Receipt orc);
	
	bool canAfford(State unit);
	void addYield(void);
	
	Turn turn;
	Income income;

protected:
	Price price;
};
