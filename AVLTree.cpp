#pragma once

#include <iostream>

#include "AVLTree.h"

using namespace std;

AVLTree::AVLTree(TransactionNode* root) { this->root = root; }

AVLTree::AVLTree() {
    root = nullptr;
}

int AVLTree::height(TransactionNode* node) {
    if (node) {
        return node->getHeight();
    } else {
        return 0;
    }
}

int AVLTree::max(int num1, int num2) {
    if (num1 > num2) {
        return num1;
    } else {
        return num2;
    }
}

TransactionNode* AVLTree::rightRotation(TransactionNode* node1) {
    TransactionNode* node2 = node1->getLeft();
    TransactionNode* T2 = node2->getRight();

    node2->setRight(node1);
    node1->setLeft(T2);

    node1->setHeight(max(height(node1->getLeft()), height(node1->getRight())) + 1);
    node2->setHeight(max(height(node2->getLeft()), height(node2->getRight())) + 1);

    return node2;
}

TransactionNode* AVLTree::leftRotation(TransactionNode* node2) {
    TransactionNode* node1 = node2->getRight();
    TransactionNode* T2 = node1->getLeft();

    node1->setLeft(node2);
    node2->setRight(T2);

    node2->setHeight(max(height(node2->getLeft()), height(node2->getRight())) + 1);
    node1->setHeight(max(height(node1->getLeft()), height(node1->getRight())) + 1);

    return node1;
}

int AVLTree::getBalance(TransactionNode* node) {
    if (node) {
        return height(node->getLeft()) - height(node->getRight());
    } else {
        return 0;
    }
}

TransactionNode* AVLTree::insertNode(TransactionNode* node, Transaction* transaction) {
    if (node == nullptr) {
        return new TransactionNode(transaction);
    }

    if (transaction->getId() < node->getTransaction()->getId()) {
        node->setLeft(insertNode(node->getLeft(), transaction));
    } else if (transaction->getId() > node->getTransaction()->getId()) {
        node->setRight(insertNode(node->getRight(), transaction));
    } else {
        return node; // No se permiten IDs duplicados
    }

    node->setHeight(1 + max(height(node->getLeft()), height(node->getRight())));

    int balance = getBalance(node);

    if (balance > 1 && transaction->getId() < node->getLeft()->getTransaction()->getId()) {
        return rightRotation(node);
    }

    if (balance < -1 && transaction->getId() > node->getRight()->getTransaction()->getId()) {
        return leftRotation(node);
    }

    if (balance > 1 && transaction->getId() > node->getLeft()->getTransaction()->getId()) {
        node->setLeft(leftRotation(node->getLeft()));
        return rightRotation(node);
    }

    if (balance < -1 && transaction->getId() < node->getRight()->getTransaction()->getId()) {
        node->setRight(rightRotation(node->getRight()));
        return leftRotation(node);
    }

    return node;
}

TransactionNode* AVLTree::minNodeValue(TransactionNode* node) {
    TransactionNode* current = node;
    while (current->getLeft() != nullptr) {
        current = current->getLeft();
    }
    return current;
}

TransactionNode* AVLTree::eliminateNode(TransactionNode* root, int id) {
    if (root == nullptr) return root;

    if (id < root->getTransaction()->getId()) {
        root->setLeft(eliminateNode(root->getLeft(), id));
    } else if (id > root->getTransaction()->getId()) {
        root->setRight(eliminateNode(root->getRight(), id));
    } else {
        if ((root->getLeft() == nullptr) || (root->getRight() == nullptr)) {
            TransactionNode* temp = root->getLeft() ? root->getLeft() : root->getRight();
            if (temp == nullptr) {
                temp = root;
                root = nullptr;
            } else {
                *root = *temp;
            }
            delete temp;
        } else {
            TransactionNode* temp = minNodeValue(root->getRight());
            root->setTransaction(temp->getTransaction());
            root->setRight(eliminateNode(root->getRight(), temp->getTransaction()->getId()));
        }
    }

    if (root == nullptr) return root;

    root->setHeight(1 + max(height(root->getLeft()), height(root->getRight())));

    int balance = getBalance(root);

    if (balance > 1 && getBalance(root->getLeft()) >= 0) {
        return rightRotation(root);
    }

    if (balance > 1 && getBalance(root->getLeft()) < 0) {
        root->setLeft(leftRotation(root->getLeft()));
        return rightRotation(root);
    }

    if (balance < -1 && getBalance(root->getRight()) <= 0) {
        return leftRotation(root);
    }

    if (balance < -1 && getBalance(root->getRight()) > 0) {
        root->setRight(rightRotation(root->getRight()));
        return leftRotation(root);
    }

    return root;
}

TransactionNode* AVLTree::searchNode(TransactionNode* node, int id) {
    if (node == nullptr || node->getTransaction()->getId() == id) {
        return node;
    }

    if (node->getTransaction()->getId() < id) {
        return searchNode(node->getRight(), id);
    }

    return searchNode(node->getLeft(), id);
}

void AVLTree::IRD(TransactionNode* node) {
    if (node == nullptr) return;
    IRD(node->getLeft());
    cout << "Transaccion ID: " << node->getTransaction()->getId() << endl;
    IRD(node->getRight());
}

void AVLTree::insert(Transaction* transaction) {
    root = insertNode(root, transaction);
}

void AVLTree::eliminate(int id) {
    root = eliminateNode(root, id);
}

Transaction* AVLTree::search(int id) {
    TransactionNode* result = searchNode(root, id);
    if (result != nullptr) {
        return result->getTransaction();
    } else {
        return nullptr;
    }
}

void AVLTree::printIRD() {
    IRD(root);
}




