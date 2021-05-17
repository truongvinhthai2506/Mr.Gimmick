#pragma once

#include <d3d9.h>
#include "Tile.h"
#include "DirectXGraphic.h"
#include "TransformHandler.h"

class InanimatedTile : public Tile
{
protected:
	Image* image;
	LPDIRECT3DSURFACE9 surface;
public:
	InanimatedTile();
	InanimatedTile(Point point, Image* image);
	~InanimatedTile();
	void Draw(GraphicDevice graphicDevice, Point cameraPoint, bool isRotate = 0, 
		LPDIRECT3DSURFACE9 backbuffer = NULL);
	bool Load(D3DXCOLOR transparentColor, DirectXGraphic directXGraphic);
	Tile* Clone();
	string GetType();
};