#include "pch.h"
#include "..\Library(loto)\Loto.h"

using namespace Prog3_1;

TEST(LotoConst, TestEXC) {
	Loto l;
	ASSERT_ANY_THROW(Loto loto(100));
	ASSERT_ANY_THROW(l.Set(12)); 
}

TEST(LotoConst, TestMethods) {
	Loto l(3);
	ASSERT_EQ(1, l.randomize());
	ASSERT_EQ(2, l.bochonok(l, 12));
	ASSERT_EQ(0, l.delLine(l));
	int ar[15];
	ASSERT_EQ(1, l.chisla(l, ar));
}

TEST(LotoConst, ZeroConst) {
	Loto l;
	ASSERT_EQ(2, l.bochonok(l, 12));
	ASSERT_EQ(nullptr, l);
}
