#include "CursorMenu.h"
#include "TextureManager.h"

CursorMenu::CursorMenu(SDL_Renderer* renderer) :
	texture(TextureManager::load("Assets/General/Menu/Cursor.png", renderer)),
	renderer(renderer), destination({ 0, 0, SCALE, SCALE })
{
	
}

CursorMenu::~CursorMenu(void)
{
	TextureManager::destroy(texture);
}

void CursorMenu::draw(const Mouse& mouse)
{
	destination.x = mouse.x;
	destination.y = mouse.y;
	TextureManager::draw(texture, destination, renderer);
}
