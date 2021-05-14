#include "Enemies.h"

Enemies::Enemies()
{

}

Enemies::Enemies(Point point, int gameObjID, Velocity velocity, int numberOfAnimatedTiles, 
	Dimension dimension, LPCWSTR fileSpriteName) : UnplayableObj(point, numberOfAnimatedTiles, 
	velocity, gameObjID)
{
	Sprite* sprite = new Sprite(dimension, fileSpriteName, 1, 0, 1);
	this->animatedTiles[0] = new AnimatedTile(point, sprite);
	SetDimension();
}

Enemies& Enemies::operator = (const Enemies& enemies)
{
	AnimatedAndMovableObj::operator = (enemies);

	return *this;
}

bool Enemies::Load(D3DXCOLOR transparentColor, DirectXGraphic directXGrphic)
{
	return this->animatedTiles[0]->Load(transparentColor, directXGrphic);
}