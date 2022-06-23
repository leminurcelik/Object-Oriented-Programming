//--- 2021-2022 Spring Object Oriented Programming Assignment 2 ---//
//--------------------------//
//---Name & Surname: Leminur Çelik
//---Student Number: 150190085
//--------------------------//
#include <iostream>
#ifndef _H
#define _H
using namespace std;
class Robot {
	friend class Crew;
	private:
		static int unqID;
		string RobotName;
		string RobotType;
		float speed; 
		int durability;
		bool canMove;
		int manufactureCost; 
		float maintenanceCost;
	
	public:
		Robot(string, float, int, int, float);
		string getName() const {return RobotName;};
		string getType() const {return RobotType;};
		void setspeed(float rbt_speed) {speed = rbt_speed;};
		float getspeed() const{return speed;};
		void setdurability(float rbt_durability) {durability = rbt_durability;};
		float getdurability() const{return durability;};
		void setCanMove(bool f){canMove = f;};
		bool getCanMove() const{return canMove;};
		void setManufactureCost(int mnf){manufactureCost = mnf;};
		int getManufactureCost() const {return manufactureCost;};
		void setMaintenanceCost(float mnt){maintenanceCost = mnt;};
		float getMaintenanceCost() const {return maintenanceCost;};
		void operator=(const Robot &);
		void showInfo() const;
		~Robot(){};
}; 

class Explorer : public Robot{
	friend class Miner;
	friend class CommandCenter;
	private:
		static float totalExploredArea;
		static int totalNumberOfSeleniumArea;
		float exploredArea;
		bool detectedSelenium;
		
		
	public:
		Explorer(string, float, int);
		bool move();
		void explore();
		void operator=(const Explorer &attributes);
		void showInfo() const; 
		~Explorer(){};
};

class Miner : public Robot{
	friend class CommandCenter;
	private:
		static int totalGatheredSelenium;
		int gatheredSelenium;

		
	public:
		Miner(string, float, int);
		void mine();
		bool move();
		void operator=(const Miner &attributes);
		void showInfo() const; 
		~Miner(){};
};


#endif