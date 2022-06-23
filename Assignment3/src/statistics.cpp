//--- 2021-2022 Spring Object Oriented Programming Assignment 3 ---//
//--------------------------//
//---Name & Surname: Leminur Çelik
//---Student Number: 150190085
//--------------------------//

//-------------Do Not Add New Libraries-------------//
//-------------All Libraries Needed Were Given-------------//

#include "statistics.h"
#include <random>
#include <iostream>

std::vector<double> StatisticalDistribution::calculate_confidence_interval(std::vector<double> random_sample, int size, double t){
    int n = size; //sample size
    double lower_bound, sample_mean, upper_bound;
    double sum = 0;
    double total = 0;
    for(int i = 0; i < n; i++){
        sum += random_sample[i]; //sum of the numbers in the sample
    }
    sample_mean = sum / n; //sample mean
    for(int i = 0; i < n; i++){
        total += (sample_mean - random_sample[i]) * (sample_mean - random_sample[i]); //sum of the numbers 
    }
    double deviation_s = sqrt(total / size); //sample standard deviation
    lower_bound = sample_mean - t * (deviation_s / sqrt(size));
    upper_bound = sample_mean + t * (deviation_s / sqrt(size));
    std::vector<double> a_vector = {lower_bound, sample_mean, upper_bound};
    return a_vector;

}
//Constructor of NormalDistribution
NormalDistribution::NormalDistribution(){
    mean = 0.0;
    stddev = 1.0;
}
//Generates a random number from a Normal Distribution
std::vector<double> NormalDistribution::sample(int size, int seed_val){
    std::default_random_engine generator;
    generator.seed(seed_val);
    std::normal_distribution<double> distribution(mean, stddev);
    std::vector<double> a_sample; //Creates a sample as a vector
    //Repeats this process to create a sample of given size
    for (int i = 0; i < size; i++) {
        double number = distribution(generator);
        a_sample.push_back(number);
    }
    return a_sample;
}
//Constructor of UniformDistribution
UniformDistribution::UniformDistribution(){
    mean = 0.0;
    a = -1.0;
    b = 1.0;
}
//Generates a random number from a Uniform Distribution
std::vector<double> UniformDistribution::sample(int size, int seed_val){
    std::default_random_engine generator;
    generator.seed(seed_val);
    std::uniform_real_distribution<double> distribution(a, b);
    std::vector<double> a_sample; //Creates a sample as a vector
    //Repeats this process to create a sample of given size
    for (int i = 0; i < size; i++) {
        double number = distribution(generator);
        a_sample.push_back(number);
    }
    return a_sample;
}
//Constructor of ExponentialDistribution
ExponentialDistribution::ExponentialDistribution(){
    mean = 1.0;
    lambda = 1.0;
}
//Generatse a random number from a Exponential Distribution
std::vector<double> ExponentialDistribution::sample(int size, int seed_val){
    std::default_random_engine generator ;
    generator.seed(seed_val);
    std::exponential_distribution<double> distribution(lambda);
    std::vector<double> a_sample; //Creates a sample as a vector
    //Repeats this process to create a sample of given size
    for (int i = 0; i < size; i++) { 
        double number = distribution(generator);
        a_sample.push_back(number);
    }
    return a_sample;
}