#ifndef __cpp__tree__
#define __cpp__tree__

#include <iostream>

class Node {
public:
    Node* left;
    Node* right;
    int data;
    Node* find(int num);
    void insert(int num);
    Node(int num);
    ~Node();
};

class Tree {
    Node* root;
public:
    Tree();
    void insert(int num);
    bool contains(int num);
};


#endif /* defined(__cpp__tree__) */
