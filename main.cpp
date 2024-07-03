#include <iostream>

#include "SystemBank.cpp"

using namespace std;


int main()
{
    
    SystemBank bank;

    bank.menu();
    bank.printTransactions();
    return 0;
}
