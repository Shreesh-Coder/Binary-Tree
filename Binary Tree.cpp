// Binary Tree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "BinaryTree.h"
#include "BinaryTreeArray.h"
#include "ThreadedBinaryTree.h"
#include "RandomTree.h"

void simpleTreeTesting();
void TreeArrayTesting();
void testInorderStack();
void testThreadedTree();
void testRandomTree();

int main()
{
    //simpleTreeTesting();
    //TreeArrayTesting();
    //testInorderStack();
    //testThreadedTree();
    testRandomTree();
}


void simpleTreeTesting() {
    tree::Node* root = new tree::Node(1);
    
    root->left = new tree::Node(2);
    root->right = new tree::Node(3);
    
    root->left->left = new tree::Node(4);
    root->left->right = new tree::Node(5);
    
    root->right->left = new tree::Node(6);

    root->left->right->right = new tree::Node(8);

    root->right->right = new tree::Node(7);
    root->right->right->right = new tree::Node(9);
    root->right->right->right->right = new tree::Node(10);

    /*
            1
          /   \
         2     3     
        / \   / \
       4   5 6   7
      / \   \     \   
     n   n   8     9
                    \
                    10
    */

    BinaryTree bt(root);
    //bt.printLevelOrderHeightRecursion();
    bt.printLevelOrderQueue();
    
    /*bt.insertLevelOrder(20);
    bt.insertLevelOrder(21);
    bt.insertLevelOrder(22);
    bt.insertLevelOrder(23);
    bt.insertLevelOrder(24);*/

    bt.deletionGFG(7);
    bt.deletion(6);
    bt.deletion(1);
    bt.deletion(10);
    bt.deletion(3);
    bt.deletion(2);
    bt.deletion(5);
    bt.deletion(9);
    bt.deletionGFG(8);
   
    std::cout << std::endl;
    bt.printLevelOrderQueue();
   /* bt.insertLevelOrder(90);
    bt.printLevelOrderQueue();*/
}

void TreeArrayTesting() {
    BinaryTreeArray bta(5);
    bta.insert(1);
    bta.insert(2);
    bta.insert(3);
    bta.insert(4);
    bta.insert(5);
    bta.insert(6);
    bta.print();
}

void testInorderStack() {
    using namespace tree;
    Node* root = new Node(1);
    //Layer 2
    root->left = new Node(2);
    root->right = new Node(3);
    //Layer 3
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    //Layer 4
    root->right->left->right = new Node(7);
    
    BinaryTree bt(root);
    bt.printInOrderStack();
    std::cout << std::endl;
    bt.morrisTraversal();
}

void testThreadedTree()
{
    ThreadedBinaryTree::Node* root = new ThreadedBinaryTree::Node(6);
    //Layer 2
    root->left = new ThreadedBinaryTree::Node(3);
    root->right = new ThreadedBinaryTree::Node(8);
    //Layer 3
    root->left->left = new ThreadedBinaryTree::Node(1);
    root->left->right = new ThreadedBinaryTree::Node(5);
    root->right->left = new ThreadedBinaryTree::Node(7);
    root->right->right = new ThreadedBinaryTree::Node(11);
    //Layer 4
    root->right->right->left = new ThreadedBinaryTree::Node(9);
    root->right->right->right = new ThreadedBinaryTree::Node(13);

    /*
    *       6
    *     /   \
    *    3     8
    *   /\    /  \
    *  1  5  7    11
    *             /\
    *            9  13
    */

    ThreadedBinaryTree *tbt = new ThreadedBinaryTree(root);
    tbt->converter();
    tbt->printInorderTraversal();
}

void testRandomTree()
{
    RandomTree::Node* root = new RandomTree::Node(6);
    //Layer 2
    root->left = new RandomTree::Node(3);
    root->right = new RandomTree::Node(8);
    //Layer 3
    root->left->left = new RandomTree::Node(1);
    root->left->right = new RandomTree::Node(5);
    //Initlazing Random Pointers
    root->left->left->random = root->left; // 1->3
    root->left->right->random = root;      // 5->6


    RandomTree* rbt = new RandomTree(root);
    rbt->RandomPointerReargmentInorder();
    rbt->printInorderRandomPointer();

    RandomTree* rbt1 = new RandomTree(rbt->cloneTree());
    std::cout << std::endl;
    rbt1->RandomPointerReargmentInorder();
    rbt1->printInorderRandomPointer();
    
    RandomTree* rbt2 = new RandomTree(rbt->cloneTreeGFG());
    std::cout << std::endl;
    rbt2->printLevelorder(); //Printing Clone
    std::cout << std::endl;
    rbt->printLevelorder(); //Printing Origianl

    
}


