#include "BinaryTree.h"
#include <queue>
#include <stack>
using namespace tree;

void BinaryTree::printLevelOrderQueue()
{
	std::queue<Node*> queue = std::queue<Node*>();
	if (root == nullptr) {
		std::cout << std::endl << "List is Empty";
		return;
	}
	Node* ptr = root;
	queue.push(ptr);
	while (!queue.empty()) {
		ptr = queue.front();
		queue.pop();

		std::cout << ptr->getData() << " ";

		if (ptr->left != nullptr) {
			queue.push(ptr->left);
		}
		if (ptr->right != nullptr) {
			queue.push(ptr->right);
		}
	}
}

void BinaryTree::printLevelOrderHeightRecursion()
{
	int height = BinaryTree::height(root);;
	for (int i = 1; i <= height; i++) {
		printGivenLevel(root, i);
	}
}

void BinaryTree::insertLevelOrder(int data)
{
	Node* newNode = new Node(data);
	
	if (root == nullptr) {
		root = newNode;
		return;
	}

	std::queue<Node*> queue;
	queue.push(root);
	Node* ptr = root;

	while (!queue.empty()) {
		ptr = queue.front();
		queue.pop();

		if (ptr->left == nullptr) {
			ptr->left = newNode;
			break;
		}
		else {
			queue.push(ptr->left);
		}

		if (ptr->right == nullptr) {
			ptr->right = newNode;
			break;
		}
		else {
			queue.push(ptr->right);
		}
	}
}

void BinaryTree::deletion(int searchItem)
{
	if (root == nullptr) {
		return;
	}
	std::queue<Node*> queue;
	Node* ptr = root;
	queue.push(ptr);

	while (!queue.empty()) {
		ptr = queue.front();
		queue.pop();

		Node* replacer;


		if (ptr->getData() == searchItem && ptr == root) {
			replacer = findBottomAndRightMost();

			if (replacer == root) {
				delete root;
				root = nullptr;
				return;
			}
			
			replacer->left = ptr->left;
			replacer->right = ptr->right;
			root = replacer;
			delete ptr;
			return;
		}

		Node* temp;

		if (ptr->right != nullptr && ptr->right->getData() == searchItem) {
			replacer = findBottomAndRightMost();
			
			if (ptr->right == nullptr) {
				delete replacer;
				return;
			}

			temp = ptr->right;
			ptr->right = replacer;
			delete temp;
			return;
		}

		if (ptr->left != nullptr && ptr->left->getData() == searchItem) {
			replacer = findBottomAndRightMost();
			
			if (ptr->left == nullptr) {
				ptr->left = nullptr;
				delete replacer;
				return;
			}

			temp = ptr->left;
			ptr->left = replacer;
			delete temp;
			return;
		}


		if (ptr->left != nullptr) {
			queue.push(ptr->left);
		}
		if (ptr->right != nullptr) {
			queue.push(ptr->right);
		}
	}
}

void BinaryTree::deletionGFG(int searchItem)
{
	std::queue<Node*> queue;
	Node* ptr = root, *keyNode = nullptr;
	queue.push(ptr);

	while (!queue.empty()) {
		ptr = queue.front();
		queue.pop();

		if (ptr->getData() == searchItem) {
			keyNode = ptr;
		}
		
		if (ptr->left != nullptr) {
			queue.push(ptr->left);
		}

		if (ptr->right != nullptr) {
			queue.push(ptr->right);
		}
	}

	if (keyNode != nullptr) {
		keyNode->setData(ptr->getData()); //ptr will point to last rightmost element
		rightMostDeleterGFG(ptr);
		if (ptr == root) {
			root = nullptr;
		}
	}
}

void BinaryTree::printInOrderStack()
{
	std::stack<Node*> stack;
	stack.push(root);
	Node* ptr = root;

	while (!stack.empty()) {
		if (ptr->left != nullptr) {
			stack.push(ptr->left);
			ptr = ptr->left;
			continue;
		}

		ptr = stack.top();
		stack.pop();
		std::cout << ptr->getData() << " ";
		
		if (ptr->right != nullptr) {
			stack.push(ptr->right);
			ptr = ptr->right;
		}
	}
}

void BinaryTree::printGivenLevel(Node* ptr, int height)
{
	if (ptr == nullptr) {
		return;
	}
	else if (height == 1) {
		std::cout << ptr->getData() << " ";
	}
	else if (height > 1) {
		printGivenLevel(ptr->left, height - 1);
		printGivenLevel(ptr->right, height - 1);
	}
}

int BinaryTree::height(tree::Node* ptr)
{
	int lheight, rheight;
	lheight = rheight = 0;

	if (ptr == nullptr) {
		return 0;
	}
	
	lheight = height(ptr->left) + 1;
	rheight = height(ptr->right) + 1;

	if (lheight >= rheight) {
		return lheight;
	}
	else {
		return rheight;
	}
}

Node* BinaryTree::findBottomAndRightMost()
{
	int height = BinaryTree::height(root);
	return rightMost(root, height - 1);
}

tree::Node* BinaryTree::rightMost(tree::Node* ptr, int height)
{
	if (ptr == nullptr) {
		return nullptr;
	}

	if (height == 1) {
		Node* temp;
		if (ptr->right != nullptr) {
			temp = ptr->right;
			ptr->right = nullptr;
			return temp;
		}
		if (ptr->left != nullptr) {
			temp = ptr->left;
			ptr->left = nullptr;
			return temp;
		}
	}
	if (height == 0) {
		return ptr;
	}	
	Node* temp;
	temp = rightMost(ptr->right, height - 1);
	if(temp != nullptr)
		return temp;

	temp = rightMost(ptr->left, height - 1);
	if (temp != nullptr) {
		return temp;
	}
}

void BinaryTree::rightMostDeleterGFG(tree::Node* delNode)
{
	std::queue<Node*> queue;
	queue.push(root);
	Node* ptr = root;

	while (!queue.empty()) {
		ptr = queue.front();
		queue.pop();

		if (ptr == delNode) {
			delete delNode;
			ptr = nullptr;
			break;
		}

		if (ptr->right != nullptr) {
			if (ptr->right == delNode) {
				delete delNode;
				ptr->right = nullptr;
				break;
			}
			queue.push(ptr->right);
		}

		if (ptr->left != nullptr) {
			if (ptr->left == delNode) {
				delete delNode;
				ptr->left = nullptr;
				break;
			}
			queue.push(ptr->left);
		}
	}
}

