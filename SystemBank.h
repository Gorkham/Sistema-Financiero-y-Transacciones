#pragma once

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

#include "Transaction.cpp"
#include "TransactionNode.cpp"

using namespace std;

class SystemBank {

    private:

    vector<TransactionNode> listTransaction;
    void saveTransaction();

    public:

    SystemBank();

    void menu();



};