#pragma once

#include <d3dx9.h>
#include "Handler.h"
#include "Point.h"

#pragma region Definition
#define SCALE 3
#pragma endregion

class TransformHandler : public Handler
{
public:
	D3DXMATRIX* GetScaleMatrix(Pair scale = Pair(SCALE, SCALE));
	const D3DXMATRIX* GetTransformMatrix(Point cameraPoint);
	D3DXVECTOR3 GetPositionAfterTransform(Point positionInWorld, Point cameraPoint);
};