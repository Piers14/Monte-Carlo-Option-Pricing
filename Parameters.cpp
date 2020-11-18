#include "Parameters.hpp"

// Parameters Inner



// Parameters Wrapper
Parameters::Parameters(const ParameterInner& param)
{
    mInnerPtr = param.clone();
}

Parameters::~Parameters()
{
    delete mInnerPtr;
}

Parameters::Parameters(const Parameters& other)
{
    mInnerPtr = other.mInnerPtr->clone();
}

Parameters& Parameters::operator=(const Parameters& rhs)
{
    if(this != &rhs)
    {
        delete mInnerPtr;
        mInnerPtr = rhs.mInnerPtr->clone();
    }
    return *this;
}

double Parameters::Mean(double time1, double time2) const
{
    return Integral(time1, time2) / (time2 - time1);
}

double Parameters::RootMeanSquare(double time1, double time2) const
{
    return SquareIntegral(time1, time2) / (time2 - time1);
}


// Constant Parameters

ParameterConstant::ParameterConstant(double constant)
{
    mConstant = constant;
    mSquareConstant = mConstant * mConstant;
}

ParameterInner* ParameterConstant::clone() const
{
    return new ParameterConstant(*this);
}

double ParameterConstant::Integral(double time1, double time2) const
{
    return mConstant * (time2 - time1);
}

double ParameterConstant::SquareIntegral(double time1, double time2) const
{
    return mSquareConstant * (time2 - time1);
}
















