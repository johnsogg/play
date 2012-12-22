
#include "tree.h"
#include <iostream>

using namespace std;

Tree::Tree() {
    root = NULL;
}

void Tree::insert(int num) {
    if (root == NULL) {
        root = new Node(num);
    } else {
        root->insert(num);
    }
}

bool Tree::contains(int num) {
    bool ret = false;
    if (root != NULL) {
        Node* node = root->find(num);
        if (node != NULL) {
            ret = true;
        }
    }
    return ret;
}

int Tree::size() {
  int ret = 0;
  if (root != NULL) {
    ret = root->size();
  }
  return ret;
}

Node* Node::find(int num) {
    Node* ret;
    if (data == num) {
        ret = this;
    } else if (data > num) {
        if (left == NULL) {
            left = new Node(num);
        } else {
            left->insert(num);
        }
        ret = left;
    } else {
        if (right == NULL) {
            right = new Node(num);
        } else {
            right->insert(num);
        }
        ret = right;
    }
    return ret;
}

Node::Node(int num) {
  data = num;
  left = NULL;
  right = NULL;
}

void Node::insert(int num) {
    if (data > num) {
        if (left == NULL) {
            left = new Node(num);
        } else {
            left->insert(num);
        }
    }
    else {
        if (right == NULL) {
            right = new Node(num);
        } else {
            right->insert(num);
        }
    }
}

int Node::size() {
  int ret = 1; // for myself
  if (this->left != NULL) {
    ret = ret + left->size();
  }
  if (right != NULL) {
    ret = ret + right->size();
  }
  return ret;
}
