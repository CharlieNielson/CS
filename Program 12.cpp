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
    shared_ptr<Node> copyNode(shared_ptr<Node> ptr);
    shared_ptr<Node> root;
    int nodeNumber = 0;
    int nodeNumberCounter = 0;
};


shared_ptr<Node> BTree::copyNode(shared_ptr<Node> ptr) {
    if (ptr == nullptr) {
      return nullptr;
    }
    auto copy = make_shared<Node>(ptr->data);
    ptr->left = copyNode(ptr->left);
    ptr->right = copyNode(ptr->right);
    return copy;
}

BTree::BTree(const BTree& ptr) {
  root = copyNode(ptr.root);
}

/*BTree& BTree::operator=(const BTree&) {
  return BTree(*this);
}*/

void BTree::insert(const int& item) {
    if (root == nullptr) {
        root = make_shared<Node>(item);
    } else {
        insert(item, root);
    }
    nodeNumber++;
}

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
    nodeNumberCounter = 0;
    preOrder(root);
}

void BTree::preOrder(shared_ptr<Node> ptr) {
    if (ptr) {
        nodeNumberCounter++;
        if (nodeNumberCounter < nodeNumber) {
            cout << ptr->data << ", ";
        } else {
            cout << ptr->data << " ";
        }
        preOrder(ptr->left);
        preOrder(ptr->right);
    }
}

void BTree::inOrder() {
    nodeNumberCounter = 0;
    inOrder(root);
}

void BTree::inOrder(shared_ptr<Node> ptr) {
    if (ptr) {
        preOrder(ptr->left);
        nodeNumberCounter++;
        if (nodeNumberCounter < nodeNumber) {
            cout << ptr->data << ", ";
        } else {
            cout << ptr->data << " ";
        }
        preOrder(ptr->right);
    }
}

void BTree::postOrder() {
    nodeNumberCounter = 0;
    postOrder(root);
}

void BTree::postOrder(shared_ptr<Node> ptr) {
    if (ptr) {
        preOrder(ptr->left);
        preOrder(ptr->right);
        nodeNumberCounter++;
        if (nodeNumberCounter < nodeNumber) {
            cout << ptr->data << ", ";
        } else {
            cout << ptr->data << " ";
        }
    }
}



int main() {
    BTree tree;
    cout << "Inserting the values 50, 75, 25, 15, 60, 35, 90, 42, 20, 27, 5, 55, 95, 80 and 70" << endl;
    tree.insert(50);
    tree.insert(75);
    tree.insert(25);
    tree.insert(15);
    tree.insert(60);
    tree.insert(35);
    tree.insert(90);
    tree.insert(42);
    tree.insert(20);
    tree.insert(27);
    tree.insert(5);
    tree.insert(55);
    tree.insert(95);
    tree.insert(80);
    tree.insert(70);

    cout << "Preorder: ";
    tree.preOrder();

    cout << "\nInorder: ";
    tree.inOrder();

    cout << "\nPostorder: ";
    tree.postOrder();
    cout << endl;

    return 0;
}
