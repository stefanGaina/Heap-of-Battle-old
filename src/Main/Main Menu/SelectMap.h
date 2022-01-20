#pragma once
#include "Run.h"
#include "CursorMenu.h"
#include "SoundMenu.h"

enum class SelectEngage
{
	NO = 0,

	TUTORIAL = -1,
	SCENARIO_1 = 1,
	SCENARIO_2 = 2,
	SCENARIO_3 = 3,
};

struct FrameCap
{
	const Uint8 perSecond = 60;
	const Uint8 delay = 1000 / perSecond;

	Uint32 start;
	Uint32 time;
};

struct SelectIcon
{
	SelectIcon(SDL_Texture* scenario, SDL_Texture* tutorial, SDL_Texture* start);
	~SelectIcon(void);

	SDL_Texture* scenario, * tutorial, * start;
};

class SelectMap : public Run
{
public:
	SelectMap(CursorMenu* cursor, const SoundMenu& sound, const Mouse& mouse, SDL_Renderer* renderer);
	~SelectMap(void);

	void render(void);
	void handleEvents(void);

	Sint8 code(void);

private:
	void resetCurrent(void);

	CursorMenu* cursor;
	const SoundMenu& sound;

	Mouse mouse;

	SDL_Renderer* renderer;
	SDL_Rect destination;

	SDL_Texture* background;
	SDL_Texture* scenario[4];
	SDL_Texture* current[5];

	SelectIcon idle, selected; //

	SelectEngage engaged;
};
