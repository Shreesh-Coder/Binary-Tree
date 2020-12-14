#include "ThreadedBinaryTree.h"

void ThreadedBinaryTree::printInorderTraversal()
{
	Node* current = root;
	//First find the left most element
	while (current->left != nullptr) {
		current = current->left;
	}

	while (current != nullptr) {
		//Print the element
		std::cout << current->data << " ";
		//if the node has rightThread then travers right
		if(current->rightThread){
			current = current->right;
		}
		else { //find left most node of right subtree
			current = current->right;
			if (current != nullptr) {
				while (current->left != nullptr) {
					current = current->left;
				}
			}
		}
	}
}

void ThreadedBinaryTree::converter()
{
	Node* current = root, *pre;
	
	while (current != nullptr) {
		if (current->left == nullptr) {
			current = current->right;
		}
		else {
			pre = current->left;
			while (pre->right != nullptr && pre->right != current) {
				pre = pre->right;
			}
			if (pre->right == nullptr) {
				pre->right = current;
				pre->rightThread = true;
				current = current->left;
			}
			else {
				current->rightThread = false;
				current = current->right;
			}
			
		}
	}
}
