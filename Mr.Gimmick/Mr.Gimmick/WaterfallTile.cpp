#include "WaterfallTile.h"

WaterfallTile::WaterfallTile()
{

}

WaterfallTile::WaterfallTile(Point point, Sprite* sprite) : WaterTile(point, sprite)
{

}

Tile* WaterfallTile::Clone()
{
	return new WaterfallTile(*this);
}

string WaterfallTile::GetType()
{
	return "WaterfallTile";
}