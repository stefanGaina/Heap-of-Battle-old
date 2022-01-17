#include "VoiceLine.h"

VoiceLine::VoiceLine(void) : move(0), select(0)
{
	loadSounds();
}

VoiceLine::~VoiceLine(void)
{
	destroySounds();
}

void VoiceLine::play(State state, Sound action)
{
	switch (state)
	{
		case State::HUMAN_INFANTRY:
		{
			switch (action)
			{
				case Sound::SELECT:
				{
					Mix_PlayChannel(-1, human.infantry.select[select % 4], 0);
					++select;
					break;
				}
				case Sound::MOVE:
				{
					Mix_PlayChannel(-1, human.infantry.move[move % 4], 0);
					++move;
					break;
				}
				case Sound::ATTACK:
				{
					Mix_PlayChannel(-1, human.infantry.attack[move % 3], 0);
					++move;
					break;
				}
				case Sound::TRAIN:
				{
					Mix_PlayChannel(-1, human.infantry.train, 0);
				}
			}
			break;
		}
		case State::ORC_INFANTRY:
		{
			switch (action)
			{
				case Sound::SELECT:
				{
					Mix_PlayChannel(-1, orc.infantry.select[select % 4], 0);
					++select;
					break;
				}
				case Sound::MOVE:
				{
					Mix_PlayChannel(-1, orc.infantry.move[move % 4], 0);
					++move;
					break;
				}
				case Sound::ATTACK:
				{
					Mix_PlayChannel(-1, orc.infantry.attack[move % 3], 0);
					++move;
					break;
				}
				case Sound::TRAIN:
				{
					Mix_PlayChannel(-1, orc.infantry.train, 0);
				}
			}
			break;
		}
		case State::HUMAN_ARCHER:
		{
			switch (action)
			{
				case Sound::SELECT:
				{
					Mix_PlayChannel(-1, human.archer.select[select % 4], 0);
					++select;
					break;
				}
				case Sound::MOVE:
				{
					Mix_PlayChannel(-1, human.archer.move[move % 4], 0);
					++move;
					break;
				}
				case Sound::ATTACK:
				{
					Mix_PlayChannel(-1, human.archer.attack[move % 3], 0);
					++move;
					break;
				}
				case Sound::TRAIN:
				{
					Mix_PlayChannel(-1, human.archer.train, 0);
				}
			}
			break;
		}
		case State::ORC_ARCHER:
		{
			switch (action)
			{
				case Sound::SELECT:
				{
					Mix_PlayChannel(-1, orc.archer.select[select % 4], 0);
					++select;
					break;
				}
				case Sound::MOVE:
				{
					Mix_PlayChannel(-1, orc.archer.move[move % 4], 0);
					++move;
					break;
				}
				case Sound::ATTACK:
				{
					Mix_PlayChannel(-1, orc.archer.attack[move % 3], 0);
					++move;
					break;
				}
				case Sound::TRAIN:
				{
					Mix_PlayChannel(-1, orc.archer.train, 0);
				}
			}
			break;
		}
		case State::HUMAN_KNIGHT:
		{
			switch (action)
			{
				case Sound::SELECT:
				{
					Mix_PlayChannel(-1, human.knight.select[select % 4], 0);
					++select;
					break;
				}
				case Sound::MOVE:
				{
					Mix_PlayChannel(-1, human.knight.move[move % 4], 0);
					++move;
					break;
				}
				case Sound::ATTACK:
				{
					Mix_PlayChannel(-1, human.knight.attack[move % 3], 0);
					++move;
					break;
				}
				case Sound::TRAIN:
				{
					Mix_PlayChannel(-1, human.knight.train, 0);
				}
			}
			break;
		}
		case State::ORC_KNIGHT:
		{
			switch (action)
			{
				case Sound::SELECT:
				{
					Mix_PlayChannel(-1, orc.knight.select[select % 4], 0);
					++select;
					break;
				}
				case Sound::MOVE:
				{
					Mix_PlayChannel(-1, orc.knight.move[move % 4], 0);
					++move;
					break;
				}
				case Sound::ATTACK:
				{
					Mix_PlayChannel(-1, orc.knight.attack[move % 3], 0);
					++move;
					break;
				}
				case Sound::TRAIN:
				{
					Mix_PlayChannel(-1, orc.knight.train, 0);
				}
			}
			break;
		}
		case State::HUMAN_WING:
		{
			switch (action)
			{
				case Sound::SELECT:
				{
					Mix_PlayChannel(-1, human.wing.select[select % 4], 0);
					++select;
					break;
				}
				case Sound::MOVE:
				{
					Mix_PlayChannel(-1, human.wing.move[move % 4], 0);
					++move;
					break;
				}
				case Sound::ATTACK:
				{
					Mix_PlayChannel(-1, human.wing.attack[move % 3], 0);
					++move;
					break;
				}
				case Sound::TRAIN:
				{
					Mix_PlayChannel(-1, human.wing.train, 0);
				}
			}
			break;
		}
		case State::ORC_WING:
		{
			switch (action)
			{
				case Sound::SELECT:
				{
					Mix_PlayChannel(-1, orc.wing.select[select % 3], 0);
					++select;
					break;
				}
				case Sound::MOVE:
				{
					Mix_PlayChannel(-1, orc.wing.move[move % 3], 0);
					++move;
					break;
				}
				case Sound::ATTACK:
				{
					Mix_PlayChannel(-1, orc.wing.attack[move % 3], 0);
					++move;
					break;
				}
				case Sound::TRAIN:
				{
					Mix_PlayChannel(-1, orc.wing.train, 0);
				}
			}
		}
	}
}

void VoiceLine::loadSounds(void)
{
	human.infantry.train = Mix_LoadWAV("Assets/Human/Units/Infantry/Sounds/Train.wav");

	human.infantry.select[0] = Mix_LoadWAV("Assets/Human/Units/Infantry/Sounds/Select.wav");
	human.infantry.select[1] = Mix_LoadWAV("Assets/Human/Units/Infantry/Sounds/Select1.wav");
	human.infantry.select[2] = Mix_LoadWAV("Assets/Human/Units/Infantry/Sounds/Select2.wav");
	human.infantry.select[3] = Mix_LoadWAV("Assets/Human/Units/Infantry/Sounds/Select3.wav");

	human.infantry.move[0] = Mix_LoadWAV("Assets/Human/Units/Infantry/Sounds/Move.wav");
	human.infantry.move[1] = Mix_LoadWAV("Assets/Human/Units/Infantry/Sounds/Move1.wav");
	human.infantry.move[2] = Mix_LoadWAV("Assets/Human/Units/Infantry/Sounds/Move2.wav");
	human.infantry.move[3] = Mix_LoadWAV("Assets/Human/Units/Infantry/Sounds/Move3.wav");

	human.infantry.attack[0] = Mix_LoadWAV("Assets/Human/Units/Infantry/Sounds/Attack.wav");
	human.infantry.attack[1] = Mix_LoadWAV("Assets/Human/Units/Infantry/Sounds/Attack1.wav");
	human.infantry.attack[2] = Mix_LoadWAV("Assets/Human/Units/Infantry/Sounds/Attack2.wav");

	human.archer.train = Mix_LoadWAV("Assets/Human/Units/Archer/Sounds/Train.wav");

	human.archer.select[0] = Mix_LoadWAV("Assets/Human/Units/Archer/Sounds/Select.wav");
	human.archer.select[1] = Mix_LoadWAV("Assets/Human/Units/Archer/Sounds/Select1.wav");
	human.archer.select[2] = Mix_LoadWAV("Assets/Human/Units/Archer/Sounds/Select2.wav");
	human.archer.select[3] = Mix_LoadWAV("Assets/Human/Units/Archer/Sounds/Select3.wav");

	human.archer.move[0] = Mix_LoadWAV("Assets/Human/Units/Archer/Sounds/Move.wav");
	human.archer.move[1] = Mix_LoadWAV("Assets/Human/Units/Archer/Sounds/Move1.wav");
	human.archer.move[2] = Mix_LoadWAV("Assets/Human/Units/Archer/Sounds/Move2.wav");
	human.archer.move[3] = Mix_LoadWAV("Assets/Human/Units/Archer/Sounds/Move3.wav");

	human.archer.attack[0] = Mix_LoadWAV("Assets/Human/Units/Archer/Sounds/Attack.wav");
	human.archer.attack[1] = Mix_LoadWAV("Assets/Human/Units/Archer/Sounds/Attack1.wav");
	human.archer.attack[2] = Mix_LoadWAV("Assets/Human/Units/Archer/Sounds/Attack2.wav");

	human.knight.train = Mix_LoadWAV("Assets/Human/Units/Knight/Sounds/Train.wav");

	human.knight.select[0] = Mix_LoadWAV("Assets/Human/Units/Knight/Sounds/Select.wav");
	human.knight.select[1] = Mix_LoadWAV("Assets/Human/Units/Knight/Sounds/Select1.wav");
	human.knight.select[2] = Mix_LoadWAV("Assets/Human/Units/Knight/Sounds/Select2.wav");
	human.knight.select[3] = Mix_LoadWAV("Assets/Human/Units/Knight/Sounds/Select3.wav");

	human.knight.move[0] = Mix_LoadWAV("Assets/Human/Units/Knight/Sounds/Move.wav");
	human.knight.move[1] = Mix_LoadWAV("Assets/Human/Units/Knight/Sounds/Move1.wav");
	human.knight.move[2] = Mix_LoadWAV("Assets/Human/Units/Knight/Sounds/Move2.wav");
	human.knight.move[3] = Mix_LoadWAV("Assets/Human/Units/Knight/Sounds/Move3.wav");

	human.knight.attack[0] = Mix_LoadWAV("Assets/Human/Units/Knight/Sounds/Attack.wav");
	human.knight.attack[1] = Mix_LoadWAV("Assets/Human/Units/Knight/Sounds/Attack1.wav");
	human.knight.attack[2] = Mix_LoadWAV("Assets/Human/Units/Knight/Sounds/Attack2.wav");

	human.wing.train = Mix_LoadWAV("Assets/Human/Units/Wing/Sounds/Train.wav");

	human.wing.select[0] = Mix_LoadWAV("Assets/Human/Units/Wing/Sounds/Select.wav");
	human.wing.select[1] = Mix_LoadWAV("Assets/Human/Units/Wing/Sounds/Select1.wav");
	human.wing.select[2] = Mix_LoadWAV("Assets/Human/Units/Wing/Sounds/Select2.wav");
	human.wing.select[3] = Mix_LoadWAV("Assets/Human/Units/Wing/Sounds/Select3.wav");

	human.wing.move[0] = Mix_LoadWAV("Assets/Human/Units/Wing/Sounds/Move.wav");
	human.wing.move[1] = Mix_LoadWAV("Assets/Human/Units/Wing/Sounds/Move1.wav");
	human.wing.move[2] = Mix_LoadWAV("Assets/Human/Units/Wing/Sounds/Move2.wav");
	human.wing.move[3] = Mix_LoadWAV("Assets/Human/Units/Wing/Sounds/Move3.wav");

	human.wing.attack[0] = Mix_LoadWAV("Assets/Human/Units/Wing/Sounds/Attack.wav");
	human.wing.attack[1] = Mix_LoadWAV("Assets/Human/Units/Wing/Sounds/Attack1.wav");
	human.wing.attack[2] = Mix_LoadWAV("Assets/Human/Units/Wing/Sounds/Attack2.wav");

	orc.infantry.train = Mix_LoadWAV("Assets/Orc/Units/Infantry/Sounds/Train.wav");

	orc.infantry.select[0] = Mix_LoadWAV("Assets/Orc/Units/Infantry/Sounds/Select.wav");
	orc.infantry.select[1] = Mix_LoadWAV("Assets/Orc/Units/Infantry/Sounds/Select1.wav");
	orc.infantry.select[2] = Mix_LoadWAV("Assets/Orc/Units/Infantry/Sounds/Select2.wav");
	orc.infantry.select[3] = Mix_LoadWAV("Assets/Orc/Units/Infantry/Sounds/Select3.wav");

	orc.infantry.move[0] = Mix_LoadWAV("Assets/Orc/Units/Infantry/Sounds/Move.wav");
	orc.infantry.move[1] = Mix_LoadWAV("Assets/Orc/Units/Infantry/Sounds/Move1.wav");
	orc.infantry.move[2] = Mix_LoadWAV("Assets/Orc/Units/Infantry/Sounds/Move2.wav");
	orc.infantry.move[3] = Mix_LoadWAV("Assets/Orc/Units/Infantry/Sounds/Move3.wav");

	orc.infantry.attack[0] = Mix_LoadWAV("Assets/Orc/Units/Infantry/Sounds/Attack.wav");
	orc.infantry.attack[1] = Mix_LoadWAV("Assets/Orc/Units/Infantry/Sounds/Attack1.wav");
	orc.infantry.attack[2] = Mix_LoadWAV("Assets/Orc/Units/Infantry/Sounds/Attack2.wav");

	orc.archer.train = Mix_LoadWAV("Assets/Orc/Units/Archer/Sounds/Train.wav");

	orc.archer.select[0] = Mix_LoadWAV("Assets/Orc/Units/Archer/Sounds/Select.wav");
	orc.archer.select[1] = Mix_LoadWAV("Assets/Orc/Units/Archer/Sounds/Select1.wav");
	orc.archer.select[2] = Mix_LoadWAV("Assets/Orc/Units/Archer/Sounds/Select2.wav");
	orc.archer.select[3] = Mix_LoadWAV("Assets/Orc/Units/Archer/Sounds/Select3.wav");

	orc.archer.move[0] = Mix_LoadWAV("Assets/Orc/Units/Archer/Sounds/Move.wav");
	orc.archer.move[1] = Mix_LoadWAV("Assets/Orc/Units/Archer/Sounds/Move1.wav");
	orc.archer.move[2] = Mix_LoadWAV("Assets/Orc/Units/Archer/Sounds/Move2.wav");
	orc.archer.move[3] = Mix_LoadWAV("Assets/Orc/Units/Archer/Sounds/Move3.wav");

	orc.archer.attack[0] = Mix_LoadWAV("Assets/Orc/Units/Archer/Sounds/Attack.wav");
	orc.archer.attack[1] = Mix_LoadWAV("Assets/Orc/Units/Archer/Sounds/Attack1.wav");
	orc.archer.attack[2] = Mix_LoadWAV("Assets/Orc/Units/Archer/Sounds/Attack2.wav");

	orc.knight.train = Mix_LoadWAV("Assets/Orc/Units/Knight/Sounds/Train.wav");

	orc.knight.select[0] = Mix_LoadWAV("Assets/Orc/Units/Knight/Sounds/Select.wav");
	orc.knight.select[1] = Mix_LoadWAV("Assets/Orc/Units/Knight/Sounds/Select1.wav");
	orc.knight.select[2] = Mix_LoadWAV("Assets/Orc/Units/Knight/Sounds/Select2.wav");
	orc.knight.select[3] = Mix_LoadWAV("Assets/Orc/Units/Knight/Sounds/Select3.wav");

	orc.knight.move[0] = Mix_LoadWAV("Assets/Orc/Units/Knight/Sounds/Move.wav");
	orc.knight.move[1] = Mix_LoadWAV("Assets/Orc/Units/Knight/Sounds/Move1.wav");
	orc.knight.move[2] = Mix_LoadWAV("Assets/Orc/Units/Knight/Sounds/Move2.wav");
	orc.knight.move[3] = Mix_LoadWAV("Assets/Orc/Units/Knight/Sounds/Move3.wav");

	orc.knight.attack[0] = Mix_LoadWAV("Assets/Orc/Units/Knight/Sounds/Attack.wav");
	orc.knight.attack[1] = Mix_LoadWAV("Assets/Orc/Units/Knight/Sounds/Attack1.wav");
	orc.knight.attack[2] = Mix_LoadWAV("Assets/Orc/Units/Knight/Sounds/Attack2.wav");

	orc.wing.train = Mix_LoadWAV("Assets/Orc/Units/Wing/Sounds/Train.wav");

	orc.wing.select[0] = Mix_LoadWAV("Assets/Orc/Units/Wing/Sounds/Select.wav");
	orc.wing.select[1] = Mix_LoadWAV("Assets/Orc/Units/Wing/Sounds/Select1.wav");
	orc.wing.select[2] = Mix_LoadWAV("Assets/Orc/Units/Wing/Sounds/Select2.wav");
	orc.wing.select[3] = nullptr;

	orc.wing.move[0] = Mix_LoadWAV("Assets/Orc/Units/Wing/Sounds/Move.wav");
	orc.wing.move[1] = Mix_LoadWAV("Assets/Orc/Units/Wing/Sounds/Move1.wav");
	orc.wing.move[2] = Mix_LoadWAV("Assets/Orc/Units/Wing/Sounds/Move2.wav");
	orc.wing.move[3] = nullptr;

	orc.wing.attack[0] = Mix_LoadWAV("Assets/Orc/Units/Wing/Sounds/Attack.wav");
	orc.wing.attack[1] = Mix_LoadWAV("Assets/Orc/Units/Wing/Sounds/Attack1.wav");
	orc.wing.attack[2] = Mix_LoadWAV("Assets/Orc/Units/Wing/Sounds/Attack2.wav");
}

void VoiceLine::destroySounds(void)
{
	Mix_FreeChunk(human.infantry.train);
	human.infantry.train = nullptr;

	Mix_FreeChunk(human.archer.train);
	human.archer.train = nullptr;

	Mix_FreeChunk(human.knight.train);
	human.knight.train = nullptr;

	Mix_FreeChunk(human.wing.train);
	human.wing.train = nullptr;

	Mix_FreeChunk(orc.infantry.train);
	orc.infantry.train = nullptr;

	Mix_FreeChunk(orc.archer.train);
	orc.archer.train = nullptr;

	Mix_FreeChunk(orc.knight.train);
	orc.knight.train = nullptr;

	Mix_FreeChunk(orc.wing.train);
	orc.wing.train = nullptr;

	for (size_t i = 0; i < 4; ++i)
	{
		Mix_FreeChunk(human.infantry.select[i]);
		human.infantry.select[i] = nullptr;

		Mix_FreeChunk(human.infantry.move[i]);
		human.infantry.move[i] = nullptr;

		Mix_FreeChunk(human.archer.select[i]);
		human.archer.select[i] = nullptr;

		Mix_FreeChunk(human.archer.move[i]);
		human.archer.move[i] = nullptr;

		Mix_FreeChunk(human.knight.select[i]);
		human.knight.select[i] = nullptr;

		Mix_FreeChunk(human.knight.move[i]);
		human.knight.move[i] = nullptr;

		Mix_FreeChunk(human.wing.select[i]);
		human.wing.select[i] = nullptr;

		Mix_FreeChunk(human.wing.move[i]);
		human.wing.move[i] = nullptr;

		Mix_FreeChunk(orc.infantry.select[i]);
		orc.infantry.select[i] = nullptr;

		Mix_FreeChunk(orc.infantry.move[i]);
		orc.infantry.move[i] = nullptr;

		Mix_FreeChunk(orc.archer.select[i]);
		orc.archer.select[i] = nullptr;

		Mix_FreeChunk(orc.archer.move[i]);
		orc.archer.move[i] = nullptr;

		Mix_FreeChunk(orc.knight.select[i]);
		orc.knight.select[i] = nullptr;

		Mix_FreeChunk(orc.knight.move[i]);
		orc.knight.move[i] = nullptr;

		Mix_FreeChunk(orc.wing.select[i]);
		orc.wing.select[i] = nullptr;

		Mix_FreeChunk(orc.wing.move[i]);
		orc.wing.move[i] = nullptr;
	}
	for (size_t i = 0; i < 3; ++i)
	{
		Mix_FreeChunk(human.infantry.attack[i]);
		human.infantry.attack[i] = nullptr;

		Mix_FreeChunk(human.archer.attack[i]);
		human.archer.attack[i] = nullptr;

		Mix_FreeChunk(human.knight.attack[i]);
		human.knight.attack[i] = nullptr;

		Mix_FreeChunk(human.wing.attack[i]);
		human.wing.attack[i] = nullptr;

		Mix_FreeChunk(orc.infantry.attack[i]);
		orc.infantry.attack[i] = nullptr;

		Mix_FreeChunk(orc.archer.attack[i]);
		orc.archer.attack[i] = nullptr;

		Mix_FreeChunk(orc.knight.attack[i]);
		orc.knight.attack[i] = nullptr;

		Mix_FreeChunk(orc.wing.attack[i]);
		orc.wing.attack[i] = nullptr;
	}
}
