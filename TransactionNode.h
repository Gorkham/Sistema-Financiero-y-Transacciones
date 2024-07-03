#pragma once

#include "Transaction.cpp"
#include <iostream>

using namespace std;

class TransactionNode {

    private:

    Transaction* transaction;
    TransactionNode* left;
    TransactionNode* right;
    int height;


    public:

    TransactionNode(Transaction* transaction);
    ~TransactionNode();
    
    int getHeight();
    void setHeight(int mum);
    TransactionNode* getLeft();
    TransactionNode* getRight();
    void setLeft(TransactionNode* left);
    void setRight(TransactionNode* right);
    Transaction* getTransaction();
    void setTransaction(Transaction* transaction);

};