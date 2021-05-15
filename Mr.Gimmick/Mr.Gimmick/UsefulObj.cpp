#include "UsefulObj.h"

UsefulObj::UsefulObj()
{

}

UsefulObj::UsefulObj(Point point, int numberOfAnimatedTiles, int gameObjID, int currentFrame, 
	Dimension dimension, String fileSpriteName) : AnimatedAndImmovableObj(point, numberOfAnimatedTiles, 
	gameObjID)
{
	AddAnimatedTile(dimension, fileSpriteName, 1, currentFrame);
}