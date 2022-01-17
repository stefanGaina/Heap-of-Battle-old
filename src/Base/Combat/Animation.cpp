#include "Animation.h"
#include "TextureManager.h"

enum AnimationSpeed
{
	ANIMATION_SPEED = 2, // 1 - slow, 2 - fast
};

Animation::Animation(TileInfo* tile, SDL_Renderer* renderer) : 
	AnimationTexture(renderer), tile(tile), distance(-1), 
	animating(false), destination({ 0, 0, SCALE, SCALE + 8 })
{
}

void Animation::draw(void)
{
	static const float TIMER = 0.18F;
	static float changeFrame = 0.0F;
	static float changeFrameAttack = 0.0F;

	if (animating)
	{
		if (destination.x % SCALE == 0 && destination.y % SCALE == 0 && changeFrameAttack == 0)
		{
			++distance;
		}
		
		if (Uint8(changeFrameAttack) == ANIMATION_FRAMES)
		{
			changeFrameAttack = 0;

			switch (current.path[distance])
			{
				case Move::ATTACK_LEFT:
				{
					current.path[distance] = Move::LEFT;
					break;
				}
				case Move::ATTACK_UP:
				{
					current.path[distance] = Move::UP;
					break;
				}
				case Move::ATTACK_RIGHT:
				{
					current.path[distance] = Move::RIGHT;
					break;
				}
				case Move::ATTACK_DOWN:
				{
					current.path[distance] = Move::DOWN;
				}
			}
		}
		switch (current.path[distance])
		{
			case Move::LEFT:
			{
				changeFrame += TIMER; // 6 frames then change it
				toAnimate = unit->left[Uint8(changeFrame) % ANIMATION_FRAMES];

				destination.x -= ANIMATION_SPEED;
				break;
			}
			case Move::UP:
			{
				changeFrame += TIMER;
				toAnimate = unit->up[Uint8(changeFrame) % ANIMATION_FRAMES];

				destination.y -= ANIMATION_SPEED;
				break;
			}
			case Move::RIGHT:
			{
				changeFrame += TIMER;
				toAnimate = unit->right[Uint8(changeFrame) % ANIMATION_FRAMES];

				destination.x += ANIMATION_SPEED;
				break;
			}
			case Move::DOWN:
			{
				changeFrame += TIMER;
				toAnimate = unit->down[Uint8(changeFrame) % ANIMATION_FRAMES];

				destination.y += ANIMATION_SPEED;
				break;
			}
			case Move::ATTACK_LEFT:
			{
				changeFrameAttack += TIMER;
				toAnimate = unit->leftAttack[Uint8(changeFrameAttack) % ANIMATION_FRAMES];

				tile->info[current.finish.x][current.finish.y].show = Show::NOTHING;
				TextureManager::draw(death[Uint8(changeFrameAttack) % ANIMATION_FRAMES], { destination.x - SCALE, destination.y , destination.w , destination.h }, renderer);
				break;
			}
			case Move::ATTACK_UP:
			{
				changeFrameAttack += TIMER;
				toAnimate = unit->upAttack[Uint8(changeFrameAttack) % ANIMATION_FRAMES];

				tile->info[current.finish.x][current.finish.y].show = Show::NOTHING;
				TextureManager::draw(death[Uint8(changeFrameAttack) % ANIMATION_FRAMES], { destination.x, destination.y - SCALE, destination.w , destination.h }, renderer);
				break;
			}
			case Move::ATTACK_RIGHT:
			{
				changeFrameAttack += TIMER;
				toAnimate = unit->rightAttack[Uint8(changeFrameAttack) % ANIMATION_FRAMES];

				tile->info[current.finish.x][current.finish.y].show = Show::NOTHING;
				TextureManager::draw(death[Uint8(changeFrameAttack) % ANIMATION_FRAMES], { destination.x + SCALE, destination.y, destination.w , destination.h }, renderer);
				break;
			}
			case Move::ATTACK_DOWN:
			{
				changeFrameAttack += TIMER;
				toAnimate = unit->downAttack[Uint8(changeFrameAttack) % ANIMATION_FRAMES];

				tile->info[current.finish.x][current.finish.y].show = Show::NOTHING;
				TextureManager::draw(death[Uint8(changeFrameAttack) % ANIMATION_FRAMES], { destination.x, destination.y + SCALE, destination.w , destination.h }, renderer);
				break;
			}
			default:
			{
				changeFrame = 0;
				distance = -1;
				animating = false;
				tile->info[current.finish.x][current.finish.y].show = (Show)current.unit;

				delete[] current.path;
				current.path = nullptr;
			}
		}
		TextureManager::draw(toAnimate, destination, renderer);
	}
}

void Animation::set(Queue* queue)
{
	if (!animating && !queue->isEmpty())
	{
		current = queue->get();

		destination.x = current.start.y * SCALE;
		destination.y = current.start.x * SCALE;

		animating = true;
		tile->info[current.start.x][current.start.y].show = Show::NOTHING;

		unit = setAttacker(current.unit);
		death = setDefender(tile->info[current.finish.x][current.finish.y].show);
	}
}

bool Animation::get(void)
{
	return animating;
}
