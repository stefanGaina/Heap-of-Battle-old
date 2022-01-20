#include "Game1.h"

Game1::Game1(SDL_Renderer* renderer, const Mouse& mouse, TileInfo* tile, Receipt human, Receipt orc, Uint8 turn) : 
	Game0(renderer, mouse), account(human, orc, turn), combat(renderer, tile), 
	map(renderer), menu(renderer), outline(renderer)
{
}

void Game1::render(void)
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

void Game1::handleEvents(void)
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
								case Engage::KEEP:
								{
									if (!humanBuilding(state))
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
				updateAltars();
				updateFarms();
				updateTowers();
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
					case SDLK_s:
					{
						if (combat.getEngaged() == Engage::PAUSE)
						{
							pause.save.write(combat.getTileInfo(), account.income.human.get(), account.income.orc.get(), account.turn.getValue(), '1');
						}
						break;
					}
					case SDLK_ESCAPE:
					{
						pauseGame();
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
	combat.checkPortals(!combat.animation.get());
}

void Game1::pauseGame(void)
{
	menu.set();
	caseUnit({ 0, 0 });
	outline.disable();
	
	pause.enable();
	combat.engage(Engage::PAUSE);

	sound.pause();
	sound.soundEffect.play(Sound::PAUSE);
}

void Game1::passTurn(void)
{
	account.turn.change();
	account.addYield();

	map.border.change();
	outline.change();
	cursor.change();

	combat.trainFarms(account.turn.getValue(), { account.human.farm.get(), account.orc.farm.get() });

	combat.refresh(account.turn.get());
	combat.highlight.set((Color)account.turn.get());

	combat.boostSpawns();
	combat.boostFarms();
	combat.boostTowers({ account.human.tower.get(), account.orc.tower.get() });

	menu.set();

	if (account.turn.get() == Faction::HUMAN && account.income.human.yield.get() != 0 || account.turn.get() == Faction::ORC && account.income.orc.yield.get() != 0)
	{
		sound.soundEffect.play(Sound::RECEIVE_GOLD);
	}
}

void Game1::humanNo(State state, Coordinate click)
{
	if (state == State::HUMAN_KEEP)
	{
		combat.engage(Engage::KEEP);
		menu.set(State::HUMAN_KEEP, 0, 0, account.human.vamp.get());
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
		state >= State::HUMAN_ALTAR && state <= State::HUMAN_TOWER ? menu.set(state) : menu.set();
	}
}

bool Game1::humanBuilding(State state)
{
	if (state >= State::TRAIN_HUMAN_INFANTRY && state <= State::TRAIN_HUMAN_WING)
	{
		if (combat.human.spawnAvailable())
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
	else if (state == State::VAMP_HUMAN_KEEP)
	{
		if (account.human.vamp.get())
		{
			sound.soundEffect.play(Sound::ERROR);
		}
		else
		{
			if (account.canAfford(State::HUMAN_KEEP))
			{
				map.building.vampHumanKeep();
				account.vamp(Faction::HUMAN);
				sound.soundEffect.play(Sound::VAMP);
				menu.set(State::HUMAN_KEEP, 0, 0, true);
			}
			else
			{
				sound.soundEffect.play(Sound::HUMAN_MORE_GOLD);
			}
		}
	}
	else
	{
		return false;
	}
	return true;
}

void Game1::orcNo(State state, Coordinate click)
{
	if (state == State::ORC_KEEP)
	{
		combat.engage(Engage::KEEP);
		menu.set(State::ORC_KEEP, 0, 0, account.orc.vamp.get());
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
		state >= State::ORC_TOWER && state <= State::ORC_ALTAR ? menu.set(state) : menu.set();
	}
}

bool Game1::orcBuilding(State state)
{
	if (state >= State::TRAIN_ORC_WING && state <= State::TRAIN_ORC_INFANTRY)
	{
		if (combat.orc.spawnAvailable())
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
	else if (state == State::VAMP_ORC_KEEP)
	{
		if (account.orc.vamp.get())
		{
			sound.soundEffect.play(Sound::ERROR);
		}
		else
		{
			if (account.canAfford(State::ORC_KEEP))
			{
				map.building.vampOrcKeep();
				account.vamp(Faction::ORC);
				sound.soundEffect.play(Sound::VAMP);
				menu.set(State::ORC_KEEP, 0, 0, true);
			}
			else
			{
				sound.soundEffect.play(Sound::ORC_MORE_GOLD);
			}
		}
	}
	else
	{
		return false;
	}
	return true;
}

bool Game1::caseUnit(Coordinate click)
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

void Game1::updateAltars(void)
{
	Flag flag = { combat.captureHumanAltar() , combat.captureOrcAltar() };
	
	account.altars(flag);
	map.building.updateAltars(flag);
}

void Game1::updateFarms(void)
{
	Flag flag = { combat.capturePoint({HUMAN_FARM_X, HUMAN_FARM_Y}), combat.capturePoint({ORC_FARM_X, ORC_FARM_Y }) };
	
	account.farms(flag);
	map.building.updateFarms(flag);
}

void Game1::updateTowers(void)
{
	Flag flag = { combat.captureHumanTower(), combat.captureOrcTower() };

	account.towers(flag);
	map.building.updateTowers(flag);
}

void Game1::checkVictory(void)
{
	if (combat.getState({ 17, 8 }) <= State::ORC_INFANTRY)
	{
		pauseGame();
		combat.engage(Engage::VICTORY);
		pause.victory.set(Faction::ORC);
		map.building.victory(Faction::ORC);
		sound.soundEffect.play(Sound::HUMAN_DEFEAT);
	}
	if (combat.getState({ 1, 16 }) >= State::HUMAN_INFANTRY)
	{
		pauseGame();
		combat.engage(Engage::VICTORY);
		pause.victory.set(Faction::HUMAN);
		map.building.victory(Faction::HUMAN);
		sound.soundEffect.play(Sound::ORC_DEFEAT);
	}
}
