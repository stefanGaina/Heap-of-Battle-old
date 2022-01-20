#include "Border.h"
#include "TextureManager.h"

Border::Border(SDL_Renderer* renderer) : current(&human), renderer(renderer), destination({ 0, 0, SCALE, SCALE })
{
	loadTextures();
}

Border::~Border(void)
{
	destroyTextures();
}

void Border::draw(void)
{
	destination.x = 0;
	destination.y = 0;
	TextureManager::draw(current->wall.corner.NorthWest, destination, renderer);

	destination.x = (COLUMN - 1) * SCALE;
	TextureManager::draw(current->wall.corner.NorthEast, destination, renderer);

	destination.y = (ROW - 1) * SCALE;
	TextureManager::draw(current->wall.corner.SouthEast, destination, renderer);

	destination.x = 0;
	TextureManager::draw(current->wall.corner.SouthWest, destination, renderer);

	for (size_t column = 1; column < COLUMN - 1; ++column)
	{
		destination.x = column * SCALE;
		destination.y = 0;
		TextureManager::draw(current->wall.horizontal[column < 15 ? (column / 3) % 2 : (column / 2) % 2], destination, renderer);

		destination.y = (ROW - 1) * SCALE;
		TextureManager::draw(current->wall.horizontal[column < 13 ? (column / 2) % 2 : (column / 4) % 2], destination, renderer);
	}
	for (size_t row = 1; row < ROW - 1; ++row)
	{
		destination.x = 0;
		destination.y = row * SCALE;
		TextureManager::draw(current->wall.vertical[row < 7 ? row % 2 : (row /3) % 2], destination, renderer);

		destination.x = (COLUMN - 1) * SCALE;
		TextureManager::draw(current->wall.vertical[row < 10 ? (row / 2) % 2 : (row / 5) % 2], destination, renderer);
	}
	for (size_t row = 1; row < ROW - 1; ++row)
	{
		for (size_t column = 1; column < 4; ++column)
		{
			destination.x = column * SCALE;
			destination.y = row * SCALE;
			TextureManager::draw(current->stone[(row + column) % 2], destination, renderer);

			destination.x = (COLUMN - column - 1) * SCALE;
			TextureManager::draw(current->stone[(row + column) % 2], destination, renderer);
		}
	}
}

void Border::change(void)
{
	current = (current == &human) ? &orc : &human;
}

void Border::loadTextures(void)
{
	human.stone[0] = TextureManager::load("Assets/Human/Border/Stone.png", renderer);
	human.stone[1] = TextureManager::load("Assets/Human/Border/Stone1.png", renderer);
	human.wall.vertical[0] = TextureManager::load("Assets/Human/Border/Wall Vertical.png", renderer);
	human.wall.vertical[1] = TextureManager::load("Assets/Human/Border/Wall Vertical1.png", renderer);
	human.wall.horizontal[0] = TextureManager::load("Assets/Human/Border/Wall Horizontal.png", renderer);
	human.wall.horizontal[1] = TextureManager::load("Assets/Human/Border/Wall Horizontal1.png", renderer);

	human.wall.corner.NorthWest = TextureManager::load("Assets/Human/Border/Wall Corner NW.png", renderer);
	human.wall.corner.NorthEast = TextureManager::load("Assets/Human/Border/Wall Corner NE.png", renderer);
	human.wall.corner.SouthEast = TextureManager::load("Assets/Human/Border/Wall Corner SE.png", renderer);
	human.wall.corner.SouthWest = TextureManager::load("Assets/Human/Border/Wall Corner SW.png", renderer);

	orc.stone[0] = TextureManager::load("Assets/Orc/Border/Stone.png", renderer);
	orc.stone[1] = TextureManager::load("Assets/Orc/Border/Stone1.png", renderer);
	orc.wall.vertical[0] = TextureManager::load("Assets/Orc/Border/Wall Vertical.png", renderer);
	orc.wall.vertical[1] = TextureManager::load("Assets/Orc/Border/Wall Vertical1.png", renderer);
	orc.wall.horizontal[0] = TextureManager::load("Assets/Orc/Border/Wall Horizontal.png", renderer);
	orc.wall.horizontal[1] = TextureManager::load("Assets/Orc/Border/Wall Horizontal1.png", renderer);

	orc.wall.corner.NorthWest = TextureManager::load("Assets/Orc/Border/Wall Corner NW.png", renderer);
	orc.wall.corner.NorthEast = TextureManager::load("Assets/Orc/Border/Wall Corner NE.png", renderer);
	orc.wall.corner.SouthEast = TextureManager::load("Assets/Orc/Border/Wall Corner SE.png", renderer);
	orc.wall.corner.SouthWest = TextureManager::load("Assets/Orc/Border/Wall Corner SW.png", renderer);
}

void Border::destroyTextures(void)
{
	TextureManager::destroy(human.wall.corner.NorthWest);
	TextureManager::destroy(human.wall.corner.NorthEast);
	TextureManager::destroy(human.wall.corner.SouthEast);
	TextureManager::destroy(human.wall.corner.SouthWest);
	
	TextureManager::destroy(orc.wall.corner.NorthWest);
	TextureManager::destroy(orc.wall.corner.NorthEast);
	TextureManager::destroy(orc.wall.corner.SouthEast);
	TextureManager::destroy(orc.wall.corner.SouthWest);

	for (size_t i = 0; i < 2; ++i)
	{
		TextureManager::destroy(human.stone[i]);
		TextureManager::destroy(human.wall.vertical[i]);
		TextureManager::destroy(human.wall.horizontal[i]);

		TextureManager::destroy(orc.stone[i]);
		TextureManager::destroy(orc.wall.vertical[i]);
		TextureManager::destroy(orc.wall.horizontal[i]);
	}
}
