#ifndef _LOTO_H_
#define _LOTO_H_
#include"stdafx.h"
#include<Windows.h>
#include<ctime>
#include <iostream>

namespace Prog3_1 {

	inline void Color(int text, int bg) {
		HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hStdOut, (WORD)((bg << 4) | text));
	}

	struct Point {
		int num;
		bool zan;
	};

	struct Line {
		int col;
		bool active;
		static const int SZ = 9;
		Point *l;
	};

	int GetNum(const char* msg);

	class Loto {
	private:
		static const int Quota = 3;
		int SZL;
		int b;
		Line *ar;
	public:
		Loto() :SZL(Quota) {
			srand(time(0));
			ar = new Line[SZL];
			for (int i = 0; i < SZL; ++i)
				ar[i].l = new Point[ar[i].SZ];
			for (int i = 0; i < SZL; ++i)
				for (int j = 0; j < ar[i].SZ; ++j)
				{
					ar[i].l[j].num = 0;
					ar[i].l[j].zan = false;
				}
		}
		Loto(int n) :SZL(n) {
			ar = new Line[SZL];
			for (int i = 0; i < SZL; ++i)
				ar[i].l = new Point[ar[i].SZ];
			srand(time(0));
			if (n < 1)
				throw std::exception("invalid value");
			for (int i = 0; i < SZL; ++i)
				for (int j = 0; j < ar[i].SZ; ++j)
				{
					ar[i].l[j].num = 0;
					ar[i].l[j].zan = false;
				}
		}
		Loto(const Loto&);
		Loto(Loto&&);
		void Set(int);
		int randomize();
		int bochonok(Loto &);
		int chisla(int *);
		int operator ()(int, int, int);
		const Loto operator --(int);
		Loto &operator =(const Loto &);
		Loto &operator =(Loto &&);
		//Loto & operator +=(const Loto &);
		//Loto & operator [](Loto &);
		friend std::istream & operator >> (std::istream &, Loto &);
		friend std::ostream & operator << (std::ostream &, const Loto &);

		int getCOL(int i) const { return ar[i].col; }
		int getELEM(int i, int j) const { return ar[i].l[j].num; }
		int getNZELEM(int i) const { 
			int k;
			for (int j = 0; j < ar[i].SZ; ++j)
				if (ar[i].l[j].num != 0)
				{
					k = ar[i].l[j].num;
					break;
				}
			return k; 
		}
		int getI(int k) const {
			int i, j;
			for (i = 0; i < SZL; ++i)
				for (j = 0; j < ar[i].SZ; ++j)
					if (k == ar[i].l[j].num)
						return i;
		}
		int getJ(int k, int i) const {
			int j;
			for (j = 0; j < ar[i].SZ; ++j)
				if (k == ar[i].l[j].num)
					return j;
		}
		bool getZAN(int i, int j) const { return ar[i].l[j].zan; }
		bool getACT(int i) const { return ar[i].active; }
		int getSZL() const { return SZL; }

		~Loto() { 
			if (ar != nullptr)
			{
				for (int i = 0; i < SZL; ++i)
					if (ar[i].l != nullptr)
					delete[] ar[i].l;
				delete[] ar;
			}
			std::cout << "Memory deleted" << std::endl;
		}
	};
}
#endif