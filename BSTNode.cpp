//
// Created by Lower School Music on 7/18/23.
//

#include "BSTNode.h"

BSTNode::BSTNode(const Money &moneyData) : data(moneyData), left(nullptr), right(nullptr)
{}

Money BSTNode::getData() const {
    return data;
}

void BSTNode::setData(const Money& moneyData)
{
    data = moneyData;
}

BSTNode* BSTNode::getLeft()
{
    return left;
}

void BSTNode::setLeft(BSTNode* newLeft)
{
    left = newLeft;
}

BSTNode* BSTNode::getRight()
{
    return right;
}

void BSTNode::setRight(BSTNode* newRight)
{
    right = newRight;
}

//bool BSTNode::operator==(const BSTNode* other) const
//{
//    return this->getData().isEqual(other->getData());
//}

BSTNode::BSTNode(const BSTNode &cpy) : data(cpy.data), left(cpy.left), right(cpy.right)
{}
