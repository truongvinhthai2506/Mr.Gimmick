#include "PassiveCreatures.h"

PassiveCreatures::PassiveCreatures()
{

}

PassiveCreatures::PassiveCreatures(Point point, int gameObjID, Velocity velocity, 
	int numberOfAnimatedTiles, Dimension dimension, LPCWSTR fileSpriteName) : UnplayableObj(point, 
	numberOfAnimatedTiles, velocity, gameObjID)
{
	Sprite* sprite = new Sprite(dimension, fileSpriteName, 1, 0, 1);
	this->animatedTiles[0] = new AnimatedTile(point, sprite); 
	SetDimension();
}

PassiveCreatures& PassiveCreatures::operator = (const PassiveCreatures& enemies)
{
	AnimatedAndMovableObj::operator = (enemies);

	return *this;
}

bool PassiveCreatures::Load(D3DXCOLOR transparentColor, DirectXGraphic directXGrphic)
{
	return this->animatedTiles[0]->Load(transparentColor, directXGrphic);
}