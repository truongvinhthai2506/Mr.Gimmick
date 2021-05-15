#include "Treasures.h"

Treasures::Treasures()
{

}

Treasures::Treasures(Point point, int gameObjID, int currentFrame, Dimension dimension,
	int numberOfAnimatedTiles, String fileSpriteName) : UsefulObj(point, numberOfAnimatedTiles, 
	gameObjID, currentFrame, dimension, fileSpriteName)
{

}