//#pragma once
#include <iostream>
#include <memory>
using namespace std;

struct Node {
  Node(int data): data(data), left(nullptr), right(nullptr) {}
  int data;
  shared_ptr<Node<int>> left;
  shared_ptr<Node<int>> right;
};

class BTree {
public:
  BTree(): root(nullptr) {}
  BTree(const BTree<int>&);
  BTree<int>& operator=(const BTree<int>&);
  void insert(const int& item);
  void preOrder();
  void inOrder();
  void postOrder();

private:
  void preOrder(shared_ptr<Node<int>> ptr);
  void inOrder(shared_ptr<Node<int>> ptr);
  void postOrder(shared_ptr<Node<int>> ptr);
  void insert(const int& item, shared_ptr<Node<int>> ptr
};

void BTree<int>::insert(const int& item, shared_ptr<Node<int>> ptr) {
  if (item < ptr->data) {
    if (ptr->left == nullptr) {
      ptr->left = make_shared<Node<int>>(item);
    } else {
      insert(item, ptr->left);
    }
  } else {
    if (ptr->right == nullptr) {
      ptr->right = make_shared<Node<int>>(item);
    } else {
      insert(item, ptr->right);
    }
  }
}

void BTree<int>::preOrder() {
  preOrder(root);
}

void BTree<int>::preOrder(shared_ptr<Node<int>> ptr) {
  if (ptr) {
    cout << ptr->data << " ";
    preOrder(ptr->left);
    preOrder(ptr->right);
  }
}

void BTree<int>::inOrder() {
  inOrder(root);
}

void BTree<int>::inOrder(shared_ptr<Node<int>> ptr) {
  if (ptr) {
    preOrder(ptr->left);
    cout << ptr->data << " ";
    preOrder(ptr->right);
  }
}

void BTree<int>::postOrder() {
  postOrder(root);
}

void BTree<int>::postOrder(shared_ptr<Node<int>> ptr) {
  if (ptr) {
    preOrder(ptr->left);
    preOrder(ptr->right);
    cout << ptr->data << " ";
  }
}
