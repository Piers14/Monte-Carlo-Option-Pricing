#include "MCStatistics.hpp"

StatisticsMean::StatisticsMean()
:
    mRunningSum(0.0), mPathsDone(0ULL)
{

}

void StatisticsMean::DumpOneResult(double result)
{
    mPathsDone++;
    mRunningSum += result;
}

std::vector<std::vector<double>> StatisticsMean::GetResultsSoFar()
{
    std::vector<std::vector<double>> resultsTable(1);
    resultsTable[0].resize(1);
    resultsTable[0][0] = mRunningSum / mPathsDone;
    return resultsTable;
}

MCStatistics* StatisticsMean::clone() const
{
    return new StatisticsMean(*this);
}
