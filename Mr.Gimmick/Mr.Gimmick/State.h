#pragma once

#include <iostream>

using namespace std;

class State
{
public:
	virtual bool IsAllowChangeState(string stateName);
	virtual State* Clone() = 0;
	void ChangeState(string stateName, State*& state);
	virtual string GetType() = 0;
};

class IdleState : public State
{
public:
	bool IsAllowChangeState(string stateName);
	State* Clone();
	string GetType();
};

class RunState : public State
{
public:
	State* Clone();
	string GetType();
};

class FlyState : public State
{
public:
	State* Clone();
	string GetType();
};

class DizzyState : public State
{
public:
	bool IsAllowChangeState(string stateName);
	State* Clone();
	string GetType();
};

class DieState : public State
{
public:
	bool IsAllowChangeState(string stateName);
	State* Clone();
	string GetType();
};

class SlideState : public State
{
public:
	bool IsAllowChangeState(string stateName);
	State* Clone();
	string GetType();
};

class AttackState : public State
{
public:
	bool IsAllowChangeState(string stateName);
	State* Clone();
	string GetType();
};