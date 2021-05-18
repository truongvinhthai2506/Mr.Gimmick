#include "InanimatedTile.h"

InanimatedTile::InanimatedTile()
{

}

InanimatedTile::InanimatedTile(Point point, Image* image) : Tile(point)
{
	this->dimension = image->GetDimension();
	this->image = image;
}

InanimatedTile::~InanimatedTile()
{
	if (this->surface != NULL)
	{
		this->surface->Release();
	}

	delete this->image;
}

void InanimatedTile::Draw(GraphicDevice graphicDevice, Point cameraPoint, bool isRotate, 
	LPDIRECT3DSURFACE9 backbuffer)
{
	RECT destinationRectangle;
	float scale = SCALE;
	float x = (this->point.GetFirstValue() - cameraPoint.GetFirstValue()) * scale;
	float y = (-this->point.GetSecondValue() + cameraPoint.GetSecondValue()) * scale;
	Dimension dimension = this->image->GetDimension();
	float width = dimension.GetFirstValue();
	float height = dimension.GetSecondValue();

	if (x != (int)x)
	{
		if (x < 0)
		{
			x = (int)x - 1;
		}
		else
		{
			x = (int)x;
		}
	}

	// Set the surface's rectangle for drawing
	destinationRectangle.left = x;
	destinationRectangle.top = y;
	destinationRectangle.right = x + width;
	destinationRectangle.bottom = y + height;

	RECT sourceRectangle;
	sourceRectangle.left = 0;
	sourceRectangle.top = 0;
	sourceRectangle.right = 16;
	sourceRectangle.bottom = 16;

	if (destinationRectangle.left < 0)
	{
		destinationRectangle.left = 0;
		sourceRectangle.left -= x / scale;
	}

	if (destinationRectangle.right > 768)
	{
		destinationRectangle.right = 768;
		sourceRectangle.right -= (x + width - 768) / scale;
	}

	// Draw the surface
	graphicDevice.DrawSurface(this->surface, backbuffer, &sourceRectangle, &destinationRectangle);
}

bool InanimatedTile::Load(D3DXCOLOR transparentColor, DirectXGraphic directXGraphic)
{
	this->surface = directXGraphic.LoadSurface(this->image->GetFilename(), transparentColor);

	if (this->surface == NULL)
	{
		return 0;
	}

	return 1;
}

Tile* InanimatedTile::Clone()
{
	return new InanimatedTile(*this);
}

string InanimatedTile::GetType()
{
	return "InanimatedTile";
}