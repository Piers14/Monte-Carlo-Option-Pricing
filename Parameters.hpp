#ifndef PARAMETERS_H
#define PARAMETERS_H

class ParameterInner
{
    public:
        // clone
        virtual ParameterInner* clone() const = 0;
        // computes integral
        virtual double Integral(double time1, double time2) const = 0;
        // computes squared integral
        virtual double SquareIntegral(double time1, double time2) const = 0;
        // dtor
        virtual ~ParameterInner(){}
};


class Parameters
{
    public:
        // ctor
        Parameters(const ParameterInner& param);
        // dtor
        virtual ~Parameters();
        // copy ctor
        Parameters(const Parameters& other);
        // assignment
        Parameters& operator=(const Parameters& other);
        // calls integral
        inline double Integral(double time1, double time2) const;
        // calls square integral
        inline double SquareIntegral(double time1, double time2) const;
        // returns mean
        double Mean(double time1, double time2) const;
        // returns rms
        double RootMeanSquare(double time1, double time2) const;

    protected:

    private:
        ParameterInner* mInnerPtr;
};

inline double Parameters::Integral(double time1, double time2) const
{
    return mInnerPtr->Integral(time1, time2);
}

inline double Parameters::SquareIntegral(double time1, double time2) const
{
    return mInnerPtr->SquareIntegral(time1, time2);
}


// Constant parameters class

class ParameterConstant : public ParameterInner
{
    public:
        // ctor
        ParameterConstant(double constant);
        // clone
        virtual ParameterInner* clone() const;
        // Integrals
        double Integral(double time1, double time2) const;
        double SquareIntegral(double time1, double time2) const;

    private:
        double mConstant;
        double mSquareConstant;
};
















#endif // PARAMETERS_H
