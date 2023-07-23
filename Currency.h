
#ifndef CURRENCYSIM_CURRENCY_H
#define CURRENCYSIM_CURRENCY_H
#include <iostream>
#include <string>

class Money;

class Currency
{
public:
    Currency();
    Currency(int wholeVal, int fractionVal);
    explicit Currency(const std::string& decimalInput);
    virtual ~Currency() = default;

    Currency(const Currency& other);
    Currency& operator=(const Currency& rhs);

    void setWhole(int newWhole);
    const int getWhole();
    void setFractional(int newFractional);
    const int getFractional();

    int rawTotal() const;
    void convertTotal(int raw);

    virtual void add(Currency& other) = 0;
    virtual void subtract(Currency& other) = 0;

    virtual bool isEqual(const Currency& other) = 0;
    virtual bool isLarger(const Currency& other) = 0;

    virtual void print() = 0;

protected:
    int fractional;
    int whole;
};


#endif //CURRENCYSIM_CURRENCY_H
