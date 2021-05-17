#include "Enemies.h"

Enemies::Enemies()
{

}

Enemies::Enemies(Point point, int gameObjID, Dimension dimension, int indexOfRowInSprite, 
	Velocity velocity, int numberOfAnimatedTiles, String fileSpriteName, int lastFrame, 
	int currentFrame) : UnplayableObj(point, velocity, gameObjID, dimension, fileSpriteName, lastFrame, 
	indexOfRowInSprite, currentFrame)
{

}