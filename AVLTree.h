#pragma once

#include <iostream>

#include "TransactionNode.cpp"

using namespace std;

class AVLTree {

    private:

    TransactionNode* root;

    int height(TransactionNode* transaction);
    int max(int num1, int num2);
    TransactionNode* rightRotation(TransactionNode* node1);
    TransactionNode* leftRotation(TransactionNode* node2);
    int getBalance(TransactionNode* node);
    TransactionNode* insertNode(TransactionNode* node, Transaction* transaccion);
    TransactionNode* eliminateNode(TransactionNode* root, int id);
    TransactionNode* minNodeValue(TransactionNode* node);
    TransactionNode* searchNode(TransactionNode* node, int id);
    void IRD(TransactionNode* node);

    public:

    AVLTree(TransactionNode*);
    void insert(Transaction* transaction);
    void eliminate(int id);
    Transaction* search(int id);
    void printIRD();

};