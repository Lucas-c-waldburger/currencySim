
#include "LinkedList.h"


LinkedList::Node::Node(Money nodeData, LinkedList::Node *nodeNext) : data(nodeData), next(nodeNext)
{}

LinkedList::LinkedList() : start(nullptr), end(nullptr), count(0)
{}

LinkedList::LinkedList(const Money &startMoney, const Money &endMoney)
{
    end = new Node{endMoney, nullptr};
    start = new Node{startMoney, end};
    count = 2;
}

LinkedList::~LinkedList()
{
    Node* currentNode = start;
    while (currentNode != nullptr)
    {
         Node* nextNode = currentNode->next;
         delete currentNode;
         currentNode = nextNode;
    }
}

void LinkedList::addData(const Money &newMoney)
{
    Node* newNode = new Node{newMoney, nullptr};

    if (!start)
    {
        start = newNode;
        start->next = end;
    }
    else if (!end)
    {
        end = newNode;
        start->next = end;
    }
    else
    {
        end->next = newNode;
        end = newNode;
    }
    ++count;
}

//void LinkedList::addData(const Money &newMoney, int position)
//{
////    if (!start || !end)
////        throw std::invalid_argument("position cannot be specified in addData function unless start and end node are not null");
//
//    if (position < 0 || position > count - 1)
//        throw std::out_of_range("invalid position");
//
//    Node* newNode = new Node{newMoney, nullptr};
//
//    if (position == 0)
//    {
//        if (!start)
//        {
//            start = newNode;
//            start->next = end;
//        }
//        else
//        {
//            newNode->next = start;
//            start = newNode;
//        }
//    }
//
//    else if (position == 1 && !end)
//    {
//        end = newNode;
//        start->next = end;
//    }
//
//    else {
//        Node *currentNode = start;
//        int i = 0;
//        while (i < position - 1) {
//            currentNode = currentNode->next;
//            ++i;
//        }
//
//        newNode->next = currentNode->next;
//        currentNode->next = newNode;
//    }
//
//    ++count;
//}

void LinkedList::deleteData(LinkedList::Node* nodeToDelete)
{
    if (nodeToDelete == start)
        return this->deleteStart();

    if (nodeToDelete == end)
        return this->deleteEnd();

    Node* currentNode = start;

    while (currentNode != nullptr)
    {
        if (currentNode->next == nodeToDelete)
        {
            currentNode->next = nodeToDelete->next;
            delete nodeToDelete;
            --count;
            return;
        }
        currentNode = currentNode->next;
    }
}

void LinkedList::deleteStart()
{
    if (!start)
        return;

    Node* newStart = start->next;
    delete start;
    start = newStart;
    --count;
}

void LinkedList::deleteEnd()
{
    if (!end)
        return;

    Node* currentNode = start;
    while (currentNode->next != end)
        currentNode = currentNode->next;

    currentNode->next = nullptr;
    delete end;
    end = currentNode;
    --count;
}

LinkedList::Node *LinkedList::findData(int wholeVal, int fractionalVal)
{
    if (!start)
        throw std::invalid_argument("Start node must be defined");

    Node* currentNode = start;

    while (currentNode != nullptr)
    {
        if (currentNode->data.getWhole() == wholeVal &&
            currentNode->data.getFractional() == fractionalVal)
        {
            return currentNode;
        }
        currentNode = currentNode->next;
    }
    return nullptr;
}

const int LinkedList::countData()
{
    return count;
}

bool LinkedList::listEmpty()
{
    return (count == 0);
}

void LinkedList::printData()
{
    Node* currentNode = start;

    while (currentNode != nullptr)
    {
        currentNode->data.print();
        currentNode = currentNode->next;
    }
}

LinkedList::Node *LinkedList::findStart()
{
    if (!start)
        throw std::invalid_argument("start is nullptr");
    return start;
}

LinkedList::Node *LinkedList::findEnd()
{
    if (!end)
        return findStart();
    return end;
}

