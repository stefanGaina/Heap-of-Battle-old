#pragma once
#include <fstream>

class Load
{
public:
	Load(void);
	~Load(void);

	void read(void);

	char getScenario(void);

private:
	std::fstream fin;
};
