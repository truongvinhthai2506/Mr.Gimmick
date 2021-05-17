#pragma once

#include "TwoDimensionObj.h"
#include "Tile.h"
#include "Color.h"
#include "LevelOne.h"

using namespace std;

class GameObj : public TwoDimensionObj
{
protected:
    int gameObjID;
public:
    GameObj();
    GameObj(Point point, int gameObjectID);
    virtual bool Load(DirectXGraphic directXGraphic, Color transparentColor = Color());
    virtual void Draw(GraphicDevice graphicDevice, Point cameraPoint, bool isRotate = 0);
    int GetID();
};