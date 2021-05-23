#pragma once

#include "AnimatedObj.h"
#include "Velocity.h"
#include "State.h"

class AnimatedAndMovableObj : public AnimatedObj
{
protected:
	Velocity velocity;
	State* state;
	string direction;
public:
	AnimatedAndMovableObj();
	AnimatedAndMovableObj(Point point, Velocity velocity, int gameObjID, Dimension dimension, 
		String fileSpriteName, int lastFrame, int indexOfRowInSprite, int currentFrame);
	void Copy(const AnimatedAndMovableObj& animatedAndMovableObj);
	AnimatedAndMovableObj(const AnimatedAndMovableObj& animatedAndMovableObj);
	void Clean();
	AnimatedAndMovableObj& operator = (const AnimatedAndMovableObj& animatedAndMovableObj);
	~AnimatedAndMovableObj();
	virtual void Move();
	void SetVelocity(Velocity velocity);
	State* GetState();
	void SetState(State* state);
	virtual void ChangeState(string stateName);
	void SetDirection(string direction = "Left");
	string GetDirection();
	void SetDimension(Dimension dimension);
};