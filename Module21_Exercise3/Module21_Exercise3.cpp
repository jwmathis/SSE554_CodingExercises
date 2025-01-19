// Jan 18 2025
// Module21_Exercise3.cpp
// Implementing a number search using a Binary Search Tree, including dynamically creating a tree structure

#include <iostream>

using namespace std;

class Node {
public:
	int data;
	Node* left;
	Node* right;

	Node(int data) : data(data), left(nullptr), right(nullptr) {}
};

void binary_search(Node* tree, int data) {
	if (tree == nullptr) {
		cout << data << " is not in the tree." << endl;
		return;
	}

	if (tree->data == data) {
		cout << data << " is in the tree." << endl;
		return;
	}
	else if (tree->data > data) { 
		binary_search(tree->left, data);
	}
	else if (tree->data < data) {
		binary_search(tree->right, data);
	} 

}

// Function to dynamically insert a node into BST
Node* insert(Node* tree, int data) {
	if (tree == nullptr) {
		return new Node(data);
	}

	if (data < tree->data) {
		tree->left = insert(tree->left, data);
	}
	else if (data > tree->data) {
		tree->right = insert(tree->right, data);
	}

	return tree;
}

int main()
{
	// Build the BST
	Node* tree = nullptr;
	int values[] = { 50, 13, 82, 10, 25, 71, 93, 2, 12, 17, 49, 51, 77, 90, 99 };
	for (int value : values) {
		tree = insert(tree, value);
	}

	int search_nums[] = { 99, 18, 50, 49, 42 };
	for (int num : search_nums) {
		binary_search(tree, num);
	}

	return 0;
}

