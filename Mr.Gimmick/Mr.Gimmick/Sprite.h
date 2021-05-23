#pragma once

#include "Image.h"
#include "SpriteHandler.h"

class Sprite : public Image
{
private:
	SpriteHandler spriteHandler;
public:
	Sprite();
	Sprite(Dimension dimension, LPCWSTR filename, int lastFrame, int animationDelay,
		int currentFrame = 0, int animationCount = 0);
	SpriteHandler GetSpriteHandler();
	void Animate(bool isChangeFrame);
	Sprite* Clone();
	void SetAnimationDelay(int animationDelay);
	int GetCurrentFrame();
	void SetCurrentFrame(int currentFrame);
	int GetLastFrame();
	void SetLastFrame(int lastFrame);
};