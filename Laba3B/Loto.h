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
		Point l[SZ];
	};

	int GetNum(const char* msg);

	class Loto {
	private:
		static const int SZL = 10;
		int top;
		int b;
		Line ar[SZL];
	public:
		Loto() :top(0) {}
		Loto(int n) : top(n) {
			srand(time(0));
			if (n < 1 || n > 10)
				throw std::exception("invalid value");
		}
		void Set(int);
		void randomize();
		int bochonok(Loto &);
		void chisla(Loto &, int *);
		int operator ()(Loto &, int, int, int);
		const Loto operator --(int);
		friend std::istream & operator >> (std::istream &,Loto &);
		friend std::ostream & operator <<(std::ostream &, const Loto &);
	};
}
#endif