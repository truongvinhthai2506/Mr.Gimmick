#include "UnplayableObj.h"

UnplayableObj::UnplayableObj()
{

}

UnplayableObj::UnplayableObj(Point point, Velocity velocity, int gameObjID, Dimension dimension, 
	String fileSpriteName, int lastFrame, int indexOfRowInSprite, int currentFrame) 
	: AnimatedAndMovableObj(point, velocity, gameObjID, dimension, fileSpriteName, lastFrame, 
	indexOfRowInSprite, currentFrame)
{

}