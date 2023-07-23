
#ifndef CURRENCYSIM_BSTNODE_H
#define CURRENCYSIM_BSTNODE_H
#include "Money.h"

class BSTNode
{
public:
    BSTNode(const Money& moneyData);
    BSTNode(const BSTNode& cpy);

//    bool operator==(const BSTNode* other) const; <- Did not work, had to manually call isEqual(). why?

    Money getData() const;
    void setData(const Money& moneyData);

    BSTNode* getLeft();
    void setLeft(BSTNode* newLeft);

    BSTNode* getRight();
    void setRight(BSTNode* newRight);

private:
    Money data;
    BSTNode* left;
    BSTNode* right;
};


#endif //CURRENCYSIM_BSTNODE_H
