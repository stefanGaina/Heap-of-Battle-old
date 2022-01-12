#pragma once
#include "Language.h"

enum
{
	ANIMATION_FRAMES = 4,
};

struct Textures
{
	SDL_Texture* left[ANIMATION_FRAMES], * up[ANIMATION_FRAMES], * right[ANIMATION_FRAMES], * down[ANIMATION_FRAMES];
	SDL_Texture* leftAttack[ANIMATION_FRAMES], * upAttack[ANIMATION_FRAMES], * rightAttack[ANIMATION_FRAMES], * downAttack[ANIMATION_FRAMES];
	SDL_Texture* death[ANIMATION_FRAMES];
};

struct Units
{
	Textures infantry, archer, knight, wing;
};

class AnimationTexture
{
public:
	AnimationTexture(SDL_Renderer* renderer);
	~AnimationTexture(void);

protected:
	Textures* setAttacker(State attacker);
	SDL_Texture** setDefender(Show defender);

	SDL_Renderer* renderer;

private:
	void loadTextures(void);
	void destroyTextures(void);

	Units human, orc;
};
