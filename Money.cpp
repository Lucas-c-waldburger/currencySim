//
// Created by Lower School Music on 7/5/23.
//

#include "Money.h"

Money::Money(int wholeVal, int fractionVal, std::string noteNm, std::string coinNm) : Currency(wholeVal, fractionVal),
             noteName(noteNm), coinName(coinNm)
{
    if (noteName.empty() || coinName.empty())
        throw std::invalid_argument("Note and/or Coin Name cannot be an empty string");
}

Money::Money(std::string& decimalInput, std::string& noteNm, std::string& coinNm) : Currency(decimalInput),
                                                                                      noteName(noteNm), coinName(coinNm)
{
    if (noteName.empty() || coinName.empty())
        throw std::invalid_argument("Note and/or Coin Name cannot be an empty string");
}

void Money::print()
{
    std::cout << whole << ' ' << noteName << ' ' << fractional << ' ' << coinName << '\n';
}

void Money::add(Currency& other)
{
    convertTotal(rawTotal() + other.rawTotal());
}

void Money::subtract(Currency& other)
{
    int subResult = rawTotal() - other.rawTotal();
    if (subResult < 0)
        throw std::invalid_argument("Subtrahend cannot be larger than minuend");

    convertTotal(subResult);
}


bool Money::isEqual(Currency& other)
{
    return rawTotal() == other.rawTotal();
}

bool Money::isLarger(Currency& other)
{
    return rawTotal() > other.rawTotal();
}
