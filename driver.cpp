#include<cmath>
#include<iostream>

#include "NormalGenerator.hpp"
#include "Payoff.hpp"
#include "PayoffBridge.hpp"
#include "VanillaOption.h"
#include "Parameters.hpp"
#include "MCStatistics.hpp"

double TestPayoff(const PayoffBridge& thePayoff, double spot);
void SimpleMC(VanillaOption& theOption, const Parameters& vol, const Parameters& r, double spot,
                int numOfPaths, NormalGenerator& rNorm, MCStatistics& gatherer);

int main(int argc, char* argv[]){
    NormalGenerator randomNormal;
    ParameterConstant vol(0.01);
    ParameterConstant r(0.1);
    double spot = 37;
    PayoffCall testCallPayoff(30);
    VanillaOption testOption(testCallPayoff, 3);

    StatisticsMean meanGatherer;

    SimpleMC(testOption, vol, r, spot, 1000000, randomNormal, meanGatherer);

    std::cout << meanGatherer.GetResultsSoFar()[0][0] << std::endl;

    return 0;
}

double TestPayoff(const PayoffBridge& thePayoff, double spot)
{
    return thePayoff(spot);
}

void SimpleMC(VanillaOption& theOption, const Parameters& vol, const Parameters& r, double spot,
                int numOfPaths, NormalGenerator& rNorm, MCStatistics& gatherer)
{
    double expiry = theOption.GetExpiry();
    double variance = vol.SquareIntegral(0, expiry);
    double rootVariance = sqrt(variance);

    double movedSpot = spot * exp(r.Integral(0, expiry) - 0.5 * variance);
    double newSpot;
    for(int i = 0; i < numOfPaths; i ++)
    {
        newSpot = movedSpot * exp(rootVariance * rNorm.rng());
        gatherer.DumpOneResult(theOption.ComputePayoff(newSpot) * exp(-r.Integral(0, expiry)));
    }
    return;
}















