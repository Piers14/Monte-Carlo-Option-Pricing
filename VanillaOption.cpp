#include "VanillaOption.h"

VanillaOption::VanillaOption(const PayoffBridge& thePayoff, double expiry)
:
    mExpiry(expiry), mPayoffB(thePayoff)
{
}

double VanillaOption::GetExpiry() const
{
    return mExpiry;
}

double VanillaOption::ComputePayoff(const double spot) const
{
    return mPayoffB(spot);
}














