//
// Created by Lower School Music on 7/17/23.
//

#include "Stack.h"

Stack::Stack() : LinkedList()
{}

Stack::Stack(const Money &startMoney, const Money &endMoney) : LinkedList(startMoney, endMoney)
{}

void Stack::push(const Money &newMoney)
{
    this->addData(newMoney);
}

void Stack::pop()
{
    this->deleteEnd();
}

LinkedList::Node *Stack::peek()
{
    return this->findEnd();
}





