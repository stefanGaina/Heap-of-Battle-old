#pragma once
#include <SDL_mixer.h>

class SoundMenu
{
public:
	SoundMenu(void);
	~SoundMenu(void);

	void play(void) const;
	void start(void) const;

private:
	Mix_Music* ambience;
	Mix_Chunk* click;
};
