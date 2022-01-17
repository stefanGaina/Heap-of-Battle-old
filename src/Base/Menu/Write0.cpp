#include "Write0.h"
#include "TextureManager.h"

Colors::Colors(void) : 
	gold({ 0xFF, 0xDF, 0x00, 0xFF }), gray({ 0x69, 0x69, 0x69, 0xFF }),
	blue({ 0x15, 0x89, 0xFF, 0xFF }), red({ 0x99, 0x00, 0x12, 0xFF })
{
}

IncomeText::IncomeText(SDL_Texture* gold, SDL_Texture* yield) : 
	gold(gold), yield(yield)
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

	for (size_t i = 0; i < 6; ++i)
	{
		TextureManager::destroy(digit[i]);
	}
}

Write0::Write0(SDL_Renderer* renderer, Uint8 lastPrice) : 
	font(TTF_OpenFont("Assets/General/Misc/Fonts/Aller_Rg.ttf", 72)), renderer(renderer), destination({ 0, 0, SCALE, SCALE }),
	current(TextureManager::createText(font, "Gold", color.gold, renderer), TextureManager::createText(font, "Yield", color.gold, renderer)), 
	neutral(TextureManager::createText(font, "Gold", color.gray, renderer), TextureManager::createText(font, "Yield", color.gray, renderer))
{

	Text* auxiliary = &human;
	SDL_Color* color = &this->color.blue;

	for (size_t i = 0; i < 2; ++i)
	{
		auxiliary->pause = TextureManager::createText(font, "Pause", *color, renderer);
		auxiliary->pass = TextureManager::createText(font, "Pass", *color, renderer);
		auxiliary->train = TextureManager::createText(font, "Train", *color, renderer);
		auxiliary->act = TextureManager::createText(font, "Act", *color, renderer);

		for (size_t j = 0; j < 6; ++j)
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
	price[4] = TextureManager::createText(font, std::to_string(lastPrice).c_str(), this->color.gold, renderer);
}

Write0::~Write0(void)
{
	TTF_CloseFont(font);
	font = nullptr;
}

void Write0::humanAlways(Receipt human, Receipt orc)
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
}

void Write0::orcAlways(Receipt human, Receipt orc)
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
}

void Write0::humanKeep(void)
{
	destination.x = 2 * SCALE;
	for (destination.y = 4 * SCALE; destination.y < 12 * SCALE; destination.y += 2 * SCALE)
	{
		TextureManager::draw(human.train, destination, renderer);
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
}

void Write0::orcKeep(void)
{
	destination.x = 22 * SCALE;
	for (destination.y = 4 * SCALE; destination.y < 12 * SCALE; destination.y += 2 * SCALE)
	{
		TextureManager::draw(orc.train, destination, renderer);
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
}

void Write0::humanUnit(Uint8 actionsLeft)
{
	destination.x = 3 * SCALE;
	destination.y = 4 * SCALE;
	TextureManager::draw(human.digit[actionsLeft], destination, renderer);

	destination.x -= SCALE;
	TextureManager::draw(human.act, destination, renderer);
}

void Write0::orcUnit(Uint8 actionsLeft)
{
	destination.x = 21 * SCALE;
	destination.y = 4 * SCALE;
	TextureManager::draw(orc.digit[actionsLeft], destination, renderer);

	destination.x += SCALE;
	TextureManager::draw(orc.act, destination, renderer);
}

void Write0::variableValueText(SDL_Texture*& texture, SDL_Color color, Uint8 value)
{
	TextureManager::destroy(texture);
	texture = TextureManager::createText(font, std::to_string(value).c_str(), color, renderer);
}
