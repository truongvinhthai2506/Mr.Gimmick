#include "GameObj.h"

GameObj::GameObj()
{
    this->gameObjID = 0;
}

GameObj::GameObj(Point point, int gameObjID) : TwoDimensionObj(point)
{
    this->gameObjID = gameObjID;
}

int GameObj::GetID()
{
    return this->gameObjID;
}