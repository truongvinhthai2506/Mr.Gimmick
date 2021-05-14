#pragma once

#include "AnimatedTile.h"

class ScrollBarTile : public AnimatedTile
{
public:
    ScrollBarTile();
    ScrollBarTile(Point point, Sprite* sprite);
    Tile* Clone();
    string GetType();
};