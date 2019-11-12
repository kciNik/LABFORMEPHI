#include "..\Library(loto)\Loto.h"

using namespace Prog3_1;

const char* MENU[]{ "1. Take the number by the keg", "2. Delete taken lines", "3. Array of free numbers", "4. Create random",
 "0. Exit" };
const unsigned menuSZ = sizeof(MENU) / sizeof(MENU[0]);

int main()
{
	int menu = 1, n;
	Loto loto;
	bool flag;
	do {
		flag = true;
		n = GetNum("Enter number of lines between 1 - 10 -> ");
		if (n == -1)
		{
			system("Pause");
			return 0;
		}
		try {
			loto.Set(n);
		}
		catch (std::exception &ex) {
			flag = false;
			std::cout << ex.what() << std::endl;
		}
	} while (!flag);
	loto.randomize();
	std::cout << "Karta: " << std::endl;
	loto.print(std::cout);
	bool work = true;
	do {
		if (menu)
			for (size_t i = 0; i != menuSZ; ++i)
				std::cout << MENU[i] << std::endl;
		menu = GetNum(">>");
		if (menu == -1)
		{
			system("Pause");
			return 0;
		}
		switch (menu)
		{
		case 0:
		{
			work = false;
			break;
		}
		case 1:
		{
			int b;
			do {
				b = GetNum("Enter number of bochonok: ");
				if (b < 1 || b > 90)
					std::cout << "Number if keg mast be between 1 - 90" << std::endl;
				if (b == -1)
				{
					system("Pause");
					return 0;
				}
			} while (b < 1 || b > 90);
			loto.bochonok(loto, b);
			std::cout << "Karta: " << std::endl;
			loto.print(std::cout);
			break;
		}
		case 2:
		{
			loto.delLine(loto);
			std::cout << "Karta: " << std::endl;
			loto.print(std::cout);
			break;
		}
		case 3:
		{
			int freech[100];
			loto.chisla(loto, freech);
			break;
		}
		case 4:
		{
			do {
				flag = true;
				n = GetNum("Enter number of lines between 1 - 10 -> ");
				if (n == -1)
				{
					system("Pause");
					return 0;
				}
				try {
					loto.Set(n);
				}
				catch (std::exception &ex) {
					flag = false;
					std::cout << ex.what() << std::endl;
				}
			} while (!flag);
			loto.randomize();
			std::cout << "Karta: " << std::endl;
			loto.print(std::cout);
		}
		default:
		{
			std::cout << "Enter error, try again" << std::endl;
			break;
		}
		}
		if (menu) {
			std::cout << "Enter 0 to continue, any number to show the menu once again, ctrl+z to leave" << std::endl;
			do {
				std::cout << ">>";
				std::cin.clear();
				std::cin.ignore(255, '\n');
				std::cin >> menu;
				if (std::cin.eof())
					work = false;
				else {
					if (!(std::cin.good()))
						std::cout << "Enter error, try again" << std::endl;
				}
			} while ((work) && !(std::cin.good()));
		}
	} while (work);
	system("Pause");
	return 0;
}