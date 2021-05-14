#include "UnplayableObj.h"

UnplayableObj::UnplayableObj()
{

}

UnplayableObj::UnplayableObj(Point point, int numberOfAnimatedTiles, Velocity velocity, 
	int gameObjID) : AnimatedAndMovableObj(point, numberOfAnimatedTiles, velocity, gameObjID)
{

}