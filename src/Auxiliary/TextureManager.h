#pragma once
#include <SDL_image.h>
#include <SDL_ttf.h>

#include <string>

class TextureManager
{
public:
	static SDL_Texture* load(const char* fileName, SDL_Renderer* renderer);
	static SDL_Texture* createText(TTF_Font* textFont, std::string text, SDL_Color textColor, SDL_Renderer* renderer);
	static void destroy(SDL_Texture*& texture);
	static void draw(SDL_Texture* texture, SDL_Rect destination, SDL_Renderer* renderer);

private:
	TextureManager(void);
};
