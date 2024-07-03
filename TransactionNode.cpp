#pragma once

#include "TransactionNode.h"
#include <iostream>

using namespace std;

TransactionNode::TransactionNode(Transaction* transaction) {

    this->transaction = transaction;

}

TransactionNode::~TransactionNode(){}
