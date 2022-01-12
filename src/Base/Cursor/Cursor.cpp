#include "Cursor.h"
#include "TextureManager.h"

CursorTexture::CursorTexture(SDL_Texture* cursor) :
	cursor(cursor)
{
}

CursorTexture::~CursorTexture(void)
{
	TextureManager::destroy(cursor);
}

Cursor::Cursor(SDL_Renderer* renderer) : 
	human(TextureManager::load("Assets/Human/Icons/Cursor.png", renderer)),
	orc(TextureManager::load("Assets/Orc/Icons/Cursor.png", renderer)),
	renderer(renderer), destination({ 0, 0, SCALE, SCALE })
{
	current = human.cursor;
}

void Cursor::draw(Mouse mouse)
{
	destination.x = mouse.x;
	destination.y = mouse.y;
	TextureManager::draw(current, destination, renderer);
}

void Cursor::change(void)
{
	current = current == human.cursor ? orc.cursor : human.cursor;
}
