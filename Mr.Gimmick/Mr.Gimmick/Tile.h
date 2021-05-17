#pragma once

#include <iostream>
#include "TwoDimensionObj.h"
#include "DirectXGraphic.h"

using namespace std;

class Tile : public TwoDimensionObj
{
public:
	Tile();
	Tile(Point point);
	virtual bool Load(D3DXCOLOR transparentColor, DirectXGraphic directXGraphic);
	virtual void Draw(GraphicDevice graphicDevice, Point cameraPoint, bool isRotate = 0, 
		LPDIRECT3DSURFACE9 backbuffer = NULL) = 0;
	virtual Tile* Clone() = 0;
	virtual string GetType() = 0;
};