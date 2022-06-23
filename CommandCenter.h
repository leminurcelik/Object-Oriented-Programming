#include <iostream>
#include "Robot.h"
using namespace std;
class Crew{
	friend class CommandCenter;
	private:
		int maxExplorers;
		int maxMiners;
		static int crewManufactureCost;
		static float crewMaintenanceCost;
		int explorerCrewSize;
		int minerCrewSize;
		Explorer **ExplorerCrew;
		Miner **MinerCrew;
		
	public:
		Crew(int, int, int, int);
		int getExplorerCrewSize(){return explorerCrewSize;};
		int getMinerCrewSize(){return minerCrewSize;};
		Explorer** getExplorers();
		Miner** getMiners();
		void setCrewMaintenanceCost(float crew_maintenance_cost){crewMaintenanceCost = crew_maintenance_cost;};
		float getCrewMaintenanceCost(){return crewMaintenanceCost;};
		void setCrewManufactureCost(int crew_manufacture_cost){crewManufactureCost = crew_manufacture_cost;};
		int getCrewManufactureCost(){return crewManufactureCost;};
		Robot* manufactureRobot();
		void initMovement();
		void updateDurability();
		void operator+=(const Robot*);
		void operator-=(string);
		void showInfo();
		~Crew();
};

class CommandCenter{
	private:
		int neededSelenium = 0;
		float searchArea = 0.0;
		int seleniumWorth = 0;
		int turnCount;
		static float totalCrewMaintenanceCost;
		float profit;
	public:
		CommandCenter(int, int, int);
		bool isGameEnded();
		void calculateProfit(Crew);
		void operator++();
		void showInfo() const;
};



