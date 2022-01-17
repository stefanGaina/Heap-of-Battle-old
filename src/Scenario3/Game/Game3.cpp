#include "Game3.h"

Game3::Game3(SDL_Renderer* renderer, const Mouse& mouse) : 
	Game0(renderer, mouse), map(renderer)
{

}

void Game3::render(void)
{
	SDL_RenderClear(renderer);

	map.draw();

	SDL_RenderPresent(renderer);
}

void Game3::handleEvents(void)
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
				//outline.set(click, combat.getState(click));
				break;
			}
			//case SDL_MOUSEBUTTONDOWN:
			//{
			//	//sound.soundEffect.play(Sound::CLICK);

			//	if (account.turn.isHuman())
			//	{
			//		SDL_GetMouseState(&mouse.x, &mouse.y);

			//		Coordinate click = { mouse.y / SCALE, mouse.x / SCALE };
			//		State state = combat.getState(click);

			//		switch (state)
			//		{
			//			case State::HUMAN_PAUSE:
			//			{
			//				//pauseGame();
			//				break;
			//			}
			//			case State::HUMAN_PASS_TURN:
			//			{
			//				passTurn();
			//				break;
			//			}
			//			default:
			//			{
			//				switch (combat.getEngaged())
			//				{
			//					case Engage::NO:
			//					{
			//						humanNo(state, click);
			//						break;
			//					}
			//					case Engage::KEEP:
			//					{
			//						if (!humanBuilding(state))
			//						{
			//							humanNo(state, click);
			//						}
			//						break;
			//					}
			//					case Engage::UNIT:
			//					{
			//						if (!caseUnit(click))
			//						{
			//							humanNo(state, click);
			//						}
			//						break;
			//					}
			//					case Engage::PAUSE: // TEMPORARY
			//					{
			//						pause.disable();
			//						combat.engage();
			//						outline.enable();
			//						sound.resume();
			//						break;
			//					}
			//					case Engage::VICTORY:
			//					{
			//						stop();
			//					}
			//				}
			//			}
			//		}
			//	}
			//	else
			//	{
			//		SDL_GetMouseState(&mouse.x, &mouse.y);

			//		Coordinate click = { mouse.y / SCALE, mouse.x / SCALE };
			//		State state = combat.getState(click);

			//		switch (state)
			//		{
			//			case State::ORC_PAUSE:
			//			{
			//				pauseGame();
			//				break;
			//			}
			//			case State::ORC_PASS_TURN:
			//			{
			//				passTurn();
			//				break;
			//			}
			//			default:
			//			{
			//				switch (combat.getEngaged())
			//				{
			//					case Engage::NO:
			//					{
			//						orcNo(state, click);
			//						break;
			//					}
			//					case Engage::KEEP:
			//					{
			//						if (!orcBuilding(state))
			//						{
			//							orcNo(state, click);
			//						}
			//						break;
			//					}
			//					case Engage::UNIT:
			//					{
			//						if (!caseUnit(click))
			//						{
			//							orcNo(state, click);
			//						}
			//						break;
			//					}
			//					case Engage::PAUSE: // TEMPORARY
			//					{
			//						pause.disable();
			//						combat.engage();
			//						outline.enable();
			//						sound.resume();
			//						break;
			//					}
			//					case Engage::VICTORY:
			//					{
			//						stop();
			//					}
			//				}
			//			}
			//		}
			//	}
			//	checkVictory();
			//	break;
			//}
			//case SDL_KEYDOWN:
			//{
			//	switch (event.key.keysym.sym)
			//	{
			//		case SDLK_SPACE:
			//		{
			//			passTurn();
			//			break;
			//		}
			//		case SDLK_b:
			//		{
			//			caseUnit({ 0,0 });

			//			if (account.turn.isHuman())
			//			{
			//				humanNo(State::HUMAN_KEEP);
			//			}
			//			else
			//			{
			//				orcNo(State::ORC_KEEP);
			//			}
			//			break;
			//		}
			//	}
			//	break;
			//}
			case SDL_QUIT:
			{
				stop();
			}
		}
	}
	//combat.animation.set(combat.queue.getThis());
	//combat.checkPortals(!combat.animation.get());
}
