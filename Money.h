
#ifndef CURRENCYSIM_MONEY_H
#define CURRENCYSIM_MONEY_H

#include "Currency.h"


class Money : public Currency
{
public:
    Money(int wholeVal, int fractionVal, std::string  noteNm, std::string  coinNm);
    Money(const std::string& decimalInput, const std::string& noteNm, const std::string& coinNm);
    Money(const Money& other);
    ~Money() override = default;

    void add(Currency& other) override;
    void subtract(Currency& other) override;

    bool isEqual(const Currency& other) override;
    bool isLarger(const Currency& other) override;

    void print() override;

private:
    std::string noteName;
    std::string coinName;
};


#endif //CURRENCYSIM_MONEY_H
