#include "Capture.h"

Capture::Capture(Faction faction) : captured(faction)
{
}

Faction Capture::get(void)
{
	return captured;
}

void Capture::update(Faction capture)
{
	captured = capture != Faction::NEUTRAL ? capture : captured;
}
