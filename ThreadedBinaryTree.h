#pragma once
#include <iostream>
class ThreadedBinaryTree
{
	class Node;
	Node* root;
public:
	ThreadedBinaryTree(Node* ptr): root{ptr}{}

	class Node {
	public:
		int data;
		Node* left;
		Node* right;
		bool rightThread;
		Node(int data) {
			this->data = data;
			rightThread = false;
			left = right = nullptr;
		}
	};

	void printInorderTraversal();
	void converter();
};

