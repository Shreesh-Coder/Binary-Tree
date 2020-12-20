#pragma once
template<typename T>
class BinaryTreeNextNode
{
public:
	class Node;
private:
	Node* root;
public:
	BinaryTreeNextNode(Node* root): root{root}{}
	class Node {
	public:
		T data;
		Node* left;
		Node* right;
		Node* nextRight;
		Node(T item) : data{ item } {}
	};

	void connectingNextRight();
	void printNextRight();
};

