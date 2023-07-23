//
// Created by Lower School Music on 7/18/23.
//

#include "BSTLinkList.h"

BSTLinkList::BSTLinkList() : root(nullptr), count(0)
{}

BSTLinkList::BSTLinkList(BSTNode* startRoot) : root(startRoot), count(1)
{}

BSTLinkList::~BSTLinkList()
{
    BSTNode* currentNode = root;
}


void BSTLinkList::addData(BSTNode* currentNode, BSTNode* newNode)
{
    if (newNode->getData().rawTotal() <= currentNode->getData().rawTotal())
    {
        if (!currentNode->getLeft())
        {
            currentNode->setLeft(newNode);
            ++count;
        }
        else
            addData(currentNode->getLeft(), newNode);
    }

    else
    {
        if (!currentNode->getRight())
        {
            currentNode->setRight(newNode);
            ++count;
        }
        else
            addData(currentNode->getRight(), newNode);
    }
}

BSTNode* BSTLinkList::getRoot() {
    return root;
}

void BSTLinkList::setRoot(BSTNode* newRoot)
{
    root = newRoot;
}

void BSTLinkList::printData(BSTNode *currentNode, int order)
{
    if (!currentNode)
        return;

    switch (order)
    {
        case PRE_ORDER:
            currentNode->getData().print();
            printData(currentNode->getLeft(), order);
            printData(currentNode->getRight(), order);
            break;

        case IN_ORDER:
            printData(currentNode->getLeft(), order);
            currentNode->getData().print();
            printData(currentNode->getRight(), order);
            break;

        case POST_ORDER:
            printData(currentNode->getLeft(), order);
            printData(currentNode->getRight(), order);
            currentNode->getData().print();
            break;

        default:
            break;
    }
}

BSTNode* BSTLinkList::searchData(BSTNode* currentNode, BSTNode* searchNode, int order)
{
    if (!currentNode)
        return nullptr;

    switch (order)
    {
        case PRE_ORDER:
            if (currentNode->getData().isEqual(searchNode->getData()))
                return currentNode;
            else
            {
                searchData(currentNode->getLeft(), searchNode, order);
                searchData(currentNode->getRight(), searchNode, order);
                break;
            }

        case IN_ORDER:
            searchData(currentNode->getLeft(), searchNode, order);

            if (currentNode == searchNode)
                return currentNode;
            else
            {
                searchData(currentNode->getRight(), searchNode, order);
                break;
            }
        case POST_ORDER:
            searchData(currentNode->getLeft(), searchNode, order);
            searchData(currentNode->getRight(), searchNode, order);

            if (currentNode == searchNode)
                return currentNode;
            break;

        default:
            break;
    }
}

BSTNode* BSTLinkList::searchData(BSTNode *currentNode, BSTNode *searchNode)
{
    if (!currentNode || currentNode->getData().isEqual(searchNode->getData()))
        return currentNode;

    if (searchNode->getData().isLarger(currentNode->getData()))
        return searchData(currentNode->getRight(), searchNode);

    else
        return searchData(currentNode->getLeft(), searchNode);


}

BSTNode* BSTLinkList::searchData(BSTNode *currentNode, int searchRawTotal)
{
    if (!currentNode || currentNode->getData().rawTotal() == searchRawTotal)
        return currentNode;

    if (searchRawTotal > currentNode->getData().rawTotal())
        return searchData(currentNode->getRight(), searchRawTotal);

    else
        return searchData(currentNode->getLeft(), searchRawTotal);

}


//BSTNode* BSTLinkList::searchDataParent(BSTNode *currentNode, BSTNode *searchNode)
//{
//    if (!currentNode)
//        return nullptr;
//
//    if (searchNode->getData().isLarger(currentNode->getData()))
//    {
//        if (currentNode->getRight() && currentNode->getLeft()->getData().isEqual(searchNode->getData()))
//            ret
//    }
//
//    if (searchNode->getData().isLarger(currentNode->getData()))
//        return searchData(currentNode->getRight(), searchNode);
//
//    else
//        return searchData(currentNode->getLeft(), searchNode);
//
//
//}


//void BSTLinkList::deleteData(BSTNode *deleteNode)
//{
//    BSTNode* foundData = searchData(root, deleteNode);
//
//    if (foundData)
//    {
//
//        if (!foundData->getLeft() && !foundData)
//    }
//}



//void BSTLinkList::deleteData(BSTNode* currentNode, BSTNode* deleteNode)
//{
//    BSTNode* foundData = searchData(root, deleteNode);
//
//    if (foundData)
//    {
//
//        if (!foundData->getLeft() && !foundData)
//    }
//}

bool BSTLinkList::deleteData(BSTNode* currentNode, int searchRawTotal)
{
    auto isLeaf = [](BSTNode* node)->bool { return (!node->getLeft() && !node->getRight()); };
    auto hasTwoChildren = [](BSTNode* node)->bool { return (node->getLeft() && node->getRight()); };
    auto oneChild = [](BSTNode* node)->BSTNode* {
            return node->getLeft() ? node->getLeft() : node->getRight();
        };
    BSTNode* nodeToDelete;

    if (searchRawTotal < currentNode->getData().rawTotal()) // if node we're searching for is smaller than current
    {
        if (currentNode->getLeft())
        {
            if (currentNode->getLeft()->getData().rawTotal() == searchRawTotal) // if left child of current is the target to delete
            {
                nodeToDelete = currentNode->getLeft();

                if (isLeaf(nodeToDelete)) // if left has no children
                {
                    delete nodeToDelete;
                    currentNode->setLeft(nullptr);
                    return true;
                }
                else // at least one child
                {
                    if (hasTwoChildren(nodeToDelete)) // if both children
                    {
                        BSTNode* tempLeft = nodeToDelete->getLeft();  // make temp nodes of both children
                        BSTNode* tempRight = nodeToDelete->getRight();
                        delete nodeToDelete;
                        currentNode->setLeft(tempRight); // set the larger branch to the left

                        BSTNode* tempCurrent = currentNode->getLeft(); // travel down the branch left, locating the smallest leaf node
                        while (tempCurrent->getLeft())
                        {
                            tempCurrent = tempCurrent->getLeft();
                        }
                        tempCurrent->setLeft(tempLeft); // once found, reassign original left to rejoin all
                        return true;
                    }
                    else // if only one child
                    {
                        BSTNode* tempNode = oneChild(nodeToDelete); // get the one child (either left or right)
                        delete nodeToDelete;
                        currentNode->setLeft(tempNode); // simply bridge path since we don't have to resolve the existence of left and right child of delete node
                        return true;
                    }
                }
            }
            else
            {
                return deleteData(currentNode->getLeft(), searchRawTotal); // go down one to the left and rerun
            }
        }

        else // search total smaller than current but no left child, so we know the node to delete is NOT present
        {
            return false;
        }
    }
    else if (searchRawTotal > currentNode->getData().rawTotal()) // if node we're searching for is larger than current
    {
        if (currentNode->getRight())
        {
            if (currentNode->getRight()->getData().rawTotal() == searchRawTotal)
            {
                nodeToDelete = currentNode->getRight();

                if (isLeaf(nodeToDelete)) // if right has no children
                {
                    delete nodeToDelete;
                    currentNode->setRight(nullptr);
                    return true;
                }
                else // at least one child
                {
                    if (hasTwoChildren(nodeToDelete)) // if both children
                    {
                        BSTNode* tempLeft = nodeToDelete->getLeft();  // make temp nodes of both children
                        BSTNode* tempRight = nodeToDelete->getRight();
                        delete nodeToDelete;
                        currentNode->setRight(tempLeft); // set the smaller branch to the right

                        BSTNode* tempCurrent = currentNode->getRight(); // travel down the branch right, locating the first unoccupied right child
                        while (tempCurrent->getRight())
                        {
                            tempCurrent = tempCurrent->getRight();
                        }
                        tempCurrent->setRight(tempRight); // once found, reassign original right branch to rejoin all
                        return true;
                    }
                    else // if only one child
                    {
                        BSTNode* tempNode = oneChild(nodeToDelete); // get the one child (either left or right)
                        delete nodeToDelete;
                        currentNode->setRight(tempNode); // simply bridge path since we don't have to resolve the existence of left and right child of delete node
                        return true;
                    }
                }
            }
            else
            {
                return deleteData(currentNode->getRight(), searchRawTotal);
            }
        }

        else // search total larger than current but no right child, so we know the node to delete is NOT present
        {
            return false;
        }
    }

    else // this should only trigger in the first go-through of this function if the node to delete is the root of the tree
    {
        throw std::invalid_argument("Cannot delete root node");
    }

}