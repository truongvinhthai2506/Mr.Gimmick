#include "Waterfall.h"

Waterfall::Waterfall()
{

}

Waterfall::Waterfall(Point point, int numberOfAnimatedTiles, int gameObjID) : UselessObj(point, 
	numberOfAnimatedTiles, gameObjID)
{

}

string Waterfall::GetType()
{
	return "Waterfall";
}

UselessObj* Waterfall::Clone()
{
	return new Waterfall(*this);
}