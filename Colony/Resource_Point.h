#ifndef _Resource_Point_h_
#define _Resource_Point_h_
#include<iostream>
#include<string>

namespace Tuliphus {
	enum TypeOfPoints {
		food = 1,
		salt,
		acid
	};

	class Resource_Point {
	private:
		std::string name[80];
		TypeOfPoints type;
		int profit;
		int population;
		int maxpopulation;
	public:
		int GetMaxpop() const { return maxpopulation; }
		int GetPop() const { return population; }
		int GetProfit() const { return profit; }
		void SetPop(int);
		void CleanUp();
		void Settlement();
		Resource_Point(TypeOfPoints n) : type(n), population(0), maxpopulation(100) {
			type = n;
			switch (type)
			{
			case 1:
			{
				profit = 20;
				break;
			}
			case 2:
			{
				profit = 5;
				break;
			}
			case 3:
			{
				profit = 7;
				break;
			}
			default:
				break;
			}
		}
		~Resource_Point() {}
	};
}
#endif

