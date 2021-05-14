#include "TwoDimensionObj.h"

void TwoDimensionObj::SetFirstValueOfPoint(int firstValueOfPoint)
{
	this->point.SetFirstValue(firstValueOfPoint);
}

void TwoDimensionObj::SetFirstValueOfDimension(int firstValueOfDimension)
{
	this->dimension.SetFirstValue(firstValueOfDimension);
}

void TwoDimensionObj::IncreaseValueOfPoint(Pair value)
{
	this->point.IncreaseValue(value);
}

void TwoDimensionObj::IncreaseSecondValueOfPoint(int additionalSecondValue)
{
	this->point.IncreaseSecondValue(additionalSecondValue);
}

void TwoDimensionObj::IncreaseFirstValueOfPoint(int additionalFirstValue)
{
	this->point.IncreaseFirstValue(additionalFirstValue);
}

TwoDimensionObj::TwoDimensionObj()
{

}

TwoDimensionObj::TwoDimensionObj(Point point)
{
	this->point = point;;
}

Point TwoDimensionObj::GetPoint()
{
	return this->point;
}

void TwoDimensionObj::SetPoint(Point point)
{
	this->point.SetValue(point);
}

Dimension TwoDimensionObj::GetDimension()
{
	return this->dimension;
}

Box TwoDimensionObj::GetBox()
{
	return Box(this->point, this->dimension);
}

void TwoDimensionObj::SetDimension(Dimension dimension)
{
	this->dimension = dimension;
}