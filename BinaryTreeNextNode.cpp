#include "BinaryTreeNextNode.h"
#include <queue>
#include <iostream>

template<typename T>
void BinaryTreeNextNode<T>::connectingNextRight()
{
	std::queue<Node*> queue;
	queue.push(root);

	while (!queue.empty()) {
		int size = queue.size();

		for (int i = 0; i < size; i++) {
			Node* ptr = queue.front();
			queue.pop();

			if (size - i == 1) {
				ptr->nextRight = nullptr;
			}else if (i < size) {
				ptr->nextRight = queue.front();
			}

			if (ptr->left) {
				queue.push(ptr->left);
			}
			if (ptr->right) {
				queue.push(ptr->right);
			}
		}
	}
}

template<typename T>
void BinaryTreeNextNode<T>::printNextRight()
{
	if (!root) {
		return;
	}
	for (Node* ptr = root; ptr; ptr = ptr->left) {
		for (Node* ptrN = ptr; ptrN; ptrN = ptrN->nextRight) {
			std::cout << ptrN->data << " ";
		}
	}
}
