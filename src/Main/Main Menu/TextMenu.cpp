#include "TextMenu.h"
#include "TextureManager.h"

TextMenu::TextMenu(SDL_Renderer* renderer) :
	font(TTF_OpenFont("Assets/General/Misc/Fonts/Aller_Rg.ttf", 72)), 
	black({ 0x00, 0x00, 0x00, 0xFF }), red({ 0x99, 0x00, 0x12, 0xFF }), renderer(renderer),
	digit1(TextureManager::createText(font, "1", red, renderer)),
	heap(TextureManager::createText(font, "Heap", black, renderer)),
	of(TextureManager::createText(font, "of", black, renderer)),
	battle(TextureManager::createText(font, "Battle", black, renderer)),
	version(TextureManager::createText(font, "version 1.7.2", black, renderer)),
	newGame(TextureManager::createText(font, "New Game", black, renderer)),
	loadGame(TextureManager::createText(font, "Load Game", black, renderer)),
	exit(TextureManager::createText(font, "Exit", black, renderer))
{
}

TextMenu::~TextMenu(void) 
{
	TextureManager::destroy(digit1);
	TextureManager::destroy(heap);
	TextureManager::destroy(of);
	TextureManager::destroy(battle);
	TextureManager::destroy(newGame);
	TextureManager::destroy(loadGame);
	TextureManager::destroy(exit);

	TTF_CloseFont(font);
	font = nullptr;
}

void TextMenu::draw(void)
{
	TextureManager::draw(digit1, { 375, 30, 50, 50 }, renderer);
	TextureManager::draw(heap, { 280, 70, 80, 60 }, renderer);
	TextureManager::draw(of, { 380, 100, 40, 40 }, renderer);
	TextureManager::draw(battle, { 440, 70, 80, 60 }, renderer);
	TextureManager::draw(version, { 360, 150, 80, 40 }, renderer);
	TextureManager::draw(newGame, { 350, 227, 100, 40 }, renderer);
	TextureManager::draw(loadGame, { 350, 302, 100, 40 }, renderer);
	TextureManager::draw(exit, { 368, 387, 60, 24 }, renderer);
}
