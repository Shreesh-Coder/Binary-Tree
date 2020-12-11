#include "BinaryTreeArray.h"

BinaryTreeArray::BinaryTreeArray(int s): size{s}
{
	arr = new int[size] {};
}

void BinaryTreeArray::insert(int ele)
{
	int left = 2 * pos + 1;
	int right = 2 * pos + 2;
	if (!arr[pos]) {
		arr[pos] = ele;
		return;
	}
	else if (left < size && !arr[left]) {
		arr[left] = ele;
		return;
	}
	else if (right < size && !arr[right]) {
		arr[right] = ele;
	}
	pos++;
}

void BinaryTreeArray::print()
{
	for (int i = 0; i < size; i++) {
		std::cout << arr[i] << " ";
	}
}

BinaryTreeArray::~BinaryTreeArray()
{
	delete[] arr;
}
