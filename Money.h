
#ifndef CURRENCYSIM_MONEY_H
#define CURRENCYSIM_MONEY_H

#include "Currency.h"


class Money : public Currency
{
public:
    Money(int wholeVal, int fractionVal, std::string noteNm, std::string coinNm);
    Money(std::string& decimalInput, std::string& noteNm, std::string& coinNm);

    ~Money() = default;

    void add(Currency& other) override;
    void subtract(Currency& other) override;

    bool isEqual(Currency& other) override;
    bool isLarger(Currency& other) override;

    void print() override;

private:
    std::string noteName;
    std::string coinName;
};


#endif //CURRENCYSIM_MONEY_H
