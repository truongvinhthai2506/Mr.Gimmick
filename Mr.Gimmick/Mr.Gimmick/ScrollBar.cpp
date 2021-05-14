#include "ScrollBar.h"

ScrollBar::ScrollBar()
{

}

ScrollBar::ScrollBar(Point point, int numberOfAnimatedTiles, int gameObjID) : UselessObj(point, 
	numberOfAnimatedTiles, gameObjID)
{

}

string ScrollBar::GetType()
{
	return "ScrollBar";
}

UselessObj* ScrollBar::Clone()
{
	return new ScrollBar(*this);
}