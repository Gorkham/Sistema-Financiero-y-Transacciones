#pragma once

#include "Transaction.cpp"
#include <iostream>

using namespace std;

class TransactionNode {

    private:

    Transaction* transaction;
    TransactionNode* left;
    TransactionNode* right;


    public:

    TransactionNode(Transaction* transaction);
    ~TransactionNode();

};