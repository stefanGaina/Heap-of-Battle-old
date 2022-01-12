#pragma once

class Run
{
public:
	Run(void);

	bool isRunning(void);

	void stop(void);

private:
	bool running;
};
