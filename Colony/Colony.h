#ifndef _Colony_h_
#define _Colony_h_
#include"Soldier.h"
#include"Den.h"
#include <vector>

namespace Tuliphus {
	class Colony {
	private:
		int number;
		Den den;
		std::vector <Soldier*> units;
		int food;
		int salt;
		int salt_in;
		int acid;
		int acid_in;
	public:
		void ChangePossibility();
		int GetEat();
		void Increase();
		void TakeSold(std::vector <Soldier*>);
		void Dead(Soldier*);
		Colony() : den(), food(50), salt(10), acid(15), acid_in(0), salt_in(0) {
			Soldier *ptr;
			for (int i = 0; i < 3; ++i)
			{
				ptr = new Defoult_Soldier;
				units.push_back(ptr);
			}
		}
		~Colony() {}
	};
}
#endif
