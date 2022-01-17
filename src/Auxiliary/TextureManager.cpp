#include "TextureManager.h"
#include "Log.h"

SDL_Texture* TextureManager::load(const char* file, SDL_Renderer* renderer)
{
	SDL_Surface* temporarySurface = IMG_Load(file);

#ifdef DEBUG
	if (temporarySurface == nullptr)
	{
		ERROR(file);
	}
#endif
	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, temporarySurface);
	SDL_FreeSurface(temporarySurface);
	
	return texture;
}

SDL_Texture* TextureManager::createText(TTF_Font* font, std::string text, SDL_Color color, SDL_Renderer* renderer)
{
#ifdef DEBUG
	if (font == nullptr)
	{
		ERROR("Invalid font");
	}
#endif
	SDL_Surface* textSurface = TTF_RenderText_Solid(font, text.c_str(), color);
	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, textSurface);
	SDL_FreeSurface(textSurface);

	return texture;
}

void TextureManager::destroy(SDL_Texture*& texture)
{
#ifdef DEBUG
	if (texture == nullptr)
	{
		WARNING("Destroy empty texture");
	}
#endif
	SDL_DestroyTexture(texture);
	texture = nullptr;
}

void TextureManager::draw(SDL_Texture* texture, SDL_Rect destination, SDL_Renderer* renderer)
{
#ifdef DEBUG
	if (texture == nullptr)
	{
		WARNING("Draw empty texture");
	}
#endif
	SDL_RenderCopy(renderer, texture, nullptr, &destination);
}
