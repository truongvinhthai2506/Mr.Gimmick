#pragma once

#include "AnimatedObj.h"
#include "Velocity.h"
#include "IdleState.h"

class AnimatedAndMovableObj : public AnimatedObj
{
protected:
	Velocity velocity;
	State* state;
public:
	AnimatedAndMovableObj();
	AnimatedAndMovableObj(Point point, int numberOfAnimatedTiles, Velocity velocity, int gameObjID);
	void Copy(const AnimatedAndMovableObj& animatedAndMovableObj);
	AnimatedAndMovableObj(const AnimatedAndMovableObj& animatedAndMovableObj);
	void Clean();
	AnimatedAndMovableObj& operator = (const AnimatedAndMovableObj& animatedAndMovableObj);
	~AnimatedAndMovableObj();
	virtual void Move(Dimension screenDimension);
	void SetVelocity(Velocity velocity);
	void SetState(State* state);
};