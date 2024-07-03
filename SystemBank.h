#pragma once

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

#include "Transaction.cpp"
#include "TransactionNode.cpp"
#include "AVLTree.cpp"

using namespace std;

class SystemBank {

    private:

    AVLTree treeAVL;
    void saveTransaction();

    public:

    SystemBank();

    void menu();

    void printTransactions();



};