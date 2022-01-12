#include "Text.h"

Text::Text(SDL_Renderer* renderer) :
	font(TTF_OpenFont("Assets/Misc/Fonts/Aller_Rg.ttf", 72)), color({ 0x00, 0x00, 0x00, 0xFF }), renderer(renderer)
{
}

Text::~Text(void) 
{

}

void Text::draw(void)
{

}
