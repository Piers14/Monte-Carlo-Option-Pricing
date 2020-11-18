#ifndef PAYOFFBRIDGE_H
#define PAYOFFBRIDGE_H

#include "Payoff.hpp"

class PayoffBridge
{
    public:
        // ctor
        PayoffBridge(const Payoff& innerPayoff);
        // dtor
        ~PayoffBridge();
        // copy ctor
        PayoffBridge(const PayoffBridge& other);
        // assignment
        PayoffBridge& operator=(const PayoffBridge& other);

        inline double operator()(double spot) const;

    protected:

    private:
        Payoff* mPayoffPtr;
};

inline double PayoffBridge::operator()(double spot) const
{
    return mPayoffPtr->operator()(spot);
}

#endif // PAYOFFBRIDGE_H
