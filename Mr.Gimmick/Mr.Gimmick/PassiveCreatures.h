#pragma once

#include "UnplayableObj.h"

#pragma region Definition
#define PASSIVE_CREATURES_BACKGROUND_COLOR D3DCOLOR_XRGB(60, 188, 252)

#define SPRITE_PASSIVE_CREATURES_PATH L"../../Resource/Image/Passive_creatures.png"
#pragma endregion

class PassiveCreatures : public UnplayableObj
{
public:
    PassiveCreatures();
    PassiveCreatures(Point point, int gameObjID, int indexOfRowInSprite, Velocity velocity = Velocity(2, 
        0), Dimension dimension = Dimension(20.4, 20.4), 
        String fileSpriteName = SPRITE_PASSIVE_CREATURES_PATH, int lastFrame = 1, int currentFrame = 1);
    PassiveCreatures& operator = (const PassiveCreatures& enemies);
    bool Load(D3DXCOLOR transparentColor, DirectXGraphic directXGrphic);
};