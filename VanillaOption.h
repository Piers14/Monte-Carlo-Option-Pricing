#ifndef VANILLAOPTION_H
#define VANILLAOPTION_H

#include "PayoffBridge.hpp"

class VanillaOption
{
    public:
        // ctor
        VanillaOption(const PayoffBridge& thePayoff, double expiry);
        // Gets expiry
        double GetExpiry() const;
        // Computes payoff
        double ComputePayoff(const double spot) const;

    protected:

    private:
        double mExpiry;

        PayoffBridge mPayoffB;
};

#endif // VANILLAOPTION_H
