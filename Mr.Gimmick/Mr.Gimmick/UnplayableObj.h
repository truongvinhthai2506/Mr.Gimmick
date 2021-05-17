#pragma once

#include "AnimatedAndMovableObj.h"

class UnplayableObj : public AnimatedAndMovableObj
{
public:
	UnplayableObj();
	UnplayableObj(Point point, Velocity velocity, int gameObjID, Dimension dimension, 
		String fileSpriteName, int lastFrame, int indexOfRowInSprite, int currentFrame);
};