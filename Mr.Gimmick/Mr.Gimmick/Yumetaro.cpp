#include "Yumetaro.h"

Yumetaro::Yumetaro()
{

}

Yumetaro::Yumetaro(int gameObjID, Point point, Velocity velocity, Dimension dimension, 
	String fileSpriteName, int lastFrame, int indexOfRowInSprite, int currentFrame) : PlayableObj(point, 
	velocity, gameObjID, dimension, fileSpriteName, lastFrame, indexOfRowInSprite, currentFrame)
{
	this->numberOfBlinks = this->heightOfJump = this->isJump = 0;
}

Yumetaro::Yumetaro(const Yumetaro& yumetaro) : PlayableObj(yumetaro)
{
	Copy(yumetaro);
}

Yumetaro& Yumetaro::operator = (const Yumetaro& yumetaro)
{
	AnimatedAndMovableObj::operator = (yumetaro);
	Copy(yumetaro);

	return *this;
}

void Yumetaro::Copy(const Yumetaro& yumetaro)
{
	this->numberOfBlinks = yumetaro.numberOfBlinks;
	this->heightOfJump = yumetaro.heightOfJump;
	this->isJump = yumetaro.isJump;
}

bool Yumetaro::Load(DirectXGraphic directXGraphic, Color transparentColor)
{
	return AnimatedObj::Load(directXGraphic, transparentColor);
}

void Yumetaro::Animate()
{
	string stateName = this->state->GetType();
	int currentFrame;
	bool isChangeFrame = stateName != "SlideState";

	this->animatedTiles[0]->Animate(isChangeFrame);
	currentFrame = this->animatedTiles[0]->GetCurrentFrame();

	if (stateName == "DizzyState")
	{
		Dimension newDimension(23.8, 24.4);

		if (currentFrame >= 5 || currentFrame == 1)
		{
			if (currentFrame == 1)
			{
				newDimension.SetFirstValue(21.8);
			}
			else if (currentFrame == 6)
			{
				newDimension.SetFirstValue(24.4);
			}
			else if (currentFrame == 7)
			{
				newDimension.SetFirstValue(24.8);
			}
			else if (currentFrame == 8)
			{
				newDimension.SetFirstValue(24.6);
			}
			else if (currentFrame == 9)
			{
				newDimension.SetFirstValue(24.66);
			}
			else if (currentFrame == 10)
			{
				newDimension.SetFirstValue(24.18);
			}
			else if (currentFrame == 11)
			{
				newDimension.SetFirstValue(23.73);
			}

			this->animatedTiles[0]->SetDimension(newDimension);
		}
	}
}

void Yumetaro::Blink()
{
	int animationDelay = 0;

	if (this->animatedTiles[0]->GetCurrentFrame() == 1)
	{
		if (this->numberOfBlinks == 0)
		{
			animationDelay = 100;
		}
	}
	else
	{
		animationDelay = 0;
		this->numberOfBlinks = ++this->numberOfBlinks % 2;
	}

	this->animatedTiles[0]->SetAnimationDelay(animationDelay);
}

void Yumetaro::ChangeAnimation(int lastFrame, int indexOfRowInSprite, Dimension dimension, 
	int currentFrame)
{
	this->animatedTiles[0]->SetLastFrame(lastFrame);
	this->animatedTiles[0]->SetIndexOfRowInSprite(indexOfRowInSprite);
	SetDimension(dimension);
	this->animatedTiles[0]->SetCurrentFrame(currentFrame);
}

void Yumetaro::ChangeState(string stateName)
{
	AnimatedAndMovableObj::ChangeState(stateName);
	this->numberOfBlinks = 0;

	if (stateName == "IdleState")
	{
		ChangeAnimation(2, 1, Dimension(20, 22.8));
	}
	else if (stateName == "RunState")
	{
		ChangeAnimation(6, 2);
	}
	else if (stateName == "FlyState")
	{
		ChangeAnimation(1, 3, Dimension(19.4, 23.4));
	}
	else if (stateName == "SlideState")
	{
		ChangeAnimation(2, 3, Dimension(19.4, 23.4), 2);
	}
	else if (stateName == "DizzyState")
	{
		this->point.IncreaseSecondValue(4.6);
		this->animatedTiles[0]->IncreaseSecondValueOfPoint(4.6);
		ChangeAnimation(11, 4, Dimension(21.8, 24.4));
	}

	this->animatedTiles[0]->SetAnimationDelay(0);
}

void Yumetaro::Update(bool isMoveToLeft, bool isMoveToRight, bool isFly, bool isFall)
{
	float vX = YUMETARO_VELOCITY_X;
	float vY = YUMETARO_VELOCITY_Y;
	string stateName = this->state->GetType();
	bool flag = isMoveToLeft || isMoveToRight || isFly;

	if (isMoveToLeft)
	{
		vX = -vX;
		this->direction = "Left";
	}

	if (isMoveToRight)
	{
		this->direction = "Right";
	}

	if (flag || isFall)
	{
		if (!isFly && isFall && (isMoveToLeft || isMoveToRight))
		{
			this->velocity = Velocity(vX, 0);
		}
		else if (!isMoveToLeft && !isMoveToRight)
		{
			if (isFall && this->heightOfJump > MIN_YUMETARO_HEIGHT_OF_JUMP)
			{
				vY = -vY;
				this->isJump = 0;
				this->heightOfJump += vY;
				this->velocity = Velocity(0, vY);

				if (this->heightOfJump == 0)
				{
					isFall = 0;
				}
			}

			if ((this->isJump && this->heightOfJump < MIN_YUMETARO_HEIGHT_OF_JUMP && !isFly) || isFly)
			{
				this->isJump = 1;
				this->heightOfJump += vY;
				this->velocity = Velocity(0, vY);

				if (this->heightOfJump >= MAX_YUMETARO_HEIGHT_OF_JUMP)
				{
					isFly = 0;
				}
			}
		}

		if ((this->heightOfJump <= MAX_YUMETARO_HEIGHT_OF_JUMP || isFall) &&
			this->state->GetType() != "IdleState")
		{
			Move();
		}

		if (stateName != "RunState" && (isMoveToLeft || isMoveToRight) && !isFly)
		{
			ChangeState("RunState");
		}
		else if (stateName != "FlyState" && isFly)
		{
			ChangeState("FlyState");
		}
	}
	
	if (!flag && this->heightOfJump == 0 && stateName != "IdleState")
	{
		ChangeState("IdleState");
	}

	if (this->state->GetType() == "IdleState")
	{
		Blink();
	}

	Animate();
}