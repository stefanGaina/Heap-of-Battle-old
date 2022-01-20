#pragma once
#include "SelectMap.h"
#include "CursorMenu.h"
#include "SoundMenu.h"
#include "TextMenu.h"
#include "Load.h"
#include "Game0.h"

struct Button
{
	SDL_Texture* idle, * selected;
};

class MainMenu : public Run
{
public:
	MainMenu(SDL_Renderer* renderer);
	~MainMenu(void);

	void render(void);
	void handleEvents(void);

private:
	void start(Game0* game);
	void resetCurrent(void);

	void initializeRectangles(void); //

	TextMenu text;
	const SoundMenu sound;
	CursorMenu cursor;

	Load load;

	Mouse mouse;

	SDL_Renderer* const renderer;
	SDL_Rect  destinationBackground, destinationLogo, destinationButton, destinationMute;

	Button button;

	SDL_Texture* background, * newGame, * muteButton, * logo;

	SDL_Texture* current[3];
	
	Sint8 scenario;

	// bool muted;
};
