// Binary Tree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "BinaryTree.h"
#include "BinaryTreeArray.h"

void simpleTreeTesting();
void TreeArrayTesting();
void testInorderStack();

int main()
{
    //simpleTreeTesting();
    //TreeArrayTesting();
    testInorderStack();
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
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
