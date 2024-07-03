#pragma once

#include "Transaction.h"
#include <iostream>

using namespace std;

Transaction::Transaction(int id,int SourceAccount,int DestinationAccount,int Amount,string GeographicLocation,string date,string hour) {

    this->id = id;
    this->SourceAccount = SourceAccount;
    this->DestinationAccount = DestinationAccount;
    this->Amount = Amount;
    this->GeographicLocation = GeographicLocation;
    this->date = date;
    this->hour = hour;

}

Transaction::~Transaction(){}