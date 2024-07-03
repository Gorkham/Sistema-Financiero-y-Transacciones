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

int Transaction::getId() {
    return id;
}

int Transaction::getSourceAccount() {
    return SourceAccount;
}

int Transaction::getDestinationAccount() {
    return DestinationAccount;
}

int Transaction::getAmount() {
    return Amount;
}

string Transaction::getGeographicLocation() {
    return GeographicLocation;
}

string Transaction::getDate() {
    return date;
}

string Transaction::getHour() {
    return hour;
}

// Setter implementations
void Transaction::setId(int id) {
    this->id = id;
}

void Transaction::setSourceAccount(int SourceAccount) {
    this->SourceAccount = SourceAccount;
}

void Transaction::setDestinationAccount(int DestinationAccount) {
    this->DestinationAccount = DestinationAccount;
}

void Transaction::setAmount(int Amount) {
    this->Amount = Amount;
}

void Transaction::setGeographicLocation(string GeographicLocation) {
    this->GeographicLocation = GeographicLocation;
}

void Transaction::setDate(string date) {
    this->date = date;
}

void Transaction::setHour(string hour) {
    this->hour = hour;
}