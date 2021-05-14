#pragma once

#include "InanimatedTile.h"

class SceneryTile : public InanimatedTile
{
public:
    SceneryTile();
    SceneryTile(Point point, Image* image);
};