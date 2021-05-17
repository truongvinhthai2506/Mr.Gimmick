#include "AnimatedObj.h"

void AnimatedObj::AddAnimatedTile(Dimension dimension, String fileSpriteName, int lastFrame, 
	int indexOfRowInSprite, int currentFrame)
{
	Sprite* sprite = new Sprite(dimension, fileSpriteName, lastFrame, 0, currentFrame);
	this->animatedTiles[0] = new AnimatedTile(this->point, sprite, indexOfRowInSprite);
	SetDimension();
}

AnimatedObj::AnimatedObj()
{
	this->numberOfAnimatedTiles = 0;
	this->animatedTiles = NULL;
}

AnimatedObj::AnimatedObj(Point point, int numberOfAnimatedTiles, int gameObjID) : GameObj(point, 
	gameObjID)
{
	Init(numberOfAnimatedTiles);
}

AnimatedObj::AnimatedObj(Point point, int gameObjID, Dimension dimension, String fileSpriteName, 
	int lastFrame, int indexOfRowInSprite, int currentFrame) : GameObj(point, gameObjID)
{
	Init(1);
	AddAnimatedTile(dimension, fileSpriteName, lastFrame, indexOfRowInSprite, currentFrame);
}

void AnimatedObj::SetDimension()
{
	Dimension tileDimension;
	tileDimension = this->animatedTiles[0]->GetDimension();
	this->dimension = Dimension(tileDimension.GetFirstValue() * numberOfAnimatedTiles,
		tileDimension.GetSecondValue());
}

void AnimatedObj::Copy(const AnimatedObj& animatedObj)
{
	this->point = animatedObj.point;
	this->numberOfAnimatedTiles = animatedObj.numberOfAnimatedTiles;
	this->animatedTiles = new AnimatedTile*[animatedObj.numberOfAnimatedTiles];
	this->dimension = animatedObj.dimension;
	this->gameObjID = animatedObj.gameObjID;

	for (int i = 0; i < animatedObj.numberOfAnimatedTiles; i++)
	{
		this->animatedTiles[i] = (AnimatedTile*)animatedObj.animatedTiles[i]->Clone();
	}
}

AnimatedObj::AnimatedObj(const AnimatedObj& animatedObj)
{
	Copy(animatedObj);
}

void AnimatedObj::Clean()
{
	for (int i = 0; i < this->numberOfAnimatedTiles; i++)
	{
		delete this->animatedTiles[i];
	}

	delete[] this->animatedTiles;
}

AnimatedObj& AnimatedObj::operator = (const AnimatedObj& animatedObj)
{
	if (this != &animatedObj)
	{
		Clean();
		Copy(animatedObj);
	}

	return *this;
}

AnimatedObj::~AnimatedObj()
{
	Clean();
}

void AnimatedObj::Init(int numberOfAnimatedTiles)
{
	this->numberOfAnimatedTiles = numberOfAnimatedTiles;
	this->animatedTiles = new AnimatedTile*[numberOfAnimatedTiles];
}

void AnimatedObj::Draw(GraphicDevice graphicDevice, Point cameraPoint, bool isRotate)
{
	for (int i = 0; i < this->numberOfAnimatedTiles; i++)
	{
		this->animatedTiles[i]->Draw(graphicDevice, cameraPoint, isRotate);
	}
}

void AnimatedObj::SetElement(int index, AnimatedTile* animatedTile)
{
	this->animatedTiles[index] = animatedTile;
}

bool AnimatedObj::Load(DirectXGraphic directXGraphic, Color transparentColor)
{
	bool flag;

	for (int i = 0; i < this->numberOfAnimatedTiles; i++)
	{
		flag = this->animatedTiles[i]->Load(transparentColor.GetColor(), directXGraphic);
	}

	return flag;
}