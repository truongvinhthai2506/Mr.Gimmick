#include "PassiveCreatures.h"

PassiveCreatures::PassiveCreatures()
{

}

PassiveCreatures::PassiveCreatures(Point point, int gameObjID, int indexOfRowInSprite, Velocity velocity,
	Dimension dimension, String fileSpriteName, int lastFrame, int currentFrame) : UnplayableObj(point, 
	velocity, gameObjID, dimension, fileSpriteName, lastFrame, indexOfRowInSprite, currentFrame)
{
	
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