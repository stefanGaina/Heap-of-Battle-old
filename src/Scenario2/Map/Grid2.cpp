#include "Grid2.h"

Grid2::Grid2(SDL_Renderer* renderer) : Grid0(renderer)
{
}

void Grid2::draw(void)
{
	horizontalBlack();
	verticalBlack();

	horizontalGray();
	verticalGray();
}

void Grid2::horizontalBlack(void)
{
	SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xAF); // black

	Uint16 row = SCALE;
	SDL_RenderDrawLine(renderer, 4 * SCALE, row, 21 * SCALE, row);

	row += SCALE;
	SDL_RenderDrawLine(renderer, 4 * SCALE, row, 9 * SCALE, row);
	SDL_RenderDrawLine(renderer, 16 * SCALE, row, 21 * SCALE, row);

	row += SCALE;
	SDL_RenderDrawLine(renderer, 5 * SCALE, row, 10 * SCALE, row);
	SDL_RenderDrawLine(renderer, 15 * SCALE, row, 21 * SCALE, row);

	for (row += SCALE; row < 8 * SCALE; row += SCALE)
	{
		SDL_RenderDrawLine(renderer, 7 * SCALE, row, 18 * SCALE, row);
	}
	for (row += 4 * SCALE; row < 16 * SCALE; row += SCALE)
	{
		SDL_RenderDrawLine(renderer, 7 * SCALE, row, 18 * SCALE, row);
	}
	SDL_RenderDrawLine(renderer, 5 * SCALE, row, 10 * SCALE, row);
	SDL_RenderDrawLine(renderer, 15 * SCALE, row, 21 * SCALE, row);

	row += SCALE;
	SDL_RenderDrawLine(renderer, 4 * SCALE, row, 9 * SCALE, row);
	SDL_RenderDrawLine(renderer, 16 * SCALE, row, 21 * SCALE, row);

	row += SCALE;
	SDL_RenderDrawLine(renderer, 4 * SCALE, row, 21 * SCALE, row);
}

void Grid2::verticalBlack(void)
{
	Uint16 column = 4 * SCALE;
	SDL_RenderDrawLine(renderer, column, SCALE, column, 18 * SCALE);

	for (column += SCALE; column < 8 * SCALE; column += SCALE)
	{
		SDL_RenderDrawLine(renderer, column, SCALE, column, 4 * SCALE);
		SDL_RenderDrawLine(renderer, column, 15 * SCALE, column, 18 * SCALE);
	}
	for (; column < 11 * SCALE; column += SCALE)
	{
		SDL_RenderDrawLine(renderer, column, SCALE, column, 7 * SCALE);
		SDL_RenderDrawLine(renderer, column, 12 * SCALE, column, 18 * SCALE);
	}
	for (; column < 15 * SCALE; column += SCALE)
	{
		SDL_RenderDrawLine(renderer, column, 5 * SCALE, column, 7 * SCALE);
		SDL_RenderDrawLine(renderer, column, 12 * SCALE, column, 14 * SCALE);
	}
	for (; column < 18 * SCALE; column += SCALE)
	{
		SDL_RenderDrawLine(renderer, column, SCALE, column, 7 * SCALE);
		SDL_RenderDrawLine(renderer, column, 12 * SCALE, column, 18 * SCALE);
	}
	for (; column < 21 * SCALE; column += SCALE)
	{
		SDL_RenderDrawLine(renderer, column, SCALE, column, 4 * SCALE);
		SDL_RenderDrawLine(renderer, column, 15 * SCALE, column, 18 * SCALE);
	}
	SDL_RenderDrawLine(renderer, column, SCALE, column, 18 * SCALE);
}

void Grid2::horizontalGray(void)
{
	SDL_SetRenderDrawColor(renderer, 0xbd, 0xb7, 0x6b, 0xfF); //

	Uint16 row = SCALE;
	SDL_RenderDrawLine(renderer, 9 * SCALE, row, 16 * SCALE, row);

	row += SCALE;
	SDL_RenderDrawLine(renderer, 9 * SCALE, row, 11 * SCALE, row);
	SDL_RenderDrawLine(renderer, 14 * SCALE, row, 16 * SCALE, row);

	row += SCALE;
	SDL_RenderDrawLine(renderer, 4 * SCALE, row, 5 * SCALE, row);
	SDL_RenderDrawLine(renderer, 10 * SCALE, row, 11 * SCALE, row);
	SDL_RenderDrawLine(renderer, 14 * SCALE, row, 15 * SCALE, row);
	SDL_RenderDrawLine(renderer, 20 * SCALE, row, 21 * SCALE, row);

	row += SCALE;
	SDL_RenderDrawLine(renderer, 4 * SCALE, row, 7 * SCALE, row);
	SDL_RenderDrawLine(renderer, 11 * SCALE, row, 14 * SCALE, row);
	SDL_RenderDrawLine(renderer, 18 * SCALE, row, 21 * SCALE, row);

	row += SCALE;
	SDL_RenderDrawLine(renderer, 11 * SCALE, row, 14 * SCALE, row);

	row += 2 * SCALE;
	SDL_RenderDrawLine(renderer, 4 * SCALE, row, 7 * SCALE, row);
	SDL_RenderDrawLine(renderer, 18 * SCALE, row, 21 * SCALE, row);

	for (; row < 9 * SCALE; row += SCALE)
	{
		SDL_RenderDrawLine(renderer, 11 * SCALE, row, 14 * SCALE, row);
	}
	for (row += 2 * SCALE; row < 13 * SCALE; row += SCALE)
	{
		SDL_RenderDrawLine(renderer, 11 * SCALE, row, 14 * SCALE, row);
	}
	row -= SCALE;
	SDL_RenderDrawLine(renderer, 4 * SCALE, row, 7 * SCALE, row);
	SDL_RenderDrawLine(renderer, 18 * SCALE, row, 21 * SCALE, row);

	row += 2 * SCALE;
	SDL_RenderDrawLine(renderer, 11 * SCALE, row, 14 * SCALE, row);

	row += SCALE;
	SDL_RenderDrawLine(renderer, 4 * SCALE, row, 7 * SCALE, row);
	SDL_RenderDrawLine(renderer, 11 * SCALE, row, 14 * SCALE, row);
	SDL_RenderDrawLine(renderer, 18 * SCALE, row, 21 * SCALE, row);

	row += SCALE;
	SDL_RenderDrawLine(renderer, 4 * SCALE, row, 5 * SCALE, row);
	SDL_RenderDrawLine(renderer, 10 * SCALE, row, 11 * SCALE, row);
	SDL_RenderDrawLine(renderer, 14 * SCALE, row, 15 * SCALE, row);
	SDL_RenderDrawLine(renderer, 20 * SCALE, row, 21 * SCALE, row);

	row += SCALE;
	SDL_RenderDrawLine(renderer, 9 * SCALE, row, 11 * SCALE, row);
	SDL_RenderDrawLine(renderer, 14 * SCALE, row, 16 * SCALE, row);

	row += SCALE;
	SDL_RenderDrawLine(renderer, 9 * SCALE, row, 16 * SCALE, row);
}

void Grid2::verticalGray(void)
{
	Uint16 column = 4 * SCALE;
	SDL_RenderDrawLine(renderer, column, 3 * SCALE, column, 7 * SCALE);
	SDL_RenderDrawLine(renderer, column, 12 * SCALE, column, 16 * SCALE);

	column += SCALE;
	SDL_RenderDrawLine(renderer, column, 3 * SCALE, column, 4 * SCALE);
	SDL_RenderDrawLine(renderer, column, 15 * SCALE, column, 16 * SCALE);

	column += 2 * SCALE;
	SDL_RenderDrawLine(renderer, column, 4 * SCALE, column, 7 * SCALE);
	SDL_RenderDrawLine(renderer, column, 12 * SCALE, column, 15 * SCALE);

	column += 2 * SCALE;
	SDL_RenderDrawLine(renderer, column, SCALE, column, 2 * SCALE);
	SDL_RenderDrawLine(renderer, column, 17 * SCALE, column, 18 * SCALE);

	column += SCALE;
	SDL_RenderDrawLine(renderer, column, SCALE, column, 3 * SCALE);
	SDL_RenderDrawLine(renderer, column, 16 * SCALE, column, 18 * SCALE);

	column += SCALE;
	SDL_RenderDrawLine(renderer, column, SCALE, column, 5 * SCALE);
	SDL_RenderDrawLine(renderer, column, 7 * SCALE, column, 12 * SCALE);
	SDL_RenderDrawLine(renderer, column, 14 * SCALE, column, 18 * SCALE);

	for (column += SCALE; column < 14 * SCALE; column += SCALE)
	{
		SDL_RenderDrawLine(renderer, column, 4 * SCALE, column, 5 * SCALE);
		SDL_RenderDrawLine(renderer, column, 7 * SCALE, column, 8 * SCALE);
		SDL_RenderDrawLine(renderer, column, 11 * SCALE, column, 12 * SCALE);
		SDL_RenderDrawLine(renderer, column, 14 * SCALE, column, 15 * SCALE);
	}
	SDL_RenderDrawLine(renderer, column, SCALE, column, 5 * SCALE);
	SDL_RenderDrawLine(renderer, column, 7 * SCALE, column, 12 * SCALE);
	SDL_RenderDrawLine(renderer, column, 14 * SCALE, column, 18 * SCALE);

	column += SCALE;
	SDL_RenderDrawLine(renderer, column, SCALE, column, 3 * SCALE);
	SDL_RenderDrawLine(renderer, column, 16 * SCALE, column, 18 * SCALE);

	column += SCALE;
	SDL_RenderDrawLine(renderer, column, SCALE, column, 2 * SCALE);
	SDL_RenderDrawLine(renderer, column, 17 * SCALE, column, 18 * SCALE);

	column += 2 * SCALE;
	SDL_RenderDrawLine(renderer, column, 4 * SCALE, column, 7 * SCALE);
	SDL_RenderDrawLine(renderer, column, 12 * SCALE, column, 15 * SCALE);

	column += 2 * SCALE;
	SDL_RenderDrawLine(renderer, column, 3 * SCALE, column, 4 * SCALE);
	SDL_RenderDrawLine(renderer, column, 15 * SCALE, column, 16 * SCALE);

	column += SCALE;
	SDL_RenderDrawLine(renderer, column, 3 * SCALE, column, 7 * SCALE);
	SDL_RenderDrawLine(renderer, column, 12 * SCALE, column, 16 * SCALE);

	SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF); // back to white
}
