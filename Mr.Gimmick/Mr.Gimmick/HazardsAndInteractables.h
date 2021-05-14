#pragma once

#include "AnimatedObj.h"

#pragma region Definition
#define HAZARDS_AND_INTERACTABLES_BACKGROUND_COLOR D3DCOLOR_XRGB(203, 102, 185)

#define SPRITE_HAZARDS_AND_INTERACTABLES_PATH L"../../Resource/Image/Hazards_and_interactables.png"
#pragma endregion

class HazardsAndInteractables : public AnimatedObj
{
public:
    HazardsAndInteractables();
    HazardsAndInteractables(Point point, int gameObjID, int currentFrame = 1, Dimension dimension = 
        Dimension(17, 23), int numberOfAnimatedTiles = 1, 
        LPCWSTR fileSpriteName = SPRITE_HAZARDS_AND_INTERACTABLES_PATH);
    HazardsAndInteractables& operator = (const HazardsAndInteractables& hazardsAndInteractables);
    bool Load(D3DXCOLOR transparentColor, DirectXGraphic directXGrphic);
};