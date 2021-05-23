#include "SpriteHandler.h"

SpriteHandler::SpriteHandler()
{
	this->currentFrame = this->lastFrame = this->animationCount = this->animationDelay = 0;
}

SpriteHandler::SpriteHandler(int lastFrame, int animationDelay, int currentFrame, int animationCount)
{
	this->currentFrame = currentFrame;
	this->lastFrame = lastFrame;
	this->animationCount = animationCount;
	this->animationDelay = animationDelay;
}

void SpriteHandler::Animate(bool isChangeFrame)
{
	if (++this->animationCount > this->animationDelay)
	{
		this->animationCount = 0;

		if (isChangeFrame && ++this->currentFrame > this->lastFrame)
		{
			this->currentFrame = 1;
		}
	}
}

RECT SpriteHandler::GetTile(int indexOfRow, Dimension dimension)
{
	float width = dimension.GetFirstValue(), height = dimension.GetSecondValue();
	RECT sourceRectangle;

	sourceRectangle.right = this->currentFrame * width;
	sourceRectangle.bottom = indexOfRow * height;
	sourceRectangle.left = sourceRectangle.right - width;
	sourceRectangle.top = sourceRectangle.bottom - height;

	return sourceRectangle;
}

void SpriteHandler::SetAnimationDelay(int animationDelay)
{
	this->animationDelay = animationDelay;
}

int SpriteHandler::GetCurrentFrame()
{
	return this->currentFrame;
}

void SpriteHandler::SetCurrentFrame(int currentFrame)
{
	this->currentFrame = currentFrame;
}

int SpriteHandler::GetLastFrame()
{
	return this->lastFrame;
}

void SpriteHandler::SetLastFrame(int lastFrame)
{
	this->lastFrame = lastFrame;
}