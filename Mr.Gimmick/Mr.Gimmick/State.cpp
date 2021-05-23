#include "State.h"

void SetState(string stateName, State*& state)
{
	if (stateName == "IdleState")
	{
		state = new IdleState();
	}
	else if (stateName == "RunState")
	{
		state = new RunState();
	}
	else if (stateName == "FlyState")
	{
		state = new FlyState();
	}
	else if (stateName == "DizzyState")
	{
		state = new DizzyState();
	}
	else if (stateName == "SlideState")
	{
		state = new SlideState();
	}
	else if (stateName == "DieState")
	{
		state = new DieState();
	}
}

bool State::IsAllowChangeState(string stateName)
{
	return 1;
}

void State::ChangeState(string stateName, State*& state)
{
	if (IsAllowChangeState(stateName))
	{
		SetState(stateName, state);
	}
	else
	{
		state = NULL;
	}
}

bool IdleState::IsAllowChangeState(string stateName)
{
	return stateName != "SlideState";
}

State* IdleState::Clone()
{
	return new IdleState(*this);
}

string IdleState::GetType()
{
	return "IdleState";
}

State* RunState::Clone()
{
	return new RunState(*this);
}

string RunState::GetType()
{
	return "RunState";
}

State* FlyState::Clone()
{
	return new FlyState(*this);
}

string FlyState::GetType()
{
	return "FlyState";
}

bool DizzyState::IsAllowChangeState(string stateName)
{
	return stateName != "DieState";
}

State* DizzyState::Clone()
{
	return new DizzyState(*this);
}

string DizzyState::GetType()
{
	return "DizzyState";
}

bool DieState::IsAllowChangeState(string stateName)
{
	return 0;
}

State* DieState::Clone()
{
	return new DieState(*this);
}

string DieState::GetType()
{
	return "DieState";
}

bool SlideState::IsAllowChangeState(string stateName)
{
	return stateName == "RunState" || stateName == "FlyState";
}

State* SlideState::Clone()
{
	return new SlideState(*this);
}

string SlideState::GetType()
{
	return "SlideState";
}

bool AttackState::IsAllowChangeState(string stateName)
{
	return stateName == "IdleState" || stateName == "RunState" || stateName == "FlyState";
}

State* AttackState::Clone()
{
	return new AttackState(*this);
}

string AttackState::GetType()
{
	return "AttackState";
}