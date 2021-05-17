#include "PlayableObj.h"

PlayableObj::PlayableObj(const PlayableObj& playableObj) : AnimatedAndMovableObj(playableObj)
{

}

PlayableObj::PlayableObj()
{

}

PlayableObj::PlayableObj(Point point, Velocity velocity, int gameObjID, Dimension dimension, 
	String fileSpriteName, int lastFrame, int indexOfRowInSprite, int currentFrame) 
	: AnimatedAndMovableObj(point, velocity, gameObjID, dimension, fileSpriteName, lastFrame, 
	indexOfRowInSprite, currentFrame)
{

}