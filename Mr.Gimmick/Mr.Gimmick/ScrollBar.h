#pragma once

#include "UselessObj.h"

class ScrollBar : public UselessObj
{
public:
    ScrollBar();
    ScrollBar(Point point, int numberOfAnimatedTiles, int gameObjID);
    string GetType();
    UselessObj* Clone();
};