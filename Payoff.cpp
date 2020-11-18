#include "Payoff.hpp"
#include<algorithm>

// Payoff - Base class

Payoff::Payoff()
{
    //ctor
}

Payoff::~Payoff()
{
    //dtor
}


// PayoffCall

PayoffCall::PayoffCall(double strike)
:
    mStrike(strike)
{
}

PayoffCall::~PayoffCall()
{
    //dtor
}

double PayoffCall::operator()(double spot) const
{
    return std::max(spot - mStrike, 0.0);
}

Payoff* PayoffCall::clone() const
{
    return new PayoffCall(*this);
}


// PayoffPut
PayoffPut::PayoffPut(double strike)
:
    mStrike(strike)
{
}

double PayoffPut::operator()(double spot) const
{
    return std::max(mStrike - spot, 0.0);
}

PayoffPut::~PayoffPut()
{
    //dtor
}

Payoff* PayoffPut::clone() const
{
    return new PayoffPut(*this);
}



