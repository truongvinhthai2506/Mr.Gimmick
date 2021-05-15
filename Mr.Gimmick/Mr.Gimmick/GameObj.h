#pragma once

#include "TwoDimensionObj.h"
#include "Tile.h"
#include "Color.h"

using namespace std;

class GameObj : public TwoDimensionObj
{
protected:
    int gameObjID;
public:
    GameObj();
    GameObj(Point point, int gameObjectID);
    virtual bool Load(DirectXGraphic directXGraphic, Color transparentColor = Color());
    virtual void Draw(int indexOfRow, bool isRotate, GraphicDevice graphicDevice, Point cameraPoint);
    int GetID();
};