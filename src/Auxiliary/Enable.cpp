#include "Enable.h"

Enable::Enable(bool enabled) 
	: enabled(enabled)
{
}

bool Enable::isEnabled(void)
{
	return enabled;
}

void Enable::enable(void)
{
	enabled = true;
}

void Enable::disable(void)
{
	enabled = false;
}
