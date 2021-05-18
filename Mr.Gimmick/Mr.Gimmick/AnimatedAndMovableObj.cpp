#include "AnimatedAndMovableObj.h"

AnimatedAndMovableObj::AnimatedAndMovableObj()
{
	this->state = NULL;
}

AnimatedAndMovableObj::AnimatedAndMovableObj(Point point, Velocity velocity, int gameObjID, 
	Dimension dimension, String fileSpriteName, int lastFrame, int indexOfRowInSprite, int currentFrame) 
	: AnimatedObj(point, gameObjID, dimension, fileSpriteName, lastFrame, indexOfRowInSprite, 
	currentFrame)
{
	this->velocity = velocity;
	this->state = new IdleState();
	this->direction = "Right";
}

void AnimatedAndMovableObj::Copy(const AnimatedAndMovableObj& animatedAndMovableObj)
{
	this->velocity = animatedAndMovableObj.velocity;
	this->state = animatedAndMovableObj.state->Clone();
	this->direction = animatedAndMovableObj.direction;
}

AnimatedAndMovableObj::AnimatedAndMovableObj(const AnimatedAndMovableObj& animatedAndMovableObj) : 
	AnimatedObj(animatedAndMovableObj)
{
	Copy(animatedAndMovableObj);
}

void AnimatedAndMovableObj::Clean()
{
	delete this->state;
}

AnimatedAndMovableObj& AnimatedAndMovableObj::operator = (
	const AnimatedAndMovableObj& animatedAndMovableObj)
{
	AnimatedObj::operator = (animatedAndMovableObj);

	if (this != &animatedAndMovableObj)
	{
		Clean();
		Copy(animatedAndMovableObj);
	}

	return *this;
}

AnimatedAndMovableObj::~AnimatedAndMovableObj()
{
	Clean();
}

void AnimatedAndMovableObj::Move(Dimension screenDimension)
{
	float x = this->point.GetFirstValue() + this->velocity.GetFirstValue();
	float y = this->point.GetSecondValue() + this->velocity.GetSecondValue();
	Point newPoint(x, y);
	this->point.SetValue(newPoint);
	
	for (int i = 0; i < this->numberOfAnimatedTiles; i++)
	{
		this->animatedTiles[i]->SetPoint(newPoint);
	}
}

void AnimatedAndMovableObj::SetVelocity(Velocity velocity)
{
	this->velocity.SetValue(velocity);
}

void AnimatedAndMovableObj::SetState(State* state)
{
	this->state = state;
}

void AnimatedAndMovableObj::SetDirection(string direction)
{
	this->direction = direction;
}

string AnimatedAndMovableObj::GetDirection()
{
	return this->direction;
}