#pragma once

#include "UnplayableObj.h"

#pragma region Definition
#define BOSSES_BACKGROUND_COLOR D3DCOLOR_XRGB(0, 0, 255)

#define SPRITE_BOSSES_PATH L"../../Resource/Image/Bosses.png"
#pragma endregion

class Bosses : public UnplayableObj
{
public:
    Bosses();
    Bosses(Point point, int gameObjID, Velocity velocity = Velocity(2, 0), int numberOfAnimatedTiles = 1,
        Dimension dimension = Dimension(40, 50), LPCWSTR fileSpriteName = SPRITE_BOSSES_PATH);
    Bosses& operator = (const Bosses& bosses);
    bool Load(D3DXCOLOR transparentColor, DirectXGraphic directXGrphic);
};