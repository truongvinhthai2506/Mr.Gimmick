#pragma once

#include "AnimatedTile.h"

class FlagTile : public AnimatedTile
{
public:
    FlagTile();
    FlagTile(Point point, Sprite* sprite);
};