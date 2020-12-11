#pragma once
#include <iostream>

namespace tree {
    class Node {
        int data;
    public:
        Node* right;
        Node* left;
        Node(int item) :data{ item } {
            right = left = nullptr;
        }
        int getData() {
            return data;
        }
        void setData(int data) {
            this->data = data;
        }
    };
}



class BinaryTree
{
    tree::Node* root;
public:
    BinaryTree(tree::Node* rootNode): root{rootNode}{}
    void printLevelOrderQueue();
    void printLevelOrderHeightRecursion();
    void insertLevelOrder(int data);
    void deletion(int searchItem);
    void deletionGFG(int searchItem);
    void printInOrderStack();
private:
    void printGivenLevel(tree::Node* ptr, int height);
    int height(tree::Node* ptr);
    tree::Node* findBottomAndRightMost();
    tree::Node* rightMost(tree::Node* ptr, int height);
    void rightMostDeleterGFG(tree::Node* delNode);
};

