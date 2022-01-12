#include "Vamp.h"

Vamp::Vamp(void) : vamped(false)
{
}

void Vamp::set(void)
{
	vamped = true;
}

bool Vamp::get(void)
{
	return vamped;
}
