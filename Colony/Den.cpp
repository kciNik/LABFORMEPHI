#include "stdafx.h"
#include "Den.h"

namespace Tuliphus {
	void Den::SetPossibility(int i, bool flag)
	{
		if (i < 0 || i > 3)
			std::exception();
		can[i].canI = flag;
	}

	void Den::SetHP(int hp) {
		if (hp < 0)
			throw std::exception();
		HP = hp;
	}

	void Den::create(avalibleUnits type, int i)
	{
		if (!can[i].canI)
			throw std::exception();
		Create c;
		c.ntime = 4;
		c.time = 0;
		c.type = type;
		spcr.push_back(c);
	}

	void Den::Grows()
	{
		for (int i = 0; i < spcr.size(); ++i)
			spcr[i].time++;
	}

	std::vector <Soldier*> Den::HappyBirthday()
	{ 
		std::vector <Soldier*> sld;
		//Soldier *sld1;
		int i, j = 0;
		for (i = 0; i < spcr.size(); ++i)
			if (spcr[i].time == spcr[i].ntime)
			{ 
				switch (spcr[i].type)
				{
				case defoultsold:
					sld[j] = new Defoult_Soldier;
				case assault:
					sld[j] = new Assault;
				case cleaner:
					sld[j] = new Cleaner;
				case hunter:
					sld[j] = new Hunter;
				default:
					break;
				}
				++j;
				spcr.erase(spcr.begin() + i);
			}
		return sld;
	}

	/*void Den::TakeDmg(int n)
	{
		HP -= n;
	}*/
}