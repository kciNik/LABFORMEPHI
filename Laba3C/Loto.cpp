#include"stdafx.h"
#include <cstdlib>
#include"Loto.h"

namespace Prog3_1 {
	Loto::Loto(const Loto &st) :SZL(st.SZL)
	{
		ar = new Line[SZL];
		for (int i = 0; i < SZL; ++i)
		{
			ar[i].l = new Point[ar[i].SZ];
			ar[i] = st.ar[i];
		}
		std::cout << "Copy constructor used" << std::endl;
	}

	Loto::Loto(Loto &&st) : SZL(st.SZL), ar(st.ar)
	{
		for (int i = 0; i < SZL; ++i)
			st.ar[i].l = nullptr;
		st.ar = nullptr;
		std::cout << "Move constructor used" << std::endl;
	}

	Loto & Loto::operator =(const Loto &st)
	{
		if (this != &st) {
			SZL = st.SZL;
			for (int i = 0; i < SZL; ++i)
				delete[] ar[i].l;
			delete[] ar;
			ar = new Line[SZL];
			for (int i = 0; i < SZL; ++i)
			{
				ar[i].l = new Point[ar[i].SZ];
				ar[i] = st.ar[i];
			}
		}
		return *this;
	}

	Loto & Loto::operator =(Loto &&st)
	{
		int tmp;
		tmp = SZL;
		SZL = st.SZL;
		st.SZL = tmp;
		for (int i = 0; i < SZL; ++i)
		{
			Line ptr = ar[i];
			ar[i] = st.ar[i];
			st.ar[i] = ptr;
		}
		return *this;
	}

	std::ostream & operator <<(std::ostream &s, const Loto &k)
	{
		if (k.SZL == 0 || k.ar[0].l[0].num < 0)
			s << "Stack is empty";
		else
			for (int i = 0; i < k.SZL; ++i)
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
		for (int i = 0; i < SZL; ++i)
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

	int Loto::randomize() {
		ar = new Line[SZL];
		for (int i = 0; i < SZL; ++i)
			ar[i].l = new Point[ar[i].SZ];
		for (int i = 0; i < SZL; ++i)
		{
			ar[i].active = true;
			for (int j = 0; j < ar[i].SZ; ++j)
			{
				ar[i].l[j].num = 0;
				ar[i].l[j].zan = false;
			}
		}
		for (int i = 0; i < SZL; ++i)
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

	void Loto::Set(int n)
	{
		if (n < 1)
			throw std::exception("invalid value");
		SZL = n;
	}

	int Loto::bochonok(Loto &k) {
		do {
			try {
				std::cin >> k;
			}
			catch (std::exception &ex) {
				std::cout << ex.what() << std::endl;
			}
			if (b < 1 || b > 90)
				std::cout << "Number of keg mast be between 1 - 90" << std::endl;
			if (k.b == -1)
			{
				return 0;
			}
		} while (b < 1 || b > 90);
		int c = k.b / 10;
		int count = 0;
		for (int i = 0; i < k.SZL; ++i) {
			if (k(i, c, b) == 1)
			{
				std::cout << "Success" << std::endl;
				count++;
			}
		}
		if (count == 0)
			std::cout << "No number or is it busy" << std::endl;
		return 1;
	}

	int Loto::chisla(int *arr) {
		int c = 0;
		for (int i = 0; i < SZL; ++i)
		{
			for (int j = 0; j < ar[i].SZ; ++j)
			{
				int count = 0;
				if ((ar[i].l[j].num != 0) && (!ar[i].l[j].zan))
				{
					for (int m = 0; m < c; ++m)
						if (arr[m] == ar[i].l[j].num)
							count++;
					if (count == 0)
					{
						arr[c] = ar[i].l[j].num;
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

	int Loto::operator ()(int i, int c, int b) {
		if (ar[i].l[c].num == b && !ar[i].l[c].zan)
		{
			ar[i].l[c].zan = true;
			return 1;
		}
		return 0;
	}
}