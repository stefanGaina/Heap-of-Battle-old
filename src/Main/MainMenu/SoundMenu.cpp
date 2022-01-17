#include "SoundMenu.h"

SoundMenu::SoundMenu(void) :
	ambience(Mix_LoadMUS("Assets/General/Menu/Main/Sounds/Ambience.mp3")),
	click(Mix_LoadWAV("Assets/General/Menu/Main/Sounds/Click.wav"))
{
	start();
}

SoundMenu::~SoundMenu(void)
{
	Mix_FreeMusic(ambience);
	ambience = nullptr;

	Mix_FreeChunk(click);
	click = nullptr;
}

void SoundMenu::play(void) const
{
	Mix_PlayChannel(-1, click, 0);
}

void SoundMenu::start(void) const
{
	Mix_PlayMusic(ambience, -1);
}
