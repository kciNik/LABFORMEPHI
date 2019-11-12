#include"stdafx.h"
#include <cstdlib>
#include"Loto.h"

namespace Prog3_1 {
	std::ostream & Loto::print(std::ostream &s) const
	{
		if (top == 0)
			s << "Stack is empty";
		else
			for (int i = 0; i < top; ++i)
			{ 
				if (ar[i].active)
					for (int j = 0; j < ar[i].SZ; ++j)
					{
						if (ar[i].l[j].zan)
							Color(4, 0);
						else Color(7, 0);
						if (ar[i].l[j].num != 0 && ar[i].l[j].num < 10)
							s << "0" << ar[i].l[j].num << " ";
						else if (ar[i].l[j].num >= 10)
							s << ar[i].l[j].num << " ";
						else
							s << "   ";
					}
					s << std::endl;
			}
		s << std::endl;
		return s;
	}

	void Loto::Set(int n)
	{
		if (n < 1 || n > 10)
			throw std::exception("invalid value");
		top = n;
	}

	int Loto::randomize() {
		for (int i = 0; i < top; ++i)
			for (int j = 0; j < ar[i].SZ; ++j)
			{
				ar[i].l[j].num = 0;
				ar[i].l[j].zan = false;
			}
		for (int i = 0; i < top; ++i)
		{
			ar[i].col = 0;
			int j;
			while (ar[i].col < 5)
			{
				j = 0 + rand() % 9;
				if (ar[i].l[j].num == 0)
				{
					ar[i].l[j].num = (j * 10) + rand() % 9;
					if (ar[i].l[j].num != 0)
						ar[i].col++;
					ar[i].l[j].zan = false;
				}
			}
		}
		return 1;
	}

	int GetNum(const char* msg) {
		int n;
		const char* errmsg = "";
		do {
			std::cout << errmsg << std::endl;
			std::cout << msg;
			std::cin >> n;
			if (std::cin.eof())
				return -1;
			if (!(std::cin.good())) {
				errmsg = "Invalid value, try again\n";
				std::cin.clear();
				std::cin.ignore(255, '\n');
				continue;
			}
			else return n;
		} while (true);
	}

	int Loto::bochonok(Loto &k, int b) {
		int c = b / 10;
		int count = 0;
		for (int i = 0; i < k.top; ++i)
			if (k.ar[i].l[c].num == b && !k.ar[i].l[c].zan)
			{
				k.ar[i].l[c].zan = true;
				std::cout << "Success" << std::endl;
				count++;
			}
		if (count == 0)
		{
			std::cout << "No number or is it busy" << std::endl;
			return 2;
		}
		return 1;
	}

	int Loto::delLine(Loto &k) {
		int count, czan;
		for (int i = 0; i < k.top; ++i)
		{
			count = 0; czan = 0;
			for (int j = 0; j < k.ar[i].SZ; ++j)
			{
				if (k.ar[i].l[j].zan)
					czan++;
			}
			if (czan == 5)
			{
				count++;
				k.ar[i].active = false;
			}
		}
		if (count > 0)
		{
			std::cout << "There are " << count << " busy line" << std::endl;
			return 1;
		}
		else
		{
			std::cout << "There are " << count << " busy line" << std::endl;
			return 0;
		}
	}

	int Loto::chisla(Loto &k, int *arr) {
		int c = 0;
		for (int i = 0; i < k.top; ++i)
		{
			for (int j = 0; j < k.ar[i].SZ; ++j)
			{
				int count = 0;
				if ((k.ar[i].l[j].num != 0) && (!k.ar[i].l[j].zan))
				{
					for (int m = 0; m < c; ++m)
						if (arr[m] == k.ar[i].l[j].num)
							count++;
					if (count == 0)
					{
						arr[c] = k.ar[i].l[j].num;
						c++;
					}
				}
			}
		}
		for (int m = 0; m < c; ++m)
			std::cout << arr[m] << " ";
		std::cout << std::endl;
		return 1;
	}
}