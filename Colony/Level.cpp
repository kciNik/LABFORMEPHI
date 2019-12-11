#include "stdafx.h"
#include <ctime>
#include "Level.h"

namespace Tuliphus {
	Level::Level()
	{
		srand(time(0));// õç
		SZX = 25;
		SZY = 25;
		field = new Cell*[SZX];
		for(int i = 0; i < SZX; ++i)
			field[i] = new Cell[SZY];
	}

	void Level::ChangeAccessory(Resource_Point *rp, int acc)
	{

	}

	void Level::SetSZX(int n)
	{
		if (n < 0)
			throw std::exception();
		SZX = n;
	}

	void Level::SetSZY(int n)
	{
		if (n < 0)
			throw std::exception();
		SZY = n;
	}
	void Level::MoveSld(int x1, int y1, int x2, int y2)
	{
		if(field[x1][y1].shere == nullptr)
			throw std::exception();
		if(field[x2][y2].shere != nullptr)
			throw std::exception();
		if(field[x2][y2].den != nullptr)
			throw std::exception();
		field[x2][y2].shere = field[x1][y1].shere;
		field[x1][y1].shere = nullptr;
	}
}
