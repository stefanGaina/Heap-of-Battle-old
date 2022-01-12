#pragma once
#include <SDL_mixer.h>
#include "Language.h"

struct Effect
{
	Mix_Music* defeat;
	Mix_Chunk* moreGold;
};

class SoundEffect
{
public:
	SoundEffect(void);
	~SoundEffect(void);

	void play(Sound sound);

private:
	void loadSounds(void);
	void destroySounds(void);

	Mix_Chunk* error, * vamp, * click, * gold, * receiveGold, * pause;

	Effect human, orc;
};
