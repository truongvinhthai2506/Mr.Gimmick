#include "ScrollBarTile.h"

ScrollBarTile::ScrollBarTile()
{

}

ScrollBarTile::ScrollBarTile(Point point, Sprite* sprite) :  AnimatedTile(point, sprite)
{

}

Tile* ScrollBarTile::Clone()
{
	return new ScrollBarTile(*this);
}

string ScrollBarTile::GetType()
{
	return "ScrollBarTile";
}