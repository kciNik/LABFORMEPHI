#ifndef _Soldier_h_
#define _Soldier_h_
#include<iostream>
#include <ctime>
#include"Resource_Point.h"

namespace Tuliphus {
	enum States
	{
		stay = 0,
		go,
		clean,
		take,
		damage,
		damadetoden
	};

	class Den;

	class Soldier {
	protected:
		int MAXHP;
		int accessory;
		int HP;
		int dodge;
		States status;
	public:
		virtual int GetMAXHP() const { return MAXHP; }
		virtual int GetHP() const { return HP; }
		virtual int GetAccessory() const { return accessory; }
		virtual double GetChance() const { return dodge; }
		virtual int GetStatus() const { return status; }
		//virtual void SetMAXHP(int n);
		virtual void SetHP(int);
		//virtual void SetChance(double n);
		virtual void SetStatus(States) = 0;
		Soldier() : MAXHP(100), HP(MAXHP), dodge(2), status(stay) {}
		~Soldier() {}
	};

	class Defoult_Soldier: public Soldier  {
	private:
		int dmg;
		double take_over;
	public:
		int GetDamage() const { return dmg; }
		double GetTakeOver() const { return take_over; }
		//void TakeOver(Resource_Point *);
		void GiveDamage(Soldier*);
		virtual void SetStatus(States);
		Defoult_Soldier() : dmg(35), take_over(0.2) {
			srand(time(0));//  написать для всех типов или в уровне?
		}
		~Defoult_Soldier() {}
	};

	class Cleaner : public Soldier {
	private:
		double take_over;
		double clean_up;
	public:
		double GetCleanUp() const { return clean_up; }
		double GetTakeOver() const { return take_over; }
		virtual void SetStatus(States);
		Cleaner() : take_over(0.3), clean_up(0.3) {}
		~Cleaner() {}
	};

	class Hunter : public Soldier {
	private:
		int dmg;
	public:
		int GetDamage() const { return dmg; }
		void GiveDamage(Soldier*);
		virtual void SetStatus(States);
		Hunter() : dmg(50) {}
		~Hunter() {}
	};

	class Assault : public Soldier {
	private:
		int dmg;
		int den_dmg;
	public:
		int GetDamage() const { return dmg; }
		int GetDenDamage() const { return den_dmg; }
		void GiveDamage(Soldier*);
		void GiveDamageToDen(Den*);
		virtual void SetStatus(States);
		Assault() : dmg(40), den_dmg(100) {}
		~Assault() {}
	};
}
#endif
