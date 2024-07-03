#pragma once

#include "TransactionNode.h"
#include <iostream>

using namespace std;

TransactionNode::TransactionNode(Transaction* transaction) {

    this->transaction = transaction;
    this->left = NULL;
    this->right = NULL;
    this->height = 1;

}

TransactionNode::~TransactionNode(){ delete transaction; }

int TransactionNode::getHeight() { return this->height; }

void TransactionNode::setHeight(int num) { this->height = num; }

TransactionNode* TransactionNode::getLeft() { return left; }

TransactionNode* TransactionNode::getRight() { return right; }

void TransactionNode::setLeft(TransactionNode* left) { this->left = left; }

void TransactionNode::setRight(TransactionNode* right) { this->right = right; }

Transaction* TransactionNode::getTransaction() { return transaction; }

void TransactionNode::setTransaction(Transaction* transaction) { this->transaction = transaction; }