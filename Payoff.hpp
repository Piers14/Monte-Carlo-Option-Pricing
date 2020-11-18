#ifndef PAYOFF_HPP
#define PAYOFF_HPP



class Payoff
{
    public:
        // ctor
        Payoff();

        // Compute payoff
        virtual double operator()(double spot) const = 0;

        // dtor
        virtual ~Payoff();

        // Virtual copy constructor
        virtual Payoff* clone() const = 0;

    private:
};

class PayoffCall : public Payoff
{
    public:
        PayoffCall(double strike);

        virtual double operator()(double spot) const;

        virtual ~PayoffCall();

        virtual Payoff* clone() const;

    private:
        double mStrike;

};

class PayoffPut : public Payoff
{
    public:
        PayoffPut(double strike);

        virtual double operator()(double spot) const;

        virtual ~PayoffPut();

        virtual Payoff* clone() const;

    private:
        double mStrike;
};

#endif // PAYOFF_HPP
