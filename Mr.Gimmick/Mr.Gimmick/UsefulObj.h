#pragma once

#include "AnimatedAndImmovableObj.h"

class UsefulObj : public AnimatedAndImmovableObj
{
public:
    UsefulObj();
    UsefulObj(Point point, int gameObjID, Dimension dimension, String fileSpriteName, int lastFrame, 
        int indexOfRowInSprite, int currentFrame);
};