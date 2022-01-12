#include "Grid1.h"

Grid1::Grid1(SDL_Renderer* renderer) : Grid0(renderer)
{
}

void Grid1::draw(void)
{
	horizontalBlack();
	verticalBlack();

	horizontalGray();
	verticalGray();
}

void Grid1::horizontalBlack(void)
{
	SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xAF); // black

	Uint16 row = SCALE;
	SDL_RenderDrawLine(renderer, 5 * SCALE, row, 21 * SCALE, row);

	row += SCALE;
	SDL_RenderDrawLine(renderer, 5 * SCALE, row, 7 * SCALE, row);
	SDL_RenderDrawLine(renderer, 15 * SCALE, row, 16 * SCALE, row);

	for (row += SCALE; row < 6 * SCALE; row += SCALE)
	{
		SDL_RenderDrawLine(renderer, 4 * SCALE, row, 17 * SCALE, row);
	}
	for (; row < 9 * SCALE; row += SCALE)
	{
		SDL_RenderDrawLine(renderer, 4 * SCALE, row, 10 * SCALE, row);
		SDL_RenderDrawLine(renderer, 15 * SCALE, row, 21 * SCALE, row);
	}

	row += 2 * SCALE;
	SDL_RenderDrawLine(renderer, 19 * SCALE, row, 21 * SCALE, row);

	for (row += SCALE; row < 14 * SCALE; row += SCALE)
	{
		SDL_RenderDrawLine(renderer, 4 * SCALE, row, 10 * SCALE, row);
		SDL_RenderDrawLine(renderer, 15 * SCALE, row, 21 * SCALE, row);
	}
	SDL_RenderDrawLine(renderer, 4 * SCALE, row, 21 * SCALE, row);

	for (row += SCALE; row < 17 * SCALE; row += SCALE)
	{
		SDL_RenderDrawLine(renderer, 8 * SCALE, row, 21 * SCALE, row);
	}
	SDL_RenderDrawLine(renderer, 9 * SCALE, row, 10 * SCALE, row);
	SDL_RenderDrawLine(renderer, 17 * SCALE, row, 21 * SCALE, row);

	row += SCALE;
	SDL_RenderDrawLine(renderer, 8 * SCALE, row, 21 * SCALE, row);
}

void Grid1::verticalBlack(void)
{
	Uint16 column = 4 * SCALE;
	SDL_RenderDrawLine(renderer, column, 2 * SCALE, column, 13 * SCALE);

	for (column += SCALE; column < 8 * SCALE; column += SCALE)
	{
		SDL_RenderDrawLine(renderer, column, SCALE, column, 9 * SCALE);
		SDL_RenderDrawLine(renderer, column, 11 * SCALE, column, 14 * SCALE);
	}
	SDL_RenderDrawLine(renderer, column, SCALE, column, 8 * SCALE);
	SDL_RenderDrawLine(renderer, column, 11 * SCALE, column, 14 * SCALE);

	for (column += SCALE; column < 11 * SCALE; column += SCALE)
	{
		SDL_RenderDrawLine(renderer, column, 3 * SCALE, column, 8 * SCALE);
		SDL_RenderDrawLine(renderer, column, 11 * SCALE, column, 18 * SCALE);
	}
	for (; column < 15 * SCALE; column += SCALE)
	{
		SDL_RenderDrawLine(renderer, column, 3 * SCALE, column, 5 * SCALE);
		SDL_RenderDrawLine(renderer, column, 14 * SCALE, column, 16 * SCALE);
	}
	for (; column < 18 * SCALE; column += SCALE)
	{
		SDL_RenderDrawLine(renderer, column, SCALE, column, 8 * SCALE);
		SDL_RenderDrawLine(renderer, column, 11 * SCALE, column, 16 * SCALE);
	}
	for (; column < 22 * SCALE; column += SCALE)
	{
		SDL_RenderDrawLine(renderer, column, 5 * SCALE, column, 8 * SCALE);
		SDL_RenderDrawLine(renderer, column, 10 * SCALE, column, 18 * SCALE);
	}
}

void Grid1::horizontalGray(void)
{
	SDL_SetRenderDrawColor(renderer, 0x69, 0x69, 0x69, 0xAF); // nice

	Uint16 row = SCALE;
	SDL_RenderDrawLine(renderer, 4 * SCALE, row, 5 * SCALE, row);
	SDL_RenderDrawLine(renderer, 7 * SCALE, row, 10 * SCALE, row);
	SDL_RenderDrawLine(renderer, 16 * SCALE, row, 21 * SCALE, row);

	row += SCALE;
	SDL_RenderDrawLine(renderer, 4 * SCALE, row, 5 * SCALE, row);
	SDL_RenderDrawLine(renderer, 7 * SCALE, row, 8 * SCALE, row);
	SDL_RenderDrawLine(renderer, 16 * SCALE, row, 17 * SCALE, row);

	row += SCALE;
	SDL_RenderDrawLine(renderer, 4 * SCALE, row, 5 * SCALE, row);
	SDL_RenderDrawLine(renderer, 8 * SCALE, row, 10 * SCALE, row);

	row += 2 * SCALE;
	SDL_RenderDrawLine(renderer, 17 * SCALE, row, 21 * SCALE, row);

	row += SCALE;
	SDL_RenderDrawLine(renderer, 19 * SCALE, row, 21 * SCALE, row);

	row += SCALE;
	SDL_RenderDrawLine(renderer, 7 * SCALE, row, 10 * SCALE, row);

	row += SCALE;
	SDL_RenderDrawLine(renderer, 6 * SCALE, row, 10 * SCALE, row);
	SDL_RenderDrawLine(renderer, 15 * SCALE, row, 21 * SCALE, row);

	row += SCALE;
	SDL_RenderDrawLine(renderer, 4 * SCALE, row, 7 * SCALE, row);
	SDL_RenderDrawLine(renderer, 18 * SCALE, row, 19 * SCALE, row);

	row += SCALE;
	SDL_RenderDrawLine(renderer, 6 * SCALE, row, 7 * SCALE, row);
	SDL_RenderDrawLine(renderer, 18 * SCALE, row, 21 * SCALE, row);

	row += SCALE;
	SDL_RenderDrawLine(renderer, 4 * SCALE, row, 10 * SCALE, row);
	SDL_RenderDrawLine(renderer, 15 * SCALE, row, 19 * SCALE, row);

	row += SCALE;
	SDL_RenderDrawLine(renderer, 15 * SCALE, row, 18 * SCALE, row);

	row += SCALE;
	SDL_RenderDrawLine(renderer, 4 * SCALE, row, 6 * SCALE, row);

	row += SCALE;
	SDL_RenderDrawLine(renderer, 4 * SCALE, row, 8 * SCALE, row);

	row += 2 * SCALE;
	SDL_RenderDrawLine(renderer, 15 * SCALE, row, 17 * SCALE, row);
	SDL_RenderDrawLine(renderer, 20 * SCALE, row, 21 * SCALE, row);

	row += SCALE;
	SDL_RenderDrawLine(renderer, 8 * SCALE, row, 9 * SCALE, row);
	SDL_RenderDrawLine(renderer, 17 * SCALE, row, 18 * SCALE, row);
	SDL_RenderDrawLine(renderer, 20 * SCALE, row, 21 * SCALE, row);

	row += SCALE;
	SDL_RenderDrawLine(renderer, 4 * SCALE, row, 9 * SCALE, row);
	SDL_RenderDrawLine(renderer, 15 * SCALE, row, 18 * SCALE, row);
	SDL_RenderDrawLine(renderer, 20 * SCALE, row, 21 * SCALE, row);
}

void Grid1::verticalGray(void)
{
	Uint16 column = 4 * SCALE;
	SDL_RenderDrawLine(renderer, column, SCALE, column, 3 * SCALE);
	SDL_RenderDrawLine(renderer, column, 9 * SCALE, column, 11 * SCALE);
	SDL_RenderDrawLine(renderer, column, 13 * SCALE, column, 18 * SCALE);

	column += SCALE;
	SDL_RenderDrawLine(renderer, column, SCALE, column, 3 * SCALE);
	SDL_RenderDrawLine(renderer, column, 13 * SCALE, column, 14 * SCALE);

	column += SCALE;
	SDL_RenderDrawLine(renderer, column, 8 * SCALE, column, 11 * SCALE);
	SDL_RenderDrawLine(renderer, column, 13 * SCALE, column, 14 * SCALE);

	column += SCALE;
	SDL_RenderDrawLine(renderer, column, SCALE, column, 2 * SCALE);
	SDL_RenderDrawLine(renderer, column, 7 * SCALE, column, 11 * SCALE);

	column += SCALE;
	SDL_RenderDrawLine(renderer, column, SCALE, column, 3 * SCALE);
	SDL_RenderDrawLine(renderer, column, 7 * SCALE, column, 8 * SCALE);
	SDL_RenderDrawLine(renderer, column, 14 * SCALE, column, 18 * SCALE);

	column += SCALE;
	SDL_RenderDrawLine(renderer, column, 7 * SCALE, column, 8 * SCALE);
	SDL_RenderDrawLine(renderer, column, 17 * SCALE, column, 18 * SCALE);

	column += SCALE;
	SDL_RenderDrawLine(renderer, column, SCALE, column, 3 * SCALE);
	SDL_RenderDrawLine(renderer, column, 7 * SCALE, column, 11 * SCALE);

	column += 5 * SCALE;
	SDL_RenderDrawLine(renderer, column, 8 * SCALE, column, 12 * SCALE);
	SDL_RenderDrawLine(renderer, column, 16 * SCALE, column, 18 * SCALE);

	column += SCALE;
	SDL_RenderDrawLine(renderer, column, SCALE, column, 2 * SCALE);
	SDL_RenderDrawLine(renderer, column, 11 * SCALE, column, 12 * SCALE);

	column += SCALE;
	SDL_RenderDrawLine(renderer, column, SCALE, column, 5 * SCALE);
	SDL_RenderDrawLine(renderer, column, 11 * SCALE, column, 12 * SCALE);
	SDL_RenderDrawLine(renderer, column, 16 * SCALE, column, 18 * SCALE);

	column += SCALE;
	SDL_RenderDrawLine(renderer, column, 8 * SCALE, column, 12 * SCALE);
	SDL_RenderDrawLine(renderer, column, 17 * SCALE, column, 18 * SCALE);

	column += SCALE;
	SDL_RenderDrawLine(renderer, column, 5 * SCALE, column, 6 * SCALE);
	SDL_RenderDrawLine(renderer, column, 8 * SCALE, column, 11 * SCALE);

	column += SCALE;
	SDL_RenderDrawLine(renderer, column, 5 * SCALE, column, 6 * SCALE);
	SDL_RenderDrawLine(renderer, column, 16 * SCALE, column, 18 * SCALE);

	column += SCALE;
	SDL_RenderDrawLine(renderer, column, SCALE, column, 6 * SCALE);
	SDL_RenderDrawLine(renderer, column, 8 * SCALE, column, 10 * SCALE);
	SDL_RenderDrawLine(renderer, column, 16 * SCALE, column, 18 * SCALE);

	SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF); // back to white
}
