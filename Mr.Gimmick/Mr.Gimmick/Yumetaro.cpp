#include "Yumetaro.h"

Yumetaro::Yumetaro()
{

}

Yumetaro::Yumetaro(int gameObjID, Point point, Velocity velocity, int numberOfAnimatedTiles,
	Dimension dimension, String fileSpriteName) : PlayableObj(point, numberOfAnimatedTiles, velocity, 
	gameObjID)
{
	AddAnimatedTile(dimension, fileSpriteName, 6);
}

Yumetaro::Yumetaro(const Yumetaro& yumetaro) : PlayableObj(yumetaro)
{

}

Yumetaro& Yumetaro::operator = (const Yumetaro& yumetaro)
{
	AnimatedAndMovableObj::operator = (yumetaro);

	return *this;
}

bool Yumetaro::Load(DirectXGraphic directXGraphic, Color transparentColor)
{
	return AnimatedObj::Load(directXGraphic, transparentColor);
}

void Yumetaro::Move(Dimension dimension)
{
	Dimension spriteDimension = this->animatedTiles[0]->GetSprite()->GetDimension();
	float lim[2];
	float scale = SCALE;
	lim[0] = dimension.GetFirstValue() - spriteDimension.GetFirstValue() * scale;
	lim[1] = dimension.GetSecondValue() - spriteDimension.GetSecondValue() * scale;

	float x = this->point.GetFirstValue();
	float y = this->point.GetSecondValue();
	bool flags[4];
	flags[0] = x <= lim[0];
	flags[1] = x >= 0;
	flags[2] = y <= lim[1];
	flags[3] = y >= 0;

	float vX = this->velocity.GetFirstValue();
	float vY = this->velocity.GetSecondValue();

	//if ((flags[0] && flags[1] && flags[2] && flags[3]) || (!flags[0] && vX <= 0) || 
	//	(!flags[1] && vY >= 0) || (!flags[2] && vY <= 0) || (!flags[3] && vY >= 0))
	{
		AnimatedAndMovableObj::Move(dimension);
	}

	if (!flags[0])
	{
		//this->point.SetFirstValue(lim[0]);
	}

	if (!flags[1])
	{
		//this->point.SetFirstValue(0);
	}

	if (!flags[2])
	{
		//this->point.SetSecondValue(lim[1]);
	}

	if (!flags[3])
	{
		//this->point.SetSecondValue(0);
	}
}

void Yumetaro::Animate()
{
	this->animatedTiles[0]->Animate();
}