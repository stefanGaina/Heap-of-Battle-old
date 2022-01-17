#include "Load.h"
#include <iostream>

Load::Load(void) : 
	fin("save.txt", std::ios::in)
{
	if (!fin.is_open())
	{
		std::cout << "[ERROR]: Can't read from save.txt" << std::endl;
	}
}

Load::~Load(void)
{
	//fin.close();
}

void Load::read(void)
{

}

char Load::getScenario(void)
{
	char scenario;

	fin >> scenario;

	return scenario;
}
