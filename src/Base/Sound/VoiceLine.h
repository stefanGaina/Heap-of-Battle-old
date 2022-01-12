#pragma once
#include <SDL_mixer.h>
#include "Language.h"

struct Line
{
	Mix_Chunk* train, * select[4], * move[4], * attack[3];
};

struct Voice
{
	Line infantry, archer, knight, wing;
};

class VoiceLine
{
public:
	VoiceLine(void);
	~VoiceLine(void);

	void play(State state, Sound action);

private:
	void loadSounds(void);
	void destroySounds(void);

	Uint8 move, select;

	Voice human, orc;
};
