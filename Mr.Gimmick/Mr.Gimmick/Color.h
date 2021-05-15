#pragma once

#include <d3dx9.h>

class Color
{
private:
	D3DXCOLOR color;
public:
	D3DXCOLOR GetColor();
	Color(D3DXCOLOR color);
	Color();
};