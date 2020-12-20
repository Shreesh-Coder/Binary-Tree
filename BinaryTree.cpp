#include "BinaryTree.h"
#include <queue>
#include <stack>
using namespace tree;

int BinaryTree::curr = 0;

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

//Based on Threaded Binary Tree. Converts the normal tree to threaded tree for inorder printing and then
//reverts back all the changes in binary tree.
void BinaryTree::morrisTraversal()
{
	Node *pre, *current;
	current = root;

	while(current != nullptr){
		if (current->left == nullptr) {
			std::cout << current->getData() << " ";
			current = current->right; // current.right will be point to the inorder successor of the current
		}
		else { //Making pre.right to point its inorder succssor
			pre = current->left;
			while (pre->right != nullptr && pre->right != current)
				pre = pre->right;

			//Creating threaded tree.
			if (pre->right == nullptr) {
				pre->right = current; 
				current = current->left;
			}
			else {
				//Reversing the changes of the above if.
				pre->right = nullptr;
				std::cout << current->getData() << " ";
				current = current->right;
			}
		}
	}
}

void BinaryTree::TreeCreator(std::string inorder, std::string preorder)
{
	curr = 0;
	root = TreeCreation(inorder, preorder);
}

void BinaryTree::printPostOrder()
{
	printPostOrder(root);
}

Node* BinaryTree::TreeCreation(std::string inorder, std::string preorder)
{
	if (preorder.empty() || inorder.empty()) {
		return nullptr;
	}

	std::string rootChar{};
	rootChar += preorder[curr];

	int pos = inorder.find(rootChar);
	std::string newInorderLeft{ "" }, newInorderRight{ "" };
	for (int i = 0; i < (pos - 1); i++) {
		newInorderLeft += inorder[i];
	}
	
	for (int j = pos+2; j < inorder.size(); j++) {
		newInorderRight += inorder[j];
	}
	curr += 2;
	Node* node = new Node(extractInteger(rootChar));
	node->left = TreeCreation(newInorderLeft, preorder);
	node->right = TreeCreation(newInorderRight, preorder);
	return node;
}

int BinaryTree::maximumWidth()
{
	std::queue<Node*> queue;
	queue.push(root);
	int max = INT_MIN;

	while (!queue.empty()) {
		Node* ptr;
		int levelSize = queue.size();
		
		if (max < levelSize) {
			max = levelSize;
		}

		for (int i = 0; i < levelSize; i++) {
			ptr = queue.front();
			queue.pop();

			if (ptr->left) {
				queue.push(ptr->left);
			}
			if (ptr->right) {
				queue.push(ptr->right);
			}
		}
	

	}
	return max;
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

void BinaryTree::printNodesAt_K_Distance(int k)
{
	std::queue<Node*> queue;
	queue.push(root);
	int distance = 0;
	while (!queue.empty()) {
		Node* ptr;
		int levelSize = queue.size();
		for (int i = 0; i < levelSize; i++) {
			ptr = queue.front();
			queue.pop();
			if (distance == k) {
				std::cout << ptr->getData() << " ";
			}
			
			if (ptr->left) {
				queue.push(ptr->left);
			}
			if (ptr->right) {
				queue.push(ptr->right);
			}
		}
		if (distance == k) {
			break;
		}
		distance++;
		
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

void BinaryTree::printKDistanceRecursion(tree::Node* root, int k)
{
	if (root == nullptr)
		return;
	if (k == 0)
		std::cout << root->getData() << " ";
	printKDistanceRecursion(root->left, k - 1);
	printKDistanceRecursion(root->right, k - 1);
}

Node* BinaryTree::findBottomAndRightMost()
{
	int height = BinaryTree::height(root);
	return rightMost(root, height - 1);
}

void BinaryTree::printAncestors(tree::Node* root, int key)
{
	static bool isCalling = true;
	if (!root) {
		return;
	}

	if (key == root->getData()) {
		isCalling = false;
		return;
	}
	
	printAncestors(root->left, key);
	if(isCalling)
	printAncestors(root->right, key);
	if(!isCalling)
	std::cout << root->getData() << " ";
}

bool BinaryTree::isSubTreeOptmize(tree::Node* subtree, tree::Node* tree)
{
	if (!subtree) {
		return true;
	}
	if (!tree) {
		return false;
	}
	std::vector<int> subtreeInorder, subtreePreorder, treeInorder, treePreorder;
	storeInorder(&subtreeInorder, subtree);
	storePreorder(&subtreePreorder, subtree);
	storeInorder(&treeInorder, tree);
	storePreorder(&treePreorder, tree);
	
	if (!isSubVector(treeInorder, subtreeInorder))
		return false;

	
	return isSubVector(treePreorder, subtreePreorder);
}

//Checks the tree hight and data. if equals then return true else return false
bool BinaryTree::areIdentical(tree::Node* rootT, tree::Node* rootS)
{
	if (rootT == nullptr && rootS == nullptr ) {
		return true;
	}
	if (rootT == nullptr || rootS == nullptr) {
		return false;
	}

	return rootT->getData() == rootS->getData()
		&& areIdentical(rootT->left, rootS->left)
		&& areIdentical(rootT->right, rootS->right);
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

//Perorder travers the tree
bool BinaryTree::isSubtree(tree::Node* subtreeRoot, tree::Node* treeRoot)
{
	if (subtreeRoot == nullptr) { //becacue null tree is also subtree
		return true;
	}
	if (treeRoot == nullptr) {
		return false;
	}

	if (areIdentical(treeRoot, subtreeRoot)) {
		return true;
	}
	return isSubtree(subtreeRoot, treeRoot->left)
		|| isSubtree(subtreeRoot, treeRoot->right);
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

int BinaryTree::extractInteger(std::string str)
{
	std::stringstream ss;
	ss << str;
	int value{0};
	std::string temp;
	while (!ss.eof()) {
		ss >> temp;
		std::stringstream(temp) >> value;
		temp = "";
	}
	return value;
}

void BinaryTree::printPostOrder(Node* root)
{
	if (root == nullptr) {
		return;
	}
	printPostOrder(root->left);
	printPostOrder(root->right);
	std::cout << root->getData() << " ";
}


void BinaryTree::storeInorder(std::vector<int>* vec, Node* root)
{
	if (!root)
		return;
	storeInorder(vec, root->left);
	vec->push_back(root->getData());
	storeInorder(vec, root->right);
}


void BinaryTree::storePreorder(std::vector<int>* vec, Node* root)
{
	if (!root) {
		return;
	}
	vec->push_back(root->getData());
	storePreorder(vec, root->left);
	storePreorder(vec, root->right);
}

bool BinaryTree::isSubVector(const std::vector<int>& Tvec, const std::vector<int>& STvec)
{
	for (int i = 0, j = 0; i < Tvec.size(); i++) {
		if (Tvec.at(i) == STvec.at(j)) {
			if (j == STvec.size() - 1) {
				return true;
			}
			j++;
		}
	}
	return false;
}