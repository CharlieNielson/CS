#pragma once
#include <iostream>
#include <memory>
using namespace std;

template <typename T>
struct Node {
  Node(T data): data(data), left(nullptr), right(nullptr) {}
  T data;
  shared_ptr<Node<T>> left;
  shared_ptr<Node<T>> right;
};

template <typename T>
class BTree {
public:
  BTree(): root(nullptr) {}
  BTree(const BTree<T>&);
  BTree<T>& operator=(const BTree<T>&);
  void insert(const T& item);
  void remove(const T& item);
  void preOrder();
  void inOrder();
  void postOrder();
  int nodeCount();
  int leavesCount();

  shared_ptr<Node<T>> find(const T& item);
  shared_ptr<Node<T>> findRightMostNode(shared_ptr<Node<T>> ptr);
  shared_ptr<Node<T>> findLeftMostNode(shared_ptr<Node<T>> ptr);
  shared_ptr<Node<T>> findParent(shared_ptr<Node<T>> ptr);

private:
  void preOrder(shared_ptr<Node<T>> ptr);
  void inOrder(shared_ptr<Node<T>> ptr);
  void postOrder(shared_ptr<Node<T>> ptr);
  void insert(const T& item, shared_ptr<Node<T>> ptr);
  void remove(const T& item, shared_ptr<Node<T>> ptr);
  shared_ptr<Node<T>> find(const T& item, shared_ptr<Node<T>> ptr);
  shared_ptr<Node<T>> findParent(shared_ptr<Node<T>> ptr, shared_ptr<Node<T>> parent);
  int nodeCount(shared_ptr<Node<T>> ptr);
  int leavesCount(shared_ptr<Node<T>> ptr);
  shared_ptr<Node<T>> copyNode(shared_ptr<Node<T>> ptr);
  shared_ptr<Node<T>> root;
};

template<typename T>
shared_ptr<Node<T>> BTree<T>::find(const T& item) {
  return find(item, root);
}

template<typename T>
shared_ptr<Node<T>> BTree<T>::find(const T& item, shared_ptr<Node<T>> ptr) {
  cout << item << ", " << ptr->data << endl;
  if (item == ptr->data) {
    return ptr;
  }
  if (item < ptr->data && ptr->left != nullptr) {
    return find(item, ptr->left);
  } else if (ptr->right != nullptr) {
    return find(item, ptr->right);
  }
  return ptr;
}

template<typename T>
shared_ptr<Node<T>> BTree<T>::findRightMostNode(shared_ptr<Node<T>> ptr) {
  if (ptr->right == nullptr) {
    return ptr;
  } else {
    return findRightMostNode(ptr->right);
  }
}

template<typename T>
shared_ptr<Node<T>> BTree<T>::findLeftMostNode(shared_ptr<Node<T>> ptr) {
  if (ptr->left == nullptr) {
    return ptr;
  } else {
    return findRightMostNode(ptr->left);
  }
}

template<typename T>
shared_ptr<Node<T>> BTree<T>::findParent(shared_ptr<Node<T>> ptr) {
  return findParent(ptr, root);
}

template<typename T>
shared_ptr<Node<T>> BTree<T>::findParent(shared_ptr<Node<T>> ptr, shared_ptr<Node<T>> parent) {
  if (parent->left == ptr || parent->right == ptr) {
    return parent;
  }
  if (ptr->data < parent->data) {
    return findParent(ptr, parent->left);
  } else {
    return findParent(ptr, parent->right);
  }
}

template<typename T>
void BTree<T>::remove(const T& item) {
  if (root == nullptr) {
    return;
  }
  remove(item, root);
}

template<typename T>
void BTree<T>::remove(const T& item, shared_ptr<Node<T>> ptr) {
  if (ptr->data == item) {
    if (ptr->left == nullptr && ptr->right == nullptr) {
      if (item < findParent(ptr)->data) {
        findParent(ptr)->left = nullptr;
      } else {
        findParent(ptr)->right = nullptr;
      }
    } else if (ptr->left == nullptr || ptr->right == nullptr) {
      if (ptr->left == nullptr) {
        ptr = ptr->right;
      } else {
        ptr = ptr->left
      }
    } else {
      T temp = findLeftMostNode(ptr->right);
      remove(temp);
      ptr->data = temp;
    }
    return;
  }
  if (item < ptr->data) {
    remove(item, ptr->left);
  } else {
    remove(item, ptr->right);
  }
}

//divider

template<typename T>
shared_ptr<Node<T>> BTree<T>::copyNode(shared_ptr<Node<T>> ptr) {
  if (ptr == nullptr) {
    return nullptr;
  }
  auto copy = make_shared<Node<T>>(ptr->data);
  ptr->left = copyNode(ptr->left);
  ptr->right = copyNode(ptr->right);
  return copy;
}

template<typename T>
BTree<T>::BTree(const BTree<T>& ptr) {
  root = copyNode(ptr.root);
}

template<typename T>
BTree<T>& BTree<T>::operator=(const BTree<T>&) {
  return BTree(*this);
}

template<typename T>
void BTree<T>::insert(const T& item) {
  if (root == nullptr) {
    root = make_shared<Node<T>>(item);
  } else {
    insert(item, root);
  }
}

template<typename T>
void BTree<T>::insert(const T& item, shared_ptr<Node<T>> ptr) {
  if (item < ptr->data) {
    if (ptr->left == nullptr) {
      ptr->left = make_shared<Node<T>>(item);
    } else {
      insert(item, ptr->left);
    }
  } else {
    if (ptr->right == nullptr) {
      ptr->right = make_shared<Node<T>>(item);
    } else {
      insert(item, ptr->right);
    }
  }
}

template<typename T>
void BTree<T>::preOrder() {
  preOrder(root);
}

template<typename T>
void BTree<T>::preOrder(shared_ptr<Node<T>> ptr) {
  if (ptr) {
    cout << ptr->data << " ";
    preOrder(ptr->left);
    preOrder(ptr->right);
  }
}

template<typename T>
void BTree<T>::inOrder() {
  inOrder(root);
}

template<typename T>
void BTree<T>::inOrder(shared_ptr<Node<T>> ptr) {
  if (ptr) {
    preOrder(ptr->left);
    cout << ptr->data << " ";
    preOrder(ptr->right);
  }
}

template<typename T>
void BTree<T>::postOrder() {
  postOrder(root);
}

template<typename T>
void BTree<T>::postOrder(shared_ptr<Node<T>> ptr) {
  if (ptr) {
    preOrder(ptr->left);
    preOrder(ptr->right);
    cout << ptr->data << " ";
  }
}

template<typename T>
int BTree<T>::nodeCount() {
  return nodeCount(root);
}

template<typename T>
int BTree<T>::nodeCount(shared_ptr<Node<T>> ptr) {
  int end = 0;
  if (ptr != nullptr) {
    end++;
    end += nodeCount(ptr->left);
    end += nodeCount(ptr->right);
  }
  return end;
}

template<typename T>
int BTree<T>::leavesCount() {
  return leavesCount(root);
}

template<typename T>
int BTree<T>::leavesCount(shared_ptr<Node<T>> ptr) {
  int end = 0;
  if (ptr != nullptr) {
    if (leavesCount(ptr->left) == 0 && leavesCount(ptr->right) == 0) {
      end++;
    }
    end += leavesCount(ptr->left);
    end += leavesCount(ptr->right);
  }
  return end;
}
