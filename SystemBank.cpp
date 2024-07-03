#pragma once

#include "SystemBank.h"

SystemBank::SystemBank() {

    
    this->saveTransaction();

}

void SystemBank::saveTransaction() {
    // Abriendo el archivo
    ifstream arch("transaction.txt");

    // Verificación del archivo
    if (!arch.is_open()) {
        cout << "No se ha logrado encontrar el archivo :(" << endl;
        return;
    }

    string line;
    string part;
    vector<string> parts;

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

        if (parts.size() == 7) {
            id = stoi(parts[0]);
            SourceAccount = stoi(parts[1]);
            DestinationAccount = stoi(parts[2]);
            Amount = stoi(parts[3]);
            GeographicLocation = parts[4];
            date = parts[5];
            hour = parts[6];

            // Crear la transacción
            Transaction* transaction = new Transaction(id, SourceAccount, DestinationAccount, Amount, GeographicLocation, date, hour);

            // Insertar la transacción en el árbol AVL
            treeAVL.insert(transaction);
        }

        parts.clear();
    }
}

void SystemBank::menu() {

    cout << "menu" << endl;
}

void SystemBank::printTransactions() {
    treeAVL.printIRD();
}