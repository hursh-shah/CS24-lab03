// intbst.cpp
// Implements class IntBST
// Hursh Shah, 1/30/26

#include "intbst.h"

#include <iostream>
using std::cout;

// constructor sets up empty tree
IntBST::IntBST() { 
    root = NULL;
}

// destructor deletes all nodes
IntBST::~IntBST() {
    clear(root);
}

// recursive helper for destructor
void IntBST::clear(Node *n) {
    if (n == NULL) {
        return;
    }
    clear(n->left);
    clear(n->right);
    delete n;
}

// insert value in tree; return false if duplicate
bool IntBST::insert(int value) {
    if (root == NULL) {
        root = new Node(value);
        return true;
    }
    return insert(value, root);
}

// recursive helper for insert (assumes n is never 0)
bool IntBST::insert(int value, Node *n) {
    if (value == n->info) {
        return false;
    }
    if (value < n->info) {
        if (n->left == NULL) {
            n->left = new Node(value);
            n->left->parent = n;
            return true;
        }
        return insert(value, n->left);
    } else {
        if (n->right == NULL) {
            n->right = new Node(value);
            n->right->parent = n;
            return true;
        }
        return insert(value, n->right);
    }
}

// print tree data pre-order
void IntBST::printPreOrder() const {
    printPreOrder(root);
}

// recursive helper for printPreOrder()
void IntBST::printPreOrder(Node *n) const {
    if (n == NULL) {
        return;
    }
    cout << n->info << " ";
    printPreOrder(n->left);
    printPreOrder(n->right);
}

// print tree data in-order, with helper
void IntBST::printInOrder() const {
    printInOrder(root);
}
void IntBST::printInOrder(Node *n) const {
    if (n == NULL) {
        return;
    }
    printInOrder(n->left);
    cout << n->info << " ";
    printInOrder(n->right);
}

// prints tree data post-order, with helper
void IntBST::printPostOrder() const {
    printPostOrder(root);
}

void IntBST::printPostOrder(Node *n) const {
    if (n == NULL) {
        return;
    }
    printPostOrder(n->left);
    printPostOrder(n->right);
    cout << n->info << " ";
}

// return sum of values in tree
int IntBST::sum() const {
    return sum(root);
}

// recursive helper for sum
int IntBST::sum(Node *n) const {
    if (n == NULL) {
        return 0;
    }
    return n->info + sum(n->left) + sum(n->right);
}

// return count of values
int IntBST::count() const {
    return count(root);
}

// recursive helper for count
int IntBST::count(Node *n) const {
    if (n == NULL) {
        return 0;
    }
    return 1 + count(n->left) + count(n->right);
}

// IMPLEMENT THIS FIRST: returns the node for a given value or NULL if none exists
// Parameters:
// int value: the value to be found
// Node* n: the node to start with (for a recursive call)
// Whenever you call this method from somewhere else, pass it
// the root node as "n"
IntBST::Node* IntBST::getNodeFor(int value, Node* n) const{
    if (n == NULL) {
        return NULL;
    }
    if (value == n->info) {
        return n;
    }
    if (value < n->info) {
        return getNodeFor(value, n->left);
    }
    return getNodeFor(value, n->right);
}

// returns true if value is in the tree; false if not
bool IntBST::contains(int value) const {
    return getNodeFor(value, root) != NULL;
}

// returns the Node containing the predecessor of the given value
IntBST::Node* IntBST::getPredecessorNode(int value) const{
    Node* n = getNodeFor(value, root);
    if (n == NULL) {
        return NULL;
    }
    if (n->left != NULL) {
        n = n->left;
        while (n->right != NULL) {
            n = n->right;
        }
        return n;
    }
    Node* p = n->parent;
    while (p != NULL && n == p->left) {
        n = p;
        p = p->parent;
    }
    return p;
}

// returns the predecessor value of the given value or 0 if there is none
int IntBST::getPredecessor(int value) const{
    Node* n = getPredecessorNode(value);
    if (n == NULL) {
        return 0;
    }
    return n->info;
}

// returns the Node containing the successor of the given value
IntBST::Node* IntBST::getSuccessorNode(int value) const{
    Node* n = getNodeFor(value, root);
    if (n == NULL) {
        return NULL;
    }
    if (n->right != NULL) {
        n = n->right;
        while (n->left != NULL) {
            n = n->left;
        }
        return n;
    }
    Node* p = n->parent;
    while (p != NULL && n == p->right) {
        n = p;
        p = p->parent;
    }
    return p;
}

// returns the successor value of the given value or 0 if there is none
int IntBST::getSuccessor(int value) const{
    Node* n = getSuccessorNode(value);
    if (n == NULL) {
        return 0;
    }
    return n->info;
}

// deletes the Node containing the given value from the tree
// returns true if the node exist and was deleted or false if the node does not exist
bool IntBST::remove(int value){
    Node* n = getNodeFor(value, root);
    if (n == NULL) {
        return false;
    }
    
    if (n->left == NULL && n->right == NULL) {
        if (n == root) {
            root = NULL;
        } else if (n->parent->left == n) {
            n->parent->left = NULL;
        } else {
            n->parent->right = NULL;
        }
        delete n;
        return true;
    }
    
    if (n->left == NULL || n->right == NULL) {
        Node* child;
        if (n->left != NULL) {
            child = n->left;
        } else {
            child = n->right;
        }
        if (n == root) {
            root = child;
            child->parent = NULL;
        } else if (n->parent->left == n) {
            n->parent->left = child;
            child->parent = n->parent;
        } else {
            n->parent->right = child;
            child->parent = n->parent;
        }
        delete n;
        return true;
    }
    
    Node* succ = getSuccessorNode(value);
    int succValue = succ->info;
    remove(succValue);
    n->info = succValue;
    return true;
}
