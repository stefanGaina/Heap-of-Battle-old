#include "Game2.h"
#include "Log.h"

Game2::Game2(SDL_Renderer* renderer, const Mouse& mouse) : 
	Game0(renderer, mouse), account({ 5, 15 }, { 0, 15 }), combat(renderer), map(renderer), menu(renderer), outline(renderer)
{
}

void Game2::render(void)
{
	SDL_RenderClear(renderer);

	map.draw();
	combat.draw();
	menu.draw(account.income.human.get(), account.income.orc.get(), account.turn.get());

	pause.draw();
	pause.victory.draw();
	outline.draw();
	cursor.draw(mouse);

	SDL_RenderPresent(renderer);
}

void Game2::handleEvents(void)
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
				outline.set(click, combat.getState(click));
				break;
			}
			case SDL_MOUSEBUTTONDOWN:
			{
				sound.soundEffect.play(Sound::CLICK);

				if (account.turn.isHuman())
				{
					SDL_GetMouseState(&mouse.x, &mouse.y);

					Coordinate click = { mouse.y / SCALE, mouse.x / SCALE };
					State state = combat.getState(click);
#ifdef DEBUG
					LOG("(" << (int)click.x << ", " << (int)click.y << ")");
#endif
					switch (state)
					{
						case State::HUMAN_PAUSE:
						{
							pauseGame();
							break;
						}
						case State::HUMAN_PASS_TURN:
						{
							passTurn();
							break;
						}
						default:
						{
							switch (combat.getEngaged())
							{
								case Engage::NO:
								{
									humanNo(state, click);
									break;
								}
								case Engage::KEEP_1:
								{
								}
								case Engage::KEEP_2:
								{
									if (!humanKeep(state))
									{
										humanNo(state, click);
									}
									break;
								}
								case Engage::UNIT:
								{
									if (!caseUnit(click))
									{
										humanNo(state, click);
									}
									break;
								}
								case Engage::PAUSE: // TEMPORARY
								{
									pause.disable();
									combat.engage();
									outline.enable();
									sound.resume();
									break;
								}
								case Engage::VICTORY:
								{
									stop();
								}
							}
						}
					}
				}
				else
				{
					SDL_GetMouseState(&mouse.x, &mouse.y);

					Coordinate click = { mouse.y / SCALE, mouse.x / SCALE };
					State state = combat.getState(click);

					switch (state)
					{
						case State::ORC_PAUSE:
						{
							pauseGame();
							break;
						}
						case State::ORC_PASS_TURN:
						{
							passTurn();
							break;
						}
						default:
						{
							switch (combat.getEngaged())
							{
								case Engage::NO:
								{
									orcNo(state, click);
									break;
								}
								case Engage::KEEP_1:
								{
								}
								case Engage::KEEP_2:
								{
									if (!orcKeep(state))
									{
										orcNo(state, click);
									}
									break;
								}
								case Engage::UNIT:
								{
									if (!caseUnit(click))
									{
										orcNo(state, click);
									}
									break;
								}
								case Engage::PAUSE: // TEMPORARY
								{
									pause.disable();
									combat.engage();
									outline.enable();
									sound.resume();
									break;
								}
								case Engage::VICTORY:
								{
									stop();
								}
							}
						}
					}
				}
				checkVictory(); //
				break;
			}
			case SDL_KEYDOWN:
			{
				switch (event.key.keysym.sym)
				{
					case SDLK_SPACE:
					{
						passTurn();
						break;
					}
					case SDLK_b:
					{
						caseUnit({ 0,0 });

						if (account.turn.isHuman())
						{
							humanNo(State::HUMAN_KEEP);
						}
						else
						{
							orcNo(State::ORC_KEEP);
						}
						break;
					}
				}
				break;
			}
			case SDL_QUIT:
			{
				stop();
			}
		}
	}
	combat.animation.set(combat.queue.getThis());
	//combat.checkPortals(!combat.animation.get());
}

void Game2::pauseGame(void)
{
	menu.set();
	caseUnit({ 0, 0 });
	outline.disable();

	pause.enable();
	combat.engage(Engage::PAUSE);

	sound.pause();
	sound.soundEffect.play(Sound::PAUSE);
}

void Game2::passTurn(void)
{
	sound.soundEffect.play(Sound::RECEIVE_GOLD);

	account.turn.change();
	account.addYield();

	map.border.change();
	outline.change();
	cursor.change();

	combat.refresh(account.turn.get());
	combat.highlight.set((Color)account.turn.get());
	combat.boostSpawns();

	menu.set();
}

void Game2::humanNo(State state, Coordinate click)
{
	if (state == State::HUMAN_KEEP_1)
	{
		combat.engage(Engage::KEEP_1);
		menu.set(State::HUMAN_KEEP);
	}
	else if (state == State::HUMAN_KEEP_2)
	{
		combat.engage(Engage::KEEP_2);
		menu.set(State::HUMAN_KEEP);
	}
	else if (state >= State::HUMAN_INFANTRY && state <= State::HUMAN_WING)
	{
		sound.voiceLine.play(state, Sound::SELECT);
		combat.engage(Engage::UNIT, click);
		menu.set(state, combat.getActions(click), combat.getAttacked(click));
	}
	else
	{
		combat.engage();
		menu.set();
	}
}

bool Game2::humanKeep(State state)
{
	if (state >= State::TRAIN_HUMAN_INFANTRY && state <= State::TRAIN_HUMAN_WING)
	{
		if (combat.humanSpawnAvailable())
		{
			state = (State)((int)state - 10); // conversion from train_unit to unit

			if (account.canAfford(state))
			{
				combat.train(state);
				sound.voiceLine.play(state, Sound::TRAIN);
				menu.set(state, combat.getActions(combat.getHumanSpawn()), false);
			}
			else
			{
				sound.soundEffect.play(Sound::HUMAN_MORE_GOLD);
			}
		}
		else
		{
			sound.soundEffect.play(Sound::ERROR);
		}
	}
	else
	{
		return false;
	}
	return true;
}

void Game2::orcNo(State state, Coordinate click)
{
	if (state == State::ORC_KEEP_1)
	{
		combat.engage(Engage::KEEP);
		menu.set(State::ORC_KEEP);
	}
	else if (state == State::ORC_KEEP_2)
	{
		combat.engage(Engage::KEEP_2);
		menu.set(State::ORC_KEEP);
	}
	else if (state >= State::ORC_WING && state <= State::ORC_INFANTRY)
	{
		sound.voiceLine.play(state, Sound::SELECT);
		combat.engage(Engage::UNIT, click);
		menu.set(state, combat.getActions(click), combat.getAttacked(click));
	}
	else
	{
		combat.engage();
		menu.set();
	}
}

bool Game2::orcKeep(State state)
{
	if (state >= State::TRAIN_ORC_WING && state <= State::TRAIN_ORC_INFANTRY)
	{
		if (combat.orcSpawnAvailable())
		{
			state = (State)((Sint8)state + 10);

			if (account.canAfford(state))
			{
				combat.train(state);
				sound.voiceLine.play(state, Sound::TRAIN);
				menu.set(state, combat.getActions(combat.getOrcSpawn()), false);
			}
			else
			{
				sound.soundEffect.play(Sound::ORC_MORE_GOLD);
			}
		}
		else
		{
			sound.soundEffect.play(Sound::ERROR);
		}
	}
	else
	{
		return false;
	}
	return true;
}

bool Game2::caseUnit(Coordinate click)
{
	if (combat.canMove(click))
	{
		combat.movement.MoveUnit(click, combat.queue.getThis());

		if (combat.movement.isAttack())
		{
			sound.voiceLine.play(combat.getState(click), Sound::ATTACK);
		}
		else
		{
			sound.voiceLine.play(combat.getState(click), Sound::MOVE);
		}
		if (combat.canAct(click))
		{
			menu.set(combat.getState(click), combat.getActions(click), combat.getAttacked(click));
		}
		else
		{
			menu.set();
		}
		return true;
	}
	return false;
}

void Game2::checkVictory(void)
{
	// TO DO
}
