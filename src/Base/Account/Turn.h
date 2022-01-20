#pragma once
#include "Language.h"

class Turn
{
public:
	Turn(Uint16 turn);

	Uint16 getValue(void);
	Faction get(void);

	bool isHuman(void);
	bool isOrc(void);
	
	void change(void);

private:
	Uint16 turn;
};
