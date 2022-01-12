#include "Sound0.h"

Sound0::Sound0(Mix_Music* ambience) : ambience(ambience)
{
	Mix_PlayMusic(ambience, -1);
}

Sound0::~Sound0(void)
{
	Mix_FreeMusic(ambience);
	ambience = nullptr;
}

void Sound0::pause(void)
{
	Mix_PauseMusic();
}

void Sound0::resume(void)
{
	Mix_ResumeMusic();
}
