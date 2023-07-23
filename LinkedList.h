
#ifndef CURRENCYSIM_LINKEDLIST_H
#define CURRENCYSIM_LINKEDLIST_H
#include "Money.h"

class LinkedList
{
public:
    struct Node
    {
        Node(Money nodeData, Node* nodeNext);
        Money data;
        Node* next;
    };
    LinkedList();
    LinkedList(const Money& startMoney, const Money& endMoney);
    virtual ~LinkedList();

    void addData(const Money& newMoney);
//    void addData(const Money& newMoney, int position);
    void deleteData(Node* nodeToDelete);
    void deleteStart();
    void deleteEnd();
    Node* findData(int wholeVal, int fractionalVal);
    Node* findStart();
    Node* findEnd();
    const int countData();
    bool listEmpty();
    void printData();

protected:
    Node* start;
    Node* end;
    int count;
};


#endif //CURRENCYSIM_LINKEDLIST_H
