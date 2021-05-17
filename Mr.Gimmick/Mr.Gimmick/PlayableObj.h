#pragma once

#include "AnimatedAndMovableObj.h"

class PlayableObj : public AnimatedAndMovableObj
{
public:
    PlayableObj(const PlayableObj& playableObj);
    PlayableObj();
    PlayableObj(Point point, Velocity velocity, int gameObjID, Dimension dimension, String fileSpriteName,
        int lastFrame, int indexOfRowInSprite, int currentFrame);
};