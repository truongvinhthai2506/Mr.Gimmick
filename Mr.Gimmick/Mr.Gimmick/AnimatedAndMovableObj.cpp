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

void AnimatedAndMovableObj::Move()
{
	float x = this->point.GetFirstValue();
	float y = this->point.GetSecondValue();
	x += this->velocity.GetFirstValue();
	y += this->velocity.GetSecondValue();
	//float vX = this->velocity.GetFirstValue();
	//y += -vX * vX / 27 + vX * 16 / 3;
	Point newPoint(x, y);
	this->point = newPoint;
	this->animatedTiles[0]->SetPoint(newPoint);
}

void AnimatedAndMovableObj::SetVelocity(Velocity velocity)
{
	this->velocity.SetValue(velocity);
}

State* AnimatedAndMovableObj::GetState()
{
	return this->state;
}

void AnimatedAndMovableObj::SetState(State* state)
{
	this->state = state;
}

void AnimatedAndMovableObj::ChangeState(string stateName)
{
	this->state->ChangeState(stateName, this->state);
}

void AnimatedAndMovableObj::SetDirection(string direction)
{
	this->direction = direction;
}

string AnimatedAndMovableObj::GetDirection()
{
	return this->direction;
}

void AnimatedAndMovableObj::SetDimension(Dimension dimension)
{
	TwoDimensionObj::SetDimension(dimension);
	this->animatedTiles[0]->SetDimension(dimension);
}