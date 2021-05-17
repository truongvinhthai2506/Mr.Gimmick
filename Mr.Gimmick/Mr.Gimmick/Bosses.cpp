#include "Bosses.h"

Bosses::Bosses()
{

}

Bosses::Bosses(Point point, int gameObjID, Velocity velocity, int numberOfAnimatedTiles, 
	Dimension dimension, String fileSpriteName, int lastFrame, int indexOfRowInSprite, int currentFrame) 
	: UnplayableObj(point, velocity, gameObjID, dimension, fileSpriteName, lastFrame, indexOfRowInSprite, 
	currentFrame)
{

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