#include "AnimatedAndImmovableObj.h"

AnimatedAndImmovableObj::AnimatedAndImmovableObj()
{

}

AnimatedAndImmovableObj::AnimatedAndImmovableObj(Point point, int numberOfAnimatedTiles, int gameObjID) 
	: AnimatedObj(point, numberOfAnimatedTiles, gameObjID)
{

}

AnimatedAndImmovableObj::AnimatedAndImmovableObj(Point point, int gameObjID, Dimension dimension, 
	String fileSpriteName, int lastFrame, int indexOfRowInSprite, int currentFrame) : AnimatedObj(point, 
	gameObjID, dimension, fileSpriteName, lastFrame, indexOfRowInSprite, currentFrame)
{

}