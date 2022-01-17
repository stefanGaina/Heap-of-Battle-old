#include "Outline0.h"

Outline0::Outline0(SDL_Renderer* renderer) : 
	Enable(true), current(&human), renderer(renderer),
	human({ 0x15, 0x89, 0xFF, 0xAF }), orc({ 0xF7, 0x0D, 0x1A, 0xAF })
{
}

void Outline0::square(Coordinate hover, Uint8 lenght)
{
	SDL_SetRenderDrawColor(renderer, current->r, current->g, current->g, current->a);

	SDL_RenderDrawLine(renderer, hover.x * SCALE, hover.y * SCALE, (hover.x + lenght) * SCALE, hover.y * SCALE);
	SDL_RenderDrawLine(renderer, hover.x * SCALE, hover.y * SCALE, hover.x * SCALE, (hover.y + lenght) * SCALE);
	SDL_RenderDrawLine(renderer, (hover.x + lenght) * SCALE, hover.y * SCALE, (hover.x + lenght) * SCALE, (hover.y + lenght) * SCALE);
	SDL_RenderDrawLine(renderer, hover.x * SCALE, (hover.y + lenght) * SCALE, (hover.x + lenght) * SCALE, (hover.y + lenght) * SCALE);

	SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
}

void Outline0::set(Coordinate hover, State state)
{
	type = state <= State::HUMAN_WING && state >= State::ORC_WING ? State::NEUTRAL : state;
	
	this->hover.x = hover.y;
	this->hover.y = hover.x;
}

void Outline0::change(void)
{
	current = current == &human ? &orc : &human;
}
