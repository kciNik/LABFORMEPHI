#include "stdafx.h"
#include "Resource_Point.h"


namespace Tuliphus {
	void Resource_Point::SetPop(int n)
	{
		if (n < 0)
			throw std::exception();
		population = n;
	}

	void Resource_Point::CleanUp()
	{
		if (GetPop() <= 0)
			throw std::exception();
		if ((GetPop() - maxpopulation * 0.2) < 0)
			population = 0;
		else 
			population -= maxpopulation * 0.2; //коэф
	}

	void Resource_Point::Settlement()
	{
		if (GetPop() >= 100)
			throw std::exception();
		if ((GetPop() + maxpopulation * 0.2) > 100)
			population = 100;
		else
			population += maxpopulation * 0.2; //коэф
	}
}
