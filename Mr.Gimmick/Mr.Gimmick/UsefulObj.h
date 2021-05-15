#pragma once

#include "AnimatedAndImmovableObj.h"

class UsefulObj : public AnimatedAndImmovableObj
{
public:
    UsefulObj();
    UsefulObj(Point point, int numberOfAnimatedTiles, int gameObjID, int currentFrame, 
        Dimension dimension, String fileSpriteName);
};