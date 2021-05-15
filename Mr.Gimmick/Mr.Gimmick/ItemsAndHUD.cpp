#include "ItemsAndHUD.h"

ItemsAndHUD::ItemsAndHUD()
{

}

ItemsAndHUD::ItemsAndHUD(Point point, int gameObjID, int currentFrame, Dimension dimension,
	int numberOfAnimatedTiles, String fileSpriteName) : UsefulObj(point, numberOfAnimatedTiles, 
	gameObjID, currentFrame, dimension, fileSpriteName)
{

}