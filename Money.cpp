//
// Created by Lower School Music on 7/5/23.
//

#include "Money.h"

#include <utility>

Money::Money(int wholeVal, int fractionVal, std::string  noteNm, std::string  coinNm) : Currency(wholeVal, fractionVal),
             noteName(std::move(noteNm)), coinName(std::move(coinNm))
{
    if (noteName.empty() || coinName.empty())
        throw std::invalid_argument("Note and/or Coin Name cannot be an empty string");
}

Money::Money(const std::string& decimalInput, const std::string& noteNm, const std::string& coinNm) : Currency(decimalInput),
                                                                                      noteName(noteNm), coinName(coinNm)
{
    if (noteName.empty() || coinName.empty())
        throw std::invalid_argument("Note and/or Coin Name cannot be an empty string");
}

Money::Money(const Money &other) : Currency(other)
{
    this->noteName = other.noteName;
    this->coinName = other.coinName;
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


bool Money::isEqual(const Currency& other)
{
    return rawTotal() == other.rawTotal();
}

bool Money::isLarger(const Currency& other)
{
    return rawTotal() > other.rawTotal();
}


