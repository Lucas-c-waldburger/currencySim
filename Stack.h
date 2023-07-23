
#ifndef CURRENCYSIM_STACK_H
#define CURRENCYSIM_STACK_H
#include "LinkedList.h"

class Stack : public LinkedList
{
public:
    Stack();
    Stack(const Money& startMoney, const Money& endMoney);
    ~Stack() override = default;

    void push(const Money& newMoney);
    void pop();
    Node* peek();
};


#endif //CURRENCYSIM_STACK_H
