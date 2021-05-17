#include "UsefulObj.h"

UsefulObj::UsefulObj()
{

}

UsefulObj::UsefulObj(Point point, int gameObjID, Dimension dimension, String fileSpriteName, 
	int lastFrame, int indexOfRowInSprite, int currentFrame) : AnimatedAndImmovableObj(point, gameObjID, 
	dimension, fileSpriteName, lastFrame, indexOfRowInSprite, currentFrame)
{

}