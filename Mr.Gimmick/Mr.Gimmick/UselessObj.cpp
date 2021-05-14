#include "UselessObj.h"

UselessObj::UselessObj()
{

}

UselessObj::UselessObj(Point point, int numberOfAnimatedTiles, int gameObjID) 
	: AnimatedAndImmovableObj(point, numberOfAnimatedTiles, gameObjID)
{

}

void UselessObj::Synchronize()
{
	int max = 0, numberOfDrawings;

	for (int i = 0; i < this->numberOfAnimatedTiles; i++)
	{
		numberOfDrawings = this->animatedTiles[i]->GetNumberOfDrawings();

		if (numberOfDrawings > max)
		{
			max = numberOfDrawings;
		}
	}

	for (int i = 0; i < this->numberOfAnimatedTiles; i++)
	{
		this->animatedTiles[i]->SetNumberOfDrawings(max);
	}
}