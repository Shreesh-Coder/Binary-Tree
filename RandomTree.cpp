#include "RandomTree.h"
#include <queue>

void RandomTree::RandomPointerReargmentInorder()
{
	Node* curr = root, * pre;

	while (curr != nullptr) {
		if (curr->left != nullptr) {
			pre = curr->left;
			while (pre->right != nullptr and pre->right != curr) {
				pre = pre->right;
			}
			if (pre->right == nullptr) {
				pre->right = curr;
				pre->random = curr;
				curr = curr->left;
			}
			else {
				pre->right = nullptr;
				curr->random = curr->right;
				curr = curr->right;
			}
		}
		else {
			curr = curr->right;
		}
	}
}

void RandomTree::printInorderRandomPointer()
{
	if (root == nullptr) {
		return;
	}

	Node* ptr = root;
	while (ptr->left != nullptr) {
		ptr = ptr->left;
	}
	for (; ptr != nullptr; ptr = ptr->random) {
		std::cout << ptr->data << " ";
	}
}

RandomTree::Node* RandomTree::cloneTree()
{
	Node* curr = root,*newCurr;
	Node* newRoot = new Node(curr->data);
	newCurr = newRoot;
	std::queue<Node*> queue,newqueue;
	queue.push(root);
	newqueue.push(newRoot);

	while (!queue.empty()) {
		curr = queue.front();
		newCurr = newqueue.front();
		
		queue.pop();
		newqueue.pop();

		if (curr->left != nullptr) {
			newCurr->left = new Node(curr->left->data);
			queue.push(curr->left);
			newqueue.push(newCurr->left);
		}
		if (curr->right != nullptr) {
			newCurr->right = new Node(curr->right->data);
			queue.push(curr->right);
			newqueue.push(newCurr->right);
		}
	}

	return newRoot;
}

RandomTree::Node* RandomTree::copyLeftRightNodeGFG(Node* treeNode)
{
	if (treeNode == nullptr)
		return nullptr;

	Node* left = treeNode->left;
	treeNode->left = new Node(treeNode->data);
	treeNode->left->left = left;
	
	if (left) {
		left->left = copyLeftRightNodeGFG(left);
	}
	treeNode->left->right = copyLeftRightNodeGFG(treeNode->right);
	return treeNode->left;
}

void RandomTree::copyRandomNode(Node* treeNode, Node* cloneNode)
{
	if (treeNode == nullptr)
		return;
	if (treeNode->random != nullptr) {
		cloneNode->random = treeNode->random->left;
	}
	else {
		cloneNode->random = nullptr;
	}

	if (treeNode->left != nullptr and cloneNode->left != nullptr) {
		copyRandomNode(treeNode->left->left, cloneNode->left->left);
	}
	copyRandomNode(treeNode->right, cloneNode->right);
}


void RandomTree::restoreTreeLeftNode(Node* treeNode, Node* cloneNode)
{
	if (treeNode == nullptr) {
		return;
	}
	if (cloneNode->left != nullptr) {
		//Node* cloneLeft = cloneNode->left->left;
		treeNode->left = treeNode->left->left;
		cloneNode->left = cloneNode->left->left;
	}
	else {
		treeNode->left = nullptr;
	}
	restoreTreeLeftNode(treeNode->left, cloneNode->left);
	restoreTreeLeftNode(treeNode->right, cloneNode->right);
}

RandomTree::Node* RandomTree::cloneTreeGFG()
{
	Node* cloneNode = copyLeftRightNodeGFG(root);
	copyRandomNode(root, cloneNode);
	restoreTreeLeftNode(root, cloneNode);
	return cloneNode;
}



void RandomTree::printInorder()
{
	printInorder(root);
}

void RandomTree::printLevelorder()
{
	std::queue<Node*> queue;
	queue.push(root);
	while (!queue.empty()) {
		Node* ptr = queue.front();
		queue.pop();

		std::cout << ptr->data << " ";

		if (ptr->left != nullptr)
			queue.push(ptr->left);
		if (ptr->right != nullptr)
			queue.push(ptr->right);
	}
}

void RandomTree::printInorder(Node* ptr)
{
	if (ptr == nullptr) {
		return;
	}


	printInorder(ptr->left);
	std::cout << ptr->data << " ";
	printInorder(ptr->right);
}
