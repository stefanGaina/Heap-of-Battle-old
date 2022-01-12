#pragma once
#include "Language.h"

class Turn
{
public:
	Turn(void);

	Uint8 getValue(void);
	Faction get(void);

	bool isHuman(void);
	bool isOrc(void);
	
	void change(void);

private:
	Uint8 turn;
};
