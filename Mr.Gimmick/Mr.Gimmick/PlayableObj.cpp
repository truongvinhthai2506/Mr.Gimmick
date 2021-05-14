#include "PlayableObj.h"

PlayableObj::PlayableObj(const PlayableObj& playableObj) : AnimatedAndMovableObj(playableObj)
{

}

PlayableObj::PlayableObj()
{

}

PlayableObj::PlayableObj(Point point, int numberOfAnimatedTiles, Velocity velocity, int gameObjID) 
	: AnimatedAndMovableObj(point, numberOfAnimatedTiles, velocity, gameObjID)
{

}