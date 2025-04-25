// intbst.cpp
// Implements class IntBST
// YOUR NAME(S), DATE

#include "intbst.h"

#include <iostream>
using std::cout;

// constructor sets up empty tree
IntBST::IntBST() { 
    root = nullptr;
}

// destructor deletes all nodes
IntBST::~IntBST() {
    clear(root);
}

// recursive helper for destructor
void IntBST::clear(Node *n) {
    if (n==nullptr){
        return;
    }
    clear(n->left);
    clear(n->right);
    delete n;
}

// insert value in tree; return false if duplicate
bool IntBST::insert(int value) {
    if (root == nullptr) {
        root = new Node(value);
        root->parent = nullptr;
        return true;
    }
    else {
        return insert(value, root);
    }
}

// recursive helper for insert (assumes n is never 0)
bool IntBST::insert(int value, Node *n) {
    if (value == n->info) {
        return false;
    }
    if (value < n->info) {
        if (n->left == nullptr){
            n->left = new Node(value);
            n->left->parent = n;
            return true;
        }
        else {
            return insert(value, n->left);
        }
    }
    else {
        if (n->right == nullptr) {
            n->right = new Node(value);
            n->right->parent = n;
            return true;
        }
        else {
            return insert(value, n->right);
        }
    }
}

// print tree data pre-order
void IntBST::printPreOrder() const {
    printPreOrder(root); // IMPLEMENT HERE
}

// recursive helper for printPreOrder()
void IntBST::printPreOrder(Node *n) const {
    if (n == nullptr) {
        return;
    }
    cout<<n->info<<" ";
    printPreOrder(n->left);
    printPreOrder(n->right);
}

// print tree data in-order, with helper
void IntBST::printInOrder() const {
    printInOrder(root);
}
void IntBST::printInOrder(Node *n) const {
    if (n == nullptr) {
        return;
    }
    printInOrder(n->left);
    cout<<n->info<<" ";
    printInOrder(n->right);
}

// prints tree data post-order, with helper
void IntBST::printPostOrder() const {
    printPostOrder(root);
}

void IntBST::printPostOrder(Node *n) const {
    if (n==nullptr) {
        return;
    }
    printPostOrder(n->left);
    printPostOrder(n->right);
    cout<<n->info<<" ";
}

// return sum of values in tree
int IntBST::sum() const {
    return sum(root);
}

// recursive helper for sum
int IntBST::sum(Node *n) const {
    if (n == nullptr){
        return 0;
    }
    return n->info + sum(n->left) + sum (n->right);
    ;
}

// return count of values
int IntBST::count() const {
    return count(root);
}

// recursive helper for count
int IntBST::count(Node *n) const {
    if (n == nullptr){
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
    if (n == nullptr) {
        return nullptr;
    }
    if (value == n->info) {
        return n;
    }
    if (value < n->info) {
        if (n->left != nullptr){
            return getNodeFor(value, n->left);
        }
        else {
            return nullptr;
        }
    }
    else {
        if (n->right != nullptr){
            return getNodeFor(value, n->right);
        }
        else {
            return nullptr;
        }
    }
}

// returns true if value is in the tree; false if not
bool IntBST::contains(int value) const {
    if (getNodeFor(value, root)!=nullptr) {
        return true;
    }
    return false;
}

// returns the Node containing the predecessor of the given value
IntBST::Node* IntBST::getPredecessorNode(int value) const{
    Node* curr = getNodeFor(value, root);
    if (curr == nullptr) {
        return nullptr;
    }
    if (curr->left != nullptr){
        curr = curr->left;
        while (curr->right!=nullptr){
            curr = curr->right;
        }
        return curr;
    }
    else {
        Node* parent = curr->parent;
        while (parent != nullptr && curr == parent->left) {
            curr = parent;
            parent = parent->parent;
        }
        return parent;
    }
    
}

// returns the predecessor value of the given value or 0 if there is none
int IntBST::getPredecessor(int value) const{
    if (IntBST::getPredecessorNode(value) == nullptr){
        return 0;
    }
    else {
        return IntBST::getPredecessorNode(value)->info;
    }
}

// returns the Node containing the successor of the given value
IntBST::Node* IntBST::getSuccessorNode(int value) const{
    Node* curr = getNodeFor(value, root);
    if (curr == nullptr) {
        return nullptr;
    }
    if (curr->right != nullptr){
        curr = curr->right;
        while (curr->left!=nullptr){
            curr = curr->left;
        }
        return curr;
    }
    else {
        Node* parent = curr->parent;
        while (parent != nullptr && curr == parent->right) {
            curr = parent;
            parent = parent->parent;
        }
        return parent;
    }
    
}


// returns the successor value of the given value or 0 if there is none
int IntBST::getSuccessor(int value) const{
    if (IntBST::getSuccessorNode(value) == nullptr){
        return 0;
    }
    else {
        return IntBST::getSuccessorNode(value)->info;
    }
}

// deletes the Node containing the given value from the tree
// returns true if the node exist and was deleted or false if the node does not exist
bool IntBST::remove(int value){
    if (IntBST::contains(value) == false) {
        return false;
    }
    Node* n = getNodeFor(value, root);

    if (n->right == nullptr && n->left == nullptr) {
        if (n->parent == nullptr) {
            root = nullptr;
            delete n;
            return true;
        }
        if (n->parent->right == n) {
            n->parent->right = nullptr;
            delete n;
            return true;
        }
        if (n->parent->left == n) {
            n->parent->left = nullptr;
            delete n;
            return true;
        }
    }
    if (n->right == nullptr) {
        if (n->parent == nullptr) {
            root = n->left;
            root->parent=nullptr;
            delete n;
            return true;
        }
        if (n->parent->right == n) {
            n->parent->right = n->left;
            n->left->parent = n->parent;
            delete n;
            return true;
        }
        if (n->parent->left == n) {
            n->parent->left = n->right;
            n->right->parent = n->parent;
            delete n;
            return true;
        }
        //predecessor of deletd node=swap value,one node tree, leaf node, one child, two children
    }
    if (n->left == nullptr) {
        if (n->parent == nullptr) {
            root = n->right;
            root->parent=nullptr;
            delete n;
            return true;
        }
        if (n->parent->left == n) {
            n->parent->left = n->left;
            n->right->parent = n->parent;
            delete n;
            return true;
        }
        if (n->parent->right == n) {
            n->parent->right = n->left;
            n->left->parent = n->parent;
            delete n;
            return true;
        }
    }

    if (n->left != nullptr && n->right != nullptr) {
        int successor_val = getSuccessor(value);
        Node* successor_node = getSuccessorNode(value);
        if (n->parent == nullptr) {
            int temp = root->info;
            root->info = successor_val;
            successor_node->info = temp; //switched w node
            if (successor_node == successor_node->parent->right){
                successor_node->parent->right = nullptr;
            }
            else{
                successor_node->parent->left = nullptr;
            }
            delete successor_node;
            return true;
        }
        if (n->parent->left == n) {
            int temp = n->info;
            n->info = successor_val;
            successor_node->info = temp;
            n->parent->left = nullptr;
            delete successor_node;
            return true;
        }
        if (n->parent->right == n) {
            int temp = n->info;
            n->info = successor_val;
            successor_node->info = temp;
            n->parent->right = nullptr;
            delete successor_node;
            return true;
        }
    }
}
