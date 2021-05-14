#pragma once

class Pair
{
protected:
	float firstValue, secondValue;
public:
	void IncreaseValue(Pair additionalValue);
	void IncreaseSecondValue(int additionalSecondValue);
	void IncreaseFirstValue(int addtionalFirstValue);
	Pair();
	Pair(float firstValue, float secondValue);
	float GetFirstValue();
	float GetSecondValue();
	void SetFirstValue(float firstValue);
	void SetSecondValue(float secondValue);
	void SetValue(Pair value);
};