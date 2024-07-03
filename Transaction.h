#pragma once

#include <iostream>

using namespace std;

class Transaction {

    private:

    int id;
    int SourceAccount;
    int DestinationAccount;
    int Amount;
    string GeographicLocation;
    string date;
    string hour;

    public:

    Transaction(int,int,int,int,string,string,string);
    ~Transaction();

    int getId() {
        return id;
    }

};