//--- 2021-2022 Spring Object Oriented Programming Assignment 2 ---//
//--------------------------//
//---Name & Surname: Leminur Çelik
//---Student Number: 150190085
//--------------------------//

//-------------Do Not Add New Libraries-------------//
//-------------All Libraries Needed Were Given-------------//
//-------------Do Not Add Change Header Include Paths-------------/

#include <iostream>
using namespace std;
#include "Robot.h"



/*
****************
BEGIN: ROBOT CLASS FUNCTION DECLARATIONS
****************
*/
int Robot::unqID = 0;

Robot::Robot(string type, float rbt_speed, int rbt_durability, int rbt_manufacture_cost, float rbt_maintenance_cost){
    unqID++;
    string s;
    if(type == "explorer")
        s = "exp";
    else
        s = "mnr";
    RobotName = s + "-" + to_string(unqID);
    RobotType = type;
    speed = rbt_speed;
    durability = rbt_durability;
    manufactureCost = rbt_manufacture_cost;
    maintenanceCost = rbt_maintenance_cost;
    canMove = true;
}
void Robot::operator=(const Robot &attributes){
    RobotName = attributes.RobotName;
    RobotType = attributes.RobotType;
    speed = attributes.speed;
    durability = attributes.durability;
    maintenanceCost = attributes.maintenanceCost;
    manufactureCost = attributes.manufactureCost;
    canMove = attributes.canMove;
}
void Robot::showInfo() const{
    cout << "Name: " << RobotName << endl;
    cout << "Type: " << RobotType << endl;
    cout << "Speed: " << speed << endl;
    cout << "Durability: " << durability << endl;
    cout << "ManufactureCost: " << manufactureCost << endl;
    cout << "MaintenanceCost: " << maintenanceCost << endl;
    cout << "Can Move: " << canMove << endl;
}
/*
****************
END: ROBOT CLASS FUNCTION DECLARATIONS
****************
*/

/*
****************
BEGIN: EXPLORER CLASS FUNCTION DECLARATIONS
****************
*/
float Explorer::totalExploredArea = 0.0;
int Explorer::totalNumberOfSeleniumArea = 0;

Explorer::Explorer(string exp_type, float exp_speed, int exp_durability): Robot(exp_type, exp_speed, exp_durability, 3000, 450/exp_speed){
    exploredArea = 0;
}

bool Explorer::move(){
    return getCanMove();
}
void Explorer::explore(){
    int exp_random = rand() % 101;
    if(exp_random >= 40){
        detectedSelenium = true;
        totalNumberOfSeleniumArea++;
    }
    else{
        detectedSelenium = false;
    }
    totalExploredArea += 1500;
    exploredArea = 1500;
}
void Explorer::operator=(const Explorer &attributes){
    setdurability(attributes.getdurability());
    setspeed(attributes.getspeed());
    setMaintenanceCost(attributes.getMaintenanceCost());
    setManufactureCost(attributes.getManufactureCost());
    setCanMove(attributes.getCanMove());
    totalExploredArea = attributes.totalExploredArea;
	totalNumberOfSeleniumArea = attributes.totalNumberOfSeleniumArea;
	exploredArea = attributes.exploredArea;
	detectedSelenium = attributes.detectedSelenium;
}
void Explorer::showInfo() const{
    Robot::showInfo();
    cout << "explored area: " << exploredArea << endl;
}
/*
****************
END: EXPLORER CLASS FUNCTION DECLARATIONS
****************
*/

/*
****************
BEGIN: MINER CLASS FUNCTION DECLARATIONS
****************
*/
int Miner::totalGatheredSelenium = 0;

Miner::Miner(string mnr_Type, float mnr_speed, int mnr_durability) : Robot(mnr_Type, mnr_speed, mnr_durability, 5000, 750/mnr_speed){
    gatheredSelenium=0;
}

void Miner::mine(){
    int mnr_random = 10 + rand() % 91;
    mnr_random *= 5;
    gatheredSelenium = mnr_random;
    Explorer::totalNumberOfSeleniumArea--;
    totalGatheredSelenium += gatheredSelenium;
}
bool Miner::move(){
    if(getCanMove() && Explorer::totalNumberOfSeleniumArea != 0)
        return true;
    else
        return false;
}
void Miner::operator=(const Miner &attributes){
    setdurability(attributes.getdurability());
    setspeed(attributes.getspeed());
    setMaintenanceCost(attributes.getMaintenanceCost());
    setManufactureCost(attributes.getManufactureCost());
    setCanMove(attributes.getCanMove());
    totalGatheredSelenium = attributes.totalGatheredSelenium;
    gatheredSelenium = attributes.gatheredSelenium;
}
void Miner::showInfo() const{
    Robot::showInfo();
    cout << "# of gathered selenium: " << gatheredSelenium << endl;
}
/*
****************
END: MINER CLASS FUNCTION DECLARATIONS
****************
*/

