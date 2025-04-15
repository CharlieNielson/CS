//#pragma once
#include <iostream>
#include <memory>
using namespace std;

struct Node {
    Node(int data): data(data), left(nullptr), right(nullptr) {}
    int data;
    shared_ptr<Node> left;
    shared_ptr<Node> right;
};

class BTree {
public:
    BTree(): root(nullptr) {}
    BTree(const BTree&);
    BTree& operator=(const BTree&);
    void insert(const int& item);
    void preOrder();
    void inOrder();
    void postOrder();

private:
    void preOrder(shared_ptr<Node> ptr);
    void inOrder(shared_ptr<Node> ptr);
    void postOrder(shared_ptr<Node> ptr);
    void insert(const int& item, shared_ptr<Node> ptr);
    shared_ptr<Node> root;
};

void BTree::insert(const int& item, shared_ptr<Node> ptr) {
    if (item < ptr->data) {
        if (ptr->left == nullptr) {
            ptr->left = make_shared<Node>(item);
        } else {
            insert(item, ptr->left);
        }
    } else {
        if (ptr->right == nullptr) {
            ptr->right = make_shared<Node>(item);
        } else {
            insert(item, ptr->right);
        }
    }
}

void BTree::preOrder() {
    preOrder(root);
}

void BTree::preOrder(shared_ptr<Node> ptr) {
    if (ptr) {
        cout << ptr->data << " ";
        preOrder(ptr->left);
        preOrder(ptr->right);
    }
}

void BTree::inOrder() {
    inOrder(root);
}

void BTree::inOrder(shared_ptr<Node> ptr) {
    if (ptr) {
        preOrder(ptr->left);
        cout << ptr->data << " ";
        preOrder(ptr->right);
    }
}

void BTree::postOrder() {
    postOrder(root);
}

void BTree::postOrder(shared_ptr<Node> ptr) {
    if (ptr) {
        preOrder(ptr->left);
        preOrder(ptr->right);
        cout << ptr->data << " ";
    }
}



int main() {
    



    return 0;
}
