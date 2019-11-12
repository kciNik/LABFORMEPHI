#include<ctime>
#include <fstream>
#include "..\LibLotoGame\Loto.h"

using namespace Prog3_1;

int main()
{
	clock_t times;
	int n;
	n = GetNum("Enter the number of lines in your Loto card: ");
	Loto loto(n);
	loto.randomize();
	std::cout << "Your card: " << std::endl << loto << std::endl;
	std::cout << "Rules: " << std::endl << "You have a Lotto card on which the numbers are located." << std::endl << "The computer will give you a random number." << std::endl << "Your task as quickly as possible to enter this number, if it is in your card, if not, enter 0." << std::endl << "If you enter a number incorrectly, you are given a new number." << std::endl << "When you complete the entire field, the game will end and your result will be recorded in a file. The faster the better!" << std::endl << "If you are ready, press ENTER" << std::endl;
	system("Pause");
	system("cls");
	std::cout << "Let's get fucking started!!!" << std::endl;
	times = clock();
	Point *arr;
	arr = new Point[n * 5];
	int col;
	col = loto.chisla(arr);
	int sch = 1;
	srand(time(0));
	int count = 0;
	while (sch == 1)
	{
		if ((0 + rand() % 10) <= 5)
		{ 
			int i;
			do {
				i = 0 + rand() % col;
			} while (arr[i].zan);
			std::cout << "Card" << std::endl << loto << std::endl << std::endl;
			std::cout << "Number: " << arr[i].num << std::endl << std::endl;
			sch = loto.bochonok(loto, arr, arr[i].num, count, col);
			system("cls");
		}
		else {
			int i = 0 + rand() % 90;
			std::cout << "Card" << std::endl << loto << std::endl << std::endl;
			std::cout << "Number: " << i << std::endl << std::endl;
			sch = loto.bochonok(loto, arr, i, count, col);
			system("cls");
		}
	}
	times = clock() - times;
	double t = times;
	delete[] arr;
	std::cout << "Your time: " << (double)times / CLOCKS_PER_SEC << " sec" << std::endl;
	std::ofstream to("res.txt", std::ios::app);
	if (!to) {
		std::cerr << "can't open output file\n";
		system("Pause");
		return 0;
	}
	to << t / CLOCKS_PER_SEC << " sec" << std::endl;
	to.close();
	system("Pause");
	return 0;
}