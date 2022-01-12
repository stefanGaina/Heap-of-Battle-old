#include "Write.h"
#include "TextureManager.h"

Colors::Colors(void) : gold({ 0xFF, 0xDF, 0x00, 0xFF }), gray({ 0x69, 0x69, 0x69, 0xFF }), blue({ 0x15, 0x89, 0xFF, 0xFF }), red({ 0x99, 0x00, 0x12, 0xFF })
{
}

IncomeText::IncomeText(SDL_Texture* gold, SDL_Texture* yield) : gold(gold), yield(yield)
{
}

IncomeText::~IncomeText(void)
{
	TextureManager::destroy(gold);
	TextureManager::destroy(yield);
}

Text::~Text(void)
{
	TextureManager::destroy(pause);
	TextureManager::destroy(pass);

	for (Uint8 i = 0; i < 6; ++i)
	{
		TextureManager::destroy(digit[i]);
	}
}

Write::Write(SDL_Renderer* renderer) : font(TTF_OpenFont("Assets/General/Misc/Fonts/Aller_Rg.ttf", 72)), renderer(renderer), destination({ 0, 0, SCALE, SCALE }),
									   current(TextureManager::createText(font, "Gold", color.gold, renderer), TextureManager::createText(font, "Yield", color.gold, renderer)), 
									   neutral(TextureManager::createText(font, "Gold", color.gray, renderer), TextureManager::createText(font, "Yield", color.gray, renderer))
{

	Text* auxiliary = &human;
	SDL_Color* color = &this->color.blue;

	for (Uint8 i = 0; i < 2; ++i)
	{
		auxiliary->pause = TextureManager::createText(font, "Pause", *color, renderer);
		auxiliary->pass = TextureManager::createText(font, "Pass", *color, renderer);
		auxiliary->train = TextureManager::createText(font, "Train", *color, renderer);
		auxiliary->act = TextureManager::createText(font, "Act", *color, renderer);

		for (Uint8 j = 0; j < 6; ++j)
		{
			char buffer[2];
			_itoa_s(j, buffer, 10);
			buffer[1] = '\0';

			auxiliary->digit[j] = TextureManager::createText(font, buffer, *color, renderer);
		}
		auxiliary = &orc;
		color = &this->color.red;
	}
	price[0] = TextureManager::createText(font, "5", this->color.gold, renderer);
	price[1] = TextureManager::createText(font, "10", this->color.gold, renderer);
	price[2] = TextureManager::createText(font, "20", this->color.gold, renderer);
	price[3] = TextureManager::createText(font, "30", this->color.gold, renderer);
	price[4] = TextureManager::createText(font, "40", this->color.gold, renderer);
}

Write::~Write(void)
{
	TTF_CloseFont(font);
	font = nullptr;
}

void Write::draw(Faction turn, State type, Receipt human, Receipt orc, Uint8 actionsLeft)
{
	switch (turn)
	{
		case Faction::HUMAN:
		{
			destination.x = SCALE;
			destination.y = SCALE;
			TextureManager::draw(current.gold, destination, renderer);

			destination.y += SCALE;
			TextureManager::draw(current.yield, destination, renderer);

			destination.x = 2 * SCALE + SCALE / 2;
			destination.y = SCALE;
			variableValueText(this->human.gold, color.gold, human.gold);
			TextureManager::draw(this->human.gold, destination, renderer);

			destination.y += SCALE;
			variableValueText(this->human.yield, color.gold, human.yield);
			TextureManager::draw(this->human.yield, destination, renderer);

			destination.y = 15 * SCALE;
			TextureManager::draw(this->human.pause, destination, renderer);

			destination.y += 2 * SCALE;
			TextureManager::draw(this->human.pass, destination, renderer);

			destination.x = 23 * SCALE;
			destination.y = SCALE;
			TextureManager::draw(neutral.gold, destination, renderer);

			destination.x -= SCALE + SCALE / 2;
			variableValueText(this->orc.gold, color.gray, orc.gold);
			TextureManager::draw(this->orc.gold, destination, renderer);

			destination.y += SCALE;
			variableValueText(this->orc.yield, color.gray, orc.yield);
			TextureManager::draw(this->orc.yield, destination, renderer);

			destination.x += SCALE + SCALE / 2;
			TextureManager::draw(neutral.yield, destination, renderer);

			switch (type)
			{
				case State::NEUTRAL:
				{
					break;
				}
				case State::HUMAN_KEEP:
				{
					destination.x = 2 * SCALE;
					for (destination.y = 4 * SCALE; destination.y < 12 * SCALE; destination.y += 2 * SCALE)
					{
						TextureManager::draw(this->human.train, destination, renderer);
					}
					destination.x = 3 * SCALE;
					destination.y = 4 * SCALE;
					TextureManager::draw(price[0], destination, renderer);

					destination.y += 2 * SCALE;
					TextureManager::draw(price[1], destination, renderer);

					destination.y += 2 * SCALE;
					TextureManager::draw(price[2], destination, renderer);

					destination.y += 2 * SCALE;
					TextureManager::draw(price[3], destination, renderer);

					destination.y += 2 * SCALE;
					TextureManager::draw(price[4], destination, renderer);
					break;
				}
				case State::HUMAN_ALTAR:
				{
					break;
				}
				case State::HUMAN_FARM:
				{
					break;
				}
				case State::HUMAN_TOWER:
				{
					break;
				}
				default:
				{
					destination.x = 3 * SCALE;
					destination.y = 4 * SCALE;
					TextureManager::draw(this->human.digit[actionsLeft], destination, renderer);

					destination.x -= SCALE;
					TextureManager::draw(this->human.act, destination, renderer);
				}
			}
			break;
		}
		case Faction::ORC:
		{
			destination.x = 23 * SCALE;
			destination.y = SCALE;
			TextureManager::draw(current.gold, destination, renderer);

			destination.y += SCALE;
			TextureManager::draw(current.yield, destination, renderer);

			destination.x -= SCALE + SCALE / 2;
			destination.y = SCALE;
			variableValueText(this->orc.gold, color.gold, orc.gold);
			TextureManager::draw(this->orc.gold, destination, renderer);

			destination.y += SCALE;
			variableValueText(this->orc.yield, color.gold, orc.yield);
			TextureManager::draw(this->orc.yield, destination, renderer);

			destination.y = 15 * SCALE;
			TextureManager::draw(this->orc.pause, destination, renderer);

			destination.y = 17 * SCALE;
			TextureManager::draw(this->orc.pass, destination, renderer);

			destination.x = SCALE;
			destination.y = SCALE;
			TextureManager::draw(neutral.gold, destination, renderer);

			destination.x += SCALE + SCALE / 2;
			variableValueText(this->human.gold, color.gray, human.gold);
			TextureManager::draw(this->human.gold, destination, renderer);

			destination.y += SCALE;
			variableValueText(this->human.yield, color.gray, human.yield);
			TextureManager::draw(this->human.yield, destination, renderer);

			destination.x -= SCALE + SCALE / 2;
			TextureManager::draw(neutral.yield, destination, renderer);

			switch (type)
			{
				case State::NEUTRAL:
				{
					break;
				}
				case State::ORC_KEEP:
				{
					destination.x = 22 * SCALE;
					for (destination.y = 4 * SCALE; destination.y < 12 * SCALE; destination.y += 2 * SCALE)
					{
						TextureManager::draw(this->orc.train, destination, renderer);
					}
					destination.x = 21 * SCALE;
					destination.y = 4 * SCALE;
					TextureManager::draw(price[0], destination, renderer);

					destination.y += 2 * SCALE;
					TextureManager::draw(price[1], destination, renderer);

					destination.y += 2 * SCALE;
					TextureManager::draw(price[2], destination, renderer);

					destination.y += 2 * SCALE;
					TextureManager::draw(price[3], destination, renderer);

					destination.y += 2 * SCALE;
					TextureManager::draw(price[4], destination, renderer);
					break;
				}
				case State::ORC_ALTAR:
				{
					break;
				}
				case State::ORC_FARM:
				{
					break;
				}
				case State::ORC_TOWER:
				{
					break;
				}
				default:
				{
					destination.x = 21 * SCALE;
					destination.y = 4 * SCALE;
					TextureManager::draw(this->orc.digit[actionsLeft], destination, renderer);

					destination.x += SCALE;
					TextureManager::draw(this->orc.act, destination, renderer);
				}
			}
		}
	}
}

void Write::variableValueText(SDL_Texture*& texture, SDL_Color color, Uint8 value)
{
	TextureManager::destroy(texture);
	texture = TextureManager::createText(font, std::to_string(value).c_str(), color, renderer);
}
