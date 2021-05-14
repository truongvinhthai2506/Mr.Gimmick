#include "WaterTile.h"

WaterTile::WaterTile()
{

}

WaterTile::WaterTile(Point point, Sprite* sprite) : AnimatedTile(point, sprite)
{

}

Tile* WaterTile::Clone()
{
	return new WaterTile(*this);
}

string WaterTile::GetType()
{
	return "WaterTile";
}