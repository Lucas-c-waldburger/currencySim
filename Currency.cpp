//
// Created by Lower School Music on 7/5/23.
//

#include "Currency.h"

Currency::Currency() : whole(0), fractional(0)
{}

Currency::Currency(int wholeVal, int fractionVal)
{
    if (wholeVal < 0 || fractionVal < 0)
        throw std::invalid_argument("Amounts cannot be negative");
    if (fractionVal > 99)
        throw std::invalid_argument("fractional amount cannot exceed 99");

    whole = wholeVal;
    fractional = fractionVal;
}

Currency::Currency(const Currency &other)
{
    this->whole = other.whole;
    this->fractional = other.fractional;
}

Currency& Currency::operator=(const Currency &rhs)
{
    if (this != &rhs)
    {
        this->whole = rhs.whole;
        this->fractional = rhs.fractional;
    }

    return *this;
}

void Currency::setWhole(int newWhole) { whole = newWhole; }

const int Currency::getWhole() { return whole; }

void Currency::setFractional(int newFractional) { fractional = newFractional; }

const int Currency::getFractional() { return fractional; }


int Currency::rawTotal() const
{
    return fractional + (whole * 100);
}

void Currency::convertTotal(int raw)
{
    whole = raw / 100;
    fractional = raw % 100;
}

Currency::Currency(std::string& decimalInput)
{
    std::string exceptionWhat = "The entry '" + decimalInput + "' is improperly formatted";
    size_t decimalPos = decimalInput.find('.');

    if (decimalPos == std::string::npos)
        throw std::invalid_argument(exceptionWhat);

    whole = std::stoi(decimalInput.substr(0, decimalPos));

    decimalInput.erase(0, decimalPos + 1);
    if (decimalInput.length() != 2)
        throw std::invalid_argument(exceptionWhat);

    fractional = std::stoi(decimalInput);
}
