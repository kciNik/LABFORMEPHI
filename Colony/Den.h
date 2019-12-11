#ifndef _Den_h_
#define _Den_h_
#include<vector>
#include<iostream>
#include<string>
#include"Soldier.h"


namespace Tuliphus {
	enum avalibleUnits
	{
		defoultsold = 1,
		assault,
		cleaner,
		hunter
	};

	struct CanCreate {
		avalibleUnits type;
		int food;
		int time;
		int salt;
		int acid;
		bool canI;
	};

	struct Create {
		avalibleUnits type;
		int time;
		int ntime;
	};

	class Den {
	private:
		int HP;
		CanCreate can[4];
		std::vector <Create> spcr;
	public:
		int GetHP() const { return HP; }
		CanCreate GetCC(int i) const { return can[i]; }
		int GetSalt(int i) const { return can[i].salt; }
		int GetAcid(int i) const { return can[i].acid; }
		int GetFood(int i) const { return can[i].food; }
		int GetSizeOfVec() const { return spcr.size(); }
		bool GetPossibility(int i) const { return can[i].canI; }
		void SetPossibility(int, bool);
		void SetHP(int);
		void create(avalibleUnits, int);
		void Grows();
		//void TakeDmg(int);
		std::vector <Soldier*> HappyBirthday();
		Den() : HP(1000) {
			can[0] = { defoultsold, 20, 4, 5, 3, 0};
			can[1] = { assault, 20, 5, 6, 3, 0 };
			can[2] = { cleaner, 20, 3, 4, 3, 0 };
			can[3] = { hunter, 20, 6, 6, 4, 0 };
		}
		~Den() {}
	};
}
#endif

