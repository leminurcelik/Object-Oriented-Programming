//--- 2021-2022 Spring Object Oriented Programming Assignment 2 ---//
//--------------------------//
//---Name & Surname: Leminur Çelik
//---Student Number: 150190085
//--------------------------//

//-------------Do Not Add New Libraries-------------//
//-------------All Libraries Needed Were Given-------------//
//-------------Do Not Add Change Header Include Paths-------------//
#include "CommandCenter.h"
#include "Robot.h"
#include <iostream>
using namespace std;
/*
****************
BEGIN: CREW CLASS FUNCTION DECLARATIONS 
****************
*/
int Crew::crewManufactureCost = 0;
float Crew::crewMaintenanceCost = 0;

Crew::Crew(int crewMaxExplorers, int crewMaxMiners, int explorer_crew_size, int miner_crew_size){
    maxExplorers = crewMaxExplorers;
    maxMiners = crewMaxMiners;
    if(maxExplorers < 1 || maxExplorers > 5)
        maxExplorers = 2;
    if(maxMiners < 1 || maxMiners > 5)
        maxMiners = 2;
    explorerCrewSize = explorer_crew_size;
    minerCrewSize = miner_crew_size;
    if(explorerCrewSize < 0 || explorerCrewSize > maxExplorers)
        explorerCrewSize = maxExplorers;
    if(minerCrewSize < 0 || minerCrewSize > maxMiners)
        minerCrewSize = maxMiners;
    for (int i = 0; i < explorerCrewSize; i++)
    {
        int robot_durability = 1 + rand() % 5;
        float speed_e = 1.5 + static_cast <float> (rand()) / ( static_cast <float> (RAND_MAX/(2.5-1.5)));
        Explorer* exp = new Explorer("explorer", speed_e, robot_durability);
        ExplorerCrew[i] = exp;
        crewManufactureCost = crewManufactureCost + ExplorerCrew[i]->getManufactureCost();
    }
    for (int i = 0; i < minerCrewSize; i++)
    {
        int robot_durability = 1 + rand() % 5;
        float speed_m = 1.0 + static_cast <float> (rand()) / ( static_cast <float> (RAND_MAX/(1.5-1.0)));
        Miner* mnr = new Miner("miner", speed_m, robot_durability);
        MinerCrew[i] = mnr;
        crewManufactureCost = crewManufactureCost + MinerCrew[i]->getManufactureCost();
    }
}
Robot* Crew::manufactureRobot(){
    string robot_type;
    cout << "Type:";
    cin >> robot_type;
    Robot *exp;
    if(robot_type == "explorer" || robot_type == "miner"){
        int robot_durability = 1 + rand() % 5;
        if(robot_type == "explorer"){
            float speed_e = 1.5 + static_cast <float> (rand()) / ( static_cast <float> (RAND_MAX/(2.5-1.5)));
            exp = new Robot("explorer", speed_e, robot_durability, 3000, 450/speed_e);
            exp->setCanMove(false);
            Robot::unqID -= 1;
        }
        else{
            float speed_m = 1.0 + static_cast <float> (rand()) / ( static_cast <float> (RAND_MAX/(1.5-1.0)));
            exp = new Robot("miner", speed_m, robot_durability, 5000, 750/speed_m);
            exp->setCanMove(false);
            Robot::unqID -= 1;
        }
    }
    return exp;
}
void Crew::initMovement(){
    for (int i = 0; i < explorerCrewSize; i++)
    {
        ExplorerCrew[i]->setCanMove(true);
    }
    for (int i = 0; i < minerCrewSize; i++)
    {
        MinerCrew[i]->setCanMove(true);
    }
}
void Crew::updateDurability(){
    cout << "Explorer durability is being updated" << endl;
    cout << "Miner durability is being updated" << endl;
    for (int i = 0; i < explorerCrewSize; i++)
    {
        if(ExplorerCrew[i]->getdurability() != 0){
            ExplorerCrew[i]->setdurability(ExplorerCrew[i]->getdurability()-1);
        }
        else{
            cout << ExplorerCrew[i]->getName() << "'s durability=0" << endl;
            ExplorerCrew[i]->setCanMove(false);
        }
    }
     for (int i = 0; i < minerCrewSize; i++)
    {
        if(MinerCrew[i]->getdurability() != 0){
            MinerCrew[i]->setdurability(MinerCrew[i]->getdurability()-1);
        }
        else{
            cout << MinerCrew[i]->getName() << "'s durability=0" << endl;
            MinerCrew[i]->setCanMove(false);
        }
    }
}
void Crew::operator+=(const Robot* robot){
    if(robot->getType() == "explorer"){
        explorerCrewSize++;
        if(explorerCrewSize <= maxExplorers){
            Explorer* exp = new Explorer(robot->getType(), robot->getspeed(), robot->getdurability());
            exp->setCanMove(false);
            ExplorerCrew[explorerCrewSize-1] = exp;
            crewManufactureCost = crewManufactureCost + exp->getManufactureCost();
        }
        else{
            cout << "This robot cannot be added, check maximum size of the crew" << endl;
            explorerCrewSize--;
        }
    }
    else{
        minerCrewSize++;
        if(minerCrewSize <= maxMiners){
            Miner* mnr = new Miner(robot->getType(), robot->getspeed(), robot->getdurability());
            mnr->setCanMove(false);
            MinerCrew[minerCrewSize-1] = mnr;
            crewManufactureCost = crewManufactureCost + mnr->getManufactureCost();
        }
        else{
            cout << "This robot cannot be added, check maximum size of the crew" << endl;
            minerCrewSize--;
        }
    }
}
void Crew::operator-=(string robot_name){
    cout << robot_name << ": Goodbye" << endl;
    if(robot_name[0] == 'e'){
        if(explorerCrewSize != 1){
            for (int i = 0; i < explorerCrewSize; i++)
            {
                if(ExplorerCrew[i]->getName() == robot_name){
                    ExplorerCrew[i] = ExplorerCrew[explorerCrewSize-1];
                } 
            }
            explorerCrewSize--;
        }
    }
    else{
        if(minerCrewSize != 1){
            for (int i = 0; i < minerCrewSize; i++)
            {
                if(MinerCrew[i]->getName() == robot_name){
                    MinerCrew[i] = MinerCrew[explorerCrewSize-1];
                } 
            }
            minerCrewSize--;
        }
    }
}
Explorer** Crew::getExplorers(){
    return ExplorerCrew;
}
Miner** Crew::getMiners(){
    return MinerCrew;
}
void Crew::showInfo(){
    cout << "explorerCrew Size:" << explorerCrewSize << endl; 
    cout << "minerCrew Size:" << minerCrewSize << endl;
    for (int i = 0; i < explorerCrewSize; i++)
    {
        ExplorerCrew[i]->showInfo();
    }
    for (int i = 0; i < minerCrewSize; i++)
    {
        MinerCrew[i]->showInfo();
    }
    cout << "Total manufacture cost: " << crewManufactureCost << endl; 
    cout << "Total maintenance cost: " << crewMaintenanceCost << endl;
}
Crew::~Crew(){
    /*for (int i = 0; i < explorerCrewSize; i++)
    {
            delete ExplorerCrew[i];
    }
    for (int i = 0; i < minerCrewSize; i++)
    {
            delete MinerCrew[i];
    }
    delete [] ExplorerCrew;
    delete [] MinerCrew;*/
}
/*
****************
END: CREW CLASS FUNCTION DECLARATIONS 
****************
*/

/*
****************
BEGIN: COMMANDCENTER CLASS FUNCTION DECLARATIONS 
****************
*/
float CommandCenter::totalCrewMaintenanceCost = 0;

CommandCenter::CommandCenter(int selenium_aim, int search_area, int selenium_worth){
	neededSelenium = selenium_aim;
    searchArea = search_area;
    seleniumWorth = selenium_worth;
    turnCount = 1;
	profit = 0;
}
bool CommandCenter::isGameEnded(){
    if(searchArea == Explorer::totalExploredArea){
        if(profit > 0 && neededSelenium <= Miner::totalGatheredSelenium){
            cout << "Area has been fully explored." << endl;
            cout << "Aim: " << neededSelenium << " selenium." << endl;
            cout << "Collected: " << Miner::totalGatheredSelenium << endl;
            cout << "Congrats!" << endl;
        }
        else{
            cout << "Mission Failed!" << endl;
        }
        return true;
    }
    return false;
}
void CommandCenter::calculateProfit(Crew a_crew){
    float expenses;
    expenses = a_crew.getCrewMaintenanceCost() + a_crew.getCrewManufactureCost();
    float revenue;
    revenue = seleniumWorth * Miner::totalGatheredSelenium;
    profit = revenue - expenses;
    cout << "Profit:" << profit << endl;
    cout << "Expenses:" << expenses << endl;
    cout << "Selenium Revenue:" << revenue << endl;
}
void CommandCenter::operator++(){
    turnCount = turnCount + 1;
}
void CommandCenter::showInfo() const{
    cout << "Current turn: " << turnCount << endl;
    cout << "Aim: " << neededSelenium << " selenium." << endl;
    cout << "Collected: " << Miner::totalGatheredSelenium << endl;
    cout << "Total Search Area: " << searchArea << endl;
    cout << "Explored Area: " << Explorer::totalExploredArea << endl;
    cout << "Currently, there are " << Explorer::totalNumberOfSeleniumArea << " area/s that include selenium. " << endl;
    if(Explorer::totalNumberOfSeleniumArea > 0)
        cout << "Mine these areas if miners have not finished their turn! If you cannot cope with mining, you can always add new miners!" << endl;
}
/*
****************
END: COMMANDCENTER CLASS FUNCTION DECLARATIONS 
****************
*/