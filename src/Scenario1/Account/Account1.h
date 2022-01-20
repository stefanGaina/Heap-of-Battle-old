#pragma once
#include "Account0.h"
#include "Capture.h"
#include "Vamp.h"

struct Objective
{
	Objective(Faction faction);

	Vamp vamp;
	Capture altar, farm, tower;
};

class Account1: public Account0
{
public:
	Account1(Receipt human, Receipt orc, Uint8 turn);
	
	void altars(Flag flag);
	void farms(Flag flag);
	void towers(Flag flag);

	void vamp(Faction faction);

	Objective human, orc;

private:
	Faction bonus;
};
