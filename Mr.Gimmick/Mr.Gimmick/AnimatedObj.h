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
	void AddAnimatedTile(Dimension dimension, String fileSpriteName, int lastFrame, 
		int indexOfRowInSprite, int currentFrame);
	AnimatedObj();
	AnimatedObj(Point point, int numberOfAnimatedTiles, int gameObjID);
	AnimatedObj(Point point, int gameObjID, Dimension dimension, String fileSpriteName, int lastFrame, 
		int indexOfRowInSprite, int currentFrame);
	AnimatedObj(const AnimatedObj& animatedObj);
	~AnimatedObj();
	void Init(int numberOfAnimatedTile);
	void SetDimension();
	void Copy(const AnimatedObj& animatedObj);
	void Clean();
	AnimatedObj& operator = (const AnimatedObj& animatedObj);
	void Draw(GraphicDevice graphicDevice, Point cameraPoint, bool isRotate = 0);
	void SetElement(int index, AnimatedTile* animatedTile);
	virtual bool Load(DirectXGraphic directXGraphic, Color transparentColor = Color());
};