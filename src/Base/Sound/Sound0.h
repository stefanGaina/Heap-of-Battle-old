#pragma once
#include "VoiceLine.h"
#include "SoundEffect.h"

class Sound0
{
public:
public:
	Sound0(Mix_Music* ambience);
	~Sound0(void);

	void pause(void);
	void resume(void);

	VoiceLine voiceLine;
	SoundEffect soundEffect;

private:
	Mix_Music* ambience;
};
