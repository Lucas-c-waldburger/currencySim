#include <iostream>
#include <fstream>
#include "Queue.h"
#include "Stack.h"
#include "BSTLinkList.h"

const std::string NOTE_NM = "Dollar", COIN_NM = "Cent";

int main()
{
    BSTLinkList bstLinkList{};

    std::string decimalInput;
    std::fstream fin("/Users/lowerschoolmusic/currencySim/MoneyInput.txt");

    if (fin.is_open())
    {
        fin >> decimalInput;
        bstLinkList.setRoot(new BSTNode{Money{decimalInput, NOTE_NM, COIN_NM}});

        while (fin >> decimalInput)
        {
            bstLinkList.addData(bstLinkList.getRoot(), new BSTNode{Money{decimalInput, NOTE_NM, COIN_NM}});
        }

        fin.close();
    }

//    Money testMoney{"20.21", NOTE_NM, COIN_NM};
//    testMoney.print();
    bstLinkList.printData(bstLinkList.getRoot(), PRE_ORDER);

//    BSTNode* toFind{new BSTNode{testMoney}};
//    toFind->getData().print();
//    BSTNode* result = bstLinkList.searchData(bstLinkList.getRoot(), toFind); // this is calling money&currency copy constructors. why?
    bool result = bstLinkList.deleteData(bstLinkList.getRoot(), 5100);


    if (result)
        std::cout << "FOUND!\n\n";
    else
        std::cout << "NOT FOUND!\n\n";

    bstLinkList.printData(bstLinkList.getRoot(), PRE_ORDER);

    return 0;
}
