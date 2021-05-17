#include "Treasures.h"

Treasures::Treasures()
{

}

Treasures::Treasures(Point point, int gameObjID, int currentFrame, Dimension dimension, 
	String fileSpriteName, int lastFrame, int indexOfRowInSprite) : UsefulObj(point, gameObjID, dimension, 
	fileSpriteName, lastFrame, indexOfRowInSprite, currentFrame)
{

}