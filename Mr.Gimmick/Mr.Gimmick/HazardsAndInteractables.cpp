#include "HazardsAndInteractables.h"

HazardsAndInteractables::HazardsAndInteractables()
{

}

HazardsAndInteractables::HazardsAndInteractables(Point point, int gameObjID, int currentFrame, 
	Dimension dimension, int numberOfAnimatedTiles, String fileSpriteName) : AnimatedObj(point, 
	numberOfAnimatedTiles, gameObjID)
{
	AddAnimatedTile(dimension, fileSpriteName, 1, currentFrame);
}

HazardsAndInteractables& HazardsAndInteractables::operator = (
	const HazardsAndInteractables& hazardsAndInteractables)
{
	AnimatedObj::operator = (hazardsAndInteractables);

	return *this;
}