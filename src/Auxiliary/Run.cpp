#include "Run.h"

Run::Run(void) : running(true)
{
}

bool Run::isRunning(void)
{
	return running;
}

void Run::stop(void)
{
	running = false;
}
