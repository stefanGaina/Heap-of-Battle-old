#include "InitSDL.h"
#include "MainMenu.h"

int main(int argc, char* argv[])
{
	const Uint16 SCREEN_WIDTH = 25 * SCALE;
	const Uint16 SCREEN_HEIGHT = 19 * SCALE - 8; // -8 to achieve 4:3 aspect ratio

	InitSDL initSDL("Heap of Battle", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, false);

	MainMenu mainMenu(initSDL.getRenderer());

	while (mainMenu.isRunning())
	{
		mainMenu.handleEvents();
		mainMenu.render();
	}
	return 0;
}
