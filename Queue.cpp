
#include "Queue.h"

Queue::Queue() : LinkedList()
{}

Queue::Queue(const Money &startMoney, const Money &endMoney) : LinkedList(startMoney, endMoney)
{}

void Queue::enqueue(const Money &newMoney)
{
    Node* newNode = new Node{newMoney, nullptr};

    if (!start)
    {
        start = newNode;
        start->next = end;
    }
    else
    {
        newNode->next = start;
        start = newNode;
    }
    ++count;
}

void Queue::dequeue()
{
    if (count == 0)
        return;
    (!end) ? deleteStart() : deleteEnd();
}

LinkedList::Node *Queue::peekFront()
{
    return this->findStart();
}

LinkedList::Node *Queue::peekRear()
{
   return (!end) ? findStart() : findEnd();
}





