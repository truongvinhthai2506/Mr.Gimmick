#pragma once

#include "PlayableObj.h"
#include "TransformHandler.h"

#pragma region Definition
#define YUMETARO_START_X 16 * 5
#define YUMETARO_START_Y 16 * 22 - 4.4

#define YUMETARO_VELOCITY_X 6
#define YUMETARO_VELOCITY_Y 8

#define YUMETARO_WIDTH 20
#define YUMETARO_HEIGHT 22.8

#define YUMETARO_BACKGROUND_COLOR Color(D3DCOLOR_XRGB(0, 0, 255))

#define SPRITE_YUMETARO_PATH L"../../Resource/Image/Yumetaro_and_bullets.png"

#define MIN_YUMETARO_HEIGHT_OF_JUMP 18
#define MAX_YUMETARO_HEIGHT_OF_JUMP 60
#pragma endregion

class Yumetaro : public PlayableObj
{
private:
    int numberOfBlinks;
    float heightOfJump;
    bool isJump;
public:
    Yumetaro();
    Yumetaro(int gameObjID, Point point = Point(YUMETARO_START_X, YUMETARO_START_Y), Velocity velocity =
        Velocity(YUMETARO_VELOCITY_X, YUMETARO_VELOCITY_Y), Dimension dimension = 
        Dimension(YUMETARO_WIDTH, YUMETARO_HEIGHT), String fileSpriteName = SPRITE_YUMETARO_PATH, 
        int lastFrame = 2, int indexOfRowInSprite = 1, int currentFrame = 1);
    Yumetaro(const Yumetaro& yumetaro);
    Yumetaro& operator = (const Yumetaro& yumetaro);
    void Copy(const Yumetaro& yumetaro);
    bool Load(DirectXGraphic directXGraphic, Color transparentColor = YUMETARO_BACKGROUND_COLOR);
    void Animate();
    void Blink();
    void ChangeAnimation(int lastFrame, int indexOfRowInSprite, Dimension dimension = 
        Dimension(19.4, 22.8), int currentFrame = 0);
    void ChangeState(string stateName);
    void Update(bool isMoveToLeft, bool isMoveToRight, bool isFly, bool isFall);
};