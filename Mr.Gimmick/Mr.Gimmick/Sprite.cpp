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

void Sprite::Animate()
{
	this->spriteHandler.Animate();
}

Sprite* Sprite::Clone()
{
	return new Sprite(*this);
}