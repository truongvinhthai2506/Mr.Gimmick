#pragma once

#include "AnimatedObj.h"

class AnimatedAndImmovableObj : public AnimatedObj
{
public:
    AnimatedAndImmovableObj();
    AnimatedAndImmovableObj(Point point, int numberOfAnimatedTiles, int gameObjID);
	AnimatedAndImmovableObj(Point point, int gameObjID, Dimension dimension, String fileSpriteName, 
        int lastFrame, int indexOfRowInSprite, int currentFrame);
};