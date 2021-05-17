#include "GameObj.h"

GameObj::GameObj()
{
    this->gameObjID = 0;
}

GameObj::GameObj(Point point, int gameObjID) : TwoDimensionObj(point)
{
    this->gameObjID = gameObjID;
    this->point.SetSecondValue(MAP_LEVEL_ONE_HEIGHT - this->point.GetSecondValue());
}

bool GameObj::Load(DirectXGraphic directXGraphic, Color transparentColor)
{
    return 0;
}

void GameObj::Draw(GraphicDevice graphicDevice, Point cameraPoint, bool isRotate)
{

}

int GameObj::GetID()
{
    return this->gameObjID;
}