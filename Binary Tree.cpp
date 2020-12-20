// Binary Tree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "BinaryTree.h"
#include "BinaryTreeArray.h"
#include "ThreadedBinaryTree.h"
#include "RandomTree.h"
#include "BinaryTreeNextNode.h"
#include <string>

void simpleTreeTesting();
void TreeArrayTesting();
void testInorderStack();
void testThreadedTree();
void testRandomTree();
void testString();
void testTreeCreation();
tree::Node* buildTree(int in[], int pre[], int n);
void testIsSubtree();
void testBinaryTreeNextNode();


int main()
{
    //simpleTreeTesting();
    //TreeArrayTesting();
    //testInorderStack();
    //testThreadedTree();
    //testRandomTree();
    //testString();
    //testTreeCreation();
    //testIsSubtree();
    testBinaryTreeNextNode();
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
    std::cout << "\nMaximum width of the tree is: " << bt.maximumWidth() << std::endl;
    bt.printNodesAt_K_Distance(2);
    std::cout << std::endl;
    bt.printKDistanceRecursion(root,2);
    std::cout << std::endl;
    bt.printAncestors(root, 7);
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

void testString() {
    std::string str = "D B E A F C";
    for ( auto ele : str) {
        if(ele != ' ')
            std::cout << ele;
    }
}

void testTreeCreation()
{
    //std::string inorder =  "0 2 4 6 8 5";
    //                     // D B E A F C
    //std::string preorder = "6 2 0 4 5 8";
    //                    //  A B D E C  F
    std::string inorder = "1 6 8 7";
    std::string preorder = "1 6 7 8";
  
    std::string temp = "0";
    BinaryTree btr(nullptr);
    //std::cout << std::endl << btr.extractInteger(temp);
    BinaryTree bt(nullptr);
    bt.TreeCreator(inorder, preorder);
    std::cout << std::endl;
    //bt.morrisTraversal();
    bt.printPostOrder();
    //int in[6]{ 0,2,4,6,8,5 };
    //int pre[6]{ 6,2,0,4,5,8 };
    int in[4]{1,6,8,7};
    int pre[4]{1,6,7,8};
    //int in[6]{ 3, 1, 4, 0, 5, 2 };
    //int pre[6]{ 0, 1, 3, 4, 2, 5 };
    BinaryTree* bt1 = new BinaryTree(buildTree(in, pre, 4));
    std::cout << std::endl;
    //bt1->morrisTraversal();
    bt1->printPostOrder();
}

int curr = 0;

tree::Node* buildTree(int in[], int pre[], int n)
{
    if (in == nullptr || pre == nullptr) {
        return nullptr;
    }
    int rootValue = pre[curr];
    int pos = 0;

    for (int i = 0; i < n; i++) {
        if (in[i] == rootValue)
            pos = i;
    }
    

    int *newInLeft = new int[pos];
    for (int i = 0; i < pos; i++) {
        newInLeft[i] = in[i];
    }
    
    int* newInRight;
    int rlen = n - pos - 1;
    if (rlen != 0 && n != 0)
        newInRight = new int[rlen];
    else
        newInRight = nullptr;

    for (int j = 0; j + pos + 1 < n; j++) {
        newInRight[j] = in[pos + 1 + j];
    }

    if (pos == 0) {
        newInLeft = nullptr;
    }
    
    curr++;
    tree::Node* node = new tree::Node(rootValue);

    node->left = buildTree(newInLeft, pre, pos);
    node->right = buildTree(newInRight, pre, rlen);

    return node;
}

void testIsSubtree() {
    using namespace tree;
    Node* rootTree = new Node(1);
    //Layer 2
    rootTree->left = new Node(2);
    rootTree->right = new Node(3);
    //Layer 3
    rootTree->left->left = new Node(4);
    rootTree->left->right = new Node(5);
    rootTree->right->left = new Node(6);
    //Layer 4
    rootTree->right->left->right = new Node(7);

    BinaryTree btt(rootTree);

    Node* rootSubtree = new Node(2);
    rootSubtree->left = new Node(4);
    rootSubtree->right = new Node(5);

    BinaryTree btst(rootSubtree);

    std::cout << "is subtree: " << BinaryTree::isSubtree(rootSubtree, rootTree);
   
    Node* root2T = new Node(1);
    root2T->left = new Node(0);
    root2T->right = new Node(3);
    root2T->right->left = new Node(4);

    Node* root2S = new Node(1);
    root2S->left = new Node(1);

    std::cout << "\nis subtree: " << BinaryTree::isSubtree(root2S, root2T);
    std::cout << "\nis subtree: " << BinaryTree::isSubTreeOptmize(root2S, root2T);
}


void testBinaryTreeNextNode() {
    BinaryTreeNextNode<char>::Node* root = new BinaryTreeNextNode<char>::Node('A');
    //Layer 2
    root->left = new BinaryTreeNextNode<char>::Node('B');
    root->right = new BinaryTreeNextNode<char>::Node('C');
    //Layer 3
    root->left->left = new BinaryTreeNextNode<char>::Node('D');
    root->left->right = new BinaryTreeNextNode<char>::Node('E');
    root->right->right = new BinaryTreeNextNode<char>::Node('F');

    BinaryTreeNextNode<char> bt(root);
    bt.connectingNextRight();
    bt.printNextRight();
}