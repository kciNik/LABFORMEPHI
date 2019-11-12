#include"stdafx.h"
#include <cstdlib>
#include"Loto.h"

namespace Prog3_1 {
	std::ostream & operator <<(std::ostream &s, const Loto &k)
	{
		if (k.top == 0)
			s << "Stack is empty";
		else
			for (int i = 0; i < k.top; ++i)
			{
				if (k.ar[i].active)
					for (int j = 0; j < k.ar[i].SZ; ++j)
					{
						if (k.ar[i].l[j].zan)
							Color(4, 0);
						else Color(7, 0);
						if (k.ar[i].l[j].num != 0 && k.ar[i].l[j].num < 10)
							s << "0" << k.ar[i].l[j].num << " ";
						else if (k.ar[i].l[j].num >= 10)
							s << k.ar[i].l[j].num << " ";
						else
							s << "   ";
					}
				s << std::endl;
			}
		s << std::endl;
		return s;
	}

	const Loto Loto::operator --(int) {
		Loto k(*this);
		int count = 0, czan = 0;
		for (int i = 0; i < top; ++i)
		{
			int count = 0, czan = 0;
			for (int j = 0; j < ar[i].SZ; ++j)
			{
				if (ar[i].l[j].zan)
					czan++;
			}
			if (czan == 5)
			{
				count++;
				ar[i].active = false;
			}
		}
		std::cout << "There are " << count << " busy line" << std::endl;
		return k;
	}

	std::istream & operator >> (std::istream &s, Loto &k) {
		k.b = GetNum("Enter number of bochonok: ");
		return s;
	}

	void Loto::randomize() {
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

	void Loto::Set(int n)
	{
		if (n < 1 || n > 10)
			throw std::exception("invalid value");
		top = n;
	}

	int Loto::bochonok(Loto &k) {
		do {
			std::cin >> k;
			if (b < 1 || b > 90)
				std::cout << "Number if keg mast be between 1 - 90" << std::endl;
			if (k.b == -1)
			{
				return 0;
			}
		} while (b < 1 || b > 90);
		int c = k.b / 10;
		int count = 0;
		for (int i = 0; i < k.top; ++i) {
			if (k(k, i, c, b) == 1)
			{
				std::cout << "Success" << std::endl;
				count++;
			}
		}
		if (count == 0)
			std::cout << "No number or is it busy" << std::endl;
		return 1;
	}

	void Loto::chisla(Loto &k, int *arr) {
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
	}

	int Loto::operator ()(Loto &k, int i, int c, int b) {
		if (k.ar[i].l[c].num == b && !k.ar[i].l[c].zan)
		{
			k.ar[i].l[c].zan = true;
			return 1;
		}
		return 0;
	}
}