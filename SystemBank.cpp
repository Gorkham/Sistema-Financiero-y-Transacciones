#pragma once

#include "SystemBank.h"

SystemBank::SystemBank() {

    
    this->saveTransaction();

}

void SystemBank::saveTransaction() {

    // Opening the file
    ifstream arch("transaction.txt");

    // File verification
    if (!arch.is_open()) {
        cout << "No se ha logrado encontrar el archivo :(" << endl;
        return;
    }

    string line;

    string part;
    vector<string> parts;

    TransactionNode *transaction;

    int id;
    int SourceAccount;
    int DestinationAccount;
    int Amount;
    string GeographicLocation;
    string date;
    string hour;

    while (getline(arch, line)) {

        stringstream ss(line);
        
        while (getline(ss, part, ',')) {

            parts.push_back(part);

        }

        

        id = stoi(parts[0]);
        
        SourceAccount = stoi(parts[1]);
        DestinationAccount = stoi(parts[2]);
        Amount = stoi(parts[3]);
        GeographicLocation = parts[4];
        date = parts[5];
        hour = parts[6];

        TransactionNode* transactionNode = new TransactionNode(*transaction = new Transaction(id,SourceAccount,DestinationAccount,Amount,GeographicLocation,date,hour));

        cout << id << endl;

        parts.clear();

    }
}

void SystemBank::menu() {

    cout << "menu" << endl;
}