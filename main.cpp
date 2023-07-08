#include <iostream>

#include "Money.h"

const std::string INPUT = "2.48 1.98 9.98 8.89 33.39";

int main() {

    Currency* currencyArr[5];
    std::string noteNm = "Dollar", coinNm = "Cent";
    std::string decimalInput;

    std::cout << "Enter 5 spaced-separated decimal values: ";

    for (auto& money : currencyArr)
    {
        try
        {
            std::cin >> decimalInput;
            money = new Money(decimalInput, noteNm, coinNm);
        }

        catch (std::invalid_argument& ex)
        {
            std::cout << ex.what() << '\n';
        }
    }

    for (auto& money : currencyArr)
    {
        money->print();
    }
    std::cout << '\n';

    // OPERATIONS
    currencyArr[0]->add(*currencyArr[1]);
    currencyArr[0]->print();

    currencyArr[2]->subtract(*currencyArr[0]);
    currencyArr[2]->print();
    std::cout << '\n';

    // EQUALITY
    std::string equalityMessage = (currencyArr[0]->isEqual(*currencyArr[3])) ?
            "Is equal to\n" : "Is not equal to\n";

    currencyArr[0]->print();
    std::cout << equalityMessage;
    currencyArr[3]->print();
    std::cout << '\n';


    // COMPARISON
    (currencyArr[0]->isLarger(*currencyArr[4])) ? currencyArr[0]->print() : currencyArr[4]->print();


    return 0;
}
