#pragma once

#include "UnplayableObj.h"

#pragma region Definition
#define ENEMIES_BACKGROUND_COLOR Color(D3DCOLOR_XRGB(57, 189, 255))

#define SPRITE_ENEMIES_PATH L"../../Resource/Image/Enemies.png"
#pragma endregion

class Enemies : public UnplayableObj
{
public:
    Enemies();
    Enemies(Point point, int gameObjID, Dimension dimension = Dimension(19.4, 19.4), 
        int indexOfRowInSprite = 1, Velocity velocity = Velocity(2, 0), int numberOfAnimatedTiles = 1, 
        String fileSpriteName = SPRITE_ENEMIES_PATH, int lastFrame = 1, int currentFrame = 1);
};