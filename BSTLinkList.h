
#ifndef CURRENCYSIM_BSTLINKLIST_H
#define CURRENCYSIM_BSTLINKLIST_H

#include "BSTNode.h"

enum Order
{
    PRE_ORDER,
    IN_ORDER,
    POST_ORDER
};

class BSTLinkList
{
public:
    BSTLinkList();
    BSTLinkList(BSTNode* startRoot);
    ~BSTLinkList();

    BSTNode* getRoot();
    void setRoot(BSTNode* newRoot);

    void addData(BSTNode* currentNode, BSTNode* newNode);
    void printData(BSTNode* currentNode, int order);

    BSTNode* searchData(BSTNode* currentNode, BSTNode* searchNode, int order);
    BSTNode* searchData(BSTNode* currentNode, BSTNode* searchNode);
    BSTNode* searchData(BSTNode* currentNode, int searchRawTotal);

    void deleteData(BSTNode* currentNode, BSTNode* deleteNode);
    bool deleteData(BSTNode* currentNode, int searchRawTotal);

    struct ConsoleInterface
    {

    };

private:
    BSTNode* root;
    int count;
};




#endif //CURRENCYSIM_BSTLINKLIST_H
