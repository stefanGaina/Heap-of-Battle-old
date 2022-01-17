#include "Turn.h"

Turn::Turn(void) : 
	turn(1)
{
}

Uint8 Turn::getValue(void)
{
	return turn;
}

Faction Turn::get(void)
{
	return isHuman() ? Faction::HUMAN : Faction::ORC;
}

bool Turn::isHuman(void)
{
	return (turn % 2);
}

bool Turn::isOrc(void)
{
	return !(turn % 2);
}

void Turn::change(void)
{
	++turn;
}
