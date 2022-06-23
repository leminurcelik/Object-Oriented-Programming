//--- 2021-2022 Spring Object Oriented Programming Assignment 3 ---//
//--------------------------//
//---Name & Surname: Leminur Çelik
//---Student Number: 150190085
//--------------------------//

#ifndef __STATISTICS_H
#define __STATISTICS_H

//-------------Do Not Add New Libraries-------------//
//-------------All Libraries Needed Were Given-------------//

#include <vector>
class StatisticalDistribution{
    protected:
        double mean;
    public:
        double getMean() const{
            return mean;
        };
        virtual std::vector<double> sample(int, int) =0;
        std::vector<double> calculate_confidence_interval(std::vector<double>, int, double);
};

class NormalDistribution : public StatisticalDistribution{
    private:
        double stddev;
    public:
        NormalDistribution();
        std::vector<double> sample(int, int);
};

class UniformDistribution : public StatisticalDistribution{
    private:
        double a;
        double b;
    public:
        UniformDistribution();
        std::vector<double> sample(int, int);
};

class ExponentialDistribution : public StatisticalDistribution{
    private:
        double lambda;
    public:
        ExponentialDistribution();
        std::vector<double> sample(int, int);
};
#endif