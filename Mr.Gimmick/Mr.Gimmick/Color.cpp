#include "Color.h"

D3DXCOLOR Color::GetColor()
{
	return this->color;
}

Color::Color(D3DXCOLOR color)
{
	this->color = color;
}

Color::Color()
{

}