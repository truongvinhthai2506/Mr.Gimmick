#pragma once

#include "AnimatedObj.h"
#include "Velocity.h"
#include "IdleState.h"

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
	virtual void Move(Dimension screenDimension);
	void SetVelocity(Velocity velocity);
	void SetState(State* state);
	void SetDirection(string direction = "Left");
	string GetDirection();
};