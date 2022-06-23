//--- 2021-2022 Spring Object Oriented Programming Assignment 3 ---//
//--------------------------//
//---Name & Surname: Leminur Çelik
//---Student Number: 150190085
//--------------------------//

//-------------Do Not Add New Libraries-------------//
//-------------All Libraries Needed Were Given-------------//

#ifndef __UTILS_H
#define __UTILS_H

#include "statistics.h"
//Choose a distribution function by given number
StatisticalDistribution* choose_function(int); 

//Creates a random sample and calculates the confidence interval for many times
double many_trials(StatisticalDistribution*, std::vector<double>, double, int, int, int);

#endif