#include "GameObj.h"

GameObj::GameObj()
{
    this->gameObjID = 0;
}

GameObj::GameObj(Point point, int gameObjID) : TwoDimensionObj(point)
{
    this->gameObjID = gameObjID;
}

bool GameObj::Load(DirectXGraphic directXGraphic, Color transparentColor)
{
    return 0;
}

void GameObj::Draw(int indexOfRow, bool isRotate, GraphicDevice graphicDevice, Point cameraPoint)
{

}

int GameObj::GetID()
{
    return this->gameObjID;
}