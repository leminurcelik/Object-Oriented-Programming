//--- 2021-2022 Spring Object Oriented Programming Assignment 3 ---//
//--------------------------//
//---Name & Surname: Leminur Çelik
//---Student Number: 150190085
//--------------------------//

//-------------Do Not Add New Libraries-------------//
//-------------All Libraries Needed Were Given-------------//

#include "utils.h"
StatisticalDistribution* choose_function(int dist_type){
    StatisticalDistribution* dist;
    //0 for "NormalDistribution"
    if(dist_type == 0){
        dist = new NormalDistribution();
    }
    //1 for "UniformDistribution"
    else if(dist_type == 1){
        dist = new UniformDistribution();
    }
    //2 for "ExponentialDistribution"
    else if(dist_type == 2){
        dist = new ExponentialDistribution();
    }
    //throw an exception
    else{
        throw "Unidentified distribution function!";
    } 
    return dist;
}
double many_trials(StatisticalDistribution* dist, std::vector<double> random_sample, double t_value, int trials, int sample_size, int seed_value){
    double success = 0.0;
    for(int i = 0; i < trials; i++){
        random_sample = dist->sample(sample_size, seed_value); //Creates a random sample
        std::vector<double> interval = dist->calculate_confidence_interval(random_sample, sample_size, t_value); //Calculates confidence interval
        seed_value++; //Increments seed value to create different sample
        //Success describes how many times the calculated confidence interval covered the theoretical mean
        if(interval[2] > dist->getMean() && interval[0] < dist->getMean()){
            success++;
        }
    }
    double precision = success / trials; //Precision describes the number of successes divided by number of trials
    return precision;
}
