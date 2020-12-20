#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
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
    static int curr;
public:
    BinaryTree(tree::Node* rootNode): root{rootNode}{}
    void printLevelOrderQueue();
    void printLevelOrderHeightRecursion();
    void insertLevelOrder(int data);
    void deletion(int searchItem);
    void deletionGFG(int searchItem);
    void printInOrderStack();
    void morrisTraversal();
    void printPostOrder();
    void TreeCreator(std::string inorder, std::string preorder);
    int maximumWidth();
    void printNodesAt_K_Distance(int k);
    void printKDistanceRecursion(tree::Node* root, int k);
   void printAncestors(tree::Node* root, int key);
   static bool isSubtree(tree::Node* subtree, tree::Node* tree);
   static bool isSubTreeOptmize(tree::Node* subtree, tree::Node* tree);
private:
    static bool isSubVector(const std::vector<int>& Tvec, const std::vector<int>& STvec);
    static void storeInorder(std::vector<int>* vec, tree::Node* root);
    static void storePreorder(std::vector<int>* vec, tree::Node* root);
    static bool areIdentical(tree::Node* rootT, tree::Node* rootS);
    tree::Node* TreeCreation(std::string inorder, std::string preorder);
    void printGivenLevel(tree::Node* ptr, int height);
    int height(tree::Node* ptr);
    tree::Node* findBottomAndRightMost();
    tree::Node* rightMost(tree::Node* ptr, int height);
    void rightMostDeleterGFG(tree::Node* delNode);
    static int extractInteger(std::string str);
    void printPostOrder(tree::Node* root);
};

