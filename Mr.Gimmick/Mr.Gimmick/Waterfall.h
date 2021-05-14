#pragma once

#include "UselessObj.h"

class Waterfall : public UselessObj
{
public:
    Waterfall();
    Waterfall(Point point, int numberOfAnimatedTiles, int gameObjID);
    string GetType();
    UselessObj* Clone();
};