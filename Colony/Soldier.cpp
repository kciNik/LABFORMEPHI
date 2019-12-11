#include "stdafx.h"
#include "Soldier.h"
#include"Den.h"

namespace Tuliphus {
	void Defoult_Soldier::GiveDamage(Soldier *sd)
	{
		if (sd->GetHP() <= 0)
			throw std::exception();
		if ((sd->GetHP() - dmg) < 0)
			sd->SetHP(0);
		//if ((1 + rand() % 10) > 3)
			sd->SetHP(sd->GetHP() - dmg);
	}

	void Defoult_Soldier::SetStatus(States n)
	{
		if (n == 2 || n == 5 || n < 0 || n > 5)
			throw std::exception();
		status = n;
	}

	void Hunter::GiveDamage(Soldier *sd)
	{
		if (sd->GetHP() <= 0)
			throw std::exception();
		if ((sd->GetHP() - dmg) < 0)
			sd->SetHP(0);
		//if ((rand() % 11) < 3)
			sd->SetHP(sd->GetHP() - dmg);
	}

	void Hunter::SetStatus(States n)
	{
		if (n == 2 || n == 3 || n == 5 || n < 0 || n > 5)
			throw std::exception();
		status = n;
	}

	void Assault::GiveDamage(Soldier *sd)
	{
		if (sd->GetHP() <= 0)
			throw std::exception();
		if ((sd->GetHP() - dmg) < 0)
			sd->SetHP(0);
		//if ((rand() % 11) < 3)
			sd->SetHP(sd->GetHP() - dmg);
	}

	void Assault::GiveDamageToDen(Den *den)
	{
		if (den->GetHP() <= 0)
			throw std::exception();
		den->SetHP(den->GetHP() - den_dmg);
	}

	void Assault::SetStatus(States n)
	{
		if (n == 2 || n == 3 || n < 0 || n > 5)
			throw std::exception();
		status = n;
	}

	void Soldier::SetHP(int hp)
	{
		if (hp < 0)
			throw std::exception();
			HP = hp;
	}

	void Cleaner::SetStatus(States n)
	{
		if (n < 0 || n > 3)
			throw std::exception();
		status = n;
	}
}
