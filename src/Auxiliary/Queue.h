#pragma once
#include "Language.h"

struct Transport
{
	State unit;
	Move* path;
	Coordinate start, finish;
};

struct Element
{
	Transport transport;

	Element* next;
};

class Queue
{
public:
	Queue(void);
	~Queue(void);
	
	bool isEmpty(void);

	void put(Transport load);

	Transport get(void);
	Queue* getThis(void);

private:
	Element* tail;
};
