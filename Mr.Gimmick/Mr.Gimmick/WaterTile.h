#pragma once

#include "AnimatedTile.h"

class WaterTile : public AnimatedTile
{
public:
    WaterTile();
    WaterTile(Point point, Sprite* sprite);
    Tile* Clone();
    string GetType();
};