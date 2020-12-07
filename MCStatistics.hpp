#ifndef MCSTATISTICS_H
#define MCSTATISTICS_H

#include <vector>

class MCStatistics
{
    public:
        MCStatistics(){};

        virtual void DumpOneResult(double result) = 0;

        virtual std::vector<std::vector<double>> GetResultsSoFar() = 0;

        virtual MCStatistics* clone() const = 0;

        virtual ~MCStatistics(){};

    protected:

    private:
};

class StatisticsMean : public MCStatistics
{
    public:
        StatisticsMean();

        virtual void DumpOneResult(double result);

        virtual std::vector<std::vector<double>> GetResultsSoFar();

        virtual MCStatistics* clone() const;

    private:
        double mRunningSum;
        unsigned long long mPathsDone;

};

#endif // MCSTATISTICS_H
