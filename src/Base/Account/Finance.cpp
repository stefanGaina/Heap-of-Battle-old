#include "Finance.h"

Finance::Finance(Uint8 value) :
	value(value)
{
}

Uint8 Finance::get(void)
{
	return value;
}

void Finance::update(Sint8 value)
{
	this->value += value;
}
