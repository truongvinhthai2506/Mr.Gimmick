#include "Enemies.h"

Enemies::Enemies()
{

}

Enemies::Enemies(Point point, int gameObjID, Dimension dimension, Velocity velocity, 
	int numberOfAnimatedTiles, String fileSpriteName) : UnplayableObj(point, numberOfAnimatedTiles, 
	velocity, gameObjID)
{
	AddAnimatedTile(dimension, fileSpriteName, 1);
}