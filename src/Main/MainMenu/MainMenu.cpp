#include "MainMenu.h"
#include "Game1.h"
#include "Game2.h"
#include "Game3.h"
#include "TextureManager.h"

MainMenu::MainMenu(SDL_Renderer* renderer) :
	text(renderer), cursor(renderer), renderer(renderer)
{
	logo = TextureManager::load("Assets/General/Menu/Main/Logo.png", renderer);
	button.idle = TextureManager::load("Assets/General/Menu/Main/Button Idle.png", renderer);
	button.selected = TextureManager::load("Assets/General/Menu/Main/Button Selected.png", renderer);
	muteButton = TextureManager::load("Assets/General/Menu/Main/Mute Button/Mute OFF Idle.png", renderer);
	background = TextureManager::load("Assets/General/Menu/Main/Menu Background.png", renderer);

	initializeRectangles(); //
	resetCurrent();
}

MainMenu::~MainMenu(void)
{
	TextureManager::destroy(logo);
	TextureManager::destroy(background);
}

void MainMenu::render()
{
	SDL_RenderClear(renderer);

	TextureManager::draw(background, destinationBackground, renderer);
	TextureManager::draw(logo, destinationLogo, renderer);

	destinationButton.x = 300;
	destinationButton.y = 200;
	TextureManager::draw(current[0], destinationButton, renderer);

	destinationButton.y = 275;
	TextureManager::draw(current[1], destinationButton, renderer);

	destinationButton.y = 350;
	TextureManager::draw(current[2], destinationButton, renderer);

	TextureManager::draw(muteButton, destinationMute, renderer);

	text.draw();

	cursor.draw(mouse);

	SDL_RenderPresent(renderer);
}

void MainMenu::handleEvents()
{
	SDL_Event event;

	if (SDL_PollEvent(&event) != 0)
	{
		switch (event.type)
		{
			case SDL_MOUSEMOTION:
			{
				SDL_GetMouseState(&mouse.x, &mouse.y);
				
				if (mouse.x >= 300 && mouse.x <= 500)
				{
					if (mouse.y >= 230 && mouse.y <= 270)
					{
						current[0] = button.selected;
					}
					else if (mouse.y >= 300 && mouse.y <= 340)
					{
						current[1] = button.selected;
					}
					else if (mouse.y >= 370 && mouse.y <= 410)
					{
						current[2] = button.selected;
					}
					else
					{
						resetCurrent();
					}
				}
				else
				{
					resetCurrent();
				}
				break;
			}
			case SDL_MOUSEBUTTONDOWN:
			{
				sound.play();

				if (current[0] == button.selected)
				{
					SelectMap selectMap(&cursor, sound, mouse, renderer);

					while (selectMap.isRunning())
					{
						selectMap.handleEvents();
						selectMap.render();
						scenario = selectMap.code();
					}
					switch (scenario)
					{
						case -1:
						{
							break;
						}
						case 1:
						{
							Game1* game = new Game1(renderer, mouse);
							start(game);
							delete game;
							break;
						}
						case 2:
						{
							Game2* game = new Game2(renderer, mouse);
							start(game);
							delete game;
							break;
						}
						case 3:
						{
							Game3* game = new Game3(renderer, mouse);
							start(game);
							delete game;
						}
					}
				}
				else if (current[1] == button.selected)
				{
					//load
				}
				else if(current[2] == button.selected)
				{
					stop();
				}
				break;
			}
			case SDL_KEYDOWN:
			{
				switch (event.key.keysym.sym)
				{
					case SDLK_ESCAPE:
					{
						stop();
					}
				}
				break;
			}
			case SDL_QUIT:
			{
				stop();
			}
			/*else
			{
				if (event.key.keysym.sym == SDLK_b)
				{
					if (Mix_PlayingMusic() == 0)
					{
						Mix_PlayMusic(ambience, -1);
					}
					else
					{
						if (Mix_PausedMusic() == 1)
						{
							Mix_ResumeMusic();
						}
						else
						{
							Mix_PauseMusic();
						}
					}
				}
			}*/
		}
	}
}

void MainMenu::start(Game0* game)
{
	FrameCap frame;

	while (game->isRunning())
	{
		frame.start = SDL_GetTicks();

		game->handleEvents();
		game->render();

		frame.time = SDL_GetTicks() - frame.start;

		if (frame.delay > frame.time)
		{
			SDL_Delay(frame.delay - frame.time);
		}
	}
	sound.start();
}

void MainMenu::initializeRectangles(void)
{
	destinationBackground.x = 0;
	destinationBackground.y = 0;
	destinationBackground.w = 25 * SCALE;
	destinationBackground.h = 19 * SCALE - 8;

	destinationLogo.x = 200;
	destinationLogo.y = 0;
	destinationLogo.w = 400;
	destinationLogo.h = 200;

	destinationButton.x = 300;
	destinationButton.y = 200;
	destinationButton.w = 200;
	destinationButton.h = 100;

	destinationMute.x = 25;
	destinationMute.y = 550;
	destinationMute.w = 25;
	destinationMute.h = 25;
}

void MainMenu::resetCurrent(void)
{
	current[0] = button.idle;
	current[1] = button.idle;
	current[2] = button.idle;
}
