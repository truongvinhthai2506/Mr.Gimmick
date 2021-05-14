#pragma once

#include "AnimatedObj.h"

class AnimatedAndImmovableObj : public AnimatedObj
{
public:
    AnimatedAndImmovableObj();
    AnimatedAndImmovableObj(Point point, int numberOfAnimatedTiles, int gameObjID);
};