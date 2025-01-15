// Jan 14 2025
// Module21_Exercise1.cpp
// 

#include <iostream>
#include <string>

using namespace std;

class Node {
public:
	int data;
	Node* left;
	Node* right;

	Node(int data, Node* left = NULL, Node* right = NULL) {
		this->data = data;
		this->left = left;
		this->right = right;
	}
};

void print_tree(Node* tree, int level = 0) {
	string s = "";
	if (tree != NULL) {
		print_tree(tree->right, level + 1);

		for (int i = 0; i < level; i++) {
			s += "| ";
		}
		s += to_string(tree->data);
		cout << s << endl;
		print_tree(tree->left, level + 1);
	}
}

int main()
{
	Node* tree = new Node(5);

	tree->left = new Node(2);
	tree->right = new Node(8);

	tree->left->left = new Node(1);
	tree->left->right = new Node(3);
	tree->right->left = new Node(7);
	tree->right->right = new Node(10);
	print_tree(tree);
	return 0;
}