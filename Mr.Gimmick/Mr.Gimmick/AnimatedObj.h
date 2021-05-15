#pragma once

#include "GameObj.h"
#include "AnimatedTile.h"
#include "DataType.h"

class AnimatedObj : public GameObj
{
protected:
	AnimatedTile** animatedTiles;
	int numberOfAnimatedTiles;
public:
	void AddAnimatedTile(Dimension dimension, String fileSpriteName, int lastFrame, int currentFrame = 1, 
		int i = 0);
	AnimatedObj();
	AnimatedObj(Point point, int numberOfAnimatedTiles, int gameObjID);
	AnimatedObj(const AnimatedObj& animatedObj);
	~AnimatedObj();
	void SetDimension();
	void Copy(const AnimatedObj& animatedObj);
	void Clean();
	AnimatedObj& operator = (const AnimatedObj& animatedObj);
	void Draw(int indexOfRow, bool isRotate, GraphicDevice graphicDevice, Point cameraPoint);
	void SetElement(int index, AnimatedTile* animatedTile);
	virtual bool Load(DirectXGraphic directXGraphic, Color transparentColor = Color());
};