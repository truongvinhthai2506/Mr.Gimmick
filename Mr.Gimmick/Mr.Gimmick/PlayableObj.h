#pragma once

#include "AnimatedAndMovableObj.h"

class PlayableObj : public AnimatedAndMovableObj
{
public:
    PlayableObj(const PlayableObj& playableObj);
    PlayableObj();
    PlayableObj(Point point, int numberOfAnimatedTiles, Velocity velocity, int gameObjID);
};