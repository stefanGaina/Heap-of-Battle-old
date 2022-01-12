#pragma once
#include "Language.h"

class Capture
{
public:
	Capture(Faction faction);

	Faction get(void);
	void update(Faction capture);

private:
	Faction captured;
};
