#include "ItemsAndHUD.h"

ItemsAndHUD::ItemsAndHUD()
{

}

ItemsAndHUD::ItemsAndHUD(Point point, int gameObjID, int currentFrame, Dimension dimension,
	int numberOfAnimatedTiles, LPCWSTR fileSpriteName) : UsefulObj(point, numberOfAnimatedTiles, 
	gameObjID)
{
	Sprite* sprite = new Sprite(dimension, fileSpriteName, 1, 0, currentFrame);
	this->animatedTiles[0] = new AnimatedTile(point, sprite);
	SetDimension();
}

ItemsAndHUD& ItemsAndHUD::operator = (const ItemsAndHUD& itemsAndHUD)
{
	AnimatedObj::operator = (itemsAndHUD);

	return *this;
}

bool ItemsAndHUD::Load(D3DXCOLOR transparentColor, DirectXGraphic directXGrphic)
{
	return this->animatedTiles[0]->Load(transparentColor, directXGrphic);
}