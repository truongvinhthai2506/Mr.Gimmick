#include "Bosses.h"

Bosses::Bosses()
{

}

Bosses::Bosses(Point point, int gameObjID, Velocity velocity, int numberOfAnimatedTiles, 
	Dimension dimension, LPCWSTR fileSpriteName) : UnplayableObj(point, numberOfAnimatedTiles, 
	velocity, gameObjID)
{
	Sprite* sprite = new Sprite(dimension, fileSpriteName, 1, 0, 1);
	this->animatedTiles[0] = new AnimatedTile(point, sprite);
	SetDimension();
}

Bosses& Bosses::operator = (const Bosses& bosses)
{
	AnimatedAndMovableObj::operator = (bosses);

	return *this;
}

bool Bosses::Load(D3DXCOLOR transparentColor, DirectXGraphic directXGrphic)
{
	return this->animatedTiles[0]->Load(transparentColor, directXGrphic);
}