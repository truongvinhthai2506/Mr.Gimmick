#include "HazardsAndInteractables.h"

HazardsAndInteractables::HazardsAndInteractables()
{

}

HazardsAndInteractables::HazardsAndInteractables(Point point, int gameObjID, int currentFrame, 
	Dimension dimension, int numberOfAnimatedTiles, LPCWSTR fileSpriteName) : AnimatedObj(point, 
	numberOfAnimatedTiles, gameObjID)
{
	Sprite* sprite = new Sprite(dimension, fileSpriteName, 1, 0, currentFrame);
	this->animatedTiles[0] = new AnimatedTile(point, sprite);
	SetDimension();
}

HazardsAndInteractables& HazardsAndInteractables::operator = (
	const HazardsAndInteractables& hazardsAndInteractables)
{
	AnimatedObj::operator = (hazardsAndInteractables);

	return *this;
}

bool HazardsAndInteractables::Load(D3DXCOLOR transparentColor, DirectXGraphic directXGrphic)
{
	return this->animatedTiles[0]->Load(transparentColor, directXGrphic);
}