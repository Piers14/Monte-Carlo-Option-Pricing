#include "PayoffBridge.hpp"

PayoffBridge::PayoffBridge(const Payoff& innerPayoff)
{
    mPayoffPtr = innerPayoff.clone();
}

PayoffBridge::~PayoffBridge()
{
    delete mPayoffPtr;
}

PayoffBridge::PayoffBridge(const PayoffBridge& other)
{
    mPayoffPtr = other.mPayoffPtr->clone();
}

PayoffBridge& PayoffBridge::operator=(const PayoffBridge& rhs)
{
    if(this != &rhs)
    {
        delete mPayoffPtr;
        mPayoffPtr = rhs.mPayoffPtr->clone();
    }
    return *this;
}
