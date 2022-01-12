#include "SoundEffect.h"

SoundEffect::SoundEffect(void)
{
	loadSounds();
}

SoundEffect::~SoundEffect(void)
{
	destroySounds();
}

void SoundEffect::play(Sound sound)
{
	switch (sound)
	{
		case Sound::CLICK:
		{
			Mix_PlayChannel(-1, click, 0);
			break;
		}
		case Sound::ERROR:
		{
			Mix_PlayChannel(-1, error, 0);
			break;
		}
		case Sound::HUMAN_MORE_GOLD:
		{
			Mix_PlayChannel(-1, human.moreGold, 0);
			break;
		}
		case Sound::ORC_MORE_GOLD:
		{
			Mix_PlayChannel(-1, orc.moreGold, 0);
			break;
		}
		case Sound::RECEIVE_GOLD:
		{
			Mix_PlayChannel(-1, receiveGold, 0);
			break;
		}
		case Sound::VAMP:
		{
			Mix_PlayChannel(-1, vamp, 0);
			break;
		}
		case Sound::PAUSE:
		{
			Mix_PlayChannel(-1, pause, 0);
			break;
		}
		case Sound::HUMAN_DEFEAT:
		{
			Mix_PlayMusic(human.defeat, 1);
			break;
		}
		case Sound::ORC_DEFEAT:
		{
			Mix_PlayMusic(orc.defeat, 1);
		}
	}
}

void SoundEffect::loadSounds(void)
{
	error = Mix_LoadWAV("Assets/General/Sounds/Error.wav");
	vamp = Mix_LoadWAV("Assets/General/Sounds/Vamp.wav");
	click = Mix_LoadWAV("Assets/General/Sounds/Click.wav");
	receiveGold = Mix_LoadWAV("Assets/General/Sounds/Receive Gold.wav");
	pause = Mix_LoadWAV("Assets/General/Sounds/Pause.wav");

	human.moreGold = Mix_LoadWAV("Assets/Human/Sounds/More Gold.wav");
	orc.moreGold = Mix_LoadWAV("Assets/Orc/Sounds/More Gold.wav");

	human.defeat = Mix_LoadMUS("Assets/Human/Sounds/Defeat.mp3");
	orc.defeat = Mix_LoadMUS("Assets/Orc/Sounds/Defeat.mp3");
}

void SoundEffect::destroySounds(void)
{
	Mix_FreeChunk(error);
	error = nullptr;

	Mix_FreeChunk(vamp);
	vamp = nullptr;

	Mix_FreeChunk(click);
	click = nullptr;

	Mix_FreeChunk(receiveGold);
	receiveGold = nullptr;

	Mix_FreeChunk(pause);
	pause = nullptr;

	Mix_FreeChunk(human.moreGold);
	human.moreGold = nullptr;

	Mix_FreeChunk(orc.moreGold);
	orc.moreGold = nullptr;

	Mix_FreeMusic(human.defeat);
	Mix_FreeMusic(orc.defeat);
}
