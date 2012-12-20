
#include "tree.h"

using namespace std;

Tree::Tree() {
    root = NULL;
    cout << "Created a nice tree." << endl;
}

void Tree::insert(int num) {
    cout << "Inserting number: " << num << endl;
    if (root == NULL) {
        root = new Node(num);
        cout << "Made a root node whose data is " << root->data << endl;
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
