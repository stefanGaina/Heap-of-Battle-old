#include "Queue.h"

Queue::Queue(void) : tail(nullptr)
{
}

Queue::~Queue(void)
{
	while (tail != nullptr)
	{
		Element* p = tail->next;
		tail->next = tail->next->next;

		delete p;
	}
}

bool Queue::isEmpty(void)
{
	return (tail == nullptr);
}

void Queue::put(Transport load)
{
	Element* p = new Element;

	p->transport = load;

	if (tail == nullptr)
	{
		p->next = p;
		tail = p;
	}
	else
	{
		p->next = tail->next;
		tail->next = p;
		tail = p;
	}
}

Transport Queue::get(void)
{
	Element* p = tail->next;
	Transport unload = tail->next->transport;

	if (p == tail)
	{
		tail = nullptr;
	}
	else
	{
		tail->next = tail->next->next;
	}
	delete p;
	return unload;
}

Queue* Queue::getThis(void)
{
	return this;
}
