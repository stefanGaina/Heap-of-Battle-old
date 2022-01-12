#pragma once
#include <SDL.h>

class Finance
{
public:
	Finance(Uint8 value);

	Uint8 get(void);
	void update(Sint8 value);

private:
	Uint8 value;
};
