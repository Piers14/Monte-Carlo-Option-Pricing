#include<cmath>
#include<iostream>

#include "NormalGenerator.hpp"
#include "Payoff.hpp"
#include "PayoffBridge.hpp"
#include "VanillaOption.h"
#include "Parameters.hpp"

double TestPayoff(const PayoffBridge& thePayoff, double spot);
double SimpleMC(VanillaOption& theOption, const Parameters& vol, const Parameters& r, double spot,
                int numOfPaths, NormalGenerator& rNorm);

int main(int argc, char* argv[]){
    NormalGenerator randomNormal;
    ParameterConstant vol(0.01);
    ParameterConstant r(0.1);
    double spot = 37;
    PayoffCall testCallPayoff(30);
    VanillaOption testOption(testCallPayoff, 3);

    double optionValue = SimpleMC(testOption, vol, r, spot, 10000000, randomNormal);

    std::cout << optionValue << std::endl;

    return 0;
}

double TestPayoff(const PayoffBridge& thePayoff, double spot)
{
    return thePayoff(spot);
}

double SimpleMC(VanillaOption& theOption, const Parameters& vol, const Parameters& r, double spot,
                int numOfPaths, NormalGenerator& rNorm)
{
    double expiry = theOption.GetExpiry();
    double variance = vol.SquareIntegral(0, expiry);
    double rootVariance = sqrt(variance);

    double movedSpot = spot * exp(r.Integral(0, expiry) - 0.5 * variance);
    double newSpot;
    double runningSum = 0;
    for(int i = 0; i < numOfPaths; i ++)
    {
        newSpot = movedSpot * exp(rootVariance * rNorm.rng());
        runningSum += theOption.ComputePayoff(newSpot);
    }
    double mean = runningSum / numOfPaths;
    return exp(-r.Integral(0, expiry)) * mean;
}















