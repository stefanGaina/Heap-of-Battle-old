#include "Game2.h"

Game2::Game2(SDL_Renderer* renderer, const Mouse& mouse) : 
	Game0(renderer, mouse), account({ 5, 15 }, { 0, 15 }), combat(renderer), map(renderer), menu(renderer), outline(renderer)
{
}

void Game2::render(void)
{
	SDL_RenderClear(renderer);

	map.draw();
	menu.draw(account.income.human.get(), account.income.orc.get(), account.turn.get());

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
									if (!humanKeep1(state))
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
								case Engage::KEEP:
								{
									if (!orcBuilding(state))
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
				checkVictory();
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
	account.turn.change();
	account.addYield();

	map.border.change();
	outline.change();
	cursor.change();

	//combat.trainFarms(account.turn.getValue(), { account.human.farm.get(), account.orc.farm.get() });

	combat.refresh(account.turn.get());
	combat.highlight.set((Color)account.turn.get());

	//combat.unit.boostSpawns();
	//combat.boostFarms();
	//combat.boostTowers({ account.human.farm.get(), account.orc.farm.get() });

	menu.set();

	if (account.turn.get() == Faction::HUMAN && account.income.human.yield.get() != 0 || account.turn.get() == Faction::ORC && account.income.orc.yield.get() != 0)
	{
		sound.soundEffect.play(Sound::RECEIVE_GOLD);
	}
}

void Game2::humanNo(State state, Coordinate click)
{
	if (state == State::HUMAN_KEEP_1)
	{
		combat.engage(Engage::KEEP_1);
		menu.set(State::HUMAN_KEEP, 0, 0);
	}
	else
	{
		if (state >= State::HUMAN_INFANTRY && state <= State::HUMAN_WING)
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
}

bool Game2::humanKeep1(State state)
{
	if (state >= State::TRAIN_HUMAN_INFANTRY && state <= State::TRAIN_HUMAN_WING)
	{
		if (combat.unit.humanSpawnAvailable())
		{
			state = (State)((Uint8)state - 10); // conversion from train_unit to unit

			if (account.canAfford(state))
			{
				combat.train(state);
				sound.voiceLine.play(state, Sound::TRAIN);
				menu.set(state, combat.getActions({ 17, 8 }), false);
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
	if (state == State::ORC_KEEP)
	{
		combat.engage(Engage::KEEP);
		menu.set(State::ORC_KEEP, 0, 0);
	}
	else
	{
		if (state >= State::ORC_WING && state <= State::ORC_INFANTRY)
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
}

bool Game2::orcBuilding(State state)
{
	if (state >= State::TRAIN_ORC_WING && state <= State::TRAIN_ORC_INFANTRY)
	{
		if (combat.unit.orcSpawnAvailable())
		{
			state = (State)((Sint8)state + 10);

			if (account.canAfford(state))
			{
				combat.train(state);
				sound.voiceLine.play(state, Sound::TRAIN);
				menu.set(state, combat.getActions({ 1, 16 }), false);
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
		if (state == State::VAMP_ORC_KEEP)
		{
			/*if (account.orc.vamp.get())
			{
				sound.soundEffect.play(Sound::error);
			}
			else
			{
				if (account.canAfford(State::orc_keep))
				{
					map.building.vampOrcKeep();
					account.vamp(Faction::orc);
					sound.soundEffect.play(Sound::vamp);
					menu.set(State::orc_keep, 0, 0, true);
				}
				else
				{
					sound.soundEffect.play(Sound::orc_more_gold);
				}
			}*/
		}
		else
		{
			return false;
		}
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

}
