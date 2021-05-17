#pragma once

#include "AnimatedObj.h"

#pragma region Definition
#define HAZARDS_AND_INTERACTABLES_BACKGROUND_COLOR Color(D3DCOLOR_XRGB(203, 102, 185))

#define SPRITE_HAZARDS_AND_INTERACTABLES_PATH L"../../Resource/Image/Hazards_and_interactables.png"
#pragma endregion

class HazardsAndInteractables : public AnimatedObj
{
public:
    HazardsAndInteractables();
    HazardsAndInteractables(Point point, int gameObjID, int currentFrame = 1, Dimension dimension = 
        Dimension(17, 23), int indexOfRowInSprite = 1, 
        String fileSpriteName = SPRITE_HAZARDS_AND_INTERACTABLES_PATH, int lastFrame = 1);
    HazardsAndInteractables& operator = (const HazardsAndInteractables& hazardsAndInteractables);
};