#include "SelectMap.h"
#include "TextureManager.h"

SelectIcon::SelectIcon(SDL_Texture* scenario, SDL_Texture* tutorial, SDL_Texture* start) :
	scenario(scenario), tutorial(tutorial), start(start)
{
}

SelectIcon::~SelectIcon(void)
{
	TextureManager::destroy(scenario);
	TextureManager::destroy(tutorial);
	TextureManager::destroy(start);
}

SelectMap::SelectMap(CursorMenu* cursor, const SoundMenu& sound, const Mouse& mouse, SDL_Renderer* renderer) :
	idle(TextureManager::load("Assets/General/Menu/Select Scenario/Scenario Icon Idle.png", renderer),
		TextureManager::load("Assets/General/Menu/Select Scenario/Tutorial Icon Idle.png", renderer),
		TextureManager::load("Assets/General/Menu/Select Scenario/Start Icon Idle.png", renderer)),
	selected(TextureManager::load("Assets/General/Menu/Select Scenario/Scenario Icon Selected.png", renderer),
		TextureManager::load("Assets/General/Menu/Select Scenario/Tutorial Icon Selected.png", renderer),
		TextureManager::load("Assets/General/Menu/Select Scenario/Start Icon Selected.png", renderer)),
	background(TextureManager::load("Assets/General/Menu/Select Scenario/Background.png", renderer)),
	cursor(cursor), sound(sound), mouse(mouse), renderer(renderer), destination({ 0, 0, SCALE, SCALE })
{
	scenario[0] = TextureManager::load("Assets/General/Menu/Select Scenario/Tutorial.png", renderer);
	scenario[1] = TextureManager::load("Assets/General/Menu/Select Scenario/Scenario1.png", renderer);
	scenario[2] = TextureManager::load("Assets/General/Menu/Select Scenario/Scenario2.png", renderer);
	scenario[3] = TextureManager::load("Assets/General/Menu/Select Scenario/Scenario3.png", renderer);

	resetCurrent();
}

SelectMap::~SelectMap(void)
{
	for (Uint8 i = 0; i < 4; ++i)
	{
		TextureManager::destroy(scenario[i]);
	}
	TextureManager::destroy(background);
}

void SelectMap::render(void)
{
	SDL_RenderClear(renderer);

	TextureManager::draw(background, { 0, 0, COLUMN * SCALE, ROW * SCALE }, renderer);

	switch (engaged)
	{
		case SelectEngage::NO:
		{
			break;
		}
		case SelectEngage::TUTORIAL:
		{
			TextureManager::draw(scenario[0], { 250, 350, 300, 251 }, renderer);

			destination.x = 8 * SCALE;
			destination.y = 17 * SCALE + SCALE / 2;
			TextureManager::draw(current[4], destination, renderer);
			break;
		}
		case SelectEngage::SCENARIO_1:
		{
			TextureManager::draw(scenario[1], { 250, 350, 300, 251 }, renderer);

			destination.x = 8 * SCALE;
			destination.y = 17 * SCALE + SCALE / 2;
			TextureManager::draw(current[4], destination, renderer);
			break;
		}
		case SelectEngage::SCENARIO_2:
		{
			TextureManager::draw(scenario[2], { 250, 350, 300, 251 }, renderer);

			destination.x = 8 * SCALE;
			destination.y = 17 * SCALE + SCALE / 2;
			TextureManager::draw(current[4], destination, renderer);
			break;
		}
		case SelectEngage::SCENARIO_3:
		{
			TextureManager::draw(scenario[3], { 250, 350, 300, 251 }, renderer);

			destination.x = 8 * SCALE;
			destination.y = 17 * SCALE + SCALE / 2;
			TextureManager::draw(current[4], destination, renderer);
		}
	}
	destination.x = 17 * SCALE;
	destination.y = 8 * SCALE;
	TextureManager::draw(current[0], destination, renderer);

	destination.x = 19 * SCALE;
	destination.y = 11 * SCALE;
	TextureManager::draw(current[1], destination, renderer);

	destination.x = 10 * SCALE;
	destination.y = 5 * SCALE;
	TextureManager::draw(current[2], destination, renderer);

	destination.x = 6 * SCALE;
	destination.y = 7 * SCALE;
	TextureManager::draw(current[3], destination, renderer);

	cursor->draw(mouse);

	SDL_RenderPresent(renderer);
}

void SelectMap::handleEvents(void)
{
	SDL_Event event;

	if (SDL_PollEvent(&event) != 0)
	{
		switch (event.type)
		{
			case SDL_MOUSEMOTION:
			{
				SDL_GetMouseState(&mouse.x, &mouse.y);

				Coordinate click = { mouse.y / SCALE, mouse.x / SCALE };
				
				if (click.x == 8 && click.y == 17)
				{
					current[0] = selected.tutorial;
				}
				else if (click.x == 5 && click.y == 10)
				{
						current[2] = selected.scenario;
				}
				else if (click.x == 11 && click.y == 19)
				{
					current[1] = selected.scenario;
				}
				else if (click.x == 7 && click.y == 6)
				{
					current[3] = selected.scenario;
				}
				else
				{
					resetCurrent();
				}
				if (engaged != SelectEngage::NO && mouse.x >= 250 && mouse. x <= 550 && mouse.y >= 350 && mouse.y <= 600)
				{
					current[4] = selected.start;
				}
				else
				{
					current[4] = idle.start;
				}
				break;
			}
			case SDL_MOUSEBUTTONDOWN:
			{
				sound.play();

				if (current[4] == selected.start)
				{
					stop();
				}
				else if (current[0] == selected.tutorial)
				{
					engaged = SelectEngage::TUTORIAL;
				}
				else if (current[1] == selected.scenario)
				{
					engaged = SelectEngage::SCENARIO_1;
				}
				else if (current[2] == selected.scenario)
				{
					engaged = SelectEngage::SCENARIO_2;
				}
				else if (current[3] == selected.scenario)
				{
					engaged = SelectEngage::SCENARIO_3;
				}
				else
				{
					engaged = SelectEngage::NO;
				}
				break;
			}
			case SDL_KEYDOWN:
			{
				switch (event.key.keysym.sym)
				{
					case SDLK_ESCAPE:
					{
						engaged = SelectEngage::NO;
						stop();
					}
				}
				break;
			}
			case SDL_QUIT:
			{
				engaged = SelectEngage::NO;
				stop();
				break;
			}
		}
	}
}

void SelectMap::resetCurrent(void)
{
	current[0] = idle.tutorial;
	current[1] = idle.scenario;
	current[2] = idle.scenario;
	current[3] = idle.scenario;
	current[4] = idle.start;
}

Sint8 SelectMap::code(void)
{
	return (Sint8)engaged;
}
