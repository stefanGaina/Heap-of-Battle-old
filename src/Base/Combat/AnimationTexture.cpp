#include "AnimationTexture.h"
#include "TextureManager.h"

AnimationTexture::AnimationTexture(SDL_Renderer* renderer) : renderer(renderer)
{
	loadTextures();
}

AnimationTexture::~AnimationTexture(void)
{
	destroyTextures();
}

Textures* AnimationTexture::setAttacker(State attacker)
{
	switch (attacker)
	{
		case State::HUMAN_INFANTRY:
		{
			return &human.infantry;
		}
		case State::HUMAN_ARCHER:
		{
			return &human.archer;
		}
		case State::HUMAN_KNIGHT:
		{
			return &human.knight;
		}
		case State::HUMAN_WING:
		{
			return &human.wing;
		}
		case State::ORC_INFANTRY:
		{
			return &orc.infantry;
		}
		case State::ORC_ARCHER:
		{
			return &orc.archer;
		}
		case State::ORC_KNIGHT:
		{
			return &orc.knight;
		}
		case State::ORC_WING:
		{
			return &orc.wing;
		}
		default:
		{
			return nullptr;
		}
	}
}

SDL_Texture** AnimationTexture::setDefender(Show defender)
{
	switch (defender)
	{
		case Show::human_infantry:
		{
			return human.infantry.death;
		}
		case Show::human_archer:
		{
			return human.archer.death;
		}
		case Show::human_knight:
		{
			return human.knight.death;
		}
		case Show::human_wing:
		{
			return human.wing.death;
		}
		case Show::orc_infantry:
		{
			return orc.infantry.death;
		}
		case Show::orc_archer:
		{
			return orc.archer.death;
		}
		case Show::orc_knight:
		{
			return orc.knight.death;
		}
		case Show::orc_wing:
		{
			return orc.wing.death;
		}
	}
}

void AnimationTexture::loadTextures(void)
{
	human.infantry.left[0] = TextureManager::load("Assets/Human/Units/Infantry/Animation/Left.png", renderer);
	human.infantry.left[1] = TextureManager::load("Assets/Human/Units/Infantry/Animation/Left1.png", renderer);
	human.infantry.left[2] = TextureManager::load("Assets/Human/Units/Infantry/Animation/Left2.png", renderer);
	human.infantry.left[3] = TextureManager::load("Assets/Human/Units/Infantry/Animation/Left3.png", renderer);

	human.infantry.up[0] = TextureManager::load("Assets/Human/Units/Infantry/Animation/Up.png", renderer);
	human.infantry.up[1] = TextureManager::load("Assets/Human/Units/Infantry/Animation/Up1.png", renderer);
	human.infantry.up[2] = TextureManager::load("Assets/Human/Units/Infantry/Animation/Up2.png", renderer);
	human.infantry.up[3] = TextureManager::load("Assets/Human/Units/Infantry/Animation/Up3.png", renderer);

	human.infantry.right[0] = TextureManager::load("Assets/Human/Units/Infantry/Animation/Right.png", renderer);
	human.infantry.right[1] = TextureManager::load("Assets/Human/Units/Infantry/Animation/Right1.png", renderer);
	human.infantry.right[2] = TextureManager::load("Assets/Human/Units/Infantry/Animation/Right2.png", renderer);
	human.infantry.right[3] = TextureManager::load("Assets/Human/Units/Infantry/Animation/Right3.png", renderer);

	human.infantry.down[0] = TextureManager::load("Assets/Human/Units/Infantry/Animation/Down.png", renderer);
	human.infantry.down[1] = TextureManager::load("Assets/Human/Units/Infantry/Animation/Down1.png", renderer);
	human.infantry.down[2] = TextureManager::load("Assets/Human/Units/Infantry/Animation/Down2.png", renderer);
	human.infantry.down[3] = TextureManager::load("Assets/Human/Units/Infantry/Animation/Down3.png", renderer);

	human.infantry.leftAttack[0] = TextureManager::load("Assets/Human/Units/Infantry/Animation/Left Attack.png", renderer);
	human.infantry.leftAttack[1] = TextureManager::load("Assets/Human/Units/Infantry/Animation/Left Attack1.png", renderer);
	human.infantry.leftAttack[2] = TextureManager::load("Assets/Human/Units/Infantry/Animation/Left Attack2.png", renderer);
	human.infantry.leftAttack[3] = TextureManager::load("Assets/Human/Units/Infantry/Animation/Left Attack3.png", renderer);

	human.infantry.upAttack[0] = TextureManager::load("Assets/Human/Units/Infantry/Animation/Up Attack.png", renderer);
	human.infantry.upAttack[1] = TextureManager::load("Assets/Human/Units/Infantry/Animation/Up Attack1.png", renderer);
	human.infantry.upAttack[2] = TextureManager::load("Assets/Human/Units/Infantry/Animation/Up Attack2.png", renderer);
	human.infantry.upAttack[3] = TextureManager::load("Assets/Human/Units/Infantry/Animation/Up Attack3.png", renderer);

	human.infantry.rightAttack[0] = TextureManager::load("Assets/Human/Units/Infantry/Animation/Right Attack.png", renderer);
	human.infantry.rightAttack[1] = TextureManager::load("Assets/Human/Units/Infantry/Animation/Right Attack1.png", renderer);
	human.infantry.rightAttack[2] = TextureManager::load("Assets/Human/Units/Infantry/Animation/Right Attack2.png", renderer);
	human.infantry.rightAttack[3] = TextureManager::load("Assets/Human/Units/Infantry/Animation/Right Attack3.png", renderer);

	human.infantry.downAttack[0] = TextureManager::load("Assets/Human/Units/Infantry/Animation/Down Attack.png", renderer);
	human.infantry.downAttack[1] = TextureManager::load("Assets/Human/Units/Infantry/Animation/Down Attack1.png", renderer);
	human.infantry.downAttack[2] = TextureManager::load("Assets/Human/Units/Infantry/Animation/Down Attack2.png", renderer);
	human.infantry.downAttack[3] = TextureManager::load("Assets/Human/Units/Infantry/Animation/Down Attack3.png", renderer);

	human.infantry.death[0] = TextureManager::load("Assets/Human/Units/Infantry/Animation/Death.png", renderer);
	human.infantry.death[1] = human.infantry.death[0];
	human.infantry.death[2] = TextureManager::load("Assets/Human/Units/Infantry/Animation/Death1.png", renderer);
	human.infantry.death[3] = human.infantry.death[2];

	human.archer.left[0] = TextureManager::load("Assets/Human/Units/Archer/Animation/Left.png", renderer);
	human.archer.left[1] = TextureManager::load("Assets/Human/Units/Archer/Animation/Left1.png", renderer);
	human.archer.left[2] = TextureManager::load("Assets/Human/Units/Archer/Animation/Left2.png", renderer);
	human.archer.left[3] = TextureManager::load("Assets/Human/Units/Archer/Animation/Left3.png", renderer);

	human.archer.up[0] = TextureManager::load("Assets/Human/Units/Archer/Animation/Up.png", renderer);
	human.archer.up[1] = TextureManager::load("Assets/Human/Units/Archer/Animation/Up1.png", renderer);
	human.archer.up[2] = TextureManager::load("Assets/Human/Units/Archer/Animation/Up2.png", renderer);
	human.archer.up[3] = TextureManager::load("Assets/Human/Units/Archer/Animation/Up3.png", renderer);

	human.archer.right[0] = TextureManager::load("Assets/Human/Units/Archer/Animation/Right.png", renderer);
	human.archer.right[1] = TextureManager::load("Assets/Human/Units/Archer/Animation/Right1.png", renderer);
	human.archer.right[2] = TextureManager::load("Assets/Human/Units/Archer/Animation/Right2.png", renderer);
	human.archer.right[3] = TextureManager::load("Assets/Human/Units/Archer/Animation/Right3.png", renderer);

	human.archer.down[0] = TextureManager::load("Assets/Human/Units/Archer/Animation/Down.png", renderer);
	human.archer.down[1] = TextureManager::load("Assets/Human/Units/Archer/Animation/Down1.png", renderer);
	human.archer.down[2] = TextureManager::load("Assets/Human/Units/Archer/Animation/Down2.png", renderer);
	human.archer.down[3] = TextureManager::load("Assets/Human/Units/Archer/Animation/Down3.png", renderer);

	human.archer.leftAttack[0] = TextureManager::load("Assets/Human/Units/Archer/Animation/Left Attack.png", renderer);
	human.archer.leftAttack[1] = TextureManager::load("Assets/Human/Units/Archer/Animation/Left Attack1.png", renderer);
	human.archer.leftAttack[2] = human.archer.leftAttack[1];
	human.archer.leftAttack[3] = human.archer.leftAttack[0];

	human.archer.upAttack[0] = TextureManager::load("Assets/Human/Units/Archer/Animation/Up Attack.png", renderer);
	human.archer.upAttack[1] = TextureManager::load("Assets/Human/Units/Archer/Animation/Up Attack1.png", renderer);
	human.archer.upAttack[2] = human.archer.upAttack[1];
	human.archer.upAttack[3] = human.archer.upAttack[0];

	human.archer.rightAttack[0] = TextureManager::load("Assets/Human/Units/Archer/Animation/Right Attack.png", renderer);
	human.archer.rightAttack[1] = TextureManager::load("Assets/Human/Units/Archer/Animation/Right Attack1.png", renderer);
	human.archer.rightAttack[2] = human.archer.rightAttack[1];
	human.archer.rightAttack[3] = human.archer.rightAttack[0];

	human.archer.downAttack[0] = TextureManager::load("Assets/Human/Units/Archer/Animation/Down Attack.png", renderer);
	human.archer.downAttack[1] = TextureManager::load("Assets/Human/Units/Archer/Animation/Down Attack1.png", renderer);
	human.archer.downAttack[2] = human.archer.downAttack[1];
	human.archer.downAttack[3] = human.archer.downAttack[0];

	human.archer.death[0] = TextureManager::load("Assets/Human/Units/Archer/Animation/Death.png", renderer);
	human.archer.death[1] = human.archer.death[0];
	human.archer.death[2] = TextureManager::load("Assets/Human/Units/Archer/Animation/Death1.png", renderer);
	human.archer.death[3] = human.archer.death[2];

	human.knight.left[0] = TextureManager::load("Assets/Human/Units/Knight/Animation/Left.png", renderer);
	human.knight.left[1] = TextureManager::load("Assets/Human/Units/Knight/Animation/Left1.png", renderer);
	human.knight.left[2] = TextureManager::load("Assets/Human/Units/Knight/Animation/Left2.png", renderer);
	human.knight.left[3] = TextureManager::load("Assets/Human/Units/Knight/Animation/Left3.png", renderer);

	human.knight.up[0] = TextureManager::load("Assets/Human/Units/Knight/Animation/Up.png", renderer);
	human.knight.up[1] = TextureManager::load("Assets/Human/Units/Knight/Animation/Up1.png", renderer);
	human.knight.up[2] = TextureManager::load("Assets/Human/Units/Knight/Animation/Up2.png", renderer);
	human.knight.up[3] = TextureManager::load("Assets/Human/Units/Knight/Animation/Up3.png", renderer);

	human.knight.right[0] = TextureManager::load("Assets/Human/Units/Knight/Animation/Right.png", renderer);
	human.knight.right[1] = TextureManager::load("Assets/Human/Units/Knight/Animation/Right1.png", renderer);
	human.knight.right[2] = TextureManager::load("Assets/Human/Units/Knight/Animation/Right2.png", renderer);
	human.knight.right[3] = TextureManager::load("Assets/Human/Units/Knight/Animation/Right3.png", renderer);

	human.knight.down[0] = TextureManager::load("Assets/Human/Units/Knight/Animation/Down.png", renderer);
	human.knight.down[1] = TextureManager::load("Assets/Human/Units/Knight/Animation/Down1.png", renderer);
	human.knight.down[2] = TextureManager::load("Assets/Human/Units/Knight/Animation/Down2.png", renderer);
	human.knight.down[3] = TextureManager::load("Assets/Human/Units/Knight/Animation/Down3.png", renderer);

	human.knight.leftAttack[0] = TextureManager::load("Assets/Human/Units/Knight/Animation/Left Attack.png", renderer);
	human.knight.leftAttack[1] = TextureManager::load("Assets/Human/Units/Knight/Animation/Left Attack1.png", renderer);
	human.knight.leftAttack[2] = TextureManager::load("Assets/Human/Units/Knight/Animation/Left Attack2.png", renderer);
	human.knight.leftAttack[3] = TextureManager::load("Assets/Human/Units/Knight/Animation/Left Attack3.png", renderer);

	human.knight.upAttack[0] = TextureManager::load("Assets/Human/Units/Knight/Animation/Up Attack.png", renderer);
	human.knight.upAttack[1] = TextureManager::load("Assets/Human/Units/Knight/Animation/Up Attack1.png", renderer);
	human.knight.upAttack[2] = TextureManager::load("Assets/Human/Units/Knight/Animation/Up Attack2.png", renderer);
	human.knight.upAttack[3] = TextureManager::load("Assets/Human/Units/Knight/Animation/Up Attack3.png", renderer);

	human.knight.rightAttack[0] = TextureManager::load("Assets/Human/Units/Knight/Animation/Right Attack.png", renderer);
	human.knight.rightAttack[1] = TextureManager::load("Assets/Human/Units/Knight/Animation/Right Attack1.png", renderer);
	human.knight.rightAttack[2] = TextureManager::load("Assets/Human/Units/Knight/Animation/Right Attack2.png", renderer);
	human.knight.rightAttack[3] = TextureManager::load("Assets/Human/Units/Knight/Animation/Right Attack3.png", renderer);

	human.knight.downAttack[0] = TextureManager::load("Assets/Human/Units/Knight/Animation/Down Attack.png", renderer);
	human.knight.downAttack[1] = TextureManager::load("Assets/Human/Units/Knight/Animation/Down Attack1.png", renderer);
	human.knight.downAttack[2] = TextureManager::load("Assets/Human/Units/Knight/Animation/Down Attack2.png", renderer);
	human.knight.downAttack[3] = TextureManager::load("Assets/Human/Units/Knight/Animation/Down Attack3.png", renderer);

	human.knight.death[0] = TextureManager::load("Assets/Human/Units/Knight/Animation/Death.png", renderer);
	human.knight.death[1] = human.knight.death[0];
	human.knight.death[2] = TextureManager::load("Assets/Human/Units/Knight/Animation/Death1.png", renderer);
	human.knight.death[3] = human.knight.death[2];

	human.wing.left[0] = TextureManager::load("Assets/Human/Units/Wing/Animation/Left.png", renderer);
	human.wing.left[1] = TextureManager::load("Assets/Human/Units/Wing/Animation/Left1.png", renderer);
	human.wing.left[2] = TextureManager::load("Assets/Human/Units/Wing/Animation/Left2.png", renderer);
	human.wing.left[3] = TextureManager::load("Assets/Human/Units/Wing/Animation/Left3.png", renderer);

	human.wing.up[0] = TextureManager::load("Assets/Human/Units/Wing/Animation/Up.png", renderer);
	human.wing.up[1] = TextureManager::load("Assets/Human/Units/Wing/Animation/Up1.png", renderer);
	human.wing.up[2] = TextureManager::load("Assets/Human/Units/Wing/Animation/Up2.png", renderer);
	human.wing.up[3] = TextureManager::load("Assets/Human/Units/Wing/Animation/Up3.png", renderer);

	human.wing.right[0] = TextureManager::load("Assets/Human/Units/Wing/Animation/Right.png", renderer);
	human.wing.right[1] = TextureManager::load("Assets/Human/Units/Wing/Animation/Right1.png", renderer);
	human.wing.right[2] = TextureManager::load("Assets/Human/Units/Wing/Animation/Right2.png", renderer);
	human.wing.right[3] = TextureManager::load("Assets/Human/Units/Wing/Animation/Right3.png", renderer);

	human.wing.down[0] = TextureManager::load("Assets/Human/Units/Wing/Animation/Down.png", renderer);
	human.wing.down[1] = TextureManager::load("Assets/Human/Units/Wing/Animation/Down1.png", renderer);
	human.wing.down[2] = TextureManager::load("Assets/Human/Units/Wing/Animation/Down2.png", renderer);
	human.wing.down[3] = TextureManager::load("Assets/Human/Units/Wing/Animation/Down3.png", renderer);

	human.wing.leftAttack[0] = TextureManager::load("Assets/Human/Units/Wing/Animation/Left Attack.png", renderer);
	human.wing.leftAttack[1] = TextureManager::load("Assets/Human/Units/Wing/Animation/Left Attack1.png", renderer);
	human.wing.leftAttack[2] = TextureManager::load("Assets/Human/Units/Wing/Animation/Left Attack2.png", renderer);
	human.wing.leftAttack[3] = human.wing.leftAttack[0];

	human.wing.upAttack[0] = TextureManager::load("Assets/Human/Units/Wing/Animation/Up Attack.png", renderer);
	human.wing.upAttack[1] = TextureManager::load("Assets/Human/Units/Wing/Animation/Up Attack1.png", renderer);
	human.wing.upAttack[2] = TextureManager::load("Assets/Human/Units/Wing/Animation/Up Attack2.png", renderer);
	human.wing.upAttack[3] = human.wing.upAttack[0];

	human.wing.rightAttack[0] = TextureManager::load("Assets/Human/Units/Wing/Animation/Right Attack.png", renderer);
	human.wing.rightAttack[1] = TextureManager::load("Assets/Human/Units/Wing/Animation/Right Attack1.png", renderer);
	human.wing.rightAttack[2] = TextureManager::load("Assets/Human/Units/Wing/Animation/Right Attack2.png", renderer);
	human.wing.rightAttack[3] = human.wing.rightAttack[0];

	human.wing.downAttack[0] = TextureManager::load("Assets/Human/Units/Wing/Animation/Down Attack.png", renderer);
	human.wing.downAttack[1] = TextureManager::load("Assets/Human/Units/Wing/Animation/Down Attack1.png", renderer);
	human.wing.downAttack[2] = TextureManager::load("Assets/Human/Units/Wing/Animation/Down Attack2.png", renderer);
	human.wing.downAttack[3] = human.wing.downAttack[0];

	human.wing.death[0] = TextureManager::load("Assets/Human/Units/Wing/Animation/Death.png", renderer);
	human.wing.death[1] = human.wing.death[0];
	human.wing.death[2] = TextureManager::load("Assets/Human/Units/Wing/Animation/Death1.png", renderer);
	human.wing.death[3] = human.wing.death[2];

	orc.infantry.left[0] = TextureManager::load("Assets/Orc/Units/Infantry/Animation/Left.png", renderer);
	orc.infantry.left[1] = TextureManager::load("Assets/Orc/Units/Infantry/Animation/Left1.png", renderer);
	orc.infantry.left[2] = TextureManager::load("Assets/Orc/Units/Infantry/Animation/Left2.png", renderer);
	orc.infantry.left[3] = TextureManager::load("Assets/Orc/Units/Infantry/Animation/Left3.png", renderer);

	orc.infantry.up[0] = TextureManager::load("Assets/Orc/Units/Infantry/Animation/Up.png", renderer);
	orc.infantry.up[1] = TextureManager::load("Assets/Orc/Units/Infantry/Animation/Up1.png", renderer);
	orc.infantry.up[2] = TextureManager::load("Assets/Orc/Units/Infantry/Animation/Up2.png", renderer);
	orc.infantry.up[3] = TextureManager::load("Assets/Orc/Units/Infantry/Animation/Up3.png", renderer);

	orc.infantry.right[0] = TextureManager::load("Assets/Orc/Units/Infantry/Animation/Right.png", renderer);
	orc.infantry.right[1] = TextureManager::load("Assets/Orc/Units/Infantry/Animation/Right1.png", renderer);
	orc.infantry.right[2] = TextureManager::load("Assets/Orc/Units/Infantry/Animation/Right2.png", renderer);
	orc.infantry.right[3] = TextureManager::load("Assets/Orc/Units/Infantry/Animation/Right3.png", renderer);

	orc.infantry.down[0] = TextureManager::load("Assets/Orc/Units/Infantry/Animation/Down.png", renderer);
	orc.infantry.down[1] = TextureManager::load("Assets/Orc/Units/Infantry/Animation/Down1.png", renderer);
	orc.infantry.down[2] = TextureManager::load("Assets/Orc/Units/Infantry/Animation/Down2.png", renderer);
	orc.infantry.down[3] = TextureManager::load("Assets/Orc/Units/Infantry/Animation/Down3.png", renderer);

	orc.infantry.leftAttack[0] = TextureManager::load("Assets/Orc/Units/Infantry/Animation/Left Attack.png", renderer);
	orc.infantry.leftAttack[1] = TextureManager::load("Assets/Orc/Units/Infantry/Animation/Left Attack1.png", renderer);
	orc.infantry.leftAttack[2] = TextureManager::load("Assets/Orc/Units/Infantry/Animation/Left Attack2.png", renderer);
	orc.infantry.leftAttack[3] = TextureManager::load("Assets/Orc/Units/Infantry/Animation/Left Attack3.png", renderer);

	orc.infantry.upAttack[0] = TextureManager::load("Assets/Orc/Units/Infantry/Animation/Up Attack.png", renderer);
	orc.infantry.upAttack[1] = TextureManager::load("Assets/Orc/Units/Infantry/Animation/Up Attack1.png", renderer);
	orc.infantry.upAttack[2] = TextureManager::load("Assets/Orc/Units/Infantry/Animation/Up Attack2.png", renderer);
	orc.infantry.upAttack[3] = TextureManager::load("Assets/Orc/Units/Infantry/Animation/Up Attack3.png", renderer);

	orc.infantry.rightAttack[0] = TextureManager::load("Assets/Orc/Units/Infantry/Animation/Right Attack.png", renderer);
	orc.infantry.rightAttack[1] = TextureManager::load("Assets/Orc/Units/Infantry/Animation/Right Attack1.png", renderer);
	orc.infantry.rightAttack[2] = TextureManager::load("Assets/Orc/Units/Infantry/Animation/Right Attack2.png", renderer);
	orc.infantry.rightAttack[3] = TextureManager::load("Assets/Orc/Units/Infantry/Animation/Right Attack3.png", renderer);

	orc.infantry.downAttack[0] = TextureManager::load("Assets/Orc/Units/Infantry/Animation/Down Attack.png", renderer);
	orc.infantry.downAttack[1] = TextureManager::load("Assets/Orc/Units/Infantry/Animation/Down Attack1.png", renderer);
	orc.infantry.downAttack[2] = TextureManager::load("Assets/Orc/Units/Infantry/Animation/Down Attack2.png", renderer);
	orc.infantry.downAttack[3] = TextureManager::load("Assets/Orc/Units/Infantry/Animation/Down Attack3.png", renderer);

	orc.infantry.death[0] = TextureManager::load("Assets/Orc/Units/Infantry/Animation/Death.png", renderer);
	orc.infantry.death[1] = orc.infantry.death[0];
	orc.infantry.death[2] = TextureManager::load("Assets/Orc/Units/Infantry/Animation/Death1.png", renderer);
	orc.infantry.death[3] = orc.infantry.death[2];

	orc.archer.left[0] = TextureManager::load("Assets/Orc/Units/Archer/Animation/Left.png", renderer);
	orc.archer.left[1] = TextureManager::load("Assets/Orc/Units/Archer/Animation/Left1.png", renderer);
	orc.archer.left[2] = TextureManager::load("Assets/Orc/Units/Archer/Animation/Left2.png", renderer);
	orc.archer.left[3] = TextureManager::load("Assets/Orc/Units/Archer/Animation/Left3.png", renderer);

	orc.archer.up[0] = TextureManager::load("Assets/Orc/Units/Archer/Animation/Up.png", renderer);
	orc.archer.up[1] = TextureManager::load("Assets/Orc/Units/Archer/Animation/Up1.png", renderer);
	orc.archer.up[2] = TextureManager::load("Assets/Orc/Units/Archer/Animation/Up2.png", renderer);
	orc.archer.up[3] = TextureManager::load("Assets/Orc/Units/Archer/Animation/Up3.png", renderer);

	orc.archer.right[0] = TextureManager::load("Assets/Orc/Units/Archer/Animation/Right.png", renderer);
	orc.archer.right[1] = TextureManager::load("Assets/Orc/Units/Archer/Animation/Right1.png", renderer);
	orc.archer.right[2] = TextureManager::load("Assets/Orc/Units/Archer/Animation/Right2.png", renderer);
	orc.archer.right[3] = TextureManager::load("Assets/Orc/Units/Archer/Animation/Right3.png", renderer);

	orc.archer.down[0] = TextureManager::load("Assets/Orc/Units/Archer/Animation/Down.png", renderer);
	orc.archer.down[1] = TextureManager::load("Assets/Orc/Units/Archer/Animation/Down1.png", renderer);
	orc.archer.down[2] = TextureManager::load("Assets/Orc/Units/Archer/Animation/Down2.png", renderer);
	orc.archer.down[3] = TextureManager::load("Assets/Orc/Units/Archer/Animation/Down3.png", renderer);

	orc.archer.leftAttack[0] = TextureManager::load("Assets/Orc/Units/Archer/Animation/Left Attack.png", renderer);
	orc.archer.leftAttack[1] = TextureManager::load("Assets/Orc/Units/Archer/Animation/Left Attack1.png", renderer);
	orc.archer.leftAttack[2] = TextureManager::load("Assets/Orc/Units/Archer/Animation/Left Attack2.png", renderer);
	orc.archer.leftAttack[3] = TextureManager::load("Assets/Orc/Units/Archer/Animation/Left Attack3.png", renderer);

	orc.archer.upAttack[0] = TextureManager::load("Assets/Orc/Units/Archer/Animation/Up Attack.png", renderer);
	orc.archer.upAttack[1] = TextureManager::load("Assets/Orc/Units/Archer/Animation/Up Attack1.png", renderer);
	orc.archer.upAttack[2] = TextureManager::load("Assets/Orc/Units/Archer/Animation/Up Attack2.png", renderer);
	orc.archer.upAttack[3] = TextureManager::load("Assets/Orc/Units/Archer/Animation/Up Attack3.png", renderer);

	orc.archer.rightAttack[0] = TextureManager::load("Assets/Orc/Units/Archer/Animation/Right Attack.png", renderer);
	orc.archer.rightAttack[1] = TextureManager::load("Assets/Orc/Units/Archer/Animation/Right Attack1.png", renderer);
	orc.archer.rightAttack[2] = TextureManager::load("Assets/Orc/Units/Archer/Animation/Right Attack2.png", renderer);
	orc.archer.rightAttack[3] = TextureManager::load("Assets/Orc/Units/Archer/Animation/Right Attack3.png", renderer);

	orc.archer.downAttack[0] = TextureManager::load("Assets/Orc/Units/Archer/Animation/Down Attack.png", renderer);
	orc.archer.downAttack[1] = TextureManager::load("Assets/Orc/Units/Archer/Animation/Down Attack1.png", renderer);
	orc.archer.downAttack[2] = TextureManager::load("Assets/Orc/Units/Archer/Animation/Down Attack2.png", renderer);
	orc.archer.downAttack[3] = TextureManager::load("Assets/Orc/Units/Archer/Animation/Down Attack3.png", renderer);

	orc.archer.death[0] = TextureManager::load("Assets/Orc/Units/Archer/Animation/Death.png", renderer);
	orc.archer.death[1] = orc.archer.death[0];
	orc.archer.death[2] = TextureManager::load("Assets/Orc/Units/Archer/Animation/Death1.png", renderer);
	orc.archer.death[3] = orc.archer.death[2];

	orc.knight.left[0] = TextureManager::load("Assets/Orc/Units/Knight/Animation/Left.png", renderer);
	orc.knight.left[1] = TextureManager::load("Assets/Orc/Units/Knight/Animation/Left1.png", renderer);
	orc.knight.left[2] = TextureManager::load("Assets/Orc/Units/Knight/Animation/Left2.png", renderer);
	orc.knight.left[3] = TextureManager::load("Assets/Orc/Units/Knight/Animation/Left3.png", renderer);

	orc.knight.up[0] = TextureManager::load("Assets/Orc/Units/Knight/Animation/Up.png", renderer);
	orc.knight.up[1] = TextureManager::load("Assets/Orc/Units/Knight/Animation/Up1.png", renderer);
	orc.knight.up[2] = TextureManager::load("Assets/Orc/Units/Knight/Animation/Up2.png", renderer);
	orc.knight.up[3] = TextureManager::load("Assets/Orc/Units/Knight/Animation/Up3.png", renderer);

	orc.knight.right[0] = TextureManager::load("Assets/Orc/Units/Knight/Animation/Right.png", renderer);
	orc.knight.right[1] = TextureManager::load("Assets/Orc/Units/Knight/Animation/Right1.png", renderer);
	orc.knight.right[2] = TextureManager::load("Assets/Orc/Units/Knight/Animation/Right2.png", renderer);
	orc.knight.right[3] = TextureManager::load("Assets/Orc/Units/Knight/Animation/Right3.png", renderer);

	orc.knight.down[0] = TextureManager::load("Assets/Orc/Units/Knight/Animation/Down.png", renderer);
	orc.knight.down[1] = TextureManager::load("Assets/Orc/Units/Knight/Animation/Down1.png", renderer);
	orc.knight.down[2] = TextureManager::load("Assets/Orc/Units/Knight/Animation/Down2.png", renderer);
	orc.knight.down[3] = TextureManager::load("Assets/Orc/Units/Knight/Animation/Down3.png", renderer);

	orc.knight.leftAttack[0] = TextureManager::load("Assets/Orc/Units/Knight/Animation/Left Attack.png", renderer);
	orc.knight.leftAttack[1] = TextureManager::load("Assets/Orc/Units/Knight/Animation/Left Attack1.png", renderer);
	orc.knight.leftAttack[2] = TextureManager::load("Assets/Orc/Units/Knight/Animation/Left Attack2.png", renderer);
	orc.knight.leftAttack[3] = TextureManager::load("Assets/Orc/Units/Knight/Animation/Left Attack3.png", renderer);

	orc.knight.upAttack[0] = TextureManager::load("Assets/Orc/Units/Knight/Animation/Up Attack.png", renderer);
	orc.knight.upAttack[1] = TextureManager::load("Assets/Orc/Units/Knight/Animation/Up Attack1.png", renderer);
	orc.knight.upAttack[2] = TextureManager::load("Assets/Orc/Units/Knight/Animation/Up Attack2.png", renderer);
	orc.knight.upAttack[3] = TextureManager::load("Assets/Orc/Units/Knight/Animation/Up Attack3.png", renderer);

	orc.knight.rightAttack[0] = TextureManager::load("Assets/Orc/Units/Knight/Animation/Right Attack.png", renderer);
	orc.knight.rightAttack[1] = TextureManager::load("Assets/Orc/Units/Knight/Animation/Right Attack1.png", renderer);
	orc.knight.rightAttack[2] = TextureManager::load("Assets/Orc/Units/Knight/Animation/Right Attack2.png", renderer);
	orc.knight.rightAttack[3] = TextureManager::load("Assets/Orc/Units/Knight/Animation/Right Attack3.png", renderer);

	orc.knight.downAttack[0] = TextureManager::load("Assets/Orc/Units/Knight/Animation/Down Attack.png", renderer);
	orc.knight.downAttack[1] = TextureManager::load("Assets/Orc/Units/Knight/Animation/Down Attack1.png", renderer);
	orc.knight.downAttack[2] = TextureManager::load("Assets/Orc/Units/Knight/Animation/Down Attack2.png", renderer);
	orc.knight.downAttack[3] = TextureManager::load("Assets/Orc/Units/Knight/Animation/Down Attack3.png", renderer);

	orc.knight.death[0] = TextureManager::load("Assets/Orc/Units/Knight/Animation/Death.png", renderer);
	orc.knight.death[1] = orc.knight.death[0];
	orc.knight.death[2] = TextureManager::load("Assets/Orc/Units/Knight/Animation/Death1.png", renderer);
	orc.knight.death[3] = orc.knight.death[2];

	orc.wing.left[0] = TextureManager::load("Assets/Orc/Units/Wing/Animation/Left.png", renderer);
	orc.wing.left[1] = TextureManager::load("Assets/Orc/Units/Wing/Animation/Left1.png", renderer);
	orc.wing.left[2] = TextureManager::load("Assets/Orc/Units/Wing/Animation/Left2.png", renderer);
	orc.wing.left[3] = TextureManager::load("Assets/Orc/Units/Wing/Animation/Left3.png", renderer);

	orc.wing.up[0] = TextureManager::load("Assets/Orc/Units/Wing/Animation/Up.png", renderer);
	orc.wing.up[1] = TextureManager::load("Assets/Orc/Units/Wing/Animation/Up1.png", renderer);
	orc.wing.up[2] = TextureManager::load("Assets/Orc/Units/Wing/Animation/Up2.png", renderer);
	orc.wing.up[3] = TextureManager::load("Assets/Orc/Units/Wing/Animation/Up3.png", renderer);

	orc.wing.right[0] = TextureManager::load("Assets/Orc/Units/Wing/Animation/Right.png", renderer);
	orc.wing.right[1] = TextureManager::load("Assets/Orc/Units/Wing/Animation/Right1.png", renderer);
	orc.wing.right[2] = TextureManager::load("Assets/Orc/Units/Wing/Animation/Right2.png", renderer);
	orc.wing.right[3] = TextureManager::load("Assets/Orc/Units/Wing/Animation/Right3.png", renderer);

	orc.wing.down[0] = TextureManager::load("Assets/Orc/Units/Wing/Animation/Down.png", renderer);
	orc.wing.down[1] = TextureManager::load("Assets/Orc/Units/Wing/Animation/Down1.png", renderer);
	orc.wing.down[2] = TextureManager::load("Assets/Orc/Units/Wing/Animation/Down2.png", renderer);
	orc.wing.down[3] = TextureManager::load("Assets/Orc/Units/Wing/Animation/Down3.png", renderer);

	orc.wing.leftAttack[0] = orc.wing.left[0];
	orc.wing.leftAttack[1] = orc.wing.left[1];
	orc.wing.leftAttack[2] = orc.wing.left[2];
	orc.wing.leftAttack[3] = orc.wing.left[3];

	orc.wing.upAttack[0] = orc.wing.up[0];
	orc.wing.upAttack[1] = orc.wing.up[1];
	orc.wing.upAttack[2] = orc.wing.up[2];
	orc.wing.upAttack[3] = orc.wing.up[3];

	orc.wing.rightAttack[0] = orc.wing.right[0];
	orc.wing.rightAttack[1] = orc.wing.right[1];
	orc.wing.rightAttack[2] = orc.wing.right[2];
	orc.wing.rightAttack[3] = orc.wing.right[3];

	orc.wing.downAttack[0] = orc.wing.down[0];
	orc.wing.downAttack[1] = orc.wing.down[1];
	orc.wing.downAttack[2] = orc.wing.down[2];
	orc.wing.downAttack[3] = orc.wing.down[3];

	orc.wing.death[0] = TextureManager::load("Assets/Orc/Units/Wing/Animation/Death.png", renderer);
	orc.wing.death[1] = orc.wing.death[0];
	orc.wing.death[2] = TextureManager::load("Assets/Orc/Units/Wing/Animation/Death1.png", renderer);
	orc.wing.death[3] = orc.wing.death[2];
}

void AnimationTexture::destroyTextures(void)
{
	for (Uint8 i = 0; i < ANIMATION_FRAMES; ++i)
	{
		TextureManager::destroy(human.infantry.left[i]);
		TextureManager::destroy(human.infantry.up[i]);
		TextureManager::destroy(human.infantry.right[i]);
		TextureManager::destroy(human.infantry.down[i]);

		TextureManager::destroy(human.infantry.leftAttack[i]);
		TextureManager::destroy(human.infantry.upAttack[i]);
		TextureManager::destroy(human.infantry.rightAttack[i]);
		TextureManager::destroy(human.infantry.downAttack[i]);

		TextureManager::destroy(human.archer.left[i]);
		TextureManager::destroy(human.archer.up[i]);
		TextureManager::destroy(human.archer.right[i]);
		TextureManager::destroy(human.archer.down[i]);

		TextureManager::destroy(human.archer.leftAttack[i]);
		TextureManager::destroy(human.archer.upAttack[i]);
		TextureManager::destroy(human.archer.rightAttack[i]);
		TextureManager::destroy(human.archer.downAttack[i]);

		TextureManager::destroy(human.knight.left[i]);
		TextureManager::destroy(human.knight.up[i]);
		TextureManager::destroy(human.knight.right[i]);
		TextureManager::destroy(human.knight.down[i]);

		TextureManager::destroy(human.knight.leftAttack[i]);
		TextureManager::destroy(human.knight.upAttack[i]);
		TextureManager::destroy(human.knight.rightAttack[i]);
		TextureManager::destroy(human.knight.downAttack[i]);

		TextureManager::destroy(human.wing.left[i]);
		TextureManager::destroy(human.wing.up[i]);
		TextureManager::destroy(human.wing.right[i]);
		TextureManager::destroy(human.wing.down[i]);

		TextureManager::destroy(human.wing.leftAttack[i]);
		TextureManager::destroy(human.wing.upAttack[i]);
		TextureManager::destroy(human.wing.rightAttack[i]);
		TextureManager::destroy(human.wing.downAttack[i]);

		TextureManager::destroy(orc.infantry.left[i]);
		TextureManager::destroy(orc.infantry.up[i]);
		TextureManager::destroy(orc.infantry.right[i]);
		TextureManager::destroy(orc.infantry.down[i]);

		TextureManager::destroy(orc.infantry.leftAttack[i]);
		TextureManager::destroy(orc.infantry.upAttack[i]);
		TextureManager::destroy(orc.infantry.rightAttack[i]);
		TextureManager::destroy(orc.infantry.downAttack[i]);

		TextureManager::destroy(orc.archer.left[i]);
		TextureManager::destroy(orc.archer.up[i]);
		TextureManager::destroy(orc.archer.right[i]);
		TextureManager::destroy(orc.archer.down[i]);

		TextureManager::destroy(orc.archer.leftAttack[i]);
		TextureManager::destroy(orc.archer.upAttack[i]);
		TextureManager::destroy(orc.archer.rightAttack[i]);
		TextureManager::destroy(orc.archer.downAttack[i]);

		TextureManager::destroy(orc.knight.left[i]);
		TextureManager::destroy(orc.knight.up[i]);
		TextureManager::destroy(orc.knight.right[i]);
		TextureManager::destroy(orc.knight.down[i]);

		TextureManager::destroy(orc.knight.leftAttack[i]);
		TextureManager::destroy(orc.knight.upAttack[i]);
		TextureManager::destroy(orc.knight.rightAttack[i]);
		TextureManager::destroy(orc.knight.downAttack[i]);

		TextureManager::destroy(orc.wing.left[i]);
		TextureManager::destroy(orc.wing.up[i]);
		TextureManager::destroy(orc.wing.right[i]);
		TextureManager::destroy(orc.wing.down[i]);

		TextureManager::destroy(orc.wing.leftAttack[i]);
		TextureManager::destroy(orc.wing.upAttack[i]);
		TextureManager::destroy(orc.wing.rightAttack[i]);
		TextureManager::destroy(orc.wing.downAttack[i]);

		TextureManager::destroy(human.infantry.death[i]);
		TextureManager::destroy(human.archer.death[i]);
		TextureManager::destroy(human.knight.death[i]);
		TextureManager::destroy(human.wing.death[i]);

		TextureManager::destroy(orc.infantry.death[i]);
		TextureManager::destroy(orc.archer.death[i]);
		TextureManager::destroy(orc.knight.death[i]);
		TextureManager::destroy(orc.wing.death[i]);
	}
}
