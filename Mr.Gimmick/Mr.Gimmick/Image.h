#pragma once

#include <d3d9.h>
#include "Dimension.h"

class Image
{
protected:
	Dimension dimension;
	LPCWSTR filename;
public:
	Image();
	Image(Dimension dimension, LPCWSTR filename);
	Dimension GetDimension();
	void SetDimension(Dimension dimension);
	LPCWSTR GetFilename();
};