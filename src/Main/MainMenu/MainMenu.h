#pragma once
#include "Game0.h"
#include "SelectMap.h"
#include "CursorMenu.h"
#include "Load.h"

#include <SDL_ttf.h>
#include <SDL_mixer.h>

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

	void initializeRectangles(void);
	void loadTextures(void);
	void loadSounds(void);

	CursorMenu cursor;

	Load load;

	Mouse mouse;

	SDL_Renderer* renderer;
	SDL_Rect  destinationBackground, destinationLogo, destinationButton, destinationMute;

	Button button;

	SDL_Texture* background, * newGame, * muteButton, * logo;

	SDL_Texture* current[3];

	Mix_Music* ambience;

	Sint8 scenario;

	// bool muted;
};
