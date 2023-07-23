
#ifndef CURRENCYSIM_QUEUE_H
#define CURRENCYSIM_QUEUE_H
#include "LinkedList.h"

class Queue : public LinkedList
{
public:
    Queue();
    Queue(const Money& startMoney, const Money& endMoney);
    ~Queue() override = default;

    void enqueue(const Money& newMoney);
    void dequeue();
    Node* peekFront();
    Node* peekRear();

};


#endif //CURRENCYSIM_QUEUE_H
