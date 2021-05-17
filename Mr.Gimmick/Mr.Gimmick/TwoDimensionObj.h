#pragma once

#include <d3dx9.h>
#include "Point.h"
#include "Image.h"
#include "Box.h"

class TwoDimensionObj
{
protected:
	Point point;
	Dimension dimension;
public:
	void SetFirstValueOfPoint(int firstValueOfPoint);
	void SetSecondValueOfPoint(int secondValueOfPoint);
	void SetFirstValueOfDimension(int firstValueOfDimension);
	void IncreaseValueOfPoint(Pair value);
	void IncreaseSecondValueOfPoint(int additionalSecondValue);
	void IncreaseFirstValueOfPoint(int additionalFirstValue);
	TwoDimensionObj();
	TwoDimensionObj(Point point);
	Point GetPoint();
	void SetPoint(Point point);
	Dimension GetDimension();
	Box GetBox();
	void SetDimension(Dimension dimension);
};