#include "Treasures.h"

Treasures::Treasures()
{

}

Treasures::Treasures(Point point, int gameObjID, int currentFrame, Dimension dimension,
	int numberOfAnimatedTiles, LPCWSTR fileSpriteName) : UsefulObj(point, numberOfAnimatedTiles, 
	gameObjID)
{
	Sprite* sprite = new Sprite(dimension, fileSpriteName, 1, 0, currentFrame);
	this->animatedTiles[0] = new AnimatedTile(point, sprite);
	SetDimension();
}

Treasures& Treasures::operator = (const Treasures& itemsAndHUD)
{
	AnimatedObj::operator = (itemsAndHUD);

	return *this;
}

bool Treasures::Load(D3DXCOLOR transparentColor, DirectXGraphic directXGrphic)
{
	return this->animatedTiles[0]->Load(transparentColor, directXGrphic);
}