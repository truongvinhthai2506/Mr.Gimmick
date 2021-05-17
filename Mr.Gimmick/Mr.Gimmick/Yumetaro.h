#pragma once

#include "PlayableObj.h"
#include "TransformHandler.h"

#pragma region Definition
#define YUMETARO_START_X 16 * 4
#define YUMETARO_START_Y 16 * 22 - 3.4

#define YUMETARO_VELOCITY_X 6
#define YUMETARO_VELOCITY_Y 0

#define YUMETARO_WIDTH 19.4f
#define YUMETARO_HEIGHT 23.0f

#define YUMETARO_BACKGROUND_COLOR Color(D3DCOLOR_XRGB(0, 0, 255))

#define SPRITE_YUMETARO_PATH L"../../Resource/Image/Yumetaro.png"
#pragma endregion

class Yumetaro : public PlayableObj
{
public:
    Yumetaro();
    Yumetaro(int gameObjID, Point point = Point(YUMETARO_START_X, YUMETARO_START_Y), Velocity velocity =
        Velocity(YUMETARO_VELOCITY_X, YUMETARO_VELOCITY_Y), Dimension dimension = 
        Dimension(YUMETARO_WIDTH, YUMETARO_HEIGHT), String fileSpriteName = SPRITE_YUMETARO_PATH, 
        int lastFrame = 6, int indexOfRowInSprite = 2, int currentFrame = 1);
    Yumetaro(const Yumetaro& yumetaro);
    Yumetaro& operator = (const Yumetaro& yumetaro);
    bool Load(DirectXGraphic directXGraphic, Color transparentColor = YUMETARO_BACKGROUND_COLOR);
    void Move(Dimension dimension);
    void Animate();
};