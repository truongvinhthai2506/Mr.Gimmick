#pragma once

#include "AnimatedAndMovableObj.h"

class UnplayableObj : public AnimatedAndMovableObj
{
public:
	UnplayableObj();
	UnplayableObj(Point point, int numberOfAnimatedTiles, Velocity velocity, int gameObjID);
};