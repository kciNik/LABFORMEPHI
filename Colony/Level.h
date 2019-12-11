#include<iostream>
#include<map>
#include"Colony.h"
#include"Resource_Point.h"

#ifndef _Level_h_
#define _Level_h_

namespace Tuliphus {
	struct Cell {
		bool type;
		Den *den = nullptr;
		Soldier *shere = nullptr;
		Resource_Point *rphere = nullptr;
	};

	class Level {
	private:
		int SZX;
		int SZY;
		std::vector <Colony*> spcolony;
		std::map <Resource_Point*, int> tabrp;
		Cell **field;
	public:
		Level();
		~Level() {
			for (int i = 0; i < SZX; ++i)
				delete[] field[i];
			delete[] field;
		}
		int GetSZX() { return SZX; }
		int GetSZY() { return SZY; }
		void ChangeAccessory(Resource_Point*, int);
		void SetSZX(int);
		void SetSZY(int);
		void MoveSld(int, int, int, int);
	};
}
#endif