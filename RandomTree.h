#pragma once
#include <iostream>

class RandomTree
{
	class Node;
	Node* root;
public:
	RandomTree(Node* node) :root{ node } {}
	class Node {
	public:
		int data;
		Node* left;
		Node* right;
		Node* random;
		Node(int item) : data{ item } {
			left = right = random = nullptr;
		}
	};
	void RandomPointerReargmentInorder();
	//Based on Random pointer
	void printInorderRandomPointer();
	Node* cloneTree();
	Node* copyLeftRightNodeGFG(Node* treeNode);
	void copyRandomNode(Node* treeNode, Node* cloneNode);
	void restoreTreeLeftNode(Node* treeNode, Node* cloneNode);
	Node* cloneTreeGFG();
	void printInorder();
	void printLevelorder();
private:
	void printInorder(Node* ptr);
};

