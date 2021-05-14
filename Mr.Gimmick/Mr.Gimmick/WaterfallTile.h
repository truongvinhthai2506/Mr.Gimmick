#pragma once

#include "WaterTile.h"

class WaterfallTile : public WaterTile
{
public:
    WaterfallTile();
    WaterfallTile(Point point, Sprite* sprite);
    Tile* Clone();
    string GetType();
};