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

    // Getters
    int getId();
    int getSourceAccount();
    int getDestinationAccount();
    int getAmount();
    string getGeographicLocation();
    string getDate();
    string getHour();

    // Setters
    void setId(int id);
    void setSourceAccount(int SourceAccount);
    void setDestinationAccount(int DestinationAccount);
    void setAmount(int Amount);
    void setGeographicLocation(string GeographicLocation);
    void setDate(string date);
    void setHour(string hour);

};