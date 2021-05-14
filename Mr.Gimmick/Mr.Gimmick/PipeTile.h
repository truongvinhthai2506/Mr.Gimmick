#pragma once

#include "InanimatedTile.h"

class PipeTile : public InanimatedTile
{
public:
    PipeTile();
    PipeTile(Point point, Image* image);
};