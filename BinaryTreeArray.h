#pragma once
#include <array>
#include <vector>
#include <iostream>

class BinaryTreeArray
{
	int *arr;
	int const size;
	int pos{};
public:
	BinaryTreeArray(int s);
	void insert(int ele);
	void print();
	~BinaryTreeArray();
};

