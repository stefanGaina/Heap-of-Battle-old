#include "Frame.h"
#include "TextureManager.h"

Frame::Frame(SDL_Renderer* renderer) : renderer(renderer), destination({ 0, 0, 3 * SCALE + 7, SCALE + 15 })
{
	texture = TextureManager::load("Assets/General/Icons/Frame.png", renderer);
}

Frame::~Frame(void)
{
	TextureManager::destroy(texture);
}

void Frame::draw(Faction turn, State type, bool hasAttacked)
{
	switch (turn)
	{
		case Faction::HUMAN:
		{
			destination.x = SCALE - 5;
			destination.y = SCALE - 7;
			TextureManager::draw(texture, destination, renderer);

			destination.y += SCALE;
			TextureManager::draw(texture, destination, renderer);

			destination.y += 13 * SCALE;
			TextureManager::draw(texture, destination, renderer);

			destination.y += 2 * SCALE;
			TextureManager::draw(texture, destination, renderer);

			if (type != State::NEUTRAL)
			{
				destination.x = SCALE - 5;
				destination.y = 4 * SCALE - 7;
				TextureManager::draw(texture, destination, renderer);

				if (type == State::HUMAN_KEEP)
				{
					for (destination.y = 6 * SCALE - 7; destination.y <= 12 * SCALE - 7; destination.y += 2 * SCALE)
					{
						TextureManager::draw(texture, destination, renderer);
					}
				}
				else if (type >= State::HUMAN_INFANTRY && type <= State::HUMAN_WING && !hasAttacked)
				{
					destination.x = SCALE - 2;
					destination.y = 6 * SCALE - 8;
					destination.w = SCALE + 5;
					TextureManager::draw(texture, destination, renderer);
					destination.w = 3 * SCALE + 7;
				}
			}
			break;
		}
		case Faction::ORC:
		{
			destination.x = 21 * SCALE - 5;
			destination.y = SCALE - 7;
			TextureManager::draw(texture, destination, renderer);

			destination.y += SCALE;
			TextureManager::draw(texture, destination, renderer);

			destination.y += 13 * SCALE;
			TextureManager::draw(texture, destination, renderer);

			destination.y += 2 * SCALE;
			TextureManager::draw(texture, destination, renderer);

			if (type != State::NEUTRAL)
			{
				destination.x = 21 * SCALE - 5;
				destination.y = 4 * SCALE - 7;
				TextureManager::draw(texture, destination, renderer);

				if (type == State::ORC_KEEP)
				{
					for (destination.y = 6 * SCALE - 7; destination.y <= 12 * SCALE - 7; destination.y += 2 * SCALE)
					{
						TextureManager::draw(texture, destination, renderer);
					}
				}
				else if (type >= State::ORC_WING && type <= State::ORC_INFANTRY && !hasAttacked)
				{
					destination.x = 23 * SCALE - 2;
					destination.y = 6 * SCALE - 8;
					destination.w = SCALE + 5;
					TextureManager::draw(texture, destination, renderer);
					destination.w = 3 * SCALE + 7;
				}
			}
		}
	}
}
