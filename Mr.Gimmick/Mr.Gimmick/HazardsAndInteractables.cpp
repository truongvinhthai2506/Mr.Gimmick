#include "HazardsAndInteractables.h"

HazardsAndInteractables::HazardsAndInteractables()
{

}

HazardsAndInteractables::HazardsAndInteractables(Point point, int gameObjID, int currentFrame, 
	Dimension dimension, int indexOfRowInSprite, String fileSpriteName, int lastFrame)
	: AnimatedObj(point, gameObjID, dimension, fileSpriteName, lastFrame, indexOfRowInSprite, 
	currentFrame)
{

}

HazardsAndInteractables& HazardsAndInteractables::operator = (
	const HazardsAndInteractables& hazardsAndInteractables)
{
	AnimatedObj::operator = (hazardsAndInteractables);

	return *this;
}