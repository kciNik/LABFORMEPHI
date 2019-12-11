#include "stdafx.h"
#include "Colony.h"

namespace Tuliphus {
	void Colony::Increase()
	{
		salt += salt_in;
		acid += acid_in;
	}

	void Colony::ChangePossibility()
	{
		if (salt >= den.GetSalt(0) && acid >= den.GetAcid(0) && (food - GetEat()) >= den.GetFood(0))
			den.SetPossibility(0, true);
		else den.SetPossibility(0, false);
		if (salt >= den.GetSalt(1) && acid >= den.GetAcid(1) && (food - GetEat()) >= den.GetFood(1))
			den.SetPossibility(1, true);
		else den.SetPossibility(1, false);
		if (salt >= den.GetSalt(2) && acid >= den.GetAcid(2) && (food - GetEat()) >= den.GetFood(2))
			den.SetPossibility(2, true);
		else den.SetPossibility(2, false);
		if (salt >= den.GetSalt(3) && acid >= den.GetAcid(3) && (food - GetEat()) >= den.GetFood(3))
			den.SetPossibility(3, true);
		else den.SetPossibility(3, false);
	}

	int Colony::GetEat()
	{
		return units.size() * 10; // значение
	}

	void Colony::TakeSold(std::vector <Soldier*> spcr)
	{
		units.insert(units.end(), spcr.begin(), spcr.end());
		for (auto i = 0; i < spcr.size(); ++i)
			spcr.pop_back();
	}

	void Colony::Dead(Soldier *sd)
	{
		for (int i = 0; i < units.size(); ++i)
			if (units[i] == sd)
			{
				units.erase(units.begin() + i);
				break;
			}
	}
}

