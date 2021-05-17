#pragma once

#include "UsefulObj.h"

#pragma region Definition
#define ITEMS_AND_HUD_BACKGROUND_COLOR Color(D3DCOLOR_XRGB(255, 255, 255))

#define SPRITE_ITEMS_AND_HUD_PATH L"../../Resource/Image/Items_and_HUD.png"
#pragma endregion

class ItemsAndHUD : public UsefulObj
{
public:
    ItemsAndHUD();
    ItemsAndHUD(Point point, int gameObjID, int currentFrame = 1, Dimension dimension = Dimension(16.5, 
        17), String fileSpriteName = SPRITE_ITEMS_AND_HUD_PATH, int lastFrame = 1, 
        int indexOfRowInSprite = 1);
};