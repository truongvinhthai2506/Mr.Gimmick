#pragma once

#include "InanimatedTile.h"

class TerrainTile : public InanimatedTile
{
public:
    TerrainTile();
    TerrainTile(Point point, Image* image);
};