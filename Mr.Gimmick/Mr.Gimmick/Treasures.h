#pragma once

#include "UsefulObj.h"

#pragma region Definition
#define TREASURES_BACKGROUND_COLOR Color(D3DCOLOR_XRGB(60, 188, 252))

#define SPRITE_TREASURES_PATH L"../../Resource/Image/Treasures.png"
#pragma endregion

class Treasures : public UsefulObj
{
public:
    Treasures();
    Treasures(Point point, int gameObjID, int currentFrame = 1, Dimension dimension = Dimension(23, 50),
        String fileSpriteName = SPRITE_TREASURES_PATH, int lastFrame = 1, int indexOfRowInSprite = 1);
};