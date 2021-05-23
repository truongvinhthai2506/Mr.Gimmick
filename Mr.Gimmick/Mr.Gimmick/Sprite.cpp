#include "Sprite.h"

Sprite::Sprite()
{

}

Sprite::Sprite(Dimension dimension, LPCWSTR filename, int lastFrame, int animationDelay, 
	int currentFrame, int animationCount) : Image(dimension, filename)
{
	this->spriteHandler = SpriteHandler(lastFrame, animationDelay, currentFrame, animationCount);
}

SpriteHandler Sprite::GetSpriteHandler()
{
	return this->spriteHandler;
}

void Sprite::Animate(bool isChangeFrame)
{
	this->spriteHandler.Animate(isChangeFrame);
}

Sprite* Sprite::Clone()
{
	return new Sprite(*this);
}

void Sprite::SetAnimationDelay(int animationDelay)
{
	this->spriteHandler.SetAnimationDelay(animationDelay);
}

int Sprite::GetCurrentFrame()
{
	return this->spriteHandler.GetCurrentFrame();
}

void Sprite::SetCurrentFrame(int currentFrame)
{
	this->spriteHandler.SetCurrentFrame(currentFrame);
}

int Sprite::GetLastFrame()
{
	return this->spriteHandler.GetLastFrame();
}

void Sprite::SetLastFrame(int lastFrame)
{
	this->spriteHandler.SetLastFrame(lastFrame);
}